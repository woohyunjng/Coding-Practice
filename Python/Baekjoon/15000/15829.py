L = int(input())
S = input()
res = 0

for i in range(L):
    res += (ord(S[i]) - 96) * 31 ** i % 1234567891

print(res % 1234567891)
