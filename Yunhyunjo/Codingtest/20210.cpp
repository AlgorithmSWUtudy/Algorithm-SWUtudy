#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {

	for (int i = 0; i < a.size(); i++) {
		if (i < b.size()) {
			if (a[i] > 58 && b[i] > 58) {
				if ((a[i] < 91 && b[i] < 91) || (a[i] < 123 && b[i] < 123)) {
					if (a[i] > b[i]) return false;
				}
				else if (a[i] < 91 && b[i] < 123) {
					if (a[i] - 65 != b[i] - 97) {
						if (a[i] - 65 > b[i] - 97) return false;
					}
				}
				else {
					if (a[i] - 97 == b[i] - 65) return false;
					if (a[i] - 97 > b[i] - 65) return false;
				}
			}
			else if (a[i] < 58 && b[i] > 58) continue;
			else if (a[i] > 58 && b[i] < 58) return false;
			else {
				string tmp1 = "";
				int cnt1 = 0;
				int n = 0;
				for (int j = i; j < a.size(); j++) {
					if (a[j] >= 58) break;
					if (a[j] - 48 == 0) cnt1++;
					tmp1 += a[j];
					n++;
				}
				string tmp2 = "";
				int cnt2 = 0;
				for (int j = i; j < b.size(); j++) {
					if (b[j] >= 58) break;
					if (b[j] - 48 == 0) cnt2++;
					tmp2 += a[j];
				}
				if (tmp1 == tmp2) {
					if (cnt1 > cnt2) return false;
				}
				else {
					if (stoi(tmp1) > stoi(tmp2)) return false;
				}
				i = i + n - 1;
			}
		}
	}
	if (a.size() > b.size()) return false;

	return true;
}

int main() {

	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	vector <string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i < v.size(); i++) {
		string tmp = v[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (compare(tmp, v[j])) {
				v[j + 1] = v[j];
			}
			else break;
		}
		v[j + 1] = tmp;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}