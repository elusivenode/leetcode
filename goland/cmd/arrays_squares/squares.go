package main

import (
	"fmt"
)

func main() {
	fmt.Print("Enter the length of an array (integer between 1 and 10,000): ")
	userLen := 0
	fmt.Scanln(&userLen)

	var userArray = make([]int, userLen)
	fmt.Println("At each pause, enter an integer. Each integer should be larger than the last.")
	for i := 0; i < userLen; i++ {
		fmt.Printf("Enter index %d: ", i)
		fmt.Scanf("%d", &userArray[i])
	}

	sortedSquares := sortedSquares(userArray)
	fmt.Printf("The array entered was: %v.\n", userArray)
	fmt.Printf("The array of squares in ascending order is: %v.\n", sortedSquares)
}

func sortedSquares(nums []int) []int {
	idxStart := 0
	idxEnd := len(nums) - 1
	var sorted = make([]int, len(nums))

	for idx := idxEnd; idx >= 0; idx-- {
		ii := nums[idxStart] * nums[idxStart]
		jj := nums[idxEnd] * nums[idxEnd]
		if ii > jj {
			sorted[idx] = ii
			idxStart++
		} else {
			sorted[idx] = jj
			idxEnd--
		}
	}
	return sorted
}
