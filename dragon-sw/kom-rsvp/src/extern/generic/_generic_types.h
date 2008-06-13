/**********************************************************
 * Filename:    _generic_types.h
 *
 * Description: This file contains type definitions and
 *              general macros
 *
 * Author: Glen Kramer (kramer@cs.ucdavis.edu)
 *         University of California @ Davis
 *********************************************************/

#ifndef _TYPES_H_V001_INCLUDED_
#define _TYPES_H_V001_INCLUDED_

#ifndef NULL
#define NULL ((void*) 0L)
#endif

//#define _USE_MSVC_SPECIFIC_TYPES_

/* Datatype abstractions. */

#if defined _USE_MSVC_SPECIFIC_TYPES_

    typedef unsigned __int8     int8u;
    typedef signed   __int8     int8s;

    typedef unsigned __int16    int16u;
    typedef signed   __int16    int16s;

    typedef unsigned __int32    int32u;
    typedef signed   __int32    int32s;

    typedef unsigned __int64    int64u;
    typedef signed   __int64    int64s;

#else  

/* use generic types */

    typedef unsigned char       int8u;
    typedef signed   char       int8s;

    typedef unsigned short int  int16u;
    typedef signed   short int  int16s;

    typedef unsigned long       int32u;
    typedef signed   long       int32s;

#endif

typedef int8s               BOOL;
typedef int8u               BYTE;
typedef char                CHAR;
typedef unsigned int        WORD;

//typedef float               FLOAT;
typedef double              DOUBLE;



template < class T > inline T round( DOUBLE val )  { return (T)( val + 0.5 ); }
//template < class T > inline T MAX( T x, T y )      { return x > y? x : y; }
//template < class T > inline T MIN( T x, T y )      { return x < y? x : y; }

//const BOOL TRUE  = 1;
//const BOOL FALSE = 0;

#endif /* _TYPES_H_V001_INCLUDED_ */
