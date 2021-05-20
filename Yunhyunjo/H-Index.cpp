#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 1;
    bool flag = true;
    sort(citations.begin(), citations.end());
    if(citations[citations.size() - 1] == 0) return 0;
    if(citations.size() == 1) return 1;
    for(int i = citations.size() - 1; i >= 0; i--){
        if(citations[i] < answer) {
            answer--;
            flag = false;
            break;
        }
        else if(citations[i] == answer) {
            flag = false;
            break;
        }
        else answer++;
    }
    if(flag) answer--;
    return answer;
}