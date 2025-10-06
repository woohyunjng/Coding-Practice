void convex_hull(vector<pr> &arr, vector<pr> &hull) {
    vector<pr> upper, lower;
    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        while (upper.size() >= 2 && CCW(upper[(int)upper.size() - 2], upper[(int)upper.size() - 1], i) >= 0)
            upper.pop_back();
        upper.push_back(i);
    }

    reverse(arr.begin(), arr.end());
    for (pr i : arr) {
        while (lower.size() >= 2 && CCW(lower[(int)lower.size() - 2], lower[(int)lower.size() - 1], i) >= 0)
            lower.pop_back();
        lower.push_back(i);
    }

    hull = upper;
    for (int i = 1; i < lower.size() - 1; i++)
        hull.push_back(lower[i]);
}