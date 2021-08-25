#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += v[i];
		sum += tmp;
	}

	cout << sum;

	return 0;
}