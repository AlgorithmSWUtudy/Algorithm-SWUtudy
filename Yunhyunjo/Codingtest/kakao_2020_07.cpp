#include <string>
#include <vector>
#include <queue>

using namespace std;
struct Robot{
    int x1, x2, y1, y2, t;
    Robot(int x1, int y1, int x2, int y2, int t){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->t = t;
    }
};

struct Lotation{
    int x1, x2, y1, y2;
    Lotation(int x1, int y1, int x2, int y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
};

vector <Lotation> Lotate(int x1, int y1, int x2, int y2, vector<vector<int>> board){
    vector <Lotation> v;
    if(x1 == x2){
        if(board[x1+1][y1] == 0 && board[x2+1][y2] == 0){
            v.push_back(Lotation(x1,y1,x2+1,y2-1));
            v.push_back(Lotation(x2,y2,x1+1,y1+1));
        }
        if(board[x1-1][y1] == 0 && board[x2-1][y2] == 0){
            v.push_back(Lotation(x2-1,y2-1,x1,y1));
            v.push_back(Lotation(x1-1,y1+1,x2,y2));
        }
    }
    else{
        if(board[x1][y1+1] == 0 && board[x2][y2+1] == 0){
            v.push_back(Lotation(x1,y1,x2-1,y2+1));
            v.push_back(Lotation(x2,y2,x1+1,y1+1));
        }
        if(board[x1][y1-1] == 0 && board[x2][y2-1] == 0){
            v.push_back(Lotation(x2-1,y2-1,x1,y1));
            v.push_back(Lotation(x1+1,y1-1,x2,y2));
        }
    }
    return v;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    queue <Robot> q;
    q.push(Robot(1,1,1,2,0));
    int n = board.size();
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    bool flag = false;
    while(1){
        Robot tmp = q.front();
        q.pop();
        int xx1 = tmp.x1;
        int yy1 = tmp.y1;
        int xx2 = tmp.x2;
        int yy2 = tmp.y2;
        for(int i = 0; i < 4; i++){
            if(xx1 + dx[i] > 0 && xx1 + dx[i] <= n && xx2 + dx[i] > 0 && xx2 + dx[i] <= n && yy1 + dy[i] > 0 && yy1 + dy[i] <= n && yy2 + dy[i] > 0 && yy2 + dy[i] <= n){
                if((xx1 + dx[i] == n && yy1 + dy[i]) == n || (xx2 + dx[i] == n && yy2 + dy[i])){
                    flag = true;
                    answer = tmp.t + 1;
                    break;
                }
                if(board[xx1 + dx[i]][yy1 + dy[i]] - 1 == 0 && board[xx2 + dx[i]][yy2 + dy[i]] - 1 == 0){
                    q.push(Robot(xx1 + dx[i], yy1 + dy[i], xx1 + dx[i], yy1 + dy[i], tmp.t+1));
                }
            }
        }
        vector <Lotation> v = Lotate(xx1,yy1,xx2,yy2,board);
        if(!v.empty()){
            for(int i = 0; i < v.size(); i++){
                q.push(Robot(v[i].x1, v[i].y1, v[i].x2, v[i].y2, tmp.t+1));
            }
        }
        if(flag) break;
    }
    
    return answer;
}