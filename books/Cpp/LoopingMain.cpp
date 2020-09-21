

// ________________________________________________________________________________
// Iterating through an array (or other structure) of data is quite a common thing
//  to do in programming. And so far, we’ve covered many different ways to do so: 
//  with loops and an index (for-loops and while loops), with pointers and pointer 
//  arithmetic, and with range-based for-loops:

An iterator is an object designed to traverse through a container, providing 
access to each element along the way.

. Just as templates make algorithm independent of the type of data stored
 iterators make the algorithms independent of the type of container used

Operator *
Returns the element of the current position.
Operator ++
Lets the iterator step forward to the next element. Most iterators also allow backward stepping with operator --.
Operator == and !=
Check whether two iterators represent the same position.
Operator =
Assigns an iterator (the position of the element to which it refers.

All container classes provide the same basic member functions that enable them to use iterators to navigate their elements. 

begin()
This returns iterator that represents the beginning of the elements in the container. 
The beginning is the position of the first element.
end()
This returns an iterator that represents the end of the elements in the container. 
The end is the position after the last element. 
This is also called a past-the-end iterator.

[begin(),end()). A half-open range has two advantages
We have a simple end criterion for loops that iterate over the elements: They simply march through until they meet end().
It avoids special handling for empty ranges. For empty ranges, begin is equal to end().



	// iterator
	vector<int>::iterator it;
	it = v.begin(); //ok
	*it = 911; // ok
	it++; //ok

	// const_iterator
	vector<int>::const_iterator cit;
	cit = v.begin();
	// *cit = 911; // Error: cannot assign to a variable that is const
	cit++; // ok



 input iterator is one that a program can use to read values from a container.

 output indicates that the iterator is used for moving information from a program to a container.



 template<typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last)
{
  cout << "Squares:  ";
  for(;first != last; first++) {
    *first = (*first) * (*first);
    cout << *first << " ";
  }
  cout << endl;
}


 square(v.begin(), v.end());

 template<typename Bidirectional>
bool isPalindrome(Bidirectional first, Bidirectional last)
{
  while(true)
  {
    last--;

    // when a character is a space, skip it
    if(*last == ' ') last--;
    if(*first == ' ') first++;
    if(first == last)
      break;

    // case insensitive comparison
    if(tolower(*first) != tolower(*last))
      return false;

    first++;

    if(first == last)
      break;
  }
  return true;
}



If there is an iterator representing the output stream, we can use it with copy().
 STL provides us such an iterator with the ostream_iterator template. 

#include <iterator>
ostream_iterator<int, char> myOutputIterator(cout, " ");

*myOutputIterator++ = 2013;
It works like:

cout << 2013 << " ";


The first template argument, int, indicates the data type being sent to the output stream. 
The second template argument, char, indicates that the output stream uses character type. 
The cout which is the first constructor argument identifies the output steam being used. 
The character string argument is a separator to be displayed after each item sent to the output stream.

 std::ostream_iterator<int> out_it (std::cout,", ");
  std::copy ( myvector.begin(), myvector.end(), out_it );