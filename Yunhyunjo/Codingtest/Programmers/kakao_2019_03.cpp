#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector <string> v;

bool check(string str){
    for(string s: v){
        bool flag = true;
        for(int i = 0; i < s.size(); i++){
            if(str.find(s[i]) == string::npos){
                flag = false;
                break;
            }
        }
        if(flag) return false;
    }
    return true;
}

int DFS(int s, int e, int n, int c, vector<vector<string>> relation, string str){
    int answer  = 0;
    if(n == c && check(str)){
        set <string> s;
        for(auto a: relation){
            string tmp  = "";
            for(char c: str){
                tmp += a[c-48];
            }
            s.insert(tmp);
        }
        if(s.size() == relation.size()){
            v.push_back(str);
            return 1;
        }
        return 0;
    }
    
    for(int i = s; i < e; i++){
        answer += DFS(i+1, e, n, c+1, relation, str+to_string(i));
    }
    return answer;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    set <string> s;
    
    for(int i = 1; i <= relation[0].size(); i++){
        answer += DFS(0, relation[0].size(), i, 0,relation, "");
    }
    
    return answer;
}