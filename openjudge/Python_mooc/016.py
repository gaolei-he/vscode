n = int(input())
if n < 0:
    print("Illegal year")
elif n > 1949 and (n - 1949) % 10 == 0:
    print("Lucky year")
elif n > 1921 and (n - 1921) % 10 == 0:
    print("Good year")
elif n % 400 == 0 or n % 100 != 0 and n % 4 == 0:
    print("Leap year")
else:
    print("Common year")