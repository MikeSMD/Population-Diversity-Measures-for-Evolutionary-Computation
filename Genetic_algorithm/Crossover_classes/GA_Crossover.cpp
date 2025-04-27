#include "GA_Crossover.h"
#include "../Random_generator.h"

template< typename Chromosome >
GA_Crossover<Chromosome>::GA_Crossover( double crossover_propability ) : crossover_propability( crossover_propability )
{
	//
}

template< typename Chromosome >
void GA_Crossover< Chromosome >::create_offsprings(const std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& offsprings, std::vector< std::pair< double, double > >& fitness_parents, const std::vector< std::size_t >& selected_indices, const int offspring_count )
{
 
    for ( int i = 0; i < selected_indices.size(); i+=2 )
    {
	    bool single = false;
	    if ( offspring_count % 2 != 0 && i+2 >= selected_indices.size() )
	    {
	    	single = true;
	    }

	
	Random_generator& random_generator = Random_generator::get_instance();

	if ( random_generator.generate_double( 0.0, 1.0 ) <= this->crossover_propability )
    	{
		std::vector< Chromosome > returned_offsprings = this->cross_chromosomes( population [ selected_indices[ i ] ].first, population [ selected_indices[ i + 1 ] ].first, !single );

		for ( Chromosome& offspring : returned_offsprings )
		{
			offsprings.emplace_back( std::move( offspring ), 0.0 );
		}
	}
	else 
	{
		offsprings.emplace_back( std::pair < Chromosome, double > ( population [ selected_indices[ i ] ] ));

		if ( !single )
			offsprings.emplace_back( std::pair < Chromosome, double > ( population [ selected_indices[ i + 1 ] ]));
	}	

	   fitness_parents.emplace_back( std::make_pair( population [ selected_indices[ i ] ].second, population [ selected_indices[ i + 1 ] ].second ) );
	   if ( !single )
	        fitness_parents.emplace_back( std::make_pair( population [ selected_indices[ i ] ].second, population [ selected_indices[ i + 1 ] ].second ) );
    }

}
template class GA_Crossover<std::vector<bool>>;
template class GA_Crossover<std::vector<int>>;
