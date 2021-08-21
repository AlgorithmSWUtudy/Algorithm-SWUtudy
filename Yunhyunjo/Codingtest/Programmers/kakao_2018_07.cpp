#include <string>

using namespace std;

int solution(string dartResult) {
    int score[3];
    int n = 0;
    char c = ' ';
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] == '*'){
            if(n != 0) score[n-1] = score[n-1] * 2;
            score[n] = score[n] * 2;
            c = '*';
            n++;
        }
        else if(dartResult[i] == '#'){
            score[n] = -score[n] ;
            c = '#';
            n++;
        }
        else{
            int num = i+1;
            score[n] = dartResult[i] - 48;
            if(dartResult[num] == '0'){
                num++;
                score[n] = 10;
                i++;
            }
            if(dartResult[num] == 'D') score[n] *= score[n]; 
            else if(dartResult[num] == 'T') score[n] *= score[n] * score[n];
            if(num+1 < dartResult.size() && dartResult[num+1] > 47 && dartResult[num+1] < 58) {
                c = ' ';
                n++;
            }
            i++;
        }
    }
    return score[0] + score[1] + score[2];
}