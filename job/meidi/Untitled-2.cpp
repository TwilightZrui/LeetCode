
#include <iostream>
#include <stack>

using namespace std;

string decodeString(string s) {
    if (s.empty()) {
        return "";
    }
    stack<int> nums;
    stack<string> strs;
    int num = 0;
    string str;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (isalpha(c)) {
            str += c;
        } else if (c == '[') {
            nums.push(num);
            strs.push(str);
            num = 0;
            str = "";
        } else {  // c == ']'
            cout << "nums: ";
            while (!nums.empty()) {
                cout << nums.top() << " ";
                nums.pop();
            }
            int n = nums.top();
            nums.pop();
            string s = strs.top();
            strs.pop();
            string tmp;
            for (int i = 0; i < n; i++) {
                tmp += str;
            }
            str = s + tmp;
        }
    }
    return str;
}

int main() {
    string s = "3(a2(c))3(a)2(bc)";
    cout << decodeString(s) << endl;  // accaccaccaaabcbc

    string s2 = "";
    cout << decodeString(s2) << endl;  // 
    return 0;
}

