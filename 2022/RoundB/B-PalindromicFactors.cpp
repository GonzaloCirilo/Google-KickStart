#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isPalindrome(long long n) {
    string s = to_string(n);
    //cout << s << endl;
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - 1 -i]){
            return false;
        }
    }
    return true;
}


void solve(){
    long long n, cont = 0;
    cin >> n;

    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            if(isPalindrome(i))
                cont++;
            if(isPalindrome(n/i) && i != (n/i))
                cont++;
        }
    }
    cout <<  " " << cont << endl;
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ":";
        solve();
    }
    return 0;
}