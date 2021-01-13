package test

import (
	"net/http"
	"testing"
)

func TestDownload(t *testing.T) {
	url := "http://www.google.com/"
	statusCode := 200
	t.Log("Given the need to test downloading content.")
	{
		t.Logf("\tWhen checking \"%s\" for status code \"%d\" ", url, statusCode)
		{
			resp, err := http.Get(url)
			if err != nil {
				t.Fatal("\t\t Should be able to make the Get call.", ballotX, err)
			}
			t.Log("\t\tShould be able to make the Get call.", checkMark)
			defer resp.Body.Close()

			if resp.StatusCode == statusCode {
				t.Logf("\t\tSHould receive a \"%d\" status. %v", statusCode, checkMark)
			} else {
				// Report test failed byt don't stop the execution of the test function
				t.Errorf("\t\tShould receive a \"%d\" status. %v %v",
					statusCode, ballotX, resp.StatusCode)
			}
		}
	}
}
