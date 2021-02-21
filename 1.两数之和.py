# 哈希查找时间复杂度O(1),总时间复杂度O(n)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for index, num in enumerate(nums):
            if target-num in hashmap:
                return [hashmap[target - num], index]
            else:
                hashmap[num] = index
        return None
