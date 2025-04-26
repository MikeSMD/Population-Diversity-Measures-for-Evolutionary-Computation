#include "DE_Greedy_selection.h"
template class DE_Greedy_Selection< std::vector< double > >;
template< typename Vector >
DE_Greedy_Selection< Vector >::DE_Greedy_Selection( ) : DE_Selection< Vector >( )
{
    //
}
template< typename Vector >
bool DE_Greedy_Selection< Vector >::change_individual( const std::pair< Vector, double >& target, const std::pair< Vector, double >& trial ) const
{
    return target.second <= trial.second;
}
