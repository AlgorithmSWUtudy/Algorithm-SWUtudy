#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long lt = 1, rt = (long long)n * times[0], mid, num;
    
    while(lt <= rt){
        mid = (lt + rt) / 2;
        num = 0;
        for(int i: times){
            num += (mid / i);
        }
        
        if(num >= n) {
            rt = mid - 1;
            answer = mid;
        }
        else lt = mid + 1;
    }
    return answer;
}