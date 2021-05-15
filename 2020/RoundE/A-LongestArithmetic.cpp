#include <bits/stdc++.h>
using namespace std;

int main(){
    int ts, n;
    vector<int> dif, arr;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++){
        printf("Case #%d: ", t);

        scanf("%d", &n);

        arr = vector<int>(n), dif = arr;

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        for(int i = 1; i < n; i++){
            dif[i-1] = arr[i] - arr[i- 1];
            //printf("%d ", dif[i-1]);
        }

        int current = dif[0];
        int count = 0, ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(current == dif[i]){
                count++;
            }else{
                ans = max(count, ans);
                count = 1;
                current = dif[i];
            }
        }

        ans = max(count, ans);

        printf("%d\n", ans + 1);

    }
    return 0;
}