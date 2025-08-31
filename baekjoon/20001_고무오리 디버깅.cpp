// https://www.acmicpc.net/problem/20001

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main (int argc, char *argv[]) {
    
    string str;
    stack<string> strs;
    
    while (true) {
        getline(cin, str);
        
        if (str == "문제")
            strs.push(str);
        else if (str == "고무오리") {
            if (strs.empty()) {
                strs.push("문제");
                strs.push("문제");
            }
            else
                strs.pop();
        }
        
        if (str == "고무오리 디버깅 끝")
            break;
    }
    
    cout << (strs.empty() ? "고무오리야 사랑해" : "힝구");
    
    return 0;
}
