/**
 * @file Rank_based_selection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_RANK_BASED_SELECTION_HEADER
#define GA_RANK_BASED_SELECTION_HEADER

#include <algorithm>
#include "RouletteHelperSelection.h"

template <typename Chromosome>

/**
 * @class Ranked_based_selection
 * @brief Třída zajišťující ruletkovou selekci jedinců dle jejich pořadí
 * */

class Rank_based_selection : public RouletteHelperSelection< Chromosome >
{
    public:
 	/**
	 * @brief Konstruktor třídy Chromosome_generator
	*/
        Rank_based_selection ( );

        virtual void run_selection(std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const ;
};

#endif
