#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[1002][1002];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    
    string str1, str2;
    cin >> str1 >> str2;
    
    if (str1.size() < str2.size())
        swap(str1, str2);
    
    int lcsSize = 0;
    string lcsStr = "";
    
    for (int i = 0; i < str1.size(); ++i) {
        for (int j = 0; j < str2.size(); ++j) {
            if (str1[i] == str2[j])
                cache[i + 1][j + 1] = cache[i][j] + 1;
            else
                cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
            lcsSize = max(lcsSize, cache[i + 1][j + 1]);
        }
    }
    
    int str2End = str2.size() - 1;
    int tmpSize0 = lcsSize, tmpSize1 = lcsSize - 1;
    
    for (int i = str1.size() - 1; 0 <= i; --i) {
        for (int j = str2End; 0 <= j; --j) {
            if (cache[i + 1][j + 1] == tmpSize0 && cache[i][j + 1] == tmpSize1 && cache[i + 1][j] == tmpSize1) {
                lcsStr += str1[i];
                --tmpSize0;
                --tmpSize1;
                str2End = j - 1;
                break;
            }
        }
        
        if (tmpSize1 == -1)
            break;
    }
    
    reverse(lcsStr.begin(), lcsStr.end());
    
    cout << lcsSize << '\n';
    cout << lcsStr << '\n';
    
    return 0;
}
