#include "DE_Crossover.h"

template class DE_Crossover< std::vector< double > >;

template< typename Vector >
DE_Crossover< Vector >::DE_Crossover( )
{
	//
}

template< typename Vector >
void DE_Crossover< Vector >::get_trials( const std::vector< std::pair < Vector, double > >& population, const std::vector< Vector >& mutants, std::vector< std::pair< Vector, double > >& trials )
{
    for ( std::size_t individual = 0; individual < population.size(); ++individual )
    {
       trials.emplace_back( std::make_pair( this->get_trial( population[ individual ].first, mutants[ individual ] ), 0.0 ) );
    }

    return;
}
