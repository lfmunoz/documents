---
title: Important Commands
mathjax: true
layout: default
toc: true
---



# Important Commands


## xargs

This command is used when you want to pass a lot of arguments to one command. 

```bash
# read all files to stdout
ls -l | awk '{print $1}' | xargs cat
```


## grep - print lines matching a pattern

```bash
# display all the lines containing the string bash
grep bash /etc/passwd

# If the string includes spaces, enclose it in double quotation marks:
grep "Gnome Display Manager" /etc/passwd

# display the lines that do not match a pattern:
grep -v nologin /etc/passwd

# recursively search for a pattern through all files in the specified directory
grep -r linuxize.com /etc

grep -E "fileName.*tank.*jar" json.txt
```

Note: GNU Grep has three regular expression feature sets, 
* Basic (default)
* Extended 
* Perl-compatible

* -E extended regular expressions
* -o Print each match, but only the match, not the entire line.
* -R  recursive search, follows symbolic links
* -r  recursively search, do not follow symbolic links
* -i  ignore case
* -l show only file name
* -w  search for whole words, (enclosed by non-word characters)
* -n show line number
* -c count matches (alternative: wc -l)
* -A 5  print lines after match
* -B 5  print lines before match
* -C 5  print lines after and before match
* -v Invert the sense of matching
* -H print the file name for each match
* -s Suppress error messages about nonexistent or unreadable files

## find 

```bash
find . -name "*.php" -print | xargs sed -i 's/foo/bar/g'
```


## sed - stream editor for filtering and transforming text 

sed is a stream editor. It works with streams of characters on a per-line basis. It has a primitive programming language that includes goto-style loops and simple conditionals (in addition to pattern matching and address matching).

I would tend to use sed where there are patterns in the text

```bash
sed 's/day/night/' <old >new

sed -n '/tank.*jar/p' json.txt

# don't print first line
sed '1 d' 
```

### References

https://www.grymoire.com/Unix/sed.html



## head - output the first part of files


```
gcc --version | head -n1
```

* -c, –bytes=[-]K
* -n, –lines=[-]K

The leading (optional) '-' means print all but the last K lines (or bytes) of each file


## less

* /characters - search for characters
* n - find next occurance
* q - quit less
* up arrow down arrow - move by one line
* space - go down one page
* b - go up one page






# Archiving and compression 

**tar Archiving** 
* tar -cvf archive_name.tar dirname/
  * -c create a new archive
  * -v verbosity, lists files which are processed 
  * -f following text is the archive name
* tar cvzf archive_name.tar.gz dirname/
  * -z filter the archive through gzip
* tar cvjf archive_name.tar.bz2 dirname/

**tar Extracting**
* tar xvf archive_name.**tar**
  * -x extract files from archive 
* tar xvfz archive_name.tar.**gz**
  * -z  Use the option z for uncompressing a gzip tar archive.
* tar xvfj archive_name.tar.**bz2**
  * -j Use the option j for uncompressing a bzip2 tar archive. 


**tar Listing**
* tar tvf archive_name.tar
  * -t  View the tar archive file content without extracting
* tar tvfz archive_name.tar.gz
* tar tvfj archive_name.tar.bz2


**tar Adding**
* tar rvf archive_name.tar newfile
  * -r  You can add additional files to an existing tar archive
* tar rvf archive_name.tar newdir/
  * -r Adding a directory to the tar is also similar 

**Note:** You cannot add file or directory to a compressed archive.

**Estimate the tar archive size ( in KB )**
  * tar -cf - /directory/to/archive/ \| wc -c
  * tar -czf - /directory/to/archive/ \| wc -c
  * tar -cjf - /directory/to/archive/ \| wc -c

https://www.cyberciti.biz/howto/question/general/compress-file-unix-linux-cheat-sheet.php