S = list(reversed(input()))
S[0] = "S"
S[1] = "T"
S[-2] = "E"
S[-1] = "D"
print("".join(S))
