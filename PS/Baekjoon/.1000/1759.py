from itertools import combinations

L, C = map(int, input().split())
letter = input().split()
vowel, conson = [], []

for i in letter:
    if i in ["a", "e", "i", "o", "u"]:
        vowel.append(i)
    else:
        conson.append(i)

res = []
for i in range(1, len(vowel) + 1):
    j = L - i
    if j < 2 or j > len(conson):
        continue

    A, B = list(combinations(vowel, i)), list(combinations(conson, j))

    arr = []
    for a in A:
        for b in B:
            arr.append("".join(sorted(a + b)))
    res += arr

res = list(sorted(list(set(res))))
for i in res:
    print(i)
