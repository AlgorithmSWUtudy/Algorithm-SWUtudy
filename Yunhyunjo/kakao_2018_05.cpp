#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map <string, int> m;
    if(cacheSize == 0) return 5*cities.size();
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        if(m[cities[i]] > 0){
            m[cities[i]] = i+1;
            answer++;
        }
        else{
            answer += 5;
            if(m.size() > cacheSize){
                vector <pair <int, string>> v;
                for(auto it = m.begin();  it!= m.end(); it++){
                    v.push_back(make_pair(it->second, it->first));
                }
                sort(v.begin(), v.end());
                m.erase(v[1].second);
                m[cities[i]] = i+1;
            }
            else{
                m[cities[i]] = i+1;
            }
        }
    }
    
    return answer;
}