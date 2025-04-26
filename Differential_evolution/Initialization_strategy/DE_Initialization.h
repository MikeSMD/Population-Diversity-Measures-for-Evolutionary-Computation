/**
 * @file DE_Initialization.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef DE_INITIALIZATION_ABSTRACT_HEADER
#define DE_INITIALIZATION_ABSTRACT_HEADER

#include <vector>
#include <unordered_set>
#include <stdexcept>
#include "../Random_generator.h"

template< typename Vector >
/**
 * @class DE_Initialization
 * @brief abstraktní třída zajišťující inicializaci populace
 */

class DE_Initialization
{
    protected:

	/**
	 * @brief počet dimenzí
	*/
        std::size_t dimension_count;

	/**
	 * @brief velikost populace
	*/
        std::size_t population_size;
	/**
	 * @brief rozsahy dimenzí
	*/
        std::vector< std::pair < double, double > > dimension_ranges;
    public:
        

	/**
	 * @brief konstruktor třídy DE_Initialization
	 * @param[in] dimension_count - počet dimenzí 
	 * @param[in] population_size - velikost populace
	 * @param[in] dimension_ranges - rozsahy dimenzí
	 * @throws -pokud nesedí nastavený rozsah pro počet dimenzí s počtem dimenzí dimension_count
	*/
	DE_Initialization( std::size_t dimension_count, std::size_t population_size, std::vector< std::pair < double, double > > dimension_ranges );

	/**
	 * @brief virtuální metoda pro inicializaci populace
	 * @param[out] population - vektor populace, bude celý přepsán
	*/

        virtual void initialize_population( std::vector< std::pair < Vector, double > >& population );

	/**
	 * @brief virtuální metoda pro inicializaci jedince
	*/
        virtual Vector generate_individual( ) = 0;
};

#endif

