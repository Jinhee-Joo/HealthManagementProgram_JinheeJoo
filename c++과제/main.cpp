#include "HealthData.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<HealthData> users;
    string filename = "health_data.txt";

    // ���� ������ �ҷ�����
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        try {
            while (!inputFile.eof()) {
                users.push_back(HealthData::loadFromFile(inputFile));
            }
        }
        catch (const exception& e) {
            cerr << "�����͸� �ҷ����� �� ������ �߻��߽��ϴ�: " << e.what() << endl;
        }
        inputFile.close();
    }

    // ����� �Է� �ޱ�
    cout << "����� ������ �Է����ּ��� (�����Ϸ��� �̸��� '����' �Է�):\n";
    while (true) {
        string name;
        cout << "�̸�: ";
        cin >> name;
        if (name == "����") break;

        int age;
        cout << "����: ";
        cin >> age;

        double height, weight;
        cout << "Ű (cm): ";
        cin >> height;
        cout << "������ (kg): ";
        cin >> weight;

        try {
            HealthData user(name, age, height, weight);
            users.push_back(user);
        }
        catch (const exception& e) {
            cerr << "�Է� ����: " << e.what() << endl;
        }
    }

    // ��� ����� ���� ���
    cout << "\n�Էµ� ����� ����:\n";
    for (auto& user : users) {
        user.displayInfo();
        cout << "--------------------\n";
    }

    // ������ ���Ϸ� ����
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (auto& user : users) {
            user.saveToFile(outputFile);
        }
        outputFile.close();
    }
    else {
        cerr << "������ ������ ������ �� �����ϴ�." << endl;
    }

    return 0;
}
