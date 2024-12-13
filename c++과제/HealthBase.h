#ifndef HEALTHBASE_H
#define HEALTHBASE_H

#include <string>
using namespace std;

// 추상 클래스 
class HealthBase {
public:
    virtual void calculateBMI() = 0;
    virtual void displayInfo() = 0;
    virtual string getHealthStatus() = 0;
    virtual ~HealthBase() {}
};

#endif // HEALTHBASE_H
