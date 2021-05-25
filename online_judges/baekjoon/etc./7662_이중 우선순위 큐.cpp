// https://www.acmicpc.net/problem/7662 

#include <iostream>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, k;
    cin >> T;

    while (T--) {
        int val;
        string cmd;
        multiset<int> ms;
        multiset<int>::iterator minIter, maxIter;

        cin >> k;
        while (k--) {
            cin >> cmd >> val;
            if (cmd == "I") {
                ms.insert(val);   
            }
            else if (!ms.empty()) {
                if (val == -1) {
                    minIter = ms.begin();
                    ms.erase(minIter);
                }
                else {
                    maxIter = ms.end();
                    --maxIter;
                    ms.erase(maxIter);
                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            minIter = ms.begin();
            maxIter = ms.end();
            --maxIter;
            cout << *maxIter << " " << *minIter << '\n';
        }
    }

    return 0;
}
