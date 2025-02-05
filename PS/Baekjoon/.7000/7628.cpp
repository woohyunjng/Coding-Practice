#include <bits/stdc++.h>
#define int long long

using namespace std;

int A[3] = {1, 2, 0};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;

    while (true) {
        cin >> N;
        if (N == 0)
            break;

        ans = 0, N--;
        while (N > 0) {
            if (N % 3 == 0)
                ans = ans;
            else if (N % 3 == 1)
                ans = A[ans];
            else
                ans = A[A[ans]];
            N /= 3;
        }

        ans = A[ans];
        if (ans == 0)
            cout << "R\n";
        else if (ans == 1)
            cout << "P\n";
        else
            cout << "S\n";
    }

    return 0;
}