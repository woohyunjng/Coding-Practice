N, B = map(int, input().split())
res = ""
while N:
    a = N % B
    if a >= 10:
        a = chr(a + 55)

    res = str(a) + res
    N //= B

print(res)
