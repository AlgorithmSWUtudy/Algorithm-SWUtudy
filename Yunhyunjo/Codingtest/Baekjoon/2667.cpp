// baekjoon 2667 :: AC - 0ms

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void find();

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector <string> map;
int n, x, y;
int main() {
	
	ios::sync_with_stdio(false);
	int cnt, sum = 0;
	string s;
	cin >> n;
	vector <int> num;
	queue <pair <int, int> > q;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		map.push_back(s);
	}
	
	while(1){
		find();
		if(x == n && y == n) break;
		q.push(make_pair(x,y));
		map[x][y] = '0';
		cnt = 1;
		while(!q.empty()){
			pair <int, int> tmp = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int a = tmp.first + dx[i];
				int b = tmp.second + dy[i];
				if(a >= 0 && a < n && b >= 0 && b <n){
					if(map[a][b] == '1'){
						q.push(make_pair(a,b));
						map[a][b] = '0';
						cnt++;
					}
				}
			}
		}
		sum++;
		num.push_back(cnt);
	}
	sort(num.begin(), num.end());
	cout << sum << "\n";
	for(int i = 0; i < sum; i++){
		cout << num[i] << "\n";
	}
	
	return 0;
}

void find(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] == '1'){
				x = i;
				y = j;
				return;
			}
		}
	}
	x = n;
	y = n;
}
