package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer  = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func main(){
	var t, l, r, n, q int
	c := 1

	scanf("%d\n", &t)
	for ; t != 0; t-- {
		scanf("%d %d\n", &n, &q)

		arr := make([][]int, 27)
		for i := 0; i < 27; i++ {
			arr[i] = make([]int, n+1)
		}

		var token rune
		set := make(map[rune]bool)

		for i := 1; i <= n; i++ {
			scanf("%c", &token)
			set[token] = true
			for j := 0; j < 27; j++ {
				arr[j][i] += arr[j][i - 1]
			}
			arr[int(token) - int('A')][i]++
		}
		ans := 0

		scanf("\n")
		for ; q != 0; q-- {
			scanf("%d %d\n", &l, &r)
			isOdd := 0
			for i := 0; i < 27; i++ {
				if set[token] == true {
					if ((arr[i][r] - arr[i][l-1]) % 2) != 0 {
						isOdd++
					}
				}
			}

			if isOdd <= 1 {
				ans++
			}
		}
		printf("Case #%d: %d\n", c, ans)
		c++
	}
}
