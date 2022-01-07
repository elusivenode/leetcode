package main

import "fmt"

func main() {
	fmt.Print("Enter the length of an array (integer between 1 and 10,000): ")
	userLen := 0
	fmt.Scanln(&userLen)

	var userArray = make([]int, userLen)
	fmt.Println("At each pause, enter a positive integer.")
	for i := 0; i < userLen; i++ {
		fmt.Printf("Enter index %d: ", i)
		fmt.Scanf("%d", &userArray[i])
	}

	maxOnes := findMaxConsecutiveOnes(userArray)
	fmt.Printf("The array entered was: %v.\n", userArray)
	fmt.Printf("The maximum number of consecutive ones in this array is %d.\n", maxOnes)
}

func findMaxConsecutiveOnes(nums []int) int {
	var tempMax, max int

	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			tempMax++
			if max < tempMax {
				max = tempMax
			}
		} else {
			tempMax = 0
		}
	}
	return max
}
