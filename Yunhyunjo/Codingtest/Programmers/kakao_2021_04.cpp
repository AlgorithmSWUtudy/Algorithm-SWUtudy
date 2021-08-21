#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2147000000;
    int graph[201][201] = {0,};
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = 1000000;
        }
    }
    
    for(int i = 0; i < fares.size(); i++){
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            for(int k = 1; k <= n; k++){
                if(j == k || i == k) continue;
                else{
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        answer  = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    
    return answer;
}