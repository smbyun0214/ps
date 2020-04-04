#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

#define MAX_QUERY 150

using namespace std;

string modified(const vector<bitset<10> > &bits, int type = 4) {
    string ret;
    
    if (type == 1) {
        for (bitset<10> tmp : bits) {
            tmp.flip();
            ret += tmp.to_string();
        }
    }
    else if (type == 2) {
        for (bitset<10> tmp : bits) {
            ret += tmp.to_string();
        }
        reverse(ret.begin(), ret.end());
    }
    else if (type == 3) {
        for (bitset<10> tmp : bits) {
            tmp.flip();
            ret += tmp.to_string();
        }
        reverse(ret.begin(), ret.end());
    }
    else {
        for (bitset<10> tmp : bits) {
            ret += tmp.to_string();
        }
    }
    
    return ret;
}

bool isExists(vector<bitset<10> > &bits, const bitset<10> &comp) {
    string strComp = comp.to_string();
    
    for (int i = 1; i <= 4; ++i) {
        string type = modified(bits, i);
        if (type.find(strComp) != string::npos)
    }
    
    return false;
}

vector<bitset<10> > setBits(const string &strBits) {
    vector<bitset<10> > ret (strBits.size() / 10);
    
    for (int i = 0, j = 0; i < strBits.size(); i += 10, ++j) {
        ret[j] = bitset<10>(strBits.substr(i, 10));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    
    int T, bitSize;
    
    cin >> T >> bitSize;
    
    while (T--) {
        
        vector<bitset<10> > bits(bitSize / 10, bitset<10>(0));
    
        char status;
        int pos, val;
        
        bitset<10> tmp(0);
        
        int idx = 0;
        
        for (int i = 0; i < MAX_QUERY; ++i) {
            pos = (i % bitSize) + 1;
            
            cout << pos << '\n';
            cin >> val;
            
            tmp[10 - pos] = val;
            
            if (i % 10 == 9) {
                if (!isExists(bits, tmp)) {
                    bits[idx] = tmp;
                    ++idx;
                }
                
                tmp.reset();
            }
        }
        
        cout << modified(bits, 4) << '\n';
        cin >> status;
    }
    
    return 0;
}
