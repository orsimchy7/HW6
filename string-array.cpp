
#include <vector> //for using the template "vector"
#include <string> //for using string-type elemnts


class StringArray : public String {
	int arrLen; //need to initialize here or on split func??
	std::vector<std::string*> subStrVec;
	//const char* original_strg;
	
	
	
	//StringArray split(const char *delimiters)
}


//NOT NEEDED!! IMPLEMENTED AT STRING.CPP

//StringArray::split(const char *delimiters) {
//	this->arrLen = 0;
//	//need to convert const char* strg to (ordinary) char* strg?
//	char* token = strtok(this->original_strg, delimeters);
//	while (token != NULL) {
//		//keep setting String array
//		subStrVec.push_back(token);
//		this->arrLen++;
//		token = strtok(NULL, delimeters);
//	}

//}
