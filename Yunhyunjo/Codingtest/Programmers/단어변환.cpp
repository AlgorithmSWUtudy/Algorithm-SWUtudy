#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Word{
    string cs;
    vector <int> ch;
    int n;
    Word(string cs, vector <int> ch, int n){
        this->cs = cs;
        this->ch = ch;
        this->n = n;
    }
};

bool check(string f, string c){
    int cnt = 0;
    for(int i = 0; i < f.size(); i++){
        if(f[i] != c[i]){
            cnt++;
            if(cnt > 1) return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 2147000000;
    queue <Word> q;
    vector <int> ch(words.size());
    q.push(Word(begin, ch, 0));
    while(!q.empty()){
        Word w = q.front();
        q.pop();
        if(w.cs == target){
            answer = min(answer, w.n);
        }
        for(int i = 0; i < words.size(); i++){
            if(w.ch[i] == 0 && check(w.cs, words[i])){
                w.ch[i] = 1;
                q.push(Word(words[i], w.ch, w.n+1));
                w.ch[i] = 0;
            }
        }
    }
    if(answer == 2147000000) return 0;
    return answer;
}