#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    
    list<int> people, ret;
    for (int i = 0; i < N; ++i)
        people.push_back(i + 1);
    
    list<int>::iterator kill = people.begin();
    
    int last;
    
    while (N) {
        for (int i = 0; i < (K - 1 % N); ++i) {
            ++kill;
            
            if (kill == people.end())
                kill = people.begin();
        }
        
        ret.push_back(*kill);
        last = *kill;
        
        if (N == 1)
            break;
        
        kill = people.erase(kill);
        if (kill == people.end())
            kill = people.begin();
        
        --N;
    }
    
    cout << '<';
    for (int i : ret) {
        cout << i;
        if (i != last)
            cout << ", ";
    }
    cout << '>';
    
    return 0;
}
