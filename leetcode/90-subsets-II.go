/*
URL: https://leetcode.com/problems/subsets-ii/
Time Complexity: O(2^n*n)
Space Complexity: O(2^n*n)
*/
package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	output := [][]int{{}}
	var startSubsetIndex int

	for i := range nums {
		currentSubsetsLength := len(output)
		for j := startSubsetIndex; j < currentSubsetsLength; j++ {
			tmp := make([]int, len(output[j])+1)
			copy(tmp, output[j])
			tmp[len(output[j])] = nums[i]
			output = append(output, tmp)
		}
		if i < len(nums)-1 && nums[i] == nums[i+1] {
			startSubsetIndex = currentSubsetsLength
		} else {
			startSubsetIndex = 0
		}
	}

	return output
}
