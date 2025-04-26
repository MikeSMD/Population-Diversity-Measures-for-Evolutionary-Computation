#ifndef DE_BINOMIAL_CROSSOVER_HEADER
#define DE_BINOMIAL_CROSSOVER_HEADER

#include <vector>
#include "DE_Crossover.h"

template< typename Vector >
class DE_Binomial_Crossover : public DE_Crossover< Vector >
{
    protected:
        double crossover_rate;

    public:
        DE_Binomial_Crossover( double crossover_rate );

        virtual Vector get_trial( const Vector& parent, const Vector& mutant ) const;

};

#endif

