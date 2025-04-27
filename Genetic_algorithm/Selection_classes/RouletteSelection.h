/**
 * @file RouletteSelection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_ROULETTE_SELECTION_HEADER
#define GA_ROULETTE_SELECTION_HEADER

#include "RouletteHelperSelection.h"

template <typename Chromosome>

/**
 * @class RouletteSelection
 * @brief Třída zajišťující ruletkovou selekci jedinců z populacec
 */
class RouletteSelection : public RouletteHelperSelection< Chromosome >
{
    public:
	/**
	 * @brief Konstruktor třídy RouletteSelection
	*/
        RouletteSelection ( );

        virtual void run_selection(std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const;
};

#endif
