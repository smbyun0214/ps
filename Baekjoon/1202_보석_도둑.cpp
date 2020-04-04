#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    
    long long weight, value;
    
    multiset<long long> bags;
    priority_queue<pair<long long, long long> > jewelry;
    
    while (N--) {
        cin >> weight >> value;
        jewelry.push(make_pair(value, weight));
    }
    
    while (K--) {
        cin >> weight;
        bags.insert(weight);
    }
    
    long long ret = 0;
    
    while (!bags.empty() && !jewelry.empty()) {
        pair<long long, long long> jewel = jewelry.top(); jewelry.pop();
        weight = jewel.second;
        value = jewel.first;
        
        multiset<long long>::iterator it = bags.lower_bound(weight);
        if (it != bags.end()) {
            ret += value;
            bags.erase(it);
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
