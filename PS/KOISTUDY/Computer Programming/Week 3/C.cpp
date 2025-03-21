#include <bits/stdc++.h>
using namespace std;

void hanoi(int N, int T) {
    if (N == 0)
        return;
    if (T == 1) {
        hanoi(N - 1, 1);
        cout << N << " : " << 'A' << "->" << 'B' << '\n';
        hanoi(N - 1, 0);
        cout << N << " : " << 'B' << "->" << 'C' << '\n';
        hanoi(N - 1, 1);
    } else {
        hanoi(N - 1, 0);
        cout << N << " : " << 'C' << "->" << 'B' << '\n';
        hanoi(N - 1, 1);
        cout << N << " : " << 'B' << "->" << 'A' << '\n';
        hanoi(N - 1, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 1;
    cin >> N;

    for (int i = 1; i <= N; i++)
        ans = ans * 3;
    ans--;

    hanoi(N, 1);

    cout << ans << '\n';

    return 0;
}