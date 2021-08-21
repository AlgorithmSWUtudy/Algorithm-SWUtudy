#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector <string> split(string s, char delim){
    vector <string> v;
    stringstream str(s);
    string tmp;
    while(getline(str, tmp, delim)){
        if(tmp == "and") continue;
        else v.push_back(tmp);
    }
    return v;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector <vector <string> > arr1;
    vector <vector <string> > arr2;
    
    for(int i = 0; i < info.size(); i++){
        arr1.push_back(split(info[i], ' '));
    }
    
    for(int i = 0; i < query.size(); i++){
        arr2.push_back(split(query[i], ' '));
    }
    
    for(int i = 0; i < arr2.size(); i++){
        int cnt = 0;  
        for(int j = 0; j < arr1.size(); j++){
            if(stoi(arr2[i][4]) > stoi(arr1[j][4])){
                continue;
            }
            if(arr2[i][0] != arr1[j][0] && arr2[i][0] != "-"){
                continue;
            }
            if(arr2[i][1] != arr1[j][1] && arr2[i][1] != "-"){
                continue;
            }
            if(arr2[i][2] != arr1[j][2] && arr2[i][2] != "-"){
                continue;
            }
            if(arr2[i][3] != arr1[j][3] && arr2[i][3] != "-"){
                continue;
            }
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}