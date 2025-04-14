#include <bits/stdc++.h>
#define int long long

using namespace std;

int H;

int dnc(int node, int V, int N) {
    if (N == (1 << V))
        return node;
    else if (N < (1 << V))
        return dnc(node << 1, V - 1, N);
    else
        return dnc(node << 1 | 1, V - 1, N - (1 << V));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, N;

    cin >> H >> N;
    cout << dnc(1, H, N) << '\n';

    return 0;
}