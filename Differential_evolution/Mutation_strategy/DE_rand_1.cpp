
#include "DE_rand_1.h"

template class DE_Rand_1< std::vector < double > >;

template< typename Vector >
DE_Rand_1< Vector >::DE_Rand_1( double mutation_factor, std::vector< std::pair< double, double > > ranges ) : DE_Mutation< Vector >( mutation_factor, ranges )
{
    //
}

template< typename Vector >
Vector DE_Rand_1< Vector >::Mutate_individual( const std::vector< std::pair < Vector, double > >& population, const std::size_t index)
{
    std::vector< std::size_t > indexes = this->getRandomIndexes( 3, population.size(), index );
    





    for ( size_t i = 0; i < 3; ++i )
    { 
    	if( population[ indexes[ i ] ].first.size() != population[ index ].first.size() )
	{
		throw std::runtime_error("Mutate_individual: počet dimenzí jedinců se neshoduje");
	}	
    }

	    Vector mutated_vector( population[ indexes[0]].first.size() );
    for ( size_t i = 0; i < population[ indexes[ 0 ] ].first.size(); ++i )
    {
        mutated_vector[ i ] = population[indexes[0]].first[i] + this->mutation_factor * ( population[ indexes[ 1 ] ].first[ i ] - population[indexes[2]].first[ i ] );
    }

    return mutated_vector;
}
