#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define node pair<ll,ll>

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, 1, -1};

bool is_valid(ll size, ll x, ll y) {
    return ((x >= 0 && x < size) && (y >= 0 && y < size));
}

node make_node(ll x, ll y) {
    return make_pair(x, y);
}

ll get_x(node m) {
    return m.first;
}

ll get_y(node m) {
    return m.second;
}

int main() {
	int size = 141;
	vector<string> racetrack(size);
	node start;
	
	for (ll i = 0; i < size; ++i) {
	    string input;
	    cin >> input;
	    racetrack[i] = input;
	}
	
	for (ll i = 0; i < size; ++i) {
	    for (ll j = 0; j < size; ++j) {
	        if (racetrack[i][j] == 'S') {
	            start = make_node(i, j);
	        }
	    }
	}
	
	map<node, node> path_map; // {to: from}
	
	queue<node> q;
	vector<vector<bool>> visited(size, vector<bool>(size, false));
	
	q.push(start);
	visited[get_x(start)][get_y(start)] = true;
	path_map[start] = make_node(-1, -1);
	node temp;
	
	while(!q.empty()) {
	    node current = q.front();
	    ll current_x = get_x(current);
	    ll current_y = get_y(current);
	    q.pop();
	    
	    if (racetrack[current_x][current_y] == 'E') {
	        temp = current;
	        break;
	    }
	    
	    for (ll i = 0; i < 4; ++i) {
	        ll new_x = current_x + dx[i];
	        ll new_y = current_y + dy[i];
	        
	        if (is_valid(size, new_x, new_y) 
	            && !visited[new_x][new_y] 
	            && racetrack[new_x][new_y] != '#') {
	            node new_ = make_node(new_x, new_y);
	            q.push(new_);
	            visited[new_x][new_y] = true;
	            path_map[new_] = current;
	        }
	    }
	}
	
	vector<node> path;
    while(get_x(temp) != -1) {
        path.push_back(temp);
        temp = path_map[temp];
    }
    
    reverse(path.begin(), path.end());
    
    ll answer = 0;
    
    for (ll k = 2; k <= 20; ++k) {
        for (ll i = 0; i < path.size(); ++i) {
            ll fx = path[i].first, fy = path[i].second;
            for (ll j = i + 1; j < path.size(); ++j) {
                ll sx = path[j].first, sy = path[j].second;
                if (abs(sx - fx) + abs(sy - fy) == k) {
                    ll saved = j - i - k;
                    if (saved >= 100) ++answer;
                }
            }
        }
    }
    
    cout << "Answer is: " << answer << endl;

}
