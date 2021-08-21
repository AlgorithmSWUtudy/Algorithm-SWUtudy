#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> train;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s = "00000000000000000000";
		train.push_back(s);
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			train[b - 1][c - 1] = '1';
		}
		else if (a == 2) {
			cin >> c;
			train[b - 1][c - 1] = '0';
		}
		else if (a == 3) {
			for (int j = 19; j > 0; j--) {
				train[b - 1][j] = train[b - 1][j-1];
			}
			train[b - 1][0] = '0';
		}
		else {
			for (int j = 0; j < 19; j++) {
				train[b - 1][j] = train[b - 1][j + 1];
			}
			train[b - 1][19] = '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (train[i] == train[j]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		cnt++;
	}

	cout << cnt;

	return 0;
}