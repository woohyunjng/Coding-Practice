N = int(input())
res = 0

for i in range(1, N + 1):
    if i <= 9:
        res += 1
        continue

    d = int(str(i)[1]) - int(str(i)[0])
    check = True

    for j in range(2, len(str(i))):
        if int(str(i)[j]) - int(str(i)[j - 1]) != d:
            check = False
            break
    
    if check:
        res += 1

print(res)
    