/*
URL: https://leetcode.com/problems/search-in-rotated-sorted-array/
Time Complexity: O(logn)
Space Complexity: O(1)
*/

package main

func search(nums []int, target int) int {
	left, right := 0, len(nums)-1

	for left <= right {
		mid := left + (right-left)/2
		if target == nums[mid] {
			return mid
		}

		// left side sorted
		if nums[left] <= nums[mid] {
			if target < nums[mid] && target >= nums[left] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else {
			if target > nums[mid] && target <= nums[right] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}

	return -1
}
