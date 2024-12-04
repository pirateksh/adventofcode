// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


bool is_valid_index(int size, int i, int j) {
    return (i >= 0 && i < size) && (j >= 0 && j < size);
}

int count_xmas(vector<vector<char>> &matrix, int i, int j) {
    if (matrix[i][j] != 'A') return 0;
    
    int n = matrix.size();
    
    if(is_valid_index(n, i+1, j+1) && is_valid_index(n, i-1, j+1) && is_valid_index(n, i+1, j-1) && is_valid_index(n, i-1, j-1)) {
        
        if (
            (
                (matrix[i+1][j+1] == 'M' && matrix[i-1][j-1] == 'S') 
                || 
                (matrix[i+1][j+1] == 'S' && matrix[i-1][j-1] == 'M')
            )
            &&
            (
                (matrix[i-1][j+1] == 'M' && matrix[i+1][j-1] == 'S') 
                || 
                (matrix[i-1][j+1] == 'S' && matrix[i+1][j-1] == 'M')
            )
        ) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int n = 140;
    vector<vector<char>> matrix(n);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            char input;
            cin >> input;
            matrix[i].push_back(input);
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            answer += count_xmas(matrix, i, j);
        }
    }
    
    cout << "Answer is: " << answer << endl;

    return 0;
}
