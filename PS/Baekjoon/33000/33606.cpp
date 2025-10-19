#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    string _S;
    bool ans;

    vector<int> arr[2];

    cin >> T;
    while (T--) {
        cin >> N >> _S, ans = true;

        for (int i = 1; i <= N << 1; i++)
            A[i] = _S[i - 1] == 'R'; // 0이 앞으로 오게

        for (int i = 1; i <= N; i++)
            if (A[i] == 1)
                arr[0].push_back(i);
        for (int i = N + 1; i <= (N << 1); i++)
            if (A[i] == 0)
                arr[1].push_back(i);

        ans &= (N - arr[0].size()) % 2 == 0;
        if (!arr[0].empty()) {
            ans &= (arr[0].front() - 1) * 2 >= (N - (int)arr[0].size());
            ans &= ((N << 1) - arr[1].back()) * 2 >= (N - (int)arr[1].size());
        }

        cout << (ans ? "YES" : "NO") << '\n';
        arr[0].clear(), arr[1].clear();
    }

    return 0;
}