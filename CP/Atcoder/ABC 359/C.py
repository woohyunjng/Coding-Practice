Sx, Sy = map(int, input().split())
Tx, Ty = map(int, input().split())

res = abs(Sy - Ty)
if Sy % 2:
    Sx = (Sx + 1) - (Sx + 1) % 2 - 1
else:
    Sx = Sx - Sx % 2
if Ty % 2:
    Tx = (Tx + 1) - (Tx + 1) % 2 - 1
else:
    Tx = Tx - Tx % 2
res += max(0, abs(Tx - Sx) - res) // 2
print(res)
