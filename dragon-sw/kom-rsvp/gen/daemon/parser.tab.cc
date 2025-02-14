/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 31 "unix/parser.y"

#include "RSVP_ConfigFileReader.h"
#include <stdio.h>
extern int yyparse();
extern int yylex();
extern int yylineno;
extern void yyerror(const char*);
extern FILE* yyin;
extern String yy_string;
extern uint32 yy_int;
extern ieee32float_p yy_float;
static String yy_ip_address;
static TimeValue yy_timeval;
static ConfigFileReader* cfr = NULL;
static const char* configfile = NULL;
static bool fatalError = false;
static String yy_ifType;
static String yy_host;
static String yy_swLayer;

#line 92 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_IP_ADDRESS = 6,                 /* IP_ADDRESS  */
  YYSYMBOL_INTERFACE = 7,                  /* INTERFACE  */
  YYSYMBOL_API_C = 8,                      /* API_C  */
  YYSYMBOL_ROUTE = 9,                      /* ROUTE  */
  YYSYMBOL_REFRESH = 10,                   /* REFRESH  */
  YYSYMBOL_ENCAP = 11,                     /* ENCAP  */
  YYSYMBOL_VIRT = 12,                      /* VIRT  */
  YYSYMBOL_DISABLE = 13,                   /* DISABLE  */
  YYSYMBOL_RAPID = 14,                     /* RAPID  */
  YYSYMBOL_LOSS = 15,                      /* LOSS  */
  YYSYMBOL_TC_C = 16,                      /* TC_C  */
  YYSYMBOL_NONE = 17,                      /* NONE  */
  YYSYMBOL_CBQ_C = 18,                     /* CBQ_C  */
  YYSYMBOL_HFSC_C = 19,                    /* HFSC_C  */
  YYSYMBOL_RATE = 20,                      /* RATE  */
  YYSYMBOL_PEER = 21,                      /* PEER  */
  YYSYMBOL_TIMER = 22,                     /* TIMER  */
  YYSYMBOL_SESSION_HASH = 23,              /* SESSION_HASH  */
  YYSYMBOL_API_HASH = 24,                  /* API_HASH  */
  YYSYMBOL_ID_HASH_SEND = 25,              /* ID_HASH_SEND  */
  YYSYMBOL_ID_HASH_RECV = 26,              /* ID_HASH_RECV  */
  YYSYMBOL_LIST_ALLOC = 27,                /* LIST_ALLOC  */
  YYSYMBOL_SB_ALLOC = 28,                  /* SB_ALLOC  */
  YYSYMBOL_EXPLICIT_ROUTE_ = 29,           /* EXPLICIT_ROUTE_  */
  YYSYMBOL_MPLS_C = 30,                    /* MPLS_C  */
  YYSYMBOL_NOMPLS = 31,                    /* NOMPLS  */
  YYSYMBOL_MPLS_ALL = 32,                  /* MPLS_ALL  */
  YYSYMBOL_NOMPLS_ALL = 33,                /* NOMPLS_ALL  */
  YYSYMBOL_LABEL_HASH = 34,                /* LABEL_HASH  */
  YYSYMBOL_LOCAL_ID = 35,                  /* LOCAL_ID  */
  YYSYMBOL_UPSTREAM_LABEL_ = 36,           /* UPSTREAM_LABEL_  */
  YYSYMBOL_INTEGER_RANGE = 37,             /* INTEGER_RANGE  */
  YYSYMBOL_NARB = 38,                      /* NARB  */
  YYSYMBOL_SLOTS = 39,                     /* SLOTS  */
  YYSYMBOL_SLOT = 40,                      /* SLOT  */
  YYSYMBOL_EXCLUDE = 41,                   /* EXCLUDE  */
  YYSYMBOL_NARB_EXTRA_OPTIONS = 42,        /* NARB_EXTRA_OPTIONS  */
  YYSYMBOL_NARB_VTAGS_ALLOWED = 43,        /* NARB_VTAGS_ALLOWED  */
  YYSYMBOL_EOS_MAP = 44,                   /* EOS_MAP  */
  YYSYMBOL_VLAN_OPTIONS = 45,              /* VLAN_OPTIONS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_command = 48,                   /* command  */
  YYSYMBOL_narb_host = 49,                 /* narb_host  */
  YYSYMBOL_narb_port = 50,                 /* narb_port  */
  YYSYMBOL_if_type = 51,                   /* if_type  */
  YYSYMBOL_slot = 52,                      /* slot  */
  YYSYMBOL_sw_layer = 53,                  /* sw_layer  */
  YYSYMBOL_excl_name = 54,                 /* excl_name  */
  YYSYMBOL_narb_option = 55,               /* narb_option  */
  YYSYMBOL_vtags = 56,                     /* vtags  */
  YYSYMBOL_vlan_option = 57,               /* vlan_option  */
  YYSYMBOL_tw_total = 58,                  /* tw_total  */
  YYSYMBOL_tw_slots = 59,                  /* tw_slots  */
  YYSYMBOL_generic = 60,                   /* generic  */
  YYSYMBOL_detail = 61,                    /* detail  */
  YYSYMBOL_tc = 62,                        /* tc  */
  YYSYMBOL_name = 63,                      /* name  */
  YYSYMBOL_local_port = 64,                /* local_port  */
  YYSYMBOL_local_address = 65,             /* local_address  */
  YYSYMBOL_remote_address = 66,            /* remote_address  */
  YYSYMBOL_remote_port = 67,               /* remote_port  */
  YYSYMBOL_virt = 68,                      /* virt  */
  YYSYMBOL_route_hops = 69,                /* route_hops  */
  YYSYMBOL_bandwidth = 70,                 /* bandwidth  */
  YYSYMBOL_latency = 71,                   /* latency  */
  YYSYMBOL_dest = 72,                      /* dest  */
  YYSYMBOL_mask = 73,                      /* mask  */
  YYSYMBOL_gateway = 74,                   /* gateway  */
  YYSYMBOL_ip_address = 75                 /* ip_address  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    63,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    95,    96,
      99,   102,   105,   106,   107,   108,   111,   114,   115,   118,
     119,   122,   123,   124,   125,   128,   129,   134,   138,   142,
     143,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     160,   161,   162,   163,   167,   171,   175,   179,   183,   184,
     188,   189,   193,   194,   198,   199,   203,   212,   216,   220,
     229,   230
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "STRING", "IP_ADDRESS", "INTERFACE", "API_C", "ROUTE", "REFRESH",
  "ENCAP", "VIRT", "DISABLE", "RAPID", "LOSS", "TC_C", "NONE", "CBQ_C",
  "HFSC_C", "RATE", "PEER", "TIMER", "SESSION_HASH", "API_HASH",
  "ID_HASH_SEND", "ID_HASH_RECV", "LIST_ALLOC", "SB_ALLOC",
  "EXPLICIT_ROUTE_", "MPLS_C", "NOMPLS", "MPLS_ALL", "NOMPLS_ALL",
  "LABEL_HASH", "LOCAL_ID", "UPSTREAM_LABEL_", "INTEGER_RANGE", "NARB",
  "SLOTS", "SLOT", "EXCLUDE", "NARB_EXTRA_OPTIONS", "NARB_VTAGS_ALLOWED",
  "EOS_MAP", "VLAN_OPTIONS", "$accept", "program", "command", "narb_host",
  "narb_port", "if_type", "slot", "sw_layer", "excl_name", "narb_option",
  "vtags", "vlan_option", "tw_total", "tw_slots", "generic", "detail",
  "tc", "name", "local_port", "local_address", "remote_address",
  "remote_port", "virt", "route_hops", "bandwidth", "latency", "dest",
  "mask", "gateway", "ip_address", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      21,    26,    29,    18,    18,    30,    31,    32,    33,    34,
      53,    54,    18,  -103,  -103,    55,    20,    56,    62,    63,
       1,     4,    64,     5,    21,  -103,    60,  -103,  -103,  -103,
      18,  -103,    18,  -103,  -103,    73,  -103,  -103,  -103,  -103,
    -103,  -103,    18,  -103,  -103,  -103,    74,  -103,  -103,     0,
    -103,    75,  -103,    76,  -103,  -103,    15,  -103,  -103,    77,
    -103,    78,  -103,  -103,    81,    82,  -103,    83,    84,  -103,
    -103,  -103,  -103,    71,    60,    18,  -103,    86,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,    11,  -103,    87,  -103,
    -103,  -103,    90,  -103,  -103,  -103,    18,  -103,  -103,     2,
    -103,    26,  -103,  -103,  -103,  -103,  -103,  -103,    91,  -103,
       4,     4,     4,    60,  -103,  -103,     3,    94,    94,    94,
    -103,  -103,    18,  -103,  -103,  -103,  -103,  -103,    95,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,    64,    50,     8,    81,    80,
       0,    77,     0,    66,    47,     0,    10,    11,    12,    13,
      14,    15,     7,    73,    18,    28,     0,    29,    31,     0,
      36,     0,    40,    24,    43,    44,    25,    74,    75,     0,
      46,    27,     1,     2,     0,     0,    53,     0,     0,    56,
      57,    58,    59,     5,    50,     0,    78,    20,    67,    48,
       9,    72,    30,    21,    35,    34,    22,    38,    23,    39,
      41,    42,     0,    45,    52,    65,     0,    54,    55,     0,
      49,     0,    79,    19,    33,    32,    37,    26,     0,    63,
       0,     0,     0,    50,     6,    69,    71,     0,     0,     0,
       4,    68,     0,    51,    76,    60,    61,    62,     0,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,    79,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,   -72,  -103,  -103,   -23,  -103,  -103,
     -17,  -103,  -103,  -103,  -100,  -102,  -103,  -103,  -103,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    23,    24,    46,    83,    49,    86,    51,    88,    53,
      56,    61,    35,    80,    73,    74,   113,    26,    96,    32,
      77,   116,   123,    42,    59,   125,    30,    75,   101,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    33,   100,    84,    54,    62,   121,    57,    58,    43,
     117,   118,   119,    47,   104,   122,   126,   127,    90,   109,
     110,   111,   112,    28,    29,    45,    29,    76,     1,     2,
       3,    25,    27,    34,    36,    37,    38,    39,    55,    81,
      85,   120,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   105,    91,    13,    14,    15,    40,    41,    44,    16,
      17,    48,    18,    19,    20,    21,    22,    50,    52,    60,
      64,    65,   102,    66,    67,    68,    79,    82,   114,   108,
      87,    89,    92,    93,    94,    95,    97,    99,    98,   103,
      69,    70,   106,   107,   115,    71,    72,   124,   129,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128
};

static const yytype_int8 yycheck[] =
{
       3,     4,    74,     3,     3,     0,     3,     3,     4,    12,
     110,   111,   112,    16,     3,    12,   118,   119,     3,    17,
      18,    19,    20,     5,     6,     5,     6,    30,     7,     8,
       9,     5,     3,     3,     3,     3,     3,     3,    37,    42,
      40,   113,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    40,    37,    32,    33,    34,     3,     3,     3,    38,
      39,     5,    41,    42,    43,    44,    45,     5,     5,     5,
      10,    11,    75,    13,    14,    15,     3,     3,   101,    96,
       5,     5,     5,     5,     3,     3,     3,    16,     4,     3,
      30,    31,     5,     3,     3,    35,    36,     3,     3,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    32,    33,    34,    38,    39,    41,    42,
      43,    44,    45,    47,    48,     5,    63,     3,     5,     6,
      72,    75,    65,    75,     3,    58,     3,     3,     3,     3,
       3,     3,    69,    75,     3,     5,    49,    75,     5,    51,
       5,    53,     5,    55,     3,    37,    56,     3,     4,    70,
       5,    57,     0,    47,    10,    11,    13,    14,    15,    30,
      31,    35,    36,    60,    61,    73,    75,    66,    75,     3,
      59,    75,     3,    50,     3,    40,    52,     5,    54,     5,
       3,    37,     5,     5,     3,     3,    64,     3,     4,    16,
      60,    74,    75,     3,     3,    40,     5,     3,    66,    17,
      18,    19,    20,    62,    63,     3,    67,    70,    70,    70,
      60,     3,    12,    68,     3,    71,    71,    71,    75,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    49,    49,
      50,    51,    52,    52,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    56,    56,    57,    57,    58,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    63,    64,    65,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    73,    74,
      75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     6,     3,     5,     2,     2,     3,
       2,     2,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     3,     3,     3,     2,     2,     4,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     2,     1,     2,
       1,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       0,     5,     2,     1,     2,     2,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     1,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* command: INTERFACE name generic TC_C tc generic  */
#line 67 "unix/parser.y"
                                               { cfr->createInterface(); cfr->cleanup(); }
#line 1243 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 5: /* command: INTERFACE name generic  */
#line 68 "unix/parser.y"
                                        { cfr->createInterface(); cfr->cleanup(); }
#line 1249 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 6: /* command: ROUTE dest mask gateway name  */
#line 69 "unix/parser.y"
                                                { cfr->createRoute(); cfr->cleanup(); }
#line 1255 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 7: /* command: EXPLICIT_ROUTE_ route_hops  */
#line 70 "unix/parser.y"
                                                { cfr->setExplicitRoute(); cfr->cleanup(); }
#line 1261 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 8: /* command: API_C INTEGER  */
#line 71 "unix/parser.y"
                                                { cfr->setApiPort( yy_int ); }
#line 1267 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 10: /* command: SESSION_HASH INTEGER  */
#line 73 "unix/parser.y"
                                                { cfr->setSessionHash(yy_int); }
#line 1273 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 11: /* command: API_HASH INTEGER  */
#line 74 "unix/parser.y"
                                                { cfr->setApiHash(yy_int); }
#line 1279 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 12: /* command: ID_HASH_SEND INTEGER  */
#line 75 "unix/parser.y"
                                                { cfr->setIdHashSend(yy_int); }
#line 1285 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 13: /* command: ID_HASH_RECV INTEGER  */
#line 76 "unix/parser.y"
                                                { cfr->setIdHashRecv(yy_int); }
#line 1291 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 14: /* command: LIST_ALLOC INTEGER  */
#line 77 "unix/parser.y"
                                                { cfr->setListAlloc(yy_int); }
#line 1297 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 15: /* command: SB_ALLOC INTEGER  */
#line 78 "unix/parser.y"
                                                { cfr->setSB_Alloc(yy_int); }
#line 1303 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 16: /* command: MPLS_ALL  */
#line 79 "unix/parser.y"
                                                { cfr->setGlobalMPLS( true ); cfr->mpls = true; }
#line 1309 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 17: /* command: NOMPLS_ALL  */
#line 80 "unix/parser.y"
                                                { cfr->setGlobalMPLS( false ); cfr->mpls = false; }
#line 1315 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 18: /* command: LABEL_HASH INTEGER  */
#line 81 "unix/parser.y"
                                                { cfr->setLabelHash(yy_int); }
#line 1321 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 19: /* command: PEER local_address remote_address INTEGER  */
#line 82 "unix/parser.y"
                                                        { cfr->addHop(yy_int); }
#line 1327 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 20: /* command: PEER local_address remote_address  */
#line 83 "unix/parser.y"
                                                        { cfr->addHop(); }
#line 1333 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 21: /* command: NARB narb_host narb_port  */
#line 84 "unix/parser.y"
                                                { }
#line 1339 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 22: /* command: SLOTS if_type slot  */
#line 85 "unix/parser.y"
                                                { }
#line 1345 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 23: /* command: EXCLUDE sw_layer excl_name  */
#line 86 "unix/parser.y"
                                                { }
#line 1351 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 24: /* command: NARB_EXTRA_OPTIONS narb_option  */
#line 87 "unix/parser.y"
                                                { }
#line 1357 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 25: /* command: NARB_VTAGS_ALLOWED vtags  */
#line 88 "unix/parser.y"
                                                { }
#line 1363 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 26: /* command: EOS_MAP bandwidth STRING INTEGER  */
#line 89 "unix/parser.y"
                                                { cfr->addEoSMap(yy_string, yy_int); }
#line 1369 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 27: /* command: VLAN_OPTIONS vlan_option  */
#line 90 "unix/parser.y"
                                                { }
#line 1375 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 28: /* narb_host: STRING  */
#line 95 "unix/parser.y"
                        { yy_host = yy_string; }
#line 1381 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 29: /* narb_host: ip_address  */
#line 96 "unix/parser.y"
                        { yy_host = yy_ip_address; }
#line 1387 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 30: /* narb_port: INTEGER  */
#line 99 "unix/parser.y"
                        { cfr->setNarbApiClient(yy_host, yy_int); }
#line 1393 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 31: /* if_type: STRING  */
#line 102 "unix/parser.y"
                        { yy_ifType = yy_string; }
#line 1399 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 32: /* slot: slot SLOT  */
#line 105 "unix/parser.y"
                        { cfr->addSlotInfo(yy_ifType, yy_string); }
#line 1405 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 33: /* slot: slot INTEGER  */
#line 106 "unix/parser.y"
                        { cfr->addSlotNum(yy_ifType, yy_int); }
#line 1411 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 34: /* slot: SLOT  */
#line 107 "unix/parser.y"
                { cfr->addSlotInfo(yy_ifType, yy_string); }
#line 1417 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 35: /* slot: INTEGER  */
#line 108 "unix/parser.y"
                        { cfr->addSlotNum(yy_ifType, yy_int); }
#line 1423 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 36: /* sw_layer: STRING  */
#line 111 "unix/parser.y"
                        { yy_swLayer = yy_string; }
#line 1429 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 37: /* excl_name: excl_name STRING  */
#line 114 "unix/parser.y"
                         { cfr->addLayerExclusion(yy_swLayer, yy_string); }
#line 1435 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 38: /* excl_name: STRING  */
#line 115 "unix/parser.y"
                         { cfr->addLayerExclusion(yy_swLayer, yy_string); }
#line 1441 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 39: /* narb_option: narb_option STRING  */
#line 118 "unix/parser.y"
                           { cfr->setNarbExtraOption(yy_string); }
#line 1447 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 40: /* narb_option: STRING  */
#line 119 "unix/parser.y"
                         { cfr->setNarbExtraOption(yy_string); }
#line 1453 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 41: /* vtags: vtags INTEGER  */
#line 122 "unix/parser.y"
                      { cfr->setAllowedVtag(yy_int); }
#line 1459 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 42: /* vtags: vtags INTEGER_RANGE  */
#line 123 "unix/parser.y"
                              { cfr->setAllowedVtagRange(yy_string); }
#line 1465 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 43: /* vtags: INTEGER  */
#line 124 "unix/parser.y"
                  { cfr->setAllowedVtag(yy_int); }
#line 1471 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 44: /* vtags: INTEGER_RANGE  */
#line 125 "unix/parser.y"
                        { cfr->setAllowedVtagRange(yy_string); }
#line 1477 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 45: /* vlan_option: vlan_option STRING  */
#line 128 "unix/parser.y"
                           { cfr->setSwitchVlanOption(yy_string); }
#line 1483 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 46: /* vlan_option: STRING  */
#line 129 "unix/parser.y"
                        { cfr->setSwitchVlanOption(yy_string); }
#line 1489 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 47: /* tw_total: INTEGER  */
#line 134 "unix/parser.y"
                        { cfr->setTimerTotal(yy_int); }
#line 1495 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 48: /* tw_slots: INTEGER  */
#line 138 "unix/parser.y"
                        { cfr->setTimerSlots(yy_int); }
#line 1501 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 51: /* detail: ENCAP local_port remote_address remote_port virt  */
#line 148 "unix/parser.y"
                                                                { cfr->encap = true; }
#line 1507 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 52: /* detail: REFRESH INTEGER  */
#line 149 "unix/parser.y"
                                                                { cfr->refreshRate = yy_int; cfr->refresh = true; }
#line 1513 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 53: /* detail: DISABLE  */
#line 150 "unix/parser.y"
                                                                { cfr->disable = true; }
#line 1519 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 54: /* detail: RAPID INTEGER  */
#line 151 "unix/parser.y"
                                                                { cfr->rapidRefreshRate = yy_int; }
#line 1525 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 55: /* detail: LOSS FLOAT  */
#line 152 "unix/parser.y"
                                                                { cfr->lossProb = yy_float; }
#line 1531 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 56: /* detail: MPLS_C  */
#line 153 "unix/parser.y"
                                                                { cfr->mpls = true; }
#line 1537 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 57: /* detail: NOMPLS  */
#line 154 "unix/parser.y"
                                                                { cfr->mpls = false; }
#line 1543 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 58: /* detail: LOCAL_ID  */
#line 155 "unix/parser.y"
                                                                { cfr->localId = yy_string; }
#line 1549 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 59: /* detail: UPSTREAM_LABEL_  */
#line 156 "unix/parser.y"
                                                                { cfr->upstreamLabel = yy_string; }
#line 1555 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 60: /* tc: CBQ_C bandwidth latency  */
#line 160 "unix/parser.y"
                                        { cfr->createTC_CBQ(); }
#line 1561 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 61: /* tc: HFSC_C bandwidth latency  */
#line 161 "unix/parser.y"
                                                { cfr->createTC_HFSC(); }
#line 1567 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 62: /* tc: RATE bandwidth latency  */
#line 162 "unix/parser.y"
                                                { cfr->createTC_Rate(); }
#line 1573 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 63: /* tc: NONE  */
#line 163 "unix/parser.y"
                                                { cfr->createTC_NONE(); }
#line 1579 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 64: /* name: STRING  */
#line 167 "unix/parser.y"
                                { cfr->interfaceName = yy_string; }
#line 1585 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 65: /* local_port: INTEGER  */
#line 171 "unix/parser.y"
                                { cfr->localPort = yy_int; }
#line 1591 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 66: /* local_address: ip_address  */
#line 175 "unix/parser.y"
                                { cfr->localAddress = yy_ip_address; }
#line 1597 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 67: /* remote_address: ip_address  */
#line 179 "unix/parser.y"
                                { cfr->remoteAddress = yy_ip_address; }
#line 1603 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 68: /* remote_port: remote_port INTEGER  */
#line 183 "unix/parser.y"
                                { cfr->remotePortList.push_back( yy_int ); }
#line 1609 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 69: /* remote_port: INTEGER  */
#line 184 "unix/parser.y"
                                { cfr->remotePortList.push_back( yy_int ); }
#line 1615 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 70: /* virt: VIRT ip_address INTEGER  */
#line 188 "unix/parser.y"
                                { cfr->virtAddress = yy_ip_address; cfr->virtMTU = yy_int; cfr->virt = true; }
#line 1621 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 72: /* route_hops: route_hops ip_address  */
#line 193 "unix/parser.y"
                                { cfr->addExplicitRouteHop(yy_ip_address); }
#line 1627 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 73: /* route_hops: ip_address  */
#line 194 "unix/parser.y"
                                { cfr->addExplicitRouteHop(yy_ip_address); }
#line 1633 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 74: /* bandwidth: INTEGER  */
#line 198 "unix/parser.y"
                        { cfr->bandwidth = yy_int; }
#line 1639 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 75: /* bandwidth: FLOAT  */
#line 199 "unix/parser.y"
                        { cfr->bandwidth = yy_float; }
#line 1645 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 76: /* latency: INTEGER  */
#line 203 "unix/parser.y"
                        { cfr->latency = yy_int; }
#line 1651 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 77: /* dest: ip_address  */
#line 212 "unix/parser.y"
                        { cfr->dest = yy_ip_address; }
#line 1657 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 78: /* mask: ip_address  */
#line 216 "unix/parser.y"
                        { cfr->mask = yy_ip_address; }
#line 1663 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 79: /* gateway: ip_address  */
#line 220 "unix/parser.y"
                        { cfr->gateway = yy_ip_address; }
#line 1669 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 80: /* ip_address: IP_ADDRESS  */
#line 229 "unix/parser.y"
                        { yy_ip_address = yy_string; }
#line 1675 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;

  case 81: /* ip_address: STRING  */
#line 230 "unix/parser.y"
                        { yy_ip_address = yy_string; }
#line 1681 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"
    break;


#line 1685 "/root/DRAGON/dragon-sw/kom-rsvp/gen/daemon/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 233 "unix/parser.y"


extern void yyerror(const char *s) {
	cerr << s << " in config file: " << configfile << " on line " << yylineno << endl;
	ERROR(5)( Log::Error, s, "in config file:", configfile, "on line", yylineno );
	fatalError = true;
}

bool ConfigFileReader::parseConfigFile( const String& filename ) {
	cleanup();
	cfr = this;
	configfile = filename.chars();
	yyin = fopen( filename.chars(), "r" );
	if ( !yyin ) {
		cfr->warn( filename );
	} else {
		yyparse();
		fclose( yyin );
	}
	return !fatalError;
}
