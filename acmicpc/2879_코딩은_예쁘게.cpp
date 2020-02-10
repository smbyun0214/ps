#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void receiveSignal(const vector<int> &h) {
    stack<int> remaining;
    
    for (int i = 0; i < h.size(); ++i) {
        while (!remaining.empty() && h[remaining.top() - 1] < h[i]) {
            remaining.pop();
        }
        
        if (remaining.empty())
            cout << 0 << ' ';
        else
            cout << remaining.top() << ' ';
        
        remaining.push(i + 1);
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<int> h(N);
    for (int i = 0; i < N; ++i)
        cin >> h[i];
    
    receiveSignal(h);
    
    return 0;
}
