#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map <string, int> m;
    
    for(string s: phone_book){
        m[s]++;
    }
    
    for(string s: phone_book){
        answer = true;
        for(auto a: m){
            if(s != a.first && s.find(a.first) != std::string::npos){ 
                answer = false;
            }
            if(!answer) break;
        }
        if(!answer) break;
    }
    
    return answer;
}
