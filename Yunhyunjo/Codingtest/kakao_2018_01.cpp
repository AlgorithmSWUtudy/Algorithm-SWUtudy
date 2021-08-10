#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector <pair <int, int>> v;
    for(auto a: lines){
        string ss = a.substr(11,12);
        string dd = a.substr(24);
        int s = stoi(ss.substr(0,2)) * 3600000 + stoi(ss.substr(3,2)) * 60000 + stod(ss.substr(6))*1000;
        int d = stod(dd.substr(0, dd.size()-1)) * 1000;
        int tmp = s - d + 1;
        if(tmp < 0){
            v.push_back(make_pair(0, s));
            continue;
        }
        v.push_back(make_pair(s - d + 1, s));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        int arr[2] = {v[i].first, v[i].second};
        for(int k = 0; k < 2; k++){
            int j = arr[k];
            int cnt = 0;
            for(auto a: v){
                if(j == a.first) cnt++;
                else if(j > a.first && j <= a.second) cnt++;
                else if(j < a.first && j+999 >= a.first) cnt++;
            }
            answer = max(answer, cnt);
        }
    }
    return answer;
}