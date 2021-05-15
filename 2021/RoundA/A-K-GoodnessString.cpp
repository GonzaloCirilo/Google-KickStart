#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int t;
    scanf("%d", &t);
    for(int ts = 0; ts < t; ts++){
        printf("Case #%d: ", ts + 1);

        int n, k;
        scanf("%d %d", &n, &k);
        vector<char> s;
        char c;
        for(int i = 0; i < n; i++){
            cin >> c;
            s.push_back(c);
        }
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - i - 1]) ans++;
        }

        //printf("%d %d =", k ,ans);
        printf("%d\n", abs(k-ans));

    }
    return 0;
}           