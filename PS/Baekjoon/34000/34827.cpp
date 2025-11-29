#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int N, X = 0, Y = 0;
string S, ans = "XXXXXXXXXXX";

void dfs(int num, int X, int Y) {
    if (num > N * 2)
        return;
    if (abs(X - Y) <= 1) {
        if (num < ans.size())
            ans = S;
        return;
    }

    bool flag;
    for (int i = 0; i < 26; i++) {
        flag = true;
        for (int j = 0; j < num; j++)
            flag &= (S[j] != 'A' + i);
        if (!flag)
            continue;
        S += ('A' + i), dfs(num + 1, X + (S[num - 1] < ('A' + i)), Y + (S[num - 1] > ('A' + i))), S.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i + 1 < N; i++) {
        if (S[i] < S[i + 1])
            X++;
        else
            Y++;
    }

    dfs(N, X, Y);

    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}