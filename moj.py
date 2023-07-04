class Solution(object):
    def longestAlternatingSubarray(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            if (nums[i] % 2 != 0 or nums[i] > threshold):
                continue
            res = max(res, 1)
            for j in range(i+1, len(nums)):
                if (nums[i] % 2 != nums[j-1] % 2 and nums[j] <= threshold):
                    res = max(res, j-i+1)
                else:
                    i = j
                    break
        return res
