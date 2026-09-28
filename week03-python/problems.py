def two_sum_brute(nums, target):
	for i in range(len(nums)):
		for j in range(i + 1, len(nums)):
			if nums[i] + nums[j] == target:
				return [i, j]
	return []

def two_sum(nums, target):
	seen = {}
	for i in range(len(nums)):
		need = target - nums[i]
		if need in seen:
			return [seen[need], i]
		seen[nums[i]] = i
	return []

def contains_duplicate(nums):
	seen = set()
	for x in nums:
		if x in seen:
			return True
		seen.add(x)
	return False

def is_anagram(s, t):
	if len(s) != len(t):
		return False
	counts = {}
	for ch in s:
		counts[ch] = counts.get(ch, 0) + 1
	for ch in t:
		if counts.get(ch, 0) == 0:
			return False
		counts[ch] = counts[ch] - 1
	return True

def majority_element(nums):
	counts = {}
	for x in nums:
		counts[x] = counts.get(x, 0) + 1
		if counts[x] > len(nums) // 2:
			return x

def single_number(nums):
	counts = {}
	for x in nums:
		counts[x] = counts.get(x, 0) + 1
	for x in counts:
		if counts[x] == 1:
			return x 
assert two_sum_brute([2, 7, 11, 15], 9) == [0, 1]
assert two_sum_brute([3, 2, 4], 6) == [1, 2]
assert two_sum_brute([3, 3], 6) == [0, 1]
assert two_sum_brute([1, 2], 10) == []

assert two_sum([2, 7, 11, 15], 9) == [0, 1]
assert two_sum([3, 2, 4], 6) == [1, 2]
assert two_sum([3, 3], 6) == [0, 1]
assert two_sum([1, 2], 10) == []

assert contains_duplicate([1, 2, 3, 1]) is True
assert contains_duplicate([1, 2, 3]) is False
assert contains_duplicate([]) is False

assert is_anagram("listen", "silent") is True
assert is_anagram("rat", "car") is False
assert is_anagram("a", "ab") is False

assert majority_element([3, 2, 3]) == 3
assert majority_element([2, 2, 1, 1, 1, 2, 2]) == 2

assert single_number([2, 2, 1]) == 1
assert single_number([4, 1, 2, 1, 2]) == 4

print("All tests passed")
