/*
URL: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Time Complexity: O(n)
Space Complexity: O(1)
*/

package main

func searchII(nums []int, target int) bool {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return true
		}

		if nums[left] < nums[mid] {
			if target < nums[mid] && target >= nums[left] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else if nums[left] == nums[mid] {
			left++
		} else {
			if target > nums[mid] && target <= nums[right] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}

	return false
}
