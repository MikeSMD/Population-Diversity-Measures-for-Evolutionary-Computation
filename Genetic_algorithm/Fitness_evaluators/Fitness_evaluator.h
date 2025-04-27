/**
 * @file Fitness_evaluator.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.03.2025
 */

#ifndef FITNESS_EVALUATOR_HEADER
#define FITNESS_EVALUATOR_HEADER

#include <functional>
#include <vector>
#include <utility>

template< typename Chromosome >

/**
 * @class Fitness_evaluator
 * @brief Třída pro evaluaci chromozomů
 */
class Fitness_evaluator
{
    private:
	/**
	  * @brief proměnná uchovávající funkci pro evaluaci předaného chromozomu
	*/
        std::function< double (Chromosome&) > fitness_evaluator;

    public:
	/**
	 * @brief Konstruktor třídy Fitness_evaluator
	*/
        Fitness_evaluator( std::function< double (Chromosome&) > fitness_evaluator );

	/**
	 * @brief metoda zajišťující evaluaci chromozomů
	 * @param[in,out] vector_to_evaluate - paramtr obsahující vektory k evaluaci, zcela se přepíše hodnota představující fitness všech daných chromozomů
	 */
	void evaluate_chromosomes( std::vector< std::pair < Chromosome, double > >& vector_to_evaluate ) const;
	/**
	 * @brief destruktor třídy Fitness_evaluator
	*/
	virtual ~Fitness_evaluator() = default;
};

#endif
