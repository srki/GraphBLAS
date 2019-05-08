//------------------------------------------------------------------------------
// GB_red:  hard-coded functions for reductions
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2019, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

#include "GB.h"
#ifndef GBCOMPACT
#include "GB_red__include.h"

// The reduction is defined by the following types and operators:

// Assemble tuples:    GB_red_build__first_int8
// Reduce to scalar:   GB_red_scalar__(none)
// Reduce each vector: GB_red_eachvec__(none)
// Reduce each index:  GB_red_eachindex__(none)

// A type:   int8_t
// C type:   int8_t

// Reduce:   ;
// Identity: (none)
// Terminal: ;

#define GB_ATYPE \
    int8_t

#define GB_CTYPE \
    int8_t

// Array to array

    // W [k] = (ztype) S [i], with typecast
    #define GB_CAST_ARRAY_TO_ARRAY(W,k,S,i)         \
        W [k] = S [i]

    // W [k] += (ztype) S [i], with typecast
    #define GB_ADD_CAST_ARRAY_TO_ARRAY(W,k,S,i)     \
        ;

    // W [k] = S [i], no typecast
    #define GB_COPY_ARRAY_TO_ARRAY(W,k,S,i)         \
        W [k] = S [i]

    // W [k] += S [i], no typecast
    #define GB_ADD_ARRAY_TO_ARRAY(W,k,S,i)          \
        ;

// Array to scalar

    // ztype s = (ztype) Ax [p], with typecast
    #define GB_CAST_ARRAY_TO_SCALAR(s,Ax,p)         \
        int8_t s = Ax [p]

    // s += (ztype) Ax [p], with typecast
    #define GB_ADD_CAST_ARRAY_TO_SCALAR(s,Ax,p)     \
        ;

    // s += S [i], no typecast
    #define GB_ADD_ARRAY_TO_SCALAR(s,S,i)           \
        ;

// Scalar to array

    // W [k] = s, no typecast
    #define GB_COPY_SCALAR_TO_ARRAY(W,k,s)          \
        W [k] = s

    // W [k] += s, no typecast
    #define GB_ADD_SCALAR_TO_ARRAY(W,k,s)           \
        ;

// workspace

    // declare a ztype array of size nthreads
    #define GB_REDUCTION_WORKSPACE(W,nthreads)      \
        int8_t W [nthreads]

// break the loop if terminal condition reached

    #define GB_BREAK_IF_TERMINAL(t)                 \
        ;

//------------------------------------------------------------------------------
// reduce to a scalar, for monoids only
//------------------------------------------------------------------------------

#if 0

void GB_red_scalar__(none)
(
    int8_t *result,
    const GrB_Matrix A,
    int nthreads
)
{ 
    int8_t s = (*result) ;
    #include "GB_reduce_to_scalar_template.c"
    (*result) = s ;
}

//------------------------------------------------------------------------------
// reduce to each vector: each vector A(:,k) reduces to a scalar Tx (k)
//------------------------------------------------------------------------------

void GB_red_eachvec__(none)
(
    int8_t *restrict Tx,
    GrB_Matrix A,
    const int64_t *restrict kfirst_slice,
    const int64_t *restrict klast_slice,
    const int64_t *restrict pstart_slice,
    int nthreads
)
{
    #include "GB_reduce_each_vector.c"
}

//------------------------------------------------------------------------------
// reduce to each index: each A(i,:) reduces to a scalar T (i)
//------------------------------------------------------------------------------

GrB_Info GB_red_eachindex__(none)
(
    GrB_Matrix *Thandle,
    GrB_Type ttype,
    GB_Sauna *Saunas,
    const int64_t hiwater,
    GrB_Matrix A,
    const int64_t *restrict pstart_slice,
    int nth,
    int nthreads,
    GB_Context Context
)
{
    GrB_Info info = GrB_SUCCESS ;
    GrB_Matrix T = NULL ;
    (*Thandle) = NULL ;
    #define GB_FREE_ALL ;
    #include "GB_reduce_each_index.c"
    (*Thandle) = T ;
    return (info) ;
}

#endif

//------------------------------------------------------------------------------
// build matrix
//------------------------------------------------------------------------------

void GB_red_build__first_int8
(
    int8_t *restrict Tx,
    int64_t  *restrict Ti,
    const int8_t *restrict S,
    int64_t nvals,
    int64_t ndupl,
    const int64_t *restrict I_work,
    const int64_t *restrict K_work,
    const int64_t *restrict tstart_slice,
    const int64_t *restrict tnz_slice,
    int nthreads
)
{
    #include "GB_reduce_build_template.c"
}

#endif
