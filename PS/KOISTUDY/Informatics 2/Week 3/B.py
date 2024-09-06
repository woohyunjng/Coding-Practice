S = input()
S = list(reversed(S))

S[0], S[1] = "S", "T"
S[-2], S[-1] = "E", "D"

print("".join(S))
