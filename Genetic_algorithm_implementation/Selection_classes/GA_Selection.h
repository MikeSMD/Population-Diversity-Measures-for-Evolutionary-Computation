#ifndef GA_SELECTION_HEADER
#define GA_SELECTION_HEADER

#include <vector>
#include <iostream>
#include <unordered_set>

template <typename Chromosome>
class GA_Selection
{
    protected:
        double selection_percentage;

    public:
        GA_Selection( double selection_percentage );
        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& selected_chromosomes );
};

#endif
