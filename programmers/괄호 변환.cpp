#include <string>
#include <vector>

using namespace std;

pair<string, string> getUV(string& str) {
    pair<string, string> ret;
    
    int left = 0, right = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            ++left;
        }
        else {
            ++right;
        }
        
        if (left == right) {
            ret.first = str.substr(0, i + 1);
            ret.second = str.substr(i + 1, str.size() - i);
            break;
        }
    }
    
    return ret;
}

bool isValid(string& str) {
    int left = 0;
    for (char c : str) {
        if (c == '(') {
            ++left;
        }
        else if (left != 0) {
            --left;
        }
        else {
            return false;
        }
    }
    
    return left == 0;
}

string inverse(string& str) {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            str[i] = ')';
        }
        else {
            str[i] = '(';
        }
    }
    return str;
}

string recursive(string &str) {
    if (str.empty())
        return str;
    
    pair<string, string> uv = getUV(str);
    string u = uv.first;
    string v = uv.second;

    string ret = "";
    
    if (isValid(u)) {
        ret += u + recursive(v);
    }
    else {
        string tmp = "(" + recursive(v) + ")";
        u = u.substr(1, u.size() - 2);
        ret += tmp + inverse(u);
    }
    
    return ret;
}

string solution(string p) {
    return recursive(p);
}