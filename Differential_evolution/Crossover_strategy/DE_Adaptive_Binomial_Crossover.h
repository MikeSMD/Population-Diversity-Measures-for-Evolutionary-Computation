#ifndef DE_ADAPTIVE_BINOMIAL_CROSSOVER_HEADER
#define DE_ADAPTIVE_BINOMIAL_CROSSOVER_HEADER

#include <vector>
#include <stdlib.h>
#include <time.h>
#include "DE_Binomial_Crossover.h"

template< typename Vector >
class DE_Adaptive_Binomial_Crossover : public DE_Crossover< Vector >
{
	private:
		double crossover_rate;
    public:
        DE_Adaptive_Binomial_Crossover( );
        bool even_call;

        virtual void get_trials( const std::vector< std::pair < Vector, double > >& population, const std::vector< Vector >& mutants, std::vector< std::pair< Vector, double > >& trials );
        void reset_calls();
        virtual Vector get_trial( const Vector& parent, const Vector& mutant ) const;
};

#endif

