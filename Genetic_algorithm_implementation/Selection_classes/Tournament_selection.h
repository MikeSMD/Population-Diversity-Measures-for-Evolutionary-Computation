#ifndef GA_TOURNAMENT_SELECTION_HEADER
#define GA_TOURNAMENT_SELECTION_HEADER

#include <vector>
#include <iostream>
#include <unordered_set>

#include "GA_Selection.h"

template <typename Chromosome>
class Tournament_selection : public GA_Selection<Chromosome>
{
    private:
        int tournament_size;
        int tournament_chooser( const std::vector< std::pair< Chromosome, double > >& population );

    public:
        Tournament_selection( double selection_percentage, int tournament_size );
        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes );
};

#endif
