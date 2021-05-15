#include <bits/stdc++.h>
using namespace std;

int main(){
    int ts;

    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++){
        printf("Case #%d:", t);

        int n, a, b, c;

        scanf("%d %d %d %d", &n, &a, &b, &c);

        if(
            (c + (a -c) + (b -c ) > n) ||
            (a == n && b == a && c != n) ||
            (n > 1 && a == b && a == 1 && c == a)
            ){
            printf(" IMPOSSIBLE\n");
            continue;
        }

        stack<int>left; queue<int> right; vector<int> rfill = vector<int>(), lfill = vector<int>();

        int mine = 102;

        int aux = n - 1; 
        for(int i = 0; i < (a - c); i++){
            left.push(aux--);
        }

        mine = min(mine, aux);

        aux = n - 1; 
        for(int i = 0; i < (b - c); i++){
            right.push(aux--);
        }
        mine = min(mine, aux);

        //printf("%d\n",(n - a - b + c));

        if(a == c){
            if(a == b && b == c && a < n){
                printf(" %d", n);

                for(int i = 0; i < (n - c); i++){
                    printf(" %d", n - 1);
                }

                for(int i = 0; i < c - 1; i++){
                    printf(" %d", n);
                }
                printf("\n");
                continue;
            }
            for(int i = 0; i < (n - a - b + c); i++){
                rfill.push_back(mine);
            }
        } else {            
            for(int i = 0; i < (n - a - b + c); i++){
                lfill.push_back(mine);
            }
        }

        while(!left.empty()){
            printf(" %d", left.top()); left.pop();
        }

        for(int i = 0; i < lfill.size(); i++){
            printf(" %d", lfill[i]);
        }

        for(int i = 0; i < c; i++) {
            printf(" %d", n);
        }

        for(int i = 0; i < rfill.size(); i++){
            printf(" %d", rfill[i]);
        }

        while(!right.empty()){
            printf(" %d", right.front()); right.pop();
        }
        printf("\n");
    }
    return 0;
}