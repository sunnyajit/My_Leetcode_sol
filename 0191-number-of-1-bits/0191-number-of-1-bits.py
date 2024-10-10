 class Solution: #codd written by sunny
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n != 0:
            res += n % 2
            n //=2
        return res    
        