#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int x);

vector <vector <int> > arr;
int n, r, cnt = 0, maxValue = 0;
int main() {
	
	cin >> n;
	vector <int> a(n);
	arr.push_back(a);
	arr.push_back(a);
	
	for(int i = 0; i < n; i++){
		cin >> arr[0][i] >> arr[1][i];
	}
	
	DFS(0);
	cout << maxValue;
	return 0;
}

void DFS(int x){
	if(x == n){
		cnt += arr[1][x];
		maxValue = max(cnt, maxValue);
		cnt -= arr[1][x];
		return ;
	}
	for(int i = x ; i < n; i++){
		if(i + arr[0][i] <= n){
			cnt += arr[1][i];
		 	DFS(i + arr[0][i]);
			cnt -= arr[1][i];
		}
		else{
			maxValue = max(cnt, maxValue);
		}
	}
}
