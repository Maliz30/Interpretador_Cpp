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
#line 4 "parser/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../ast/ast.h"

int yylex(void);
void yyerror(const char *s);

// Variável global para a raiz da AST
NoAST *raiz_ast = NULL;

#line 85 "parser/parser.tab.c"

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
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 4,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_DOUBLE = 5,               /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_CHAR = 6,                 /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOL = 7,                 /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 8,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_LONG = 9,                 /* TOKEN_LONG  */
  YYSYMBOL_TOKEN_SHORT = 10,               /* TOKEN_SHORT  */
  YYSYMBOL_TOKEN_UNSIGNED = 11,            /* TOKEN_UNSIGNED  */
  YYSYMBOL_TOKEN_SIGNED = 12,              /* TOKEN_SIGNED  */
  YYSYMBOL_TOKEN_AUTO = 13,                /* TOKEN_AUTO  */
  YYSYMBOL_TOKEN_VOID = 14,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_INCLUDE = 15,             /* TOKEN_INCLUDE  */
  YYSYMBOL_TOKEN_USING = 16,               /* TOKEN_USING  */
  YYSYMBOL_TOKEN_NAMESPACE = 17,           /* TOKEN_NAMESPACE  */
  YYSYMBOL_TOKEN_COUT = 18,                /* TOKEN_COUT  */
  YYSYMBOL_TOKEN_CIN = 19,                 /* TOKEN_CIN  */
  YYSYMBOL_TOKEN_ENDL = 20,                /* TOKEN_ENDL  */
  YYSYMBOL_TOKEN_RETURN = 21,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_IF = 22,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 23,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 24,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_FOR = 25,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_BREAK = 26,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_COMMA = 27,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_SEMICOLON = 28,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_LPAREN = 29,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 30,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LBRACE = 31,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_RBRACE = 32,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_HASH = 33,                /* TOKEN_HASH  */
  YYSYMBOL_TOKEN_LT = 34,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_GT = 35,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_SHIFT_L = 36,             /* TOKEN_SHIFT_L  */
  YYSYMBOL_TOKEN_SHIFT_R = 37,             /* TOKEN_SHIFT_R  */
  YYSYMBOL_TOKEN_DOUBLE_COLON = 38,        /* TOKEN_DOUBLE_COLON  */
  YYSYMBOL_TOKEN_DOUBLE_QUOTES = 39,       /* TOKEN_DOUBLE_QUOTES  */
  YYSYMBOL_TOKEN_SINGLE_QUOTES = 40,       /* TOKEN_SINGLE_QUOTES  */
  YYSYMBOL_TOKEN_EQ = 41,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 42,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_LEQ = 43,                 /* TOKEN_LEQ  */
  YYSYMBOL_TOKEN_GEQ = 44,                 /* TOKEN_GEQ  */
  YYSYMBOL_TOKEN_AND = 45,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 46,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_ASSIGN = 47,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_PLUS = 48,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 49,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MUL = 50,                 /* TOKEN_MUL  */
  YYSYMBOL_TOKEN_DIV = 51,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MOD = 52,                 /* TOKEN_MOD  */
  YYSYMBOL_TOKEN_NUMBER = 53,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_BOOL_LITERAL = 54,        /* TOKEN_BOOL_LITERAL  */
  YYSYMBOL_TOKEN_ID = 55,                  /* TOKEN_ID  */
  YYSYMBOL_TOKEN_STRING_LITERAL = 56,      /* TOKEN_STRING_LITERAL  */
  YYSYMBOL_TOKEN_ERROR = 57,               /* TOKEN_ERROR  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_programa = 59,                  /* programa  */
  YYSYMBOL_programa_declaracao = 60,       /* programa_declaracao  */
  YYSYMBOL_definicao_funcao = 61,          /* definicao_funcao  */
  YYSYMBOL_bloco_escopo = 62,              /* bloco_escopo  */
  YYSYMBOL_operacoes_possiveis = 63,       /* operacoes_possiveis  */
  YYSYMBOL_declaracao_funcao = 64,         /* declaracao_funcao  */
  YYSYMBOL_parametros_funcao = 65,         /* parametros_funcao  */
  YYSYMBOL_funcao_declaracao_parametro = 66, /* funcao_declaracao_parametro  */
  YYSYMBOL_while_loop = 67,                /* while_loop  */
  YYSYMBOL_for_loop = 68,                  /* for_loop  */
  YYSYMBOL_incremento = 69,                /* incremento  */
  YYSYMBOL_condicional_if = 70,            /* condicional_if  */
  YYSYMBOL_operacao_matematica_atribuicao_valor = 71, /* operacao_matematica_atribuicao_valor  */
  YYSYMBOL_operacao_matematica = 72,       /* operacao_matematica  */
  YYSYMBOL_operacao_relacional = 73,       /* operacao_relacional  */
  YYSYMBOL_operacao_relacional_tipos = 74, /* operacao_relacional_tipos  */
  YYSYMBOL_entrada_dados = 75,             /* entrada_dados  */
  YYSYMBOL_entrada_dados_parametros = 76,  /* entrada_dados_parametros  */
  YYSYMBOL_saida_dados = 77,               /* saida_dados  */
  YYSYMBOL_saida_dados_parametro = 78,     /* saida_dados_parametro  */
  YYSYMBOL_saida_dados_opcoes = 79,        /* saida_dados_opcoes  */
  YYSYMBOL_declaracao_variavel = 80,       /* declaracao_variavel  */
  YYSYMBOL_variavel = 81,                  /* variavel  */
  YYSYMBOL_tipagem = 82,                   /* tipagem  */
  YYSYMBOL_return = 83,                    /* return  */
  YYSYMBOL_declaracao_namespace = 84,      /* declaracao_namespace  */
  YYSYMBOL_chamada_biblioteca = 85         /* chamada_biblioteca  */
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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   128,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   154,   161,   162,   174,   175,   176,
     177,   178,   184,   190,   196,   202,   206,   212,   214,   218,
     219,   223,   230,   237,   238,   239,   240,   244,   247,   253,
     254,   255,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   283,   286,   289,   292,   298,   299,   300,
     301,   302,   303,   307,   314,   315,   319,   326,   327,   331,
     332,   333,   337,   346,   349,   352,   355,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   376,
     383,   390
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_FLOAT", "TOKEN_DOUBLE", "TOKEN_CHAR", "TOKEN_BOOL",
  "TOKEN_STRING", "TOKEN_LONG", "TOKEN_SHORT", "TOKEN_UNSIGNED",
  "TOKEN_SIGNED", "TOKEN_AUTO", "TOKEN_VOID", "TOKEN_INCLUDE",
  "TOKEN_USING", "TOKEN_NAMESPACE", "TOKEN_COUT", "TOKEN_CIN",
  "TOKEN_ENDL", "TOKEN_RETURN", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE",
  "TOKEN_FOR", "TOKEN_BREAK", "TOKEN_COMMA", "TOKEN_SEMICOLON",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACE", "TOKEN_RBRACE",
  "TOKEN_HASH", "TOKEN_LT", "TOKEN_GT", "TOKEN_SHIFT_L", "TOKEN_SHIFT_R",
  "TOKEN_DOUBLE_COLON", "TOKEN_DOUBLE_QUOTES", "TOKEN_SINGLE_QUOTES",
  "TOKEN_EQ", "TOKEN_NEQ", "TOKEN_LEQ", "TOKEN_GEQ", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_ASSIGN", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_MOD", "TOKEN_NUMBER", "TOKEN_BOOL_LITERAL",
  "TOKEN_ID", "TOKEN_STRING_LITERAL", "TOKEN_ERROR", "$accept", "programa",
  "programa_declaracao", "definicao_funcao", "bloco_escopo",
  "operacoes_possiveis", "declaracao_funcao", "parametros_funcao",
  "funcao_declaracao_parametro", "while_loop", "for_loop", "incremento",
  "condicional_if", "operacao_matematica_atribuicao_valor",
  "operacao_matematica", "operacao_relacional",
  "operacao_relacional_tipos", "entrada_dados", "entrada_dados_parametros",
  "saida_dados", "saida_dados_parametro", "saida_dados_opcoes",
  "declaracao_variavel", "variavel", "tipagem", "return",
  "declaracao_namespace", "chamada_biblioteca", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     210,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,   -13,   -18,    13,    35,    45,    62,    52,
       3,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,    86,
    -101,  -101,  -101,   108,   146,    15,    15,   263,    75,    84,
    -101,  -101,    46,   232,   149,  -101,   244,   244,   150,   164,
      15,   153,   157,   105,   197,   202,   173,   263,   175,   186,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,    85,    89,
     213,   224,   229,   214,   227,    54,   121,   233,  -101,   123,
     140,   151,   152,   156,  -101,   174,   183,   184,   187,   203,
    -101,   234,   253,   226,  -101,   235,  -101,  -101,  -101,  -101,
    -101,  -101,   228,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,    -2,   263,  -101,   231,    41,
      76,   -16,   259,  -101,  -101,   236,  -101,   254,   255,   270,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   239,
    -101,  -101,   240,   248,   249,   266,   111,  -101,   -15,    33,
     245,    -7,   268,    81,    63,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,   -15,  -101,  -101,   246,  -101,   263,
     250,   251,   143,  -101,  -101,   178,   272,  -101,  -101,  -101,
    -101,   277
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     8,     7,    10,    11,    12,     9,     6,     0,
      13,     5,     4,     0,     0,     0,     0,     0,     0,     0,
       1,     3,    83,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      82,   100,    67,    68,    71,    72,    69,    70,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
      41,     0,    28,     0,    84,    85,    66,    65,    63,    64,
      15,    15,     0,   101,    62,    57,    52,    58,    53,    59,
      54,    60,    55,    61,    56,    47,    42,    48,    43,    49,
      44,    50,    45,    51,    46,     0,     0,    29,     0,     0,
       0,     0,     0,    26,    15,     0,    86,     0,     0,    37,
      16,    18,    22,    23,    24,    21,    20,    19,    17,     0,
      25,    31,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,    83,     0,    33,    34,    15,    14,    81,
      79,    80,    77,    76,     0,    74,    73,     0,    15,    27,
       0,     0,     0,    78,    75,     0,     0,    35,    36,    32,
      38,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   286,  -101,  -100,  -101,    18,   128,  -101,    23,
      56,  -101,    71,    72,   256,   109,   261,  -101,  -101,  -101,
    -101,   136,     2,  -101,     0,   107,  -101,  -101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,   129,   140,   141,    91,    92,   142,
     143,   132,   144,   145,    56,    48,    68,   146,   161,   147,
     159,   172,   148,    43,   149,   150,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,   130,    28,    40,    33,   169,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    23,    13,
      29,   176,    28,    24,    14,    15,   133,    16,    17,   134,
     177,   152,   153,   154,   156,    34,    18,    51,    23,    50,
     170,   171,    35,    24,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    25,    93,    19,   137,
     138,   173,    14,    15,    36,    16,    17,   182,    46,   174,
      47,    26,    27,   139,    37,    57,    25,    38,   185,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    26,    27,    58,   137,   138,    19,    14,    15,    39,
      16,    17,    79,    80,    81,    82,    83,    30,   151,    52,
     179,   180,   181,    53,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   135,    30,    58,   137,
     138,    19,    14,    15,    53,    16,    17,    54,    96,    55,
      97,    42,    98,   168,    99,    49,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    75,    72,
      76,   137,   138,    44,    14,    15,    19,    16,    17,    85,
      86,    87,    88,    89,    45,   189,   105,    61,   106,    93,
      70,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   107,    71,   108,   137,   138,    19,    14,
      15,    90,    16,    17,   109,   111,   110,   112,    73,   113,
     190,   114,    74,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    78,    13,   115,    94,   116,
      84,    14,    15,    19,    16,    17,   117,   119,   118,   120,
     121,    95,   122,    18,   100,    79,    80,    81,    82,    83,
      85,    86,    87,    88,    89,   101,   123,   102,   124,    59,
      60,    58,   103,   104,   125,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    62,    63,
     126,   127,   128,   131,   136,    64,    65,    66,    67,   155,
     158,   157,   160,   162,   163,   164,   165,   167,   166,   178,
     175,   184,   191,   187,   188,   133,    41,   186,    69,    77,
     183
};

static const yytype_uint8 yycheck[] =
{
       0,   101,     0,     0,    17,    20,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,    16,
      20,    28,    20,     0,    21,    22,    28,    24,    25,    31,
      37,    47,    48,    49,   134,    53,    33,    37,    20,    37,
      55,    56,    29,    20,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    57,    55,    18,
      19,    28,    21,    22,    29,    24,    25,   167,    53,    36,
      55,     0,     0,    32,    29,    29,    20,    15,   178,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    20,    20,    47,    18,    19,    55,    21,    22,    47,
      24,    25,    48,    49,    50,    51,    52,     0,    32,    34,
      29,    48,    49,    29,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   126,    20,    47,    18,
      19,    55,    21,    22,    29,    24,    25,    53,    53,    55,
      55,    55,    53,    32,    55,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    53,    50,
      55,    18,    19,    55,    21,    22,    55,    24,    25,    48,
      49,    50,    51,    52,    28,    32,    53,    28,    55,   179,
      30,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    53,    30,    55,    18,    19,    55,    21,
      22,    28,    24,    25,    53,    53,    55,    55,    55,    53,
      32,    55,    55,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    28,    16,    53,    53,    55,
      28,    21,    22,    55,    24,    25,    53,    53,    55,    55,
      53,    55,    55,    33,    31,    48,    49,    50,    51,    52,
      48,    49,    50,    51,    52,    31,    53,    28,    55,    27,
      28,    47,    35,    30,    30,    55,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    34,    35,
      27,    55,    47,    55,    53,    41,    42,    43,    44,    30,
      36,    55,    37,    23,    55,    55,    48,    31,    49,    31,
      55,    55,    30,    53,    53,    28,    20,   179,    47,    53,
     174
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    21,    22,    24,    25,    33,    55,
      59,    60,    61,    64,    67,    68,    70,    71,    80,    82,
      83,    84,    85,    17,    53,    29,    29,    29,    15,    47,
       0,    60,    55,    81,    55,    28,    53,    55,    73,    73,
      80,    82,    34,    29,    53,    55,    72,    29,    47,    27,
      28,    28,    34,    35,    41,    42,    43,    44,    74,    74,
      30,    30,    73,    55,    55,    53,    55,    72,    28,    48,
      49,    50,    51,    52,    28,    48,    49,    50,    51,    52,
      28,    65,    66,    82,    53,    55,    53,    55,    53,    55,
      31,    31,    28,    35,    30,    53,    55,    53,    55,    53,
      55,    53,    55,    53,    55,    53,    55,    53,    55,    53,
      55,    53,    55,    53,    55,    30,    27,    55,    47,    62,
      62,    55,    69,    28,    31,    82,    53,    18,    19,    32,
      63,    64,    67,    68,    70,    71,    75,    77,    80,    82,
      83,    32,    47,    48,    49,    30,    62,    55,    36,    78,
      37,    76,    23,    55,    55,    48,    49,    31,    32,    20,
      55,    56,    79,    28,    36,    55,    28,    37,    31,    29,
      48,    49,    62,    79,    55,    62,    65,    53,    53,    32,
      32,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    65,    65,    66,
      66,    67,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    78,    78,    79,
      79,    79,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     0,     1,     2,
       4,     7,    10,     3,     3,     5,     5,     7,    11,     4,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     3,     1,
       1,     1,     3,     1,     3,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     5
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
  case 2: /* programa: programa_declaracao  */
#line 125 "parser/parser.y"
    {
        raiz_ast = (yyvsp[0].no);
    }
#line 1325 "parser/parser.tab.c"
    break;

  case 3: /* programa: programa programa_declaracao  */
#line 129 "parser/parser.y"
    {
        if ((yyvsp[-1].no) == NULL) {
            raiz_ast = (yyvsp[0].no);
        } else if ((yyvsp[0].no)) {
            raiz_ast = criarNoOp(';', (yyvsp[-1].no), (yyvsp[0].no));
        } else {
            raiz_ast = (yyvsp[-1].no);
        }
    }
#line 1339 "parser/parser.tab.c"
    break;

  case 14: /* definicao_funcao: tipagem TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE  */
#line 155 "parser/parser.y"
    {
        printf("Definição de função reconhecida\n");
    }
#line 1347 "parser/parser.tab.c"
    break;

  case 15: /* bloco_escopo: %empty  */
#line 161 "parser/parser.y"
                       { (yyval.no) = NULL; }
#line 1353 "parser/parser.tab.c"
    break;

  case 16: /* bloco_escopo: bloco_escopo operacoes_possiveis  */
#line 162 "parser/parser.y"
                                       {
        if ((yyvsp[-1].no) == NULL) {
            (yyval.no) = (yyvsp[0].no);
        } else if ((yyvsp[0].no)) {
            (yyval.no) = criarNoOp(';', (yyvsp[-1].no), (yyvsp[0].no)); 
        } else {
            (yyval.no) = (yyvsp[-1].no);
        }
    }
#line 1367 "parser/parser.tab.c"
    break;

  case 17: /* operacoes_possiveis: declaracao_variavel  */
#line 174 "parser/parser.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1373 "parser/parser.tab.c"
    break;

  case 18: /* operacoes_possiveis: declaracao_funcao  */
#line 175 "parser/parser.y"
                        { (yyval.no) = NULL; }
#line 1379 "parser/parser.tab.c"
    break;

  case 19: /* operacoes_possiveis: saida_dados  */
#line 176 "parser/parser.y"
                  { (yyval.no) = NULL; }
#line 1385 "parser/parser.tab.c"
    break;

  case 20: /* operacoes_possiveis: entrada_dados  */
#line 177 "parser/parser.y"
                    { (yyval.no) = NULL; }
#line 1391 "parser/parser.tab.c"
    break;

  case 21: /* operacoes_possiveis: operacao_matematica_atribuicao_valor  */
#line 178 "parser/parser.y"
                                           {
        printf("AST da operação:\n");
        imprimirAST((yyvsp[0].no));
        printf("\n");
        (yyval.no) = (yyvsp[0].no);
    }
#line 1402 "parser/parser.tab.c"
    break;

  case 22: /* operacoes_possiveis: while_loop  */
#line 184 "parser/parser.y"
                 { 
        printf("AST do loop while:\n");
        imprimirAST((yyvsp[0].no));
        printf("\n");
        (yyval.no) = (yyvsp[0].no); 
    }
#line 1413 "parser/parser.tab.c"
    break;

  case 23: /* operacoes_possiveis: for_loop  */
#line 190 "parser/parser.y"
               { 
        printf("AST do loop for:\n");
        imprimirAST((yyvsp[0].no));
        printf("\n");
        (yyval.no) = (yyvsp[0].no); 
    }
#line 1424 "parser/parser.tab.c"
    break;

  case 24: /* operacoes_possiveis: condicional_if  */
#line 196 "parser/parser.y"
                     {
        printf("AST do condicional:\n");
        imprimirAST((yyvsp[0].no));
        printf("\n");
        (yyval.no) = (yyvsp[0].no);
    }
#line 1435 "parser/parser.tab.c"
    break;

  case 25: /* operacoes_possiveis: return  */
#line 202 "parser/parser.y"
             { (yyval.no) = NULL; }
#line 1441 "parser/parser.tab.c"
    break;

  case 26: /* declaracao_funcao: tipagem TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_SEMICOLON  */
#line 207 "parser/parser.y"
    {
        printf("Declaração de função reconhecida\n");
    }
#line 1449 "parser/parser.tab.c"
    break;

  case 31: /* while_loop: TOKEN_WHILE TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE  */
#line 224 "parser/parser.y"
    {
        (yyval.no) = criarNoLoop('W', (yyvsp[-4].no), (yyvsp[-1].no));
    }
#line 1457 "parser/parser.tab.c"
    break;

  case 32: /* for_loop: TOKEN_FOR TOKEN_LPAREN declaracao_variavel operacao_relacional TOKEN_SEMICOLON incremento TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE  */
#line 231 "parser/parser.y"
    {
        (yyval.no) = criarNoFor((yyvsp[-7].no), (yyvsp[-6].no), (yyvsp[-4].no), (yyvsp[-1].no));
    }
#line 1465 "parser/parser.tab.c"
    break;

  case 33: /* incremento: TOKEN_ID TOKEN_PLUS TOKEN_PLUS  */
#line 237 "parser/parser.y"
                                                                       { (yyval.no) = criarNoOp('P', criarNoId((yyvsp[-2].v_string), TIPO_INT), NULL); }
#line 1471 "parser/parser.tab.c"
    break;

  case 34: /* incremento: TOKEN_ID TOKEN_MINUS TOKEN_MINUS  */
#line 238 "parser/parser.y"
                                                                       { (yyval.no) = criarNoOp('M', criarNoId((yyvsp[-2].v_string), TIPO_INT), NULL); }
#line 1477 "parser/parser.tab.c"
    break;

  case 35: /* incremento: TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_PLUS TOKEN_NUMBER  */
#line 239 "parser/parser.y"
                                                                       { (yyval.no) = criarNoOp('=', criarNoId((yyvsp[-4].v_string), TIPO_INT), criarNoOp('+', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int)))); }
#line 1483 "parser/parser.tab.c"
    break;

  case 36: /* incremento: TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_MINUS TOKEN_NUMBER  */
#line 240 "parser/parser.y"
                                                                       { (yyval.no) = criarNoOp('=', criarNoId((yyvsp[-4].v_string), TIPO_INT), criarNoOp('-', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int)))); }
#line 1489 "parser/parser.tab.c"
    break;

  case 37: /* condicional_if: TOKEN_IF TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE  */
#line 244 "parser/parser.y"
                                                                                                  {
        (yyval.no) = criarNoCondicional((yyvsp[-4].no), (yyvsp[-1].no), NULL);
    }
#line 1497 "parser/parser.tab.c"
    break;

  case 38: /* condicional_if: TOKEN_IF TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE bloco_escopo TOKEN_RBRACE  */
#line 247 "parser/parser.y"
                                                                                                                                                      {
        (yyval.no) = criarNoCondicional((yyvsp[-8].no), (yyvsp[-5].no), (yyvsp[-1].no));
    }
#line 1505 "parser/parser.tab.c"
    break;

  case 39: /* operacao_matematica_atribuicao_valor: TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER TOKEN_SEMICOLON  */
#line 253 "parser/parser.y"
                                                                                  { (yyval.no) = criarNoOp('=', criarNoId((yyvsp[-3].v_string), TIPO_INT), criarNoNum((yyvsp[-1].v_int)));}
#line 1511 "parser/parser.tab.c"
    break;

  case 40: /* operacao_matematica_atribuicao_valor: TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_SEMICOLON  */
#line 254 "parser/parser.y"
                                                                                  { (yyval.no) = criarNoOp('=', criarNoId((yyvsp[-3].v_string), TIPO_INT), criarNoId((yyvsp[-1].v_string), TIPO_INT));}
#line 1517 "parser/parser.tab.c"
    break;

  case 41: /* operacao_matematica_atribuicao_valor: TOKEN_ID TOKEN_ASSIGN operacao_matematica TOKEN_SEMICOLON  */
#line 255 "parser/parser.y"
                                                                                  { (yyval.no) = criarNoOp('=', criarNoId((yyvsp[-3].v_string), TIPO_INT), (yyvsp[-1].no)); }
#line 1523 "parser/parser.tab.c"
    break;

  case 42: /* operacao_matematica: TOKEN_ID TOKEN_PLUS TOKEN_ID  */
#line 259 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('+', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1529 "parser/parser.tab.c"
    break;

  case 43: /* operacao_matematica: TOKEN_ID TOKEN_MINUS TOKEN_ID  */
#line 260 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('-', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1535 "parser/parser.tab.c"
    break;

  case 44: /* operacao_matematica: TOKEN_ID TOKEN_MUL TOKEN_ID  */
#line 261 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('*', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1541 "parser/parser.tab.c"
    break;

  case 45: /* operacao_matematica: TOKEN_ID TOKEN_DIV TOKEN_ID  */
#line 262 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('/', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1547 "parser/parser.tab.c"
    break;

  case 46: /* operacao_matematica: TOKEN_ID TOKEN_MOD TOKEN_ID  */
#line 263 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('%', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1553 "parser/parser.tab.c"
    break;

  case 47: /* operacao_matematica: TOKEN_ID TOKEN_PLUS TOKEN_NUMBER  */
#line 264 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('+', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int))); }
#line 1559 "parser/parser.tab.c"
    break;

  case 48: /* operacao_matematica: TOKEN_ID TOKEN_MINUS TOKEN_NUMBER  */
#line 265 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('-', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int))); }
#line 1565 "parser/parser.tab.c"
    break;

  case 49: /* operacao_matematica: TOKEN_ID TOKEN_MUL TOKEN_NUMBER  */
#line 266 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('*', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int))); }
#line 1571 "parser/parser.tab.c"
    break;

  case 50: /* operacao_matematica: TOKEN_ID TOKEN_DIV TOKEN_NUMBER  */
#line 267 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('/', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int))); }
#line 1577 "parser/parser.tab.c"
    break;

  case 51: /* operacao_matematica: TOKEN_ID TOKEN_MOD TOKEN_NUMBER  */
#line 268 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('%', criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int))); }
#line 1583 "parser/parser.tab.c"
    break;

  case 52: /* operacao_matematica: TOKEN_NUMBER TOKEN_PLUS TOKEN_ID  */
#line 269 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('+', criarNoNum((yyvsp[-2].v_int)), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1589 "parser/parser.tab.c"
    break;

  case 53: /* operacao_matematica: TOKEN_NUMBER TOKEN_MINUS TOKEN_ID  */
#line 270 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('-', criarNoNum((yyvsp[-2].v_int)), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1595 "parser/parser.tab.c"
    break;

  case 54: /* operacao_matematica: TOKEN_NUMBER TOKEN_MUL TOKEN_ID  */
#line 271 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('*', criarNoNum((yyvsp[-2].v_int)), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1601 "parser/parser.tab.c"
    break;

  case 55: /* operacao_matematica: TOKEN_NUMBER TOKEN_DIV TOKEN_ID  */
#line 272 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('/', criarNoNum((yyvsp[-2].v_int)), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1607 "parser/parser.tab.c"
    break;

  case 56: /* operacao_matematica: TOKEN_NUMBER TOKEN_MOD TOKEN_ID  */
#line 273 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('%', criarNoNum((yyvsp[-2].v_int)), criarNoId((yyvsp[0].v_string), TIPO_INT)); }
#line 1613 "parser/parser.tab.c"
    break;

  case 57: /* operacao_matematica: TOKEN_NUMBER TOKEN_PLUS TOKEN_NUMBER  */
#line 274 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('+', criarNoNum((yyvsp[-2].v_int)), criarNoNum((yyvsp[0].v_int))); }
#line 1619 "parser/parser.tab.c"
    break;

  case 58: /* operacao_matematica: TOKEN_NUMBER TOKEN_MINUS TOKEN_NUMBER  */
#line 275 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('-', criarNoNum((yyvsp[-2].v_int)), criarNoNum((yyvsp[0].v_int))); }
#line 1625 "parser/parser.tab.c"
    break;

  case 59: /* operacao_matematica: TOKEN_NUMBER TOKEN_MUL TOKEN_NUMBER  */
#line 276 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('*', criarNoNum((yyvsp[-2].v_int)), criarNoNum((yyvsp[0].v_int))); }
#line 1631 "parser/parser.tab.c"
    break;

  case 60: /* operacao_matematica: TOKEN_NUMBER TOKEN_DIV TOKEN_NUMBER  */
#line 277 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('/', criarNoNum((yyvsp[-2].v_int)), criarNoNum((yyvsp[0].v_int))); }
#line 1637 "parser/parser.tab.c"
    break;

  case 61: /* operacao_matematica: TOKEN_NUMBER TOKEN_MOD TOKEN_NUMBER  */
#line 278 "parser/parser.y"
                                                          { (yyval.no) = criarNoOp('%', criarNoNum((yyvsp[-2].v_int)), criarNoNum((yyvsp[0].v_int))); }
#line 1643 "parser/parser.tab.c"
    break;

  case 62: /* operacao_matematica: TOKEN_LPAREN operacao_matematica TOKEN_RPAREN  */
#line 279 "parser/parser.y"
                                                         { (yyval.no) = (yyvsp[-1].no); }
#line 1649 "parser/parser.tab.c"
    break;

  case 63: /* operacao_relacional: TOKEN_ID operacao_relacional_tipos TOKEN_NUMBER  */
#line 283 "parser/parser.y"
                                                    {
        (yyval.no) = criarNoOp((yyvsp[-1].v_char), criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoNum((yyvsp[0].v_int)));
    }
#line 1657 "parser/parser.tab.c"
    break;

  case 64: /* operacao_relacional: TOKEN_ID operacao_relacional_tipos TOKEN_ID  */
#line 286 "parser/parser.y"
                                                  {
        (yyval.no) = criarNoOp((yyvsp[-1].v_char), criarNoId((yyvsp[-2].v_string), TIPO_INT), criarNoId((yyvsp[0].v_string), TIPO_INT));
    }
#line 1665 "parser/parser.tab.c"
    break;

  case 65: /* operacao_relacional: TOKEN_NUMBER operacao_relacional_tipos TOKEN_ID  */
#line 289 "parser/parser.y"
                                                      {
        (yyval.no) = criarNoOp((yyvsp[-1].v_char), criarNoNum((yyvsp[-2].v_int)), criarNoId((yyvsp[0].v_string), TIPO_INT));
    }
#line 1673 "parser/parser.tab.c"
    break;

  case 66: /* operacao_relacional: TOKEN_NUMBER operacao_relacional_tipos TOKEN_NUMBER  */
#line 292 "parser/parser.y"
                                                          {
        (yyval.no) = criarNoOp((yyvsp[-1].v_char), criarNoNum((yyvsp[-2].v_int)), criarNoNum((yyvsp[0].v_int)));
    }
#line 1681 "parser/parser.tab.c"
    break;

  case 67: /* operacao_relacional_tipos: TOKEN_LT  */
#line 298 "parser/parser.y"
                { (yyval.v_char) = '<'; }
#line 1687 "parser/parser.tab.c"
    break;

  case 68: /* operacao_relacional_tipos: TOKEN_GT  */
#line 299 "parser/parser.y"
                { (yyval.v_char) = '>'; }
#line 1693 "parser/parser.tab.c"
    break;

  case 69: /* operacao_relacional_tipos: TOKEN_LEQ  */
#line 300 "parser/parser.y"
                { (yyval.v_char) = 'L'; }
#line 1699 "parser/parser.tab.c"
    break;

  case 70: /* operacao_relacional_tipos: TOKEN_GEQ  */
#line 301 "parser/parser.y"
                { (yyval.v_char) = 'G'; }
#line 1705 "parser/parser.tab.c"
    break;

  case 71: /* operacao_relacional_tipos: TOKEN_EQ  */
#line 302 "parser/parser.y"
                { (yyval.v_char) = 'E'; }
#line 1711 "parser/parser.tab.c"
    break;

  case 72: /* operacao_relacional_tipos: TOKEN_NEQ  */
#line 303 "parser/parser.y"
                { (yyval.v_char) = 'N'; }
#line 1717 "parser/parser.tab.c"
    break;

  case 73: /* entrada_dados: TOKEN_CIN entrada_dados_parametros TOKEN_SEMICOLON  */
#line 308 "parser/parser.y"
    {
        printf("Entrada de dados reconhecida\n");
    }
#line 1725 "parser/parser.tab.c"
    break;

  case 76: /* saida_dados: TOKEN_COUT saida_dados_parametro TOKEN_SEMICOLON  */
#line 320 "parser/parser.y"
    {
        printf("Saída de dados reconhecida\n");
    }
#line 1733 "parser/parser.tab.c"
    break;

  case 82: /* declaracao_variavel: tipagem variavel TOKEN_SEMICOLON  */
#line 337 "parser/parser.y"
                                     {
        printf("Declaração de variável reconhecida\n");
        imprimirAST((yyvsp[-1].no));
        printf("\n");
        (yyval.no) = (yyvsp[-1].no);
    }
#line 1744 "parser/parser.tab.c"
    break;

  case 83: /* variavel: TOKEN_ID  */
#line 346 "parser/parser.y"
             { 
        (yyval.no) = criarNoDeclaracao(TIPO_INT, (yyvsp[0].v_string));
    }
#line 1752 "parser/parser.tab.c"
    break;

  case 84: /* variavel: TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER  */
#line 349 "parser/parser.y"
                                       { 
        (yyval.no) = criarNoOp('=', criarNoDeclaracao(TIPO_INT, (yyvsp[-2].v_string)), criarNoNum((yyvsp[0].v_int)));
    }
#line 1760 "parser/parser.tab.c"
    break;

  case 85: /* variavel: variavel TOKEN_COMMA TOKEN_ID  */
#line 352 "parser/parser.y"
                                  { 
        (yyval.no) = criarNoOp(',', (yyvsp[-2].no), criarNoDeclaracao(TIPO_INT, (yyvsp[0].v_string))); 
    }
#line 1768 "parser/parser.tab.c"
    break;

  case 86: /* variavel: variavel TOKEN_COMMA TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER  */
#line 355 "parser/parser.y"
                                                            { 
        (yyval.no) = criarNoOp(',', (yyvsp[-4].no), criarNoOp('=', criarNoDeclaracao(TIPO_INT, (yyvsp[-2].v_string)), criarNoNum((yyvsp[0].v_int)))); 
    }
#line 1776 "parser/parser.tab.c"
    break;

  case 99: /* return: TOKEN_RETURN TOKEN_NUMBER TOKEN_SEMICOLON  */
#line 377 "parser/parser.y"
    {
        printf("Retorno de função reconhecido\n");
    }
#line 1784 "parser/parser.tab.c"
    break;

  case 100: /* declaracao_namespace: TOKEN_USING TOKEN_NAMESPACE TOKEN_ID TOKEN_SEMICOLON  */
#line 384 "parser/parser.y"
    {
        printf("Declaração de namespace reconhecida\n");
    }
#line 1792 "parser/parser.tab.c"
    break;

  case 101: /* chamada_biblioteca: TOKEN_HASH TOKEN_INCLUDE TOKEN_LT TOKEN_ID TOKEN_GT  */
#line 391 "parser/parser.y"
    {
        printf("Chamada de biblioteca reconhecida\n");
    }
#line 1800 "parser/parser.tab.c"
    break;


#line 1804 "parser/parser.tab.c"

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

#line 396 "parser/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}

int main(int argc, char **argv) {
    int resultado = yyparse();
    
    if (resultado == 0 && raiz_ast) {
        printf("AST gerada com sucesso!\n");
        printf("AST completa:\n");
        imprimirAST(raiz_ast);
        printf("\n\n");
        
        // Executar o programa
        executarPrograma(raiz_ast);
        
        // Liberar memória
        liberarAST(raiz_ast);
    }
    
    return resultado;
}
