from collections import OrderedDict
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = OrderedDict()
        for x in range(len(nums)):
            if nums[x] not in dic:
                dic[nums[x]] = [x]
            else:
                dic[nums[x]].append(x)
        
        for x in dic:
            y = target - x
            if y in dic and len(dic[x]) == 1 and dic[x][0] != dic[y][0]:
                return dic[x][0], dic[y][0]
            if y in dic and len(dic[x]) == 2:
                return dic[x][0], dic[x][1]
                
        return None
        
        