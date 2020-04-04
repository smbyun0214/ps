#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

deque<int> parsing(string str) {
    deque<int> ret;
    
    string::size_type sz;
    string tmp;
    
    for (int i = 1; i < str.size(); ++i) {
        if ((str[i] == ',' || str[i] == ']') && !tmp.empty()) {
            int num = stoi(tmp, &sz);
            
            ret.push_back(num);
            tmp.clear();
        }
        else {
            tmp += str[i];
        }
    }
    
    return ret;
}

string packing(deque<int> nums, bool isDefault) {
    string tmp = "";
    
    if (isDefault) {
        for (int i = 0; i < nums.size(); ++i) {
            tmp += to_string(nums[i]);
            
            if (i == nums.size() - 1)
                break;
            
            tmp += ',';
        }
    }
    else {
        for (int i = nums.size() - 1; 0 <= i; --i) {
            tmp += to_string(nums[i]);
            
            if (i == 0)
                break;
            
            tmp += ',';
        }
    }
    
    return "[" + tmp + "]";
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    bool isDefault, isError;;
    int size;
    string comm, strNums;
    
    
    while (T--) {
        cin >> comm >> size >> strNums;
        
        isDefault = true; isError = false;
        
        deque<int> nums = parsing(strNums);
        
        for (int i = 0; i < comm.size(); ++i) {
            if (comm[i] == 'R')
                isDefault = !isDefault;
            else {
                if (nums.empty()) {
                    isError = true;
                    break;
                }
                
                if (isDefault)
                    nums.pop_front();
                else
                    nums.pop_back();
            }
        }
        
        if (isError)
            cout << "error" << '\n';
        else
            cout << packing(nums, isDefault) << '\n';
    }
    
    return 0;
}
