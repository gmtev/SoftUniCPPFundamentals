#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Swimming Championship

int main() {
    int n;
    int neededPoints;
    int swimmers;
    double hotelPricePerDay;
    double participationFee;

    cin >> n >> neededPoints >> swimmers >> hotelPricePerDay >> participationFee;

    vector<double> dailyPoints(n);
    for (int i = 0; i < n; i++) {
        cin >> dailyPoints[i];
    }

    for (int i = 1; i < n; i++) {
        dailyPoints[i] += 0.05 * dailyPoints[i - 1];
    }

    double totalPoints = 0.0;
    for (int i = 0; i < n; i++) {
        totalPoints += dailyPoints[i];
    }


    double hotelExpenses = swimmers * hotelPricePerDay * n;
    double participationExpenses = swimmers * participationFee;
    double totalExpenses = hotelExpenses + participationExpenses;

    bool success = totalPoints >= neededPoints;
    double sponsorCoverage = success ? 0.25 : 0.10;
    double moneyLeftToPay = totalExpenses * (1.0 - sponsorCoverage);

    cout << fixed << setprecision(2);
    cout << "Money left to pay: " << moneyLeftToPay << " BGN." << endl;

    if (success) {
        cout << "The championship was successful!" << endl;
    } else {
        cout << "The championship was not successful." << endl;
    }

    return 0;
}


// Array to Number

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (arr.size() > 1) {
        vector<int> finalen;
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            finalen.push_back(arr[i] + arr[i + 1]);
        }
        arr = finalen;
    }

    cout << arr[0] << endl;

    return 0;
}

// Train

void printTrain(const vector<string>& train) {
    cout << "|";
    for (const string& wagon : train) {
        if (wagon.empty()) {
            cout << " |";
        } else {
            cout << wagon << "|";
        }
    }
    cout << endl;
}

int main() {
    vector<string> train;
    string input;

    while (getline(cin, input) && input != "end") {
        if (input == "empty") {
            train.push_back("");
        } else {
            train.push_back(input);
        }
    }

    while (getline(cin, input) && input != "E") {
        if (input == "P") {

            printTrain(train);
        } else if (input[0] == 'M') {

            int oldPos, newPos;
            sscanf(input.c_str(), "M %d %d", &oldPos, &newPos);

            oldPos--;
            newPos--;

            string wagon = train[oldPos];

            train.erase(train.begin() + oldPos);

            train.insert(train.begin() + newPos, wagon);

            printTrain(train);
        } else if (input[0] == 'L') {
            int pos;
            sscanf(input.c_str(), "L %d", &pos);

            pos--;

            train.erase(train.begin() + pos);

            printTrain(train);
        }
    }

    return 0;
}