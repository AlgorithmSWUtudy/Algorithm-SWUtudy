#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> q;
    
    for(int i = 0; i < progresses.size(); i++){
        int n = 100 - progresses[i];
        if(n % speeds[i] == 0) n = n / speeds[i];
        else n = n / speeds[i] + 1;
        q.push(n);
    }
    
    int m = q.front();
    q.pop();
    int cnt = 1;
    while(!q.empty()){
        if(m >= q.front()){
            q.pop();
            cnt++;
        }
        else{
            m = q.front();
            q.pop();
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}