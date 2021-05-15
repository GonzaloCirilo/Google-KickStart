#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> rev, vector<int> &visited, int node, set<int> &printed){
    //visited[node] = 1;
    for(int i = 0; i <rev[node].size(); i++){
        if(!visited[rev[node][i]]){
            visited[rev[node][i]] = 1;
            DFS(rev, visited, rev[node][i], printed);
        }
    }
    if(printed.insert(node + 'A').second)
        putchar(node + 'A');
}
int main(){
    int t, r ,c;
    scanf("%d", &t);
    for(int ts = 1; ts<= t; ts++){
        printf("Case #%d:", ts);

        scanf("%d %d\n", &r, &c);
        int grid[32][32] = {};

        set<int> s[32], adj[29];

        vector<vector<int>> graph = vector<vector<int>>(27, vector<int>()), rev = graph;
        bool valid = true;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                char c;
                scanf("%c", &c);
                grid[i][j] = c - 'A';
                if(i == 0)
                    s[j].insert(c - 'A');
                if(i > 0 && !(s[j].insert(c - 'A').second) && grid[i - 1][j] != grid[i][j])
                    valid = false;

                if(i > 0  && grid[i - 1][j] != grid[i][j] && adj[grid[i][j]].insert(grid[i-1][j]).second){
                    graph[grid[i][j]].push_back(grid[i-1][j]);
                    rev[grid[i-1][j]].push_back(grid[i][j]);
                }
            }
            getchar();
        }

        if(!valid){
            printf(" -1\n");
            continue;
        }
        putchar(' ');
        vector<int> visited = vector<int>(28, 0);
        stack<int> toposort;
        for(int i = 0; i < c; i++){
            if(!visited[grid[r-1][i]]){
                int s = grid[r-1][i];

                stack<int> q;
                q.push(s);
                toposort.push(s);
                visited[s] = 1;

                while(!q.empty()){
                    int node = q.top(); q.pop();
                    for(int j = 0; j < graph[node].size(); j++){
                        int ad = graph[node][j];
                        if(!visited[ad]){
                            visited[ad] = 1;
                            q.push(ad);
                            toposort.push(ad);
                            //putchar(ad + 'A');
                        }
                    }

                }

            }
        }
        //putchar('\n');

        visited = vector<int>(28, 0);
        set<int> printed;
        while(!toposort.empty()){
            int node = toposort.top(); toposort.pop();
            visited[node] = 1;
            DFS(rev, visited, node, printed);

            
        }
        putchar('\n');

        
    }
    return 0;
}