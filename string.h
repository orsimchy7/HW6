
#include "generic-string.h"
#include "string-array.h"


class String;


StringArray split(const char *delimiters)
GenericString& operator=(const char *str)
GenericString& trim()
bool operator==(const GenericString &other)
bool operator==(const char *other)
int to_integer()
String& as_string()
const String& as_string()
GenericString* make_string(const char *str);
