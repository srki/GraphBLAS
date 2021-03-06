//------------------------------------------------------------------------------
// GrB_Monoid_wait: wait for a user-defined GrB_Monoid to complete
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// In SuiteSparse:GraphBLAS, a user-defined GrB_Monoid has no pending
// operations to wait for.  All this method does is verify that the monoid is
// properly initialized.

#include "GB.h"

GrB_Info GrB_Monoid_wait   // no work, just check if the GrB_Monoid is valid
(
    GrB_Monoid *monoid
)
{ 

    //--------------------------------------------------------------------------
    // check inputs
    //--------------------------------------------------------------------------

    GB_WHERE ("GrB_Monoid_wait (&monoid)") ;
    GB_RETURN_IF_NULL (monoid) ;
    GB_RETURN_IF_NULL_OR_FAULTY (*monoid) ;

    //--------------------------------------------------------------------------
    // return result
    //--------------------------------------------------------------------------

    return (GrB_SUCCESS) ;
}

