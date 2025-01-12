#ifndef GA_ROULETTE_HELPER_SELECTION_HEADER
#define GA_ROULETTE_HELPER_SELECTION_HEADER

#include <vector>
#include <iostream>
#include <unordered_set>

#include "GA_Selection.h"

template <typename Chromosome>
class RouletteHelperSelection : public GA_Selection<Chromosome>
{
    protected:
        void random_roulette_selection( const std::vector< double >& roulette, const std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes );
        

    public:
        RouletteHelperSelection ( double selection_percentage );
        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes ) = 0;
        //
};

#endif
