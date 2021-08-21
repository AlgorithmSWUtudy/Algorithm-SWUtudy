#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n != 0) {
		vector <int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector <bool> ch(n, false);
		for (int i = 0; i < 6; i++) {
			ch[i] = true;
		}
		do {
			for (int i = 0; i < n; i++) {
				if (ch[i]) cout << v[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(ch.begin(), ch.end()));
		cout << "\n";
		cin >> n;
	}

	return 0;
}