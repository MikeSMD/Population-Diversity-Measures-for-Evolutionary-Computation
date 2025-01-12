#include"n_Point_crossover.h"

template < typename Chromosome >
n_Point_crossover< Chromosome >::n_Point_crossover( int crossover_points ) : crossover_points( crossover_points )
{
    //
}

template < typename Chromosome >
Chromosome n_Point_crossover< Chromosome >::run_crossover( std::vector< std::pair< Chromosome, double > >& selected_chromosomes )
{
    std::pair< Chromosome&, Chromosome& > parents = this->choose_parents( selected_chromosomes );

    Chromosome child = Chromosome( parents.first.size() );

    int genes = parents.first.size();
    if ( this->crossover_points > parents.first.size() )
    {
        return child;
    }

    std::unordered_set< int > points = {};
    while( points.size() < this->crossover_points )
    {
        int number = rand() % genes;
        points.insert( number );
    }

    bool first_parent = true;
    for ( int gene = 0; gene < genes; ++gene )
    {
        if ( points.find( gene ) != points.end() )
        {
            first_parent = !first_parent;
        }
        if ( first_parent )
        {
            child[ gene ] = parents.first [ gene ];
        }
        else 
            child[ gene ] = parents.second [ gene ];
    }

    return child;

}
