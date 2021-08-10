#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map <string, int> m;
    for(int i = 65; i < 91; i++){
        char c = i;
        string s = "";
        s += c;
        m[s] = i-64;
    }
    int num = 27;
    for(int i = 0; i < msg.size(); i++){
        string s = "";
        int n;
        int j;
        for(j = i; j < msg.size(); j++){
            s += msg[j];
            if(m[s] > 0) n = m[s];
            else{
                m[s] = num++;
                break;
            }
        }
        answer.push_back(n);
        i = j - 1;
    }
    return answer;
}