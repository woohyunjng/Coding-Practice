S = input()
dict = {"A": 0, "B": 1, "C": 2, "D": 3, "E": 4, "a": 5, "b": 6, "c": 7, "d": 8, "e": 9}

res = ""
for i in S:
    res += str(dict[i])

print(int(res))
