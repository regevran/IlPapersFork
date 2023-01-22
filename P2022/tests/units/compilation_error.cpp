
#include "3way.hpp"
#include "catch2/catch_all.hpp"


struct BadComp
{
    template<typename T, typename U = T>
    auto operator()(T t, U u) -> bool
    {
        return 5 > 6;
    }
};
    
TEST_CASE("compilation error")
{
    std::vector<int> v1{0, 1, 2, 3};
    std::vector<int> v2{0, 1, 2, 3};

    // open the followinf section to make sure
    // Comp doesn't compile correctly
    /*
    auto res = 
        std::ranges::lexicographical_compare_three_way(
            std::ranges::begin(v1), std::ranges::end(v1),
            std::ranges::begin(v2), std::ranges::end(v2),
            BadComp{}
        );
    */
}
