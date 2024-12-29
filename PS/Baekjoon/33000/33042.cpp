#include <bits/stdc++.h>
#define int long long

#define MAX 200

using namespace std;

map<string, int> cnt;
string arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (++cnt[arr[i]] == 5 && !res)
            res = i;
    }

    cout << res << '\n';

    return 0;
}