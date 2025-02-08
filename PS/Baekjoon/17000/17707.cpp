#include <bits/stdc++.h>
#define int long long

#define MAX 450000
#define SQ_MAX 700

using namespace std;

int A[MAX], T[MAX], B[MAX], C[MAX], S, X;
vector<int> arr[MAX], bucket[SQ_MAX];

void remove(int K, int V) {
    arr[K].erase(lower_bound(arr[K].begin(), arr[K].end(), V));
    bucket[K / X].erase(lower_bound(bucket[K / X].begin(), bucket[K / X].end(), V));
}

void add(int K, int V) {
    arr[K].insert(lower_bound(arr[K].begin(), arr[K].end(), V), V);
    bucket[K / X].insert(lower_bound(bucket[K / X].begin(), bucket[K / X].end(), V), V);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, K, ans;
    vector<int> comp;

    cin >> N >> Q, comp.push_back(0);
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    for (int i = 1; i <= Q; i++) {
        cin >> T[i];
        if (T[i] == 1)
            cin >> B[i];
        else if (T[i] == 2)
            cin >> C[i] >> B[i], comp.push_back(B[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    S = comp.size(), X = (int)sqrt(S);

    for (int i = 0; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
    for (int i = 1; i <= Q; i++)
        B[i] = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin() + 1;

    for (int i = 0; i < N; i++)
        add(A[i], A[i + 1]);

    for (int i = 1; i <= Q; i++) {
        if (T[i] == 1) {
            ans = 0, K = B[i] - 1;
            while ((K + 1) % X)
                ans += arr[K].end() - lower_bound(arr[K].begin(), arr[K].end(), B[i]), K--;
            for (int j = 0; j <= K; j += X)
                ans += bucket[j / X].end() - lower_bound(bucket[j / X].begin(), bucket[j / X].end(), B[i]);
            cout << ans << '\n';
        } else if (T[i] == 2) {
            remove(A[C[i] - 1], A[C[i]]), add(A[C[i] - 1], B[i]);
            if (C[i] < N)
                remove(A[C[i]], A[C[i] + 1]), add(B[i], A[C[i] + 1]);
            A[C[i]] = B[i];
        }
    }
}