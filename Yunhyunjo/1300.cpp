// baekjoon 1300 :: AC - 32ms 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long lt , mid, rt, cnt, n, k, res;
	
	
	cin >> n >> k;
	
	lt = 1;
	rt = k;
	while(lt <= rt){
		mid = (lt + rt) / 2;
		cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt+= min(n, (mid-1)/i);
		}
		if(cnt >= k){
			rt = mid - 1;
		}
		else {
			lt = mid + 1;
			res = mid;
		}
	}
	
	cout << res;

	return 0;
}
