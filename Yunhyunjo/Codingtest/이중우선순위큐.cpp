#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    for(string s: operations){
        if(s[0] == 'I'){
            string tmp = "";
            for(int i = 2; i < s.length(); i++){
                tmp += s[i];
            }
            v.push_back(stoi(tmp));
            sort(v.begin(), v.end());
        }
        else{
            if(!v.empty()){
                if(s[2] == '-') v.erase(v.begin());
                else v.pop_back();
            }
        }
    }
    if(v.empty()) answer = {0,0};
    else{
        answer.push_back(v.back());
        answer.push_back(v[0]);
    }
    return answer;
}