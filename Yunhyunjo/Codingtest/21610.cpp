#include <iostream>
#include <vector>

using namespace std;

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int lx[4] = { -1, -1, 1, 1 };
int ly[4] = { -1, 1, -1, 1 };

int main() {

	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int arr[51][51];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	vector <pair <int, int>>r;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		r.push_back(make_pair(a, b));
	}

	vector <pair <int, int>> c;
	c.push_back(make_pair(n, 1));
	c.push_back(make_pair(n, 2));
	c.push_back(make_pair(n-1, 1));
	c.push_back(make_pair(n-1, 2));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < c.size(); j++) {
			c[j].first = c[j].first + dx[r[i].first] * r[i].second;
			c[j].second = c[j].second + dy[r[i].first] * r[i].second;
			int a = r[i].second % n;
			if (c[j].first < 1) c[j].first = n + a;
			else if (c[j].first > n) c[j].first = c[j].first - n;
		}
	}


	return 0;
}