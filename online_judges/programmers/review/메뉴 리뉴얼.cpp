// 참고: https://youtu.be/iTS0KdaEYi8

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> cache[11];
int maxCnt[11] = {0};

void setCache(int pos, const string& candi, const string& order) {
    if (pos == order.length()) {
        int length = candi.length();
        if (length >= 2) {
            ++cache[length][candi];
            maxCnt[length] = max(maxCnt[length], cache[length][candi]);
        }
        return;
    }
    
    setCache(pos + 1, candi + order[pos], order);
    setCache(pos + 1, candi, order);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (string& order : orders) {
        sort(order.begin(), order.end());
        setCache(0, "", order);
    }
    
    vector<string> ret;
    for (int length : course) {
        for (pair<string, int> p : cache[length]) {
            if (p.second >= 2 && p.second == maxCnt[length]) {
                ret.push_back(p.first);
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    return ret;
}
