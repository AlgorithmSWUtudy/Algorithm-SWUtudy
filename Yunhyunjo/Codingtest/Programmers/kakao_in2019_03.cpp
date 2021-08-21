#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int ch[8];
vector<string> user_ids;
vector<string> banned_ids;
set <vector <string>> tmp;
vector <string> v;
int cnt = 0;

void dfs(int idx){
    if(idx == banned_ids.size()){
        vector <string> v2 = v;
        sort(v2.begin(), v2.end());
        tmp.insert(v2);
        return;
    }
    for(int j = 0; j < user_ids.size(); j++){
        if(user_ids[j].size() == banned_ids[idx].size() && !ch[j]){
            bool flag = true;
            for(int i = 0; i < user_ids[j].size(); i++){
                if(user_ids[j][i] == banned_ids[idx][i] || banned_ids[idx][i] == '*') continue;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag){
                ch[j] = 1;
                v.push_back(user_ids[j]);
                dfs(idx + 1);
                v.pop_back();
                ch[j] = 0;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer;
    user_ids = user_id;
    banned_ids = banned_id;
    dfs(0);
    return answer = tmp.size();
}