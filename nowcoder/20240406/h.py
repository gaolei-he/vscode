def unique_substrings(s):
    n = len(s)
    suffix_array = sorted(s[i:] for i in range(n))
    count = n
    for i in range(1, n):
        j = 0
        while j < len(suffix_array[i]) and j < len(suffix_array[i-1]) and suffix_array[i][j] == suffix_array[i-1][j]:
            j += 1
        count += len(suffix_array[i]) - j
    return count
for _ in range(int(input())):
    print(unique_substrings(input()))