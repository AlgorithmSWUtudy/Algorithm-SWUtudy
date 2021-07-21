#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> answer;
vector <bool> ch(100);
void ZOAC(string s, int l, int r) {
	if (l >= r) return;
	int idx = l;
	for (int i = l; i < r; i++) {
		if (s[idx] > s[i]) {
			idx = i;
		}
	}
	string str = "";
	ch[idx] = true;
	for (int i = 0; i < s.size(); i++) {
		if (ch[i]) str += s[i];
	}
	answer.push_back(str);

	ZOAC(s, idx + 1, r);
	ZOAC(s, l, idx);
}

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	ZOAC(s, 0, s.size());

	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << endl;
	}
	cout << answer.back();

	return 0;
}