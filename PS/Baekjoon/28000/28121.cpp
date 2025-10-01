#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int uf[MAX], depth[MAX];
bool chk[MAX];
vector<int> arr[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, PA, PB, K, ans = 0;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        uf[i] = i, arr[i].push_back(i);

    while (Q--) {
        cin >> A >> B;
        PA = find(A), PB = find(B);

        if (PA != PB) {
            if (chk[PA])
                ans -= arr[PA].size();
            if (chk[PB])
                ans -= arr[PB].size();

            if (arr[PA].size() < arr[PB].size())
                swap(PA, PB);
            K = depth[A] ^ depth[B] ^ 1, chk[PA] |= chk[PB];

            for (int node : arr[PB]) {
                uf[node] = PA, arr[PA].push_back(node);
                depth[node] ^= K;
            }
            arr[PB].clear();
        } else
            ans -= chk[PA] ? arr[PA].size() : 0, chk[PA] |= depth[A] ^ depth[B] ^ 1;

        if (chk[PA])
            ans += arr[PA].size();

        cout << ans << '\n';
    }

    return 0;
}