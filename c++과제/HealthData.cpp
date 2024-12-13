#include "HealthData.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// �⺻ ������
HealthData::HealthData() : name(""), age(0), height(0.0), weight(0.0), bmi(0.0) {}

// �Ű����� ������
HealthData::HealthData(string n, int a, double h, double w) : name(n), age(a), height(h), weight(w) {
    if (age < 0 || height <= 0 || weight <= 0) {
        throw invalid_argument("�Է°��� 0���� Ŀ�� �մϴ�.");
    }
    calculateBMI();
}

// BMI ��� �Լ�
void HealthData::calculateBMI() {
    bmi = weight / ((height / 100) * (height / 100));
}

// ����� ���� ���
void HealthData::displayInfo() {
    cout << "�̸�: " << name << endl;
    cout << "����: " << age << "��" << endl;
    cout << "Ű: " << height << "cm" << endl;
    cout << "������: " << weight << "kg" << endl;
    cout << "BMI: " << bmi << endl;
    cout << "����: " << getHealthStatus() << endl;
}

// �ǰ� ���� ��ȯ �Լ�
string HealthData::getHealthStatus() {
    if (bmi < 18.5) return "��ü��";
    else if (bmi < 24.9) return "����";
    else if (bmi < 29.9) return "��ü��";
    else return "��";
}

// ������ �����ε� (BMI ��)
bool HealthData::operator>(const HealthData& other) const {
    return this->bmi > other.bmi;
}

// ������ ����
void HealthData::saveToFile(ofstream& out) {
    out << name << " " << age << " " << height << " " << weight << "\n";
}

// ������ �ҷ�����
HealthData HealthData::loadFromFile(ifstream& in) {
    string name;
    int age;
    double height, weight;
    in >> name >> age >> height >> weight;
    return HealthData(name, age, height, weight);
}
