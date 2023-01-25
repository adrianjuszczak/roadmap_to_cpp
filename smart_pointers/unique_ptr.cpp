#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <utility>

namespace anjk
{
    template <typename T>
    struct unique_ptr
    {
        /**
         *  unique_ptr never allocates any resources that's why is noexcept
         */
        unique_ptr() noexcept : m_pointer{nullptr} {}
        ~unique_ptr() { delete m_pointer; }
        /*
            CTOR is explicit because taking ownership  is important and 
            should be done inntentionaly.
            Compiler can use constructor with one param in order to convert one type to another.
        */
        unique_ptr(T *pointer) 
            : m_pointer{pointer} {}
        /**
         *  @brief Due to fact that move CTOR and move assignment operator is declared
         *  I could have removed copy CTOR and copy assignment operator
         */
        unique_ptr(const unique_ptr &other) = delete;
        unique_ptr &operator=(const unique_ptr &other) = delete;
        unique_ptr(unique_ptr &&other) noexcept
            : m_pointer{std::exchange(other.m_pointer, nullptr)} {}

        unique_ptr &operator=(unique_ptr &&other) noexcept
        {
            /**
             *  @jeżeli z jakiegoś powodu zdefiniowano
             *  unique_ptr<T>::swap(T*, T*)
             *  wystąpi błąd kompilacji - niejednoznaczność
             *
             *
             *  using std::swap used for preventing ambiguity
             *  reason - ADL
             */
            using std::swap;

            std::swap(this->m_pointer, other.m_pointer);
            return *this;
        }
        /**
         *  Replaces the managed object.
         *
         *  1) Given current_ptr, the pointer that was managed by *this, performs the following actions, in this order:
         *  Saves a copy of the current pointer old_ptr = current_ptr
         *  Overwrites the current pointer with the argument current_ptr = ptr
         *  If the old pointer was non-empty, deletes the previously managed object
         *  @example
         *  unique_ptr<Foo> up(new Foo());
         *  std::cout << "Replace owned Foo with a new Foo...\n";
         *  up.reset(new Foo());  // calls deleter for the old one
         *
         */
        void reset(T *pointer)
        {
            T *old_pointer = m_pointer;

            using std::swap;
            swap(this->m_pointer, pointer);

            if (old_pointer != nullptr)
                delete old_pointer;
        }
        
        /**
         *  It is your responsibiliti not to leave
         *  dangling pointer.
        */
        T* release() noexcept {
            T* old_pointer = m_pointer;
            m_pointer = nullptr;

            return old_pointer;
        }

        T *get() const
        {
            return m_pointer;
        }

        T *operator->() const noexcept
        {
            return m_pointer;
        }

        T &operator*() const noexcept
        {
            return *m_pointer;
        }

        bool operator!=(unique_ptr const &) const
        {
            return m_pointer;
        }

        inline operator bool() const
        {
            return (get() != nullptr) ? true : false;
        }

    private:
        T *m_pointer;
    };
}


struct Test
{
    void foo()
    {
        std::cout << "foo() \n";
    }
};

int main(void)
{
    try
    {
        anjk::unique_ptr<Test> ptr(new Test);
        ptr->foo();
        ptr.reset(new Test());
        anjk::unique_ptr<Test> ptr_2(new Test);
        ptr_2 = std::move(ptr);

        if (ptr_2 != nullptr)
            std::cout << "ptr_2 != nullptr \n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}