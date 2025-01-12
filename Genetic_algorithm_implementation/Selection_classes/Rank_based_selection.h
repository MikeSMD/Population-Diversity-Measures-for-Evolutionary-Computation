#ifndef GA_RANK_BASED_SELECTION_HEADER
#define GA_RANK_BASED_SELECTION_HEADER

#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "GA_Selection.h"
#include "RouletteHelperSelection.h"

template <typename Chromosome>
class Rank_based_selection : public RouletteHelperSelection< Chromosome >
{
    public:
        Rank_based_selection ( double selection_percentage );
        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes );
};

#endif
