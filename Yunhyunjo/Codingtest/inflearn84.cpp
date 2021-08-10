#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int x, int y);

vector <vector <int> > arr;
int n, r, maxValue = 0;
int main() {
	
	cin >> n;
	vector <int> a(n);
	arr.push_back(a);
	arr.push_back(a);
	
	for(int i = 0; i < n; i++){
		cin >> arr[0][i] >> arr[1][i];
	}
	
	DFS(0, 0);
	cout << maxValue;
	return 0;
}

void DFS(int x, int y){
	if(x == n){
		maxValue = max(y, maxValue);
	}
	else{
		if(x + arr[0][x] <= n) DFS(x + arr[0][x], y + arr[1][x]);
		DFS(x + 1, y);
	}
}
