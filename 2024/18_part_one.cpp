#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[] = {0, 0, 1, -1};
ll dy[] = {-1, 1, 0, 0};

bool is_valid(ll size, ll x, ll y) {
    return ((x >= 0 && x < size) && (y >= 0 && y < size));
}

int main() {
	ll n = 3450;
	ll m = 71;
	ll fallen_bytes_count = 1024;
	vector<vector<ll>> bytes(n);
	
	for(ll i = 0; i < n; ++i) {
	    string input;
	    cin >> input;
	    stringstream ss(input);
	    
	    while(ss.good()) {
	        string num;
	        getline(ss, num, ',');
	        bytes[i].push_back(stoll(num));
	    }
	}
	
	char grid[m][m];
	bool visited[m][m];
	for (ll i = 0; i < m; ++i) {
	    for (ll j = 0; j < m; ++j) {
	        grid[i][j] = '.';
	    }
	}
	
	for(ll i = 0; i < fallen_bytes_count; ++i) {
	    ll x = bytes[i][1], y = bytes[i][0];
	    grid[x][y] = '#';
	}

	
	queue<vector<ll>> bfs_q; // [x, y, step_count]
	bfs_q.push({0, 0, 0});
	visited[0][0] = true;
	
	while(!bfs_q.empty()) {
	    vector<ll> current = bfs_q.front();
	    ll current_x = current[0], current_y = current[1];
	    ll step_count = current[2];
	    bfs_q.pop();
	    
	    if (current_x == m - 1 && current_y == m - 1) {
	        cout << "Answer is: " << step_count << endl;
	        break;
	    }

	    for (ll i = 0; i < 4; ++i) {
	        ll new_x = current_x + dx[i];
	        ll new_y = current_y + dy[i];
	        if (is_valid(m, new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y] != '#') {
	            bfs_q.push({new_x, new_y, step_count + 1LL});
	            visited[new_x][new_y] = true;
	        }
	    }
	}
}
