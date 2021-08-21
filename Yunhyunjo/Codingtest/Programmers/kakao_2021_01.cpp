#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int cnt = 0;
    for(int i = 0; i < new_id.size(); i++){
        if(new_id[i] > 64 && new_id[i] < 91){
            answer += new_id[i] + 32;
        }
        else if(new_id[i] > 96 && new_id[i] < 123 ||new_id[i] > 47 && new_id[i] < 58 || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            answer += new_id[i];
        }
    }
    
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == '.'){
            if(cnt != 0){
                answer.erase(i,1);
                i--;
            }
            else
                cnt++;
        }
        else 
            cnt = 0;
    }
    if(answer[0] == '.') answer.erase(0,1);
    if(answer[answer.size()-1] == '.') answer.erase(answer.size()-1);
    if(answer.size() == 0) answer += 'a';
    if(answer.size() >= 16) {
        answer.erase(15, answer.size());
        if(answer[14] == '.') answer.erase(14);
    }
    if(answer.size() <= 2){
        while(answer.size() != 3){
            answer+=answer.back();
        }
    }
    return answer;
}