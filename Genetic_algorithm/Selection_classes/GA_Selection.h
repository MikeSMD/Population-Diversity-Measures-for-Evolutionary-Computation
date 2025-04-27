/**
 * @file GA_Selection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_SELECTION_HEADER
#define GA_SELECTION_HEADER

#include <vector>
#include <utility>

template <typename Chromosome>
/**
 * @class GA_Selection
 * @brief Třída zajišťující selekci chromozomů z předané populace
 */

class GA_Selection
{
    public:
	/**
	 * @brief konstruktor třídy GA_Selection
	*/
        GA_Selection( );


	/**
	 * @brief metoda zajišťující selekci chromozomů z předané populace
	 * @param[in] population Vstupní parametr s chromozomy s kandidáty na selekci. population vektor nemusí udržet stejné pořadí jako bylo před zavoláním této metody
	 * @param[out] selected_chromosomes Výstupní parametr, kde se uloží vybraní jedinci selekčním operátorem. vektor bude zcela přepsán, jeho původní data budou ztracena
	 * @param[in] selection_count počet jedinců, kolik se má vybrat
	*/
        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const = 0;
	/**
	 * @brief destruktor třídy GA_Selection
	*/

	virtual ~GA_Selection() = default;
};
#endif
