#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector <string> split(string s, char delim){
    stringstream str(s);
    string tmp;
    vector <string> v;
    while(getline(str, tmp, delim)){
        v.push_back(tmp);
    }
    return v;
}

string make(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#') {
            if(s[i-1] == 'C') s.replace(i-1,2,"c");
            else if(s[i-1] == 'A') s.replace(i-1,2,"a");
            else if(s[i-1] == 'D') s.replace(i-1,2,"d");
            else if(s[i-1] == 'E') s.replace(i-1,2,"e");
            else s.replace(i-1,2,"g");
        }
    }
    return s;
}

struct Music{
    int n, idx;
    string s;
    Music(int n, int idx, string s){
        this->n = n;
        this->idx = idx;
        this->s = s;
    }
    bool operator <(const Music &a)const{
        if(n != a.n) return n > a.n;
        return idx < a.idx;
    }
};

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector <Music> res;
    m = make(m);
    int i = 1;
    cout << m << endl;
    for(auto a: musicinfos){
        vector <string> v = split(a, ',');
        int s, e;
        s = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        e = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2));
        if(s > e) s = 1440 - s;
        else s = e - s;
        int cnt = 0;
        v[3] = make(v[3]);
        if(s < v[3].size()){
             string ss = v[3].substr(0,s);
             if(ss.find(m) != std::string::npos){
                 res.push_back(Music(s, i++, v[2]));
             }
            continue;
        }
        while(1){
            v[3] += v[3];
            if(m.size() < v[3].size()) break;
        }
        if(v[3].find(m) != std::string::npos){
            res.push_back(Music(s, i++, v[2]));
        }
    }
    if(res.empty()) return "(None)";
    sort(res.begin(), res.end());
    return res[0].s;
}
