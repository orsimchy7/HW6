
#include "generic-field.h"
#include "generic-string.h"
#include <cstring>
#include <iostream>
using namespace std;
//<iostream> provides us access to cout cin cerr


class Port : public GenericField {
public:
    int range_start = 0;
    int range_end = 0;
    String rule_info;

    Port(const char* rule);
    ~Port();

    bool match(const GenericString &packet) const;
};

Port::Port(const char* rule){
    //parsing the rule string.
    GenericString* s_p = make_string(rule);
    s_p->as_string();
    s_p->trim();

    //separate the field name and value.
    StringArray as1 = s_p->split("=");
    
    StringArray range_values = as1[1]->split("-");

    //convert strings to ints
    range_start = range_values[0]->trim().to_integer();
    range_end = range_values[1]->trim().to_integer();
    
    // rule_info = "src-port" or "dst-port"
    rule_info = as1[0]->trim();

    delete s_p;
}

Port::~Port() {
}


bool Port::match(const GenericString &packet) const {
    // Parse the packet
    String trimmed_packet = packet->as_string().trim();
    StringArray fields = trimmed_packet.split(",");
    //fields = ["src-ip=6.6.6.6  ", 
    //" src-port=67,dst-port=4 ",...]

    //find the relevant port field.
    for (int i = 0; i < fields.arrLen; i++) {
        StringArray key_value = fields[i]->split("=");
        key_value[0]->trim();

        // Check if the current field matches the rule information.
        if (*(key_value[0]) == rule_info) {
            int port = key_value[1]->trim().to_integer();
            return (port >= range_start && port <= range_end);
        }
    }

    // Return false if error
    return false; 
}