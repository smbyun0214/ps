//https://codeforces.com/gym/102556/problem/F
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Birthday {
    int year, month, day;
    
    Birthday(int year, int month, int day) : year(year), month(month), day(day) { }
    
    bool operator < (const Birthday& other) const {
        if (year == other.year && month == other.month)
            return day < other.day;
        
        if (year == other.year)
            return month < other.month;
        
        return year < other.year;
    }
    
    bool isFastYear() {
        return month <= 2;
    }
    
    string packing() {
        string ret = to_string(year);
        
        ret += "-";
        
        if (month < 10)
            ret += "0" + to_string(month);
        else
            ret += to_string(month);
        
        ret += "-";
        
        if (day < 10)
            ret += "0" + to_string(day);
        else
            ret += to_string(day);
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    vector<Birthday> birthdays;
    
    char _;
    int year, month, day;
    
    Birthday start(987654321, 987654321, 987654321);
    Birthday end(-1, -1, -1);
    
    for (int i = 0; i < N + 1; ++i) {
        cin >> year >> _ >> month >> _ >> day;
        
        Birthday current(year, month, day);
        
        if (month <= 2)
            birthdays.push_back(current);
        
        start = min(current, start);
        end = max(current, end);
    }
    
    birthdays.push_back(start);
    birthdays.push_back(end);
    
    sort(birthdays.begin(), birthdays.end());
    
    vector<Birthday> ret;
    for (int i = 1; i < birthdays.size(); ++i) {
        Birthday &prev = birthdays[i - 1], &curr = birthdays[i];
        
        int maxJ = (curr.isFastYear() ? curr.year - 1 : curr.year);
        
        for (int j = prev.year + 1; j <= maxJ; ++j) {
            ret.push_back(Birthday(j, 1, 1));
        }
    }
    
    cout << ret.size() << '\n';
    for (Birthday b : ret)
        cout << b.packing() << '\n';
    
    return 0;
}
