#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    
    sort(words.begin(), words.end());
    for(int i = 0; i < words.size(); i++){
        int maxi = 0;
        if(i-1 >= 0){
            int j;
            for(j = 0; j < words[i].size(); j++){
                if(j >= words[i-1].size() || words[i-1][j] != words[i][j]) {
                    j++;
                    break;
                }
            }
            maxi = j;
        }
        if(i+1 < words.size()){
            int j;
            for(j = 0; j < words[i].size(); j++){
                if(j >= words[i+1].size() || words[i+1][j] != words[i][j]) {
                    j++;
                    break;
                }
            }
            maxi = max(maxi, j);
        }
        answer += maxi;
    }
    return answer;
}
