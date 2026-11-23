/*﻿*************************************
* Автор:   Чупин Артем                *
* Задание: Строки, векторы и словари  *
* Вариант: 31                         *
**************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main() {

    string operationNumber;

    cout << "Enter operation number (1-4): ";
    getline(cin, operationNumber);

    if (operationNumber == "1") {

        // Блок A
        int maxLength = 200;
        string inputString;
        string resultString = "";

        cout << "Enter string: " << endl;
        getline(cin, inputString);

        if (inputString.length() > maxLength) {
            cout << "INVALID" << endl;
            return 0;
        }

        if (!inputString.empty()) {
            resultString += inputString[0];
        }

        for (int charIndex = 1; charIndex < inputString.length(); ++charIndex) {
            if (inputString[charIndex] != inputString[charIndex - 1]) {
                resultString += inputString[charIndex];
            }
        }

        if (resultString.empty()) {
            cout << "EMPTY" << endl;
        }
        else {
            cout << resultString << endl;
        }
    }
    else if (operationNumber == "2") {

        // Блок B
        int n, m;
        vector<int> firstVector, secondVector;
        int number;

        cout << "Enter size of first vector: ";
        cin >> n;

        for (int index = 0; index < n; ++index) {
            cout << "Enter element " << index + 1 << ": ";
            cin >> number;
            
            if (number < -1000 || number > 1000) {
                cout << "INVALID";
                return 0;
            }

            firstVector.push_back(number);
        }

        cout << "Enter size of second vector: ";
        cin >> m;

        for (int index = 0; index < m; ++index) {
            cout << "Enter element " << index + 1 << ": ";
            cin >> number;
            secondVector.push_back(number);
        }

        for (int index = 0; index < m; ++index) {
            firstVector.push_back(secondVector[index]);
        }

        for (int index = 0; index < firstVector.size(); ++index) {
            cout << firstVector[index] << " ";
        }
    } else if (operationNumber == "3") {

        // Блок C
        int pairsCount;
        string key;
        int value;

        cout << "Enter number of pairs: ";
        cin >> pairsCount;

        if (pairsCount < 0) {
            cout << "INVALID";
            return 0;
        }

        map<string, int> data;
        cout << "Enter key and value: " << endl;

        for (int index = 0; index < pairsCount; ++index) {
            cout << "Enter element " << index + 1 << ": " << endl
                << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            data[key] = value;
        }

        int positiveCount = 0;

        for (const auto& entry : data) {
            if (entry.second > 0) {
                ++positiveCount;
            }
        }

        cout << positiveCount << endl;
    } else if (operationNumber == "4") {

        // Блок D
        int messagesCount;
        vector<map<string, string>> messages;
        vector<string> result;
        string sender, text;

        cout << "Enter number of messages: ";
        cin >> messagesCount;

        if (messagesCount < 0 || messagesCount > 100) {
            cout << "INVALID";
            return 0;
        }

        cin.ignore();

        if (messagesCount == 0) {
            cout << "EMPTY";
            return 0;
        }

        for (int index = 0; index < messagesCount; ++index) {
            cout << "Message " << index + 1 << endl 
                 << "Sender: ";
            getline(cin, sender);
            cout << "Text: ";
            getline(cin, text);

            messages.push_back({{ "sender", sender }, { "text", text }});
        }

        for (int index = 0; index < messagesCount; ++index) {
            if (index == 0 || messages[index]["sender"] != messages[index - 1]["sender"]) {
                result.push_back(messages[index]["sender"] + ": " + messages[index]["text"]);
            } else {
                result.back() += " / " + messages[index]["text"];
            }
        }

        for (int index = 0; index < result.size(); ++index) {
            cout << result[index] << endl;
        }
    } else {
        cout << "Operation not found";
        return 0;
    }
}
