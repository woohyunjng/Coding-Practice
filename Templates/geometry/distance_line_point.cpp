double distance_line_point(pr A, pr B, pr C) { // A-B와 C 사이 거리
    double AL = dis(B, C), BL = dis(A, C), CL = dis(A, B), SL, S;

    SL = (AL + BL + CL) / 2, S = sqrt(SL * (SL - AL) * (SL - BL) * (SL - CL));
    return 2 * S / CL;
}