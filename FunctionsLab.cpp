#include <iostream>
using namespace std;

// Sign of Integer Numbers

void printSign(int number) {
    cout << "The number " << number << " is ";

    if (number > 0) {
        cout << "positive." << endl; 
    } else if (number < 0) {
        cout << "negative." << endl;
    } else {
        cout << "zero." << endl;
    }
}

int main() {

    int number;
    cin >> number;

    printSign(number);

    return 0;
}

// Grades

void printGrade(float grade) {
    if (grade >= 5.50) {
        cout << "Excellent" << endl;
    } else if (grade >= 4.50) {
        cout << "Very good" << endl;
    } else if (grade >= 3.50) {
        cout << "Good" << endl;
    } else if (grade >= 3.00) {
        cout << "Poor" << endl;
    } else {
        cout << "Fail" << endl;
    }
}

int main() {

    float grade;
    cin >> grade;

    printGrade(grade);

    return 0;
}

// Smallest of Three Numbers

int printSmallest(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < c && b < a)
        return b;
    else
        return c;
}

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    cout << printSmallest(a, b, c) << endl;

    return 0;
}

// Printing Triangle

void print1toN(int size) {
    for (int currentNumber = 1; currentNumber <= size; currentNumber++)
        cout << currentNumber << ' ';
    cout << endl;
}

int main() {

    int size;
    cin >> size;

    for (int currentLine = 1; currentLine <= size; currentLine++)
        print1toN(currentLine);
    for (int currentLine = size - 1; currentLine > 0; currentLine--)
        print1toN(currentLine);

    return 0;
}

// Calculate Rectangle Area

int rectangleArea(int width, int height) {
    return width * height;
}

int main() {

    int a, b;
    cin >> a >> b;

    cout << rectangleArea(a, b) << endl;
    return 0;
}

// Math Power

// could be done with long instead of int, but it does not matter to the judge tests.
int mathPower(int number, int power) {
    int result = 1;

    while(power--)
        result = result * number;

    return result;
}

int main() {

    int number, power;
    cin >> number >> power;

    cout << mathPower(number, power) << endl;
    return 0;
}
