// น้มุ 17298 :: TLE

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	
	cin >> n;
	vector <int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		stack <int> s;
		for(int j = n; j > i; j--){
			if(arr[j] > arr[i])
				s.push(arr[j]);
		}
		if(s.empty())
			cout << -1 << " ";
		else
			cout << s.top() << " ";
	}
	
	return 0;
}
