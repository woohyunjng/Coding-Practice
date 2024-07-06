A, B, C, D, E, F = map(int, input().split())
G, H, I, J, K, L = map(int, input().split())

X1 = (min(A, D), max(A, D))
Y1 = (min(B, E), max(B, E))
Z1 = (min(C, F), max(C, F))

X2 = (min(G, J), max(G, J))
Y2 = (min(H, K), max(H, K))
Z2 = (min(I, L), max(I, L))

res = (
    (X1[1] > X2[0] and X1[0] < X2[1])
    and (Y1[1] > Y2[0] and Y1[0] < Y2[1])
    and (Z1[1] > Z2[0] and Z1[0] < Z2[1])
)
print("Yes" if res else "No")
