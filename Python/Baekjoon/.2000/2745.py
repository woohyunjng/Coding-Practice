N, B = input().split()
B = int(B)

res = 0
for i in range(len(N) - 1, -1, -1):
    num = N[i]
    if num.isalpha():
        num = str(ord(num) - 55)
    res += int(num) * B ** (len(N) - 1 - i)

print(res)
