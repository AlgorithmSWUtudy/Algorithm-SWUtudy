#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> order;
vector<vector<pair <int, int>>> m;
set <int> var;
int ch[7];
vector <int> tmp;

void dfs(){
    if(tmp.size() == var.size()){
        order.push_back(tmp);
        return;
    }
    for(int a: var){
        if(ch[a] == 0){
            ch[a] = 1;
            tmp.push_back(a);
            dfs();
            ch[a] = 0;
            tmp.pop_back();
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 2147000000;
    vector<vector<pair <int, int>>> memo(7);
    queue <pair <int, int>> q;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(board[i][j] != 0){
                var.insert(board[i][j]);
                memo[i].push_back(make_pair(i,j));
            }
        }
    }
    dfs();
    q.push(make_pair(r,c));
    for(auto a: order){
        int res;
        for(int i: a){
            int enter = 0;
            int num = 2;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(i == board[x][y] ){
                    num--;
                    enter++;
                }
            }
        }
        answer = min(answer, res);
    }
    
    return answer;
}