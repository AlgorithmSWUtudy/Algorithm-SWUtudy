#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int x, int val);

vector <int> num;
int arr[4];
int n, maxValue = 0, minValue = 2147000000;
int main() {
	
	ios::sync_with_stdio(false);
	
	cin >> n;
	num.resize(n);

	
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	for(int i = 0; i < 4; i++){
		cin >> arr[i];
	}
	
	DFS(1, num[0]);
	cout << maxValue << "\n" << minValue;
	return 0;
}

void DFS(int x, int val){
	if(x >= n){
		maxValue = max(maxValue, val);
		minValue = min(minValue, val);
		return;
	}
	for(int i = 0; i < 4; i++){
		if(arr[i] != 0){
			arr[i]--;
			if(i == 0)
				DFS(x + 1, val + num[x]);
			else if(i == 1)
				DFS(x + 1, val - num[x]);
			else if(i == 2)
				DFS(x + 1, val * num[x]);
			else
				DFS(x + 1, val / num[x]);
			arr[i]++;
		}
	}
}
