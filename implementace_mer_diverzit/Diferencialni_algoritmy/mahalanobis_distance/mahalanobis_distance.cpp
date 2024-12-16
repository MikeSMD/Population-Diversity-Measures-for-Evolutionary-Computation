#include "mahalanobis_distance.h"
#include <cmath>
#include <unordered_map>
#include <Eigen/Dense>

template<typename Chromosome, typename Container>

double mahalanobis_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo, const Container& population )
{
   double sum = 0;

   std::unordered_map< int, double > dimensions_average_values = {};
   size_t population_size = population.size();
    
   size_t chromosome_size = chromosomeOne.size();

   for ( size_t dimension = 0; dimension < chromosome_size; ++dimension )
   {    
       double sum = 0.0;
   
        for ( size_t chromosome = 0; chromosome < population_size; ++chromosome )
        {
            sum += population[ chromosome ][ dimension ];
        }
        
       dimensions_average_values[ dimension ] = sum / population_size;
   }

    Eigen::MatrixXd covarianceMatrix ( chromosome_size, chromosome_size );

    for ( size_t i = 0; i < chromosome_size; ++i )
    {
        
        for ( size_t j = 0; j < chromosome_size; ++j )
        {

            double sum = 0.0;
            for ( size_t chromosome_index = 0; chromosome_index < population_size; ++chromosome_index )
            {
                
                sum += ( population[ chromosome_index ][ i ] - dimensions_average_values[ i ] ) * ( population[ chromosome_index ][ j ] - dimensions_average_values[ j ] );

            }
            covarianceMatrix( i, j ) = sum / ( population_size - 1 );

        }

    }

    Eigen::MatrixXd inverseCovarianceMatrix = covarianceMatrix.inverse();

    Eigen::VectorXd chromosome_difference( chromosome_size );

    for ( size_t i = 0; i < chromosome_size; ++i )
    {
        chromosome_difference( i ) = chromosomeOne[ i ] - chromosomeTwo[ i ];
    }

   return std::pow( chromosome_difference.transpose() * inverseCovarianceMatrix * chromosome_difference, 0.5 );
}
