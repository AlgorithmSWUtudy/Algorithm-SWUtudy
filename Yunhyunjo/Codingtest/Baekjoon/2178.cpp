#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a;
	cin >> n >> m;
	vector <string> v(n);
	vector <vector <int>> ch(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ch[i].resize(m, 0);
	}

	queue <pair <int, int>> q;
	q.push(make_pair(0, 0));
	ch[0][0] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == n - 1 && b == m - 1) break;
		for (int i = 0; i < 4; i++) {
			int x = a + dx[i];
			int y = b + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '0' && ch[x][y] == 0) {
				ch[x][y] = ch[a][b] + 1;
				q.push(make_pair(x, y));
			}
		}
	}

	cout << ch[n - 1][m - 1];

	return 0;
}