#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string, int> com;
    map <string, int> par;
    for(int i = 0; i < completion.size(); i++){
        par[participant[i]]++;
        com[completion[i]]++;
    }
    par[participant[participant.size()-1]]++;
    
    for(int i = 0; i < participant.size(); i++){
        if(com[participant[i]] > 0){
            if(com[participant[i]] != par[participant[i]]){
                answer = participant[i];
                break;
            }
        }
        else{
            answer = participant[i];
            break;
        }
    }
    return answer;
}