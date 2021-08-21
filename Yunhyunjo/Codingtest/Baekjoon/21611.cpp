#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[50][50];
int bead[4];
int n, m;

void moveBeads();
int findBead(int a, int b, int d, int c, int e, int ce);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int x = (n + 1) / 2, y = x;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int j = 1; j <= b; j++) {
			int tx = x + dx[a - 1] * j;
			int ty = y + dy[a - 1] * j;
			if (tx > 0 && tx <= n && ty > 0 && ty <= n) {
				bead[map[tx][ty]]++;
				map[tx][ty] = 0;
			}
			else break;
		}
		moveBeads();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void moveBeads() {
	int a = (n + 1) / 2, b = a - 1;
	int bx[4] = { 1,0,-1,0 };
	int by[4] = { 0,1,0,-1 };
	int d = 0, c = 1, e = 1, ce = 0;
	while (map[a][b] != 0) {
		ce++;
		a += bx[d];
		b += by[d];
		if (e == ce) {
			ce = 0;
			c++;
			if (c == 2)
				e++;
		}
		if (c == 2) {
			c = 0;
			d = (d + 1) % 4;
		}
	}

	while (a > 0 && a <= n && b > 0 && b <= n) {
		int i = findBead(a + bx[d], b + by[d], d, c, e, ce);
		cout << a << " " << b << " : " << d << " " << c << " " << e << " " << ce << endl;
		if (i == -1) {
			map[a][b] = 0;
			break;
		}
		else map[a][b] = i;
		ce++;
		a += bx[d];
		b += by[d];
		if (e == ce) {
			ce = 0;
			c++;
			if (c == 2)
				e++;
		}
		if (c == 2) {
			c = 0;
			d = (d + 1) % 4;
		}
		
	}

}

int findBead(int a, int b, int d, int c, int e, int ce) {

	int bx[4] = { 1,0,-1,0 };
	int by[4] = { 0,1,0,-1 };

	while (1) {
		if (map[a][b] != 0) break;
		else {
			ce++;
			a += bx[d];
			b += by[d];
			if (e == ce) {
				ce = 0;
				c++;
				if (c == 2)
					e++;
			}
			if (c == 2) {
				c = 0;
				d = (d + 1) % 4;
			}
		}
		if (a < 1 || a > n || b < 1 || b > n) return -1;
	}

	return map[a][b];
}