#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
	int x, y;
	Edge(int x, int y){
		this -> x = x;
		this -> y = y;
	}
	
	bool operator< (const Edge &a)const{
		return y > a.y;     //최소 priority queue라 >, 최대면 <로 해야됨
	}
};

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, a, b, c;
	
	cin >> n >> m;
	
	vector <pair <int, int> > graph[21];
	vector <int> dist(n+1, 2147000000);
	priority_queue <Edge> Q;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c));
	}
	
	Q.push(Edge(1, 0));
	dist[1] = 0;
	for(int k = 0; k < n; k++){
		int now = Q.top().x;
		int cost = Q.top().y;
		Q.pop();
		for(int i = 0; i < graph[now].size(); i++){
			int next = graph[now][i].first;
			int nextDist = graph[now][i].second + dist[now];
			if(nextDist < dist[next]){
				dist[next] = nextDist;
				Q.push(Edge(next, nextDist));
			}
				
		}
	}
	
	for(int i = 2; i <= n; i++){
		if(dist[i] == 2147000000){
			cout << i << " : impossiable" << "\n";
		}
		else{
			cout << i << " : " << dist[i] << "\n";
		}
	}
	
	return 0;
}
