#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, num;
    cin >> N;
    
    queue<int> cache;
    string comm;
    
    while (N-- > 0) {
        cin >> comm;
        
        if (comm == "push") {
            cin >> num;
            cache.push(num);
        }
        else if (comm == "size") {
            cout << cache.size() << '\n';
        }
        else if (comm == "empty") {
            cout << (cache.empty() ? 1 : 0) << '\n';
        }
        else {
            if (cache.empty())
                cout << -1 << '\n';
            else if (comm == "pop") {
                cout << cache.front() << '\n';
                cache.pop();
            }
            else if (comm == "front") {
                cout << cache.front() << '\n';
            }
            else if (comm == "back") {
                cout << cache.back() << '\n';
            }
        }
    }
    
    return 0;
}
