# import sys

# l = []
# t = int(input())
# for i in range(t):
#     n = int(input())
#     lst = list(map(int, sys.stdin.readline().split()))
#     ans = 0
#     j = 0
#     # for j in range(n):
#     while j < n:
#         st = j
#         j = n - 1
#         for k in range(st+1, n):
#             if lst[k] != lst[st]:
#                 j = k - 1
#                 break
#             j = k
        
        
#         if j == n:
#             j -= 1

            
        
#         if j == n - 1 and st == 0:
#             ans += 1
#         elif j == n - 1:
#             if lst[st-1] > lst[st]:
#                 ans += 1
#         elif st == 0:
#             if lst[j+1] > lst[j]:
#                 ans += 1
#         else:
#             if lst[st-1] > lst[st] and lst[j+1] > lst[j]:
#                 ans += 1
#         if ans > 1:
#             break
#         j += 1
#     if ans == 1:
#         print("YES")
#     else:
#         print("NO")
for _ in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    flag = False
    ans = "YES"
    for i in range(n - 1):
        if lst[i] < lst[i + 1]:
            flag = True
        elif lst[i+1] < lst[i] and flag:
            ans = "NO"
            break
    print(ans)