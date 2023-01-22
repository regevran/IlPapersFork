
#include "3way.hpp"
#include "catch2/catch_all.hpp"

TEST_CASE("ranges")
{
    std::vector<int> v1{5, 6, 7, 8};
    std::vector<int> v2{0, 1, 2, 3};

    auto res = 
        std::ranges::lexicographical_compare_three_way(v1, v2);

    CHECK(res == std::strong_ordering::greater);
}

