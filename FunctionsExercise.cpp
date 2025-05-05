#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

// Center Point

void printPoint(double x, double y) {
    cout << "(" << x << ", " << y << ")";
}

double calculateDistance(double x, double y) {
    return x*x + y*y;
}

int main() {

    double x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    double z1 = calculateDistance(x1, y1);
    double z2 = calculateDistance(x2, y2);

    if (z1 <= z2){
        printPoint(x1, y1);
    } else {
        printPoint(x2, y2);
    }

    cout << endl;
    return 0;
}

// Operations

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if (b != 0)
        return a / b;
    else
        return 0; // to avoid errors
}

int calculate(char symbol, int a, int b) {
    switch(symbol) {
        case '+': return add(a, b);
        case '-': return sub(a, b);
        case '*': return mul(a, b);
        case '/': return division(a, b);
    }

    return 0;
}

int main() {
    int a, b;

    cin >> a >> b;

    char symbol;
    cin >> symbol;


    cout << calculate(symbol, a, b) << endl;

    return 0;
}

// Factorial Division

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;

    long long result = n * factorial(n - 1);
    // long long result = 1;

    // for (int current = 2; current <= n; current ++)
    //     result *= current;

    return result;
}

int main() {

    int a, b;
    cin >> a >> b;

    long long af = factorial(a);
    long long bf = factorial(b);

    double result = (double)af / bf;

    cout << fixed << setprecision(2) << result << endl;

    return 0;
}

// Print Name of Numbers

string numberToWord(int number) {
    switch(number) {
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }

    return "";
}

string decimalToWord(int number) {
    switch(number) {
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "sixty";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninety";
    }

    return "";
}

string teensToWord(int number) {
    switch(number) {
        case 0: return "ten";
        case 1: return "eleven";
        case 2: return "twelve";
        case 3: return "thirteen";
        case 4: return "fourteen";
        case 5: return "fifteen";
        case 6: return "sixteen";
        case 7: return "seventeen";
        case 8: return "eighteen";
        case 9: return "nineteen";
    }

    return "";
}

int main() {
    int n;

    cin >> n;

    if (n == 0) {
        cout << numberToWord(n) << endl;
        return 0;
    }

    int n1 = n % 10;
    int n2 = (n / 10) % 10;
    int n3 = (n / 100) % 10;
    int n4 = (n / 1000); // no higher numbers than 9999

    if (n4)
        cout << numberToWord(n4) << " thousand ";

    if (n3)
        cout << numberToWord(n3) << " hundred ";

    if (n2 >= 2)
        cout << decimalToWord(n2) << " ";

    if (n2 == 1) {
        cout << teensToWord(n1);
    } else 
        if (n1)
            cout << numberToWord(n1); 

    cout << endl;
    return 0;
}

// Multiply Evens, Sum by Odds

bool getDigit(int n, int & s) {

    s = n % 10;

    return s % 2 == 0;
}

int main() {

    int n;
    cin >> n;

    int sumOdd = 0;
    int sumEven = 0;

    while(n) {
        int single;

        if (getDigit(n, single)) {
            sumEven += single;
        } else {
            sumOdd += single;
        }
        n /= 10;
    }

    cout << sumOdd * sumEven << endl;

    return 0;
}

// Vowels Count

bool isVowel (char c) {

    switch(c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        case 'y':
        case 'Y':
            return true;
        
        default:
            return false;
    }
}

int vowelsCount(string s) {

    int vowelsCount = 0;

    for (int current = 0; current < s.length(); current++)
        vowelsCount += isVowel(s[current]);

    return vowelsCount;
}

int main() {

    string s;
    getline(cin, s);

    cout << vowelsCount(s) << endl;

    return 0;
}

// Password Validator

bool checkPasswordLength(string s) {

    return s.length() >= 6 && s.length() <= 10;
}

bool checkPasswordContent(string s) {

    for(int curr = 0; curr < s.length(); curr++)
        if (!isalnum(s[curr]))
            return false;
    return true;
}

bool checkPasswordDigits(string s) {

    int digitsCount = 0;

    for(int curr = 0; curr < s.length(); curr++)
        if (isdigit(s[curr]))
            digitsCount++;

    return digitsCount >= 2;
}

void checkPassword(string s, bool & lengthOK, bool & contentOK, bool & atLeastTwoDigitsOK) {
    lengthOK = checkPasswordLength(s);
    contentOK = checkPasswordContent(s);
    atLeastTwoDigitsOK = checkPasswordDigits(s);
}


int main() {

    string s;
    getline(cin, s);

    bool lengthOK;
    bool contentOK;
    bool atLeastTwoDigitsOK;

    checkPassword(s, lengthOK, contentOK, atLeastTwoDigitsOK);
    
    if (lengthOK && contentOK && atLeastTwoDigitsOK) {
        cout << "Password is valid" << endl;
    } else {
        if (!lengthOK)
            cout << "Password must be between 6 and 10 characters" << endl;
        if (!contentOK)
            cout << "Password must consist only of letters and digits" << endl;
        if (!atLeastTwoDigitsOK)
            cout << "Password must have at least 2 digits" << endl;
    }

    return 0;
}

// Orders

double getPrice(string product) {

    if (product == "water")
        return 1;
    if (product == "coffee")
        return 1.5;
    if (product == "coke")
        return 1.4;
    if (product == "snacks")
        return 2;
    
        return 0;
}

double totalOrder(string product, int quantity) {

    double price = getPrice(product);

    return price * quantity;
}

int main() {

    string product;
    int quantity;
    getline(cin, product);
    cin >> quantity;

    cout << fixed << setprecision(2) << totalOrder(product, quantity) << endl;
    return 0;
}

// Greater of Two Values

void compareInt(){
    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << a << endl;
    else    
        cout << b << endl;
}

void compareChar(){
    char a, b;
    cin >> a >> b;

    if (a > b)
        cout << a << endl;
    else    
        cout << b << endl;
}

void compareStr(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (a > b)
        cout << a << endl;
    else    
        cout << b << endl;
}

int main() {

    string type;

    getline(cin, type);

    if (type == "int")
        compareInt();
    if (type == "char")
        compareChar();
    if (type == "string")
        compareStr();
    
    
    return 0;
}
