#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 0;
    multiset<int> A, B, C;
    multiset<int>::iterator it_B, it_C;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X, A.insert(X);
    for (int i = 1; i <= N; i++)
        cin >> X, B.insert(X);
    for (int i = 1; i <= N; i++)
        cin >> X, C.insert(X);

    for (int i : A) {
        it_B = B.upper_bound(i);
        if (it_B == B.end())
            break;
        X = *it_B, B.erase(it_B);

        it_C = C.upper_bound(X);
        if (it_C == C.end())
            break;
        C.erase(it_C), res++;
    }

    cout << res;

    return 0;
}