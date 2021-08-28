#include <iostream>

using namespace std;

int matrix[9][9], check[81][2], n = 0;
int blank(int k);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> matrix[i][j];
			if (!matrix[i][j]) {
				check[n][0] = i;
				check[n][1] = j;
				n++;
			}

		}
	}

	blank(0);
}

int blank(int k) {
	bool positive[9] = { 0, };
	int x = check[k][0], y = check[k][1], s = 0;

	if (k == n) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}

		return 1;
	}

	int a = (x / 3) * 3, b = (y / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (matrix[i][y])
			positive[matrix[i][y] - 1] = true;
		if (matrix[x][i])
			positive[matrix[x][i] - 1] = true;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[a + i][b + j])
				positive[matrix[a + i][b + j] - 1] = true;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (s)
			return 1;
		if (!positive[i]) {
			matrix[x][y] = i + 1;
			s = blank(k+1);
			if (s)
				return 1;
			matrix[x][y] = 0;
		}
	}
	return 0;
}