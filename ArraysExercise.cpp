#include <iostream>
#include <array>
#include <iomanip>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

static const int MAXSIZE = 99;

// Zig-Zag Arrays

int main() {

    array<int, MAXSIZE> m1;
    array<int, MAXSIZE> m2;

    int N;
    cin >> N;

    for(int cnt = 0; cnt < N; cnt++) {

        int n1, n2;
        cin >> n1 >> n2;

        if(cnt % 2) {
            m2[cnt] = n1;
            m1[cnt] = n2;
        } else {
            m2[cnt] = n2;
            m1[cnt] = n1;
        }
    }

    for(int cnt = 0; cnt < N; cnt++) {
        cout << m1[cnt] << " ";
    }
    cout << endl;

    for(int cnt = 0; cnt < N; cnt++) {
        cout << m2[cnt] << " ";
    }
    cout << endl;

    return 0;

}

// Longest Sequence

int main(){

    int N;
    cin >> N;

    int numbers[MAXSIZE];

    for(int cnt = 0; cnt < N; cnt++)
        cin >> numbers[cnt];
    
    int max_sequence_size = 1;
    int current_sequence_size = 1;
    int max_s_num = numbers[0];
    int cur_s_num = numbers[0];

    for(int cnt = 1; cnt < N; cnt++){
        if (numbers[cnt] == cur_s_num) {
            current_sequence_size++;
        } else {
            if (current_sequence_size >= max_sequence_size) {
                max_sequence_size = current_sequence_size;
                max_s_num = cur_s_num;
            }
            current_sequence_size = 1;
            cur_s_num = numbers[cnt];
        }
    }

    if (current_sequence_size >= max_sequence_size) {
        max_sequence_size = current_sequence_size;
        max_s_num = cur_s_num;
    }


    for(int cnt = 0; cnt < max_sequence_size; cnt++)
        cout << max_s_num << " ";

    cout << endl;

    return 0;
}

// Above Average

int main(){

    int N;
    int average = 0;
    array<int, 99> numbers;

    cin >> N;
    for(int cnt = 0; cnt < N; cnt++){
        cin >> numbers[cnt];
        average += numbers[cnt];
    }

    average = average / N;

    for(int cnt = 0; cnt < N; cnt++){
        if (numbers[cnt] >= average) {
            cout << numbers[cnt] << ' ' << flush;
        }
    }

    cout << endl;

    return 0;
}

// Most Frequent Number

int main() {
    int N;
    cin >> N;

    array<int, 99> numbers;
    array<int, 10> counters = {};

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
        counters[numbers[i]]++;
    }

    int max_count = 0;
    vector<int> most_frequent;

    for (int digit = 0; digit < 10; ++digit) {
        if (counters[digit] > max_count) {
            max_count = counters[digit];
            most_frequent.clear();
            most_frequent.push_back(digit);
        } else if (counters[digit] == max_count && max_count > 0) {
            most_frequent.push_back(digit);
        }
    }

    for (int val : most_frequent)
        cout << val << " ";
    cout << endl;

    return 0;
}

// int main(){

//     int N;
//     array<int, 99> numbers;

//     cin >> N;
//     for(int cnt = 0; cnt < N; cnt++){
//         cin >> numbers[cnt];
//     }

//     int counters[10] = {};

//     for(int cnt = 0; cnt < N; cnt++) {
//         int current = numbers[cnt];
//         counters[current]++;
//     }

//     int max_count = 0;

//     for(int cnt = 0; cnt < 10; cnt++){
//         if (counters[cnt] > max_count)
//             max_count = counters[cnt];
//     }

//     for(int cnt = 0; cnt < 10; cnt++){
//         if (counters[cnt] == max_count)
//             cout << cnt << " ";
//     }
//     cout << endl;

//     return 0;
// }

// Cartesian Product

int main() {
    int N;
    cin >> N;

    int numbers[MAXSIZE];

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << numbers[i] * numbers[j] << " ";
        }
    }

    cout << endl;
    return 0;
}

// Closest Numbers

int main() {
    int N;
    cin >> N;

    int numbers[MAXSIZE];

    for (int cnt = 0; cnt < N; cnt++) {
        cin >> numbers[cnt];
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    int min_diff = INT_MAX;

    for (int first = 0; first < N - 1; first++)
        for (int second = first+1; second < N; second++) {
            int diff = abs(numbers[first] - numbers[second]);
            if (diff < min_diff) {
                min_diff = diff;
            }
    }

    cout << min_diff << endl;

    return 0;
}

// Array Rotation

int main() {
    int N;
    cin >> N;

    int numbers[MAXSIZE];
    for (int cnt = 0; cnt < N; cnt++) {
        cin >> numbers[cnt];
    }

    int R;
    cin >> R;

    R = R % N;

    for (int cnt = 0; cnt < N; cnt++) {
        cout << numbers[(cnt + R) % N] << " ";
    }

    cout << endl;
    return 0;
}

// Top Integers

int main() {
    int N;
    cin >> N;

    int numbers[MAXSIZE];
    for (int cnt = 0; cnt < N; cnt++) {
        cin >> numbers[cnt];
    }

    vector<int> topIntegers;
    int maxRight = numbers[N - 1];
    topIntegers.push_back(maxRight);

    for (int cnt = N - 2; cnt >= 0; cnt--) {
        if (numbers[cnt] > maxRight) {
            topIntegers.push_back(numbers[cnt]);
            maxRight = numbers[cnt];
        }
    }

    for (int cnt = topIntegers.size() - 1; cnt >= 0; cnt--) {
        cout << topIntegers[cnt] << " ";
    }

    cout << endl;
    return 0;
}

// Magic Sum

int main() {
    int N;
    cin >> N;

    int numbers[MAXSIZE];
    for (int cnt = 0; cnt < N; cnt++) {
        cin >> numbers[cnt];
    }

    int magicSum;
    cin >> magicSum;

    for (int cnt = 0; cnt < N - 1; cnt++) {
        for (int scnd = cnt + 1; scnd < N; scnd++) {
            if (numbers[cnt] + numbers[scnd] == magicSum) {
                cout << numbers[cnt] << " " << numbers[scnd] << endl;
            }
        }
    }

    return 0;
}
