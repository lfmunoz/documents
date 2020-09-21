
// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout


std::pair <std::string,double> product1;                     // default constructor
std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
std::pair <std::string,double> product3 (product2);          // copy constructor


 product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair 

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

