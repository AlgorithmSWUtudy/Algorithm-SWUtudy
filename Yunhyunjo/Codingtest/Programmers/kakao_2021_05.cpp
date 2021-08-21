#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Video{
    int sh, sm, ss, eh, em, es;
    
    Video(int sh, int sm, int ss, int eh, int em, int es){
        this->sh = sh;
        this->sm = sm;
        this->ss = ss;
        this->eh = eh;
        this->em = em;
        this->es = es;
    }
    bool operator < (const Video &a)const{
        if(sh != a.sh) return sh < a.sh;
        if(sm != a.sm) return sm < a.sm;
        if(ss != a.ss) return ss < a.ss;
        if(eh != a.eh) return eh < a.eh;
        if(em != a.em) return em < a.em;
        if(es != a.es) return es < a.es;
    }
};

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector <Video> log;
    
    if(play_time == adv_time){
        return "00:00:00";
    }
    
    for(auto a: logs){
        vector <int> v;
        int idx = 0;
        for(char c: a){
            string str = "";
            if(c == ':'){
                v.push_back(stoi(str));
            }
            else if(c == '-') continue;
            else str += c;
        }
        log.push_back(Video(v[0],v[1],v[2],v[3],v[4],v[5]));
    }
    
    sort(log.begin(), log.end());
    
    return answer;
}