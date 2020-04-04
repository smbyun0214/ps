#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str1, str2;
    cin >> str1 >> str2;
    
    int size1 = str1.size();
    int size2 = str2.size();
    
    int ret = 987654321;
    
    for (int i = 0; i <= size2 - size1; ++i) {
        int tmp = 0;
        
        for (int j = 0; j < size1; ++j) {
            if (str1[j] != str2[i + j])
                ++tmp;
            
            if (ret < tmp)
                break;
        }
        
        ret = min(ret, tmp);
    }
     
    cout << ret << '\n';
    
    
    return 0;
}
