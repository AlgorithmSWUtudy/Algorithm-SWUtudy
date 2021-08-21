#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	map <char, int> m;
	m['q'] = 0;
	m['u'] = 1;
	m['a'] = 2;
	m['c'] = 3;
	m['k'] = 4;

	vector <int> v;

	for (char c : s) {
		if (c == 'q') {
			if (v.empty()) { 
				v.push_back(0);
				continue;
			}
			bool flag = true;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == 4) {
					v[i] = 0;
					flag = false;
					break;
				}
			}
			if(flag) v.push_back(0);
		}
		else {
			if (v.empty()) {
				cout << -1;
				return 0;
			}
			bool flag = true;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == m[c]-1) {
					v[i] = m[c];
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << -1;
				return 0;
			}
		}
	}
	int c = 0;
	for (auto a : v) c += a;
	if (c == 4 * v.size()) cout << v.size();
	else cout << -1;
	return 0;
}