#include "Graph_coloring.h"

#include <iostream>

std::vector< int > GCP_generate_chromosome( int genes_count, int max_colors )
{
    Random_generator& rg = Random_generator::get_instance();

    std::vector< int > chromosome = {};
    for ( int i = 0; i < genes_count; ++i )
    {
        chromosome.emplace_back( rg.generate_int(0, max_colors - 1) );
    }

    return chromosome;
}

void GCP_mutation_gene( std::vector< int >& chromosome, int gene_index, int max_colors )
{

    int number = chromosome[gene_index];
    while( number == chromosome[ gene_index ] )
    {
        Random_generator& rg = Random_generator::get_instance();
        number = rg.generate_int(0,max_colors-1);
    }
    chromosome[gene_index] = number;
}

double GCP_fitness_evaluator( std::vector< std::vector< int > > graph,  std::vector< int >& chromosome )
{
    int adj_error = 0;
    std::set< int > colors;
    int edges = 0;

   for ( int node = 0; node < graph.size(); ++node )
   {
       colors.insert( chromosome [ node ] );
        for ( int adj_index = 0; adj_index < graph[ node ].size(); ++adj_index )
        {
            edges+=1;

            if ( chromosome[ graph[ node ][ adj_index ] ] == chromosome[ node ] )
                adj_error+=1;
        }
   }

  // edges /= 2;
  // adj_error/=2;
	if ( adj_error == 0 )
	{
		return 1.0 + 1.0 / ( 1.0 + colors.size() );
	}
	else
	{
		return 1.0 / ( 1.0 + adj_error );
	}
}

