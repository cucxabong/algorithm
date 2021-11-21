/*
URL: https://leetcode.com/problems/subsets/
Time Complexity: O(2^n*n)
Space Complexity: O(2^n*n)
*/
package main

func subsets(nums []int) [][]int {
	output := [][]int{{}}

	for _, n := range nums {
		for _, s := range output {
			a := make([]int, len(s)+1)
			copy(a, s)
			a[len(s)] = n
			output = append(output, a)
		}
	}

	return output
}
