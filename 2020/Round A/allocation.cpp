#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int t, n, b, x;
    vector<int>hs;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &b);
        while(n--){
            scanf("%d", &x);
            hs.push_back(x);
        }

        sort(hs.begin(), hs.end());

        int ans = 0;
        for(int j = 0; j < hs.size(); j++){
            if(b >= hs[j]){
                ans++;
                b -= hs[j];
            }
        }

        printf("Case #%d: %d\n", i, ans);

        hs.clear();
    }
    return 0;
}