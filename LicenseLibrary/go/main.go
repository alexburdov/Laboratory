package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Printf("%s\n", GUID())
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run main.go COMP_GUID")
	} else {
		guid := os.Args[1]
		fmt.Println("COMP_GUID:", guid)
		fmt.Printf("LICENSE KEY:%x\n", getLicenseKeyByMachineGuid(guid))
	}
}
