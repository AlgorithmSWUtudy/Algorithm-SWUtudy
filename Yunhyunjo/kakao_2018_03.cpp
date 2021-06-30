#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector <int> v;
    for(auto a: timetable){
        v.push_back(stoi(a.substr(0,2))*60 + stoi(a.substr(3)));
    }
    sort(v.begin(), v.end());
    int j = 0, h, mi;
    int s = 540;
    while(n--){
        for(int i = 0; i < m; i++){
            if(timetable.size() == j) {
                h = s / 60;
                mi = s % 60;
                if(h < 10) answer += '0';
                answer += to_string(h);
                if(mi < 10) answer += ":0";
                else answer += ':';
                answer += to_string(mi);
                return answer;
            }
            if(s >= v[j]) j++;
            else break;
        }
        s += t;
    }
    if(j == v.size())  s = v.back()-1;
    else if(j == 0) s -= t;
    else if (j < v.size()) s = v[j-1] -1;
    h = s / 60;
    mi = s % 60;
    if(h < 10) answer += '0';
    answer += to_string(h);
    if(mi < 10) answer += ":0";
    else answer += ':';
    answer += to_string(mi);
    return answer;
}