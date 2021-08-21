#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Faile{
    double l;
    int n;
    Faile(double l, int n){
        this->l = l;
        this->n = n;
    }
    bool operator <(const Faile &a)const{
        if(l != a.l) return l > a.l;
        return n < a.n;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector <pair <int, int>> v(N,{0,0});
    vector <Faile> s;
    
    for(int i: stages){
        if(i > N){
            for(int j = 0; j < N; j++){
                v[j].second++;
            }
        }
        else{
            for(int j = 0; j < i; j++){
                v[j].second++;
        }
            v[i-1].first++;
        }
    }
    int idx = 0;
    for(auto a: v){
        if(a.second == 0) s.push_back(Faile(0, idx));
        else s.push_back(Faile((double)a.first / (double)a.second, idx));
        idx++;
    }
    sort(s.begin(), s.end());
    for(auto a: s){
        answer.push_back(a.n+1);
    }
    return answer;
}