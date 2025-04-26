#include "DE_Selection.h"
template class DE_Selection< std::vector< double > >;
template< typename Vector >
DE_Selection< Vector >::DE_Selection( )
{
    //
}
template< typename Vector >
void DE_Selection<Vector>::update_population( std::vector< std::pair < Vector, double > >& population, const std::vector< std::pair < Vector, double > >& trials ) const
{
	if ( trials.size() != population.size() )
	{
		throw std::runtime_error ( "update_population: počet jedinců není roven počtu trialům" );
	}
    for ( int individual = 0; individual < population.size(); ++individual )
    {
        if ( change_individual( population.at( individual ), trials.at( individual ) ) )
        {
            population[ individual ] = trials.at( individual );
        }
    }
}
