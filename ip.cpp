
#include "generic-field.h"
#include "generic-string.h"
#include <cstring>
#include <iostream>
using namespace std;
//<iostream> provides us access to cout cin cerr

//Ip inherits from that abstruct class GenericField
class Ip: public GenericField{
		
public:

	int ip_rule_ints[4] = {0};
	int prefix =0; //from MSB to LSB
	String rule_info;


	//we must implement the pure virtual func
	bool match(const GenericString& packet);


	unsigned int get_packet_ip(const GenericString& packet) const; 

	//constructor that gets an ip rule
	Ip(const char* rule);

	//destructor
	~Ip();
};

Ip::Ip(const char* rule){
	//"src-ip =   122.0.0.0/8"

    //setting the ip_rule to be String type
    GenericString* s_p =  make_string(rule);
    s_p->as_string();
    s_p->trim();

    //first we split description and given ip
    StringArray as1 = s_p->split("=");
    //as1 = ["src-ip ", "  122.0.0.0/8"]

    //now we split the ip from the bits rule
    StringArray as2 = as1[1]->split("/");
    //as2=["   122.0.0.0", "8"]

    //now we split each int (delimiter = ".")
    StringArray ip_values = as2[0]->split(".");
    //ip_values = ["   122", "0", "0" ,"0"]

    for (int i = 0; i < 4; ++i) {
        ip_values[i]->trim();
        ip_rule_ints[i] = ip_values[i]->to_integer();
    }


    //finding important_bits_num
    prefix = as2[1]->to_integer();

    //finding if the rule is about src or dst
    rule_info = as1[0]->trim();

   	delete s_p;
	cout<< "constructor IP" << endl;
}

Ip::~Ip(){

	cout << "~Ip()" << endl;
}

Ip::match(const GenericString& packet) const{

	ip = get_packet_ip(packet);

	int suffix = 32 - this.prefix;
	unsigned int mask = -1U << suffix; //-1U = FFF..

	unsigned int lowest_ip = ((this.ip_rule[0] << 24) | 
                  (this.ip_rule[1] << 16) | 
                  (this.ip_rule[2] << 8)  | 
                  this.ip_rule[3]) &  mask;


	unsigned int highest_ip = lo | (~mask);

	cout << "match()"; 

	return (ip >=lowest_ip) && (ip<=highest_ip);

}	


Ip::get_packet_ip(const GenericString& packet) const{
	//==== Procss packet
		//we want to take the ip that matches the rule
		//if my rule is about src-ip
		//then we will take the packet's src-ip ...
		String trimmed_packet = packet->as_string().trim();
    	StringArray fields = trimmed_packet.split(",");
    	//fields = ["src-ip=6.6.6.6  ", 
    	//" src-port=67,dst-port=4 "...]

    for (int i = 0; i < fields.arrLen; i++) {
        StringArray key_value = fields[i]->split("=");
        key_value[0]->trim();

        if (*(key_value[0]) == rule_info) {
            StringArray ip_parts = key_value[1]->trim().split(".");
            unsigned int ip = (ip_parts[0]->to_integer() << 24) |
                              (ip_parts[1]->to_integer() << 16) |
                              (ip_parts[2]->to_integer() << 8) |
                              ip_parts[3]->to_integer();
            return ip;
        }
    }

    return 0; // if there is a problem

}