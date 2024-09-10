double distance_line_point(pr A, pr B, pr C) {
    double a, b, c, s, S;
    a = sqrt(pow(B.first - C.first, 2) + pow(B.second - C.second, 2));
    b = sqrt(pow(A.first - C.first, 2) + pow(A.second - C.second, 2));
    c = sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
    s = (a + b + c) / 2;
    S = sqrt(s * (s - a) * (s - b) * (s - c));
    return 2 * S / c;
}