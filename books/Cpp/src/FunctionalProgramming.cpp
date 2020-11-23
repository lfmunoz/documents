



auto println = [](const char  *message){ std::cout << message << std::endl;};



auto lambda_echo = [](int i ) { std::cout << i << std::endl; };  
 std::vector<int> col{20,24,37,42,23,45,37};
 for_each(col,lambda_echo);


 auto addOne = [](int i) { return i+1;};
 auto returnCol = map(col,addOne);
 for_each(returnCol,lambda_echo);


// function generator:
int RandomNumber () { return (std::rand()%100); }

string toUpper(string data) {
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::toupper(c); });
    return data;
}
std::generate (myvector.begin(), myvector.end(), RandomNumber);



Move semantics
 https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

 https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/



 https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
 https://stackoverflow.com/questions/5695548/public-friend-swap-member-function
 