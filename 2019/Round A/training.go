package main

import (
	"fmt"
	"bufio"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

var p,n, a int64
var aux [1000000]int64
var max int64

func countSort(e int64, slice []int64){
    var count [10]int64
    for i := int64(0); i < n; i++ {
        count[9-(slice[i]/e)%10]++
    }
    for i := 1; i < 10; i++ {
        count[i] += count[i-1]
    }
    
    for i := n - int64(1); i >= 0; i-- {
        aux[count[9-(slice[i] / e) % int64(10)] - 1] = slice[i]
		count[9-(slice[i] / e) % int64(10)]--
    }
    
    for i := int64(0); i < n; i++ { 
        slice[i] = aux[i]
    }
}

func radixSort(slice []int64){
    for i := int64(1); max / i > 0; i*=10{
        countSort(i, slice)
    }
}

func main() {
    defer writer.Flush()
	cont := 1
	var t int
	scanf("%d\n", &t)
	
	for t > 0 {
	    var s, prefix []int64
	    scanf("%d %d\n", &n, &p)
	    max = int64(0)
	    for i := 0; int64(i) < n; i++ {
	        scanf("%d", &a)
	        s = append(s,a)
	        prefix = append(prefix,a)
	        if max < a {
		    max = a
		}
	    }
	    scanf("\n")
	    prefix = append(prefix,int64(0))
		
		radixSort(s)
		prefix[n - int64(1)] = s[n - int64(1)]
	    
	    for i := n - int64(2); i >= 0; i-- {
	        prefix[i] = prefix[i + int64(1)] + s[i]
	    }
	    min := int64(999999999999)
	    for i := int64(0); i <= n - p; i++ {
			aux := p * s[i] - (prefix[i] - prefix[i+p])
			if aux < min {
				min = aux
			}
	    }
	    t--
	    printf("Case #%d: %d\n", cont, min);
	    cont++
	}	
}
