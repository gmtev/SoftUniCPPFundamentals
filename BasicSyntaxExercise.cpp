#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <numeric>
using namespace std;

// Order Two Numbers

int main() {
    int num1;
    int num2;
    // int num1, num2;
    cin >> num1;
    cin >> num2;
    // cin >> num1 >> num2;

    if (num1 > num2) {
        cout << num2 << ' ' << num1 << endl;
    } else {
        cout << num1 << ' ' << num2 << endl;
    }

    return 0;
}

// Product Sign

int main() {
    float num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    if (num1 == 0 || num2 == 0 || num3 == 0) {
        cout << "+" << endl;

    } else {
    int i = 0;
    if (num1 < 0)
        i++;
    if (num2 < 0)
        i++;
    if (num3 < 0)
        i++;
    
    bool Positive = (i % 2 == 0);

    if (Positive)
        cout << "+" << endl;
    else
        cout << "-" << endl;

    }

    return 0;
}

// Quadratic Equation

int main () {
    double a, b, c;

    cin >> a >> b >> c;

    double discriminant = (b*b - 4*a*c);

    if (discriminant < 0) {
        cout << "no roots" << endl;
    } else {
        cout << (-b + sqrt(discriminant)) / (2 * a) << " ";
        if (discriminant > 0)
            cout << (-b - sqrt(discriminant)) / (2 * a);
        cout << endl;
    }

    return 0;
}

// Numbers 1 to N

int main () {

    int n;
    cin >> n;

    for (int current = 1; current <= n; current++){
        cout << current << ' ';
    }

    cout << endl;

    return 0;
}

// Min and Max

int main () {

    int n;

    cin >> n;

    int minimum = INT_MAX, maximum = INT_MIN;

    for(int counter = 0; counter < n; counter++){
        int current;
        cin >> current;

        if (current < minimum)
            minimum = current;
        if (current > maximum)
            maximum = current;
    }

    cout << minimum << " " << maximum << endl;

    return 0;
}

// Greatest Common Divisor

int main() {

    int a, b;

    cin >> a >> b;

    int greatestcd = gcd(a, b);

    cout << greatestcd << endl;

    return 0;
}

// int main () {
//     int a, b;

//     cin >> a >> b;

//     if (b < a) {
//         int temporary = a;
//         a = b;
//         b = temporary;
//         // swap(a, b), we make sure that a < b
//     }

//     int gcd = a;
//     for (;gcd >0; gcd--)
//         if ((a % gcd == 0) && (b % gcd == 0))
//             break;

//     cout << gcd << endl;

//     return 0;
// }

// Print and Sum

int main () {

    int start, end;

    cin >> start >> end;

    int sum = 0;

    for (int current = start; current <= end; current++) {
        cout << current << " " << flush;
        sum += current;
    }

    cout << endl << "Sum: " << sum << endl;

    return 0;
}

// Strong Number

int main () {

    int n;

    cin >> n;

    int remaining = n;

    long strongSum = 0;

    while(remaining) {

        int currentDigit = remaining % 10;
        remaining /= 10;

        long fac = 1;

        for (int current = 2; current <= currentDigit; current++)
            fac = fac * current;
        
        strongSum += fac;
    }

    cout << (n == strongSum ? "yes" : "no") << endl;

    return 0;
}