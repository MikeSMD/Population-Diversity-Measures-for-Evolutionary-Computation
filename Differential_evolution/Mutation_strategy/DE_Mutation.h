/**
 * @file DE_Mutation.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef DE_MUTATION_ABSTRACT_HEADER
#define DE_MUTATION_ABSTRACT_HEADER

#include <vector>
#include <unordered_set>
#include <stdexcept>
#include "../Random_generator.h"
template< typename Vector >

/**
 * @class DE_Mutation
 * @brief abstraktní třída pro aplikaci mutační strategie
 */
class DE_Mutation
{
    private:

	/**
	 * @brief atribut pro rozsah dimenzí
	*/
	std::vector< std::pair< double, double > > ranges;
	/**
	 * @brief nejlepší nalezený vektor
	*/	
	const Vector* best_vector;
    protected:


	/**
	 * @brief mutační faktor
	*/
        double mutation_factor;

	/**
	 * @brief funkce pro generaci náhodných indexů
	 * @param[in] count - počet generovaných indexů
	 * @param[in] population_size - velikost populace
	 * @param[in] dimension_ranges - index, kterému se musí vyhnout
	 * @throws runtime_error - pokud je count větší než population_size - 1
	*/
	
        std::vector<std::size_t > getRandomIndexes( int count, size_t population_size, size_t index ) const;

/**
	 * @brief funkce pro nalezení nejlepšího jedince
	 * @param[in] population - populace
	 * @throws pokud bude populace prázdná
	*/
	
        const Vector* getBestVector( const std::vector< std::pair < Vector, double > >& population );
    public:

	
	/**
	 * @brief konstruktor třídy DE_Mutation
	 * @param[in] mutation_factor - mutační faktor
	 * @param[in] ranges - rozsahy dimenzí
	*/
        DE_Mutation( double mutation_factor, std::vector< std::pair< double, double > > ranges );

	/**
	 * @brief funkce pro generaci mutantů
	 * @param[in] population - populace
	 * @param[out] mutants - generování mutanti k jedincům
	*/
        void get_mutants( const std::vector< std::pair < Vector, double > >& population, std::vector< Vector >& mutants ) ;
       /**
	 * @brief funkce pro generaci mutanta z konkrétního jedince
	 * @param[in] population - populace
	 * @param[in] index - index jedince v populaci, ke kterému se mutant vytváří
	 * @throws runtime_error pokud bude neshoda v počtu dimenzí u jedinců
	*/ 
        virtual Vector Mutate_individual(const std::vector< std::pair < Vector, double > >& population, const std::size_t index) = 0;

};

#endif
