#include "DE_Fitness_evaluator.h"

template class DE_Fitness_evaluator< std::vector< double > >;

template< typename Individual >
DE_Fitness_evaluator< Individual >::DE_Fitness_evaluator( const std::function< double( const Individual& ) >& fitness_function ) : fitness_evaluator( fitness_function )
{
    //
}


template< typename Individual >
void DE_Fitness_evaluator< Individual > :: evaluate( std::vector< std::pair < Individual, double > >& individuals ) const
{
    for ( int i = 0; i < individuals.size(); ++i )
    {
        individuals[ i ].second = fitness_evaluator( individuals[ i ].first );
    }
}

