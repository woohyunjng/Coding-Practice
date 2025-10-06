bool is_intersect(pr A, pr B, pr C, pr D) { // A-B C-D 교차판정
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0) {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);
        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

pr get_intersect(pr A, pr B, pr C, pr D) { // A-B C-D 교차점
    double resX, resY;
    resX = (double)((A[0] * B[1] - A[1] * B[0]) * (C[0] - D[0]) - (A[0] - B[0]) * (C[0] * D[1] - C[1] * D[0])) / ((A[0] - B[0]) * (C[1] - D[1]) - (A[1] - B[1]) * (C[0] - D[0]));
    resY = (double)((A[0] * B[1] - A[1] * B[0]) * (C[1] - D[1]) - (A[1] - B[1]) * (C[0] * D[1] - C[1] * D[0])) / ((A[0] - B[0]) * (C[1] - D[1]) - (A[1] - B[1]) * (C[0] - D[0]));
    return {resX, resY};
}