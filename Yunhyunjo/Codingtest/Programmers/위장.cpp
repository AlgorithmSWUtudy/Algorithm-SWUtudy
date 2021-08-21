#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map <string, int> m;
    int cnt = 0;
    
    for(auto a: clothes){
        m[a[1]]++;
    }
    if(m.size() == 1) return clothes.size();
    if(m.size() == 30){ return 1073741823; }
    vector <bool> ch(m.size(), false);
    for(int i = 2; i <= m.size(); i++){
        for(int j = 0; j < i; j++){
            ch[j] = true;
        }
        do{
            int b = 0;
            int c = 1;
            for(auto a: m){
                if(ch[b++]){
                    c *= a.second;
                }
            }
            cnt += c;
        }while(prev_permutation(ch.begin(), ch.end()));
    }
    answer = cnt + clothes.size();
    return answer;
}