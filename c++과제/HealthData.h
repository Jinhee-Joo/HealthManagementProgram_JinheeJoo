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
    double height; // Ű (cm)
    double weight; // ������ (kg)
    double bmi;

public:
    HealthData(); // �⺻ ������
    HealthData(string n, int a, double h, double w); // �Ű����� ������

    void calculateBMI() override; // BMI ��� �Լ�
    void displayInfo() override;  // ����� ���� ���
    string getHealthStatus() override; // �ǰ� ���� ��ȯ

    bool operator>(const HealthData& other) const; // ������ �����ε�

    void saveToFile(ofstream& out); // ������ ����
    static HealthData loadFromFile(ifstream& in); // ������ �ҷ�����
};

#endif // HEALTHDATA_H

