L = int(input())
S = input()

pi = [0 for i in range(L)]
j = 0

for i in range(1, L):
    while j > 0 and S[i] != S[j]:
        j = pi[j - 1]
    if S[i] == S[j]:
        j += 1
        pi[i] = j

print(L - pi[-1])
