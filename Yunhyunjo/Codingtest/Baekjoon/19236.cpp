#include <iostream>
#include <vector>

using namespace std;
pair <int, int> shark;
int dshark[2];

int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,0,-1,-1,-1,0,1,1,1 };
vector <pair <int, int>> d(17);
vector <vector <pair <int, int>>> grid;

void change();
void dfs();

int main() {

	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) {
		vector <pair <int, int>> v;
		int arr[2];
		for (int j = 0; j < 8; j++) {
			cin >> arr[j % 2];
			if (j % 2 == 1) {
				v.push_back(make_pair(arr[0], arr[1]));
				d[arr[0]] = make_pair(i, j / 2);
			}
		}
		grid.push_back(v);
	}

	shark = make_pair(grid[0][0].first, grid[0][0].second);
	d[grid[0][0].first] = { -1,-1 };
	dshark[0] = 0;
	dshark[1] = 0;
	grid[0][0] = { -1, -1 };

	change();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << grid[i][j].first << ", " << grid[i][j].second << " | ";
		}
		cout << endl;
	}

	return 0;
}

void change() {
	for (int i = 1; i <= 16; i++) {
		int x = d[i].first;
		int y = d[i].second;
		if (x == -1) continue;
		int n = 8;
		int j = grid[x][y].second;
		while(n--) {
			if (x + dx[j] >= 0 && x + dx[j] < 4 && y + dy[j] >= 0 && y + dy[j] < 4) {
				if (x + dx[j] != dshark[0] || y + dy[j] != dshark[1]) {
					pair <int, int> tmp = make_pair(grid[x][y].first, j);
					grid[x][y] = grid[x + dx[j]][y + dy[j]];
					grid[x + dx[j]][y + dy[j]] = tmp;
					d[i] = make_pair(x + dx[j], y + dy[j]);
					d[grid[x][y].first] = make_pair(x, y);
					break;
				}
			}
			j++;
			if (j == 9) j = 1;
		}
	}
}

void dfs() {
	for (int i = 1; i <= 3; i++){
		if (dshark[0] + (dx[shark.second] * i) >= 0 && dshark[0] + (dx[shark.second] * i) < 4 && dshark[1] + (dy[shark.second] * i) >= 0 && dshark[1] + (dy[shark.second] * i) < 4) {
			if (grid[dshark[0] + (dx[shark.second] * i)][dshark[1] + (dy[shark.second] * i)].first != -1) {
				dshark[0] = dshark[0] + (dx[shark.second] * i);
				dshark[1] = dshark[1] + (dy[shark.second] * i);
				shark.first += grid[dshark[0]][dshark[1]].first;
				shark.second = grid[dshark[0]][dshark[1]].second;
				d[grid[dshark[0]][dshark[1]].first] = { -1,-1 };
				grid[dshark[0]][dshark[1]] = { -1,-1 };
			}
			else break;
		 }
	}
}