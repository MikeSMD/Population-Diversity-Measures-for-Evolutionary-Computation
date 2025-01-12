#ifndef GA_P_POINT_CROSSOVER_HEADER
#define GA_P_POINT_CROSSOVER_HEADER

#include <vector>
#include <iostream>
#include <unordered_set>

#include "GA_Crossover.h"

template <typename Chromosome>
class n_Point_crossover : public GA_Crossover< Chromosome >
{
    private:
        int crossover_points;

   public:
        n_Point_crossover( int crossover_points );
        virtual Chromosome run_crossover( std::vector< std::pair< Chromosome, double > >& selected_chromosomes);
};

#endif
