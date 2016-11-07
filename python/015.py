class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        dic = []
        nums.sort()
        length = len(nums)
        for target in range(length):
            tmp = []
            for y in range(target + 1, length):
                x = -nums[target] - nums[y]
                if x in nums[y + 1:]:
                    tmp = (nums[target], nums[y], x)
                if len(tmp) >= 1:
                    result.append(tmp)
        c = [dic.append(list(x)) for x in set(result)]
        return dic