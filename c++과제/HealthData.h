#ifndef HEALTHDATA_H
#define HEALTHDATA_H

#include "HealthBase.h"
#include <string>
#include <fstream>
using namespace std;

class HealthData : public HealthBase {
private:
    string name;
    int age;
    double height; // 키 (cm)
    double weight; // 몸무게 (kg)
    double bmi;

public:
    HealthData(); // 기본 생성자
    HealthData(string n, int a, double h, double w); // 매개변수 생성자

    void calculateBMI() override; // BMI 계산 함수
    void displayInfo() override;  // 사용자 정보 출력
    string getHealthStatus() override; // 건강 상태 반환

    bool operator>(const HealthData& other) const; // 연산자 오버로딩

    void saveToFile(ofstream& out); // 데이터 저장
    static HealthData loadFromFile(ifstream& in); // 데이터 불러오기
};

#endif // HEALTHDATA_H

