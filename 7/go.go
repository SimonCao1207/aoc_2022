package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	// content, err := os.ReadFile("smol.txt")
	content, err := os.ReadFile("input.txt")
	sizes := make(map[int]int)
	if err != nil {
		log.Fatal(err)
	}
	lines := strings.Split(string(content), "\n")
	inputs := []string{}
	for _, line := range lines {
		nl := strings.Replace(line, "$ ", "", 1)
		if nl[0:2] != "ls" && nl[0:3] != "dir" {
			inputs = append(inputs, nl)
		}
	}

	stack := []int{}
	for i := 0; i < len(inputs); i++ {
		command := inputs[i]
		if command[0:2] == "cd" && strings.Contains(command, "..") {
			stack = stack[:len(stack)-1]
		} else if command[0:2] == "cd" {
			stack = append(stack, i)
			sizes[i] = 0
		} else {
			size, _ := strconv.Atoi(strings.Split(string(command), " ")[0])
			for _, s := range stack {
				sizes[s] += size
			}
		}
	}
	ans := 0
	for _, size := range sizes {
		if size <= 100000 {
			ans += size
		}
	}

	fmt.Println("sol: ", ans)
}
