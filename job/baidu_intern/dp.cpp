#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // 输入序列长度
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // 输入序列元素
    }

    vector<int> dp(n, 1); // dp[i] 表示以 nums[i] 结尾的最长上升子序列长度
    int ans = 1; // 最终答案
    for (int i = 1; i < n; i++) {
for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl; // 输出最长上升子序列长度
    return 0;
}

CXX FLAG -O2