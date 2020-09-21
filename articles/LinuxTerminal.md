If multiple processes are writing to a single pipe, then it is guaranteed that their
data won’t be intermingled if they write no more than PIPE_BUF bytes at a time.


any write greater than PIPE_BUF (limits.h) bytes may be
interleaved with writes by other processes


A pipe is simply a buffer maintained in kernel memory.


Once a pipe is full, further writes to the pipe block until the reader removes
some data from the pipe.

The reason for employing large buffer sizes is effi-
ciency: each time a writer fills the pipe, the kernel must perform a context switch
to allow the reader to be scheduled so that it can empty some data from the pipe.

