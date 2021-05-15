#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int t;
    int n, k, ai;
    scanf("%d", &t);
    for(int ts = 1; ts<= t; ts++){
        printf("Case #%d:", ts);

        scanf("%d %d", &n, &k);
        bool inCountdown = false;
        int ans = 0, next;
        for(int i = 0; i < n; i++){
            scanf("%d", &ai);

            if(inCountdown && next == ai){
                next--;
                if(next == 0){
                    inCountdown = false;
                    ans++;
                }
            }else{
                inCountdown = false;
            }

            if(ai == k){
                inCountdown = true;
                next = k - 1;
            }
        }

        printf(" %d\n", ans);
        
    }
    return 0;
}