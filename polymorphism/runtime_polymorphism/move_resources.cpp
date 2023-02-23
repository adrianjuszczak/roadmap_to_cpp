#include <iostream>
#include <utility>
#include <stdexcept>


/**
 *  @brief Write IResources an abstract class, 
 *  Generate an Numbers that implements IResources, 
 *  within Numbers class allocate 2d arrays using RAII.
*/
namespace anjk
{
    struct IResources
    {
        virtual ~IResources() = default;
        virtual void get() = 0;
    };

    struct Numbers : public IResources
    {
        Numbers(size_t rows, size_t columns);           
        ~Numbers();                                     
        Numbers(const Numbers &cp);                     
        Numbers &operator=(const Numbers &cp) = delete; // TODO implement COPY CTOR
        Numbers(Numbers &&mv) noexcept;                 
        Numbers &operator=(Numbers &&mv) noexcept;      

        void get()
        {
            std::cout << "Heap was allocated: " << howManyHeapAllocation << " times. \n";
        }

    private:
        size_t m_rows{};
        size_t m_columns{};
        static size_t howManyHeapAllocation;
        int **ptr;
    };

    size_t Numbers::howManyHeapAllocation = 0;

    Numbers::Numbers(size_t rows, size_t columns)
        : m_rows{rows}, m_columns{columns}
    {
        ptr = new int *[rows];

        for (size_t i = 0; i < rows; i++)
        {
            ptr[i] = new int[columns];
        }

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                ptr[i][j] = ++howManyHeapAllocation;
                std::cout << ptr[i][j] << "\n";
            }
            std::cout << "\n";
        }

        if (howManyHeapAllocation != (m_rows * m_columns))
            throw std::runtime_error{"Number of heap allocation differ."};

        std::cout << "Numbers CTRO finished. \n";
    }

    Numbers::~Numbers()
    {
        for (size_t i = 0; i < m_rows; i++)
        {
            delete[] ptr[i];
        }
        delete[] ptr;
    }

    Numbers::Numbers(const Numbers &cp)
    {
        m_columns = cp.m_columns;
        m_rows = cp.m_rows;

        ptr = new int *[m_rows];

        for (size_t i = 0; i < m_rows; i++)
        {
            ptr[i] = new int[m_columns];
        }

        int cnt{};
        for (size_t j = 0; j < m_rows; j++)
        {
            for (size_t k = 0; k < m_columns; k++)
            {
                ptr[j][k] = cp.ptr[j][k];
                ++cnt;
            }
        }
        if (cnt != howManyHeapAllocation)
            throw std::runtime_error{"Heap corruption during copy CTOR"};
    }

    Numbers &Numbers::operator=(Numbers &&mv) noexcept
    {
        if (this == &mv)
            return *this;

        m_rows = mv.m_rows;
        m_columns = mv.m_columns;
        ptr = mv.ptr;
        mv.m_rows = 0;
        mv.m_columns = 0;
        mv.ptr = nullptr;

        return *this;
    }

    Numbers::Numbers(Numbers &&mv) noexcept
        : m_rows{mv.m_rows}, m_columns{mv.m_columns}, ptr{mv.ptr}
    {
        mv.m_rows = 0;
        mv.m_columns = 0;
        mv.ptr = nullptr;
    }
}

int
main(void)
{
    try
    {
        anjk::Numbers numb1(2, 5);
        anjk::Numbers numb2(std::move(numb1));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}