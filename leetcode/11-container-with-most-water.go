/*
URL: https://leetcode.com/problems/container-with-most-water
Time Complexity: O(n)
Space Complexity: O(1)
*/
package main

func maxArea(height []int) int {
	ret := 0
	i, j := 0, len(height)-1
	for i < j {
		ret = max(ret, min(height[i], height[j])*(j-i))

		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}

	return ret
}
