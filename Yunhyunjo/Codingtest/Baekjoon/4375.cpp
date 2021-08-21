#include <iostream>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        int n = 0;
        for(int i = 1; ;i++){
            n = (n * 10 + 1) % t;
            if(n == 0){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}