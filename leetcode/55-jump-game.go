/*
URL: https://leetcode.com/problems/jump-game/
Time Complexity: O(n)
Space Complexity: O(1)
*/

package main

func canJump(nums []int) bool {
	farthest := 0
	for i := 0; i <= farthest && i < len(nums); i++ {
		farthest = max(farthest, i+nums[i])
	}

	if farthest >= len(nums)-1 {
		return true
	}

	return false
}
