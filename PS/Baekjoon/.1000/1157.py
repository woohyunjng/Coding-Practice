from collections import Counter

S = input()
word_list = Counter(S.upper())

word, mx = "?", -1
for i, j in word_list.items():
    if j > mx:
        word = i
        mx = j
    elif j == mx:
        word = "?"

print(word)
