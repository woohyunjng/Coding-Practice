N, K = map(int, input().split())
dct = [i for i in range(10)] + [chr(i + 65) for i in range(26)]
res = ""

while N:
    res = str(dct[N % K]) + res
    N //= K

print(res)
