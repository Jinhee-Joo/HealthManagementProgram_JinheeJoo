#include "HealthData.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<HealthData> users;
    string filename = "health_data.txt";

    // 기존 데이터 불러오기
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        try {
            while (!inputFile.eof()) {
                users.push_back(HealthData::loadFromFile(inputFile));
            }
        }
        catch (const exception& e) {
            cerr << "데이터를 불러오는 중 오류가 발생했습니다: " << e.what() << endl;
        }
        inputFile.close();
    }

    // 사용자 입력 받기
    cout << "사용자 정보를 입력해주세요 (종료하려면 이름에 '종료' 입력):\n";
    while (true) {
        string name;
        cout << "이름: ";
        cin >> name;
        if (name == "종료") break;

        int age;
        cout << "나이: ";
        cin >> age;

        double height, weight;
        cout << "키 (cm): ";
        cin >> height;
        cout << "몸무게 (kg): ";
        cin >> weight;

        try {
            HealthData user(name, age, height, weight);
            users.push_back(user);
        }
        catch (const exception& e) {
            cerr << "입력 오류: " << e.what() << endl;
        }
    }

    // 모든 사용자 정보 출력
    cout << "\n입력된 사용자 정보:\n";
    for (auto& user : users) {
        user.displayInfo();
        cout << "--------------------\n";
    }

    // 데이터 파일로 저장
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (auto& user : users) {
            user.saveToFile(outputFile);
        }
        outputFile.close();
    }
    else {
        cerr << "데이터 파일을 저장할 수 없습니다." << endl;
    }

    return 0;
}
