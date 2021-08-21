#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct FileName{
    string h, n, t, lh;
    FileName(string h, string n, string t){
        this->h = h;
        this->n = n;
        this->t = t;
        this->lh = h;
        transform(lh.begin(), lh.end(), lh.begin(), ::tolower);
    }
    bool operator <(const FileName &a)const{
        if(lh != a.lh) return lh < a.lh;
        return stoi(n) < stoi(a.n);
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector <FileName> file;
    
    for(auto a: files){
        string h = "", n = "";
        int i;
        for(i = 0; i < a.size(); i++){
            if(a[i] > 47 && a[i] < 58) break;
            else h += a[i];
        }
        for(i = i; i < a.size(); i++){
            if(a[i] > 47 && a[i] < 58) n += a[i];
            else break;
        }
        string t = a.substr(i);
        file.push_back(FileName(h, n, t));
    }
    stable_sort(file.begin(), file.end());
    
    for(auto a: file){
        string str = a.h + a.n + a.t;
        answer.push_back(str);
    }
    return answer;
}