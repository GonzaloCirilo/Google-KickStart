#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int ts;
    cin >> ts;
    for(int t = 1; t <= ts; t++){
        string line;
        cin >> line;
        //cout << aux << endl;

        long long x = 0, y = 0;

        long long pow10to9 = 1000000000;

        stack<long long> ss; long long mult = 1, n = 0, s = 0, w = 0, e = 0;

        for(int i = 0; i < line.size(); i++){

            if(line[i] - '0' >= 0 && line[i] - '0' <= 9){
                mult = ((mult % pow10to9)* (line[i] - '0'))  % pow10to9;
                ss.push(mult);
            }

            if(line[i] == ')'){
                ss.pop();
                mult = ss.empty() ? 1 : ss.top();
            }


            switch(line[i]){
                case 'N':
                    y = (y - mult + pow10to9) % pow10to9;
                    break;
                case 'S':
                    y = (y + mult + pow10to9) % pow10to9;
                    break;
                case 'W':
                    x = (x - mult + pow10to9) % pow10to9;
                    break;
                case 'E':
                    x = (x + mult + pow10to9) % pow10to9;
                    break;
            }
        }

        cout << "Case #" << t << ": " << x + 1 << " " << y + 1 << endl;
    }
    return 0;
}