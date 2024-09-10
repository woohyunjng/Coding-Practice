double second_cosine(pr A, pr B, pr C) {
    double a = sqrt(pow(B.first - C.first, 2) + pow(B.second - C.second, 2));
    double b = sqrt(pow(A.first - C.first, 2) + pow(A.second - C.second, 2));
    double c = sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
    return (a * a + c * c - b * b) / (2 * a * c);
}