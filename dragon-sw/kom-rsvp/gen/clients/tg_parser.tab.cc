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
#line 31 "unix/tg_parser.y"


#include "tg_classes.h"

using namespace TG;

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
static String yy_name;
static RSVP_API* api = NULL;
static TSpec tspec;
static TimeValue rsvpSignalWaitTime;
static TimeValue rsvpSyncBackoffTime;
static RSpec rspec;
static bool stamp,rsvp,flowMapping;
static uint32 flowCount, createCount;
static NetAddress localAddr,remoteAddr;
static uint16 localPort, remotePort;
static uint32 packetRate,packetSize,totalSize,sourceCount;
static double hurstParameter,wtpFactor;
static TimeValue flowArrival,flowDuration;
static enum FlowType { tg_UDP, tg_TCP, tg_TCP_Server } flowType;
static enum SenderType { tg_CBR, tg_TRACE, tg_PARETO, tg_GREEDY } senderType;
static ActionObject* action = NULL;
static Flow* flow = NULL;
static Flow** flows = NULL;
static RateEstimator* rateEstimator = NULL;
static DelayCounter* delayCounter = NULL;
static PacketCounter* packetCounter = NULL;
static SimpleList<uint32> varList;
static TimeValue varTime, cbrTime, connectTime;
static bool fixedArrival, fixedDuration;
static bool syntaxError = true, fatalError = false;
static const char* configfile = NULL;

static void createSummaryObject( SummaryObject& so ) {
	if ( traffgen->getSummaryObject( so.getName() ) ) {
		cerr << "ERROR: summary object " << so.getName() << "already exists" << endl;
		exit(1);
	}
	traffgen->addSummaryObject( so );
}

static SummaryObject* findSummaryObject( const String& name ) {
	SummaryObject* so = traffgen->getSummaryObject( name );
	if ( !so ) {
		cerr << "WARNING: cannot find summary object named " << name << endl;
	}
	return so;
}

struct Alias {
	String name;
	String addr;
	Alias( const String& n = "", const String& a = "" ) : name(n), addr(a) {}
};
static SimpleList<Alias> aliasList;

static void findAlias( const String& name ) {
	SimpleList<Alias>::ConstIterator iter = aliasList.begin();
	for ( ; iter != aliasList.end(); ++iter ) {
		if ( (*iter).name == name ) {
			yy_ip_address = (*iter).addr;
			return;
		}
	}
	yy_ip_address = name;
}

static void cleanup() {
	flows = NULL;
	flow = NULL;
	action = NULL;
}
static void doSendFlow() {
	if ( stamp ) flow->enableSenderTimestamping();
	if ( rsvp && api ) reinterpret_cast<Sender*>(action)->enableSignallingRSVP( *api, tspec, rsvpSignalWaitTime, rsvpSyncBackoffTime );
	if ( rateEstimator ) flow->attachSendingRateEstimator( *rateEstimator );
	if ( packetCounter ) flow->attachSendPacketCounter( *packetCounter );
}
static void doReceiveFlow() {
	if ( stamp ) flow->enableReceiverTimestamping();
	if ( rsvp && api ) flow->signalReceiverRSVP( *api, rspec, wtpFactor );
	if ( rateEstimator ) flow->attachReceivingRateEstimator( *rateEstimator );
	if ( delayCounter ) flow->attachDelayCounter( *delayCounter );
	traffgen->addFlow( *flow );
}
static void finishFlowset() {
	uint32 i = 0;
	for ( ; i < flowCount; ++i ) {
		traffgen->addFlowHousekeeping( *flows[i] );
	}
	delete [] flows;
	flows = NULL;
}
static void doReceiveFlowset() {
	uint32 i = 0;
	for ( ; i < flowCount; ++i ) {
		traffgen->addFlow( *flows[i] );
		if ( stamp ) flows[i]->enableReceiverTimestamping();
		if ( rsvp && api ) {
			flows[i]->signalReceiverRSVP( *api, rspec, wtpFactor );
			if (i/10 == 0) usleep(1000);
		}
		if ( rateEstimator ) flows[i]->attachReceivingRateEstimator( *rateEstimator );
		if ( delayCounter ) flows[i]->attachDelayCounter( *delayCounter );
	}
}
static void doSendFlowset() {
	ActionSet* as = new ActionSet( createCount, flowArrival, flowDuration, fixedArrival, fixedDuration );
	uint32 i = 0;
	uint32 avgFlowCount = (uint32)(flowDuration/flowArrival);
	if ( createCount > flowCount && avgFlowCount * 1.5 > flowCount ) {
		LOG(4)( LogWarning, "WARNING: estimated avg. flow count is", avgFlowCount, "given flow count:", flowCount );
	}
	for ( ; i < flowCount; ++i ) {
                                                             assert(flows[i]);
		Sender* s;
		if ( senderType == tg_CBR ) {
			s = new CbrSender( *flows[i], packetSize, packetRate, TimeValue( 0, 0 ) );
		} else if ( senderType == tg_TRACE ) {
			s = new TraceSender( *flows[i], yy_string );
		} else if ( senderType == tg_PARETO ) {
			s = new ParetoSender( *flows[i], packetSize, packetRate, TimeValue( 0, 0 ), sourceCount, hurstParameter );
		} else {
			s = new GreedySender( *flows[i], packetSize, packetRate, totalSize, TimeValue( 0, 0 ) );
		}
		traffgen->addActionHousekeeping( *s );
		as->addAction( *s );
		if ( stamp ) flows[i]->enableSenderTimestamping();
		if ( rsvp && api ) s->enableSignallingRSVP( *api, tspec, rsvpSignalWaitTime, rsvpSyncBackoffTime );
		if ( rateEstimator ) flows[i]->attachSendingRateEstimator( *rateEstimator );
		if ( packetCounter ) flows[i]->attachSendPacketCounter( *packetCounter );
	}
	if ( flowMapping && rsvp && api ) {
		Flowset* flowset = new Flowset( localPort, flowCount);
		flowset->flows[0] = flows[0];
		RSVP_API::SessionId id = flows[0]->registerSenderRSVP( *api, flowset );
		for ( i = 1; i < flowCount; ++i ) {
			flows[i]->setRSVP( *api, id );
			flowset->flows[i] = flows[i];
		}
		
	}
	action = as;
}
static void doCreateFlowset() {
	flows = new Flow*[flowCount];
	uint32 i = 0;
	for ( ; i < flowCount; ++i ) {
		switch ( flowType ) {
		case tg_UDP:
			if ( flowMapping ) {
				flows[i] = new UdpFlow( localAddr.rawAddress(), localPort + i, remoteAddr.rawAddress(), remotePort );
			} else {
				flows[i] = new UdpFlow( localAddr.rawAddress(), localPort + i, remoteAddr.rawAddress(), remotePort + i );
			}
			break;
		case tg_TCP:
			if ( flowMapping ) {
				flows[i] = new TcpFlow( localAddr.rawAddress(), remoteAddr.rawAddress(), remotePort, connectTime );
			} else {
				flows[i] = new TcpFlow( localAddr.rawAddress(), remoteAddr.rawAddress(), remotePort + i, connectTime );
			}
			break;
		case tg_TCP_Server:
			flows[i] = new TcpServer( localAddr.rawAddress(), localPort + i );
			break;
		default:
			assert(0);
		}
	}
}
static void createCbrVariation() {
	CbrSender* sender = new CbrSender( *flow, packetSize, packetRate, cbrTime );
	traffgen->addActionHousekeeping( *sender );
	SenderVariation* sv = new SenderVariation( *sender, varTime );
	sv->addPacketRates(varList);
	varList.clear();
	action = sv;
}
static bool checkLocalAddress() {
	if ( !traffgen->findInterface(localAddr.rawAddress()) ) {
		cerr << "ignoring unknown local address: " << localAddr << endl;
		syntaxError = false;
		return false;
	}
	return true;
}


#line 272 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"

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

#include "tg_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FLOW = 3,                       /* FLOW  */
  YYSYMBOL_FLOWSET = 4,                    /* FLOWSET  */
  YYSYMBOL_ESTIMATOR = 5,                  /* ESTIMATOR  */
  YYSYMBOL_DCOUNTER = 6,                   /* DCOUNTER  */
  YYSYMBOL_PCOUNTER = 7,                   /* PCOUNTER  */
  YYSYMBOL_ALIAS = 8,                      /* ALIAS  */
  YYSYMBOL_SEED = 9,                       /* SEED  */
  YYSYMBOL_SEND = 10,                      /* SEND  */
  YYSYMBOL_RECV = 11,                      /* RECV  */
  YYSYMBOL_UDP = 12,                       /* UDP  */
  YYSYMBOL_TCP = 13,                       /* TCP  */
  YYSYMBOL_CBR = 14,                       /* CBR  */
  YYSYMBOL_TRACE = 15,                     /* TRACE  */
  YYSYMBOL_PARETO = 16,                    /* PARETO  */
  YYSYMBOL_GREEDY = 17,                    /* GREEDY  */
  YYSYMBOL_MAP = 18,                       /* MAP  */
  YYSYMBOL_FIXED = 19,                     /* FIXED  */
  YYSYMBOL_REPEAT = 20,                    /* REPEAT  */
  YYSYMBOL_AT = 21,                        /* AT  */
  YYSYMBOL_VARY = 22,                      /* VARY  */
  YYSYMBOL_SERVER = 23,                    /* SERVER  */
  YYSYMBOL_STAMP = 24,                     /* STAMP  */
  YYSYMBOL_RSVP_S = 25,                    /* RSVP_S  */
  YYSYMBOL_WTP = 26,                       /* WTP  */
  YYSYMBOL_RATE = 27,                      /* RATE  */
  YYSYMBOL_DELAY = 28,                     /* DELAY  */
  YYSYMBOL_PACKETS = 29,                   /* PACKETS  */
  YYSYMBOL_SYNC = 30,                      /* SYNC  */
  YYSYMBOL_INTEGER = 31,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_STRING = 33,                    /* STRING  */
  YYSYMBOL_IP_ADDRESS = 34,                /* IP_ADDRESS  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_command = 37,                   /* command  */
  YYSYMBOL_flow_command = 38,              /* flow_command  */
  YYSYMBOL_ext_flow_descr = 39,            /* ext_flow_descr  */
  YYSYMBOL_flow_descr = 40,                /* flow_descr  */
  YYSYMBOL_flow_send = 41,                 /* flow_send  */
  YYSYMBOL_sendertype = 42,                /* sendertype  */
  YYSYMBOL_flow_recv = 43,                 /* flow_recv  */
  YYSYMBOL_add_actions = 44,               /* add_actions  */
  YYSYMBOL_add_action = 45,                /* add_action  */
  YYSYMBOL_flowset_command = 46,           /* flowset_command  */
  YYSYMBOL_ext_flowset_descr = 47,         /* ext_flowset_descr  */
  YYSYMBOL_flowset_descr = 48,             /* flowset_descr  */
  YYSYMBOL_flowset_send = 49,              /* flowset_send  */
  YYSYMBOL_flowset_recv = 50,              /* flowset_recv  */
  YYSYMBOL_send_conf = 51,                 /* send_conf  */
  YYSYMBOL_recv_conf = 52,                 /* recv_conf  */
  YYSYMBOL_fs_conf = 53,                   /* fs_conf  */
  YYSYMBOL_create_count = 54,              /* create_count  */
  YYSYMBOL_flowcount = 55,                 /* flowcount  */
  YYSYMBOL_local = 56,                     /* local  */
  YYSYMBOL_map = 57,                       /* map  */
  YYSYMBOL_remote = 58,                    /* remote  */
  YYSYMBOL_local_addr = 59,                /* local_addr  */
  YYSYMBOL_connect_time = 60,              /* connect_time  */
  YYSYMBOL_stamp = 61,                     /* stamp  */
  YYSYMBOL_rsvp_send = 62,                 /* rsvp_send  */
  YYSYMBOL_rsvpwait = 63,                  /* rsvpwait  */
  YYSYMBOL_sync = 64,                      /* sync  */
  YYSYMBOL_tspec = 65,                     /* tspec  */
  YYSYMBOL_avg = 66,                       /* avg  */
  YYSYMBOL_depth = 67,                     /* depth  */
  YYSYMBOL_peak = 68,                      /* peak  */
  YYSYMBOL_min = 69,                       /* min  */
  YYSYMBOL_MTU = 70,                       /* MTU  */
  YYSYMBOL_rsvp_recv = 71,                 /* rsvp_recv  */
  YYSYMBOL_rate = 72,                      /* rate  */
  YYSYMBOL_slack = 73,                     /* slack  */
  YYSYMBOL_wtp = 74,                       /* wtp  */
  YYSYMBOL_rate_estimator = 75,            /* rate_estimator  */
  YYSYMBOL_dcounter = 76,                  /* dcounter  */
  YYSYMBOL_pcounter = 77,                  /* pcounter  */
  YYSYMBOL_packetsize = 78,                /* packetsize  */
  YYSYMBOL_packetrate = 79,                /* packetrate  */
  YYSYMBOL_totalsize = 80,                 /* totalsize  */
  YYSYMBOL_srccount = 81,                  /* srccount  */
  YYSYMBOL_hurst = 82,                     /* hurst  */
  YYSYMBOL_vary = 83,                      /* vary  */
  YYSYMBOL_variation = 84,                 /* variation  */
  YYSYMBOL_arrival = 85,                   /* arrival  */
  YYSYMBOL_duration = 86,                  /* duration  */
  YYSYMBOL_fixed = 87,                     /* fixed  */
  YYSYMBOL_fixed_a = 88,                   /* fixed_a  */
  YYSYMBOL_fixed_d = 89,                   /* fixed_d  */
  YYSYMBOL_timeval = 90,                   /* timeval  */
  YYSYMBOL_ip_address = 91,                /* ip_address  */
  YYSYMBOL_alias_command = 92,             /* alias_command  */
  YYSYMBOL_name = 93,                      /* name  */
  YYSYMBOL_estimator_command = 94,         /* estimator_command  */
  YYSYMBOL_dcounter_command = 95,          /* dcounter_command  */
  YYSYMBOL_pcounter_command = 96           /* pcounter_command  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   240,   240,   241,   245,   246,   247,   248,   249,   250,
     251,   252,   256,   257,   258,   259,   260,   264,   268,   269,
     270,   274,   278,   279,   280,   281,   282,   283,   287,   291,
     292,   296,   297,   301,   302,   303,   304,   305,   309,   313,
     314,   318,   319,   320,   321,   325,   329,   333,   337,   341,
     345,   349,   353,   354,   358,   362,   366,   367,   371,   372,
     376,   377,   378,   382,   386,   387,   391,   392,   396,   397,
     401,   402,   406,   407,   411,   415,   419,   420,   421,   422,
     426,   427,   431,   435,   436,   437,   441,   442,   446,   447,
     451,   452,   456,   460,   464,   468,   472,   476,   480,   481,
     485,   489,   493,   494,   498,   499,   503,   504,   508,   509,
     513,   514,   518,   522,   526,   530,   534
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
  "\"end of file\"", "error", "\"invalid token\"", "FLOW", "FLOWSET",
  "ESTIMATOR", "DCOUNTER", "PCOUNTER", "ALIAS", "SEED", "SEND", "RECV",
  "UDP", "TCP", "CBR", "TRACE", "PARETO", "GREEDY", "MAP", "FIXED",
  "REPEAT", "AT", "VARY", "SERVER", "STAMP", "RSVP_S", "WTP", "RATE",
  "DELAY", "PACKETS", "SYNC", "INTEGER", "FLOAT", "STRING", "IP_ADDRESS",
  "$accept", "program", "command", "flow_command", "ext_flow_descr",
  "flow_descr", "flow_send", "sendertype", "flow_recv", "add_actions",
  "add_action", "flowset_command", "ext_flowset_descr", "flowset_descr",
  "flowset_send", "flowset_recv", "send_conf", "recv_conf", "fs_conf",
  "create_count", "flowcount", "local", "map", "remote", "local_addr",
  "connect_time", "stamp", "rsvp_send", "rsvpwait", "sync", "tspec", "avg",
  "depth", "peak", "min", "MTU", "rsvp_recv", "rate", "slack", "wtp",
  "rate_estimator", "dcounter", "pcounter", "packetsize", "packetrate",
  "totalsize", "srccount", "hurst", "vary", "variation", "arrival",
  "duration", "fixed", "fixed_a", "fixed_d", "timeval", "ip_address",
  "alias_command", "name", "estimator_command", "dcounter_command",
  "pcounter_command", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -119,    62,  -119,  -119,     7,   -18,     0,     2,    10,    18,
      29,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    -9,    -7,
      53,    78,  -119,    61,    80,    85,    69,    69,  -119,  -119,
      -9,  -119,  -119,  -119,    -9,    43,    -9,    -9,  -119,    52,
    -119,    66,    82,   100,    52,  -119,    70,    82,   104,    -9,
       6,  -119,  -119,  -119,    64,  -119,    -8,    84,  -119,  -119,
      69,  -119,  -119,    89,    86,    87,    86,    86,    52,    88,
      69,    53,    82,    82,  -119,    86,    90,    86,    86,    61,
      82,   103,    -9,   103,  -119,  -119,    91,  -119,  -119,  -119,
      92,    96,  -119,    95,  -119,    95,    95,  -119,    89,  -119,
    -119,  -119,  -119,  -119,    95,    99,    95,    95,  -119,  -119,
      -9,  -119,    -9,  -119,  -119,    97,   107,  -119,    23,    69,
      98,   105,    99,  -119,    52,    69,   102,    98,  -119,    69,
    -119,    47,  -119,  -119,   106,   102,  -119,    69,   108,   111,
      52,  -119,   118,  -119,  -119,   110,    99,  -119,    73,   109,
    -119,   112,  -119,    69,   110,  -119,  -119,    69,  -119,  -119,
    -119,    69,  -119,    99,    52,  -119,  -119,  -119,  -119,  -119,
     113,  -119,    75,  -119,   119,  -119,    52,  -119,  -119,   114,
    -119,  -119,   116,    77,  -119,   117,  -119,  -119,    69,  -119,
    -119,  -119,    81,  -119,  -119,  -119,  -119,  -119,   120,  -119,
     121,  -119,  -119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    11,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,   116,   113,
       0,    10,   111,   110,     0,     0,     0,     0,    55,    59,
      13,     0,    30,    14,    59,    34,     0,    30,    35,     0,
       0,   108,   109,   114,     0,   112,    18,     0,    51,    17,
      57,    58,    28,    87,     0,     0,     0,     0,    59,     0,
       0,    12,    30,    30,    45,     0,     0,     0,     0,    33,
      30,    53,     0,    53,   115,    52,     0,    54,    20,    56,
       0,    89,    92,     0,    25,     0,     0,    21,    87,    31,
      32,    16,    29,    15,     0,   105,     0,     0,    37,    36,
       0,    38,     0,    19,    86,     0,    79,    93,     0,     0,
       0,    91,   105,   104,    59,     0,     0,     0,    39,    57,
      88,    85,    47,    24,    22,     0,    94,     0,     0,    62,
      59,    42,   107,   100,    95,     0,   105,    40,     0,    77,
      80,     0,    78,     0,     0,    27,    90,     0,    46,    41,
     106,     0,    96,   105,    59,    84,    83,    82,    76,    23,
       0,    26,    67,    63,   103,   101,    59,    44,    99,    97,
      69,    68,    65,     0,   102,     0,    43,    98,    61,    60,
      71,    70,     0,    49,    48,    64,    73,    72,     0,    74,
       0,    75,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,  -119,  -119,  -119,  -119,   115,  -119,   -14,   -42,
    -119,  -119,  -119,  -119,   101,   -20,  -118,   122,  -114,  -119,
    -119,   -21,   -72,   -35,   123,    21,   -27,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      41,  -119,  -119,   -30,   -54,    20,    19,    -1,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   -26,   -16,  -119,  -119,  -119,
    -119,  -119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    11,    12,    20,    21,    42,    68,    40,    71,
      72,    13,    23,    24,    47,    45,    97,    62,   124,   194,
      25,    34,    86,    56,    37,    88,    98,   158,   172,   189,
     182,   183,   192,   198,   200,   202,   132,   151,   168,   152,
      91,   116,   139,    93,   118,   137,   145,   163,   169,   179,
     142,   174,   185,   125,   161,    89,    35,    14,    30,    15,
      16,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    54,    60,    38,    48,    79,   141,    43,   140,   110,
      85,   112,    63,    22,    55,    59,    36,    63,    57,    18,
      19,    57,   159,   -53,    32,    33,    32,    33,    81,    82,
     102,   103,   164,    26,    38,    27,    95,    96,   109,    32,
      33,   119,   120,    28,   100,   104,   177,   106,   107,   176,
     122,    29,   126,   127,    51,    52,   133,   101,   186,   108,
      31,   111,     2,     3,    39,     4,     5,     6,     7,     8,
       9,    10,    44,   148,    58,   128,    61,   129,   149,   150,
      64,    65,    66,    67,    75,    76,    77,    78,    41,    39,
      46,    44,   134,   135,    57,    84,    57,    49,    50,   143,
      51,    52,    69,    70,   165,   166,   180,   181,   190,   191,
      41,   155,   196,   197,    46,    87,    90,    92,   123,    99,
      94,    85,   113,   105,   115,   114,   117,   170,   153,   136,
     130,   173,   131,   144,   138,   175,   157,   160,   184,   121,
     -81,   156,   162,   167,   178,   187,   188,   146,   193,    80,
     147,   199,   201,   171,   154,     0,     0,     0,    73,     0,
       0,     0,   195,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
      26,    27,    37,    19,    24,    47,   124,    21,   122,    81,
      18,    83,    39,    31,    30,    36,    23,    44,    34,    12,
      13,    37,   140,    31,    33,    34,    33,    34,    49,    23,
      72,    73,   146,    33,    50,    33,    66,    67,    80,    33,
      34,    95,    96,    33,    70,    75,   164,    77,    78,   163,
     104,    33,   106,   107,    31,    32,    33,    71,   176,    79,
      31,    82,     0,     1,    11,     3,     4,     5,     6,     7,
       8,     9,    11,    26,    31,   110,    24,   112,    31,    32,
      14,    15,    16,    17,    14,    15,    16,    17,    10,    11,
      10,    11,   118,   119,   110,    31,   112,    12,    13,   125,
      31,    32,    20,    21,    31,    32,    31,    32,    31,    32,
      10,   137,    31,    32,    10,    31,    27,    31,    19,    31,
      33,    18,    31,    33,    28,    33,    31,   153,    22,    31,
      33,   157,    25,    31,    29,   161,    25,    19,    19,    98,
      31,    33,    32,    31,    31,    31,    30,   127,    31,    48,
     129,    31,    31,   154,   135,    -1,    -1,    -1,    43,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    37,    38,    46,    92,    94,    95,    96,    12,    13,
      39,    40,    31,    47,    48,    55,    33,    33,    33,    33,
      93,    31,    33,    34,    56,    91,    23,    59,    91,    11,
      43,    10,    41,    43,    11,    50,    10,    49,    50,    12,
      13,    31,    32,    90,    90,    91,    58,    91,    31,    56,
      58,    24,    52,    61,    14,    15,    16,    17,    42,    20,
      21,    44,    45,    41,    52,    14,    15,    16,    17,    44,
      49,    56,    23,    59,    31,    18,    57,    31,    60,    90,
      27,    75,    31,    78,    33,    78,    78,    51,    61,    31,
      90,    43,    44,    44,    78,    33,    78,    78,    50,    44,
      57,    56,    57,    31,    33,    28,    76,    31,    79,    79,
      79,    75,    79,    19,    53,    88,    79,    79,    58,    58,
      33,    25,    71,    33,    90,    90,    31,    80,    29,    77,
      53,    51,    85,    90,    31,    81,    80,    60,    26,    31,
      32,    72,    74,    22,    81,    90,    33,    25,    62,    51,
      19,    89,    32,    82,    53,    31,    32,    31,    73,    83,
      90,    82,    63,    90,    86,    90,    53,    51,    31,    84,
      31,    32,    65,    66,    19,    87,    51,    31,    30,    64,
      31,    32,    67,    31,    54,    90,    31,    32,    68,    31,
      69,    31,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    37,    38,    38,    38,    38,    38,    39,    40,    40,
      40,    41,    42,    42,    42,    42,    42,    42,    43,    44,
      44,    45,    45,    46,    46,    46,    46,    46,    47,    48,
      48,    49,    49,    49,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    57,    58,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    71,    71,    71,    71,
      72,    72,    73,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    79,    80,    81,    82,    83,    84,    84,
      85,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    93,    94,    95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     3,     3,     5,     5,     3,     3,     5,
       4,     3,     4,     6,     4,     2,     6,     5,     2,     2,
       0,     2,     2,     4,     3,     3,     5,     5,     4,     5,
       6,     6,     5,     8,     7,     2,     4,     4,     6,     1,
       1,     2,     1,     0,     2,     1,     1,     0,     1,     0,
       4,     4,     0,     1,     2,     0,     5,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     0,
       1,     1,     1,     2,     2,     0,     2,     0,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     1,     3,     1,     3,     4,     2
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
  case 2: /* program: program command  */
#line 240 "unix/tg_parser.y"
                                { if (action) { traffgen->addActionHousekeeping( *action ); traffgen->addAction( *action ); } cleanup(); }
#line 1498 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 4: /* command: flow_command  */
#line 245 "unix/tg_parser.y"
                                { traffgen->addFlowHousekeeping( *flow ); }
#line 1504 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 5: /* command: flowset_command  */
#line 246 "unix/tg_parser.y"
                                { finishFlowset(); }
#line 1510 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 10: /* command: SEED INTEGER  */
#line 251 "unix/tg_parser.y"
                                { traffgen->setRandomSeed( yy_int ); }
#line 1516 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 11: /* command: error  */
#line 252 "unix/tg_parser.y"
                                { if (syntaxError) yyerror("error"); else syntaxError = true; }
#line 1522 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 17: /* ext_flow_descr: TCP SERVER local  */
#line 264 "unix/tg_parser.y"
                                                { flow = new TcpServer( localAddr.rawAddress(), localPort ); }
#line 1528 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 18: /* flow_descr: UDP local remote  */
#line 268 "unix/tg_parser.y"
                                                { flow = new UdpFlow( localAddr.rawAddress(), localPort, remoteAddr.rawAddress(), remotePort ); }
#line 1534 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 19: /* flow_descr: UDP local remote map INTEGER  */
#line 269 "unix/tg_parser.y"
                                                { flow = new UdpFlow( localAddr.rawAddress(), localPort, remoteAddr.rawAddress(), remotePort, yy_int ); }
#line 1540 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 20: /* flow_descr: TCP local_addr remote connect_time  */
#line 270 "unix/tg_parser.y"
                                                { flow = new TcpFlow( localAddr.rawAddress(), remoteAddr.rawAddress(), remotePort, connectTime ); }
#line 1546 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 21: /* flow_send: SEND sendertype send_conf  */
#line 274 "unix/tg_parser.y"
                                                        { doSendFlow(); }
#line 1552 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 22: /* sendertype: CBR packetsize packetrate timeval  */
#line 278 "unix/tg_parser.y"
                                                        { action = new CbrSender( *flow, packetSize, packetRate, yy_timeval ); }
#line 1558 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 23: /* sendertype: CBR packetsize packetrate timeval VARY vary  */
#line 279 "unix/tg_parser.y"
                                                        { cbrTime = yy_timeval; createCbrVariation(); }
#line 1564 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 24: /* sendertype: CBR packetsize packetrate STRING  */
#line 280 "unix/tg_parser.y"
                                                        { action = new CbrSender( *flow, packetSize, packetRate, yy_string ); }
#line 1570 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 25: /* sendertype: TRACE STRING  */
#line 281 "unix/tg_parser.y"
                                                        { action = new TraceSender( *flow, yy_string ); }
#line 1576 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 26: /* sendertype: PARETO packetsize packetrate timeval srccount hurst  */
#line 282 "unix/tg_parser.y"
                                                                { action = new ParetoSender( *flow, packetSize, packetRate, yy_timeval, sourceCount, hurstParameter ); }
#line 1582 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 27: /* sendertype: GREEDY packetsize packetrate totalsize timeval  */
#line 283 "unix/tg_parser.y"
                                                         { action = new GreedySender( *flow, packetSize, packetRate, totalSize, yy_timeval ); }
#line 1588 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 28: /* flow_recv: RECV recv_conf  */
#line 287 "unix/tg_parser.y"
                                { doReceiveFlow(); }
#line 1594 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 31: /* add_action: REPEAT INTEGER  */
#line 296 "unix/tg_parser.y"
                                { assert(action); ActionObject* saveAction = action; action = new RepeatAction( *saveAction, yy_int ); traffgen->addActionHousekeeping( *saveAction ); }
#line 1600 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 32: /* add_action: AT timeval  */
#line 297 "unix/tg_parser.y"
                                { assert(action); ActionObject* saveAction = action; action = new DelayAction( *saveAction, yy_timeval ); traffgen->addActionHousekeeping( *saveAction ); }
#line 1606 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 38: /* ext_flowset_descr: flowcount TCP SERVER local  */
#line 309 "unix/tg_parser.y"
                                                                { flowType = tg_TCP_Server; doCreateFlowset(); }
#line 1612 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 39: /* flowset_descr: flowcount UDP local map remote  */
#line 313 "unix/tg_parser.y"
                                                                { flowType = tg_UDP; doCreateFlowset(); }
#line 1618 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 40: /* flowset_descr: flowcount TCP local_addr map remote connect_time  */
#line 314 "unix/tg_parser.y"
                                                                { flowType = tg_TCP; doCreateFlowset(); }
#line 1624 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 41: /* flowset_send: SEND CBR packetsize packetrate fs_conf send_conf  */
#line 318 "unix/tg_parser.y"
                                                                                { senderType = tg_CBR; doSendFlowset(); }
#line 1630 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 42: /* flowset_send: SEND TRACE STRING fs_conf send_conf  */
#line 319 "unix/tg_parser.y"
                                                                                { senderType = tg_TRACE; doSendFlowset(); }
#line 1636 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 43: /* flowset_send: SEND PARETO packetsize packetrate srccount hurst fs_conf send_conf  */
#line 320 "unix/tg_parser.y"
                                                                                { senderType = tg_PARETO; doSendFlowset(); }
#line 1642 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 44: /* flowset_send: SEND GREEDY packetsize packetrate totalsize fs_conf send_conf  */
#line 321 "unix/tg_parser.y"
                                                                                                { senderType = tg_GREEDY; doSendFlowset(); }
#line 1648 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 45: /* flowset_recv: RECV recv_conf  */
#line 325 "unix/tg_parser.y"
                        { doReceiveFlowset(); }
#line 1654 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 46: /* send_conf: stamp rate_estimator pcounter rsvp_send  */
#line 329 "unix/tg_parser.y"
                                                { delayCounter = NULL; }
#line 1660 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 47: /* recv_conf: stamp rate_estimator dcounter rsvp_recv  */
#line 333 "unix/tg_parser.y"
                                                { packetCounter = NULL; }
#line 1666 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 49: /* create_count: INTEGER  */
#line 341 "unix/tg_parser.y"
                                { createCount = yy_int; }
#line 1672 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 50: /* flowcount: INTEGER  */
#line 345 "unix/tg_parser.y"
                                { flowCount = yy_int; }
#line 1678 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 51: /* local: ip_address INTEGER  */
#line 349 "unix/tg_parser.y"
                                { localAddr = yy_ip_address; localPort = yy_int; if ( !checkLocalAddress() ) YYERROR; }
#line 1684 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 52: /* map: MAP  */
#line 353 "unix/tg_parser.y"
                                { flowMapping = true; }
#line 1690 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 53: /* map: %empty  */
#line 354 "unix/tg_parser.y"
                                { flowMapping = false; }
#line 1696 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 54: /* remote: ip_address INTEGER  */
#line 358 "unix/tg_parser.y"
                                { remoteAddr = yy_ip_address; remotePort = yy_int; }
#line 1702 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 55: /* local_addr: ip_address  */
#line 362 "unix/tg_parser.y"
                                { localAddr = yy_ip_address; if ( !checkLocalAddress() ) YYERROR; }
#line 1708 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 56: /* connect_time: timeval  */
#line 366 "unix/tg_parser.y"
                                { connectTime = yy_timeval; }
#line 1714 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 57: /* connect_time: %empty  */
#line 367 "unix/tg_parser.y"
                                { connectTime = TimeValue(0,0); }
#line 1720 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 58: /* stamp: STAMP  */
#line 371 "unix/tg_parser.y"
                                { stamp = true; }
#line 1726 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 59: /* stamp: %empty  */
#line 372 "unix/tg_parser.y"
                                { stamp = false; }
#line 1732 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 60: /* rsvp_send: RSVP_S rsvpwait tspec sync  */
#line 376 "unix/tg_parser.y"
                                        { rsvp = true; }
#line 1738 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 61: /* rsvp_send: RSVP_S rsvpwait tspec SYNC  */
#line 377 "unix/tg_parser.y"
                                        { rsvp = true; rsvpSyncBackoffTime = TimeValue(0,0); }
#line 1744 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 62: /* rsvp_send: %empty  */
#line 378 "unix/tg_parser.y"
                                        { rsvp = false; }
#line 1750 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 63: /* rsvpwait: timeval  */
#line 382 "unix/tg_parser.y"
                        { rsvpSignalWaitTime = yy_timeval; }
#line 1756 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 64: /* sync: SYNC timeval  */
#line 386 "unix/tg_parser.y"
                        { rsvpSyncBackoffTime = yy_timeval; }
#line 1762 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 65: /* sync: %empty  */
#line 387 "unix/tg_parser.y"
                        { rsvpSyncBackoffTime = TimeValue(-1,-1); }
#line 1768 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 67: /* tspec: %empty  */
#line 392 "unix/tg_parser.y"
                                { TSpec x; tspec = x; }
#line 1774 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 68: /* avg: FLOAT  */
#line 396 "unix/tg_parser.y"
                        { tspec.set_r(yy_float); }
#line 1780 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 69: /* avg: INTEGER  */
#line 397 "unix/tg_parser.y"
                        { tspec.set_r(yy_int); }
#line 1786 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 70: /* depth: FLOAT  */
#line 401 "unix/tg_parser.y"
                        { tspec.set_b(yy_float); }
#line 1792 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 71: /* depth: INTEGER  */
#line 402 "unix/tg_parser.y"
                        { tspec.set_b(yy_int); }
#line 1798 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 72: /* peak: FLOAT  */
#line 406 "unix/tg_parser.y"
                        { tspec.set_p(yy_float); }
#line 1804 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 73: /* peak: INTEGER  */
#line 407 "unix/tg_parser.y"
                        { tspec.set_p(yy_int); }
#line 1810 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 74: /* min: INTEGER  */
#line 411 "unix/tg_parser.y"
                        { tspec.set_m(yy_int); }
#line 1816 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 75: /* MTU: INTEGER  */
#line 415 "unix/tg_parser.y"
                        { tspec.set_M(yy_int); }
#line 1822 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 76: /* rsvp_recv: RSVP_S rate slack  */
#line 419 "unix/tg_parser.y"
                                { rsvp = true; wtpFactor = 1.0; }
#line 1828 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 77: /* rsvp_recv: RSVP_S INTEGER  */
#line 420 "unix/tg_parser.y"
                                { rsvp = true; wtpFactor = 1.0; rspec.set_R(0); rspec.set_S(yy_int); }
#line 1834 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 78: /* rsvp_recv: RSVP_S wtp  */
#line 421 "unix/tg_parser.y"
                                { rsvp = true; rspec.set_R(0); rspec.set_S(0); }
#line 1840 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 79: /* rsvp_recv: %empty  */
#line 422 "unix/tg_parser.y"
                                { rsvp = false; }
#line 1846 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 80: /* rate: FLOAT  */
#line 426 "unix/tg_parser.y"
                        { rspec.set_R(yy_float); }
#line 1852 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 81: /* rate: INTEGER  */
#line 427 "unix/tg_parser.y"
                        { rspec.set_R(yy_int); }
#line 1858 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 82: /* slack: INTEGER  */
#line 431 "unix/tg_parser.y"
                        { rspec.set_S(yy_int); }
#line 1864 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 83: /* wtp: WTP FLOAT  */
#line 435 "unix/tg_parser.y"
                        { wtpFactor = yy_float; }
#line 1870 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 84: /* wtp: WTP INTEGER  */
#line 436 "unix/tg_parser.y"
                        { wtpFactor = yy_int; }
#line 1876 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 85: /* wtp: %empty  */
#line 437 "unix/tg_parser.y"
                        { wtpFactor = 1.0; }
#line 1882 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 86: /* rate_estimator: RATE STRING  */
#line 441 "unix/tg_parser.y"
                        { rateEstimator = (RateEstimator*)findSummaryObject( yy_string ); }
#line 1888 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 87: /* rate_estimator: %empty  */
#line 442 "unix/tg_parser.y"
                        { rateEstimator = NULL; }
#line 1894 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 88: /* dcounter: DELAY STRING  */
#line 446 "unix/tg_parser.y"
                        { delayCounter = (DelayCounter*)findSummaryObject( yy_string ); }
#line 1900 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 89: /* dcounter: %empty  */
#line 447 "unix/tg_parser.y"
                        { delayCounter = NULL; }
#line 1906 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 90: /* pcounter: PACKETS STRING  */
#line 451 "unix/tg_parser.y"
                        { packetCounter = (PacketCounter*)findSummaryObject( yy_string ); }
#line 1912 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 91: /* pcounter: %empty  */
#line 452 "unix/tg_parser.y"
                        { packetCounter = NULL; }
#line 1918 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 92: /* packetsize: INTEGER  */
#line 456 "unix/tg_parser.y"
                                { packetSize = yy_int; }
#line 1924 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 93: /* packetrate: INTEGER  */
#line 460 "unix/tg_parser.y"
                                { packetRate = yy_int; }
#line 1930 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 94: /* totalsize: INTEGER  */
#line 464 "unix/tg_parser.y"
                                { totalSize = yy_int; }
#line 1936 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 95: /* srccount: INTEGER  */
#line 468 "unix/tg_parser.y"
                                { sourceCount = yy_int; }
#line 1942 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 96: /* hurst: FLOAT  */
#line 472 "unix/tg_parser.y"
                                { hurstParameter = yy_float; }
#line 1948 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 97: /* vary: timeval variation  */
#line 476 "unix/tg_parser.y"
                                { varTime = yy_timeval; }
#line 1954 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 98: /* variation: variation INTEGER  */
#line 480 "unix/tg_parser.y"
                                { varList.push_back( yy_int ); }
#line 1960 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 99: /* variation: INTEGER  */
#line 481 "unix/tg_parser.y"
                                { varList.push_back( yy_int ); }
#line 1966 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 100: /* arrival: timeval  */
#line 485 "unix/tg_parser.y"
                                { flowArrival = yy_timeval; }
#line 1972 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 101: /* duration: timeval  */
#line 489 "unix/tg_parser.y"
                                { flowDuration = yy_timeval; }
#line 1978 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 102: /* fixed: FIXED  */
#line 493 "unix/tg_parser.y"
                                { fixedArrival = fixedDuration = true; }
#line 1984 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 104: /* fixed_a: FIXED  */
#line 498 "unix/tg_parser.y"
                                { fixedArrival = true; }
#line 1990 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 105: /* fixed_a: %empty  */
#line 499 "unix/tg_parser.y"
                                { fixedArrival = false; }
#line 1996 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 106: /* fixed_d: FIXED  */
#line 503 "unix/tg_parser.y"
                                { fixedDuration = true; }
#line 2002 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 107: /* fixed_d: %empty  */
#line 504 "unix/tg_parser.y"
                                { fixedDuration = false; }
#line 2008 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 108: /* timeval: INTEGER  */
#line 508 "unix/tg_parser.y"
                                { yy_timeval = TimeValue(yy_int,0); }
#line 2014 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 109: /* timeval: FLOAT  */
#line 509 "unix/tg_parser.y"
                                { yy_timeval.getFromFraction(yy_float); }
#line 2020 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 110: /* ip_address: IP_ADDRESS  */
#line 513 "unix/tg_parser.y"
                                { yy_ip_address = yy_string; }
#line 2026 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 111: /* ip_address: STRING  */
#line 514 "unix/tg_parser.y"
                                { findAlias( yy_string ); }
#line 2032 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 112: /* alias_command: ALIAS name ip_address  */
#line 518 "unix/tg_parser.y"
                                { aliasList.push_back( Alias(yy_name,yy_ip_address) ); }
#line 2038 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 113: /* name: STRING  */
#line 522 "unix/tg_parser.y"
                                { yy_name = yy_string; }
#line 2044 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 114: /* estimator_command: ESTIMATOR STRING timeval  */
#line 526 "unix/tg_parser.y"
                                        { createSummaryObject( *new RateEstimator( yy_timeval, yy_string ) ); }
#line 2050 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 115: /* dcounter_command: DCOUNTER STRING timeval INTEGER  */
#line 530 "unix/tg_parser.y"
                                        { createSummaryObject( *new DelayCounter( yy_timeval, yy_int, yy_string ) ); }
#line 2056 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;

  case 116: /* pcounter_command: PCOUNTER STRING  */
#line 534 "unix/tg_parser.y"
                                        { createSummaryObject( *new PacketCounter( yy_string ) ); }
#line 2062 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"
    break;


#line 2066 "/root/DRAGON/dragon-sw/kom-rsvp/gen/clients/tg_parser.tab.c"

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

#line 537 "unix/tg_parser.y"


void yyerror(const char *s) {
	cerr << s << " in config file: " << configfile << " in line " << yylineno << endl;
	fatalError = true;
}

bool tg_parser_parse( const String& filename, RSVP_API* rapi = NULL ) {
	configfile = filename.chars();
	api = rapi;
	yyin = fopen( filename.chars(), "r" );
	if ( !yyin ) {
		cerr << "ERROR: cannot access configuration file " << filename << endl;
		exit(1);
	} else {
		yyparse();
		fclose( yyin );
	}
	return !fatalError;
}
