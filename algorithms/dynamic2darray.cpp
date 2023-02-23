#include <iostream>

int **array;

int main()
{
    {
        {
            array = new int *[10];

            for (int i = 0; i < 10; i++)
            {
                array[i] = new int[10];
            }

            // fill array
            int cnt{0};
            for (size_t j = 0; j < 10; j++)
            {
                for (size_t k = 0; k < 10; k++)
                {
                    array[j][k] = cnt++;
                }
            }

            // print values
            for (size_t l = 0; l < 10; l++)
            {
                for (size_t m = 0; m < 10; m++)
                {
                    std::cout << array[l][m] << " ";
                }
                std::cout << "\n";
            }
        }

        for (size_t i = 0; i < 10; i++)
        {
            delete[] array[i];
        }
         delete[] array;
    }
}