#include "mahalanobis_distance.h"

template<typename Individual, typename Container>
double mahalanobis_distance( const Individual& individualOne, const Individual& individualTwo, const Container& population )
{
	std::size_t population_size = population.size();

    	if ( population_size <= 1 )
		throw std::invalid_argument("mahalanobis_distance: velikost populace je příliš malá");
	std::size_t dimensions = individualOne.size();
    
	std::vector<double> dimensions_average_values( dimensions , 0.0);

    	for ( std::size_t dimension = 0; dimension < dimensions; ++dimension )
    	{
        	double sum = 0.0;
        	for ( std::size_t individual = 0; individual < population_size; ++ individual )
        	{
            		sum += population[ individual ][ dimension ];
        	}

		dimensions_average_values[ dimension ] = sum / population_size;
	}

	Eigen::MatrixXd covarianceMatrix = Eigen::MatrixXd::Zero( dimensions , dimensions );

	const double epsilon = 1e-4;

	for ( std::size_t i = 0; i < dimensions ; ++i )
	{
		for ( std::size_t j = 0; j < dimensions; ++j )
		{
			double sum = 0.0;
			for ( std::size_t index = 0; index < population_size; ++index )
			{
				sum += ( population[ index ][ i ] - dimensions_average_values[ i ] ) * ( population[ index ][ j ] - dimensions_average_values[ j ] );
			}
			covarianceMatrix( i, j ) = sum / ( population_size - 1 ) + ( i == j ? epsilon : 0 );
		}
	}

	Eigen::LDLT<Eigen::MatrixXd> ldlt( covarianceMatrix ); 

	if (ldlt.info() != Eigen::Success || !ldlt.isPositive())
        	return std::numeric_limits<double>::quiet_NaN();
    
    
	Eigen::MatrixXd inverseCovarianceMatrix = ldlt.solve( Eigen::MatrixXd::Identity( covarianceMatrix.rows(), covarianceMatrix.cols() ) );

    Eigen::VectorXd chromosome_difference( dimensions );

    for ( std::size_t i = 0; i < dimensions ; ++i )
    { 
        chromosome_difference( i ) = individualOne[ i ] -individualTwo[ i ];
    }

    return std::sqrt(chromosome_difference.transpose() * inverseCovarianceMatrix * chromosome_difference );
}

template double mahalanobis_distance<std::vector<double>, std::vector<std::vector<double>>>(const std::vector<double>&, const std::vector<double>&, const std::vector<std::vector<double>>&);
