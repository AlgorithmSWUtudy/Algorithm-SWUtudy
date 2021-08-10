#include <string>
#include <vector>
#include <cmath>

using namespace std;

int key[4][3];

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int lt[2] = {3,0};
    int rt[2] = {3,2};
    
    for(int i: numbers){
        if(i == 1 || i == 4 || i == 7) {
            answer += "L";
            lt[0] = i / 3;
            lt[1] = 0;
        }
        else if(i == 3 || i == 6 || i == 9) {
            answer += "R";
            rt[0] = i / 3 - 1;
            rt[1] = 2;
        }
        else{
            int x, y = 1;
            if(i == 0) x = 3;
            else x = i / 3;
            int ld = abs(x - lt[0]) + abs(y - lt[1]);
            int rd = abs(x - rt[0]) + abs(y - rt[1]);
            if(ld < rd) {
                answer += "L";
                lt[0] = x;
                lt[1] = y;
            }
            else if(ld > rd){
                answer += "R";
                rt[0] = x;
                rt[1] = y;
            }
            else if(hand == "right"){
                answer += "R";
                rt[0] = x;
                rt[1] = y;
            }
            else{
                answer += "L";
                lt[0] = x;
                lt[1] = y;
            }
        }
    }
    
    return answer;
}