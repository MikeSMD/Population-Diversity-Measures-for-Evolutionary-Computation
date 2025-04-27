/**
 * @file GA_Mutation.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */


#ifndef GA_MUTATION_HEADER
#define GA_MUTATION_HEADER

#include <functional>
#include <vector>
#include <utility>
#include "../Random_generator.h"

template< typename Chromosome >
/**
 * @class GA_Mutation
 * @brief Třída zajišťující mutaci chromozomů pomocí předané funkce na mutaci chromozomu
 */
class GA_Mutation 
{
    private:

		/**
	 * @brief proměnná uchovávající funkci pro mutaci jednoho genu chromozomu
	*/
        std::function< void( Chromosome&, int ) > mutation;	
    protected:
    	/**
	 * @brief Mutační pravědpodobnost 
	 * proměnná určující pravděpodobnost mutace per gen
	*/
        double mutation_propability;
        GA_Mutation( double mutation_propability );



    public:

	/**
	 * @brief konstruktor třídy GA_Mutation
	*/
        GA_Mutation( std::function< void ( Chromosome&, int ) > mutation, double mutation_propability );

	/**
	 * @brief veřejná metoda pro aplikaci mutace na předaný vektor chromozomů
	 * @param[in,out] population Výstupní parametr, na jehož chromozomy se aplikuje mutační operátor
	 * @param[in] max_fitness Vstupní parametr předaný hodnotou pro specifikaci maximální fitness hodnoty v populaci
	 *
	*/
        virtual void mutate_population( std::vector< std::pair< Chromosome, double > >& population ) const;
	/**
	 * @brief destruktor třídy GA_Mutation
	*/
	virtual ~GA_Mutation() = default;
};






#endif
