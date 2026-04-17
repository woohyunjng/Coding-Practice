#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;

int A[MAX], B[MAX];
map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    vector<int> ansA, ansB, tmp;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt[A[i]]++;

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        if (cnt[B[i]] > 0)
            ansA.push_back(B[i]), ansB.push_back(B[i]), cnt[B[i]]--, ans++;
        else
            tmp.push_back(B[i]);
    }

    for (int i = 1; i <= N; i++)
        if (cnt[A[i]] > 0)
            ansA.push_back(A[i]), cnt[A[i]]--;
    for (int i : tmp)
        ansB.push_back(i);

    cout << ans << '\n';
    for (int i : ansA)
        cout << i << ' ';
    cout << '\n';
    for (int i : ansB)
        cout << i << ' ';
    cout << '\n';

    return 0;
}