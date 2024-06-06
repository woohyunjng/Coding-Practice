N = int(input())
A = list(map(int, input().split()))

odd = True
res_1, res_2 = 0, 0

for i in A:
    if odd and i % 2:
        odd = False
        res_1 += 1
    if not odd and not i % 2:
        odd = True
        res_1 += 1

odd = False
for i in A:
    if odd and i % 2:
        odd = False
        res_2 += 1
    if not odd and not i % 2:
        odd = True
        res_2 += 1

print(max(res_1, res_2))
