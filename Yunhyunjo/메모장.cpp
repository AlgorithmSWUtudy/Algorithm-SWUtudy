#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};
int map[101][101];
int ch[101][101];
const int NUM = 1000000007;
int mini = 2147000000;
int nn, mm;
int res = 0;
void dfs(int x, int y, int d){
    if(x == nn && y == mm){
        if(mini == 2147000000){
            mini = d;
            res = 1;
        }
        else if(mini == d){
            res = ((res % NUM) + 1) % NUM;
        }
        return;
    }
    
    for(int i = 0; i < 2; i++){
        if(x + dx[i] <= nn && y + dy[i] <= mm && map[x+dx[i]][y+dy[i]] != 1 && ch[x+dx[i]][y+dy[i]] == 0){
            ch[x+dx[i]][y+dy[i]] == 1;
            dfs(x + dx[i], y + dy[i], d + 1);
            ch[x+dx[i]][y+dy[i]] == 0;
        }
    }
    
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    nn = n;
    mm = m;
    for(auto a: puddles){
        map[a[0]][a[1]] = 1;
    }

    dfs(1,1,0);
    
    return answer = res;
}