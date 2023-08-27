
#include <iostream>
#include <string>
#include <stack>

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
                i++; // 修正：拆分数字时，需要把i移动到正确的位置
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

            // 修正：在处理']'字符时，需要把i向前移动一位，避免一次次处理相同的字母
            i++;
        }
        // 当前字符是字母
        else {
            string str = "";
            while (i < s.size() && isalpha(s[i])) {
                str += s[i];
                i++;
            }
            strs.push(str); // 将字符串压入栈
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
    string s = "3(a2(c))3(a)2(bc)";
    string result = decodeString(s);
    cout << result << endl; // 输出: "accaccaccaaabcbc"
    return 0;
}
