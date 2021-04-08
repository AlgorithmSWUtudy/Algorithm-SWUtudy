// baekjoon 14467 :: AC - 0ms

#include <iostream>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a, b, arr[11] = {0,}, wh[11], cnt = 0;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(arr[a] == 0){
			arr[a]++;
			wh[a] = b;
		}
		else{
			if(wh[a] != b){
				cnt++;
				wh[a] = b;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
