// https://www.acmicpc.net/problem/6416

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> out, in;
map<int, vector<int> > nodes;
map<int, bool> isUsed;

map<int, int>::iterator it;
map<int, vector<int> >::iterator jt;
map<int, bool>::iterator kt;

bool isTree(int root) {
    isUsed[root] = true;
    for (int child : nodes[root]) {
        if (isUsed[child] || !isTree(child))
            return false;
    }
    return true;
}

bool isAllUsed() {
    for (kt = isUsed.begin(); kt != isUsed.end(); ++kt) {
        if (!kt->second)
        return false;
    }

    return true;
}

int main (int argc, char *argv[]) {
    
    int testcase = 1;
    int u, v;

    while (true) {
        cin >> u >> v;

        if (u == -1 && v == -1) break;
        
        if (u == 0 && v == 0) {
            int root = -1;
            for (it = in.begin(); it != in.end(); ++it) {
                if (it->second == 0) {
                    root = it->first;
                    break;
                }
            }

            if (isTree(root) && isAllUsed())
                cout << "Case " << testcase++ << " is a tree." << '\n';
            else
                cout << "Case " << testcase++ << " is not a tree." << '\n';
            
            out.clear();
            in.clear();
            nodes.clear();
            isUsed.clear();
            
            continue;
        }

        if (out.end() == (it = out.find(u))) out[u] = 0;
        if (out.end() == (it = out.find(v))) out[v] = 0;
        if (in.end() == (it = in.find(u))) in[u] = 0;
        if (in.end() == (it = in.find(v))) in[v] = 0;
        ++out[u], ++in[v];
        
        if (nodes.end() == (jt = nodes.find(u))) nodes.insert(make_pair(u, vector<int>()));
        nodes[u].push_back(v);

        isUsed[u] = false;
        isUsed[v] = false;
    }
    
    return 0;
}
