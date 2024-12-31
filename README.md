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
    #define num_points 3
    #define dims 2

    // Example usage
    // Column major [3x2] matrix
    // | 0 1 |
    // | 0 3 |
    // | 1 5 |
    float points[num_points*dims] = {
        0, 0, 1,
        1, 3, 5
    };

    // Expects at least [num_points x num_points]
    float Z[num_points*num_points] = {0};

    int result = pdist_cm(points, Z, num_points, dims);
    if (result == 0) {
        // Success
        
        // Values in Z are technically stored in Column major
        // but because the result is always symmetric.
        // it doesnt matter... The transpose is itself.
    } else {
        // Error
    }

    return 0;
}
