#include "SaltRoadCPP.h"
#include <stdio.h>
#include <string>

extern "C" int saltroad_add(int a, int b);
extern "C" const char * saltroad_uppercase(const char * utf8);
extern "C" const char * saltroad_jsonpath(const char * query, const char * json);
extern "C" void testSaltRoad();

int SaltRoadCPP::add(int a, int b) {
    return saltroad_add(a, b);
}

std::string SaltRoadCPP::uppercase(std::string string) {
    return saltroad_uppercase(string.c_str());
}

std::string SaltRoadCPP::jsonpath(std::string query, std::string json) {
    return saltroad_jsonpath(query.c_str(), json.c_str());
}


void testSaltRoad() {
    
    SaltRoadCPP * sr = new SaltRoadCPP();
    
    int x = sr->add(40, 2);
    fprintf(stderr, "the value is: %d\n", x);
    
    std::string hello = sr->uppercase("hello world!");
    fprintf(stderr, "uppercase: %s\n", hello.c_str());
    
    std::string results = sr->jsonpath("$[3,6,-2]", "[0,1,2,3,4,5,6,7,8,9]");
    fprintf(stderr, "jsonpath: %s\n", results.c_str());
}

