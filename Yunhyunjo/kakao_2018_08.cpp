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

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector <pair <int, string>> res;
    // map <string, int> m = {"C" : 1, "C#" : 2, "D" : 3, "D#" : 4, "E" : 5, "F" : 6, "F#" : 7, "G" : 8, "G#" : 9,  "A" : 10, "A#" : 11, "B" : 12, "E#" : 13};
    for(auto a: musicinfos){
        vector <string> v = split(a, ',');
        int s, e;
        s = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        e = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2));
        s = e - s;
        int cnt = 0;
        for(char c: v[3]){
            if(c == '#') continue;
            else cnt++;
        }
        e = s / cnt;
        for(int i = 0; i < e; i++){
            v[3] += v[3];
        }
        if(v[3].find(m) != std::string::npos){
            res.push_back(make_pair(s, v[2]));
        }
    }
    if(res.empty()) return "none";
    sort(res.begin(), res.end());
    return res[0].second;
}