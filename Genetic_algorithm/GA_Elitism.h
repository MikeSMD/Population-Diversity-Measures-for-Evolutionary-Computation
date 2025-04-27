/**
 * @file GA_Elitism.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef GA_ELITISM_HEADER
#define GA_ELITISM_HEADER
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
template< typename Chromosome >
/**
 * @class GA_Elitism
 * @brief Třída zajišťující uchovávání nejlepších jedinců
 */
class GA_Elitism
{
    private:
	/**
	 * @brief proměnná uchovávající nejlepší jedince
	*/
	    
        std::vector< std::pair< Chromosome, double > > elitism_chromosomes;
	/**
	 * @brief proměnná uchovávající velikost elitismu
	*/
	std::size_t elitism_count;

    public:
	/**
	 * @brief Konstruktor třídy GA_Elitism
	*/
        GA_Elitism( std::size_t elitism_count );
	/**
	 * @brief metoda zajišťující uložení elit
	 * @param[in] population kolekce chromozomů, ze které se budou brát elity, population může změnit své pořadí chromozomů
	 *
	 * @throws runtime_error - pokud je elitism_count příliš velký či je menší než 1
	*/
        void save_best_chromosomes( std::vector< std::pair< Chromosome, double > >& population );

	/**
	 * @brief metoda pro získání elit
	 *
 	 * @return kolekce nejlepších chromozomů
	*/
       std::vector< std::pair< Chromosome, double > > get_saved_chromosomes() const ;

	/**
	 * @brief metoda pro získání velikosti elitismu
	 *
 	 * @return velikost elitismu
	*/
       std::size_t get_elitism_size() const ;
	/**
	 * @brief destruktor třídy GA_Elitism
	*/
       ~GA_Elitism() = default;
};




#endif
