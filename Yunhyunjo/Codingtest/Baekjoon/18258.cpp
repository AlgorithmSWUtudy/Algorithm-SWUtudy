// baekjoon 18258 :: AC - 388ms

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void push(int x);
int pop();
int size();
int empty();
int front();
int back();
int f = 0,b = -1;
vector <int> arr;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, num;
	
	cin >> n;

	string s;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s == "push"){
			cin >> num;
			push(num);
		}
		else if(s == "pop"){
			cout << pop() << "\n";
		}
		else if(s == "size"){
			cout << size() << "\n";
		}
		else if(s == "empty"){
			cout << empty() << "\n";
		}
		else if(s == "front"){
			cout << front() << "\n";
		}
		else{
			cout << back() << "\n";
		}
	}
	
	return 0;
}

void push(int x){
	arr.push_back(x);
	b++;
}
int pop(){
	if(f > b)
		return -1;
	else
		return arr[f++];
}
int size(){
	return b - f + 1;
}
int empty(){
	if(f > b)
		return 1;
	else
		return 0;
}
int front(){
	if(f > b)
		return -1;
	else
		return arr[f];
}
int back(){
	if(f > b)
		return -1;
	else
		return arr[b];
}
