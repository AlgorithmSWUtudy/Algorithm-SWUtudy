#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DFS(int x);

vector <int> arr, ch;
deque <int> dq;
int n, r, cnt = 0;
int main() {
	
	cin >> n >> r;
	arr.resize(n);
	ch.resize(n+1);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	DFS(0);
	cout << cnt;
	return 0;
}

int DFS(int x){
	if(x == r){
		for(int i = 0; i < r; i++){
			cout << dq[i] << " ";
		}
		cout << "\n";
		cnt++;
		return 0;
	}
	for(int i = 0; i < n; i++){
		if(ch[i] == 0){
			ch[i] = 1;
			dq.push_back(arr[i]);
			DFS(x + 1);
			dq.pop_back();
			ch[i] = 0;
		}
	}
}
