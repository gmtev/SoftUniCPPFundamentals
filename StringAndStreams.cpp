#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Reverse Strings

string reverseWord(const string & input) {
    ostringstream ostr;

    for(int current = input.size() - 1; current >= 0; current--){
        ostr << input[current];
    }
    return ostr.str();
}

int main() {

    string input;

    getline(cin, input);
    while(input != "end") {
        string reversed = reverseWord(input);
        cout << input << " = " << reversed << endl;
        getline(cin, input);
    }

    return 0;
}

// Repeat Strings

int main() {

    string buffer;
    getline(cin, buffer);

    istringstream istr(buffer);
    ostringstream ostr;
    string word;

    while(istr >> word) {
        for(int current = 0; current < word.size(); current++)
            ostr << word;
    }

    cout << ostr.str() << endl;

    return 0;
}

// Substring

int main() {

    string first, second;
    getline(cin, first);
    getline(cin, second);

    int pos = second.find(first);
    while(pos!= string::npos) {
        second.erase(pos, first.size());
        pos = second.find(first);
    }

    cout << second << endl;

    return 0;
}

// Digits, Letters and Other

int main() {

    string line;
    getline(cin, line);

    istringstream istr(line);

    ostringstream digits, letters, other;

    char ch;
    while(istr >> ch) {
        if (isdigit(ch))
            digits << ch;
        else if (isalpha(ch))
            letters << ch;
        else
            other << ch;
    }

    cout << digits.str() << endl
        << letters.str() << endl
        << other.str() << endl;
        
    return 0;
}
