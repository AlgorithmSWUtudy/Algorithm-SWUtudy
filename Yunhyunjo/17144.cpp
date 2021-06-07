#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int x1, yy1, x2, y2;
vector < vector <int>> clean(vector <vector <int>> v, int r, int c);
vector < vector <int>> spread(vector <vector <int>> v, int r, int c) {
	int ch[50][50] = { 0, };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int cc = 0;
			if (v[i][j] == -1) continue;
			if (v[i][j] != 0) {
				int rd = v[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int xx = i + dx[k];
					int yy = j + dy[k];
					if (xx >= 0 && xx < r && yy >= 0 && yy < c && v[xx][yy] != -1) {
						cc++;
						ch[xx][yy] += rd;
					}
				}
				v[i][j] = v[i][j] - (rd * cc);
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] == -1) continue;
			v[i][j] += ch[i][j];
		}
	}

	return clean(v,r,c);
}

vector < vector <int>> clean(vector <vector <int>> v, int r, int c) {
	int tmp1 = 0, tmp2 = 0, tmp3, tmp4;

	for (int i = 1; i < c; i++) {
		tmp3 = v[x1][i];
		tmp4 = v[x2][i];
		v[x1][i] = tmp1;
		v[x2][i] = tmp2;
		tmp1 = tmp3;
		tmp2 = tmp4;
	}

	int a = 1;
	while (1) {
		if (x1 - a < 0 && x2 + a >= r) break;
		if (x1 - a >= 0) {
			tmp3 = v[x1 - a][c - 1];
			v[x1 - a][c - 1] = tmp1;
			tmp1 = tmp3;
		}
		if (x2 + a < r) {
			tmp4 = v[x2 + a][c - 1];
			v[x2 + a][c - 1] = tmp2;
			tmp2 = tmp4;
		}
		a++;
	}
	
	for (int i = c - 1; i >= 0; i--) {
		tmp3 = v[0][i];
		tmp4 = v[r-1][i];
		v[0][i] = tmp1;
		v[r-1][i] = tmp2;
		tmp1 = tmp3;
		tmp2 = tmp4;
	}

	a = 1;
	int t1 = 0, t2 = r-1;
	while (1) {
		if (t1 + a >= x1 && x2 - a <= x2) break;
		if (t1 + a < x1) {
			tmp3 = v[t1 + a][0];
			v[t1 + a][0] = tmp1;
			tmp1 = tmp3;
		}
		if (x2 - a > x2) {
			tmp4 = v[t2 - a][0];
			v[t2 - a][0] = tmp2;
			tmp2 = tmp4;
		}
		a++;
	}

	return v;
}

int main() {

	ios_base::sync_with_stdio(false);

	int r, c, t;

	cin >> r >> c >> t;
	vector <vector <int>> map;
	bool flag = true;
	for (int i = 0; i < r; i++) {
		vector <int> a(c);
		for (int j = 0; j < c; j++) {
			cin >> a[j];
			if (a[j] == -1) {
				if (flag) {
					x1 = i; 
					yy1 = j;
					flag = !flag;
				}
				else {
					x2 = i; 
					y2 = j;
				}
			}
		}
		map.push_back(a);
	}

	for (int i = 0; i < t; i++) {
		map = spread(map, r, c);
	}
	int cnt = 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cnt += map[i][j];
		}
	}
	cout << cnt;
	return 0;
}