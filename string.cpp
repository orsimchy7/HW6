
#include <string.h> //this or <cstring>?
#include <stdio.h>
#include <iostream> //why?
#include "generic-string.h"
//#include "string.h" needed?
#include "string-array.h"

class String : public GenericString {
	char* strg; //mustnt be const oherwise cant change!! and probably wasnt allowed to use std::string
	StringArray substrg;
	public:
		String(); //constructor
		StringArray split(const char *delimiters)
		GenericString& operator=(const char *str)
		GenericString& trim()
		bool operator==(const GenericString &other)
		bool operator==(const char *other)
		int to_integer()
		String& as_string()
		const String& as_string()
		GenericString* make_string(const char *str); //were asked to implement it here...
}

//constuctor
String::String() { cout << "String created" << endl}

//operators
String::operator=(const char *str) {
	strcpy(this->strg, str);
	return *this; //this is the way of returning refernce to this
}

String::operator==(const GenericString &other){
	if (!strcmp(other.strg, this->strg)) {
		return true;
	}
	return false;
}

String::operator==(const char *other) {
	if (!strcmp(other, this->strg)) {
		return true;
	}
	return false;
}

//other functions

String::split(const char *delimiters) {
	this->substrg->arrLen = 0;
	//need to convert const char* strg to (ordinary) char* strg?
	char* token = strtok(this->strg, delimeters);
	while (token != NULL) {
		//keep setting String array
		this->substrg->subStrVec.push_back(token);
		this->substrg->arrLen++;
		token = strtok(NULL, delimeters);
	}

}

String::trim() { //fix it!!
	char* ptr = this->strg; //to avoid memory leaking. operator = has original meaning (?). and ptr doesnt need to be deleted in the end? check
	while(*(ptr) != ' ') {
		ptr++; //'removing' first white spaces
	}
	int lastidx = strlen(ptr);
	while (lastidx >= 0 && ptr[lastidx] - 1 != ' ') {
		lastidx--;
	}
	*ptr[lastidx] = '\0';
	delete(this->strg); //oh no! but it delete data of ptr1 too...
	this->strg = new char[lastidx +1];
	const char* new_strg = prt;
	this = new_strg; //new meaning, right? strcpy suppose to stop when meet
}
//1. non const ver.
String::String& as_string() {
	dynamic_cast<String*>(this) //converts safely
	return *this;
}
//2. const ver.
String::String& as_string() {
	dynamic_cast<String*>(this) //converts safely
	const String& cnstRef = *this; //is legal? dont need constructor?
	return cnstRef;
}


String::to_integer() {
	return atoi(this->strg);
}

//helpers:
int atoi(const char* str) //converts numeric str to an actual num (int type)
char *strtok(char *str, const char *delim) //break to substrings
