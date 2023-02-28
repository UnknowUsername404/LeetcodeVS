#include <string>

using namespace std;

class Solution {
public:
    string buildStr(string& s) {
        string str;
        for (char it : s) {
            if (it != '#') str.push_back(it);
            else if(!str.empty()) {//为空的情况
                str.pop_back();
            }
        }
        return str;
    }

    bool backspaceCompare(string s, string t) {
        return buildStr(s) == buildStr(t);
    }
};