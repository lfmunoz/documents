package test

import (
	"net/http"
	"testing"
)

func TestDownloadTable(t *testing.T) {

	var urls = []struct {
		url        string
		statusCode int
	}{
		{
			"http://www.google.com/",
			200,
		},
		{
			"http://www.aol.com/",
			200,
		},
	}

	t.Log("Given the need to test downloading content.")
	{
		for _, u := range urls {
			t.Logf("\tWhen checking \"%s\" for status code \"%d\" ", u.url, u.statusCode)
			{
				resp, err := http.Get(u.url)
				if err != nil {
					t.Fatal("\t\t Should be able to make the Get call.", ballotX, err)
				}
				t.Log("\t\tShould be able to make the Get call.", checkMark)
				defer resp.Body.Close()

				if resp.StatusCode == u.statusCode {
					t.Logf("\t\tSHould receive a \"%d\" status. %v", u.statusCode, checkMark)
				} else {
					// Report test failed byt don't stop the execution of the test function
					t.Errorf("\t\tShould receive a \"%d\" status. %v %v",
						u.statusCode, ballotX, resp.StatusCode)
				}
			}
		}
	}
}
