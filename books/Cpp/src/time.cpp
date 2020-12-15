// ________________________________________________________________________________
//  INCLUDE
// ________________________________________________________________________________
#include <iostream>
#include <ctime>  /* time_t, struct tm, difftime, time, mktime */


using namespace std;

int main() {
    
    // std::time_t time( std::time_t* arg );
    // Returns the current calendar time encoded as a std::time_t object
    //  also stores it in the object pointed to by arg, unless arg is a null pointer.
    // Number of SECONDS since 00:00 hours, Jan 1, 1970 UTC
    time_t currentTime = time(nullptr);
    cout << "time_t=" <<  currentTime << "\n";

    // std::tm* localtime( const std::time_t *time );
    // Converts given time since epoch as std::time_t value into calendar time, 
    //  expressed in local time.
    tm* localTime = localtime(&currentTime);

    // char* asctime( const std::tm* time_ptr );
    // Converts given calendar time std::tm to a textual representation 
    //  of the following fixed 25-character form: Www Mmm dd hh:mm:ss yyyy\n
    char* time = asctime(localTime);
    cout << time;

    // std::size_t strftime( char* str, std::size_t count, const char* format, const std::tm* time );
    // Converts the date and time information from a given calendar time time to a 
    // null-terminated multibyte character string str according to format string format
    // %F = "%Y-%m-%d" (the ISO 8601 date format)
    // %p = a.m. or p.m. 
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%F", localTime)) {
        std::cout << mbstr << '\n';
    }

    return 0;
}

/*
g++ -std=c++11 time.cpp -o time.elf
./time.elf
time_t=1607796630
Sat Dec 12 12:10:30 2020
2020-12-12

*/
