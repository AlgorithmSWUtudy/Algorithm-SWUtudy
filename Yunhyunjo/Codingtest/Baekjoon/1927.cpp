// baekjoon 1927 :: AC - 16ms 

#include <iostream>
#include <queue>

using namespace std;


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a;
	
	cin >> n;
	
	priority_queue <int> q;
	
	for(int i = 0; i < n; i++){
		cin >> a;
		if(!q.empty() && a == 0){
			cout << -q.top() << "\n";
			q.pop();
		}
		else if(q.empty() && a == 0)
			cout << 0 << "\n";
		else{
			q.push(-a);
		}
	}

	return 0;
}
