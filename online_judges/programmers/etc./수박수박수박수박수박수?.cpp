#include <string>

using namespace std;

string solution(int n) {
    string str = "수박";
    string answer;
    for (int i = 0; i < n; ++i) {
        answer += str.substr(3*(i%2), 3);
    }
    
    return answer;
}
