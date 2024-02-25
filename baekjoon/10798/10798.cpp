#include <iostream>
#include <string>
#include <vector>


int main()
{
    std::vector<std::string> allstr;
    std::string str;
    int n = 0;
    for (int i = 0; i < 5; ++i)
    {
        std::getline(std::cin, str);
        allstr.push_back(str);
        n = n > str.length() ? n : str.length();
    }
    std::string answer = "";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; j++)
        {
            if (allstr[j].length() > i && allstr[j][i] != ' ')
            {
                answer += allstr[j][i];
            }
        }
    }
    std::cout << answer;
    return 0;
}