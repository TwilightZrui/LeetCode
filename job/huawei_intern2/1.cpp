#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    string str[1000];
    string pre[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> pre[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int ans1 = 0, ans2 = 0, ans = 0;
    int bitw = 0;
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0)
        {
            ans1++;
            arr[i] /= 2;
            arr[i + 1] << 1;
        }
        for (j = i; j < N - 1; j++)
        {
            if (arr[j] % 2 == 0)
            {
                ans2++;
                arr[j] /= 2;
                arr[j + 1] << 1;
            }
        }
        if (j > i)
        {
            arr[j] = 1;
        }
        ans = min(ans1, ans2);
        bitw = j - i;
    }

    cout << ans << endl;
    cout << bitw << endl;
    if (j > i)
    {
        cout << "+" << j - i << endl;
    }
    else
    {
        cout << "-" << i << endl;
    }
    for (int i = 0; i < N; i++)
        cout << arr[i] << endl;

    return 0;
}