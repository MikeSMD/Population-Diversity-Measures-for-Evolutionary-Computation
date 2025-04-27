#include "SAT_problem.h"
#include <iostream>
#include <algorithm>
std::vector< bool > generate_chromosome( int genes_count )
{
    Random_generator& rg = Random_generator::get_instance();

    std::vector< bool > chromosome = {};
    for ( int i = 0; i < genes_count; ++i )
    {
        chromosome.emplace_back( rg.generate_int(1, 2) == 1 );
    }

    return chromosome;
}

void mutation_gene( std::vector< bool >& chromosome, int gene_index )
{
   

    chromosome[ gene_index ] = ! chromosome[ gene_index ];
}

double fitness_evaluator( std::vector< std::vector< int > > formula,  std::vector< bool >& chromosome )
{
    int succeded = 0;
   for ( int clause = 0; clause < formula.size(); ++clause )
   {
       bool returned_true = false;
        for ( int literar = 0; literar < formula[ clause ].size(); ++literar )
        {
            int index = formula[ clause ] [ literar ];

            bool res = chromosome[ abs( index ) ];
            if ( index < 0 )
                res = !res;

            if ( res )
            {
                returned_true = true;
                break;
            }
        }

        if ( returned_true )
            succeded+=1;
   }
   return static_cast< double >( succeded )/ formula.size();
}

bool end_criterium( const std::vector< std::pair < std::vector< bool >, double > >& population, bool resetStaticValues )
{
	static double best_fitness = -std::numeric_limits<double>::infinity();
	static int not_changed_generation_count = 0;

	if ( resetStaticValues )
	{
		best_fitness = -std::numeric_limits<double>::infinity();
		not_changed_generation_count = 0;	
		
		return true;
	}

	double best_one = std::max_element( population.begin(), population.end(), [](const auto& a, const auto& b)
			{
			 	return a.second < b.second;
			}
			)->second;

	if ( best_one > best_fitness )
	{
		best_fitness = best_one;
		not_changed_generation_count = 0;
	}
	else 
		not_changed_generation_count += 1;

	std::cout << "changed last - " << not_changed_generation_count<<std::endl;
	return not_changed_generation_count >= 100;
}

