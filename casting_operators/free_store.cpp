#include <iostream>
#include <new>
#include <cstddef>

// use non-template type param for bucket size

struct Bucket
{
    constexpr static size_t pageSize{4096};
    std::byte page[4096];
};

struct Heap
{
    void *allocate(size_t bytes);
    void free(void *page);

    constexpr static size_t n_of_buckets{10};
    Bucket buckets[n_of_buckets];
    bool bucket_used[n_of_buckets];
};

void *Heap::allocate(size_t bytes)
{
    if (bytes > Bucket::pageSize)
        throw std::bad_alloc{};

    for (size_t i{}; i < n_of_buckets; i++)
    {
        if (!bucket_used[i])
        {
            bucket_used[i] = true;
            return buckets[i].page;
        }
    }
    throw std::bad_alloc{};
}

void Heap::free(void *page)
{
    for (size_t i{}; i < n_of_buckets; i++)
    {
        if (buckets[i].page == page)
        {
            bucket_used[i] = false;
            return;
        }
    }
}

Heap heap;

void *operator new(size_t bytes)
{
    return heap.allocate(bytes);
}

int main()
{
    try
    {
        printf("Buckets:    %p\n", heap.buckets);
        auto breakfast = new unsigned int{0xC0FFEE};
        auto dinner = new unsigned int{0xDEADBEEF};
        printf("Breakfast:  %p 0x%x\n", breakfast, *breakfast);
        printf("Dinner:     %p 0x%x\n", dinner, *dinner);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
    }
}