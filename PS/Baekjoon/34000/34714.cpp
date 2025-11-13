#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int H[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> arr, st;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> H[i];

    for (int i = 1; i <= N; i++) {
        if (i > 1) {
            while (!st.empty() && -st.back() < H[i - 1])
                C[-st.back()]--, st.pop_back();
            st.push_back(-H[i - 1]), C[H[i - 1]]++;
        }
        if (H[i] != 0)
            continue;

        H[i] = 1, arr.clear();
        for (int j = i + 1; j <= N; j++) {
            if (H[j] == 0)
                break;
            if (!arr.empty() && arr.back() >= H[j])
                continue;
            if (C[H[j]])
                H[i] = max(H[i], H[j] + 1);
            arr.push_back(H[j]), C[H[j]]++;
        }

        while (C[H[i]])
            H[i]++;

        for (int j : arr)
            C[j]--;
    }

    cout << *max_element(H + 1, H + N + 1) << '\n';

    return 0;
}