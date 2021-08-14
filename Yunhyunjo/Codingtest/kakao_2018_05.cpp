#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    int answer = 0;
    if(cacheSize == 0) return 5 * cities.size();
    
    deque <string> cache;
    
    for(string s: cities){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        deque <string> ::iterator it = find(cache.begin(), cache.end(), s);
        if(it != cache.end()){
            cache.erase(it);
            cache.push_back(s);
            answer++;
        }
        else{
            if(cache.size() >= cacheSize) cache.pop_front();
            cache.push_back(s);
            answer += 5;
        }
    }
    
    return answer;
}