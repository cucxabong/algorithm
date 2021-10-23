/*
URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
Time Complexity: O(n)
Space Complexity: O(1)
*/

package main

func removeDuplicates(nums []int) int {
	prev := nums[0]
	endIdx := 1
	count := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] == prev {
			if count < 2 {
				count++
				nums[endIdx] = nums[i]
				endIdx++
			}
		} else {
			prev = nums[i]
			count = 1
			nums[endIdx] = nums[i]
			endIdx++
		}
	}

	return endIdx
}
