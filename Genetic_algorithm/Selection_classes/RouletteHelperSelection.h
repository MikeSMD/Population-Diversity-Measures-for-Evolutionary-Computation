/**
 * @file RouletteHelperSelection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_ROULETTE_HELPER_SELECTION_HEADER
#define GA_ROULETTE_HELPER_SELECTION_HEADER

#include "../Random_generator.h"
#include <unordered_set>
#include "GA_Selection.h"

template <typename Chromosome>

/**
 * @class RouletteHelperSelection
 * @brief Třída zajišťující selekci dle proporcionálního náhodného výběru
*/

 class RouletteHelperSelection : public GA_Selection<Chromosome>
{
    protected:

	/**
	 * @brief metoda zajišťující náhodný proporcionální výběr jedinců z populace dle nastavených hodnot
	 * @param[in] roulette Vstupní parametr s rozdělenými hodnotami pro každý index 
	 * @param[in] population Vstupní parametr s populací chromozomů k selekci
	 * @param[out] selected_chromosomes Výstupní parametr, kde se uloží vybraní jedinci
	 * @param[in] selection_count počet jedinců, kolik se má vybrat
	*/
        void random_roulette_selection( const std::vector< double >& roulette, const std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const;
  
    public:
	/**
	 * @brief Konstruktor třídy RouletteHelperSelection
	*/
        RouletteHelperSelection ( );

        virtual void run_selection(std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const = 0;
};

#endif
