int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

void convex_hull(vector<pr> &arr, vector<pr> &hull) {
    vector<pr> upper, lower;
    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        while (upper.size() >= 2 && CCW(upper[upper.size() - 2], upper[upper.size() - 1], i) >= 0)
            upper.pop_back();
        upper.push_back(i);
    }

    reverse(arr.begin(), arr.end());
    for (pr i : arr) {
        while (lower.size() >= 2 && CCW(lower[lower.size() - 2], lower[lower.size() - 1], i) >= 0)
            lower.pop_back();
        lower.push_back(i);
    }

    hull = upper;
    for (int i = 1; i < lower.size() - 1; i++)
        hull.push_back(lower[i]);
}