#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > grid;
int dx[] = { -1,-1,-1,-2,0,1,1,1,2,0 };
int dy[] = { -1,0,1,0,-2,-1,0,1,0,-1 };
double dz[] = { 0.1,0.07,0.01,0.02,0.05,0.1,0.07,0.01,0.02 };

int cx[4] = { 0,1,0,-1 };
int cy[4] = { -1,0,1,0 };
int n;
int sand = 0;

void tornado(int x, int y, int d) {
	int total = 0;
	for (int i = 0; i < 10; i++) {
		//if(i != 9) total = total + grid[x][y] * dz[i];
		if (d == 0) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n) {
				if (i == 9) {
					grid[x + dx[i]][y + dy[i]] = grid[x][y] - total;
					continue;
				}
				grid[x + dx[i]][y + dy[i]] = grid[x + dx[i]][y + dy[i]] + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
				cout << x + dx[i] << " : " << y + dy[i] << " , ";
			}
			else {
				if (i == 9) {
					sand = sand + grid[x][y] - total;
					continue;
				}
				sand = sand + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
			}
		}
		else if (d == 1) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + (-dy[i]) >= 0 && y + (-dy[i]) < n) {
				if (i == 9) {
					grid[y + (-dy[i])][x + dx[i]] = grid[x][y] - total;
					continue;
				}
				grid[y + (-dy[i])][x + dx[i]] = grid[y + (-dy[i])][x + dx[i]] + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
				cout << y + (-dy[i]) << " : " << x + dx[i] << " , ";
			}
			else {
				if (i == 9) {
					sand = sand + grid[x][y] - total;
					continue;
				}
				sand = sand + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
			}
		}
		else if (d == 2) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + (-dy[i]) >= 0 && y + (-dy[i]) < n) {
				if (i == 9) {
					grid[x + dx[i]][y + (-dy[i])] = grid[x][y] - total;
					continue;
				}
				grid[x + dx[i]][y + (-dy[i])] = grid[x + dx[i]][y + (-dy[i])] + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
				cout << x + dx[i] << " : " << y + (-dy[i]) << " , ";
			}
			else {
				if (i == 9) {
					sand = sand + grid[x][y] - total;
					continue;
				}
				sand = sand + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
			}
		}
		else {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n) {
				if (i == 9) {
					grid[y + dy[i]][x + dx[i]] = grid[x][y] - total;
					continue;
				}
				grid[y + dy[i]][x + dx[i]] = grid[y + dy[i]][x + dx[i]] + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
				cout << y + dy[i] << " : " << x + dx[i] << " , ";
			}
			else {
				if (i == 9) {
					sand = sand + grid[x][y] - total;
					continue;
				}
				sand = sand + grid[x][y] * dz[i];
				total = total + grid[x][y] * dz[i];
				//cout << grid[x][y] * dz[i] << " ";
			}
		}
	}
	cout << sand << endl;
	grid[x][y] = 0;
}
int arr[499][499];
int main() {

	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		vector <int> aa;
		int b;
		for (int j = 0; j < n; j++) {
			cin >> b;
			aa.push_back(b);
		}
		grid.push_back(aa);
	}

	int d = 0, num = 0, c = 1, dc = 2;
	int nx = n / 2, ny = n / 2;
	while (1) {
		nx = nx + cx[d];
		ny = ny + cy[d];
		cout << nx << " " << ny << endl;
		if(grid[nx][ny] != 0) tornado(nx, ny, d);
		arr[nx][ny] = 1;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
		cout << endl;
		num++;
		
		if (num == c) {
			dc--;
			if (d == 3) d = 0;
			else d++;
			if (dc == 0) {
				c++;
				dc = 2;
			}
			num = 0;
		}
		if (nx == 0 && ny == 0) break;
	}

	cout << sand;

	return 0;
}