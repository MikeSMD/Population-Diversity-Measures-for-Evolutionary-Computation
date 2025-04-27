/**
 * @file n_Point_crossover.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_P_POINT_CROSSOVER_HEADER
#define GA_P_POINT_CROSSOVER_HEADER

#include <unordered_set>
#include "GA_Crossover.h"
#include "../Random_generator.h"

template <typename Chromosome>
/**
 * @class n_Point_crossover
 * @brief Třída zajišťující n-bodové křížení jedinců
 */
class n_Point_crossover : public GA_Crossover< Chromosome >
{
    private:
	/**
	 * @brief počet bodů křížení
	*/
        int crossover_points;

	/**
	 * @brief metoda pro zkřížení dvou rodičů za účelem získání konkrétního potomka
	 * @param[in] parentOne první z rodičů
	 * @param[in] parentTwo druhý z rodičů
	 * @param[in] mask seznam křížících se bodů
	 * @return zkřížený chromozom
	 */
	Chromosome perform_crossover( const Chromosome& parentOne, const Chromosome& parentTwo, std::unordered_set< int > mask ) const ;

   public:
	/**
	 * @brief konstruktor třídy n_Point_crossover
 	*/

	 n_Point_crossover( double crossover_propability ,int crossover_points );
        virtual std::vector< Chromosome > cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two );
};

#endif
