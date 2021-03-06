#pragma once

#include <matazure/config.hpp>

namespace matazure {

/// sequence execution policy
struct sequence_policy {};

/// sequence execution policy with auto vectorization
struct sequence_vectorized_policy {};

#ifdef _OPENMP

#define MATAZURE_OPENMP

/// openmp parallel execution policy
struct omp_policy {};

/// openmp parallel execution policy with auto vectorization
struct omp_vectorized_policy {};

#endif

}
