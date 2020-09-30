package ref;

import java.io.File;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.CharBuffer;
import java.nio.IntBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileChannel.MapMode;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystem;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardWatchEventKinds;
import java.nio.file.WatchKey;
import java.nio.file.WatchService;


// https://app.pluralsight.com/library/courses/files-java-nio-api/table-of-contents

public class NIO {

/*
NIO provides:
    bulk access to raw bytes
    bidirectional channels
    off-heap buffering
    proper support for charsets   
    support for asynchronous operations

Buffer: where data resides
Channel: where the data comes from
Selector for asynchronous operations

A write operation takes a data form a buffer and
writes it to a channel

A read operation reads data from a channel and
writes it into a buffer


Channel is an interface, implemented by

FileChannel accesses to a file
it has a cursor
multiple read and writes
it is thread safe

DatagramChannel access to a socket
supports multicast
supports multiple non-concurrent reads and writes

SocketChannel and ServerSocketChannel


FileChannel, ServerSocketChannel and SocketChannel are
abstract classes, concrete implementations are hidden
directly. You use factory methods instead.

A FileChannel can be mapped to memory array
for direct access. It is built on OS features
for fast access.



Buffer is an abstract class
ByteBuffer only type a channel can write in or read from
CharBuffer

And then extended by concrete implementations which are hidden
Buffers are created with factory methods

A buffer is an in-memory structure. maybe be stored in the off-heap
space of the JVM

A buffer has 3 properties
capacity = the size of the backing array
current position
limit = last position in memory seen by the buffer

A buffer can hold a single mark
it sets the mark to the current position (cursor)
it returns this to chain calls

A buffer supports 4 operations
rewind - clears the mark and sets the current position to 0
reset - sets the current position to the previous set mark
flip - sets the limit to the current position and rewinds the buffer
prevents reading past what has been written into the buffer
clear - clears the buffer


*/


    void writeToFile() {
        // create buffer outside of JVM Heap
        ByteBuffer byteBuffer = ByteBuffer.allocate(1024);
        byteBuffer.putInt(10);
        FileChannel fileChannel = FileChannel.open(
            Paths.get("files/ints.bin"), CREATE, WRITE);
        fileChannel.write(byteBuffer);
        fileChannel.close();
    }
   
    void readFromFile() {
        FileChannel fileChannel = FileChannel.open(
            Paths.get("files/ints.bin"), CREATE, WRITE);
        // create buffer outside of JVM Heap
        ByteBuffer byteBuffer = ByteBuffer.allocate(1024);
        byteBuffer.putInt(10);
        System.out.println("Position = " + byteBuffer.position());
        System.out.println("Limit= " + byteBuffer.limit());
        fileChannel.read(byteBuffer);
        // after we read, the cursor is pointing at the next
        // available byte, we set the limit there and rewind
        // to the beginning so we can access the bytes
        byteBuffer.flip(); 
        IntBuffer intBuffer = byteBuffer.asIntBuffer();
        System.out.println("Position = " + intBuffer.position());
        System.out.println("Limit= " + intBuffer.limit());
        int i = intBuffer.get();
        fileChannel.close();
    } 


/*
    Gather / Scatter pattern is useful when handling
    messages with fixed-length parts
*/
    void gatherOrScatter() {
        ByteBuffer header = ByteBuffer.allocate(1024);
        ByteBuffer body  = ByteBuffer.allocate(4096);
        ByteBuffer footer = ByteBuffer.allocate(128);
        ByteBuffer[] message = {header, body, footer};
        long bytesRead = channel.read(message);
        long bytesWritten = channel.write(message);
    }

/*
    MappedByteBuffer is a buffer that maps a file to memory

    Useful for applications that read the same file many times
    READ_ONLY, READ_WRITE, PRIVATE
    PRIVATE means modifications are local to channel it won't be written to disk

*/

    void fileMemoryMapping() {
        File file = new File("/tmp/example.dat");
        FileChannel channel = new RandomAccessFile(file, "r").getChannel();
        ByteBuffer buf = channel.map(
            MapMode.READ_ONLY, 0L, file.length());
        // Java manages data in Big-Endian form by default
        buf.order(ByteOrder.LITTLE_ENDIAN);
    }

/*
    To convert ByteBuffer <-> CharBuffer we need to specify charset

        UTF_8, UTF_16LE, UTF_16BE, UTF_16, US_ASCII, ISO_8859_1

        encode() - takes a CharBuffer returns a ByteBuffer
        decode() - takes a ByteBuffer and returns a CharBuffer

*/
    String bufToString(ByteBuffer buf) {
        CharBuffer utf8Buffer = StandardCharsets.UTF_8.decode(buf);
        return new String(utf8Buffer.array());
    }

/*

 NIO2 - Added for performance
  plugged into the native file system

  A file system in Java NIO2 is an abstraction of a real file system
    The JDK provides two file system the default one and
    a JAR file system

    FileSystemProvider  acts as a factory for file systems

    FileSystem is an abstraction of a file system


    WatchService pattern 
    create a watch service
    register the watch service to a directory
    get the returned key 
    poll the events


*/

    void watchDir() {
        Path dir = Paths.get("/git/myProject");
        FileSystem fileSystem = dir.getFileSystem();
        WatchService watchService = fileSystem.newWatchService();
        WatchKey key = dir.register(watchService, 
            StandardWatchEventKinds.ENTRY_CREATE,
            StandardWatchEventKinds.ENTRY_DELETE,
            StandardWatchEventKinds.ENTRY_MODIFY
        );
        while(key.isValid()) {
            WatchKey take = watchService.take();
            take.reset();
        }
        
    }



}