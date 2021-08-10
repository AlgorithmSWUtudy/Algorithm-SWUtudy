#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map <string, int> m;
int ch[11];
int chl[11];
string s;
int l;
void dfs(int L, int c){
    if(L == l){
        string b = "";
        for(int i = 0; i < l; i++){
            b += s[ch[i]];
        }
        m[b]++;
        chl[l] = max(chl[l], m[b]);
        return;
    }
    for(int i = c; i < s.size(); i++) {
        ch[L] = i;
        dfs(L+1, i+1);
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
    }
    
    for(auto a: orders){
        for(int i: course){
            s = a;
            l = i;
            dfs(0, 0);
        }
    }
    
    for(int i: course){
        for(auto a: m){
            if(a.second > 1 && i == a.first.length() && a.second == chl[i]){
                answer.push_back(a.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
