#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector <vector <int>> arr(n+1);
	for (int i = 0; i <= n; i++) {
		vector <int> a(n + 1);
		arr.push_back(a);
	}
	vector <pair <int, int>> v;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(make_pair(-a, i + 1));
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int answer = 0;
	int idx = 0;
	set <int> tmp;
	while (tmp.size() != n) {
		int num = v[idx].second;
		bool flag = false;
		for (int i : tmp) {
			if (i == num) {
				flag = true;
				idx++;
				break;
			}
		}
		if (flag) continue;
		answer = answer + (-v[idx].first);
		tmp.insert(num);
		for (int i = 0; i < arr[num].size(); i++) {
			tmp.insert(arr[num][i]);
		}

		idx++;
	}

	cout << answer;
	return 0;
}