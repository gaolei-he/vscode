from typing import List
from itertools import combinations
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans = -1
        for x, y in combinations(nums, 2):
            if x + y > ans and max(str(x)) == max(str(y)):
                ans = x + y
        return ans