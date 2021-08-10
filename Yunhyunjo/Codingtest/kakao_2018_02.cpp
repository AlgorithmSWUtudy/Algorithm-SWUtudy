#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map <string, int> make(string s){
    map <string, int> m;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] < 65 || s[i] > 91) continue;
        if(s[i+1] < 65 || s[i+1] > 91){
            i++;
            continue;
        }
        string str = s.substr(i,2);
        m[str]++;
    }
    return m;
}

int solution(string str1, string str2) {
    int answer = 0;
    map <string, int> m1 = make(str1);
    map <string, int> m2 = make(str2);
    map <string, int>::iterator it;
    if(m1.empty() && m2.empty()) return 65536;
    double d1 = 0, d2 = 0;
    for(it = m1.begin(); it != m1.end(); it++){
        if(m2[it->first] > 0){
            if(it->second > m2[it->first]){
                d2 += it->second;
                d1 += m2[it->first];
            }
            else{
                d1 += it->second;
                d2 += m2[it->first];
            }
        }
        else d2 += it->second;
    }
    for(it = m2.begin(); it != m2.end(); it++){
        if(m1[it->first] == 0) d2 += it->second;
    }
    answer = (d1/d2) * 65536;
    return answer;
}