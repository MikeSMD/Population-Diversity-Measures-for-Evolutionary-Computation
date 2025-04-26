/**
 * @file DE_Selection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */
#ifndef DE_SELECTION_ABSTRACT_HEADER
#define DE_SELECTION_ABSTRACT_HEADER

#include <vector>
#include <stdexcept>
#include <unordered_set>

template< typename Vector >
/**
 * @class DE_Selection
 * @brief abstraktní třída pro aplikaci mutační strategie
 */

class DE_Selection
{
    public:

	/**
	 * @brief konstruktor třídy DE_Selection
	*/
        DE_Selection();

	/**
	 * @brief funkce pro selekci jedinců
	 * @param[in] population - populace
	 * @param[in] trials - zkřížení jedinci, jejich index musí korespondovat s jedincem indexu, dle kterého byl vytvořen. 
	 * @throws runtime_error - pokud je počet jedinců v trials rozdílný od population
	*/
        void update_population( std::vector< std::pair < Vector, double > >& population, const std::vector< std::pair < Vector, double > >& trials ) const;

/**
	 * @brief virtuální funkce pro selekci jedince
	 * @param[in] target - cílový vektor
	 * @param[in] trial- zkřížený jedinec
	*/
        virtual bool change_individual( const std::pair< Vector, double >& target, const std::pair< Vector, double >& trial ) const = 0;
};

#endif

