#ifndef __PDIST_H__
#define __PDIST_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief COLUMN MAJOR | Compute the pairwise Euclidean distance between points. Results are stored in Z.
 * 
 * @param points Numeric matrix of size [num_points x dim]. Rows correspond to individual observations, and columns to indvidual variables.
 * @param Z Symmetric matrix of size [num_points x num_points]. The diagonal is zero. Z(i,j) is the Euclidean distance between observations i and j.
 * @param num_points Number of observations. The number of rows in points.
 * @param dim Number of variables. The number of columns in points.
 * 
 * @return 0 if successful, -1 otherwise.
 */
int pdist_cm(const float* points, float* Z, long num_points, long dim);


/**
 * @brief ROW MAJOR | Compute the pairwise Euclidean distance between points. Results are stored in Z.
 * 
 * @param points Numeric matrix of size [num_points x dim]. Rows correspond to individual observations, and columns to indvidual variables.
 * @param Z Symmetric matrix of size [num_points x num_points]. The diagonal is zero. Z(i,j) is the Euclidean distance between observations i and j.
 * @param num_points Number of observations. The number of rows in points.
 * @param dim Number of variables. The number of columns in points.
 * 
 * @return 0 if successful, -1 otherwise.
 */
int pdist_rm(const float* points, float* Z, long num_points, long dim);

#ifdef __cplusplus
}
#endif

#endif // !__PDIST_H__
