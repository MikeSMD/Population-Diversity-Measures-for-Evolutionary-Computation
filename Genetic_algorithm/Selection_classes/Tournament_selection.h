/**
 * @file Tournament_selection.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_TOURNAMENT_SELECTION_HEADER
#define GA_TOURNAMENT_SELECTION_HEADER

#include <unordered_set>

#include "GA_Selection.h"
#include "../Random_generator.h"

template <typename Chromosome>
/**
 * @class Tournament_selection
 * @brief Třída zajišťující turnajovou slekci z populace chromozomů
 */
class Tournament_selection : public GA_Selection<Chromosome>
{
    private:
	/**
	 * @brief velikost turnaje
	 * proměnná uchovávající velikost turnaje
	*/
	std::size_t tournament_size;

	/**
	 * @brief metoda zajišťující jeden turnajový výběr
	 * @param[in] population Vstupní parametr předaný referencí obsahující chromozomy k selekci
	 *
 	 * @return - celočíselná hodnota reprezentující index vybraného chromozomu v předané populaci
	*/
        int tournament_chooser( const std::vector< std::pair< Chromosome, double > >& population ) const;

    public:
	/**
	 * @brief Konstruktor třídy Tournament_selection
	*/
        Tournament_selection( std::size_t tournament_size );

        virtual void run_selection( std::vector< std::pair< Chromosome, double > >& population, const std::size_t selection_count, std::vector< std::size_t >& selected_indices ) const ;
};

#endif
