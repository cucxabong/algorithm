/*
URL: https://leetcode.com/problems/jump-game-ii/
Time Complexity: O(n)
Space Complexity: O(1)
*/

package main

func jump(nums []int) int {
	jumps := 0
	farthest := 0
	curEnd := 0
	for i := 0; i < len(nums)-1; i++ {
		farthest = max(farthest, nums[i]+i)

		if i == curEnd {
			jumps++
			curEnd = farthest
		}
	}

	return jumps
}
