// baekjoon 1966 :: AC - 0ms

#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int c, n, m, a;
	
	cin >> c;
	
	while(c--){
		cin >> n >> m;
		vector <int> arr(n);
		priority_queue <int> pq;
		int cnt = 0, p = 0;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			pq.push(arr[i]);
		}
		while(1){
			if(p == n)
				p = 0;
			if(arr[p] == pq.top()){
				if(p == m){
					cnt++;
					break;
				}
				else{
					pq.pop();
					cnt++;
				}
			}
			p++;
		}
		
		cout << cnt << "\n";
	}
		
	return 0;
}
