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

#ifndef YY_YY_ROOT_DRAGON_DRAGON_SW_KOM_RSVP_GEN_CLIENTS_TG_PARSER_TAB_H_INCLUDED
# define YY_YY_ROOT_DRAGON_DRAGON_SW_KOM_RSVP_GEN_CLIENTS_TG_PARSER_TAB_H_INCLUDED
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
    FLOW = 258,                    /* FLOW  */
    FLOWSET = 259,                 /* FLOWSET  */
    ESTIMATOR = 260,               /* ESTIMATOR  */
    DCOUNTER = 261,                /* DCOUNTER  */
    PCOUNTER = 262,                /* PCOUNTER  */
    ALIAS = 263,                   /* ALIAS  */
    SEED = 264,                    /* SEED  */
    SEND = 265,                    /* SEND  */
    RECV = 266,                    /* RECV  */
    UDP = 267,                     /* UDP  */
    TCP = 268,                     /* TCP  */
    CBR = 269,                     /* CBR  */
    TRACE = 270,                   /* TRACE  */
    PARETO = 271,                  /* PARETO  */
    GREEDY = 272,                  /* GREEDY  */
    MAP = 273,                     /* MAP  */
    FIXED = 274,                   /* FIXED  */
    REPEAT = 275,                  /* REPEAT  */
    AT = 276,                      /* AT  */
    VARY = 277,                    /* VARY  */
    SERVER = 278,                  /* SERVER  */
    STAMP = 279,                   /* STAMP  */
    RSVP_S = 280,                  /* RSVP_S  */
    WTP = 281,                     /* WTP  */
    RATE = 282,                    /* RATE  */
    DELAY = 283,                   /* DELAY  */
    PACKETS = 284,                 /* PACKETS  */
    SYNC = 285,                    /* SYNC  */
    INTEGER = 286,                 /* INTEGER  */
    FLOAT = 287,                   /* FLOAT  */
    STRING = 288,                  /* STRING  */
    IP_ADDRESS = 289               /* IP_ADDRESS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define FLOW 258
#define FLOWSET 259
#define ESTIMATOR 260
#define DCOUNTER 261
#define PCOUNTER 262
#define ALIAS 263
#define SEED 264
#define SEND 265
#define RECV 266
#define UDP 267
#define TCP 268
#define CBR 269
#define TRACE 270
#define PARETO 271
#define GREEDY 272
#define MAP 273
#define FIXED 274
#define REPEAT 275
#define AT 276
#define VARY 277
#define SERVER 278
#define STAMP 279
#define RSVP_S 280
#define WTP 281
#define RATE 282
#define DELAY 283
#define PACKETS 284
#define SYNC 285
#define INTEGER 286
#define FLOAT 287
#define STRING 288
#define IP_ADDRESS 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ROOT_DRAGON_DRAGON_SW_KOM_RSVP_GEN_CLIENTS_TG_PARSER_TAB_H_INCLUDED  */
