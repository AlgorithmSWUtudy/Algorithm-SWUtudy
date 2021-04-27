#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct TList{
    vector <int> a;
    int s;
    TList(vector <int> a, int s){
        this->a = a;
        this->s = s;
    }
    bool operator< (const TList &b)const{
        return s < b.s;
    }
};

vector<int> solution(string s) {
    vector<int> answer;
    vector <TList> tlist;
    int tmp = 0;
    vector <int> x;
    for(int i = 2; i < s.size() - 1; i++){
        if(s[i] > 47 && s[i] < 58){
            tmp = tmp * 10 + s[i] - 48;
        }
        else if(s[i] == ','){
            x.push_back(tmp);
            tmp = 0;
        }
        else{
            x.push_back(tmp);
            tmp = 0;
            i+=2;
            tlist.push_back(TList(x, x.size()));
            x.clear();
        }
    }
    sort(tlist.begin(), tlist.end());
    answer.push_back(tlist[0].a[0]);
    for(int i = 1; i < tlist.size(); i++){
        for(int j = 0; j < tlist[i].a.size(); j++){
            bool flag = false;
            for(int k = 0; k < answer.size(); k++){
                if(answer[k] == tlist[i].a[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answer.push_back(tlist[i].a[j]);
                break;
            }
        }
    }
    return answer;
}