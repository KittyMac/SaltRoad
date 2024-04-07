#ifndef __SALTROAD_CPP__
#define __SALTROAD_CPP__

#ifdef __cplusplus

#include <string>
#include <functional>

class SaltRoadCPP {
private:

public:
    int add(int a, int b);
    std::string uppercase(std::string string);
    std::string jsonpath(std::string query, std::string json);
    void flynnTest(std::string tolower, std::function<void(std::string)> func);
};

#endif

#ifdef __cplusplus
extern "C" {
#endif

void testSaltRoad();

#ifdef __cplusplus
}
#endif

#endif
