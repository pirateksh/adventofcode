#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define node pair<pair<ll,ll>, pair<ll,ll>>  // {{score, direction}, {dx,dy}}
// Direction: 0 - East, 1 - South, 2 - West, 3 - North
#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

int dx[4] = {-1, 1, 0, 0};  // Row offsets for up, down, left, right
int dy[4] = {0, 0, -1, 1};  // Column offsets for up, down, left, right
int directions[4] = {NORTH, SOUTH, WEST, EAST};

bool is_valid_index(int n, int x, int y) {
    return ((x >= 0 && x < n) && (y >= 0 && y < n));
}

bool is_complement(int direction, int new_direction) {
    return 
    (direction == SOUTH && new_direction == NORTH)
    ||
    (direction == NORTH && new_direction == SOUTH)
    ||
    (direction == EAST && new_direction == WEST)
    ||
    (direction == WEST && new_direction == EAST);
}

node make_node(ll score, ll direction, ll dx, ll dy) {
    return make_pair(make_pair(score, direction), make_pair(dx, dy));
}

ll get_score(node current) {
    return current.first.first;
}

ll get_direction(node current) {
    return current.first.second;
}

ll get_x(node current) {
    return current.second.first;
}

ll get_y(node current) {
    return current.second.second;
}

int main() {
	ll n = 141;
	vector<string> grid;
	for (ll i = 0; i < n; ++i) {
	    string input;
	    cin >> input;
	    grid.push_back(input);
	    
	}
	   
   node start;
	for (ll i = 0; i < n; ++i) {
	    for (ll j = 0; j < grid[i].size(); ++j) {
	        if (grid[i][j] == 'S') {
    	        start = make_node(0, EAST, i, j);
    	    }
	    }
	}
	
	set<node> queue;
	queue.insert(start);
	
	while(!queue.empty()) {
	    node current = *(queue.begin());
	    ll score = get_score(current);
	    ll direction = get_direction(current);
	    ll x = get_x(current);
	    ll y = get_y(current);
	    
	    if (grid[x][y] == 'E') {
	        cout << "Answer is: " << score << endl;
	        break;
	    }
	    
	    queue.erase(current);
	    
	    for (ll i = 0; i < 4; i++) {
            ll new_x = x + dx[i];
            ll new_y = y + dy[i];
            ll new_direction = directions[i];
        
            if (is_valid_index(n, new_x, new_y) && grid[new_x][new_y] != '#') {
                if (direction == new_direction) { // Move
                    queue.insert(make_node(score + 1, new_direction, new_x, new_y));
                } else if(!is_complement(direction, new_direction)) { // Turn only 90 degree.
                    queue.insert(make_node(score + 1000, new_direction, x, y));
                }
            }
        }
	}

}
