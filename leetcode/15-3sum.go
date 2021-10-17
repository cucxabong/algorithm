/*
URL: https://leetcode.com/problems/3sum
Time Complexity: O(n^2 + nlogn) = O(n^2)
Space Complexity: O(1)
*/
package main

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	output := [][]int{}

	for i := 0; i < len(nums)-1; i++ {
		left, right := i+1, len(nums)-1
		target := -nums[i]
		for left < right {
			if nums[left]+nums[right] == target {
				tmp := []int{nums[i], nums[left], nums[right]}
				output = append(output, tmp)

				// Remove dup solution
				for left < len(nums)-1 && nums[left] == nums[left+1] {
					left++
				}
				left++

				for right > 0 && nums[right] == nums[right-1] {
					right--
				}
				right--

			} else if nums[left]+nums[right] < target {
				left++
			} else {
				right--
			}
		}

		// Skip all items are equal to processed item
		for i < len(nums)-1 && nums[i] == nums[i+1] {
			i++
		}
	}

	return output
}
