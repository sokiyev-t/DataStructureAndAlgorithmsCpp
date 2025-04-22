#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
    std::map<std::string, double> m;
    m["apelsin"] = 2;
    m["milk"] = 3;
    m["avokado"] = 4;

    for (const auto &pair : m)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}