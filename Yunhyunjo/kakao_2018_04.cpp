#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set <pair<int, int>> bang(int m, int n, vector <string> board){
    set <pair<int, int>> v;
    for(int i = 0; i < m-1; i++){
        for(int j = 0; j < n-1; j++){
            if(board[i][j] != ' ' && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i+1][j] == board[i+1][j+1]){
                v.insert(make_pair(i,j));
                v.insert(make_pair(i,j+1));
                v.insert(make_pair(i+1,j));
                v.insert(make_pair(i+1,j+1));
            }
        }
    }
    return v;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    set <pair<int, int>> v = bang(m, n, board);
     while(v.size() != 0){
         for(auto a: v){
             int x = a.first, y = a.second;
             while(x-1 >= 0){
                 board[x][y] = board[x-1][y];
                 x--;
             }
             board[x][y] = ' ';
             answer++;
         }
         v = bang(m, n, board);
     }
    return answer;
}