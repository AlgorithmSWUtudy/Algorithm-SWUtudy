#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string split(string s, char delim) {
	stringstream str(s);
	string tmp;
	string v;

	while (getline(str, tmp, delim)) {
		string t = "";
		for (int i = tmp.size() - 1; i >= 0; i--) {
			t += tmp[i];
		}
		t += " ";
		v += t;
	}

	return v;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	getline(cin, s);

	string str = "";
	string v;
	for (char c : s) {
		if (c == '<') {
			if (str != "") {
				string t = split(str, ' ');
				v += (t.substr(0, t.size() - 1));
			}
			str = c;
		}
		else if (c == '>') {
			str += c;
			v += str;
			str = "";
		}
		else {
			str += c;
		}
	}

	if (str != "") {
		string t = split(str, ' ');
		v += (t.substr(0, t.size() - 1));
	}

	cout << v;
	return 0;
}