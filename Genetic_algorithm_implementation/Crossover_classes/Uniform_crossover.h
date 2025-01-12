#ifndef GA_UNIFORM_CROSSOVER_HEADER
#define GA_UNIFORM_CROSSOVER_HEADER

#include <vector>
#include <iostream>

#include "GA_Crossover.h"

template <typename Chromosome>
class Uniform_crossover : public GA_Crossover< Chromosome >
{
   public:
        virtual Chromosome run_crossover( std::vector< std::pair< Chromosome, double > >& selected_chromosomes) = 0;
};

#endif
