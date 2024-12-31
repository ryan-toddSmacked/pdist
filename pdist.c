#include "pdist.h"

#include <math.h>

#define sub2ind_cm(rowi, coli, rows, cols) (rowi + coli * (long)rows)
#define sub2ind_rm(rowi, coli, rows, cols) (coli + rowi * (long)cols)

int pdist_cm(const float* points, float* Z, long num_points, long dim)
{
	long numel = (long)num_points * (long)num_points;
    long idx = 0;


    // We can only test if pointers are not NULL
    if (points == NULL || Z == NULL)
        return -1;

	#pragma omp parallel for
	for (idx = 0; idx < numel; idx++)
	{
		// Thread-local variables
		long i = 0;
		long j = 0;
		long d = 0;
		double dist = 0.0;
		double diff = 0.0;
		long idx_1 = 0;
		long idx_2 = 0;

		// Get column major, (row, col) = (idx % num_points, idx / num_points)
		i = idx % num_points;
		j = idx / num_points;

		if (j < i)
			continue;

		if (i == j)
		{
			Z[idx] = 0.0f;
			continue;
		}

		dist = 0.0;
		for (d = 0; d < dim; d++)
		{
			// Euclidean distance
			// Access points[i, d] and points[j, d], column major
			diff = 0.0;
			idx_1 = sub2ind_cm(i, d, num_points, dim);
			idx_2 = sub2ind_cm(j, d, num_points, dim);

			diff = (double)points[idx_1] - (double)points[idx_2];
			dist += diff * diff;
		}

		dist = sqrt(dist);

		// Access dists[i, j] and dists[j, i], column major
		idx_1 = sub2ind_cm(i, j, num_points, num_points);
		idx_2 = sub2ind_cm(j, i, num_points, num_points);

		Z[idx_1] = (float)dist;
		Z[idx_2] = (float)dist;
	}
}

int pdist_rm(const float* points, float* Z, long num_points, long dim)
{
	long numel = (long)num_points * (long)num_points;
    long idx = 0;	// openmp for loop index

    // We can only test if pointers are not NULL
    if (points == NULL || Z == NULL)
        return -1;

	#pragma omp parallel for
	for (idx = 0; idx < numel; idx++)
	{
		// Thread-local variables
		long i = 0;
		long j = 0;
		long d = 0;
		double dist = 0.0;
		double diff = 0.0;
		long idx_1 = 0;
		long idx_2 = 0;

		// Get row major, (row, col) = (idx / num_points, idx % num_points)
		i = idx / num_points;
		j = idx % num_points;

		if (i < j)
			continue;

		if (i == j)
		{
			Z[idx] = 0.0f;
			continue;
		}

		dist = 0.0;
		for (d = 0; d < dim; d++)
		{
			// Euclidean distance
			// Access points[i, d] and points[j, d], row major
			diff = 0.0;
			idx_1 = sub2ind_rm(i, d, num_points, dim);
			idx_2 = sub2ind_rm(j, d, num_points, dim);
			
			diff = (double)points[idx_1] - (double)points[idx_2];
			dist += diff * diff;
		}

		dist = sqrt(dist);

		// Access dists[i, j] and dists[j, i], row major
		idx_1 = sub2ind_rm(i, j, num_points, num_points);
		idx_2 = sub2ind_rm(j, i, num_points, num_points);

		Z[idx_1] = (float)dist;
		Z[idx_2] = (float)dist;
	}
}


