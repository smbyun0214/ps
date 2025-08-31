#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0, j = 0; i < s.size(); ++i, ++j) {
        if (s[i] == ' ') {
            j = -1;
            continue;
        }
        
        if (j % 2) {
            s[i] = tolower(s[i]);
        }
        else {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}
