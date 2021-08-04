#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map <string, int> cache;
    vector <pair <int, string>> tmp;
    
    if(cacheSize == 0) return cities.size()*5;
    
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        if(cache[cities[i]] == 0){
            if(tmp.size() < cacheSize) tmp.push_back(make_pair(i+1, cities[i]));
            else{
                sort(tmp.begin(), tmp.end());
                cache[tmp[0].second] = 0;
                tmp[0].second = cities[i];
                tmp[0].first = i+1;
            }
            cache[cities[i]] = i+1;
            answer += 5;
        }
        else{
            for(int j = 0; j < cacheSize; j++){
                if(tmp[j].second == cities[i]){
                    tmp[j].first = i+1;
                    break;
                }
            }
            cache[cities[i]] = i+1;
            answer++;
        }
    }

    return answer;
}