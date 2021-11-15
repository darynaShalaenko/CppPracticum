// CPP program for REGEX parse c++11
#include <iostream>
#include <regex>
#include <string>
#include <vector>
  
/**
 * @brief Tokenize the given vector 
   according to the regex
 * and remove the empty tokens.
 *
 * @param str
 * @param re
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenize(
                     const std::string str,
                          const std::regex re)
{
    std::sregex_token_iterator it{ str.begin(), 
                             str.end(), re, -1 };
    std::vector<std::string> tokenized{ it, {} };
  
    // Additional check to remove empty strings
    tokenized.erase(
        std::remove_if(tokenized.begin(), 
                            tokenized.end(),
                       [](std::string const& s) {
                           return s.size() == 0;
                       }),
        tokenized.end());
  
    return tokenized;
}
  
// Driver Code
int main()
{
    const std::string str = "Break string            \n      a,spaces,and,commas";
    const std::regex re(R"([\s|,]+)");
    
    // Function Call
    const std::vector<std::string> tokenized = 
                           tokenize(str, re);
    
    for (std::string token : tokenized)
        std::cout << token << std::endl;
    return 0;
}
