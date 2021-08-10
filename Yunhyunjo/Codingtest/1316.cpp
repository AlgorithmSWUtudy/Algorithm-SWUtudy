// baekjoon 1316 :: AC - 0ms

#include <iostream>
#include <string>

using namespace std;

int check(string s);

int main (void){
    int n, num=0;
    cin >> n;
    string arr[n];
    bool test = true;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        num += check(arr[i]);
    }
    cout << num;
}

int check(string s){
    int arr[26] = {0,};
    bool test = true;
    for(int i = 0; i < s.size(); i++){
        if (s[i] != s[i+1]||i==s.size()-1){
            if(arr[s[i]-97] == 0)
                arr[s[i]-97] = 1;
            else{
                test = false;
                break;
            }
        }
        
     }
    if(test)
        return 1;
    else
        return 0;
}
