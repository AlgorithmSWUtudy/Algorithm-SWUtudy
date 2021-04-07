// น้มุ 20207 :: AC - 0ms 

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a, b, arr[366] = {0,}, minValue = 365, maxValue = 0, h = 0, w = 0, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		if(a == b){
			arr[a]++;
		}
		else{
			for(int j = a; j <= b; j++){
				arr[j]++;
			}
		}
		minValue = min(minValue, a);
		maxValue = max(maxValue, b);
	}
	for(int i = minValue; i <= maxValue; i++){
		if(arr[i] == 0){
			sum += (w * h);
			h = 0;
			w = 0;
		}
		else{
			w++;
			h = max(h, arr[i]);
		}
	}
	sum += (w * h);
	cout << sum;
	
	return 0;
}
