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

#ifndef YY_YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser/parser.y"

#include "../ast/ast.h"

#line 53 "parser/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 258,               /* TOKEN_INT  */
    TOKEN_FLOAT = 259,             /* TOKEN_FLOAT  */
    TOKEN_DOUBLE = 260,            /* TOKEN_DOUBLE  */
    TOKEN_CHAR = 261,              /* TOKEN_CHAR  */
    TOKEN_BOOL = 262,              /* TOKEN_BOOL  */
    TOKEN_STRING = 263,            /* TOKEN_STRING  */
    TOKEN_LONG = 264,              /* TOKEN_LONG  */
    TOKEN_SHORT = 265,             /* TOKEN_SHORT  */
    TOKEN_UNSIGNED = 266,          /* TOKEN_UNSIGNED  */
    TOKEN_SIGNED = 267,            /* TOKEN_SIGNED  */
    TOKEN_AUTO = 268,              /* TOKEN_AUTO  */
    TOKEN_VOID = 269,              /* TOKEN_VOID  */
    TOKEN_INCLUDE = 270,           /* TOKEN_INCLUDE  */
    TOKEN_USING = 271,             /* TOKEN_USING  */
    TOKEN_NAMESPACE = 272,         /* TOKEN_NAMESPACE  */
    TOKEN_COUT = 273,              /* TOKEN_COUT  */
    TOKEN_CIN = 274,               /* TOKEN_CIN  */
    TOKEN_ENDL = 275,              /* TOKEN_ENDL  */
    TOKEN_RETURN = 276,            /* TOKEN_RETURN  */
    TOKEN_IF = 277,                /* TOKEN_IF  */
    TOKEN_ELSE = 278,              /* TOKEN_ELSE  */
    TOKEN_WHILE = 279,             /* TOKEN_WHILE  */
    TOKEN_FOR = 280,               /* TOKEN_FOR  */
    TOKEN_BREAK = 281,             /* TOKEN_BREAK  */
    TOKEN_COMMA = 282,             /* TOKEN_COMMA  */
    TOKEN_SEMICOLON = 283,         /* TOKEN_SEMICOLON  */
    TOKEN_LPAREN = 284,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 285,            /* TOKEN_RPAREN  */
    TOKEN_LBRACE = 286,            /* TOKEN_LBRACE  */
    TOKEN_RBRACE = 287,            /* TOKEN_RBRACE  */
    TOKEN_HASH = 288,              /* TOKEN_HASH  */
    TOKEN_LT = 289,                /* TOKEN_LT  */
    TOKEN_GT = 290,                /* TOKEN_GT  */
    TOKEN_SHIFT_L = 291,           /* TOKEN_SHIFT_L  */
    TOKEN_SHIFT_R = 292,           /* TOKEN_SHIFT_R  */
    TOKEN_DOUBLE_COLON = 293,      /* TOKEN_DOUBLE_COLON  */
    TOKEN_DOUBLE_QUOTES = 294,     /* TOKEN_DOUBLE_QUOTES  */
    TOKEN_SINGLE_QUOTES = 295,     /* TOKEN_SINGLE_QUOTES  */
    TOKEN_EQ = 296,                /* TOKEN_EQ  */
    TOKEN_NEQ = 297,               /* TOKEN_NEQ  */
    TOKEN_LEQ = 298,               /* TOKEN_LEQ  */
    TOKEN_GEQ = 299,               /* TOKEN_GEQ  */
    TOKEN_AND = 300,               /* TOKEN_AND  */
    TOKEN_OR = 301,                /* TOKEN_OR  */
    TOKEN_ASSIGN = 302,            /* TOKEN_ASSIGN  */
    TOKEN_PLUS = 303,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 304,             /* TOKEN_MINUS  */
    TOKEN_MUL = 305,               /* TOKEN_MUL  */
    TOKEN_DIV = 306,               /* TOKEN_DIV  */
    TOKEN_MOD = 307,               /* TOKEN_MOD  */
    TOKEN_NUMBER = 308,            /* TOKEN_NUMBER  */
    TOKEN_BOOL_LITERAL = 309,      /* TOKEN_BOOL_LITERAL  */
    TOKEN_ID = 310,                /* TOKEN_ID  */
    TOKEN_STRING_LITERAL = 311,    /* TOKEN_STRING_LITERAL  */
    TOKEN_ERROR = 312              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser/parser.y"

    int v_int;           
    float v_float;      
    double v_double;  
    char v_char;
    int v_bool;   
    char *v_string;    
    long v_long;
    short v_short;    
    unsigned v_unsigned;  
    signed v_signed;
    NoAST *no; 

#line 141 "parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
