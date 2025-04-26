/**
 * @file DE_Rand_2.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef DE_RAND_2_MUTATION_HEADER
#define DE_RAND_2_MUTATION_HEADER

#include "DE_Mutation.h"

#include <unordered_set>

template < typename Vector >

/**
 * @class DE_Rand_2
 * @brief třída pro aplikaci mutační strategie
 */
class DE_rand_2 : public DE_Mutation< Vector >
{
    public:

	/**
	 * @brief konstruktor třídy DE_Rand_2
	 * @param[in] mutation_factor - mutační faktor
	 * @param[in] ranges - rozsahy dimenzí
	*/
        DE_rand_2( double mutation_factor, std::vector< std::pair< double, double > > ranges );
        virtual Vector Mutate_individual( const std::vector< std::pair < Vector, double > >& population, const std::size_t index);
};

#endif
