#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//
//using namespace std;
//
//bool isMatching(string str1, string str2, string &result) {
//    if (str1.size() > str2.size())
//        swap(str1, str2);
//
//    int i = 0, j = 0;
//    while (i < str1.size() && j < str2.size()) {
//        if (str1[i] == '*') {
//            ++i;
//            ++j;
//            continue;
//        }
//
//        if (str1[i] == '*')
//
//    }
//    if (str2.find(str1) != string::npos) {
//        result = str2;
//        return true;
//    }
//
//    return false;
//}
//
//string patternMatching(string &lCandi, string &rCandi, int idx, const vector<string> &strs) {
//    const string &base = strs[idx];
//
//    for (int mid = 0, left = 0; mid <= base.size(); ++mid) {
//        if (base[mid] == '*') {
//            string lstr = base.substr(mid - 1, mid - 1 - left);
//            string rstr = base.substr(mid + 1, base.size() - mid);
//
//            string lResult, rResult;
//            if (getMatching(lCandi, lstr, lResult)) {
//                patternMatching(lResult, rCandi, idx + 1, strs);
//            }
//            if (getMatching(rCandi, rstr, rResult)) {
//                patternMatching(lCandi, rResult, idx + 1, strs);
//            }
//            if (rstr.find(right) != string::npos || right.find(rstr) != string::npos) {
//                if (right.size() < rstr.size())
//                    patternMatching(lstr, rstr, idx + 1, strs);
//                else
//                    patternMatching(lsr, right, idx + 1, strs);
//            }
//
//            if (lstr.find(left) != string::npos || left.find(lstr) != string::npos) {
//                if (left.size() < lstr)
//            }
//
//            patternMatching(base.substr(mid - 1, mid - 1 - left), base.substr(mid + 1, base.size() - mid));
//            left = mid + 1;
//        }
//    }
//
//
//    string &str = strs[start];
//
//    for (int i = 0; i < str.size(); ++i) {
//        if (str[i] == '*')
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int T, N;
//
//    cin >> T;
//
//    while (T--) {
//        cin >> N;
//
//        vector<string> strs(N);
//
//        for (int i = 0; i < N; ++i) {
//            cin >> strs[i];
//        }
//
//        sort(strs.begin(), strs.end());
//
//    }
//
//    return 0;
//}


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    
    for (int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        
        int n;
        cin >> n;
    
        vector<string> strs(n);
    
        for (int i = 0; i < n; i++)
            cin >> strs[i];
        
        string pref = "";
        string suf = "";
        
        vector<string> sub;
    
        bool ok = true;
        
        for (string& s : strs) {
            int last = -1;
            
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] == '*') {
                    if (last == -1) {
                        string other_pref = s.substr(0, i);
                        
                        if (other_pref.size() > pref.size()) swap(pref, other_pref);
                        
                        if (pref.substr(0, other_pref.size()) != other_pref) {
                            ok = false;
                            break;
                        }
                    }
                    else {
                        sub.push_back(s.substr(last + 1, i - last - 1));
                    }
                    
                    last = i;
                }
            }
            
            if (!ok) break;
    
            string other_suf = s.substr(last + 1);
    
            if (other_suf.size() > suf.size()) swap(suf, other_suf);
            
            if (suf.substr(suf.size() - other_suf.size()) != other_suf) {
                ok = false;
                break;
            }
        }
    
        if (!ok) {
            cout << "*" << '\n';
        }
        else {
            cout << pref;
            
            for (auto& s : sub)
                cout << s;
            
            cout << suf << '\n';
        }
    }
    
    return 0;
}
