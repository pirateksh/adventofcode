#include <bits/stdc++.h>
using namespace std;

bool is_diff_acceptable(int diff, int prev_diff) {
    return (abs(diff) >= 1) && (abs(diff) <= 3) && (diff * prev_diff > 0);
}

bool process_level(vector<int> level) {
    int prev_diff = level[0] - level[1];
    if (!is_diff_acceptable(prev_diff, prev_diff)) return false;
    
    for (int j = 2; j < level.size(); ++j) {
        int curr_diff = level[j-1] - level[j];
        if (!is_diff_acceptable(curr_diff, prev_diff)) return false;
        prev_diff = curr_diff;
    }
    
    return true;
}

bool is_tolerant(vector<int> level) {
    // Using brute force.
    for (int i = 0 ; i < level.size(); ++i) { // Exlude element at index i.
        vector<int> level_copy(level);
        level_copy.erase(level_copy.begin() + i);
        bool result = process_level(level_copy);
        if (result) return true;
    }
    return false;
}

int main() {
    int n = 1000;
    vector<vector<int>> levels(n);

    
    for(int i = 0; i < n; ++i) {
        string line;    
        getline(cin, line);
    
        stringstream ss(line);
        int number;
        while (ss >> number) {
            levels[i].push_back(number);
        }
    }
    
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (process_level(levels[i])) ++count;
        else if (is_tolerant(levels[i])) ++count;
    }
    
    cout << endl << "Answer is: " << count;

    return 0;
}
