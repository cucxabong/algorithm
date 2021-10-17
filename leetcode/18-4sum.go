/*
URL: https://leetcode.com/problems/4sum
Time Complexity: O(n^3 + nlogn) = O(n^2)
Space Complexity: O(1)
*/

package main

import (
	"fmt"
	"sort"
)

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	output := [][]int{}
	if len(nums) < 4 {
		return output
	}

	for i := 0; i < len(nums)-3; i++ {
		for j := i + 1; j < len(nums)-2; j++ {
			newTarget := target - nums[i] - nums[j]
			left, right := j+1, len(nums)-1

			for left < right {
				leftValue, rightValue := nums[left], nums[right]
				sum := nums[left] + nums[right]
				if sum == newTarget {
					tmp := []int{
						nums[i],
						nums[j],
						nums[left],
						nums[right],
					}
					output = append(output, tmp)
					fmt.Println("i: ", i, "j: ", j)
				}

				if sum >= newTarget {
					for right >= left && nums[right] == rightValue {
						right--
					}
				}

				if sum <= newTarget {
					for left <= right && nums[left] == leftValue {
						left++
					}
				}

			}

			// Remove duplicate solution for j
			for j < len(nums)-1 && nums[j] == nums[j+1] {
				j++
			}
		}

		// Remove duplicate solution for i
		for i < len(nums)-1 && nums[i] == nums[i+1] {
			i++
		}
	}

	return output
}
