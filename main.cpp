
#include "generic-field.h"
#include "ip.h"
#include "port.h"

#include "generic-string.h"
#include "string.h"
#include "string-array.h"
#include "input.h"

#include <iostream>
using namespace std;

int main(int argc,char **argv){
	
	String rule = argv[1];

	//first we need to figure out if the rule is
	//about Ip or Port
	StringArray rule_divided=rule.split("=");
	rule_divided[0]->trim();
	StringArray rule_info = rule_divided[0]->split("-");
	//we will get in rule_info for example:
	//["src", "ip"]

	const char* port_str = "port";
    const char* ip_str = "ip";

    if(rule_info[1]==ip_str){
    	Ip ip_obj(rule);

    	//using the function parse_input(Generic_field& field)
    	parse_input(ip_obj);

    }else{
    	Port port_obj(rule);
    	parse_input(port_obj);

    }




	/*Ip ip("hi");

	int ip_rule[4]; 
	ip_rule[0] = 122;
	ip_rule[1] = 12;
	ip_rule[2] = 1;
	ip_rule[3] = 0;
	*/
	return 0;
}