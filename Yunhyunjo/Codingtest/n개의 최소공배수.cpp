#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    int n = arr.back(), i = 0;
    while(1){
        int num = n * ++i;
        bool flag = false;
        for(int j = 0; j < arr.size()-1; j++){
            if(num % arr[j] != 0){
                flag = true;
                break;
            }
        }
        if(flag) continue;
        answer = num;
        break;
    }
    return answer;
}