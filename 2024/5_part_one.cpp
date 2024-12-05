#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1176, m = 174;
	unordered_map<int, vector<int>> ordering;
	
	for(int i = 0; i < n; ++i) {
	    string input;
	    cin >> input;
	    int num1 = stoi(input.substr(0, 2));
	    int num2 = stoi(input.substr(3, 2));
	    ordering[num1].push_back(num2);
	}
	
	vector<vector<int>> pages(m);
	for(int i = 0; i < m; ++i) {
	    string input;
	    cin >> input;
	    stringstream ss(input);
	    while(ss.good()) {
	        string num;
            getline(ss, num, ',');
            pages[i].push_back(stoi(num));
	    }
	}
	
	int answer = 0;
	
	for (int i = 0; i < m; ++i) {
	    int size = pages[i].size(), j, k;
	    for(j = 0; j < size; ++j) {
	        for (k = j + 1; k < size; ++k) {
	            int key = pages[i][j], value = pages[i][k];
	            auto it = find(ordering[key].begin(), ordering[key].end(), value);
	            if (it == ordering[key].end()) break; // Not found
	        }
	        if (k != size) break;
	    }
	    if (j == size) {
	        answer += pages[i][size / 2];
	    }
	}
	
	cout << "Answer is: " << answer << endl;

}
