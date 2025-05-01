#include <iostream>
#include <iomanip>
using namespace std;

// Student Information

int main() {

    string name;
    int age;
    float grade;

    // cin >> name >> age >> grade; 
    cin >> name;
    cin >> age;
    cin >> grade;

    cout << setprecision(2) << fixed;
    cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;

    return 0;
}

// Passed or Failed

int main() {

    float grade;

    cin >> grade;

    if (grade >= 3.0) {
        cout << "Passed!";
    } else {
        cout << "Failed!";
    }

    cout << endl;
    return 0;
}

// Month Printer

int main() {

    int month;

    cin >> month;

    switch(month) {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;

        default: cout << "Error!"; break;
    }

    cout << endl;

    return 0;
}

// Foreign Languages

int main() {

    string country;

    cin >> country;

    if (country == "England" || country == "USA")
        cout << "English";
    else if (country == "Mexico" || country == "Spain" || country == "Argentina")
        cout << "Spanish";
    else
        cout << "unknown";
    
    cout << endl;

    return 0;
}

// Divisible by 3
// or just have a for(int cnt = 3; cnt <= 99; cnt+=3) and print the number directly.

int main() {

    for (int cnt = 1; cnt <= 100; cnt++)
        if (cnt % 3 == 0)
            cout << cnt << endl;

    return 0;
}

// Sum of Odd Numbers

int main() {

    int n;
    int sum = 0;
    cin >> n;

    for (int current = 1; n != 0; current+=2, n--) {
        cout << current << endl;
        sum += current;
    }
    
    cout << "Sum: " << sum << endl;
    return 0;
}

// Multiplication Table

int main() {

    int number;
    cin >> number;

    for (int current = 1; current <= 10; current ++)
        cout << number << " X " << current << " = " << number * current << endl;

    return 0;
}

// Even Number

int main() {

    do {
        int number;
        cin >> number;

        if (number % 2) {
            cout << "Please write an even number." << endl;
        } else {
            if (number < 0) {
                number *= -1;
            }
            cout << "The number is: " << number << endl;
            break;
        }

    } while (true);
    
    return 0;
}