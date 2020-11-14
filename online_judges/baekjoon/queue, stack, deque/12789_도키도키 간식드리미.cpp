// https://www.acmicpc.net/problem/12789

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N;
    cin >> N;
    
    queue<int> waiting;
    stack<int> spaces;
    
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        waiting.push(num);
    }
    
    int i = 1;
    while (!waiting.empty() || !spaces.empty()) {
        bool passed = false;
        
        while (!spaces.empty()) {
            int num = spaces.top();
            
            if (num == i) {
                spaces.pop();
                ++i;
                passed = true;
            }
            else {
                break;
            }
        }
        
        while (!waiting.empty()) {
            int num = waiting.front();
            
            if (num == i) {
                waiting.pop();
                ++i;
                passed = true;
                break;
            }
            else {
                spaces.push(num);
                waiting.pop();
            }
        }
        
        if (!passed) {
            cout << "Sad";
            return 0;
        }
    }
    
    cout << "Nice";
    
    return 0;
}
