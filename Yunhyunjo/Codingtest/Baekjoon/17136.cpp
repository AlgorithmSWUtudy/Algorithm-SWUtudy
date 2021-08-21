#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mini = 2147000000;
int paper[25][2] = { {0,0},{0,1},{1,0},{1,1},{0,2},{1,2},{2,0},{2,1},{2,2},{0,3},{1,3},{2,3}, {3,0},{3,1},{3,2},{3,3},{0,4},{1,4}, {2,4},
	{3,4},{4,0},{4,1},{4,2},{4,3},{4,4} };
int pc[5] = { 5,5,5,5,5 };

bool isFill(int grid[10][10], int x, int y, int l) {
	for (int i = 0; i < l; i++) {
		int xx = x + paper[i][0];
		int yy = y + paper[i][1];
		if (xx >= 0 && xx < 10 && yy >= 0 && yy < 10 && grid[xx][yy] == 1) {
			continue;
		}
		else return false;
	}
	return true;
}

void fill(int grid[10][10], int x, int y, int l) {
	for (int i = 0; i < l; i++) {
		int xx = x + paper[i][0];
		int yy = y + paper[i][1];
		grid[xx][yy] = 0;
	}
}

void fill2(int grid[10][10], int x, int y, int l) {
	for (int i = 0; i < l; i++) {
		int xx = x + paper[i][0];
		int yy = y + paper[i][1];
		grid[xx][yy] = 1;
	}
}

void Count(int grid[10][10], int cnt) {
	int i, j;
	bool flag = false;
	for (i=0; i < 10; i++) {
		for (j=0; j < 10; j++) {
			if (grid[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (i == 10 && j == 10) {
		mini = min(mini, cnt);
		return;
	}
	for (int k = 5; k > 0; k--) {
		if (isFill(grid, i, j, k * k)) {
			if (pc[k - 1] == 0) continue;
			fill(grid, i, j, k * k);
			pc[k - 1]--;
			Count(grid, cnt + 1);
			fill2(grid, i, j, k * k);
			pc[k - 1]++;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int grid[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> grid[i][j];
		}
	}
	Count(grid, 0);
	if (mini == 2147000000) {
		cout << -1;
		return 0;
	}
	cout << mini;
	return 0;
}