#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct State{
    string id;
    string state;
    State(string id, string state){
        this->id = id;
        this->state = state;
    }
};

vector <string> split(string s, char delim){
    stringstream str(s);
    vector <string> v;
    string tmp;
    
    while(getline(str, tmp, delim)){
        v.push_back(tmp);
    }
    return v;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector <vector <string>> re;
    vector <State> res;
    map <string, string> m;
    
    for(string s: record){
        re.push_back(split(s, ' '));
    }
    
    for(auto a: re){
        if(a[0] == "Enter"){
            m[a[1]] = a[2];
            res.push_back(State(a[1],"님이 들어왔습니다."));
        }
        else if(a[0] == "Leave"){
            res.push_back(State(a[1],"님이 나갔습니다."));
        }
        else{
            m[a[1]] = a[2];
        }
    }
    
    for(auto a: res){
        answer.push_back(m[a.id] + a.state);
    }
    
    return answer;
}