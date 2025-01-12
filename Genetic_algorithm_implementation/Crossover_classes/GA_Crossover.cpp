#include "GA_Crossover.h"

template< typename Chromosome >
std::pair< Chromosome&, Chromosome& > GA_Crossover< Chromosome >::choose_parents( std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
    int second_number = rand() % selected_chromosomes.size();
    int first_number = second_number;
    while( first_number == second_number )
    {
        first_number = rand() % selected_chromosomes.size();
    }
    return std::pair< Chromosome&, Chromosome& > ( selected_chromosomes[ first_number ], selected_chromosomes[ second_number ] );
}

