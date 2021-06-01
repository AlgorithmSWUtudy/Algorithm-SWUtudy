#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

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

	int dx = 0;
	int dy = 1;
	int idx = 0;
	int hx = 1, hy = 1, tx = 1, ty = 1;
	bool flag;
	int t = 0;
	while (1) {
		for (int i = 0; i < v[idx].first; i++) {
			if (hx + dx > 0 && hx + dx <= n && hy + dy > 0 && hy + dy <= n && map[hx + dx][hy + dy] != 2) {
				t++;
				if (map[hx + dx][hy + dy] == 1) {
					hx += dx;
					hy += dy;
					map[hx + dx][hy + dy] = 2;
				}
				else {
					hx += dx;
					hy += dy;
				}
			}
			else {
				break;
				flag = true;
			}
		}
		if (flag) break;
		if (v[idx].second == 'L') {
			dx = -dx;
			dy = -dy;
		}
		else {
			int tmp = dx;
			dx = dy;
			dy = tmp;
		}
	}

	cout << t;

	return 0;
}