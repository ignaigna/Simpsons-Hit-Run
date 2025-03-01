//===========================================================================
// Copyright (C) 2003 Radical Entertainment Ltd.  All rights reserved.
//
// Component:   Upcase Function
//
// Description: converts a string to upper case
//
// Authors:     Ian Gipson
//
// Revisions		Date		Author	Revision
//					2000/10/23	IJG		Created
//
//===========================================================================

// Recompilation protection flag.
#ifndef __UPCASE_H
#define __UPCASE_H


//===========================================================================
// Nested Includes
//===========================================================================
#include <string.h>
#include <ctype.h>

//===========================================================================
// Forward References
//===========================================================================

//===========================================================================
// Constants, Typedefs, and Macro Definitions (needed by external clients)
//===========================================================================

//===========================================================================
// Interface Definitions
//===========================================================================

void Upcase( char* string );

#endif //__UPCASE_H
