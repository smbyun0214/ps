#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, num;
    cin >> N;
    
    deque<int> cache;
    string comm;
    
    while (N-- > 0) {
        cin >> comm;
        
        if (comm == "push_front") {
            cin >> num;
            cache.push_front(num);
        }
        else if (comm == "push_back") {
            cin >> num;
            cache.push_back(num);
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
            else if (comm == "pop_front") {
                cout << cache.front() << '\n';
                cache.pop_front();
            }
            else if (comm == "pop_back") {
                cout << cache.back() << '\n';
                cache.pop_back();
            }
            else if (comm == "front")
                cout << cache.front() << '\n';
            else if (comm == "back")
                cout << cache.back() << '\n';
        }
    }
    
    return 0;
}
