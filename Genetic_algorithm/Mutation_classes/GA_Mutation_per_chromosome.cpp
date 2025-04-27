#include "GA_Mutation_per_chromosome.h"

template< typename Chromosome >
GA_Mutation_per_chromosome< Chromosome >::GA_Mutation_per_chromosome( std::function< void ( Chromosome& ) > mutation, double mutation_propability ) : GA_Mutation< Chromosome > ( mutation_propability ), mutation( mutation )
{
	//
}


template< typename Chromosome >
void GA_Mutation_per_chromosome< Chromosome >::mutate_population(  std::vector< std::pair< Chromosome, double > >& population ) const 
{
    Random_generator& random_generator = Random_generator::get_instance();

    for ( std::size_t i = 0; i < population.size(); ++i )
    {
            if ( ( random_generator.generate_double ( 0.0, 1.0 ) ) < this->mutation_propability )
            {
                this->mutation( population.at( i ).first );
                population.at( i ).second = 0.0;
            }
    }
}








//instanciace
template class GA_Mutation_per_chromosome<std::vector<bool>>;

template class GA_Mutation_per_chromosome<std::vector<int>>;



