/**
 * @file DE_Uniform_initialization.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef DE_UNIFORM_INITIALIZATION_HEADER
#define DE_UNIFORM_INITIALIZATION_HEADER

#include <vector>
#include <set>
#include <unordered_set>
#include "DE_Initialization.h"

template< typename Vector >
/**
 * @class DE_Uniform_initialization
 * @brief třída zajišťující inicializaci populace pomcí uniformní distribuce
 */
class DE_Uniform_initialization : public DE_Initialization < Vector >
{
    public:

	/**
	 * @brief konstruktor třídy DE_Uniform_initialization
	 * @param[in] dimension_count - počet dimenzí 
	 * @param[in] population_size - velikost populace
	 * @param[in] dimension_ranges - rozsahy dimenzí
	 * @throws dle konstruktoru předka
	*/
        DE_Uniform_initialization( std::size_t dimension_count, std::size_t population_size, std::vector< std::pair < double, double > >& dimension_ranges );

        virtual Vector generate_individual( );
};

#endif

