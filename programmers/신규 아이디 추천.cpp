#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string normalizeStep2(string& str) {
    string ret = "";
    for (char c : str) {
        if (('a' <= c && c <= 'z')
        || ('0' <= c && c <= '9')
        || ('_' == c || '-' == c || '.' == c)) {
            ret += c;
        }
    }
    return ret;
}

string normalizeStep3(string& str) {
    string ret = "";
    int cur = 0, next = -1;
    while (cur < str.size()) {
        next = cur + 1;
        while (str[cur] == '.' && next < str.size() && str[next] == '.')
            ++next;
        ret += str[cur];
        cur = next;
    }
    return ret;
}

string normalizeStep4(string& str) {
    string ret = str;
    if (ret[0] == '.') {
        ret = ret.substr(1, ret.size() - 1);
    }
    if (ret[ret.size() - 1] == '.') {
        ret = ret.substr(0, ret.size() - 1);
    }
    return ret;
}

string normalizeStep5(string& str) {
    if (str.empty())
        return "a";
    return str;
}

string normalizeStep6(string& str) {
    string ret = str;
    if (str.size() >=16)
        ret = str.substr(0, 15);
    
    return normalizeStep4(ret);
}

string normalizeStep7(string& str) {
    string ret = str;
    while (ret.size() <= 2) {
        ret += ret[ret.size() - 1];
    }
    
    return ret;
}

string solution(string new_id) {
    // step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    // step 2
    new_id = normalizeStep2(new_id);
    
    // step 3
    new_id = normalizeStep3(new_id);
    
    // step 4
    new_id = normalizeStep4(new_id);
    
    // step 5
    new_id = normalizeStep5(new_id);
    
    // step 6
    new_id = normalizeStep6(new_id);
    
    // step 7
    new_id = normalizeStep7(new_id);
    
    return new_id;
}
