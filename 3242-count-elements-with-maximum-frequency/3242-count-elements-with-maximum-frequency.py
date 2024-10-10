class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        counts = Counter(nums)
        max_fre = max(counts.values())
        return sum([count for count in counts.values() if count  == max_fre])
        #time O(n)
        #space O(n)