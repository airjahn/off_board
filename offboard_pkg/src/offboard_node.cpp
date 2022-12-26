/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>


#include"baowei.h"
#include"baowei.cpp"
#include"baowei_private.h"
#include"baowei_types.h"



mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

geometry_msgs::PoseStamped local_pos;
void local_pos_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
    local_pos = *msg;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;
    baoweiModelClass baowei;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Subscriber local_pos_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("mavros/local_position/pose", 10, local_pos_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::Publisher local_vel_pub = nh.advertise<geometry_msgs::TwistStamped>
            ("mavros/setpoint_velocity/cmd_vel", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");



    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);
    float pos_x=local_pos.pose.position.x;
    float pos_y=local_pos.pose.position.y;


    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    geometry_msgs::TwistStamped vel;
    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

//    last_request = ros::Time::now();

//(ros::Time::now() - last_request > ros::Duration(5.0))
int flag=0;
    while(ros::ok()){
         pos_x=local_pos.pose.position.x;
         pos_y=local_pos.pose.position.y;
         baowei.baowei_U.CUR_POS_X=pos_x;
         baowei.baowei_U.CUR_POS_Y=pos_y;
         baowei.baowei_U.SP_POS_X=0;
         baowei.baowei_U.SP_POS_Y=0;
         baowei.baowei_U.SP_R=5;
         baowei.baowei_U.SP_WD=1;
         baowei.baowei_U.K1=2;
         baowei.baowei_U.K2=2;
         baowei.step();
         vel.twist.linear.x =baowei.baowei_Y.SP_VEL_X;
         vel.twist.linear.y =baowei.baowei_Y.SP_VEL_Y;
         vel.twist.linear.z = 0.8;
         set_mode_client.call(offb_set_mode);
         arming_client.call(arm_cmd);
          //local_vel_pub.publish(vel);


            if( flag==0&&(ros::Time::now() - last_request > ros::Duration(10.0)))
		{
			flag++;
                	pose.pose.position.x = 10;
    			pose.pose.position.y = 0;
    			pose.pose.position.z = 2;
                 last_request = ros::Time::now();
                 ROS_INFO("pos1");
                }
		if(flag==1&&(ros::Time::now() - last_request > ros::Duration(10.0)))
		{
			flag++;
                	pose.pose.position.x = 10;
    			pose.pose.position.y = 10;
    			pose.pose.position.z = 2;
                 last_request = ros::Time::now();
		ROS_INFO("pos2");
                }
		if(flag==2&&(ros::Time::now() - last_request > ros::Duration(10.0)))
		{
			flag++;
                	pose.pose.position.x = 0;
    			pose.pose.position.y = 10;
    			pose.pose.position.z = 2;
                 last_request = ros::Time::now();
		ROS_INFO("pos3");
                }
		if(flag==3&&(ros::Time::now() - last_request > ros::Duration(10.0)))
		{
			flag++;
                	pose.pose.position.x = 0;
    			pose.pose.position.y = 0;
    			pose.pose.position.z = 2;
                 last_request = ros::Time::now();
		ROS_INFO("pos4");
                }
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
