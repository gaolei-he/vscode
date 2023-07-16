from typing import List
class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        return sum([v*v if len(nums)%(i+1)==0 else 0 for i, v in enumerate(nums)])