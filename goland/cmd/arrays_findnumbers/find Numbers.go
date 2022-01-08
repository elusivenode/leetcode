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

	ctEvens := findNumbers(userArray)
	fmt.Printf("The array entered was: %v.\n", userArray)
	fmt.Printf("There are %d numbers in this array with an even number of digits.\n", ctEvens);

}

func findNumbers(nums []int) int {
	var numDigs int
	ctEvens := 0
	for i := 0; i < len(nums); i++ {
		numDigs = numDigits(nums[i])
		if numDigs%2 == 0 {
			ctEvens++
		}
	}
	return ctEvens
}

func numDigits(num int) int {
	n := num
	count := 0
	for ; n != 0; {
		n /= 10
		count++
	}
	return count
}