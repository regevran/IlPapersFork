

#include <iterator>

namespace std::ranges
{
    template<
        input_iterator I1, sentinel_for<I1> S1,
        input_iterator I2, sentinel_for<I2> S2,
        class Comp,
        class Proj1,
        class Proj2
    >
    using three_way_comp_result_t =
        invoke_result_t<Comp, std::projected<I1, Proj1>, std::projected<I2, Proj2>>;

    template<
        input_iterator I1, sentinel_for<I1> S1,
        input_iterator I2, sentinel_for<I2> S2,
        class Comp = compare_three_way,
        class Proj1 = identity, 
        class Proj2 = identity
    >
    requires
        //true ||
        std::convertible_to<three_way_comp_result_t<I1,S1,I2,S2,Comp,Proj1,Proj2>, strong_ordering> ||
        std::convertible_to<three_way_comp_result_t<I1,S1,I2,S2,Comp,Proj1,Proj2>, weak_ordering> ||
        std::convertible_to<three_way_comp_result_t<I1,S1,I2,S2,Comp,Proj1,Proj2>, partial_ordering>
    constexpr auto
        lexicographical_compare_three_way( 
            I1 first1, 
            S1 last1, 
            I2 first2, 
            S2 last2, 
            Comp comp = {},
            Proj1 proj1 = {}, 
            Proj2 proj2 = {}
    ) -> common_comparison_category_t<
                decltype(
                    comp(proj1(*first1), proj2(*first2))
                ), 
                strong_ordering
         >
    {
        while (first1 != last1)
        {
            if (first2 == last2)
            {
                return strong_ordering::greater;
            }

            if (auto cmp = comp(proj1(*first1), proj2(*first2)); 
                cmp != 0 ) 
            {
                return cmp;
            }

            ++first1;
            ++first2;
        }

        // GCC 11 implementation with the
        // note: See PR 94006
        return (first2 == last2) <=> true; 
    } 
}
