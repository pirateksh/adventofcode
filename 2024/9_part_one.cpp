#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	string input;
	cin >> input;
	vector<ll> disk_map;
	
	ll total = 0;
	for(auto& s: input) {
	    ll num = s - '0';
	    disk_map.push_back(num);
	    total += num;
	}
	
	vector<ll> blocks(total, -1);
	ll id = 0, j = 0;
    
    for (ll i = 0; i < disk_map.size(); i += 2) {
        ll times = disk_map[i];
        while(times--) {
            blocks[j++] = id;
        }
        ++id;
        j += disk_map[i+1];
    }
    
    ll front = disk_map[0], back = total - 1;
    while (true) {
        if (front >= back) break;
        if (blocks[front] != -1) { // If front is not empty
            ++front;
            continue;
        }
        if (blocks[back] == -1) { // If back is empty
            --back;
            continue;
        }
        blocks[front] = blocks[back];
        blocks[back] = -1;
        ++front;
        --back;
    }
    
    ll answer = 0;
    
    for (ll i = 0; i < blocks.size(); ++i) {
        if (blocks[i] == -1) break;
        answer += i * blocks[i];
    }
    
    cout << "Answer is: " << answer << endl;
}
