#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


// Valid Usernames

bool isValidUsername(const string& username) {
    
    if (username.length() < 3 || username.length() > 16)
        return false;

    for (char ch : username) {
        if (!isalnum(ch) && ch != '-' && ch != '_') {
            return false;
        }
    }

    return true;
}

int main() {

    string input;
    getline(cin, input);

    size_t start = 0;
    while (start < input.length()) {
        size_t end = input.find(", ", start);
        string username;

        if (end == string::npos) {
            username = input.substr(start);
            start = input.length(); 
        } else {
            username = input.substr(start, end - start);
            start = end + 2;
        }

        if (isValidUsername(username)) {
            cout << username << endl;
        }
    }

    return 0;
}

// Caesar Cipher

int main() {

    string text;
    getline(cin, text); 

    for (char& ch : text) {
        ch = ch + 3; 
    }

    cout << text << endl;

    return 0;
}

// Replace Repeating Chars

int main() {

    string input;
    getline(cin, input);

    if (input.empty()) {
        cout << "" << endl;
        return 0;
    }

    string result;
    result += input[0];

    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] != input[i - 1]) {
            result += input[i];
        }
    }

    cout << result << endl;

    return 0;
}

// Character Multiplier

int main() {

    string str1, str2;
    cin >> str1 >> str2;

    int totalSum = 0;
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t minLen = min(len1, len2);

    for (size_t i = 0; i < minLen; ++i) {
        totalSum += str1[i] * str2[i];
    }

    if (len1 > len2) {
        for (size_t i = len2; i < len1; ++i) {
            totalSum += str1[i];
        }
    } else if (len2 > len1) {
        for (size_t i = len1; i < len2; ++i) {
            totalSum += str2[i];
        }
    }

    cout << totalSum << endl;
    return 0;
}

// Mathematical Expression

int main() {

    string expression;
    getline(cin, expression);

    int balance = 0;

    for (char ch : expression) {
        if (ch == '(') {
            balance++;
        } else if (ch == ')') {
            balance--;
            if (balance < 0) {
                cout << "incorrect" << endl;
                return 0;
            }
        }
    }

    if (balance == 0) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }

    return 0;
}

// Title Case

int main() {

    string text;
    getline(cin, text);

    bool newWord = true;

    for (char& ch : text) {
        if (isalpha(ch)) {
            if (newWord) {
                ch = toupper(ch);
                newWord = false;
            }
        } else {
            newWord = true;
        }
    }

    cout << text << endl;
    return 0;
}

// Replace All

int main() {

    string text, findStr, replaceStr;
    getline(cin, text);
    getline(cin, findStr);
    getline(cin, replaceStr);

    size_t pos = 0;
    while ((pos = text.find(findStr, pos)) != string::npos) {
        text.replace(pos, findStr.length(), replaceStr);
        pos += replaceStr.length();
    }

    cout << text << endl;

    return 0;
}

// Invalid Input

bool isInteger(const string& str) {

    if (str.empty()) return false;
    size_t i = 0;
    if (str[0] == '-' && str.size() > 1) i = 1;
    for (; i < str.size(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

int main() {

    string input;
    getline(cin, input);

    stringstream ss(input);
    string token;
    int sum = 0;
    vector<string> words;

    while (ss >> token) {
        if (isInteger(token)) {
            sum += stoi(token);
        } else {
            words.push_back(token);
        }
    }

    cout << sum << endl;
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

