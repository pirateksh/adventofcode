// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


bool is_valid_index(int size, int i, int j) {
    return (i >= 0 && i < size) && (j >= 0 && j < size);
}

// Brute force++ :D
int count_xmas(vector<vector<char>> &matrix, int i, int j) {
    if (matrix[i][j] != 'X') return 0;
    
    int n = matrix.size(), count = 0;
    
    // Check below
    if (is_valid_index(n, i+1, j) && matrix[i+1][j] == 'M') {
        if (is_valid_index(n, i+2, j) && matrix[i+2][j] == 'A') {
            if (is_valid_index(n, i+3, j) && matrix[i+3][j] == 'S') {
                ++count;
            }
        }
    }
    
    // Check up
    if (is_valid_index(n, i-1, j) && matrix[i-1][j] == 'M') {
        if (is_valid_index(n, i-2, j) && matrix[i-2][j] == 'A') {
            if (is_valid_index(n, i-3, j) && matrix[i-3][j] == 'S') {
                ++count;
            }
        }
    }
    
    // Check right
    if (is_valid_index(n, i, j+1) && matrix[i][j+1] == 'M') {
        if (is_valid_index(n, i, j+2) && matrix[i][j+2] == 'A') {
            if (is_valid_index(n, i, j+3) && matrix[i][j+3] == 'S') {
                ++count;
            }
        }
    }
    
    // Check left
    if (is_valid_index(n, i, j-1) && matrix[i][j-1] == 'M') {
        if (is_valid_index(n, i, j-2) && matrix[i][j-2] == 'A') {
            if (is_valid_index(n, i, j-3) && matrix[i][j-3] == 'S') {
                ++count;
            }
        }
    }
    
    // Check left up
    if (is_valid_index(n, i-1, j-1) && matrix[i-1][j-1] == 'M') {
        if (is_valid_index(n, i-2, j-2) && matrix[i-2][j-2] == 'A') {
            if (is_valid_index(n, i-3, j-3) && matrix[i-3][j-3] == 'S') {
                ++count;
            }
        }
    }
    
    // Check left down
    if (is_valid_index(n, i+1, j-1) && matrix[i+1][j-1] == 'M') {
        if (is_valid_index(n, i+2, j-2) && matrix[i+2][j-2] == 'A') {
            if (is_valid_index(n, i+3, j-3) && matrix[i+3][j-3] == 'S') {
                ++count;
            }
        }
    }
    
    // Check right down
    if (is_valid_index(n, i+1, j+1) && matrix[i+1][j+1] == 'M') {
        if (is_valid_index(n, i+2, j+2) && matrix[i+2][j+2] == 'A') {
            if (is_valid_index(n, i+3, j+3) && matrix[i+3][j+3] == 'S') {
                ++count;
            }
        }
    }
    
    // Check right up
    if (is_valid_index(n, i-1, j+1) && matrix[i-1][j+1] == 'M') {
        if (is_valid_index(n, i-2, j+2) && matrix[i-2][j+2] == 'A') {
            if (is_valid_index(n, i-3, j+3) && matrix[i-3][j+3] == 'S') {
                ++count;
            }
        }
    }
    
    return count;
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
