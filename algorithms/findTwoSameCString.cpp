#include <iostream>
#include <stdexcept>

bool findIfTwoSameChar(const char *txt)
{

    if (txt != " ")
    {
        const char *word = txt;

        int length = 0;
        while (word[length])
        {
            length++;
        }

        for (size_t i = 0; i < (length - 1); i++)
        {
            for (size_t j = i; j < (length - 1); j++)
            {
                std::cout << word[i] << " == " << word[j + 1] << std::endl;
                if (word[i] == word[j + 1])
                {
                    return true;
                }
            }
            std::cout << "\n";
        }
        return false;
    }

    throw std::runtime_error{"Given CString is empty. \n"};
}

int main()
{

    try
    {
        if(findIfTwoSameChar("ANJK")) {
            std::cout << "there are same characters. \n";
        } else {
            std::cout << "there are no same characters. \n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}