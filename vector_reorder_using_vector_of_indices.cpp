#include <iostream>
#include <vector>
#include <iterator>

//https://stackoverflow.com/questions/838384/reorder-vector-using-a-vector-of-indices

template< typename order_iterator, typename value_iterator >
void reorder( order_iterator order_begin, order_iterator order_end, value_iterator v )  {   
    typedef typename std::iterator_traits< value_iterator >::value_type value_t;
    typedef typename std::iterator_traits< order_iterator >::value_type index_t;
    typedef typename std::iterator_traits< order_iterator >::difference_type diff_t;

    diff_t remaining = order_end - 1 - order_begin;
    for ( index_t s = index_t(), d; remaining > 0; ++ s ) {
        for ( d = order_begin[s]; d > s; d = order_begin[d] ) ;
        if ( d == s ) {
            -- remaining;
            value_t temp = v[s];
            while ( d = order_begin[d], d != s ) {
                std::swap( temp, v[d] );
                -- remaining;
            }
            v[s] = temp;
        }
    }
};

//destructive, but faster
template< typename order_iterator, typename value_iterator >
void reorder_destructive( order_iterator order_begin, order_iterator order_end, value_iterator v )  {
    typedef typename std::iterator_traits< value_iterator >::value_type value_t;
    typedef typename std::iterator_traits< order_iterator >::value_type index_t;
    typedef typename std::iterator_traits< order_iterator >::difference_type diff_t;

    diff_t remaining = order_end - 1 - order_begin;
    for ( index_t s = index_t(); remaining > 0; ++ s ) {
        index_t d = order_begin[s];
        if ( d == (diff_t) -1 ) continue;
        -- remaining;
        value_t temp = v[s];
        for ( index_t d2; d != s; d = d2 ) {
            std::swap( temp, v[d] );
            std::swap( order_begin[d], d2 = (diff_t) -1 );
            -- remaining;
        }
        v[s] = temp;
    }
};

int main() {
    std::vector<int> vi = {4,5,2,1,0,3};
    std::vector<char> vc = {'a', 'b', 'c', 'd', 'e', 'f'};
	
    reorder(vi.begin(), vi.end(), vc.begin());
    std::cout << "after reorder:" << std::endl;
    std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(vc.begin(), vc.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    vi = {4,5,2,1,0,3};
    vc = {'a', 'b', 'c', 'd', 'e', 'f'};
    reorder_destructive(vi.begin(), vi.end(), vc.begin());
    std::cout << "after reorder_destructive:" << std::endl;
    std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(vc.begin(), vc.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    return 0;
}

/*
after reorder:
4 5 2 1 0 3 
e d c f a b 
after reorder_destructive:
4 5 2 -1 -1 -1 
e d c f a b 
*/
