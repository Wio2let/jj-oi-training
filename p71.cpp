#include <iostream>
#include <vector>

using namespace std;

string name(int t) {
    if (t == 1) return "/*";
    if (t == 2) return "(";
    if (t == 3) return "[";
    return "{";
}

int main() {
    vector<int> stk;
    string s;

    while (getline(cin, s)) {
        if (s == ".") break;

        for (int i = 0; i < (int)s.size(); i++) {
            if (i + 1 < (int)s.size() && s[i] == '/' && s[i+1] == '*') {
                stk.push_back(1);
                i++;
            } else if (i + 1 < (int)s.size() && s[i] == '*' && s[i+1] == '/') {
                if (stk.empty()) { cout << "NO\n?-*/" << endl; return 0; }
                if (stk.back() != 1) { cout << "NO\n" << name(stk.back()) << "-?" << endl; return 0; }
                stk.pop_back();
                i++;
            } else if (s[i] == '(') {
                stk.push_back(2);
            } else if (s[i] == ')') {
                if (stk.empty()) { cout << "NO\n?-)" << endl; return 0; }
                if (stk.back() != 2) { cout << "NO\n" << name(stk.back()) << "-?" << endl; return 0; }
                stk.pop_back();
            } else if (s[i] == '[') {
                stk.push_back(3);
            } else if (s[i] == ']') {
                if (stk.empty()) { cout << "NO\n?-]" << endl; return 0; }
                if (stk.back() != 3) { cout << "NO\n" << name(stk.back()) << "-?" << endl; return 0; }
                stk.pop_back();
            } else if (s[i] == '{') {
                stk.push_back(4);
            } else if (s[i] == '}') {
                if (stk.empty()) { cout << "NO\n?-}" << endl; return 0; }
                if (stk.back() != 4) { cout << "NO\n" << name(stk.back()) << "-?" << endl; return 0; }
                stk.pop_back();
            }
        }
    }

    if (!stk.empty()) {
        cout << "NO\n" << name(stk.back()) << "-?" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
