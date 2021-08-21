#include <iostream>

using namespace std;

int n, m;

int ch[8];

void dfs(int L, int a) {
	if (L == m) {
		for (int i = 0; i < m; i++) {
			cout << ch[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = a; i <= n; i++) {
		ch[L] = i;
		dfs(L + 1, i);
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	dfs(0, 1);

	return 0;
}