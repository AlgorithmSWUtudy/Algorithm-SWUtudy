#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    brown = (brown - 4) / 2;
    int x;
    if(brown % 2 == 0) x = brown / 2;
    else x = brown / 2 + 1;
    int y = brown - x;
    while(x*y != yellow){
        x++;
        y--;
    }
    answer.push_back(x+2);
    answer.push_back(y+2);
    return answer;
}