#include <iostream>
#include <algorithm>
#include <ranges>
#include <cmath>
#include <tuple>
using namespace std;



bool is_pentagonal(size_t i)
{
    size_t x = 1+(24*i);
    size_t x_sqr_root = static_cast<size_t>(sqrt(x));
    if( 1+(24*i) != x_sqr_root*x_sqr_root)
        return false;
    if( (1+x_sqr_root) % 6 == 0 )
        return true;
    return false;
}

bool is_hexagonal(size_t i)
{
    size_t x = 1+(8*i);
    size_t x_sqr_root = static_cast<size_t>(sqrt(x));
    if( 1+(8*i) != x_sqr_root*x_sqr_root)
        return false;
    if( (1+x_sqr_root) % 4 == 0 )
        return true;
    return false;
}




int main()
{
    for( const auto& o :  ranges::iota_view(1)
                       |  ranges::views::transform([](size_t i){ return make_tuple(i, (i*(i+1))/2); })
                       |  ranges::views::filter( [](const tuple<size_t,size_t>& t){ return is_pentagonal(get<1>(t))&&is_hexagonal(get<1>(t)); })
                       |  ranges::views::take(3) )
        cout<<"i: "<<get<0>(o)<< "  val: " << get<1>(o) <<endl;

    return 0;
}
