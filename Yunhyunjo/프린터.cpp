#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue <int> pq;
    for(int i: priorities){
        pq.push(i);
    }
    int n = 0;
    while(1){
        n %= priorities.size();
        int cur = priorities[n];
        int curQ = pq.top();
        if(priorities[n] == 0){
            n++;
            continue;
        }
        if(cur >= curQ){
            answer++;
            priorities[n] = 0;
            pq.pop();
            if(n == location) break;
            n++;
        }
        else n++;
    }
    
    return answer;
}