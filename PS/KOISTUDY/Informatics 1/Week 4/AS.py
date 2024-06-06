A1, A2, A3, A4, B1, B2, B3, B4 = map(int, input().split())
if A3 < B1 or B3 < A1 or A4 < B2 or B4 < A2:
    print("none")
elif (
    (A1, A2) == (B3, B4)
    or (A3, A2) == (B1, B4)
    or (A3, A4) == (B1, B2)
    or (A1, A4) == (B3, B2)
):
    print("point")
elif (
    (A3 == B1 and A2 < B4 and B2 < A4)
    or (B3 == A1 and A2 < B4 and B2 < A4)
    or (A4 == B2 and A1 < B3 and B1 < A3)
    or (B4 == A2 and A1 < B3 and B1 < A3)
):
    print("line")
else:
    print("rectangle")
