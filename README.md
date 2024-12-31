# pdist

Pairwise distance between pairs of observations.

## Overview

This library provides functions to compute the pairwise Euclidean distance between points in a numeric matrix. It is inspired by MATLAB's `pdist` function.

## Functions

### `pdist_cm`

Compute the pairwise Euclidean distance between points in a column-major order. Results are stored in a symmetric matrix `Z`.

#### Parameters

- `points`: Numeric matrix of size `[num_points x dim]`. Rows correspond to individual observations, and columns to individual variables.
- `Z`: Symmetric matrix of size `[num_points x num_points]`. The diagonal is zero. `Z(i,j)` is the Euclidean distance between observations `i` and `j`.
- `num_points`: Number of observations. The number of rows in `points`.
- `dim`: Number of variables. The number of columns in `points`.

#### Returns

- `0` if successful, `-1` otherwise.

### `pdist_rm`

Compute the pairwise Euclidean distance between points in a row-major order. Results are stored in a symmetric matrix `Z`.

#### Parameters

- `points`: Numeric matrix of size `[num_points x dim]`. Rows correspond to individual observations, and columns to individual variables.
- `Z`: Symmetric matrix of size `[num_points x num_points]`. The diagonal is zero. `Z(i,j)` is the Euclidean distance between observations `i` and `j`.
- `num_points`: Number of observations. The number of rows in `points`.
- `dim`: Number of variables. The number of columns in `points`.

#### Returns

- `0` if successful, `-1` otherwise.

## Usage

Include the header file `pdist.h` in your C source file and link against the compiled library.

```c
#include "pdist.h"

int main() {
    // Example usage
    float points[] = { /* your data */ };
    float Z[/* size */];
    long num_points = /* number of points */;
    long dim = /* dimension */;

    int result = pdist_cm(points, Z, num_points, dim);
    if (result == 0) {
        // Success
    } else {
        // Error
    }

    return 0;
}
