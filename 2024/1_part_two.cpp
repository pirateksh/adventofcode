#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n = 1000; // Found by pasting the input in vs code.
    vector<ll> list_a(n), list_b(n);
    unordered_map<ll, ll> list_b_frequency;
    
    for (int i = 0; i < n; ++i) {
        cin >> list_a[i] >> list_b[i]; 
        list_b_frequency[list_b[i]]++;
    }
    
    ll similarity_score = 0;
    
    for (int i = 0; i < n; ++i) {
        ll element = list_a[i];
        similarity_score += (element * list_b_frequency[element]);
    }
    
    cout << endl << "Answer is: " << similarity_score << endl;
    
    return 0;
}
