#include <bits/stdc++.h>
#define int long long

#define MAX 500100
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, H, res = 0, cnt = 0;
    string S;

    cin >> N >> H >> S;

    for (char i : S) {
        if (i == '(') {
            if (cnt >= H)
                res++, cnt--;
            else
                cnt++;
        } else {
            if (!cnt)
                res++, cnt++;
            else
                cnt--;
        }
    }

    cout << res;

    return 0;
}