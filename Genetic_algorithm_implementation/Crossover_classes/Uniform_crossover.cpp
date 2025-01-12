#include"Uniform_crossover.h"

template < typename Chromosome >
Chromosome Uniform_crossover< Chromosome >::run_crossover( std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
    std::pair< Chromosome&, Chromosome& > parents = this->choose_parents( selected_chromosomes );

    Chromosome child = Chromosome( parents.first.size() );
    int genes = parents.first.size();
    for ( int gene = 0; gene < genes; ++gene )
    {
        child[ gene ] = ( rand() % 2 ) ? parents.first[ gene ] : parents.second[ gene ];
    }

    return child;
}
