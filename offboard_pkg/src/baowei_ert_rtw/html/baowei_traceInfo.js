function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "baowei"};
	this.sidHashMap["baowei"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/CUR_POS_X"] = {sid: "baowei:58"};
	this.sidHashMap["baowei:58"] = {rtwname: "<Root>/CUR_POS_X"};
	this.rtwnameHashMap["<Root>/CUR_POS_Y"] = {sid: "baowei:59"};
	this.sidHashMap["baowei:59"] = {rtwname: "<Root>/CUR_POS_Y"};
	this.rtwnameHashMap["<Root>/SP_POS_X"] = {sid: "baowei:60"};
	this.sidHashMap["baowei:60"] = {rtwname: "<Root>/SP_POS_X"};
	this.rtwnameHashMap["<Root>/SP_POS_Y"] = {sid: "baowei:61"};
	this.sidHashMap["baowei:61"] = {rtwname: "<Root>/SP_POS_Y"};
	this.rtwnameHashMap["<Root>/SP_R"] = {sid: "baowei:62"};
	this.sidHashMap["baowei:62"] = {rtwname: "<Root>/SP_R"};
	this.rtwnameHashMap["<Root>/SP_WD"] = {sid: "baowei:63"};
	this.sidHashMap["baowei:63"] = {rtwname: "<Root>/SP_WD"};
	this.rtwnameHashMap["<Root>/K1"] = {sid: "baowei:64"};
	this.sidHashMap["baowei:64"] = {rtwname: "<Root>/K1"};
	this.rtwnameHashMap["<Root>/K2"] = {sid: "baowei:65"};
	this.sidHashMap["baowei:65"] = {rtwname: "<Root>/K2"};
	this.rtwnameHashMap["<Root>/Fcn"] = {sid: "baowei:66"};
	this.sidHashMap["baowei:66"] = {rtwname: "<Root>/Fcn"};
	this.rtwnameHashMap["<Root>/Fcn1"] = {sid: "baowei:67"};
	this.sidHashMap["baowei:67"] = {rtwname: "<Root>/Fcn1"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "baowei:68"};
	this.sidHashMap["baowei:68"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Sum1"] = {sid: "baowei:69"};
	this.sidHashMap["baowei:69"] = {rtwname: "<Root>/Sum1"};
	this.rtwnameHashMap["<Root>/Sum3"] = {sid: "baowei:70"};
	this.sidHashMap["baowei:70"] = {rtwname: "<Root>/Sum3"};
	this.rtwnameHashMap["<Root>/Sum4"] = {sid: "baowei:71"};
	this.sidHashMap["baowei:71"] = {rtwname: "<Root>/Sum4"};
	this.rtwnameHashMap["<Root>/Sum5"] = {sid: "baowei:72"};
	this.sidHashMap["baowei:72"] = {rtwname: "<Root>/Sum5"};
	this.rtwnameHashMap["<Root>/Sum6"] = {sid: "baowei:73"};
	this.sidHashMap["baowei:73"] = {rtwname: "<Root>/Sum6"};
	this.rtwnameHashMap["<Root>/cos"] = {sid: "baowei:74"};
	this.sidHashMap["baowei:74"] = {rtwname: "<Root>/cos"};
	this.rtwnameHashMap["<Root>/k1(R-r)*cos"] = {sid: "baowei:75"};
	this.sidHashMap["baowei:75"] = {rtwname: "<Root>/k1(R-r)*cos"};
	this.rtwnameHashMap["<Root>/k1*???R-r???*sin"] = {sid: "baowei:76"};
	this.sidHashMap["baowei:76"] = {rtwname: "<Root>/k1*???R-r???*sin"};
	this.rtwnameHashMap["<Root>/k2*r*wd*sin"] = {sid: "baowei:77"};
	this.sidHashMap["baowei:77"] = {rtwname: "<Root>/k2*r*wd*sin"};
	this.rtwnameHashMap["<Root>/k2rwdcos"] = {sid: "baowei:78"};
	this.sidHashMap["baowei:78"] = {rtwname: "<Root>/k2rwdcos"};
	this.rtwnameHashMap["<Root>/r"] = {sid: "baowei:79"};
	this.sidHashMap["baowei:79"] = {rtwname: "<Root>/r"};
	this.rtwnameHashMap["<Root>/sin"] = {sid: "baowei:80"};
	this.sidHashMap["baowei:80"] = {rtwname: "<Root>/sin"};
	this.rtwnameHashMap["<Root>/SP_VEL_X"] = {sid: "baowei:81"};
	this.sidHashMap["baowei:81"] = {rtwname: "<Root>/SP_VEL_X"};
	this.rtwnameHashMap["<Root>/SP_VEL_Y"] = {sid: "baowei:82"};
	this.sidHashMap["baowei:82"] = {rtwname: "<Root>/SP_VEL_Y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
