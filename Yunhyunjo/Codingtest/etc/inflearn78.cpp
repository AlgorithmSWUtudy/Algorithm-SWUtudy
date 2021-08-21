#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line{
	int x, y, z;
	Line(int x, int y, int z){
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}
	
	bool operator< (const Line &a)const{
		return z < a.z;
	}
};

int arr[26];

int Find(int x){
	if(x == arr[x]) return x;
	else return arr[x] = Find(arr[x]);
}

int Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y) return 1;
	else{
		arr[x] = y;
		return 0;
	} 
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int v, e, a, b, c, sum = 0;
	
	vector <Line> line; 
	
	cin >> v >> e;
	
	for(int i = 1; i <= v; i++){
		arr[i] = i;
	}
	
	for(int i = 0; i < e; i++){
		cin >> a >> b >> c;
		line.push_back(Line(a,b,c));
	}
	
	sort(line.begin(), line.end());
	
	for(int i = 0; i < e; i++){
		if(Union(line[i].x, line[i].y) == 0){
			sum += line[i].z;
		}
	}
	
	cout << sum;
	
	return 0;
}
