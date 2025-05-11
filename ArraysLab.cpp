#include <iostream>
#include <string>
#include <array>
using namespace std;

// Day of Week

string daysOfWeek [] = {
    "Invalid day!",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

void printDayOfWeek(string days[], int day) {

    if (day < 1 || day > 7)
        day = 0;
    cout << days[day] << endl;
}

int main() {

    int day;

    cin >> day;

    printDayOfWeek(daysOfWeek, day);

    return 0;

}

// Day of Week #2

array<string, 8> daysOfWeekArray = {
    "Invalid day!",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

void printDayOfWeekArray(const array<string, 8> & days, int day) {

    if (day < 1 || day > 7)
        day = 0;
    cout << days[day] << endl;
}

int main() {

    int day;

    cin >> day;

    printDayOfWeekArray(daysOfWeekArray, day);

    return 0;

}

// Print Numbers in Reverse Order

int main() {

    const int MaxSize = 99;

    int array[MaxSize] = {};

    int num;

    cin >> num;

    for (int current = 0; current < num; current++)
        cin >> array[current];
    
    for (int current = num-1; current >= 0; current--)
        cout << array[current] << ' ' << flush;
    
        cout << endl;

    return 0;
}

// Print Numbers in Reverse Order #2

int main() {

    const int MaxSize = 99;

    int num;

    cin >> num;

    array<int, MaxSize> arr = {};

    for (int current = 0; current < num; current++)
        cin >> arr[current];
    
    for (int current = num-1; current >= 0; current--)
        cout << arr[current] << ' ' << flush;
    
        cout << endl;

    return 0;
}

// Sum Even Numbers

int main() {

    const int MaxSize = 99;
    int arr[MaxSize];

    int N;
    cin >> N;

    for(int cnt = 0; cnt < N; cnt++)
        cin >> arr[cnt];

    long sum = 0;
    for(int cnt = 0; cnt < N; cnt++)
        if ( (arr[cnt] % 2) == 0) {
            sum += arr[cnt];
        }
    
    cout << sum << endl;

    return 0;
}

// Reverse Array of Strings

void reverseArray(string rev[], int size) {
    int iterations = size / 2;
    for(int cnt = 0; cnt < iterations; cnt++) {
        string tmp = rev[cnt];
        rev[cnt] = rev[size - 1 - cnt];
        rev[size-1 - cnt] = tmp;
    }
}

void printArray(string toPrint[], int size) {
    for(int cnt = 0; cnt < size; cnt++)
        cout << toPrint[cnt] << ' ';
    cout << endl;
}

int main() {

    const int MaxSize = 99;
    int N;
    cin >> N;

    string arr[MaxSize];

    for(int cnt = 0; cnt < N; cnt++)
        cin >> arr[cnt];
    
    reverseArray(arr, N);
    printArray(arr, N);

    return 0;
}

// Even and Odd Subtraction

int main() {

    const int MaxSize = 99;
    int arr[MaxSize];

    int N;
    cin >> N;

    for(int cnt = 0; cnt < N; cnt++)
        cin >> arr[cnt];

    long sumEvens = 0;
    long sumOdds = 0;

    for(int cnt = 0; cnt < N; cnt++)
        if (arr[cnt] % 2) 
            sumEvens += arr[cnt];
        else 
            sumOdds += arr[cnt];
        
    
    cout << sumOdds - sumEvens << endl;

    return 0;
}

// Equal Arrays

void readArr(int arr[], int size) {
    for(int cnt=0; cnt < size; cnt++)
        cin >> arr[cnt];
}

bool areIdentical(int arr1[], int arr2[], int N, int & returnValue) {
    int sum = 0;
    for(int cnt = 0; cnt < N; cnt++) {
        if (arr1[cnt] != arr2[cnt]) {
            returnValue = cnt;
            return false;
        }
        sum += arr1[cnt];
    }
    returnValue = sum;
    return true;
}

int main() {

    const int MaxSize = 99;
    int arr1[MaxSize], arr2[MaxSize];

    int N;
    cin >> N;

    readArr(arr1, N);
    readArr(arr2, N);

    int returnValue;
    if (areIdentical(arr1, arr2, N, returnValue)) {
        cout << "Arrays are identical. Sum: " << returnValue << endl;
    } else {
        cout << "Arrays are not identical. Found difference at " << returnValue << " index." << endl;
    }


    return 0;
}
