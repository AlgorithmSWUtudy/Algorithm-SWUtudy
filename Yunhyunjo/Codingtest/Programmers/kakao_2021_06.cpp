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

struct Position{
    int x, y, z;
    Position(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

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
    queue <Position> q;
    
    dfs();
    q.push(Position(r,c,0));
    for(auto a: order){
        int res = 0;
        for(int i: a){
            int num = 2;
            int m[4][4] = {0,};
            while(!q.empty()){
                int x = q.front().x;
                int y = q.front().y;
                int z = q.front().z;
                q.pop();
                if(i == board[x][y]) num--;
                if(num != 0){
                    for(int j = 0; j < 4; j++){
                        if(x + dx[j] >= 0 && x + dx[j] < 4 && y + dy[j] >= 0 && y + dy[j] < 4 && m[x + dx[j]][y + dy[j]]){
                            if(z == j+1 && board[x][y] != 0){
                                m[x + dx[j]][y + dy[j]] = m[x][y] + 1;
                            }
                            else if(z == j+1){
                                m[x + dx[j]][y + dy[j]] = m[x][y];
                            }
                            else{
                                m[x + dx[j]][y + dy[j]] = m[x][y] + 1;
                            }
                            q.push(Position(x + dx[j], y + dy[j], j+1));
                        }
                    }
                }
                else{
                    res += m[x][y] + 2;
                    queue<Position> emt;
                    swap(q, emt);
                    q.push(Position(x,y,0));
                    break;
                }
            }
        }
        answer = min(answer, res);
    }
    
    return answer;
}
