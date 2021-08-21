//baekjoon AC - 100ms

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector <long long> d(1000000+1, 1);
    for(int i = 2; i <= 1000000; i++){
        for(int j = 1; i*j <= 1000000; j++){
            d[i*j] += i;
        }
    }
    vector <long long> s(1000001);
    for(int i = 1; i <= 1000000; i++){
        s[i] = s[i-1] + d[i];
    }
    
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << s[n] << '\n';
    }
}
