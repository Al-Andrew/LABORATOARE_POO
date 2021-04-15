#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <regex>
#include <algorithm>
#include <ostream>

std::vector<std::string> split(const std::string str, const std::string delim)
{
    std::regex expr(delim);
    std::vector<std::string> tokens(std::sregex_token_iterator(str.begin(), str.end(), expr, -1),
                                    std::sregex_token_iterator());
    return tokens;
}

int main(int argc, char** argv)
{
    //Get text from file
    std::string text;
    std::ifstream fin("C:/dev/POO_1S2/seminar8/p1/text.txt");
    std::getline(fin, text);

    //Make it all lowercase;
    std::transform(text.begin(), text.end(), text.begin(),
    [](unsigned char c){ return std::tolower(c); });
    
    //Tokenize
    std::vector<std::string> tokens(split(text,"(\\. | |\\? |! )")); 

    //Put them in the map
    std::map<std::string, uint32_t> map;
    for(auto& tok : tokens)
        map[tok]++;

    //Make the queue
    auto cmp = [](std::pair<std::string,uint32_t> a, std::pair<std::string,uint32_t> b){
        if( a.second == b.second )
            return a.first > b.first;
        else
            return a.second < b.second;
    };
    std::priority_queue<std::pair<std::string, uint32_t>,
                         std::vector<std::pair<std::string,uint32_t>>,
                          decltype(cmp)> qu( map.begin(), map.end(), cmp );

    //Print the tokens
    while( !qu.empty() )
    {
        auto cr = qu.top();
        std::cout << cr.first << " => " << cr.second << "\n";
        qu.pop();
    }

    return 0;
}
