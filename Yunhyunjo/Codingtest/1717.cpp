// baekjoon 1717 :: AC - 52ms 

#include <iostream>
#include <vector>

using namespace std;

int unf[1000001];

int Find(int a){
	if(a == unf[a]) return a;
	return unf[a] = Find(unf[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	
	if(a != b) unf[a] = b;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, a, b, c;
	
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++){
		unf[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		if(a == 0){
			Union(b, c);
		}
		else{
			if(Find(b) == Find(c))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}
