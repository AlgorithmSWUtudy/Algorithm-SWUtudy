#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int grid[10000][10000];

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int num = 1;
    int mx = 0, my = 0;
    for(auto a: nodeinfo){
        grid[a[0]][a[1]] = num++;
        mx = max(mx, a[0]);
        my = max(my, a[1]);
    }
    vector <vector <int>> tree;
    for(int i = my; i >= 0; i--){
        vector <int> a;
        for(int j = 0; j <= mx; j++){
            if(grid[j][i] != 0){
                a.push_back(grid[j][i]);
            }
        }
        if(!a.empty()) tree.push_back(a);
    }
    
    for(auto a: tree){
        for(int i: a){
            cout << i << " ";
        }
        cout << endl;
    }
    
    return answer;
}