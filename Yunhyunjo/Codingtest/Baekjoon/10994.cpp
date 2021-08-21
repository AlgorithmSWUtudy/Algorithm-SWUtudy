#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int m = 4 * n - 3;
	int a = 1, b = 0;
	for (int i = 0; i < m / 2; i++) {
		if (i % 2 == 0) {
			string s = "", bl = "";
			for (int k = 0; k < b; k++) {
				if (k % 2 == 0) s += '*';
				else s += ' ';
			}
			for (int k = 0; k < m - (2 * b); k++) {
				bl += '*';
			}
			cout << s << bl;
			reverse(s.begin(), s.end());
			cout << s << "\n";
			b += 2;
		}
		else {
			string s = "", bl = "";
			for (int k = 0; k < a; k++) {
				if (k % 2 == 0) s += '*';
				else s += ' ';
			}
			for (int k = 0; k < m - (2 * a); k++) {
				bl += ' ';
			}
			cout << s << bl << s << "\n";
			a += 2;
		}
	}
	string ss = "";
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) ss += '*';
		else ss += ' ';
	}
	cout << ss;
	for (int i = 0; i < m / 2; i++) {
		cout << "\n";
		if (i % 2 == 1) {
			b -= 2;
			string s = "", bl = "";
			for (int k = b + 1; k > 1; k--) {
				if (k % 2 == 1) s += '*';
				else s += ' ';
			}
			for (int k = 0; k < m - (2 * b); k++) {
				bl += '*';
			}
			cout << s << bl;
			reverse(s.begin(), s.end());
			cout << s;
		}
		else {
			a -= 2;
			string s = "", bl = "";
			for (int k = a + 1; k > 1; k--) {
				if (k % 2 == 0) s += '*';
				else s += ' ';
			}
			for (int k = 0; k < m - (2 * a); k++) {
				bl += ' ';
			}
			cout << s << bl << s;
		}
	}

	return 0;
}