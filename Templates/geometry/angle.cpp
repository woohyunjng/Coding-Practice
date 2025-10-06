double angle(pr A, pr B, pr C) { // A - B - C 사이 각도 cos
    double AL = dis(B, C), BL = dis(A, C), CL = dis(A, B);
    return (double)(AL * AL + CL * CL - BL * BL) / (2 * AL * CL);
}