bool chk(vector<pr> arr, pr P) {
    pr X, Y;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        X = arr[i], Y = arr[(i + 1) % arr.size()];
        if (X[1] < Y[1])
            swap(X, Y);

        if (CCW(X, P, Y) == 0 && min(X[0], Y[0]) <= P[0] && P[0] <= max(X[0], Y[0]) && min(X[1], Y[1]) <= P[1] && P[1] <= max(X[1], Y[1]))
            return true;

        if (max(X[0], Y[0]) < P[0] || X[1] <= P[1] || Y[1] > P[1])
            continue;
        if (min(X[0], Y[0]) > P[0] || CCW(X, P, Y) > 0)
            cnt++;
    }

    return cnt & 1;
}