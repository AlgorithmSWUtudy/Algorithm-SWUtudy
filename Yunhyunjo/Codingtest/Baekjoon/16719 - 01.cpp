// baekjoon 16719 ZOAC :: AC - 0ms

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string s;
int memo[100];

void FindLeft(int x);
void FindRight(int x);
void PrintSort(int i);

struct Chr{
	int x, y;
	
	Chr(int x, int y){
		this -> x = x;
		this -> y = y;
	}
	bool operator<(const Chr &a)const{
		if(x != a.x) return x < a.x;
		if(y != a.y) return y < a.y;
	}
};

struct Res{
	char x;
	int y;
	
	Res(char x, int y){
		this -> x = x;
		this -> y = y;
	}
	bool operator<(const Res &a)const{
		return y < a.y;
	}
};

vector <Chr> arr;
vector <Res> res;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		arr.push_back(Chr(s[i] - 65, i));
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < s.size(); i++){
		if(memo[arr[i].y] == 0){
			PrintSort(i);
		}
		FindLeft(i);
	}
	
		
	return 0;
}

void FindLeft(int x){
	for(int i = x + 1; i < s.size(); i++){
		if(arr[i].y > arr[x].y && memo[arr[i].y] == 0){
			PrintSort(i);
			FindLeft(i);
		}
	}
}

void PrintSort(int i){
	res.push_back(Res(s[arr[i].y], arr[i].y));
	sort(res.begin(), res.end());
	memo[arr[i].y] = 1;
	if(i != 0)
		cout << "\n";
	for(int j = 0; j < res.size(); j++){
		cout << res[j].x;
	}
}
