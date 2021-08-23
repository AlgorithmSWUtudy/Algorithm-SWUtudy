#include <string>
#include <vector>
#include <iostream>

using namespace std;

string binary(int s, int n){
    string str = "";
    int num;
    while(n){
        num = n % 2;
        char c = num + 48;
        str = c + str;
        n /= 2;
    }
    string z = "";
    for(int i = 0; i < s - str.size(); i++){
        z += '0';
    }
    
    return z + str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector <string> v1, v2;
    
    for(int i = 0; i < n; i++){
        v1.push_back(binary(n, arr1[i]));
        v2.push_back(binary(n, arr2[i]));
    }
    for(int i = 0; i < n; i++){
        string s = "";
        for(int j = 0; j < n; j++){
            if(v1[i][j] == '0' && v2[i][j] == '0') s += ' ';
            else s+='#';
        }
        answer.push_back(s);
    }
    return answer;
}