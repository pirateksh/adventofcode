#include <bits/stdc++.h>
using namespace std;

bool is_diff_acceptable(int diff, int prev_diff) {
    return (abs(diff) >= 1) && (abs(diff) <= 3) && (diff * prev_diff > 0);
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
        int prev_diff = levels[i][0] - levels[i][1], j;
        if (!is_diff_acceptable(prev_diff, prev_diff)) continue;
        
        for (j = 2; j < levels[i].size(); ++j) {
            int curr_diff = levels[i][j-1] - levels[i][j];
            if (!is_diff_acceptable(curr_diff, prev_diff)) break;
            prev_diff = curr_diff;
        }
        
        if (j == levels[i].size()) ++count;
    }
    
    cout << endl << "Answer is: " << count;

    return 0;
}
