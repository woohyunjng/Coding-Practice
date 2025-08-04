#include <bits/stdc++.h>
using namespace std;

const int MAX = 20001;

int N, A[MAX];
map<int, int> cnt;

int get(int K) {
    int ans = 0;
    cnt.clear();
    for (int i = 1; i <= N; i++)
        ans = max(ans, ++cnt[A[i] % K]);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, K, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, N);

    ans = get(2);
    for (int i = 0; i < 200; i++) {
        X = dis(gen), Y = dis(gen), K = abs(A[X] - A[Y]);
        if (X == Y)
            continue;
        for (int i = 2; i * i <= K; i++) {
            if (K % i)
                continue;
            while (K % i == 0)
                K /= i;
            ans = max(ans, get(i));
        }
        if (K > 1)
            ans = max(ans, get(K));
    }

    cout << ans << '\n';

    return 0;
}