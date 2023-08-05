from re import fullmatch

S = input()
res = fullmatch(r"(100+1+|01)+", S)
print("SUBMARINE" if res else "NOISE")
