#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int map[20][20];
int ch[20][20];
struct Shark {
	int s, c, t;
	void sizeUp() {
		s++;
		c = 0;
	}
};

struct Point {
	int x, y, t;
	Point(int x, int y, int t) {
		this->x = x;
		this->y = y;
		this->t = t;
	}
};
int main() {

	ios_base::sync_with_stdio(false);

	int n, res = 0;

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				a = i;
				b = j;
			}
		}
	}
	Shark sh;
	sh.s = 2;
	sh.c = 0;
	sh.t = 0;
	int dx[] = { -1, 0, 0, 1 };
	int dy[] = { 0, -1, 1, 0 };
	queue <Point> q;
	q.push(Point(a, b, 0));
	while (!q.empty()){
		Point p = q.front();
		q.pop();
		if (map[p.x][p.y] != 0 && map[p.x][p.y] < sh.s) {
			sh.c++;
			map[p.x][p.y] = 0;
			if (sh.c == sh.s) sh.sizeUp();
			while (!q.empty()) q.pop();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ch[i][j] = 0;
				}
			}
			sh.t = p.t;
		}
		for (int i = 0; i < 4; i++) {
			if (p.x + dx[i] >= 0 && p.x + dx[i] < n && p.y + dy[i] >= 0 && p.y + dy[i] < n && ch[p.x + dx[i]][p.y + dy[i]] == 0) {
				q.push(Point(p.x + dx[i], p.y + dy[i], p.t + 1));
				ch[p.x + dx[i]][p.y + dy[i]] = 1;
			}
		}
	}

	cout << sh.t;

	return 0;
}