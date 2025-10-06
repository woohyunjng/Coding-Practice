bool chk(vector<pr> &hull, pr P) {
    int st = 2, en = (int)hull.size() - 1, md;

    if (hull.size() == 2)
        return !CCW(hull[0], P, hull[1]) && min(hull[0][0], hull[1][0]) <= P[0] && P[0] <= max(hull[0][0], hull[1][0]) && min(hull[0][1], hull[1][1]) <= P[1] && P[1] <= max(hull[0][1], hull[1][1]);

    while (st < en) {
        md = st + en >> 1;
        if (CCW(hull[0], hull[md], P) < 0)
            en = md;
        else
            st = md + 1;
    }

    return CCW(hull[0], hull[st - 1], P) >= 0 && CCW(hull[st - 1], hull[st], P) >= 0 && CCW(hull[st], hull[0], P) >= 0;
}