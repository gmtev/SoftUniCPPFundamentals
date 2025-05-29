#include <iostream>
#include <sstream>
#include <list>
using namespace std;

// Below Average Only

int main() {

    int N;
    cin >> N;

    list<int> numbers;
    int average = 0;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        average += num;
        numbers.push_back(num);
    }

    average = average / N;

    for(list<int>::iterator it = numbers.begin(); it != numbers.end();) {
        int number = *it;
        if (number > average)
            it = numbers.erase(it);
        else
            it++;
    }

    int idx = 0;
    int oddSum = 0, evenSum = 0;
    for(list<int>::iterator it = numbers.begin();
        it != numbers.end(); it++, idx++) {
            int number = *it;
            if (idx % 2) {
                oddSum += number;
            } else {
                evenSum += number;
            }
        }

    cout << oddSum * evenSum << endl;

    return 0;
}

// Special Items

bool isMagical(char c) {
    // could be done with switch too
    return c == 'a' || 
    c == 'e' ||
    c == 'i' ||
    c == 'o' ||
    c == 'u';
}

int main() {

    string line;
    getline(cin, line);

    string result;
    char prevChar = 0;
    for(char c : line) {

        if (isMagical(c) || prevChar != c)
            result += c;
        prevChar = c;
    }

    cout << result << endl;

    return 0 ;
}

// Machine Commands

int main() {

    list<int> numbers;

    while(true) {
        string command;
        getline(cin, command);
        if (command == "end")
            break;
        
        istringstream numberStream(command);
        int number;
        if (numberStream >> number) {
            numbers.push_back(number);
        } else {
            if (command == "discard") {
                numbers.pop_back();
            } else {
                int a = numbers.back();
                numbers.pop_back();
                int b = numbers.back();
                numbers.pop_back();
                if (command == "sum") {
                    numbers.push_back(a + b);
                } else if (command == "subtract") {
                    numbers.push_back(a - b);
                } else {
                    ostringstream concat;
                    concat << b << a;
                    string concatenated = concat.str();
                    
                    istringstream numberStream(concatenated);
                    int number;
                    if (numberStream >> number) {
                        numbers.push_back(number);
                    }
            }
        }

    }

}
    for (int i : numbers)
        cout << i << endl;
    
    return 0;

}