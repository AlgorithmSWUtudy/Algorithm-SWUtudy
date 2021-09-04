#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9') answer = answer * 10 + (s[i] - 48);
        else if(s[i] == 'z') {
            answer *= 10;
            i += 3;
        }
        else if(s[i] == 'o'){
            answer = answer * 10 + 1;
            i += 2;
        } 
        else if(s[i] == 'e'){
            answer = answer * 10 + 8;
            i += 4;
        }
        else if(s[i] == 'n'){
            answer = answer * 10 + 9;
            i += 3;
        }
        else if(s[i] == 't'){
            if(s[i+1] == 'w'){
                answer = answer * 10 + 2;
                i += 2;
            }
            else{
                answer = answer * 10 + 3;
                i += 4;
            }
        }
        else if(s[i] == 'f'){
            if(s[i+1] == 'o') answer = answer * 10 + 4; 
            else answer = answer * 10 + 5; 
            i += 3;
        }
        else{
            if(s[i+1] == 'e'){
                answer = answer * 10 + 7;
                i += 4;
            }
            else{
                answer = answer * 10 + 6;
                i += 2;
            }
        }
    }
    
    return answer;
}