

#include <iterator>
#include <ranges>


namespace std 
{
    template <
        typename T, 
        typename... U
    >
    concept same_as_any_of = (std::same_as<T, U> or ...); // exposition only
}

namespace std::ranges
{
    template<
        input_iterator I1,
        input_iterator I2,
        class Comp,
        class Proj1,
        class Proj2
    >
    using lexicographical_compare_three_way_result_t =
        invoke_result_t<
            Comp, 
            typename projected<I1, Proj1>::value_type, 
            typename projected<I2, Proj2>::value_type
        >; // exposition-only

    template<
            std::input_iterator I1,
            std::input_iterator I2,
            class Comp,
            class Proj1,
            class Proj2
    >
    constexpr bool is_lexicographical_compare_three_way_result_ordering =
            std::same_as_any_of<
                lexicographical_compare_three_way_result_t<
                    I1, I2, Comp, Proj1, Proj2
                >,
                std::strong_ordering, std::weak_ordering, std::partial_ordering>; //exposition-only

    template<
        input_iterator I1, sentinel_for<I1> S1,
        input_iterator I2, sentinel_for<I2> S2,
        class Comp = compare_three_way,
        class Proj1 = identity, 
        class Proj2 = identity
    >
    requires
        is_lexicographical_compare_three_way_result_ordering<
            I1, I2, Comp, Proj1, Proj2
        >
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

    template<
        ranges::input_range R1,
        ranges::input_range R2,
        class Comp = compare_three_way,
        class Proj1 = identity, 
        class Proj2 = identity
    >
    requires
        is_lexicographical_compare_three_way_result_ordering<
            iterator_t<R1>, iterator_t<R2>, Comp, Proj1, Proj2
        > 
    constexpr auto
        lexicographical_compare_three_way( 
            R1&& r1,
            R2&& r2,
            Comp comp = {},
            Proj1 proj1 = {}, 
            Proj2 proj2 = {}
    ) -> common_comparison_category_t<
                decltype(
                    comp(proj1(*ranges::begin(r1)), proj2(*ranges::begin(r2)))
                ), 
                strong_ordering
         >
     {
         return lexicographical_compare_three_way(
                 ranges::begin(r1), ranges::end(r1),
                 ranges::begin(r2), ranges::end(r2),
                 move(comp),
                 move(proj1),
                 move(proj2));
     }
}

