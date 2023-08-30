#include <bits/stdc++.h>
using namespace std;

// 以加号把表达式分割成多个部分，返回一个string数组
vector<string> split(const string &str, char delim = '+')
{
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim))
    {
        if (!token.empty())
        {
            tokens.push_back(token);
        }
    }
    return tokens;
}

// 返回两个字符相加结果
int add(char a, char b)
{
    if (isdigit(a))
    {
        assert(isdigit(b)); // a是字符但b不是字符的情况，其实不该发生，发生的话报个错。
        a = a - '0';        // 字符转数字
        b = b - '0';
        return a + b;
    }
    else
    {
        assert(!isdigit(b));
        // 下面9种
        if (a == '!' && b == '!')
            return 0;
        if (a == '!' && b == '@')
            return 13;
        if (a == '!' && b == '#')
            return 4;
        if (a == '@' && b == '!')
            return 13;
        if (a == '@' && b == '@')
            return 7;
        if (a == '@' && b == '#')
            return 20;
        if (a == '#' && b == '!')
            return 4;
        if (a == '#' && b == '@')
            return 20;
        if (a == '#' && b == '#')
            return 5;
    }
}

string cmd;

int main()
{
    int n;
    cin >> n;
    cin >> cmd;
    vector<string> v = split(cmd);
    int sz = v.size();
    // cout << v << endl;
    // 把s1翻转过来，方便计算，比如3.75翻转成57.3
    reverse(v[0].begin(), v[0].end());
    string s1 = v[0];
    // 如果是整数，补一个.0，方便小数点对齐
    if (s1.find(".") == string::npos)
        s1 = "0." + s1;
    for (int i = 1; i < sz; i++)
    {
        reverse(v[i].begin(), v[i].end());
        string s2 = v[i];
        if (s2.find(".") == string::npos)
            s2 = "0." + s2;
        int len1 = s1.size(), len2 = s2.size();
        int p1 = s1.find("."), p2 = s2.find(".");
        // 下面四行，对应着 3.7 和 5.41这种，第二个加数的小数点位数更多，把3.7变成3.70
        if (p1 < p2)
        {
            for (int j = 0; j < p2 - p1; j++)
                s1 = "0" + s1;
        }
        else
        {
            for (int j = 0; j < p1 - p2; j++)
                s2 = "0" + s2;
        }
        // 下面四行，对应着把整数位对齐到同一长度
        int p3 = len1 - p1, p4 = len2 - p2;
        if (p3 < p4)
        {
            for (int j = 0; j < p4 - p3; j++)
                s1 = s1 + "0";
        }
        else
        {
            for (int j = 0; j < p3 - p4; j++)
                s2 = s2 + "0";
        }
        // 对齐完了，现在应该 整数部分和小数部分长度都一样
        int tmp = 0; // 进数
        int len = s1.size();
        // res保存s1+s2的结果
        string res;
        // 对于每一位，相加一下，更新res，保留进数
        for (int j = 0; j < len; j++)
        {
            // 如果是小数点，直接跳过
            if (s1[j] == '.')
            {
                res += '.';
                continue;
            }
            int i = j;
            for(int i = 0; i <len; i++)
            {
                // 如果是小数点，直接跳过
                if (s1[i] == '.')
                {
                    res += '.';
                    continue;
                }
                int tmp = add(s1[i], s2[j]);
                res += to_string(tmp);
            }
            int num = tmp + add(s1[j], s2[j]);
            char digit = '0' + num % 10;
            res = res + digit;
            tmp = num / 10;
        }
        // 看看还有没有进的，如果有，加上
        char digit = '0' + tmp;
        if (tmp != 0)
            res = res + digit;
        // 去除小数部分的0
        int pos = 0;
        while (pos < res.size() && res[pos] == '0')
            pos++; // 第一个条件是为了避免0+0=0，然后跳过0的时候超出字符串范围
        if (res[pos] == '.')
            pos++; // 如果没有小数部分，自然也不要.了
        res = res.substr(pos);
        reverse(res.begin(), res.end());
        s1 = res;
    }
    cout << s1 << endl;
    return 0;
}