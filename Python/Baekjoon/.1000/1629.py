def pw(A, B, C):
    if B == 1:
        return A % C

    if B % 2:
        return (pw(A, B // 2, C) ** 2 * A) % C
    else:
        return pw(A, B // 2, C) ** 2 % C


A, B, C = map(int, input().split())
print(pw(A, B, C))
