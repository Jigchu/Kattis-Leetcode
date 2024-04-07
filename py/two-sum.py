def two_sum(nums: list[int], target: int):
	nums_og = nums[:]
	nums.sort()
	index1 = 0
	index2 = len(nums) - 1

	while True:
		total = nums[index1] + nums[index2]
		if total == target:
			break
		if total < target:
			index1 += 1
		if total > target:
			index2 -= 1

	index1 = nums_og.index(nums[index1])
	nums_og.reverse()
	index2 = (len(nums)-1) - nums_og.index(nums[index2])

	return index1, index2

print(two_sum([3,3], 6))