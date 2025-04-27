#include "GA_Mutation.h"

template< typename Chromosome >
GA_Mutation< Chromosome >::GA_Mutation( std::function< void ( Chromosome&, int ) > mutation, double mutation_propability ) : mutation( mutation ), mutation_propability( mutation_propability )
{
	//
}

template< typename Chromosome >
GA_Mutation< Chromosome >::GA_Mutation( double mutation_propability ) : mutation_propability( mutation_propability )
{
	//
}


template< typename Chromosome >
void GA_Mutation< Chromosome >::mutate_population(  std::vector< std::pair< Chromosome, double > >& population ) const 
{
    Random_generator& random_generator = Random_generator::get_instance();

    for ( std::size_t i = 0; i < population.size(); ++i )
    {
        for ( std::size_t gene = 0; gene < population.at( i ).first.size(); gene++ )
        {
            if ( ( random_generator.generate_double ( 0.0, 1.0 ) ) < this->mutation_propability )
            {
                this->mutation( population.at( i ).first, gene );
                population.at( i ).second = 0.0;
            }
        }
    }
}







//instanciace
template class GA_Mutation<std::vector<bool>>;

template class GA_Mutation<std::vector<int>>;



