
// ________________________________________________________________________________
// MAP
// ________________________________________________________________________________
// https ://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/
// http ://cs.brown.edu/courses/cs123/docs/java_to_cpp.shtml
// https : //linuxconfig.org/c-understanding-pointers

// ________________________________________________________________________________
//  INCLUDE
// ________________________________________________________________________________
#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;


// ________________________________________________________________________________
// MAP
// ________________________________________________________________________________

int map()
{

  map<string, int> Map;

  If k matches the key of an element in the container, the function returns a reference to its mapped value.

If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value. 
Notice that this always increases the container size by one, even if no mapped value is assigned to the element (the element is constructed using its default constructor).

default constructor of int i 0

      if (!Map[tmp]) Map[tmp] = 1;
            else Map[tmp]++;


 for (auto &m : Map) { // m為pair structure
            if (m.second > Max) {
                Max = m.second;
                str = m.first;
            }
        }


    // DECLARE
    std::map<std::string, int> mapOfWords;

    // INSERT
    // insert will not replace already added key
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));

    // We can also insert data in std::map using operator []
    // NOTE: Will replace the value of already added key.
     mapOfWords["sun"] = 3;

    //ITERATE
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end()) {
        std::cout<< it->first <<" :: "<< it->second << std::endl;
        it++;
    }

    // Check if insertion is successful or not
    if(mapOfWords.insert(std::make_pair("earth", 1)).second == false) {
        std::cout<<"Element with key 'earth' not inserted because already existed"<<std::endl;
    }

    // Searching element in std::map by key.
    if(mapOfWords.find("sun") != mapOfWords.end()) {
        std::cout<<"word 'sun' found"<<std::endl;
    }


    // Erasing By Key
    mapOfWords.erase("earth");
}

int getIfPresent(std::map<std::string, int> & mapOfWords, string key) {
    auto it = mapOfWords.find(key);
    if(it != mapOfWords.end()) {
        return  it->second;
    }
    return -1; // NOT SURE WHAT TO RETURN, NULL is not a valid value for an integer
}

std::map<std::string, int>::iterator serachByValue(std::map<std::string, int> & mapOfWords, int val)
{
    // Iterate through all elements in std::map and search for the passed element
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        if(it->second == val)
        return it;
        it++;
    }
}


void mapIteratefor() {

    for(auto it = freqTbl.begin(); it != mapOfWords.end(); it++) {
            std::cout<< it->first <<" :: "<< it->second << std::endl;
        }
}

void mapIterateWhile(std::map<char, int> &ourMap) {
    std::map<char, int>::iterator it = ourMap.begin();
    while(it != mapOfWords.end()) {
        std::cout<< it->first <<" :: "<< it->second << std::endl;
        it++;
    }
}



bool mapContainsKey(std::map<int, string>& map, int key)
{
  if (map.find(key) == map.end()) return false;
  return true;
}
