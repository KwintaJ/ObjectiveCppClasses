//######################################//
//                                      //
//    Jan Kwinta          26.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 4, zadanie 4               //
//                                      //
//######################################//

#include <iostream>
#include <vector>

template<typename T>
struct sum_traits;

template<>
struct sum_traits<char>
{
    typedef int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};
template<>
struct sum_traits<int>
{
    typedef long int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};
template<>
struct sum_traits<float>
{
    typedef double sum_type;
    static sum_type zero()
    {
        return 0.0;
    }
};
template<>
struct sum_traits<double>
{
    typedef double sum_type;
    static sum_type zero()
    {
        return 0.0;
    }
};

template <typename Iter>
typename sum_traits<typename std::iterator_traits<Iter>::value_type>::sum_type sum(Iter begin, Iter end) 
{
    typedef typename std::iterator_traits<Iter>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;
    sum_type total = sum_traits<value_type>::zero(); 
    for(auto it = begin; it != end; ++it)
    {
        total += *it;
    }
    return total; 
};

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int ints[] = {1, 2, 3, 4, 5};
    std::cout << "Suma int: " << sum(ints, ints + 5) << std::endl;

    char chars[] = {'a', 'b', 'c'};
    std::cout << "Suma char1: " << sum(chars, chars + 3) << std::endl;

    float floats[] = {1.1, 2.2, 3.3};
    std::cout << "Suma float: " << sum(floats, floats + 3) << std::endl;

    double doubles[] = {1.1, 2.2, 3.3};
    std::cout << "Suma double: " << sum(doubles, doubles + 3) << std::endl;

    std::vector<int> v(5, 5);
    std::cout << "Suma int w std::vector: " << sum(v.begin(), v.end()) << std::endl;
}