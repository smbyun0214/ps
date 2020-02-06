#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    string str;
    
    cin >> T;
    
    while (T--) {
        cin >> str;
        
        int size = 0;
        list<char> clist;
        list<char>::iterator cursor = clist.end();
        
        for (char c : str) {
            switch (c) {
                case '<':
                    if (cursor != clist.begin())
                        --cursor;
                    break;
                    
                case '>':
                    if (cursor != clist.end())
                        ++cursor;
                    break;
                    
                case '-':
                    if (cursor == clist.begin())
                        break;
                    
                    if (size < 2) {
                        clist.clear();
                        cursor = clist.end();
                        size = 0;
                    }
                    else {
                        if (cursor != clist.begin())
                            --cursor;
                        
                        cursor = clist.erase(cursor);
                        --size;
                    }
                    break;
                    
                default:
                    cursor = clist.insert(cursor, c);
                    ++cursor;
                    ++size;
                    break;
            }
        }
        
        for (char c : clist)
            cout << c;
        cout << '\n';
    }
    
    return 0;
}
