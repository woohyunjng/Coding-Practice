double triangle_area(pr A, pr B, pr C) { // A-B-C 삼각형 넓이
    return abs(
               A[0] * (B[1] - C[1]) +
               B[0] * (C[1] - A[1]) +
               C[0] * (A[1] - B[1])) /
           2.0;
}