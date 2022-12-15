

#include <algorithm>
#include "catch2/catch_all.hpp"

TEST_CASE("containers")
{
    std::vector<int> v1{0, 1, 2, 3};
    std::vector<int> v2{0, 1, 2, 4};

    auto res = 
        std::lexicographical_compare_three_way(
            std::begin(v1), std::end(v1),
            std::begin(v2), std::end(v2),
            std::compare_three_way{}
        );

    CHECK(res == std::strong_ordering::less);
}


