#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	
	vector <pair <int, int>> v;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	int sum = 1, s = v[0].first, e = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= s && v[i].second < e) {
			s = v[i].first;
			e = v[i].second;
		}
		else if(e <= v[i].first){
			s = v[i].first;
			e = v[i].second;
			sum++;
		}
	}

	cout << sum;

	return 0;
}