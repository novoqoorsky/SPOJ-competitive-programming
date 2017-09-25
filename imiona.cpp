/*  http://pl.spoj.com/problems/NAMES/
    Dominik Nowogorski
    25-09-2017
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    std::map<std::string, int> names;
    std::vector<std::pair<std::string, int>> namesVector;
    std::string unused1, unused2, name;
    while (std::cin >> unused1 >> unused2 >> name) {
        for (std::string::size_type i = 0; i < name.length(); i++) {
            name[i] = std::toupper(name[i]);
        }
        if (names.find(name) == names.end()) {
            names.insert(std::pair<std::string, int>(name, 1));
        } else {
            names[name]++;
        }
    }
    for (auto const& x: names) {
        namesVector.push_back(std::pair<std::string, int>(x.first, x.second));
    }
    std::sort(namesVector.begin(), namesVector.end(),
         []( const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2 )
         {
             return ( p1.second > p2.second ||
                    ( !( p2.second > p1.second ) && p1.first < p2.first ) );
         } );
    for (auto const& x: namesVector) {
        std::cout << x.first << " " << x.second << std::endl;
    }

    return 0;
}
