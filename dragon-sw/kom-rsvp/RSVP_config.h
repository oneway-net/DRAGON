/* RSVP_config.h.  Generated from RSVP_config.h.in by configure.  */
/* RSVP_config.h.in.  Generated from configure.in by autoheader.  */
#ifndef _RSVP_config_h_
#define _RSVP_config_h_ 1

/* size of label hash container for MPLS */
#define LABEL_HASH_COUNT 65536

/* size of message id hash container for refresh reduction */
#define MESSAGE_ID_HASH_COUNT_SEND 131072

/* size of message id hash container for refresh reduction */
#define MESSAGE_ID_HASH_COUNT_RECV 131072

/* size of api hash container -> useful for large tests with few end systems */
#define API_HASH_COUNT 1

/* size of session hash container */
#define SESSION_HASH_COUNT 4096

/* define to include dest port number into hash calculation
   note: this is useful for certain tests, but prohibits 100%-correct RSVP */
/* #undef SESSION_HASH_PORTS */

/* default total period which is covered by timer wheel */
#define TIMER_SLOT_TOTAL_PERIOD 600

#define MPLS_REAL	(defined(ENABLE_MPLS) && (defined(MPLS_WISCONSIN) || defined(MPLS_CAMBRIDGE)))

/* #undef ALTQ_DEVICE */
/* #undef CBQ_DEVICE */
/* #undef ENABLE_ALTQ */
#define ENABLE_CBQ 1
/* #undef ENABLE_MPLS */
#define ENABLE_SNMP 1
/* #undef FIXED_TIMEOUTS */
/* #undef FUZZY_TIMERS */
#define GETSOCKOPT_SIZE_T socklen_t
#define GETSOCKNAME_SIZE_T socklen_t
/* #undef HAVE_KLD */
/* #undef HAVE_SIN_LEN */
/* #undef HFSC_DEVICE */
#define HTONS_IP_HEADER 1
#define INVERSE_DNS 1
/* #undef MPLS_WISCONSIN */
/* #undef MPLS_CAMBRIDGE */
/* #undef NEED_IN_PKTINFO */
/* #undef NEED_MULTICAST_TTL */
/* #undef NEED_RA_SOCKOPT */
/* #undef NEED_UNICAST_TTL */
/* #undef NO_TIMERS */
#define ONEPASS_RESERVATION 1
#define PIDFILE "/var/run/RSVPD.pid"
#define REAL_NETWORK 1
#define SO_REUSEXXX SO_REUSEPORT
#define REFRESH_REDUCTION 1
#define RSRR_SERV_PATH "/tmp/.rsrr_svr"
#define RSRR_CLI_PATH "/tmp/.rsrr_cli"
#define RSVP_MEMORY_MACHINE 1
#define RSVP_STATS 1
#define RECVFROM_BUF_T void*
#define RECVFROM_SIZE_T socklen_t
#define RSVP_CHECKS 1
#define SENDTO_BUF_T const void*
/* #undef STAMP_DEVICE */
#define USE_SCOPE_OBJECT 1
/* #undef VIRT_NETWORK */
#define WITH_API 1
/* #undef WITH_JAVA_API */

#define Linux 1
/* #undef FreeBSD */
/* #undef SunOS */
/* #undef Darwin */

#define FATAL_ON 1
#define ERROR_ON 1
#define CHECK_ON 1
#define LOG_ON 1
/* #undef NDEBUG */

#if !defined(REAL_NETWORK) && !defined(VIRT_NETWORK)
#define NS2	1
#endif



/* Define to 1 if you have the `inet_aton' function. */
#define HAVE_INET_ATON 1

/* Define to 1 if you have the `inet_ntop' function. */
#define HAVE_INET_NTOP 1

/* Define to 1 if you have the `inet_pton' function. */
#define HAVE_INET_PTON 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the `pthreads' library (-lpthreads). */
/* #undef HAVE_LIBPTHREADS */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mpls_init' function. */
/* #undef HAVE_MPLS_INIT */

/* Define to 1 if you have the <pthreads.h> header file. */
/* #undef HAVE_PTHREADS_H */

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the `rtnl_open' function. */
/* #undef HAVE_RTNL_OPEN */

/* Define to 1 if you have the <sstream> header file. */
#define HAVE_SSTREAM 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the address where bug reports for this package should be sent. */
// #undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
// #undef PACKAGE_NAME

/* Define to the full name and version of this package. */
// #undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
// #undef PACKAGE_TARNAME

/* Define to the version of this package. */
// #undef PACKAGE_VERSION

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* DRAGON VLSR-specific options follow */

/* Define switch vendor/model number for VLSR control */
#define SWITCH_VENDOR_MODEL AutoDetect

/* Define the default VLSR switch control port to avoid loss of management 
   connectivity to the switch. */
#define SWITCH_CTRL_PORT 255

/* Define the default SNMP community string to control switch */
#define SWITCH_SNMP_COMMUNITY "dragon"

/* Define a flag to indicator that the VLSR switch is using Force10 App Software Version 6.2.1.x */
/* #undef FORCE10_SOFTWARE_V6 */

/* Define CLI session type for VLSR control */
#define CLI_SESSION_TYPE CLI_NONE

/* Define CLI username and password for VLSR access to the switch */
#define CLI_USERNAME "unknown"
#define CLI_PASSWORD "unknown"
#define CLI_ENABPASS ""

/* Define TL1 session type for VLSR control */
#define TL1_SESSION_TYPE TL1_NONE

/* Define TL1 username and password for VLSR access to the switch */
#define TL1_USERNAME "unknown"
#define TL1_PASSWORD "unknown"

/* If this option is defined, enable VLSR switch port shutdown operations 
   (currently used only for Force10 switches) */
/* #undef ENABLE_SWITCH_PORT_SHUTDOWN */

/* Define external commands paths */
#define VCONFIG_PATH "/usr/sbin/vconfig"
#define BRCTL_PATH "/usr/sbin/brctl"
#define EXPECT_PATH "/usr/local/bin/expect"

#endif /* _RSVP_config_h_ */
