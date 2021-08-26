#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	string tmp = "";
	vector <string> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 47 && s[1] < 58) {
			tmp += s[i];
		}
		else {
			v.push_back(tmp);
			tmp = "";
			tmp += s[i];
			v.push_back(tmp);
			tmp = "";
		}
	}
	v.push_back(tmp);
	int num = stoi(v[0]);
	int i = 1;
	while (v[i] == "+") {
		num += stoi(v[i + 1]);
		i += 2;
	}
	i++;
	int pre;
	while (i < v.size()) {
		pre = stoi(v[i]);
		i++;
		while (i < v.size() && v[i] == "+") {
			pre += stoi(v[i+1]);
			i += 2;
		}
		if (i < v.size() && v[i] == "-") i++;
		num -= pre;
	}
	cout << num;
	return 0;

}