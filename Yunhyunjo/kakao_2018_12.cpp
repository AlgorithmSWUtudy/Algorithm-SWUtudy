#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector <char> v;
    v.push_back('0');
    int k = p-1;
    int i = 0;
    while(++i){
        int r, a = i;
        string s = "";
        while(a != 0){
            r = a % n;
            char c;
            if(r > 9) c = r + 55;
            else c = r+48;
            s += c;
            a /= n;
        }
        reverse(s.begin(), s.end());
        for(char j: s){
            v.push_back(j);
        }
        if(v.size() > k){
            answer += v[k];
            k += m;
            if(answer.size() == t) break;
        }
    }
    return answer;
}