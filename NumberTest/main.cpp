#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> digits = {
    {1, 100},
    {2, 200},
    {3, 200},
    {4, 2000},
    {5, 1000},
    {6, 700},
    {7, 400},
    {8, 300},
    {9, 1500},
    {10, 3000},
    {11, 4000},
    {12, 2500},
    {13, 2000},
    {14, 500}
};

vector<vector<int>> get_combinations(int total) {
    vector<vector<int>> valid_combinations;
    int n = digits.size();
    for (int i = 0; i < (1 << n); i++) {
        vector<int> combination;
        bool hasEight = false;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                int digit = next(digits.begin(), j)->first;
                combination.push_back(digit);
                if (digit == 8) {
                    hasEight = true;
                }
            }
        }
        if (find(combination.begin(), combination.end(), 1) == combination.end()) {
            continue;
        }
        if (find(combination.begin(), combination.end(), 9) != combination.end() && !hasEight) {
            continue;
        }
        if (find(combination.begin(), combination.end(), 10) != combination.end() && !hasEight) {
            continue;
        }
        if (!hasEight && find(combination.begin(), combination.end(), 5) == combination.end() && find(combination.begin(), combination.end(), 1) == combination.end()) {
            continue;
        }
        int sum = 0;
        for (int digit : combination) {
            sum += digits[digit];
        }
        if (sum == total) {
            valid_combinations.push_back(combination);
        }
    }
    return valid_combinations;
}

int main() {
    int total;
    cout << "Enter your total" << endl;
    cin >> total;
    vector<vector<int>> combinations = get_combinations(total);
    for (vector<int> combination : combinations) {
        for (int digit : combination) {
            cout << digit << " ";
        }
        cout << endl;
    }
    return 0;
}