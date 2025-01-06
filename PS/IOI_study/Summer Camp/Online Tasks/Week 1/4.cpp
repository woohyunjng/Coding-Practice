#include "maxmin.h"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pr;

int mpm(vector<int> &arr, int A, int B, int C) { return max({arr[A], arr[B], arr[C]}) + min({arr[A], arr[B], arr[C]}); }

vector<int> recover_sequence(int N) {
    vector<int> arr(5), mpm_val, sorted_mpm_val, cnt[5], st;
    vector<pr> index_arr;
    bool check;
    int K, A, B, C;

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            for (int k = j + 1; k < 5; k++)
                mpm_val.push_back(max_plus_min(i, j, k));

    sorted_mpm_val = mpm_val;
    sort(sorted_mpm_val.begin(), sorted_mpm_val.end());

    st = sorted_mpm_val;
    st.erase(unique(st.begin(), st.end()), st.end());

    for (int i : st)
        cnt[upper_bound(sorted_mpm_val.begin(), sorted_mpm_val.end(), i) - lower_bound(sorted_mpm_val.begin(), sorted_mpm_val.end(), i)]
            .push_back(i);

    if (!cnt[4].empty()) {
        cnt[1].push_back(cnt[4][0]);
        cnt[3].push_back(cnt[4][0]);
    }

    for (int i = 1; i <= 3; i++)
        sort(cnt[i].begin(), cnt[i].end());

    arr[0] = (cnt[1][0] + cnt[3][0] - cnt[1][2]) / 2;
    arr[2] = cnt[1][0] - arr[0], arr[4] = cnt[1][2] - arr[2];
    arr[1] = cnt[2][1] - arr[4], arr[3] = cnt[2][0] - arr[0];

    do {
        check = true, K = 0;
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                for (int k = j + 1; k < 5; k++)
                    check = check && mpm(arr, i, j, k) == mpm_val[K++];
        if (check)
            break;
    } while (next_permutation(arr.begin(), arr.end()));

    for (int i = 0; i < 5; i++)
        index_arr.push_back({arr[i], i});
    sort(index_arr.begin(), index_arr.end());

    A = index_arr[0].second, B = index_arr[1].second, C = index_arr[2].second;

    for (int i = 5; i < N; i++) {
        K = max_plus_min(i, B, C);
        if (K != arr[B] + arr[C]) {
            if (K < arr[B] + arr[C])
                arr.push_back(K - arr[C]);
            else
                arr.push_back(K - arr[B]);
        } else {
            K = max_plus_min(i, A, B) - arr[A];
            arr.push_back(K);

            if (K - arr[B] < arr[C] - K)
                A = B, B = i;
            else
                C = i;
        }
    }

    return arr;
}