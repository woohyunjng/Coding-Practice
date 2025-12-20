#include "floppy.h"

#include <bits/stdc++.h>
using namespace std;

vector<int> arr[40001];

void read_array(int subtask_id, const vector<int> &A) {
    vector<int> st;
    string ans = "";

    int N = (int)A.size();
    for (int i : A) {
        while (!st.empty() && st.back() < i)
            st.pop_back(), ans += '0';
        st.push_back(i), ans += '1';
    }
    save_to_floppy(ans);
}

vector<int> solve_queries(int subtask_id, int N,
                          const string &bits,
                          const vector<int> &QL, const vector<int> &QR) {
    int Q = (int)QL.size(), X = 0;
    vector<int> ans(Q, 0), st;

    for (int i = 0; i < Q; i++)
        arr[QR[i]].push_back(i);

    for (char i : bits) {
        if (i == '0')
            st.pop_back();
        else {
            st.push_back(X++);
            for (int j : arr[X - 1])
                ans[j] = *lower_bound(st.begin(), st.end(), QL[j]);
        }
    }

    return ans;
}