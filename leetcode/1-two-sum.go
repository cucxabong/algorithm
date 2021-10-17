/*
URL: https://leetcode.com/problems/two-sum/
Time Complexity: O(n)
Space Complexity: O(n)
*/
package main

func twoSum(nums []int, target int) []int {
	track := map[int]int{}
	for i := 0; i < len(nums); i++ {
		if v, ok := track[nums[i]]; ok {
			return []int{i, v}
		}

		track[target-nums[i]] = i
	}

	return []int{}
}
