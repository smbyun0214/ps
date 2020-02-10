#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, n;
    cin >> N;
    
    priority_queue<int, vector<int>> leftMax;
    priority_queue<int, vector<int>, greater<>> rightMin;
    
    bool isInit = true;
    while (N--) {
        cin >> n;
        
        if (isInit) {
            leftMax.push(n);
            isInit = false;
        }
        else if (leftMax.size() == rightMin.size()) {
            if (n <= rightMin.top()) {
                leftMax.push(n);
            }
            else {
                int tmp = rightMin.top();
                rightMin.pop();
                
                leftMax.push(tmp);
                rightMin.push(n);
            }
        }
        else {
            if (n <= leftMax.top()) {
                int tmp = leftMax.top();
                leftMax.pop();
                
                rightMin.push(tmp);
                leftMax.push(n);
            }
            else {
                rightMin.push(n);
            }
        }
        
        cout << leftMax.top() << '\n';
    }
    
    return 0;
}


