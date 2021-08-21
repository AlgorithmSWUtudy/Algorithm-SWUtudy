// baekjoon 1244 :: AC - 0ms

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, a, b;
	
	cin >> n;
	vector <int> arr(n+1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		if(a == 1){
			for(int j = b; j <= n; j += b){
				arr[j] = (arr[j] == 1) ? 0 : 1;
			}
		}
		else{
			int x = 1;
			while(b - x > 0 && b + x <= n){
				if(arr[b-x] == arr[b+x]){
					arr[b-x] = (arr[b-x] == 1) ? 0 : 1;
					arr[b+x] = (arr[b+x] == 1) ? 0 : 1;
					x++;
				}
				else
					break;
			}
			arr[b] = (arr[b] == 1) ? 0 : 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << arr[i] << " ";
		if(i % 20 == 0)
			cout << "\n";
	}
		
	return 0;
}
