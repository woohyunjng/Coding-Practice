#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int N, A[MAX], B[MAX], V[MAX];
set<int> st;

int get(int X) {
    if (X == 0 || X == N + 1)
        return 0;

    set<int>::iterator iter;
    int res = 0, Y, Z;

    iter = st.lower_bound(X);
    Y = *prev(iter), Z = *next(iter);

    res += X * (Z - X) + (N + 1 - X) * (X - Y) + (X - Y) * (X - Z);
    if (Y != 0 && Z != N + 1 && (A[X] - A[Y]) * (A[X] - A[Z]) > 0)
        res += (N + 1 - Z) * Y;
    return V[X] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int ans = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], B[A[i]] = i;
    st.insert(0), st.insert(N + 1);

    set<int>::iterator iter;
    for (int i = 1; i <= N; i++) {
        iter = st.lower_bound(B[i]);
        ans -= V[*prev(iter)], ans -= V[*iter];

        iter = st.insert(B[i]).first;
        ans += get(B[i]);
        ans += get(*prev(iter)), ans += get(*next(iter));

        cout << ans << '\n';
    }
}
