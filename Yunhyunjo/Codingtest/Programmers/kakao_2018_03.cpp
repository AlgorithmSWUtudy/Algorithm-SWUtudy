#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector <int> v;
    sort(timetable.begin(), timetable.end());
    for(auto a: timetable){
        v.push_back(stoi(a.substr(0,2))*60 + stoi(a.substr(3)));
    }
    int j = 0, h, mi;
    int s = 540;
    while(n != 1){
        for(int i = 0; i < m; i++){
            if(timetable.size() == j) break;
            if(s >= v[j]) j++;
            else break;
        }
        s += t;
        n--;
    }        
    for(int i = 0; i < m-1; i++){
        if(j == v.size()) break;
        if(s >= v[j]) j++;
    }
    if(j != v.size()) {
        if(s > v[j] - 1) s = v[j] - 1;
    }
    h = s / 60;
    mi = s % 60;
    if(h < 10) answer += '0';
    answer += to_string(h);
    if(mi < 10) answer += ":0";
    else answer += ':';
    answer += to_string(mi);
    return answer;
}
