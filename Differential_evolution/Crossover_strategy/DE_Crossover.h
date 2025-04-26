#ifndef DE_CROSSOVER_ABSTRACT_HEADER
#define DE_CROSSOVER_ABSTRACT_HEADER

#include <vector>
#include <unordered_set>
#include "../Random_generator.h"
template< typename Vector >
class DE_Crossover
{
    public:
        DE_Crossover();

        virtual void get_trials( const std::vector< std::pair < Vector, double > >& population, const std::vector< Vector >& mutants, std::vector< std::pair < Vector, double > >& trials );
        virtual Vector get_trial( const Vector& parent, const Vector& mutant ) const = 0;
        
};

#endif

