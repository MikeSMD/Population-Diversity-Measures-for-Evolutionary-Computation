/**
 * @file DE_LHS_initialization.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef DE_LHS_INITIALIZATION_HEADER
#define DE_LHS_INITIALIZATION_HEADER

#include <vector>
#include <unordered_set>
#include "DE_Initialization.h"

template< typename Vector >

/**
 * @class DE_LHS_Initialization
 * @brief třída zajišťující inicializaci populace pomcí LHS
 */
class DE_LHS_initialization : public DE_Initialization < Vector >
{
    private:
	 /**
	 * @brief atribut pro zachování použitých indexů jednotlivých strat
	*/
        std::vector< std::unordered_set< std::size_t > > generated_strat_indexes;

    public:

	/**
	 * @brief konstruktor třídy DE_LHS_initialization
	 * @param[in] dimension_count - počet dimenzí 
	 * @param[in] population_size - velikost populace
	 * @param[in] dimension_ranges - rozsahy dimenzí
	 * @throws dle konstruktoru předka
	*/
        DE_LHS_initialization( std::size_t dimension_count, std::size_t population_size, std::vector< std::pair < double, double > >& dimension_ranges );

        virtual void initialize_population( std::vector< std::pair < Vector, double > >& population ) override;
     

        virtual Vector generate_individual( ) override;
};

#endif

