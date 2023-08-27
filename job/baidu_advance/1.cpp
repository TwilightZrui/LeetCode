#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <string>

using namespace std;

int main() {
    int T;
    vector<int> res;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        res.push_back(a+b+c);
    }

`2qq
    for (int n : res) {
        cout << n << endl;
    }
}
