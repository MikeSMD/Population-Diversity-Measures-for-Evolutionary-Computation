#ifndef GA_CROSSOVER_HEADER
#define GA_CROSSOVER_HEADER

#include <vector>
#include <iostream>

template <typename Chromosome>
class GA_Crossover
{
    protected:
        std::pair< Chromosome&, Chromosome& > choose_parents( std::vector< std::pair< Chromosome, double > >& selected_chromosomes );
    
    public:
        virtual Chromosome run_crossover( std::vector< std::pair< Chromosome, double > >& selected_chromosomes) = 0;
};

#endif
