#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> cache;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int recursiveCnt(string& subNumber, vector<bool>& isUsed, const string& numbers) {   
    int ret = 0;
    
    for (int i = 0; i < isUsed.size(); ++i) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            subNumber.push_back(numbers[i]);
            ret += recursiveCnt(subNumber, isUsed, numbers);
            subNumber.pop_back();
            isUsed[i] = false;
        }
    }
    
    if (subNumber.empty())
        return ret;
    
    int subNum = stoi(subNumber);
    if (isPrime(subNum) && cache.find(subNum) == cache.end()) {
        cache.insert(subNum);
        ++ret;
    }
    
    return ret;
}

int solution(string numbers) {
    int ret = 0;
    string subNumber = "";
    vector<bool> isUsed(numbers.size(), false);
    
    for (int i = 0; i < numbers.size(); ++i) {
        ret += recursiveCnt(subNumber, isUsed, numbers);
    }
    
    return ret;
}
