#include "Fitness_evaluator.h"

// instanciace
template class Fitness_evaluator< std::vector< int > >;
template class Fitness_evaluator< std::vector< bool > >;

template< typename Chromosome >

Fitness_evaluator< Chromosome >::Fitness_evaluator( std::function< double (Chromosome&) > fitness_evaluator ) : fitness_evaluator( fitness_evaluator )
{
    //
}

template< typename Chromosome >

void Fitness_evaluator< Chromosome >::evaluate_chromosomes( std::vector< std::pair < Chromosome, double > >& vector_to_evaluate ) const
{
    if ( ! this->fitness_evaluator )
	    return;
    
    for ( std::size_t chromosome_index = 0; chromosome_index < vector_to_evaluate.size(); ++chromosome_index )
    {
        vector_to_evaluate [ chromosome_index ].second = this->fitness_evaluator( vector_to_evaluate[ chromosome_index ].first );
    }
}
