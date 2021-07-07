#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};
int map[101][101];
int ch[101][101];
int mini = 2147000000;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto a: puddles){
        map[a[1]][a[0]] = 1;
    }
    queue <pair <int, int>> q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x == n && y == m){
            ++answer % 1000000007;
        }
        q.pop();
        for(int i = 0; i < 2; i ++){
            if(x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m){
                if(map[x + dx[i]][y + dy[i]] != 1){
                    if(ch[x + dx[i]][y + dy[i]] == 0 || ch[x][y] + 1 <= ch[x + dx[i]][y + dy[i]]) {
                        q.push(make_pair(x + dx[i],y + dy[i]));
                        ch[x + dx[i]][y + dy[i]] = ch[x][y] + 1;
                    }
                }
            }
        }
    }
    
    return answer;
}
