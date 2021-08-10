#include <iostream>
#include <vector>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector <int> a(n);
	vector <int> b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	vector <int> v(n + m);
	int aa = 0, bb = 0, c = 0;
	while (aa < n && bb < m) {
		if (a[aa] < b[bb]) v[c++] = a[aa++];
		else v[c++] = b[bb++];
	}

	while (aa < n) v[c++] = a[aa++];
	while (bb < m) v[c++] = b[bb++];

	for (int i = 0; i < n + m; i++) {
		cout << v[i] << " ";
	}

	return 0;
}