
#include "DE_curr_to_best_2.h"

template class DE_curr_to_best_2< std::vector < double > >;

template< typename Vector >
DE_curr_to_best_2< Vector >::DE_curr_to_best_2( double mutation_factor, std::vector< std::pair< double, double > > ranges ) : DE_Mutation< Vector >( mutation_factor, ranges )
{
    //
}

template< typename Vector >
Vector DE_curr_to_best_2< Vector >::Mutate_individual( const std::vector< std::pair < Vector, double > >& population, const std::size_t index)
{
    std::vector< std::size_t > indexes = this->getRandomIndexes( 1, population.size(), index );
    const Vector* best_vector = this->getBestVector( population );

    

    
    if ( best_vector == nullptr )
	    throw std::runtime_error ("Mutate_individual: nenalezen nejlepší jedinec");

    if ( best_vector->size() != population[ index ].first.size() || population[ indexes[ 0 ] ].first.size() != population[ index ].first.size() )
	    throw std::runtime_error ("Mutate_individual: počet dimenzí není shodný");



    Vector mutated_vector( population[ indexes[ 0 ] ].first.size() );

    for ( size_t i = 0; i < population[ indexes[ 0 ] ].first.size(); ++i )
    {
        mutated_vector[ i ] = (*best_vector)[ i ] + this->mutation_factor * ( (*best_vector)[ i ] - population[ index ].first[ i ] ) + this->mutation_factor * ( (*best_vector)[ i ] - population[ indexes[ 0 ] ].first[ i ] );
    }
    return mutated_vector;
}
