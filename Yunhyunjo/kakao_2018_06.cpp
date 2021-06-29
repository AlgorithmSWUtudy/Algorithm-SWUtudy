#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long bin(int i){
    long long r, res = 0, j = 1;
    while(i != 0){
        r = i % 2;
        i /= 2;
        res += r*j;
        j *= 10;
    }
    return res;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i = 0; i < n; i++){
        string a = to_string(bin(arr1[i])), b = to_string(bin(arr2[i]));
        string z = "";
        for(int k = 0; k < n-a.size(); k++){
            z+='0';
        }
        a = z + a;
        z = "";
        for(int k = 0; k < n-b.size(); k++){
            z+='0';
        }
        b = z + b;
        z = "";
        for(int j = 0; j < n; j++){
            if(a[j] == '0' && b[j] == '0') z += ' ';
            else z += '#';
        }
        answer[i] = z;
    }
    return answer;
}