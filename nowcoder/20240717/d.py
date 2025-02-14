# generated by chatgpt
def count_ones(n: int) -> int:
    count = 0
    factor = 1

    while factor <= n:
        lower_numbers = n - (n // factor) * factor
        current_digit = (n // factor) % 2
        higher_numbers = n // (factor * 2)
        
        # Calculate the contribution of current digit place
        if current_digit == 1:
            count += higher_numbers * factor + lower_numbers + 1
        else:
            count += higher_numbers * factor
        count %= mod
        factor *= 2
    
    return count
mod = 998244353
t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    print((count_ones(r) - count_ones(l - 1) + mod) % mod)
