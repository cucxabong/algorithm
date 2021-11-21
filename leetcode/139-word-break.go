/*
URL: https://leetcode.com/problems/word-break/
Time Complexity: ?
Space Complexity: ?
*/
package main

import (
	"strings"
)

func wordBreakMemo(s string, wordDict []string, memo map[string]bool) bool {
	// edge case
	if len(s) == 0 {
		return true
	}

	if v, ok := memo[s]; ok {
		return v
	}

	for i := range wordDict {
		if s == wordDict[i] {
			return true
		}

		if strings.HasPrefix(s, wordDict[i]) {
			memo[s] = wordBreakMemo(s[len(wordDict[i]):], wordDict, memo)
			if memo[s] {
				return true
			}
		}
	}

	return false
}

func wordBreak(s string, wordDict []string) bool {
	memo := map[string]bool{}

	return wordBreakMemo(s, wordDict, memo)
}
