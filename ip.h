#ifndef IP_H
#define IP_H

#include "generic-field.h" 
#include "string.h"


class Ip : public GenericField {
public:

	int ip_rule_ints[4];
	int prefix; //from MSB to LSB
	String rule_info;


    Ip(const String& rule);
    Ip(const Ip& other); //copy constructor
    ~Ip();


    bool match(const GenericString &packet) const;
    unsigned int get_packet_ip(const GenericString& packet) const; 
};


	

#endif

