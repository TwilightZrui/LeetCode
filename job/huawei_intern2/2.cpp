#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <string>
// #include <stringstream>
#include <vector>
using namespace std;
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

int add(char a, char b)
{

    if (isdigit(a))
    {
        assert(isdigit(b));
        a = a - '0';
        b = b - '0';
        return a + b;
    }
    else
    {
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
    reverse(v[0].begin(), v[0].end());
    string s1 = v[0];
    if (s1.find(".") == string::npos)
    {
        s1 = "0." + s1;
    }
    for (int i = 1; i < sz; i++)
    {
        reverse(v[i].begin(), v[i].end());
        string s2 = v[i];
        if (s2.find(".") == string::npos)
            s2 = "0." + s2;
        int len1 = s1.size();
        int len2 = s2.size();
        int p1 = s1.find(".");
        int p2 = s2.find(".");
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
        // 把整数对齐到同一长度
        int p3 = len1 - p1, p4 = len2 - p2;
        if (p3 < p4)
        {
            for (int j = 0; j < p4 - p3; j++)
                s1 = s1 + "0";
        }
        else
        {
            for (int j = 0; j < p3 - p4; j++)
            {
                s2 = s2 + "0";
            }
        }
        // 对齐完了
        int tmp = 0;
        int len = s1.size();
        string res;
        for (int j = 0; j < len; j++)
        {
            // 如果小数点
            if (s1[j] == '.')
            {
                res += '.';
                continue;
            }
            int num = tmp + add(s1[j], s2[j]);
            char digit = '0' + num % 10;
            res = res + digit;
            tmp = num / 10;
        }
        // 看看还有没有进的
        char digit = '0' + tmp;
        if (tmp != 0)
            res = res + digit;
        // 去除小数部分的0
        int pos = 0;
        while (pos < res.size() && res[pos] == '0')
            pos++;

        if (res[pos] == '.')
            pos++;
        res = res.substr(pos);
        reverse(res.begin(), res.end());
        s1 = res;
    }
    cout << s1 << endl;
    return 0;
}