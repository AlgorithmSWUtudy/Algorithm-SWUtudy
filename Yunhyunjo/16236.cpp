#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int memo[20][20];

struct State {
	int x, y, dis;
	State(int x, int y, int dis) {
		this->x = x;
		this->y = y;
		this->dis = dis;
	}

	bool operator <(const State& a)const {
		if (dis == a.dis) {
			if (x == a.x) return y > a.y;
			else return x > a.x;
		}
		else return dis > a.dis;
	}
};

struct Shark {
	int x, y, ate = 0, size = 2;
	void sizeUp() {
		size++;
		ate = 0;
	}
};

int main() {

	ios_base::sync_with_stdio(false);

	int n, res = 0;
	Shark shark;

	cin >> n;

	vector <vector <int>> map;
	for (int i = 0; i < n; i++) {
		vector <int> a(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			if (a[j] == 9) {
				shark.x = i;
				shark.y = j;
				a[j] = 0;
			}
		}
		map.push_back(a);
	}

	int dx[] = { -1, 0 , 0, 1 };
	int dy[] = { 0, -1, 1, 0 };
	int ch[20][20] = { 0, };

	priority_queue <State> pq;
	pq.push(State(shark.x, shark.y, 0));

	while (!pq.empty()) {
		State tmp = pq.top();
		pq.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;
		if (map[x][y] != 0 && map[x][y] < shark.size) {
			shark.x = x;
			shark.y = y;
			shark.ate++;
			if (shark.ate >= shark.size) shark.sizeUp();
			map[x][y] = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ch[i][j] = 0;
				}
			}
			while (!pq.empty()) pq.pop();
			res = z;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= n || map[xx][yy] > shark.size || ch[xx][yy] > 0) continue;
			pq.push(State(xx, yy, z + 1));
			ch[xx][yy] = 1;
		}
	}

	cout << res;

	return 0;
}