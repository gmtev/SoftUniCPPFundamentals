#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


// Remove Negatives and Reverse

vector<int> readNumbers(const string & str) {
    vector<int> res;

    istringstream istr(str);

    int tmp;
    while(istr >> tmp)
        res.push_back(tmp);
    
        return res;
}

void removeNegatives(vector<int> & numbers) {

    for(vector<int>::iterator it = numbers.begin(); it != numbers.end();) {
        if (*it < 0) {
            it = numbers.erase(it);
        } else {
            it++;
        }
    }
}

// void print(const vector<int> numbers) {

//     if (numbers.size() == 0) {
//         cout << "empty" << endl;
//         return;
//     }

//     for(int i : numbers)
//         cout << i << ' ' << flush;
//     cout << endl;
// }

void printReverse(const vector<int> & numbers) {

    if (numbers.size() == 0) {
        cout << "empty" << endl;
        return;
    }

    vector<int>::const_iterator it = numbers.end();
    it--;

    while(true) {
        cout << *it << ' ';
        if (it == numbers.begin()) {
            break;
        }
        it--;
    }
    cout << endl;
} 

int main() {

    string buffer;
    getline(cin, buffer);

    vector<int> numbers = readNumbers(buffer);
    removeNegatives(numbers);
    printReverse(numbers);

    return 0;
}

// Products

int main() {

    vector<string> products;

    vector<string>::size_type numProducts;
    cin >> numProducts;
    cin.ignore(); // to not mess with the following getline
    products.reserve(numProducts);

    while(numProducts--) {
        string product;
        getline(cin, product);
        products.push_back(product);
    }

    sort(products.begin(), products.end());

    for(vector<string>::size_type curProduct = 0; curProduct < products.size(); curProduct++) {
        cout << curProduct+1 << '.' << products[curProduct] << endl;
    }


    return 0;
}

// Gauss Trick

int main() {

    string buffer;
    getline(cin, buffer);

    vector<int> numbers = readNumbers(buffer);
    list<int> result;
    vector<int>::size_type from = 0, to = numbers.size()-1;

    for(; from <= to; from++, to--) {
        if (from != to)
            result.push_back(numbers[from] + numbers[to]);
        else {
            result.push_back(numbers[from]);
            break;
        }
    }

    for(int i : result)
        cout << i << ' ';
    cout << endl;


    return 0;
}

// Merging Lists

list<int> readNumbersList(istream & inputStream) {
    list<int> res;

    string buffer;
    getline(inputStream, buffer);

    istringstream istr(buffer);

    int tmp;
    while(istr >> tmp)
        res.push_back(tmp);
    
        return res;
}

int main() {

    list<int> i1 = readNumbersList(cin);
    list<int> i2 = readNumbersList(cin);

    list<int> result;

    list<int>::iterator i1iter = i1.begin();
    list<int>::iterator i2iter = i2.begin();

    while(i1iter != i1.end() || i2iter != i2.end()) {

        if (i1iter != i1.end()) {
            result.push_back(*i1iter);
            i1iter++;
        }

        if (i2iter != i2.end()) {
            result.push_back(*i2iter);
            i2iter++;
        }
    }

    for(int i : result)
        cout << i << ' ' << flush;
    cout << endl;

    return 0;
}

// Manipulations

vector<int> readNumbersFinal(istream & inputStream) {
    vector<int> res;

    string buffer;
    getline(inputStream, buffer);

    istringstream istr(buffer);

    int tmp;
    while(istr >> tmp)
        res.push_back(tmp);
    
        return res;
}

int main() {

    vector<int> result = readNumbersFinal(cin);
    while(true) {
        string buffer;
        getline(cin, buffer);

        if (buffer == "end")
            break;
        
            istringstream istr(buffer);

            string command;
            istr >> command;
            int par1;
            istr >> par1;

            if (command == "Add") {
                result.push_back(par1);
            } else if (command == "Remove") {
                vector<int>::iterator itFound = find(result.begin(), result.end(), par1);
                if (itFound != result.end()) {
                    result.erase(itFound);
                }
            } else if (command == "RemoveAt") {
                result.erase(result.begin() + par1);
            } else if (command == "Insert") {
                int par2;
                istr >> par2;
                result.insert(result.begin() + par2, par1);
            } else {
                cout << "Error!" << endl;
            }
    }

    for(int i : result)
        cout << i << ' ' << flush;
    cout << endl;

    return 0;
}
