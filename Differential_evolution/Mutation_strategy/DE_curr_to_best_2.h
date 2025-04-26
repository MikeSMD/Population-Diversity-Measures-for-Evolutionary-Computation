/**
 * @file DE_curr_to_best_2.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef DE_CURR_TO_BEST_MUTATION_HEADER
#define DE_CURR_TO_BEST_MUTATION_HEADER

#include "DE_Mutation.h"

#include <unordered_set>

template < typename Vector >

/**
 * @class DE_curr_to_best_2
 * @brief třída pro aplikaci mutační strategie
 */
class DE_curr_to_best_2 : public DE_Mutation< Vector >
{
    public:

	/**
	 * @brief konstruktor třídy DE_curr_to_best_2
	 * @param[in] mutation_factor - mutační faktor
	 * @param[in] ranges - rozsahy dimenzí
	*/
        DE_curr_to_best_2( double mutation_factor, std::vector< std::pair< double, double > > ranges );

 	/**
	 * @brief funkce pro generaci mutanta z konkrétního jedince
	 * @param[in] population - populace
	 * @param[in] index - index jedince v populaci, ke kterému se mutant vytváří
	 * @throws runtime_error pokud nebude nalezen nejlepší jedinec či bude neshoda v počtu dimenzí u jedinců
	*/ 
        virtual Vector Mutate_individual( const std::vector< std::pair < Vector, double > >& population, const std::size_t index);
};

#endif
