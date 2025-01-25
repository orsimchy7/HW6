#ifndef PORT_H
#define PORT_H

#include "generic-field.h"

class Port : public GenericField {
public:
    int range_start = 0;
    int range_end = 0;
    String rule_info;

    Port(const char* rule);
    ~Port();

    bool match(const GenericString &packet) const override;
};

#endif