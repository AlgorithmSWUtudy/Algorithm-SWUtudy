#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    priority_queue <pair <int, int>> q;
    vector <pair <int, int>> v;
    int sum = 0;
    for(auto a: jobs){
        q.push(make_pair(-a[0], a[1]));
    }
    while(!q.empty()){
        pair <int, int> tmp = q.top();
        if(sum == -tmp.first){
            int mini = 2147000000;
            int ts;
            int ta;
            while(!q.empty() && sum > -tmp.first){
                v.push_back(make_pair(-tmp.first, tmp.second));
                q.pop();
                tmp = q.top();
            }
            do{
                ts = sum;
                ta = answer;
                for(int i = 0; i < v.size(); i++){
                    ts += v[i].second;
                    ta += (ts - v[i].first);
                }
                mini = min(mini, ta);
            }while(next_permutation(v.begin(), v.end()));
            sum = ts;
            answer = ta;
        }
        else{
            int mini = 2147000000;
            int ts;
            int ta;
            while(!q.empty() && sum > -tmp.first){
                v.push_back(make_pair(-tmp.first, tmp.second));
                q.pop();
                tmp = q.top();
            }
            do{
                ts = sum;
                ta = answer;
                for(int i = 0; i < v.size(); i++){
                    ts += v[i].second;
                    ta += (ts - v[i].first);
                }
                mini = min(mini, ta);
            }while(next_permutation(v.begin(), v.end()));
            sum = ts;
            answer = ta;
        }
    }
    
    return answer / n;
}