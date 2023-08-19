#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A[200001], mx = -1, new_mx = -1, res = 0;

    cin >> N;
    for (int i = 0 ; i < N ; i ++) {
        cin >> A[i];
        mx = max(A[i], mx);
    }

    for (int i = N - 1; i >= 0 ; i--) {
        if (A[i] == mx) {
            break;
        }

        if (A[i] > new_mx) {
            new_mx = A[i];
            res ++;
        }
    }

    cout << res;
}
