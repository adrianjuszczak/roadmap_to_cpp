#include <memory>
#include <utility>
#include <iostream>

namespace boost {

template<class T>
inline typename enable_if_<!is_array<T>::value, std::unique_ptr<T> >::type
make_unique()
{
    return std::unique_ptr<T>(new T());
}

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
template<class T, class... Args>
inline typename enable_if_<!is_array<T>::value, std::unique_ptr<T> >::type
make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif

template<class T>
inline typename enable_if_<!is_array<T>::value, std::unique_ptr<T> >::type
make_unique(typename remove_reference<T>::type&& value)
{
    return std::unique_ptr<T>(new T(std::move(value)));
}

template<class T>
inline typename enable_if_<!is_array<T>::value, std::unique_ptr<T> >::type
make_unique_noinit()
{
    return std::unique_ptr<T>(new T);
}

template<class T>
inline typename enable_if_<is_unbounded_array<T>::value,
    std::unique_ptr<T> >::type
make_unique(std::size_t size)
{
    return std::unique_ptr<T>(new typename remove_extent<T>::type[size]());
}

template<class T>
inline typename enable_if_<is_unbounded_array<T>::value,
    std::unique_ptr<T> >::type
make_unique_noinit(std::size_t size)
{
    return std::unique_ptr<T>(new typename remove_extent<T>::type[size]);
}

} /* boost */

#endif