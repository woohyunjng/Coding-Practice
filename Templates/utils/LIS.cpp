int LIS(vector<int> arr) {
    vector<int> X, Y;

    for (int i : arr) {
        if (X.empty() || X.back() < i) {
            X.push_back(i);
            Y.push_back(X.size() - 1);
        } else {
            Y.push_back(lower_bound(X.begin(), X.end(), i) - X.begin());
            X[Y.back()] = i;
        }
    }

    return X.size();
}

vector<int> LIS(vector<int> arr) {
    vector<int> X, Y, res;

    for (int i : arr) {
        if (X.empty() || X.back() < i) {
            X.push_back(i);
            Y.push_back(X.size() - 1);
        } else {
            Y.push_back(lower_bound(X.begin(), X.end(), i) - X.begin());
            X[Y.back()] = i;
        }
    }

    int K = X.size() - 1;
    for (int i = Y.size() - 1; i >= 0; i--) {
        if (Y[i] == K) {
            K--;
            res.push_back(arr[i]);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}