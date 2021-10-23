/*
URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Time Complexity: O(logn)
Space Complexity: O(1)
*/

package main

func searchRange(nums []int, target int) []int {
	output := []int{-1, -1}
	if len(nums) == 0 {
		return output
	}

	output[0] = searchRangeSearch(nums, target, true)
	if output[0] != -1 {
		output[1] = searchRangeSearch(nums, target, false)
	}

	return output
}

func searchRangeSearch(nums []int, target int, first bool) int {
	left, right := 0, len(nums)-1

	for left <= right {
		mid := left + (right-left)/2
		if target == nums[mid] {
			if first && mid > left && nums[mid-1] == target {
				right = mid - 1
			} else if !first && mid < right && target == nums[mid+1] {
				left = mid + 1
			} else {
				return mid
			}
		} else if target < nums[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return -1
}
