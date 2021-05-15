#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){

    int ts;
    cin >> ts;
    for(int t = 0; t < ts; t++){
        cout << "Case #" << t + 1 << ":";
        int n;
        string s;
        cin >> n >> s;
        vector<int>ans = vector<int> (n);
        ans[0] = 1;
        int acc = 1;
        cout << " " << acc;
        for(int i = 1; i < n; i++){
            if(s[i] > s[i - 1]){
                acc++;
                ans[i] = acc;
                cout << " " << acc;
            }else{
                acc = 1;
                cout << " 1";
            }
        }
        cout << endl;
    
    }
    return 0;
}