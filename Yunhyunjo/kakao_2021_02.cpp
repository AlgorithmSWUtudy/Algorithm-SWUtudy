#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector <map <vector <char> , int> > c(11);
map <vector <char>, int>::iterator it;

void find(string a, string b, vector<int> course){
    vector <char> res;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                res.push_back(b[j]);
                if(res.size() >= 2){
                    c[res.size()][res]++;
                }
                break;
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector <vector <vector <char> > > cc(11);
    for(int i = 0; i < orders.size() - 1; i++){
        for(int j = i + 1; j < orders.size(); j++){
            find(orders[i], orders[j],course);
        }
    }
    for(int i = 2;i <= 10; i++){
        int maxi = 0;
        for(it = c[i].begin(); it != c[i].end(); it++){
            if(maxi <= it->second/2+1) maxi = it->second/2+1;
        }
        for(it = c[i].begin(); it != c[i].end(); it++){
            if(maxi == it->second/2+1){
                cc[i].push_back(it->first);
            }
        }
    }
    for(int i = 0; i < course.size(); i++){
        for(int j = 0; j < cc[course[i]].size(); j++){
            string s = "";
            sort(cc[course[i]][j].begin(), cc[course[i]][j].end());
            for(int k = 0; k < cc[course[i]][j].size(); k++){
                s += cc[course[i]][j][k];
            }
            answer.push_back(s);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}