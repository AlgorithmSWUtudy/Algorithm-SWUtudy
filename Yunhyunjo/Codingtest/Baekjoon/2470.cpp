#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int p1 = 0, p2 = n - 1;
	int tmp = 2147000000;
	int one, two;

	while (1) {
		if (p1 == p2) break;
		if (abs(v[p1] + v[p2]) <= tmp) {
			tmp = abs(v[p1] + v[p2]);
			one = v[p1];
			two = v[p2];
			if (tmp == 0) break;
		}
		if (v[p2] > abs(v[p1])) {
			p2--;
		}
		else p1++;
	}
	cout << one << " " << two;

	return 0;
}