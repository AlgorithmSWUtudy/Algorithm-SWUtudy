#include <string>
#include <map>
#include <algorithm>

using namespace std;

map <string, int> create(string s){
    map <string, int> res;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] < 65 || s[i] > 90){
            continue;
        }
        if(s[i+1] < 65 || s[i+1] > 91){
            i++; continue;
        }
        string str = "";
        str += s[i];
        str += s[i+1];
        res[str]++;
    }
    return res;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    map <string, int> m1 = create(str1);
    map <string, int> m2 = create(str2);
    int r = 0, a = 0;
    if(m1.empty() && m2.empty()) return 65536;
    for(map <string, int> ::iterator it = m1.begin(); it != m1.end(); it++){
        if(m2[it->first] != 0){
            if(it->second > m2[it->first]){
                r += m2[it->first];
                a += it->second;
            }
            else{
                a += m2[it->first];
                r += it->second;
            }
            m2[it->first] = 0;
        }
        else{
            a += it->second;
        }
    }
    for(map <string, int> ::iterator it = m2.begin(); it != m2.end(); it++){
        a += it->second;
    }
    double d = (double)r / (double)a;
    return answer = d * 65536;
}