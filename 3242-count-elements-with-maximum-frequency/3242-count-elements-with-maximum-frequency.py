 class Solution: #code written by sunny
    def maxFrequencyElements(self, nums: List[int]) -> int:
        counts = Counter(nums)
        max_fre = max(counts.values())
        return sum([count for count in counts.values() if count  == max_fre])
         