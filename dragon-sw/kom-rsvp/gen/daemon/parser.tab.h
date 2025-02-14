/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ROOT_DRAGON_DRAGON_SW_KOM_RSVP_GEN_DAEMON_PARSER_TAB_H_INCLUDED
# define YY_YY_ROOT_DRAGON_DRAGON_SW_KOM_RSVP_GEN_DAEMON_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    STRING = 260,                  /* STRING  */
    IP_ADDRESS = 261,              /* IP_ADDRESS  */
    INTERFACE = 262,               /* INTERFACE  */
    API_C = 263,                   /* API_C  */
    ROUTE = 264,                   /* ROUTE  */
    REFRESH = 265,                 /* REFRESH  */
    ENCAP = 266,                   /* ENCAP  */
    VIRT = 267,                    /* VIRT  */
    DISABLE = 268,                 /* DISABLE  */
    RAPID = 269,                   /* RAPID  */
    LOSS = 270,                    /* LOSS  */
    TC_C = 271,                    /* TC_C  */
    NONE = 272,                    /* NONE  */
    CBQ_C = 273,                   /* CBQ_C  */
    HFSC_C = 274,                  /* HFSC_C  */
    RATE = 275,                    /* RATE  */
    PEER = 276,                    /* PEER  */
    TIMER = 277,                   /* TIMER  */
    SESSION_HASH = 278,            /* SESSION_HASH  */
    API_HASH = 279,                /* API_HASH  */
    ID_HASH_SEND = 280,            /* ID_HASH_SEND  */
    ID_HASH_RECV = 281,            /* ID_HASH_RECV  */
    LIST_ALLOC = 282,              /* LIST_ALLOC  */
    SB_ALLOC = 283,                /* SB_ALLOC  */
    EXPLICIT_ROUTE_ = 284,         /* EXPLICIT_ROUTE_  */
    MPLS_C = 285,                  /* MPLS_C  */
    NOMPLS = 286,                  /* NOMPLS  */
    MPLS_ALL = 287,                /* MPLS_ALL  */
    NOMPLS_ALL = 288,              /* NOMPLS_ALL  */
    LABEL_HASH = 289,              /* LABEL_HASH  */
    LOCAL_ID = 290,                /* LOCAL_ID  */
    UPSTREAM_LABEL_ = 291,         /* UPSTREAM_LABEL_  */
    INTEGER_RANGE = 292,           /* INTEGER_RANGE  */
    NARB = 293,                    /* NARB  */
    SLOTS = 294,                   /* SLOTS  */
    SLOT = 295,                    /* SLOT  */
    EXCLUDE = 296,                 /* EXCLUDE  */
    NARB_EXTRA_OPTIONS = 297,      /* NARB_EXTRA_OPTIONS  */
    NARB_VTAGS_ALLOWED = 298,      /* NARB_VTAGS_ALLOWED  */
    EOS_MAP = 299,                 /* EOS_MAP  */
    VLAN_OPTIONS = 300             /* VLAN_OPTIONS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define FLOAT 259
#define STRING 260
#define IP_ADDRESS 261
#define INTERFACE 262
#define API_C 263
#define ROUTE 264
#define REFRESH 265
#define ENCAP 266
#define VIRT 267
#define DISABLE 268
#define RAPID 269
#define LOSS 270
#define TC_C 271
#define NONE 272
#define CBQ_C 273
#define HFSC_C 274
#define RATE 275
#define PEER 276
#define TIMER 277
#define SESSION_HASH 278
#define API_HASH 279
#define ID_HASH_SEND 280
#define ID_HASH_RECV 281
#define LIST_ALLOC 282
#define SB_ALLOC 283
#define EXPLICIT_ROUTE_ 284
#define MPLS_C 285
#define NOMPLS 286
#define MPLS_ALL 287
#define NOMPLS_ALL 288
#define LABEL_HASH 289
#define LOCAL_ID 290
#define UPSTREAM_LABEL_ 291
#define INTEGER_RANGE 292
#define NARB 293
#define SLOTS 294
#define SLOT 295
#define EXCLUDE 296
#define NARB_EXTRA_OPTIONS 297
#define NARB_VTAGS_ALLOWED 298
#define EOS_MAP 299
#define VLAN_OPTIONS 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ROOT_DRAGON_DRAGON_SW_KOM_RSVP_GEN_DAEMON_PARSER_TAB_H_INCLUDED  */
