#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

int N, V[MAX], F[MAX];

int query(int X, int Y) {
    if (Y == N && V[X] != 0)
        return V[X];

    int res;
    cout << "H " << X << ' ' << 1 << ' ' << Y << '\n', cout.flush();
    cin >> res;

    if (Y == N)
        V[X] = res;
    return res;
}

signed main() {
    int K, DX, DY;

    cin >> N, F[0] = F[1] = 1;
    for (int i = 2; F[i - 1] <= N; i++)
        F[i] = F[i - 1] + F[i - 2];

    for (int st = 1, en = N, md1, md2; st < en;) {
        for (K = 0; F[K] < en - st + 1;)
            K++;

        if (en - st == 1)
            K++;
        md1 = st + F[K - 2] - 1, md2 = st + F[K - 1] - 1;

        if (query(md1, N) < query(md2, N))
            st = md1 + 1;
        else
            en = md2 - 1;
        DX = st;
    }

    K = query(DX, N);
    for (int st = 1, en = N, md; st <= en;) {
        md = st + en >> 1;
        if (query(DX, md) == K)
            DY = md, en = md - 1;
        else
            st = md + 1;
    }

    cout << "! " << DX << ' ' << DY << '\n', cout.flush();

    return 0;
}