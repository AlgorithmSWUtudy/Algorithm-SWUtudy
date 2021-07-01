#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector <int> s;
    int sc;
    char p = ' ';
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] > 47 && dartResult[i] < 58){
            if(dartResult[i+1] == 48) {
                sc = 10;
                i++;
            }
            else sc = dartResult[i] - 48;
        }
        else if(dartResult[i] > 64 && dartResult[i] < 91){
            if(dartResult[i] == 'S') s.push_back(sc);
            else if(dartResult[i] == 'D') s.push_back(sc * sc);
            else s.push_back(sc*sc*sc);
        }
        else{
            if(dartResult[i] == '*'){
                if(p == '*'){
                    s[s.size()-2] *= 4;
                    s[s.size()-1] *= 2;
                }
                else if(p == '#'){
                    s[s.size()-2] *= 2;
                    s[s.size()-1] *= 2;
                    p = '#';
                }
                else {
                    s[s.size()-2] *= 2;
                    s[s.size()-1] *= 2;
                    p = ' ';
                }
            }
            else{
                s[s.size()-1] *= (-1);
                p = '#';
            }
        }
    }
    for(auto a: s){
        answer += a;
    }
    return answer;
}