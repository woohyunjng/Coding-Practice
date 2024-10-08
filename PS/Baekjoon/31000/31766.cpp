#include <bits/stdc++.h>
#define int long long

#define MAX 1001000

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = 0, sm = 0, st = 0, X;
    string S_A, S_B;

    vector<int> A, B;

    cin >> N >> K;
    cin >> S_A >> S_B;

    for (int i = 0; i < N; i++) {
        if (S_A[i] - '0' == 1) {
            A.push_back(i - st);
            sm++;
        }
        if (S_B[i] - '0' == 1) {
            B.push_back(i - st);
            sm--;
        }

        if (sm == 0) {
            if (!A.empty() && !B.empty()) {
                if (A.front() > B.front())
                    swap(A, B);

                for (int j = 0; j < A.size(); j++) {
                    res += B[j] / K - A[j] / K;
                    A[j] = A[j] % K, B[j] = B[j] % K;
                }

                sort(A.begin(), A.end()), sort(B.begin(), B.end());

                X = 0;
                for (int j = 0; j < A.size(); j++) {
                    if (B[X] <= A[j])
                        X++;
                    else
                        res++;
                }
                A.clear(), B.clear();
            }
            st = i + 1;
        }
    }

    cout << res;

    return 0;
}