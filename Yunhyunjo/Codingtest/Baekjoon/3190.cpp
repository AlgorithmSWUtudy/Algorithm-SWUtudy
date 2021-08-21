#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int map[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {

	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;

		map[x][y] = 1;
	}
	map[1][1] = 2;
	int L;
	cin >> L;

	vector <pair <int, char>> v(L);
	for (int i = 0; i < L; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int dir = 0;
	int idx = 0;
	int hx, hy;
	deque < pair <int, int>> snake;
	snake.push_back(make_pair(1, 1));
	bool flag = false;
	int t = 0;
	while (1) {
		if (idx >= L) {
			hx = snake.back().first;
			hy = snake.back().second;
			t++;
			if (hx + dx[dir] > 0 && hx + dx[dir] <= n && hy + dy[dir] > 0 && hy + dy[dir] <= n && map[hx + dx[dir]][hy + dy[dir]] != 2) {
				if (map[hx + dx[dir]][hy + dy[dir]] == 1) {
					snake.push_back(make_pair(hx + dx[dir], hy + dy[dir]));
					map[hx + dx[dir]][hy + dy[dir]] = 2;
				}
				else {
					snake.push_back(make_pair(hx + dx[dir], hy + dy[dir]));
					int a = snake.front().first;
					int b = snake.front().second;
					map[a][b] = 0;
					map[hx + dx[dir]][hy + dy[dir]] = 2;
					snake.pop_front();
				}
			}
			else break;
			continue;
		}
		int num = v[idx].first - t;
		for (int i = 0; i < num; i++) {
			hx = snake.back().first;
			hy = snake.back().second;
			t++;
			if (hx + dx[dir] > 0 && hx + dx[dir] <= n && hy + dy[dir] > 0 && hy + dy[dir] <= n && map[hx + dx[dir]][hy + dy[dir]] != 2) {
				if (map[hx + dx[dir]][hy + dy[dir]] == 1) {
					snake.push_back(make_pair(hx + dx[dir], hy + dy[dir]));
					map[hx + dx[dir]][hy + dy[dir]] = 2;
				}
				else {
					snake.push_back(make_pair(hx + dx[dir], hy + dy[dir]));
					int a = snake.front().first;
					int b = snake.front().second;
					map[a][b] = 0;
					map[hx + dx[dir]][hy + dy[dir]] = 2;
					snake.pop_front();
				}
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag) break;
		if (dir == 0) {
			if (v[idx].second == 'L') dir = 3;
			else dir = 1;
		}
		else if (dir == 1) {
			if (v[idx].second == 'L') dir = 0;
			else dir = 2;
		}
		else if (dir == 2) {
			if (v[idx].second == 'L') dir = 1;
			else dir = 3;
		}
		else {
			if (v[idx].second == 'L') dir = 2;
			else dir = 0;
		}
		
		idx++;
	}

	cout << t;

	return 0;
}