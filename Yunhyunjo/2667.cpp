// baekjoon 2667 :: WA

#include <iostream>
#include <vector>

using namespace std;

int DFS(int x, int y);
int find();

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, x, y;
vector <string> arr(25);

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cnt = 0;
	
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == '1'){
				DFS(i, j);
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}

int DFS(int x, int y){
	int a, b;
	for(int i = 0; i < 4; i++){
		a = x + dx[i];
		b = y + dy[i];
		if(a >= 0 && a < n && b >= 0 && b <= n){
			if(arr[a][b] == '1'){
				arr[a][b] == '0';
				DFS(a,b);
			}
		}
	}
	return 0;
}
