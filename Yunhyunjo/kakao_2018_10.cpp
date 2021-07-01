#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    map <string, int> m;
    for(string s: words){
        string tmp = "";
        int i = 0;
        for(char c: s){
            tmp += c;
            m[tmp]++;
        }
    }
    for(string s: words){
        string tmp = "";
        int i = 0;
        for(char c: s){
            tmp += c;
            if(m[tmp] == 1){
                answer += tmp.size();
                break;
            }
            if(s.size() == tmp.size()) answer += s.size();
        }
    }
    return answer;
}