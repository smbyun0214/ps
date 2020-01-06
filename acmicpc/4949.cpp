#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    stack<char> cache;
    
    
    string line;
    while (true) {
        getline(cin, line);
        
        if (line == ".")
            break;
        
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '(' || line[i] == ')'
            || line[i] == '[' || line[i] == ']') {
                if (line[i] == '(')
                    cache.push(')');
                else if (line[i] == '[')
                    cache.push(']');
                else if (!cache.empty() && cache.top() == line[i])
                        cache.pop();
                else {
                    cache.push('-');
                    break;
                }
            }
        }
        
        if (cache.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
        
        while(!cache.empty()) cache.pop();
    }
    
    return 0;
}
