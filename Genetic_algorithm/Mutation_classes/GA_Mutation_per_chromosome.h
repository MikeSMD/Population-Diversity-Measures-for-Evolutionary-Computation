/**
 * @file GA_Mutation_per_chromosome.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 30.03.2025
 */


#ifndef GA_MUTATION_PER_CHROMOSOME_HEADER
#define GA_MUTATION_PER_CHROMOSOME_HEADER

#include "../Random_generator.h"
#include "GA_Mutation.h"

template< typename Chromosome >
/**
 * @class GA_Mutation_per_chromosome
 * @brief Třída zajišťující mutaci chromozomů pomocí předané funkce na mutaci chromozomu
 */
class GA_Mutation_per_chromosome : public GA_Mutation< Chromosome >
{
    private:
	std::function< void ( Chromosome& ) > mutation;
    public:

	/**
	 * @brief konstruktor třídy GA_Mutation
	*/
        GA_Mutation_per_chromosome( std::function< void ( Chromosome& ) > mutation, double mutation_propability );

	/**
	 * @brief veřejná metoda pro aplikaci mutace na předaný vektor chromozomů
	 * @param[in,out] population Výstupní parametr, na jehož chromozomy se aplikuje mutační operátor
	 * @param[in] max_fitness Vstupní parametr předaný hodnotou pro specifikaci maximální fitness hodnoty v populaci
	 *
	*/
        virtual void mutate_population( std::vector< std::pair< Chromosome, double > >& population) const;
	/**
	 * @brief destruktor třídy GA_Mutation
	*/
	virtual ~GA_Mutation_per_chromosome() = default;
};






#endif
