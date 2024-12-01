#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1000; // Found by pasting the input in vs code.
    vector<int> list_a(n), list_b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> list_a[i] >> list_b[i]; 
    }
    
    sort(list_a.begin(), list_a.end());
    sort(list_b.begin(), list_b.end());
    
    int difference = 0;
    
    for (int i = 0; i < n; ++i) {
        difference += abs(list_a[i] - list_b[i]);    
    }
    
    cout << endl << "Answer is: " << difference << endl;
    
    return 0;
}
