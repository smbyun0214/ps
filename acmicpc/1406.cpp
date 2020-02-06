#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    char cmd, opt;
    int M;
    string str;
    
    cin >> str >> M;
    
    list<char> clist;
    
    for (char c : str)
        clist.push_back(c);
    
    int size = str.size();
    list<char>::iterator cursor = clist.end();
    
    while (M--) {
        cin >> cmd;
        
        switch (cmd) {
            case 'L':
                if (cursor != clist.begin())
                    --cursor;
                break;
            
            case 'D':
                if (cursor != clist.end())
                    ++cursor;
                break;
            
            case 'B':
                if (cursor == clist.begin())
                    break;
                
                if (size == 1) {
                    clist.clear();
                    size = 0;
                    
                    cursor = clist.begin();
                }
                else {
                    --cursor;
                    cursor = clist.erase(cursor);
                    --size;
                }
                break;
            
            case 'P':
                cin >> opt;
                cursor = clist.insert(cursor, opt);
                ++cursor;
                ++size;
                break;
                
            default:
                break;
        }
    }
    
    for (char c : clist)
        cout << c;
    cout << '\n';
    
    return 0;
}
