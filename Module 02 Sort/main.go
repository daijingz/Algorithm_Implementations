package main

import (
	"fmt"
	"math/rand"
	"time"
)

func checkAvailable(arr []int) bool {
	seen := make(map[int]bool)
	for _, val := range arr {
		if val == 0 || seen[val] {
			return false
		}
		seen[val] = true
	}
	return true
}

func clone(original []int) []int {
	newArr := make([]int, len(original))
	copy(newArr, original)
	return newArr
}

func printArray(name string, arr []int) {
	fmt.Printf("%s: ", name)
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
}

// Selection Sort
func SelectionSort(arr []int) []int {
	if !checkAvailable(arr) {
		panic("Invalid input")
	}
	out := []int{}
	working := clone(arr)
	for len(working) > 0 {
		minIdx := 0
		for i := 1; i < len(working); i++ {
			if working[i] < working[minIdx] {
				minIdx = i
			}
		}
		out = append(out, working[minIdx])
		working = append(working[:minIdx], working[minIdx+1:]...)
	}
	return out
}

// Insertion Sort
func InsertionSort(arr []int) []int {
	if !checkAvailable(arr) {
		panic("Invalid input")
	}
	out := clone(arr)
	for i := 1; i < len(out); i++ {
		key := out[i]
		j := i - 1
		for j >= 0 && out[j] > key {
			out[j+1] = out[j]
			j--
		}
		out[j+1] = key
	}
	return out
}

// Merge Sort
func MergeSort(arr []int) []int {
	if !checkAvailable(arr) {
		panic("Invalid input")
	}
	if len(arr) <= 1 {
		return arr
	}
	mid := len(arr) / 2
	left := MergeSort(arr[:mid])
	right := MergeSort(arr[mid:])
	return merge(left, right)
}

func merge(left, right []int) []int {
	result := []int{}
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}
	result = append(result, left[i:]...)
	result = append(result, right[j:]...)
	return result
}

// Shell Sort
func ShellSort(arr []int) []int {
	if !checkAvailable(arr) {
		panic("Invalid input")
	}
	out := clone(arr)
	n := len(out)
	for gap := n / 2; gap > 0; gap /= 2 {
		for i := gap; i < n; i++ {
			temp := out[i]
			j := i
			for j >= gap && out[j-gap] > temp {
				out[j] = out[j-gap]
				j -= gap
			}
			out[j] = temp
		}
	}
	return out
}

// Quick Sort (custom pivot logic)
func QuickSort(arr []int) []int {
	if !checkAvailable(arr) {
		panic("Invalid input")
	}
	min, max := arr[0], arr[0]
	for _, v := range arr {
		if v < min {
			min = v
		}
		if v > max {
			max = v
		}
	}
	rand.Seed(time.Now().UnixNano())
	pivot := arr[rand.Intn(len(arr))]
	for pivot == min || pivot == max {
		pivot = arr[rand.Intn(len(arr))]
	}

	left := []int{}
	right := []int{}
	for _, val := range arr {
		if val < pivot {
			left = append(left, val)
		} else if val > pivot {
			right = append(right, val)
		}
	}

	leftSorted := InsertionSort(left)
	rightSorted := InsertionSort(right)

	result := append(leftSorted, pivot)
	result = append(result, rightSorted...)
	return result
}

func main() {
	original := []int{4, 9, 1, 5, 2}

	printArray("InsertionSort", InsertionSort(clone(original)))
	printArray("MergeSort", MergeSort(clone(original)))
	printArray("ShellSort", ShellSort(clone(original)))
	printArray("QuickSort", QuickSort(clone(original)))
	printArray("SelectionSort", SelectionSort(clone(original)))
}
