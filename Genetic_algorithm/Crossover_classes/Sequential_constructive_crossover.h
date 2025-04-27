/**
 * @file Sequential_constructive_crossover.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 29.03.2025
 */

#ifndef GA_SCX_HEADER
#define GA_SCX_HEADER

#include "GA_Crossover.h"
#include "../Random_generator.h"
#include <unordered_set>
#include <functional>
#include <stdexcept>

template <typename Chromosome, typename Gene >
/**
 * @class Uniform_crossover
 * @brief Třída zajišťující uniformní křížení
 */
class Sequential_constructive_crossover : public GA_Crossover< Chromosome >
{
	private:
		const std::vector< std::vector< int > > flowMatrix;
		const std::vector< std::vector< int > > distanceMatrix;
		const std::function< double( Chromosome& ) > fitness; 

		double Calculate( const Chromosome& offspring, Gene adding_facility , size_t adding_location ) const ;
Gene findNext( Gene current, Chromosome parent, std::unordered_set< Gene > used_genes );
		/**
		 * @brief metoda pro zkřížení dvou rodičů za účelem získání konkrétního potomka
		 * @param[in] parentOne první z rodičů
		 * @param[in] parentTwo druhý z rodičů
		 * @param[in] mask maska pro určení jaký gen vzít z jakého rodiče
		 * @return zkřížený chromozom
		 */
	//	Chromosome perform_crossover( const Chromosome& parentOne, const Chromosome& parentTwo, std::vector< bool > mask ) const ;
			
   public:
	/**
	 * @brief konstruktor třídy Sequential_constructive_crossover
 	*/
	Sequential_constructive_crossover( double crossover_propability, const std::vector< std::vector< int > >& flowMatrix, const std::vector< std::vector< int > >& distanceMatrix, std::function< double( Chromosome& ) > fitness );

        virtual std::vector< Chromosome > cross_chromosomes( const Chromosome& parentOne, const Chromosome& parentTwo, const bool generate_two );

	virtual void create_offsprings(const std::vector< std::pair< Chromosome, double > >& population, std::vector< std::pair< Chromosome, double > >& offsprings, std::vector< std::pair< double, double > >& fitness_parents, const std::vector< std::size_t >& selected_indices, const int offspring_count = 1 );
};

#endif
