/**
 * @file Uniform_crossover.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_UNIFORM_CROSSOVER_HEADER
#define GA_UNIFORM_CROSSOVER_HEADER

#include "GA_Crossover.h"
#include "../Random_generator.h"

template <typename Chromosome>
/**
 * @class Uniform_crossover
 * @brief Třída zajišťující uniformní křížení
 */
class Uniform_crossover : public GA_Crossover< Chromosome >
{
   private:

	/**
	 * @brief metoda pro zkřížení dvou rodičů za účelem získání konkrétního potomka
	 * @param[in] parentOne první z rodičů
	 * @param[in] parentTwo druhý z rodičů
	 * @param[in] mask maska pro určení jaký gen vzít z jakého rodiče
	 * @return zkřížený chromozom
	 */
	Chromosome perform_crossover( const Chromosome& parentOne, const Chromosome& parentTwo, std::vector< bool > mask ) const ;
			
   public:
	/**
	 * @brief konstruktor třídy Uniform_crossover
 	*/
	Uniform_crossover( double crossover_propability );

        virtual std::vector< Chromosome > cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two );
};

#endif
