#ifndef DE_EXPONENITAL_CROSSOVER_HEADER
#define DE_EXPONENITAL_CROSSOVER_HEADER

#include <vector>
#include <stdlib.h>
#include <time.h>
#include "DE_Crossover.h"

template< typename Vector >
class DE_Exponential_Crossover : public DE_Crossover< Vector >
{
    public:
        DE_Exponential_Crossover( );

        virtual Vector get_trial( const Vector& parent, const Vector& mutant ) const;

};

#endif

