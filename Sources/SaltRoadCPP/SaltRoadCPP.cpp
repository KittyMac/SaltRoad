#include "SaltRoadCPP.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>

extern "C" int saltroad_add(int x, int y);
extern "C" const char * saltroad_uppercase(const char * ptr);
extern "C" const char * saltroad_jsonpath(const char * path, const char * json);
extern "C" void saltroad_flynnTest(const char * ptr, void * functionPtr, void * infoPtr);
extern "C" void saltroad_download(const char * ptr, void * functionPtr, void * infoPtr);
extern "C" void saltroad_ocr();
extern "C" void saltroad_imap();
extern "C" const char * saltroad_eval(const char * ptr);

extern "C" void testSaltRoad();



void function1Callback(std::function<void(std::string)> * closure, const char * resultCString) {
    std::string cppString = resultCString;
    (*closure)(cppString);
    delete closure;
}

int SaltRoadCPP::add(int a, int b) {
    return saltroad_add(a, b);
}

std::string SaltRoadCPP::uppercase(std::string string) {
    return saltroad_uppercase(string.c_str());
}

std::string SaltRoadCPP::jsonpath(std::string query, std::string json) {
    return saltroad_jsonpath(query.c_str(), json.c_str());
}

void SaltRoadCPP::flynnTest(std::string tolower, std::function<void(std::string)> closure) {
    std::function<void(std::string)> * copyClosure = new std::function<void(std::string)>(closure);
    saltroad_flynnTest(tolower.c_str(), (void *)function1Callback, copyClosure);
}


void testSaltRoad() {
    
    SaltRoadCPP * sr = new SaltRoadCPP();
    
    int x = sr->add(40, 2);
    fprintf(stderr, "the value is: %d\n", x);
    
    std::string hello = sr->uppercase("hello world!");
    fprintf(stderr, "uppercase: %s\n", hello.c_str());
    
    std::string results = sr->jsonpath("$[3,6,-2]", "[0,1,2,3,4,5,6,7,8,9]");
    fprintf(stderr, "jsonpath: %s\n", results.c_str());
    
    sr->flynnTest("HELLO WORLD 1", [](std::string result) {
        fprintf(stderr, "flynnResult: %s\n", result.c_str());
    });
    
    sr->flynnTest("HELLO WORLD 2", [](std::string result) {
        fprintf(stderr, "flynnResult: %s\n", result.c_str());
    });
    
    sr->flynnTest("HELLO WORLD 3", [](std::string result) {
        fprintf(stderr, "flynnResult: %s\n", result.c_str());
    });
    
}

