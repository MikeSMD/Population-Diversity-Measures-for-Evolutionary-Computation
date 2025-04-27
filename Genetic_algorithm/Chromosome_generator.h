/**
 * @file Chromosome_generator.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_CHROMOSOME_GENERATOR_HEADER
#define GA_CHROMOSOME_GENERATOR_HEADER

#include <functional>
#include <vector>
#include <utility>

template< typename Chromosome >
/**
 * @class Chromosome_generator
 * @brief Třída zajišťující inicializaci populace pomocí předané funkce na generaci Chromozomů
 */
class Chromosome_generator
{
    private:
	/**
	 * @brief proměnná uchovávající funkci pro generaci jednoho chromozomu
	*/
        std::function< Chromosome() > chromosome_generator;

    public:
	/**
	 * @brief Konstruktor třídy Chromosome_generator
	*/
	Chromosome_generator( std::function< Chromosome() > chromosome_generator );

	/**
	 * @brief metoda zajišťující incializaci populace
	 * @param[out] population Výstupní parametr, jež se naplní vygenerovanými chromozomy. Původní data budou přepsána
	 * @param[in] population_size Vstupní parametr předaný hodnotou pro specifikaci velikosti inicializující se populace
	 * @throws - dle metody pro generaci chromozomů
 	 *
	*/
        void initialize_population( std::vector< std::pair< Chromosome, double > >& population, const std::size_t population_size ) const;

	/**
	 * @brief Konstruktor třídy Chromosome_generator
	*/

	~Chromosome_generator() = default;
};

#endif
