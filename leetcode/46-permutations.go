/*
URL: https://leetcode.com/problems/permutations/
Time Complexity: O(n!*n)
Space Complexity: O(n!*n)
*/
package main

func permuteBacktrack(nums []int) [][]int {
	output := [][]int{}
	backtrack(&output, 0, []int{}, nums)
	return output
}

func backtrack(output *[][]int, track int, combination []int, nums []int) {
	tmp := make([]int, len(combination))
	copy(tmp, combination)
	if len(tmp) == len(nums) {
		*output = append(*output, tmp)
		return
	}

	for k := range nums {
		if track&(1<<k) == 0 {
			backtrack(output, track|(1<<k), append(tmp, nums[k]), nums)
		}
	}
}

func permute(nums []int) [][]int {
	output := [][]int{{}}

	for _, n := range nums {
		tmpOutput := [][]int{}
		for i := range output {
			for j := 0; j <= len(output[i]); j++ {
				tmp := []int{}
				tmp = append(tmp, output[i][:j]...)
				tmp = append(tmp, n)
				tmp = append(tmp, output[i][j:]...)
				tmpOutput = append(tmpOutput, tmp)
			}
		}
		output = tmpOutput
	}

	return output
}
