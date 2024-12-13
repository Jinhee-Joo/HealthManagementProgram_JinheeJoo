#include "HealthData.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// 기본 생성자
HealthData::HealthData() : name(""), age(0), height(0.0), weight(0.0), bmi(0.0) {}

// 매개변수 생성자
HealthData::HealthData(string n, int a, double h, double w) : name(n), age(a), height(h), weight(w) {
    if (age < 0 || height <= 0 || weight <= 0) {
        throw invalid_argument("입력값은 0보다 커야 합니다.");
    }
    calculateBMI();
}

// BMI 계산 함수
void HealthData::calculateBMI() {
    bmi = weight / ((height / 100) * (height / 100));
}

// 사용자 정보 출력
void HealthData::displayInfo() {
    cout << "이름: " << name << endl;
    cout << "나이: " << age << "세" << endl;
    cout << "키: " << height << "cm" << endl;
    cout << "몸무게: " << weight << "kg" << endl;
    cout << "BMI: " << bmi << endl;
    cout << "상태: " << getHealthStatus() << endl;
}

// 건강 상태 반환 함수
string HealthData::getHealthStatus() {
    if (bmi < 18.5) return "저체중";
    else if (bmi < 24.9) return "정상";
    else if (bmi < 29.9) return "과체중";
    else return "비만";
}

// 연산자 오버로딩 (BMI 비교)
bool HealthData::operator>(const HealthData& other) const {
    return this->bmi > other.bmi;
}

// 데이터 저장
void HealthData::saveToFile(ofstream& out) {
    out << name << " " << age << " " << height << " " << weight << "\n";
}

// 데이터 불러오기
HealthData HealthData::loadFromFile(ifstream& in) {
    string name;
    int age;
    double height, weight;
    in >> name >> age >> height >> weight;
    return HealthData(name, age, height, weight);
}
