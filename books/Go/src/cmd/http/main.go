// ________________________________________________________________________________
// http
// ________________________________________________________________________________
package main

import (
	"fmt"
	"net/http"
	"time"
)

// ________________________________________________________________________________
// CONFIG
// ________________________________________________________________________________
const port = ":8090"

// ________________________________________________________________________________
// ENDPOINTS
// ________________________________________________________________________________
func hello(w http.ResponseWriter, req *http.Request) {
	fmt.Fprintf(w, "hello\n")
}

func headers(w http.ResponseWriter, req *http.Request) {
	for name, headers := range req.Header {
		for _, h := range headers {
			fmt.Fprintf(w, "%v: %v\n", name, h)
		}
	}
}

func context(w http.ResponseWriter, req *http.Request) {
	// A context.Context is created for each request by the net/http machinery,
	//  and is available with the Context() method.
	ctx := req.Context()
	fmt.Println("server: hello handler started")
	defer fmt.Println("server: hello handler ended")

	select {
	case <-time.After(5 * time.Second):
		fmt.Fprintf(w, "hello\n")
	case <-ctx.Done():

		err := ctx.Err()
		fmt.Println("server:", err)
		internalError := http.StatusInternalServerError
		http.Error(w, err.Error(), internalError)
	}
}

// ________________________________________________________________________________
// MAIN
// ________________________________________________________________________________
func main() {

	fmt.Println("Listening on port: ", port)
	http.HandleFunc("/api/hello", hello)
	http.HandleFunc("/api/headers", headers)
	http.HandleFunc("/api/context", context)

	// http://localhost:8090/ will server index.html
	http.Handle("/", http.FileServer(http.Dir("./web")))
	//  nil tells it to use the default router
	http.ListenAndServe(port, nil)
}
