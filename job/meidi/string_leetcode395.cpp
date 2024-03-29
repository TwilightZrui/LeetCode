
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
    stack<int> nums;    // 用于保存数字
    stack<string> strs; // 用于保存字符串

    int i = 0;
    while (i < s.size()) {
        // 当前字符是数字
        if (isdigit(s[i])) {
            int n = 0;
            while (isdigit(s[i])) {
                n = n * 10 + s[i] - '0';
                i++;
            }
            nums.push(n);
        }
        // 当前字符是左括号
        else if (s[i] == '[') {
            strs.push("["); // 将左括号压入栈中，用于后续做标记
            i++;
        }
        // 当前字符是右括号，进行字符串解码
        else if (s[i] == ']') {
            string str = "";
            while (strs.top() != "[") { // 将栈中的字符串进行拼接
                str = strs.top() + str;
                strs.pop();
            }
            strs.pop(); // 弹出左括号

            int n = nums.top(); // 获取数字
            nums.pop();

            string newStr = ""; // 将拼接好的字符串复制n次
            for (int j = 0; j < n; j++) {
                newStr += str;
            }
            strs.push(newStr); // 将新得到的字符串压入栈中

            i++; // 修正
        }
        // 当前字符是字母
        else if (isalpha(s[i])) {
            string str = "";
            while (i < s.size() && isalpha(s[i])) {
                str += s[i];
                i++;
            }
            strs.push(str);
        } else {
            i++; // 修正
        }
    }

    // 最后将栈中的所有字符串进行拼接
    string result = "";
    while (!strs.empty()) {
        result = strs.top() + result;
        strs.pop();
    }

    return result;
}

int main() {
    string s = "2(a)c";
    cout << decodeString(s) << endl; // 输出：ac

    return 0;
}
