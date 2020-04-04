#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    stack<int> nums;
    
    int lines;
    cin >> lines;
    
    string comm;
    int num;
    
    while (lines-- > 0) {
        cin >> comm;
        
        if (comm == "push") {
            cin >> num;
            nums.push(num);
        }
        else if (comm == "size") {
            cout << nums.size() << '\n';
        }
        else if (comm == "empty") {
            cout << (nums.empty() == true ? 1 : 0) << '\n';
        }
        else {
            if (nums.empty()) {
                cout << -1 << '\n';
            }
            else {
                if (comm == "pop") {
                    cout << nums.top() << '\n';
                    nums.pop();
                }
                else if (comm == "top") {
                    cout << nums.top() << '\n';
                }
            }
        }
    }
    
    return 0;
}
