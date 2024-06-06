N = int(input())
if N in [4, 7]:
    res = -1
else:
    if N % 3 == 0:
        res = 0
    elif N % 3 == 1:
        res = 2
        N -= 10
    else:
        res = 1
        N -= 5
    res += (N // 15) * 3 + (N % 15) // 3

print(res)
