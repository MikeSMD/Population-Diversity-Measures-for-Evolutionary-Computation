
#include "DE_rand_to_best_1.h"



template class DE_rand_to_best_1< std::vector < double > >;

template< typename Vector >
DE_rand_to_best_1< Vector >::DE_rand_to_best_1( double mutation_factor, std::vector< std::pair< double, double > > ranges ) : DE_Mutation< Vector >( mutation_factor, ranges )
{
    //
}


template< typename Vector >
Vector DE_rand_to_best_1< Vector >::Mutate_individual( const std::vector< std::pair < Vector, double > >& population, const std::size_t index )
{
    std::vector< std::size_t > indexes = this->getRandomIndexes( 4, population.size(), index );

    const Vector* best_vector = this->getBestVector( population );

    if ( best_vector == nullptr )
	    throw std::runtime_error ("Mutate_individual: nenalezen nejlepší jedinec");
    for ( size_t i = 0; i < 4; ++i )
    { 
	    if( population[ indexes[ i ] ].first.size() != population[ index ].first.size() )
	    {
		    throw std::runtime_error("Mutate_individual: počet dimenzí jedinců se neshoduje");
	    }	
    }

    if ( population[ index ].first.size() != best_vector->size() )
    {
    	
  	throw std::runtime_error("Mutate_individual: počet dimenzí jedinců se neshoduje");

    }
    Vector mutated_vector( population[ indexes[ 0 ] ].first.size() );

    for ( size_t i = 0; i < population[ indexes[ 0 ] ].first.size(); ++i )
    {
	    mutated_vector[ i ] = population[ indexes[ 0 ] ].first[ i ] + this->mutation_factor * ( (*best_vector)[ i ] - population[ indexes[ 1 ] ].first[ i ] ) + this->mutation_factor * ( population[ indexes[ 2 ] ].first[ i ] - population[ indexes[ 3 ] ].first[ i ] );
    }

    return mutated_vector;
}
