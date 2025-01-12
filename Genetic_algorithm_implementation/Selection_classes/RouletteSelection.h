#ifndef GA_ROULETTE_SELECTION_HEADER
#define GA_ROULETTE_SELECTION_HEADER

#include <vector>
#include <iostream>
#include <unordered_set>

#include "GA_Selection.h"
#include "RouletteHelperSelection.h"

template <typename Chromosome>
class RouletteSelection : public RouletteHelperSelection< Chromosome >
{
    public:
        RouletteSelection ( double selection_percentage );
        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes );
};

#endif
