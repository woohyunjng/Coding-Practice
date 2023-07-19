N = int(input())

for i in range(1, N):
    res = i
    for j in str(i):
        res += int(j)
    
    if res == N:
        print(i)
        exit()

print(0)
