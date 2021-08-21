#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, cnt = 0;

struct Stone{
	int m, h, w;
	Stone(int m, int h, int w){
		this->m = m;
		this->h = h;
		this->w = w;
	}
	
	bool operator<(const Stone &a){
		return m > a.m;
	}
};

int main() {
	
	ios_base::sync_with_stdio(false);

	int n, a, b, c, hei;
	
	cin >> n;
	
	vector <Stone> arr;
	vector <int> mem(n);
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		arr.push_back(Stone(a,b,c));
	}
	
	sort(arr.begin(), arr.end());
	mem[0] = arr[0].h;
	hei = mem[0];
	for(int i = 1; i < n; i++){
		int maxi = 0;
		for(int j = i-1; j >= 0; j--){
			if(arr[j].w > arr[i].w && mem[j] > maxi)
				maxi = mem[j];
		}
		mem[i] = maxi + arr[i].h;
		hei = max(hei, mem[i]);
	}
	
	cout << hei;
	
	return 0;
}
