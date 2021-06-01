#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

map <string, vector <pair <string, int>>> t;
int n;
vector <string> v;
void dfs(string s, string str){
    
    if(t[s].empty()){
        if(str.size() == n){
            v.push_back(str);
        }
        return;
    }
    
    if(str.size() == n){
        v.push_back(str);
        return;
    }
    
    for(int i = 0; i < t[s].size(); i++){
        if(t[s][i].second == 0){
            t[s][i].second = 1;
            dfs(t[s][i].first, str + t[s][i].first);
            t[s][i].second = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = (tickets.size()+1)*3;
    for(auto a: tickets){
        t[a[0]].push_back(make_pair(a[1], 0));
    }
    dfs("ICN", "ICN");
    sort(v.begin(), v.end());
    string tmp = "";
    for(int i = 0; i < v[0].size(); i++){
        if(i % 3 == 2){
            tmp += v[0][i];
            answer.push_back(tmp);
            tmp = "";
        }
        else tmp += v[0][i];
    }
    return answer;
}