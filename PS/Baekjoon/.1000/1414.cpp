#include <bits/stdc++.h>
#define MAX 100
#define int long long

using namespace std;
typedef array<int, 3> tp;

int parent[MAX];
vector<tp> lnk;

int find(int K) {
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

void uni(int A, int B) {
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    parent[B] = A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, sm = 0, K, A, B;
    string S;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            if (S[j - 1] == '0')
                continue;
            if (97 <= S[j - 1] && S[j - 1] <= 122)
                K = S[j - 1] - 96;
            else
                K = S[j - 1] - 38;
            sm += K;
            lnk.push_back({K, i, j});
        }
    }

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    sort(lnk.begin(), lnk.end());
    K = 0;
    for (tp i : lnk) {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            continue;
        uni(A, B);
        sm -= i[0];
        K++;
    }

    if (K == N - 1)
        cout << sm;
    else
        cout << -1;

    return 0;
}