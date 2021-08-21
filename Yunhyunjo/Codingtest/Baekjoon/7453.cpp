#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector <vector <int> > v(n);
	int a, b, c, d;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		v[0].push_back(a);
		v[1].push_back(b);
		v[2].push_back(c);
		v[3].push_back(b);
	}

	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = v[0][i] + v[1][j];
			for (int k = 0; k < n; k++) {

			}
		}
	}

	cout << cnt;

	return 0;
}