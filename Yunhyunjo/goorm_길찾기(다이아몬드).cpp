#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int dia[100][100];
	int memo[100][100] = {0,};
	int i;
	for( i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin >> dia[i][j];
		}
	}
	int a = i - 1, b = 1;
	for(i = i; i < a + n; i++){
		for(int j = 0; j < n - b; j++){
			cin >> dia[i][j];
		}
		b++;
	}
	
	memo[0][0] = dia[0][0];
	
	int dx[2] = {1, 1};
	int dy[2] = {0, 1};
	
	for( i = 0; i < n-1; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 2; k++){
				if(j + dy[k] >= 0 && j + dy[k] <= i+1){
					memo[i + dx[k]][j + dy[k]] = max(memo[i + dx[k]][j + dy[k]], memo[i][j] + dia[i + dx[k]][j + dy[k]]);
				}
			}
		}
	}
	b = 0;
	a = i;
	int dx2[2] = {1, 1};
	int dy2[2] = {-1, 0};
	for(i = i; i < a + n; i++){
		for(int j = 0; j < n - b; j++){
			for(int k = 0; k < 2; k++){
				if(j + dy2[k] >= 0 && j + dy2[k] < n - b){
					memo[i + dx2[k]][j + dy2[k]] = max(memo[i + dx2[k]][j + dy2[k]], memo[i][j] + dia[i + dx2[k]][j + dy2[k]]);
				}
			}
		}
		b++;
	}
	
	cout << memo[n*2 - 2][0];
	
	return 0;
}