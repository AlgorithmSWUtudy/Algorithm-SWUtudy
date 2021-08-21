#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int x, int L);

vector <pair <int, int> > home;
vector <pair <int, int> > pizza;
int ch[20];
int n, m, minValue = 2147000000;
int main() {
	
	ios::sync_with_stdio(false);
	
	int a;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a;
			if(a == 1){
				home.push_back(make_pair(i, j));
			}
			else if(a == 2){
				pizza.push_back(make_pair(i, j));
			}
		}
	}
	
	DFS(0, 0);
	cout << minValue;
	return 0;
}

void DFS(int L, int s){
	if(L == m){
		int sum = 0;
		for(int i = 0; i < home.size(); i++){
			int x1 = home[i].first;
			int y1 = home[i].second;
			int dis = 2147000000;
			for(int j = 0; j < m; j++){
				int x2 = pizza[ch[j]].first;
				int y2 = pizza[ch[j]].second;
				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
			}
			sum += dis;
		}
		minValue = min(minValue, sum);
		return;
	}
	for(int i = s; i < pizza.size(); i++){
		ch[L] = i;
		DFS(L + 1, i+1);
	}
}
