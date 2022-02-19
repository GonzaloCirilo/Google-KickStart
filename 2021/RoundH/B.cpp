#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <numeric>
#include <string>
#include <map>
#include <stack>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    map<char, int> m;
    m['U'] = 0, m['R'] = 1, m['Y'] = 1, m['B'] = 1, m['O'] = 2, m['P'] = 2, m['G'] = 2, m['A'] = 3;
    char prev = '-';
    vector<char> arr = vector<char>();
    for(int i = 0; i < n; i++) {
        if(s[i] != prev) {
            arr.push_back(s[i]);
        }
        prev = s[i];
    }

    vector<vector<int>> g = vector<vector<int>> ();
    long count = 0;
    long rind = -1, yind = -1, bind =-1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 'Y') {
            g.push_back(vector<int>());
            long yindAux = count++;
            if (yind != -1) {
                g[yind].push_back(yindAux);
                g[yindAux].push_back(yind);
            }
            yind = yindAux;
            rind = -1;
            bind = -1;

        } else if(arr[i] == 'B') {
            g.push_back(vector<int>());
            long bindAux = count++;
            if(bind != -1){
                g[bind].push_back(bindAux);
                g[bindAux].push_back(bind);
            }
            bind = bindAux;
            rind = -1;
            yind = -1;

        } else if(arr[i] == 'R') {
            g.push_back(vector<int>());
            long rindAux = count++;
            if(rind != -1){
                g[rind].push_back(rindAux);
                g[rindAux].push_back(rind);
            }
            rind = rindAux;
            bind = -1;
            yind = -1;

        } else if(arr[i] == 'G') {
            g.push_back(vector<int>());
            long yindAux = count++;
            if (yind != -1) {
                g[yind].push_back(yindAux);
                g[yindAux].push_back(yind);
            }
            yind = yindAux;
            g.push_back(vector<int>());
            long bindAux = count++;
            if(bind != -1){
                g[bind].push_back(bindAux);
                g[bindAux].push_back(bind);
            }
            bind = bindAux;
            rind = -1;

        } else if (arr[i] == 'P') {
            g.push_back(vector<int>());
            long bindAux = count++;
            if(bind != -1){
                g[bind].push_back(bindAux);
                g[bindAux].push_back(bind);
            }
            bind = bindAux;
            g.push_back(vector<int>());
            long rindAux = count++;
            if(rind != -1){
                g[rind].push_back(rindAux);
                g[rindAux].push_back(rind);
            }
            rind = rindAux;
            yind = -1;
        } else if(arr[i] == 'O') {
            g.push_back(vector<int>());
            long rindAux = count++;
            if(rind != -1){
                g[rind].push_back(rindAux);
                g[rindAux].push_back(rind);
            }
            rind = rindAux;
            g.push_back(vector<int>());
            long yindAux = count++;
            if (yind != -1) {
                g[yind].push_back(yindAux);
                g[yindAux].push_back(yind);
            }
            yind = yindAux;
            bind = -1;
        } else if(arr[i] == 'A') {
            g.push_back(vector<int>());
            long rindAux = count++;
            if(rind != -1){
                g[rind].push_back(rindAux);
                g[rindAux].push_back(rind);
            }
            rind = rindAux;
            g.push_back(vector<int>());
            long yindAux = count++;
            if (yind != -1) {
                g[yind].push_back(yindAux);
                g[yindAux].push_back(yind);
            }
            yind = yindAux;
            g.push_back(vector<int>());
            long bindAux = count++;
            if(bind != -1){
                g[bind].push_back(bindAux);
                g[bindAux].push_back(bind);
            }
            bind = bindAux;
        } else if (arr[i] == 'U') {
            rind = -1;
            bind = -1;
            yind = -1;
        }
    } 

    vector<int> visited = vector<int>(g.size(), 0);
    long long ans = 0;
    for(int i = 0; i < g.size(); i++) {
        if(visited[i])
            continue;
        int s = i;
        stack<int> ss;
        visited[s] = 1;
        ss.push(s);
        while(!ss.empty()){
            int n = ss.top(); ss.pop();
            for(int j = 0; j < g[n].size(); j++){
                if(!visited[g[n][j]]){
                    ss.push(g[n][j]);
                    visited[g[n][j]] = 1;
                }
            }
        }
        ans++;
    }
    cout<<" " << ans << endl;

    /*for(auto x : g){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }*/
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