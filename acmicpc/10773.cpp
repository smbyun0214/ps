#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    stack<int> nums;
    int ret = 0;
    
    int lines, n;
    cin >> lines;
    
    while (lines-- > 0) {
        cin >> n;
        
        if (n != 0) {
            ret += n;
            nums.push(n);
        }
        else if (!nums.empty()) {
            ret -= nums.top();
            nums.pop();
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
