/*
URL: https://leetcode.com/problems/next-permutation/
Time Complexity: O(n)
Space Complexity: O(1)
*/
package main

func nextPermutation(nums []int) {
	if len(nums) < 2 {
		return
	}

	targetIdx := len(nums) - 2
	for targetIdx >= 0 && nums[targetIdx] >= nums[targetIdx+1] {
		targetIdx--
	}

	// swap
	if targetIdx >= 0 {
		replaceIdx := len(nums) - 1
		for replaceIdx > targetIdx && nums[replaceIdx] <= nums[targetIdx] {
			replaceIdx--
		}
		nums[targetIdx], nums[replaceIdx] = nums[replaceIdx], nums[targetIdx]
		targetIdx++
	} else {
		targetIdx = 0
	}

	// Re-ordering the rest
	left := targetIdx
	right := len(nums) - 1
	for left < right {
		nums[left], nums[right] = nums[right], nums[left]
		left++
		right--
	}
}
