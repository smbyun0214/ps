#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    
    string command;
    int option;
    
    queue<int> q;
    
    while (N--) {
        cin >> command;
        
        if (!command.compare("push")) {
            cin >> option;
            q.push(option);
        }
        else if (!command.compare("pop")) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (!command.compare("size")) {
            cout << q.size() << '\n';
        }
        else if (!command.compare("empty")) {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else {
            if (q.empty())
                cout << -1 << '\n';
            else if (!command.compare("front"))
                cout << q.front() << '\n';
            else
                cout << q.back() << '\n';
        }
    }
    
    return 0;
}
