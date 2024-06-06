from string import ascii_uppercase, ascii_lowercase

J, N = map(int, input().split())
res = 0

for i in range(N):
    S = input()
    val = 0

    for j in ascii_uppercase:
        val += S.count(j) * 4

    for j in ascii_lowercase:
        val += S.count(j) * 2

    for j in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]:
        val += S.count(j) * 2

    val += S.count(" ")

    if val <= J:
        res += 1

print(res)
