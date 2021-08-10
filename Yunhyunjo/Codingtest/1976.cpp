// baekjoon 1976 :: AC - 0ms 

#include <iostream>

using namespace std;

int unf[201];

int Find(int a){
	if(a == unf[a]) return a;
	return unf[a] = Find(unf[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a > b) unf[a] = b;
	if(a < b) unf[b] = a;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, num;
	
	cin >> n >> m;

	
	for(int i = 1; i <= n; i++){
		unf[i] = i;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> num;
			if(i != j && num == 1)
				Union(i, j);
		}
	}
	int root;
	for(int i = 1; i <= m; i++){
		cin >> num;
		if(i == 1)
			root = Find(num);
		else if(root != Find(num)){
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";

	return 0;
}
