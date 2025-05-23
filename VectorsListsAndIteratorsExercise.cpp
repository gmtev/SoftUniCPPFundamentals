#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <climits>
using namespace std;


// Merge Trains

void readTrain(list<int> & train) {
    string line;
    getline(cin, line);

    istringstream istr(line);
    int railcar;
    while(istr >> railcar)
        train.push_back(railcar);
}

void mergeFromTrain(list<int> & train, list<int> & result, char trainName, string & mergeInfo) {

    int backCart = train.back();
    train.pop_back();

    result.push_front(backCart);

    mergeInfo += trainName;
}

int main() {

    list<int> trainA;
    readTrain(trainA);

    list<int> trainB;
    readTrain(trainB);

    list<int> result;
    string mergeInfo;

    while(trainA.size() || trainB.size()) {
        if (trainA.size() == 0)
            mergeFromTrain(trainB, result, 'B', mergeInfo);
        else
            if (trainB.size() == 0)
                mergeFromTrain(trainA, result, 'A', mergeInfo);
            else {
                int endA = trainA.back();
                int endB = trainB.back();
                if (endA < endB)
                    mergeFromTrain(trainA, result, 'A', mergeInfo);
                else
                    mergeFromTrain(trainB, result, 'B', mergeInfo);

            }
    }

    cout << mergeInfo << endl;
    for(int cart : result)
        cout << cart << ' ';

    cout << endl;

    return 0;
}

// Brackets

bool checkExpression(const list<char> & expression) {

    int br0Count = 0;
    int br1Count = 0;
    int br2Count = 0; //counter for each different type of brackets

    for(
        list<char>::const_iterator it = expression.begin();
        it!= expression.end();
        it++) {
            switch(*it) {
                case '(': br0Count++;break;
                case ')':
                    if (br0Count > 0)
                        br0Count--;
                    else
                        return false;
                    break;
                case '[':
                    if (br0Count != 0)
                        return false;
                    br1Count++;
                    break;
                case ']':
                    if (br0Count != 0)
                        return false;
                    if (br1Count <= 0)
                        return false;
                    br1Count--;
                    break;
                case '{':
                    if (br0Count != 0 || br1Count != 0)
                        return false;
                    br2Count++;
                    break;
                case '}':
                    if (br0Count != 0 || br1Count != 0)
                        return false;
                    if (br2Count <= 0)
                        return false;
                    br2Count--;
                    break;
            }

        }

    return br0Count == 0 && br1Count == 0 && br2Count == 0;
}

int main() {

    string str;
    getline(cin, str);

    list<char> expression;
    for(char c: str)
        expression.push_back(c);

    cout << (checkExpression(expression) ? "valid" : "invalid") << endl;
    return 0;
}

// Pipes

void readIntVector(istream & input, int numberCount, vector<int> & data) {
    while(numberCount--) {
        int number;
        cin >> number;
        data.push_back(number);
    }
}

int main() {

    int N;
    cin >> N;

    vector<int> checkup;
    checkup.reserve(N);
    readIntVector(cin, N, checkup);

    vector<int> installation;
    installation.reserve(N);
    readIntVector(cin, N, installation);

    vector<int> yearsToGo;
    yearsToGo.reserve(N);

    for(int curPipe = 0; curPipe < checkup.size(); curPipe++) {
        int corrosionPerYear = installation[curPipe] - checkup[curPipe];
        yearsToGo.push_back(installation[curPipe] / corrosionPerYear);
    }

    for(int i : yearsToGo)
        cout << i << ' ';
    cout << endl;

    return 0;
}


// Bus

int convertMilitaryTime(const string & busTimeStr) {

    int minutesSinceMidnight = 0;
    int hour = (busTimeStr[0] - '0') * 10 + (busTimeStr[1] - '0');
    int minute = (busTimeStr[2] - '0') * 10 + (busTimeStr[3] - '0');

    return hour * 60 + minute;
}

int main() {
    
    int N;

    cin >> N;

    vector<int> busArrivalTime;
    busArrivalTime.reserve(N);

    for (int i = 0; i < N; ++i) {
        string busTimeStr;
        cin >> busTimeStr;
        int minutesSinceMidnight = convertMilitaryTime(busTimeStr);
        busArrivalTime.push_back(minutesSinceMidnight);
    }

    string trainDepartureTimeStr;
    cin >> trainDepartureTimeStr;

    int trainDepartureTime = convertMilitaryTime(trainDepartureTimeStr);

    int bestBusTime = INT_MAX;
    int bestTimeIndex = -1;

    for(int busPos = 0; busPos < busArrivalTime.size(); busPos++) {

        int busArrival = busArrivalTime[busPos];
        int diff;
        if (trainDepartureTime >= busArrival)
            diff = trainDepartureTime - busArrival;
        else {
            diff = (24*60)-busArrival;
            diff += trainDepartureTime;
        }  
        
        if (diff < bestBusTime) {
            bestBusTime = diff;
            bestTimeIndex = busPos + 1;
        }
    }

    cout << bestTimeIndex << endl;

    return 0;
}