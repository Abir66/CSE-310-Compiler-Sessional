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
#line 1 "1905066.y"

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"
#include"1905066_parser_helper.h"
#include"1905066_ICG_helper.h"

using namespace std;



#line 86 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    BREAK = 263,                   /* BREAK  */
    RETURN = 264,                  /* RETURN  */
    SWITCH = 265,                  /* SWITCH  */
    CASE = 266,                    /* CASE  */
    DEFAULT = 267,                 /* DEFAULT  */
    CONTINUE = 268,                /* CONTINUE  */
    LPAREN = 269,                  /* LPAREN  */
    RPAREN = 270,                  /* RPAREN  */
    LCURL = 271,                   /* LCURL  */
    RCURL = 272,                   /* RCURL  */
    LTHIRD = 273,                  /* LTHIRD  */
    RTHIRD = 274,                  /* RTHIRD  */
    COMMA = 275,                   /* COMMA  */
    SEMICOLON = 276,               /* SEMICOLON  */
    PRINTLN = 277,                 /* PRINTLN  */
    PRINT = 278,                   /* PRINT  */
    INCOP = 279,                   /* INCOP  */
    DECOP = 280,                   /* DECOP  */
    ASSIGNOP = 281,                /* ASSIGNOP  */
    NOT = 282,                     /* NOT  */
    ID = 283,                      /* ID  */
    INT = 284,                     /* INT  */
    FLOAT = 285,                   /* FLOAT  */
    DOUBLE = 286,                  /* DOUBLE  */
    CONST_INT = 287,               /* CONST_INT  */
    CONST_FLOAT = 288,             /* CONST_FLOAT  */
    CHAR = 289,                    /* CHAR  */
    VOID = 290,                    /* VOID  */
    ADDOP = 291,                   /* ADDOP  */
    MULOP = 292,                   /* MULOP  */
    RELOP = 293,                   /* RELOP  */
    LOGICOP = 294,                 /* LOGICOP  */
    BITOP = 295,                   /* BITOP  */
    CONST_STRING = 296,            /* CONST_STRING  */
    SCANINT = 297,                 /* SCANINT  */
    LOWER_THAN_ELSE = 298          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define RETURN 264
#define SWITCH 265
#define CASE 266
#define DEFAULT 267
#define CONTINUE 268
#define LPAREN 269
#define RPAREN 270
#define LCURL 271
#define RCURL 272
#define LTHIRD 273
#define RTHIRD 274
#define COMMA 275
#define SEMICOLON 276
#define PRINTLN 277
#define PRINT 278
#define INCOP 279
#define DECOP 280
#define ASSIGNOP 281
#define NOT 282
#define ID 283
#define INT 284
#define FLOAT 285
#define DOUBLE 286
#define CONST_INT 287
#define CONST_FLOAT 288
#define CHAR 289
#define VOID 290
#define ADDOP 291
#define MULOP 292
#define RELOP 293
#define LOGICOP 294
#define BITOP 295
#define CONST_STRING 296
#define SCANINT 297
#define LOWER_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "1905066.y"

    SymbolInfo* symbolInfo; 

#line 229 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_SWITCH = 10,                    /* SWITCH  */
  YYSYMBOL_CASE = 11,                      /* CASE  */
  YYSYMBOL_DEFAULT = 12,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_LPAREN = 14,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 15,                    /* RPAREN  */
  YYSYMBOL_LCURL = 16,                     /* LCURL  */
  YYSYMBOL_RCURL = 17,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 18,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 19,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_PRINTLN = 22,                   /* PRINTLN  */
  YYSYMBOL_PRINT = 23,                     /* PRINT  */
  YYSYMBOL_INCOP = 24,                     /* INCOP  */
  YYSYMBOL_DECOP = 25,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 26,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 31,                    /* DOUBLE  */
  YYSYMBOL_CONST_INT = 32,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 33,               /* CONST_FLOAT  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_VOID = 35,                      /* VOID  */
  YYSYMBOL_ADDOP = 36,                     /* ADDOP  */
  YYSYMBOL_MULOP = 37,                     /* MULOP  */
  YYSYMBOL_RELOP = 38,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 39,                   /* LOGICOP  */
  YYSYMBOL_BITOP = 40,                     /* BITOP  */
  YYSYMBOL_CONST_STRING = 41,              /* CONST_STRING  */
  YYSYMBOL_SCANINT = 42,                   /* SCANINT  */
  YYSYMBOL_LOWER_THAN_ELSE = 43,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_start = 45,                     /* start  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_unit = 47,                      /* unit  */
  YYSYMBOL_func_declaration = 48,          /* func_declaration  */
  YYSYMBOL_func_definition = 49,           /* func_definition  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_parameter_list = 52,            /* parameter_list  */
  YYSYMBOL_compound_statement = 53,        /* compound_statement  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_var_declaration = 56,           /* var_declaration  */
  YYSYMBOL_type_specifier = 57,            /* type_specifier  */
  YYSYMBOL_declaration_list = 58,          /* declaration_list  */
  YYSYMBOL_statements = 59,                /* statements  */
  YYSYMBOL_60_5 = 60,                      /* $@5  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_P = 66,                         /* P  */
  YYSYMBOL_expression_statement = 67,      /* expression_statement  */
  YYSYMBOL_variable = 68,                  /* variable  */
  YYSYMBOL_N = 69,                         /* N  */
  YYSYMBOL_M = 70,                         /* M  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_logic_expression = 72,          /* logic_expression  */
  YYSYMBOL_rel_expression = 73,            /* rel_expression  */
  YYSYMBOL_simple_expression = 74,         /* simple_expression  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_unary_expression = 76,          /* unary_expression  */
  YYSYMBOL_factor = 77,                    /* factor  */
  YYSYMBOL_argument_list = 78,             /* argument_list  */
  YYSYMBOL_arguments = 79                  /* arguments  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    41,    46,    53,    58,    64,    72,    81,
      91,    91,   109,   109,   128,   140,   149,   158,   169,   169,
     184,   184,   193,   218,   224,   230,   238,   245,   253,   261,
     272,   272,   283,   283,   294,   299,   325,   333,   333,   333,
     356,   366,   385,   385,   419,   424,   429,   439,   446,   454,
     462,   470,   474,   479,   489,   508,   542,   549,   562,   568,
     621,   627,   664,   671,   705,   712,   734,   742,   796,   817,
     848,   859,   872,   934,   944,   956,   963,   979,   998,  1004,
    1010,  1017
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "BREAK", "RETURN", "SWITCH", "CASE", "DEFAULT",
  "CONTINUE", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD",
  "COMMA", "SEMICOLON", "PRINTLN", "PRINT", "INCOP", "DECOP", "ASSIGNOP",
  "NOT", "ID", "INT", "FLOAT", "DOUBLE", "CONST_INT", "CONST_FLOAT",
  "CHAR", "VOID", "ADDOP", "MULOP", "RELOP", "LOGICOP", "BITOP",
  "CONST_STRING", "SCANINT", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "$@3", "$@4", "var_declaration",
  "type_specifier", "declaration_list", "statements", "$@5", "$@6",
  "statement", "$@7", "$@8", "$@9", "P", "expression_statement",
  "variable", "N", "M", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -79,   -79,   -79,     9,   -24,   -79,   -79,   -79,   -79,
     -16,   -79,   -79,    21,    23,    11,   -13,    27,   -79,    35,
      -7,    41,    54,    62,   -79,    68,    65,   -24,   -79,   -79,
      55,    78,   -79,   -79,    68,    69,    79,   -79,    87,   -79,
     -79,   -79,    88,    85,   -79,   -79,   -79,    95,    96,   -79,
     102,   114,   -79,    97,   105,   114,    50,   -79,   -79,   114,
     108,   -79,   -79,    74,   -79,   -79,    37,   103,   -79,    86,
      47,    94,   -79,   -79,    85,   114,   112,   118,   -79,   115,
     122,    -4,    38,    51,   -79,   114,   114,   -79,   121,   125,
     -79,   -79,   114,   -79,   -79,   114,   114,   114,   -79,   -79,
     -79,   114,   -79,   -79,   136,   137,   138,   139,   -79,   140,
     141,   143,   142,   144,   -79,   114,    94,   120,   -79,   148,
     112,   -79,   145,   146,   147,   149,   -79,   114,   -79,   150,
     -79,   -79,   -79,   154,   -79,   -79,   -79,   -79,   -79,   -79,
      85,   -79,   -79,   153,   114,    85,   -79,   -79,   -79,   -79,
     157,    85,   -79,   -79,    85,   -79
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    12,
       0,    17,     0,    26,     9,     0,    10,     0,    16,    29,
       0,    18,    13,     8,     0,    15,     0,    30,     0,    11,
      14,    27,    57,     0,    21,    19,    32,     0,     0,    57,
       0,     0,    52,     0,     0,     0,    54,    74,    75,     0,
       0,    36,    34,     0,    31,    35,    71,     0,    58,    60,
      62,    64,    66,    70,     0,     0,     0,     0,    47,     0,
       0,     0,     0,    71,    69,    79,     0,    68,     0,    28,
      76,    77,     0,    53,    57,     0,     0,     0,    33,    51,
      57,     0,    46,    73,     0,     0,     0,     0,    81,     0,
      78,     0,    54,     0,    59,     0,    65,    63,    67,     0,
       0,    42,     0,     0,     0,     0,    72,     0,    55,     0,
      61,    57,    37,     0,    48,    44,    49,    45,    80,    50,
       0,    57,    57,    40,     0,     0,    56,    38,    43,    57,
       0,     0,    57,    41,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   159,   -79,   -79,   -79,   -79,   -79,    -9,
     -79,   -79,    31,    15,   -79,   -79,   -79,   -79,   -73,   -79,
     -79,   -79,   -79,   -72,   -38,   -79,   -49,   -48,   -78,    43,
      77,    70,   -37,   -79,   -79,   -79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    25,    20,    61,
      37,    38,    62,    63,    14,    42,    43,    74,    64,   141,
     150,   133,   119,    65,    66,   149,    46,    67,    68,    69,
      70,    71,    72,    73,   109,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    98,    79,    80,   100,     1,     2,   108,    26,    11,
      51,     3,    13,    27,   114,    10,    32,    83,    84,    22,
      10,    83,    87,    55,    56,    39,    19,    99,    57,    58,
      21,     9,    59,   105,   107,    15,     9,   104,   111,    16,
       1,     2,    35,    17,    18,   115,     3,    83,   132,   138,
     113,   120,    51,   121,    83,    23,    24,    83,    83,    83,
     118,    90,    91,    92,    85,    55,    56,   143,    86,    28,
      57,    58,   148,    29,    59,    90,    91,    83,   153,   106,
      30,   155,   140,    95,    31,    96,    33,    36,    47,    83,
      48,    49,   144,   145,    50,   -20,   147,    40,    41,    51,
     151,    31,    89,   154,    44,    45,    52,    53,    54,    75,
      76,    81,    55,    56,     1,     2,    51,    57,    58,    82,
       3,    59,    88,    78,    93,    94,    51,    60,    51,    55,
      56,    97,   101,    52,    57,    58,   102,   103,    59,    55,
      56,    55,    56,    16,    57,    58,    57,    58,    59,   112,
      59,   122,   123,   124,   125,   126,    95,   146,   130,   129,
      86,   127,   128,   131,    12,   116,   134,   135,   136,   142,
     137,   139,   152,   117
};

static const yytype_uint8 yycheck[] =
{
      49,    74,    50,    51,    76,    29,    30,    85,    15,     0,
      14,    35,    28,    20,    92,     0,    25,    55,    55,    32,
       5,    59,    59,    27,    28,    34,    15,    75,    32,    33,
      15,     0,    36,    81,    82,    14,     5,    41,    86,    18,
      29,    30,    27,    20,    21,    94,    35,    85,   120,   127,
      88,   100,    14,   101,    92,    28,    21,    95,    96,    97,
      97,    24,    25,    26,    14,    27,    28,   140,    18,    28,
      32,    33,   145,    19,    36,    24,    25,   115,   151,    41,
      18,   154,   131,    36,    16,    38,    21,    32,     3,   127,
       5,     6,   141,   142,     9,    17,   144,    28,    19,    14,
     149,    16,    28,   152,    17,    17,    21,    22,    23,    14,
      14,    14,    27,    28,    29,    30,    14,    32,    33,    14,
      35,    36,    14,    21,    21,    39,    14,    42,    14,    27,
      28,    37,    14,    21,    32,    33,    21,    15,    36,    27,
      28,    27,    28,    18,    32,    33,    32,    33,    36,    28,
      36,    15,    15,    15,    15,    15,    36,     4,   115,    15,
      18,    20,    19,    15,     5,    95,    21,    21,    21,    15,
      21,    21,    15,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,    35,    45,    46,    47,    48,    49,    56,
      57,     0,    47,    28,    58,    14,    18,    20,    21,    15,
      52,    57,    32,    28,    21,    51,    15,    20,    28,    19,
      18,    16,    53,    21,    50,    57,    32,    54,    55,    53,
      28,    19,    59,    60,    17,    17,    70,     3,     5,     6,
       9,    14,    21,    22,    23,    27,    28,    32,    33,    36,
      42,    53,    56,    57,    62,    67,    68,    71,    72,    73,
      74,    75,    76,    77,    61,    14,    14,    70,    21,    71,
      71,    14,    14,    68,    76,    14,    18,    76,    14,    28,
      24,    25,    26,    21,    39,    36,    38,    37,    62,    71,
      67,    14,    21,    15,    41,    71,    41,    71,    72,    78,
      79,    71,    28,    68,    72,    70,    75,    74,    76,    66,
      70,    71,    15,    15,    15,    15,    15,    20,    19,    15,
      73,    15,    67,    65,    21,    21,    21,    21,    72,    21,
      70,    63,    15,    62,    70,    70,     4,    71,    62,    69,
      64,    70,    15,    62,    70,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      50,    49,    51,    49,    52,    52,    52,    52,    54,    53,
      55,    53,    56,    57,    57,    57,    58,    58,    58,    58,
      60,    59,    61,    59,    62,    62,    62,    63,    64,    62,
      62,    62,    65,    62,    62,    62,    62,    62,    62,    62,
      62,    66,    67,    67,    68,    68,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       0,     2,     0,     4,     1,     1,     1,     0,     0,    12,
       7,    11,     0,     8,     5,     5,     3,     2,     5,     5,
       5,     0,     1,     2,     1,     4,     0,     0,     1,     3,
       1,     4,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
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
  case 2: /* start: program  */
#line 35 "1905066.y"
                {
		(yyval.symbolInfo) = new SymbolInfo("start", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		finishParsing((yyval.symbolInfo));
	}
#line 1402 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 41 "1905066.y"
                       {
		printLog("program : program unit");
		(yyval.symbolInfo) = new SymbolInfo("program", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1412 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 46 "1905066.y"
              {
		printLog("program : unit");
		(yyval.symbolInfo) = new SymbolInfo("program", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1422 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 53 "1905066.y"
                       {
		printLog("unit : var_declaration");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1432 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 59 "1905066.y"
        {
		printLog("unit : func_declaration");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1442 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 65 "1905066.y"
        {
		printLog("unit : func_definition");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1452 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 72 "1905066.y"
                                                                            {
		printLog("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("func_declaration", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-5].symbolInfo)->getDataType());

		addFunction((yyvsp[-4].symbolInfo), (yyvsp[-5].symbolInfo)->getDataType());

		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1466 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 81 "1905066.y"
                                                    {
		printLog("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("func_declaration", (yyvsp[-4].symbolInfo)->getType());
		(yyval.symbolInfo)->setDataType((yyvsp[-4].symbolInfo)->getDataType());

		addFunction((yyvsp[-3].symbolInfo), (yyvsp[-4].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1479 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 91 "1905066.y"
                                                                 { 
		addFunction((yyvsp[-3].symbolInfo), (yyvsp[-4].symbolInfo)->getDataType(), true);
		inGlobalScope = false;
		genFunctioninitCode((yyvsp[-3].symbolInfo)->getName());
	}
#line 1489 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 95 "1905066.y"
                             {
		printLog("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("func_definition", "non-terminal");

		(yyval.symbolInfo)->addChildren({(yyvsp[-6].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		
		//------------------code generation------------------
		auto func = symbolTable->lookup((yyvsp[-5].symbolInfo)->getName());
		if((yyvsp[0].symbolInfo)->getNextList().size() > 0){
			for(auto line : (yyvsp[0].symbolInfo)->getNextList()) function_return_lines.push_back(line);
		}
		genFunctionEndingCode(func);
	
	}
#line 1508 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 109 "1905066.y"
                                          { 
		addFunction((yyvsp[-2].symbolInfo), (yyvsp[-3].symbolInfo)->getDataType(), true); 
		inGlobalScope = false;
		genFunctioninitCode((yyvsp[-2].symbolInfo)->getName());
	}
#line 1518 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 113 "1905066.y"
                             {
		printLog("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("func_definition", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		
		//------------------code generation------------------
		auto func = symbolTable->lookup((yyvsp[-4].symbolInfo)->getName());
		if((yyvsp[0].symbolInfo)->getNextList().size() > 0){
			for(auto line : (yyvsp[0].symbolInfo)->getNextList()) function_return_lines.push_back(line);
		}
		genFunctionEndingCode(func);

	}
#line 1536 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 128 "1905066.y"
                                                        {
		printLog("parameter_list : parameter_list COMMA type_specifier ID");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", (yyvsp[-3].symbolInfo)->getType());

		(yyvsp[0].symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());

		if(!checkParamRedeclaration((yyvsp[0].symbolInfo))) params.push_back((yyvsp[0].symbolInfo));
		
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

	}
#line 1553 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 140 "1905066.y"
                                              {
		printLog("parameter_list : parameter_list COMMA type_specifier");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", (yyvsp[-2].symbolInfo)->getType());

		SymbolInfo* id = new SymbolInfo("", "ID", (yyvsp[0].symbolInfo)->getDataType());
		params.push_back(id);

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1567 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 149 "1905066.y"
                            {
		printLog("parameter_list : type_specifier ID");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", "non-terminal");

		(yyvsp[0].symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		if(!checkParamRedeclaration((yyvsp[0].symbolInfo))) params.push_back((yyvsp[0].symbolInfo));
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1581 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 158 "1905066.y"
                         {
		printLog("parameter_list : type_specifier");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", "non-terminal");

		SymbolInfo* id = new SymbolInfo("", "ID", (yyvsp[0].symbolInfo)->getDataType());
		params.push_back(id);

		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1595 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 169 "1905066.y"
                           {symbolTable->enterScope(); addParamsToScope();}
#line 1601 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@3 statements RCURL  */
#line 169 "1905066.y"
                                                                                             {
		printLog("compound_statement : LCURL statements RCURL");
		(yyval.symbolInfo) = new SymbolInfo("compound_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();

		// ------------------code generation------------------
		// if($3->getNextList().size() > 0){
		// 	for(auto line : $3->getNextList()) function_return_lines.push_back(line);
		// }

		(yyval.symbolInfo)->setNextList((yyvsp[-1].symbolInfo)->getNextList());
		
	}
#line 1621 "y.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 184 "1905066.y"
                {symbolTable->enterScope(); addParamsToScope();}
#line 1627 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL $@4 RCURL  */
#line 184 "1905066.y"
                                                                       {
		printLog("compound_statement : LCURL RCURL");
		(yyval.symbolInfo) = new SymbolInfo("compound_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
#line 1639 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 193 "1905066.y"
                                                            {
		printLog("var_declaration : type_specifier declaration_list SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("var_declaration", "non-terminal");
		setVarsDataType((yyvsp[-2].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		genVarDeclarationCode();

		// insert in symbol table
		for(auto var : vars){
			bool success = symbolTable->insert(var);
			if(!success){
				std::string error_message = "Redeclaration of variable '" + var->getName() + "'";
				semanticError(var->getStartLine(), error_message);
			}

			if((yyvsp[-2].symbolInfo)->getDataType() == "VOID"){
				std::string error_message = "Variable or field '" + var->getName() + "' declared void";
				semanticError(var->getStartLine(), error_message);
			}
		}

	}
#line 1667 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 218 "1905066.y"
                     {
		printLog("type_specifier : INT");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "INT", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1678 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 224 "1905066.y"
                {
		printLog("type_specifier : FLOAT");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "FLOAT", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1689 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 230 "1905066.y"
               {
		printLog("type_specifier : VOID");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "VOID", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1700 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 238 "1905066.y"
                                             {
		printLog("declaration_list : declaration_list COMMA ID");
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1712 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 245 "1905066.y"
                                                            {
		printLog("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		(yyvsp[-3].symbolInfo)->setArray(true, std::stoi((yyvsp[-1].symbolInfo)->getName()));
		vars.push_back((yyvsp[-3].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo),(yyvsp[-4].symbolInfo),(yyvsp[-3].symbolInfo),(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1725 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 253 "1905066.y"
             {
		printLog("declaration_list : ID");
		vars.clear();
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1738 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 261 "1905066.y"
                                     {
		printLog("declaration_list : ID LTHIRD CONST_INT RTHIRD");
		vars.clear();
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		(yyvsp[-3].symbolInfo)->setArray(true, std::stoi((yyvsp[-1].symbolInfo)->getName()));
		vars.push_back((yyvsp[-3].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo),(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1752 "y.tab.c"
    break;

  case 30: /* $@5: %empty  */
#line 272 "1905066.y"
             {genComment("------------------ Line " + to_string(line_count) + " ------------------");}
#line 1758 "y.tab.c"
    break;

  case 31: /* statements: $@5 statement  */
#line 272 "1905066.y"
                                                                                                                 {
		printLog("statements : statement");
		(yyval.symbolInfo) = new SymbolInfo("statements", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------ code generation ------------------
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
		
		// std::cout<<"here - "<<$2->getLabel()<<std::endl;
		// backpatch($1->getNextList(), $2->getLabel());
	}
#line 1774 "y.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 283 "1905066.y"
                       {genComment("------------------ Line " + to_string(line_count) + " ------------------");}
#line 1780 "y.tab.c"
    break;

  case 33: /* statements: statements M $@6 statement  */
#line 283 "1905066.y"
                                                                                                                           {
		printLog("statements : statements statement");
		(yyval.symbolInfo) = new SymbolInfo("statements", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------ code generation ------------------
		backpatch((yyvsp[-3].symbolInfo)->getNextList(), (yyvsp[-2].symbolInfo)->getLabel());
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
	}
#line 1794 "y.tab.c"
    break;

  case 34: /* statement: var_declaration  */
#line 294 "1905066.y"
                            {
		printLog("statement : var_declaration");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1804 "y.tab.c"
    break;

  case 35: /* statement: expression_statement  */
#line 299 "1905066.y"
                               {
		printLog("statement : expression statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));

		if(!(yyvsp[0].symbolInfo)->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch((yyvsp[0].symbolInfo)->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch((yyvsp[0].symbolInfo)->getFalseList(), label);

			// label = new_label();
			// genCode(label + ":");
			// backpatch($$->getNextList(), label);			
		}

		
	}
#line 1835 "y.tab.c"
    break;

  case 36: /* statement: compound_statement  */
#line 325 "1905066.y"
                             {
		printLog("statement : compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------ code generation ------------------
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
	}
#line 1848 "y.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 333 "1905066.y"
                                                                 { normal_expression_to_logic((yyvsp[0].symbolInfo), false); }
#line 1854 "y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 333 "1905066.y"
                                                                                                                         {genCode("\tPOP AX"); genCode("\tJMP " + (yyvsp[-4].symbolInfo)->getLabel());}
#line 1860 "y.tab.c"
    break;

  case 39: /* statement: FOR LPAREN expression_statement M expression_statement $@7 M expression $@8 RPAREN M statement  */
#line 333 "1905066.y"
                                                                                                                                                                                                       {
		printLog("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-11].symbolInfo), (yyvsp[-10].symbolInfo), (yyvsp[-9].symbolInfo), (yyvsp[-7].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		auto S1 = (yyvsp[-9].symbolInfo);
		auto B = (yyvsp[-7].symbolInfo);
		auto S2 = (yyvsp[-4].symbolInfo);
		auto S3 = (yyvsp[0].symbolInfo);
		auto M1 = (yyvsp[-8].symbolInfo);
		auto M2 = (yyvsp[-5].symbolInfo);
		auto M3 = (yyvsp[-1].symbolInfo);

		normal_expression_to_logic(B);

		backpatch(B->getTrueList(), M3->getLabel());
		backpatch(S3->getNextList(), M2->getLabel());
		// $$->setNextList(merge(B->getFalseList(), S3->getNextList()));
		(yyval.symbolInfo)->setNextList(B->getFalseList());
		genCode("\tJMP " + M2->getLabel());

	}
#line 1888 "y.tab.c"
    break;

  case 40: /* statement: IF LPAREN expression P RPAREN M statement  */
#line 356 "1905066.y"
                                                                          {
		printLog("statement : IF LPAREN expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-6].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		backpatch((yyvsp[-4].symbolInfo)->getTrueList(), (yyvsp[-1].symbolInfo)->getLabel());
		(yyval.symbolInfo)->setNextList(merge((yyvsp[-4].symbolInfo)->getFalseList(), (yyvsp[0].symbolInfo)->getNextList()));

	}
#line 1903 "y.tab.c"
    break;

  case 41: /* statement: IF LPAREN expression P RPAREN M statement ELSE N M statement  */
#line 366 "1905066.y"
                                                                       {
		printLog("statement : IF LPAREN expression RPAREN statement ELSE statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-10].symbolInfo), (yyvsp[-9].symbolInfo), (yyvsp[-8].symbolInfo), (yyvsp[-6].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		auto B = (yyvsp[-8].symbolInfo);
		auto M1 = (yyvsp[-5].symbolInfo);
		auto M2 = (yyvsp[-1].symbolInfo);
		auto N = (yyvsp[-2].symbolInfo);
		auto S1 = (yyvsp[-4].symbolInfo);
		auto S2 = (yyvsp[0].symbolInfo);

		backpatch(B->getTrueList(), M1->getLabel());
		backpatch(B->getFalseList(), M2->getLabel());
		auto temp = merge(S1->getNextList(), N->getNextList());
		(yyval.symbolInfo)->setNextList(merge(temp, S2->getNextList()));

	}
#line 1927 "y.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 385 "1905066.y"
                                    { normal_expression_to_logic((yyvsp[0].symbolInfo)); }
#line 1933 "y.tab.c"
    break;

  case 43: /* statement: WHILE M LPAREN expression $@9 RPAREN M statement  */
#line 385 "1905066.y"
                                                                                           {
		printLog("statement : WHILE LPAREN expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-7].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo)});

		//------------------code generation------------------
		auto M1 = (yyvsp[-6].symbolInfo);
		auto B = (yyvsp[-4].symbolInfo);
		auto M2 = (yyvsp[-1].symbolInfo);
		auto S1 = (yyvsp[-2].symbolInfo);

		backpatch(S1->getNextList(), M1->getLabel());
		backpatch(B->getTrueList(), M2->getLabel());
		(yyval.symbolInfo)->setNextList(B->getFalseList());
		genCode("\tJMP " + M1->getLabel());
	}
#line 1954 "y.tab.c"
    break;

  case 44: /* statement: PRINTLN LPAREN expression RPAREN SEMICOLON  */
#line 419 "1905066.y"
                                                      {
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		printExpression((yyvsp[-2].symbolInfo), true);
	}
#line 1964 "y.tab.c"
    break;

  case 45: /* statement: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 424 "1905066.y"
                                                   {
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		printExpression((yyvsp[-2].symbolInfo), false);
	}
#line 1974 "y.tab.c"
    break;

  case 46: /* statement: RETURN expression SEMICOLON  */
#line 429 "1905066.y"
                                      {
		printLog("statement : RETURN expression SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		genCode("\tPOP AX");
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 1989 "y.tab.c"
    break;

  case 47: /* statement: RETURN SEMICOLON  */
#line 439 "1905066.y"
                          {
		printLog("statement : RETURN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 2001 "y.tab.c"
    break;

  case 48: /* statement: PRINTLN LPAREN CONST_STRING RPAREN SEMICOLON  */
#line 446 "1905066.y"
                                                       {
		printLog("statement : PRINTLN LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		printString((yyvsp[-2].symbolInfo), true);
	}
#line 2014 "y.tab.c"
    break;

  case 49: /* statement: PRINT LPAREN CONST_STRING RPAREN SEMICOLON  */
#line 454 "1905066.y"
                                                     {
		printLog("statement : PRINTLN LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		printString((yyvsp[-2].symbolInfo), false);
	}
#line 2027 "y.tab.c"
    break;

  case 50: /* statement: SCANINT LPAREN variable RPAREN SEMICOLON  */
#line 462 "1905066.y"
                                                  {
		genCode("\tCALL int_intput");
		genCode("\tMOV AX, INT_");
		if((yyvsp[-4].symbolInfo)->isArray() && !(yyvsp[-4].symbolInfo)->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV " + (yyvsp[-2].symbolInfo)->getAsmName() + ", AX");
	}
#line 2038 "y.tab.c"
    break;

  case 51: /* P: %empty  */
#line 470 "1905066.y"
    {	
		normal_expression_to_logic((yyvsp[0].symbolInfo)); 
	}
#line 2046 "y.tab.c"
    break;

  case 52: /* expression_statement: SEMICOLON  */
#line 474 "1905066.y"
                                 {
		printLog("expression_statement : SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("expression_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2056 "y.tab.c"
    break;

  case 53: /* expression_statement: expression SEMICOLON  */
#line 479 "1905066.y"
                               {
		printLog("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("expression_statement", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[-1].symbolInfo));
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		//------------------code generation------------------
		genCode("\tPOP AX");
	}
#line 2069 "y.tab.c"
    break;

  case 54: /* variable: ID  */
#line 489 "1905066.y"
              {
		printLog("variable : ID");
		
		auto symbol = checkValidVar((yyvsp[0].symbolInfo));
		
		if(symbol) (yyval.symbolInfo) = new SymbolInfo(symbol);
		else (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo));
		
		(yyval.symbolInfo)->setName("variable");
		(yyval.symbolInfo)->setType("non-terminal");

		
		if(symbol) (yyval.symbolInfo)->setDataType(symbol->getDataType());
		else (yyval.symbolInfo)->setDataType("ERROR");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------code generation------------------
		// asmName is set in copy constructor
	}
#line 2093 "y.tab.c"
    break;

  case 55: /* variable: ID LTHIRD expression RTHIRD  */
#line 508 "1905066.y"
                                      {
		printLog("variable : ID LTHIRD expression RTHIRD");

		(yyvsp[-3].symbolInfo)->setArray();

		auto symbol = checkValidVar((yyvsp[-3].symbolInfo), true);
		if(symbol) (yyval.symbolInfo) = new SymbolInfo(symbol);
		else (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo));
		
		(yyval.symbolInfo)->setName("variable");
		(yyval.symbolInfo)->setType("non-terminal");

		
		if(symbol) (yyval.symbolInfo)->setDataType(symbol->getDataType());
		else (yyval.symbolInfo)->setDataType("ERROR");
		
		if((yyvsp[-1].symbolInfo)->getDataType() != "INT"){
			// index must be integer
			std::string error_message = "Array subscript is not an integer";
			semanticError((yyvsp[-1].symbolInfo)->getStartLine(), error_message);
		}
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------code generation------------------
		genCode("\tPOP AX");							// get the value of index from expression(stack)
		genCode("\tSHL AX, 1"); 						// multiply by 2
		genCode("\tLEA BX, " + symbol->getAsmName()); 	// get the address of array[0]
		genCode("\tSUB BX, AX"); 						// get the address of array[index]
		genCode("\tPUSH BX"); 							// push the address of array[index] to stack
		(yyval.symbolInfo)->setAsmName("[BX]"); 
	}
#line 2130 "y.tab.c"
    break;

  case 56: /* N: %empty  */
#line 542 "1905066.y"
    {
		(yyval.symbolInfo) = new SymbolInfo();
		(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 2140 "y.tab.c"
    break;

  case 57: /* M: %empty  */
#line 549 "1905066.y"
    {
		std::string label = new_label();
		(yyval.symbolInfo) = new SymbolInfo();
		(yyval.symbolInfo)->setLabel(label);

		//------------------code generation------------------
		genCode(label + ":");
	}
#line 2153 "y.tab.c"
    break;

  case 58: /* expression: logic_expression  */
#line 562 "1905066.y"
                              {
		printLog("expression : logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2164 "y.tab.c"
    break;

  case 59: /* expression: variable ASSIGNOP logic_expression  */
#line 568 "1905066.y"
                                             {
		printLog("expression : variable ASSIGNOP logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-2].symbolInfo)->getDataType());
		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// can't assign  void
			(yyval.symbolInfo)->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
		}

		else if((yyvsp[-2].symbolInfo)->getDataType() == "VOID"){
			// can't assign to  void
			(yyval.symbolInfo)->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError((yyvsp[-2].symbolInfo)->getStartLine(), error_message);
		}

		if((yyvsp[-2].symbolInfo)->getDataType() == "INT" && (yyvsp[0].symbolInfo)->getDataType() == "FLOAT"){
			std::string error_message = "Warning: possible loss of data in assignment of FLOAT to INT";
			semanticError((yyvsp[-2].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------code generation------------------

		(yyval.symbolInfo)->clearNextList();
		if(!(yyvsp[0].symbolInfo)->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch((yyvsp[0].symbolInfo)->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch((yyvsp[0].symbolInfo)->getFalseList(), label);

			label = new_label();
			genCode(label + ":");
			backpatch((yyval.symbolInfo)->getNextList(), label);			
		}
		genCode("\tPOP AX");
		if((yyvsp[-2].symbolInfo)->isArray() && !(yyvsp[-2].symbolInfo)->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV " + (yyvsp[-2].symbolInfo)->getAsmName() + ", AX");
		genCode("\tPUSH AX");
		(yyval.symbolInfo)->clearNextList();
	}
#line 2220 "y.tab.c"
    break;

  case 60: /* logic_expression: rel_expression  */
#line 621 "1905066.y"
                                  {
		printLog("logic_expression : rel_expression");
		(yyval.symbolInfo) = new SymbolInfo("logic_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2231 "y.tab.c"
    break;

  case 61: /* logic_expression: rel_expression LOGICOP M rel_expression  */
#line 627 "1905066.y"
                                                  {
		printLog("logic_expression : rel_expression LOGICOP rel_expression");
		(yyval.symbolInfo) = new SymbolInfo("logic_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");

		if((yyvsp[-3].symbolInfo)->getDataType() == "VOID" || (yyvsp[-1].symbolInfo)->getDataType() == "VOID"){
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "Can't do logic operations void";
			// semanticError($3->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo)});

		// ------------------code generation------------------
		// short circuit code and backpatching
		SymbolInfo* B = (yyval.symbolInfo);
		SymbolInfo* B1 = (yyvsp[-3].symbolInfo);
		SymbolInfo* B2 = (yyvsp[0].symbolInfo);

		// careful with the order
		normal_expression_to_logic(B2);
		normal_expression_to_logic(B1);

		if((yyvsp[-2].symbolInfo)->getName() == "&&"){
			backpatch(B1->getTrueList(), (yyvsp[-1].symbolInfo)->getLabel());
			B->setTrueList(B2->getTrueList());
			B->setFalseList(merge(B1->getFalseList(), B2->getFalseList()));
		}
		else if((yyvsp[-2].symbolInfo)->getName() == "||"){
			backpatch(B1->getFalseList(), (yyvsp[-1].symbolInfo)->getLabel());
			B->setFalseList(B2->getFalseList());
			B->setTrueList(merge(B1->getTrueList(), B2->getTrueList()));
		}
		genCode("\tPUSH AX");
	}
#line 2271 "y.tab.c"
    break;

  case 62: /* rel_expression: simple_expression  */
#line 664 "1905066.y"
                                   {
		printLog("rel_expression : simple_expression");
		(yyval.symbolInfo) = new SymbolInfo("rel_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2283 "y.tab.c"
    break;

  case 63: /* rel_expression: simple_expression RELOP simple_expression  */
#line 671 "1905066.y"
                                                    {
		printLog("rel_expression : simple_expression RELOP simple_expression");
		(yyval.symbolInfo) = new SymbolInfo("rel_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");

		if((yyvsp[-2].symbolInfo)->getDataType() == "VOID" || (yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// can't compare void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "Can't compare void";
			// semanticError($3->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------code generation------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		genCode("\tCMP AX, BX");

		(yyval.symbolInfo)->addToTrueList(temp_asm_line_count);
		(yyval.symbolInfo)->addToFalseList(temp_asm_line_count + 1);

		string op = (yyvsp[-1].symbolInfo)->getName();
		if(op == "<") genCode("\tJL ");
		else if(op == ">") genCode("\tJG ");
		else if(op == "<=") genCode("\tJLE ");
		else if(op == ">=") genCode("\tJGE ");
		else if(op == "==") genCode("\tJE ");
		else if(op == "!=") genCode("\tJNE ");
		
		genCode("\tJMP ");
	}
#line 2320 "y.tab.c"
    break;

  case 64: /* simple_expression: term  */
#line 705 "1905066.y"
                         {
		printLog("simple_expression : term");
		(yyval.symbolInfo) = new SymbolInfo("simple_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2332 "y.tab.c"
    break;

  case 65: /* simple_expression: simple_expression ADDOP term  */
#line 712 "1905066.y"
                                       {
		printLog("simple_expression : simple_expression ADDOP term");
		(yyval.symbolInfo) = new SymbolInfo("simple_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType(typecast((yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)));

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			std::string error_message = "Can't add void";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
			(yyval.symbolInfo)->setDataType("VOID");
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		if((yyvsp[-1].symbolInfo)->getName() == "+") genCode("\tADD AX, BX");
		else genCode("\tSUB AX, BX");
		genCode("\tPUSH AX");
	}
#line 2357 "y.tab.c"
    break;

  case 66: /* term: unary_expression  */
#line 734 "1905066.y"
                        {
		printLog("term : unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("term", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
	}
#line 2370 "y.tab.c"
    break;

  case 67: /* term: term MULOP unary_expression  */
#line 742 "1905066.y"
                                      {
		printLog("term : term MULOP unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("term", "non-terminal");
		(yyval.symbolInfo)->setDataType(typecast((yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)));

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// unary expression can't be void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($3->getStartLine(), error_message);
		}

		if((yyvsp[-1].symbolInfo)->getName() == "%" && ((yyvsp[-2].symbolInfo)->getDataType() != "INT" || (yyvsp[0].symbolInfo)->getDataType() != "INT")){
			// not int in modulus
			(yyval.symbolInfo)->setDataType("INT");
			std::string error_message = "Operands of modulus must be integers ";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
		}

		else if(((yyvsp[-1].symbolInfo)->getName() == "/" || (yyvsp[-1].symbolInfo)->getName() == "%") && (yyvsp[0].symbolInfo)->getValue() == "0"){
			// division by zero
			std::string error_message = "Warning: division by zero";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		//genCode("\tXOR DX, DX");
		genCode("\tCWD");
		if((yyvsp[-1].symbolInfo)->getName() == "*") genCode("\tIMUL BX");
		else genCode("\tIDIV BX");

		if((yyvsp[-1].symbolInfo)->getName() != "%") genCode("\tPUSH AX");
		else genCode("\tPUSH DX");

		/*	multiply A x B
			code : IMUL source
				A: source
				B: ax
				Product (ms 16 bits): dx 
				Product (ls 16 bits): ax

			division
			code : IDIV source
				Divisor: source; Dividend: dx:ax 
				Quotient: ax; Remainder: dx
		*/
		
	}
#line 2427 "y.tab.c"
    break;

  case 68: /* unary_expression: ADDOP unary_expression  */
#line 796 "1905066.y"
                                          {
		printLog("unary_expression : ADDOP unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// unary expression can't be void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		if((yyvsp[-1].symbolInfo)->getName() == "-"){
			genCode("\tPOP AX");
			genCode("\tNEG AX");
			genCode("\tPUSH AX");
		}
	}
#line 2453 "y.tab.c"
    break;

  case 69: /* unary_expression: NOT unary_expression  */
#line 817 "1905066.y"
                               {
		printLog("unary_expression : NOT unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// unary expression can't be void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		// genCode("\tPOP AX");
		// genCode("\tCMP AX, 0");

		// string label1 = "LL0";
		// string label2 = "LL1";

		// genCode("\tJNE " + label1);
		// genCode("\tPUSH 1");
		// genCode("\tJMP " + label2);
		// genCode(label1 + ":");
		// genCode("\tPUSH 0");
		// genCode(label2 + ":");

		(yyval.symbolInfo)->setTrueList((yyvsp[0].symbolInfo)->getFalseList());
		(yyval.symbolInfo)->setFalseList((yyvsp[0].symbolInfo)->getTrueList());

	}
#line 2489 "y.tab.c"
    break;

  case 70: /* unary_expression: factor  */
#line 848 "1905066.y"
                 {
		printLog("unary_expression : factor");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getValue());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
	}
#line 2503 "y.tab.c"
    break;

  case 71: /* factor: variable  */
#line 859 "1905066.y"
                  {
		printLog("factor : variable");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setArray((yyvsp[0].symbolInfo)->isArray());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ---------------------Code generation---------------------
		if((yyvsp[0].symbolInfo)->isArray() && !(yyvsp[0].symbolInfo)->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV AX, " + (yyvsp[0].symbolInfo)->getAsmName());
		genCode("\tPUSH AX");

	}
#line 2521 "y.tab.c"
    break;

  case 72: /* factor: ID LPAREN argument_list RPAREN  */
#line 872 "1905066.y"
                                         {
		printLog("factor : ID LPAREN argument_list RPAREN");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("");

		SymbolInfo *symbol= symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());

		if(!symbol){
			std::string error_message = "Undeclared function '" + (yyvsp[-3].symbolInfo)->getName() + "'";
			semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			(yyval.symbolInfo)->setDataType("ERROR");
		}
		
		else{
			
			(yyval.symbolInfo)->setDataType(symbol->getDataType());
			// if not function
			if(!symbol->isFunction()){
				std::string error_message = (yyvsp[-3].symbolInfo)->getName() + " is not a function";
				semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			}

			// else if paramater size not equal
			else if(symbol->getParamCount() > (yyvsp[-1].symbolInfo)->getParamCount()){
				std::string error_message = "Too few arguments to function '" + (yyvsp[-3].symbolInfo)->getName() + "'";
				semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			}

			else if(symbol->getParamCount() < (yyvsp[-1].symbolInfo)->getParamCount()){
				std::string error_message = "Too many arguments to function '" + (yyvsp[-3].symbolInfo)->getName() + "'";
				semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			}

			// else if parameter type mismatch
			else{
				vector<SymbolInfo*> params = symbol->getParams();
				vector<SymbolInfo*> args = (yyvsp[-1].symbolInfo)->getParams();

				for(int i=0; i<params.size(); i++){

					if(params[i]->getDataType() != args[i]->getDataType()){
						
						// typecast?
						if(!(params[i]->getDataType() == "INT" || params[i]->getDataType() == "FLOAT") && (args[i]->getDataType() == "INT" || args[i]->getDataType() == "FLOAT"))
						{
							std::string error_message = "Parameter type mismatch ( For " + std::to_string(i+1) +"th parameter ) in function " + symbol->getName() + " at line " + std::to_string(symbol->getStartLine());
							semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
						}
					}
				}
			} 
		}

		if((yyvsp[-1].symbolInfo)->getChildrenSize() == 0) (yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		else (yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});


		// ---------------------Code generation---------------------
		genCode("\tCALL " + (yyvsp[-3].symbolInfo)->getName());
		if((yyval.symbolInfo)->getDataType() != "VOID") genCode("\tPUSH AX");
		else genCode("\tPUSH 0");
	}
#line 2588 "y.tab.c"
    break;

  case 73: /* factor: LPAREN expression RPAREN  */
#line 934 "1905066.y"
                                   {
		printLog("factor : LPAREN expression RPAREN");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		(yyval.symbolInfo)->setTrueList((yyvsp[-1].symbolInfo)->getTrueList());
		(yyval.symbolInfo)->setFalseList((yyvsp[-1].symbolInfo)->getFalseList());
	}
#line 2603 "y.tab.c"
    break;

  case 74: /* factor: CONST_INT  */
#line 944 "1905066.y"
                    {
		printLog("factor : CONST_INT");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getName());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ---------------------Code generation---------------------
		// genCode("\tMOV AX, " + $1->getName());
		// genCode("\tPUSH AX");
		genCode("\tPUSH " + (yyvsp[0].symbolInfo)->getName());
	}
#line 2620 "y.tab.c"
    break;

  case 75: /* factor: CONST_FLOAT  */
#line 956 "1905066.y"
                      {
		printLog("factor : CONST_FLOAT");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("FLOAT");
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getName());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2632 "y.tab.c"
    break;

  case 76: /* factor: variable INCOP  */
#line 963 "1905066.y"
                         {
		printLog("factor: variable INCOP");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");

		if((yyvsp[-1].symbolInfo)->isArray()){
			// array can't be incremented
			std::string error_message = "Array can't be incremented";
			semanticError((yyvsp[-1].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genINC_DEC((yyvsp[-1].symbolInfo), "++");
	}
#line 2653 "y.tab.c"
    break;

  case 77: /* factor: variable DECOP  */
#line 979 "1905066.y"
                         {
		printLog("factor: variable DECOP");
		
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");

		if((yyvsp[-1].symbolInfo)->isArray()){
			// array can't be decremented
			std::string error_message = "Array can't be decremented";
			semanticError((yyvsp[-1].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genINC_DEC((yyvsp[-1].symbolInfo), "--");
	}
#line 2675 "y.tab.c"
    break;

  case 78: /* argument_list: arguments  */
#line 998 "1905066.y"
                          {
		printLog("argument_list : arguments");
		(yyval.symbolInfo) = new SymbolInfo("argument_list", "non-terminal");
		(yyval.symbolInfo)->setParams((yyvsp[0].symbolInfo)->getParams());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2686 "y.tab.c"
    break;

  case 79: /* argument_list: %empty  */
#line 1004 "1905066.y"
          {
		printLog("argument_list : ");
		(yyval.symbolInfo) = new SymbolInfo("argument_list", "non-terminal");
	}
#line 2695 "y.tab.c"
    break;

  case 80: /* arguments: arguments COMMA logic_expression  */
#line 1010 "1905066.y"
                                             {
		printLog("arguments : arguments COMMA logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("arguments", "non-terminal");
		(yyval.symbolInfo)->setParams((yyvsp[-2].symbolInfo)->getParams());
		(yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo));					 
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 2707 "y.tab.c"
    break;

  case 81: /* arguments: logic_expression  */
#line 1017 "1905066.y"
                           {
		printLog("arguments : logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("arguments", "non-terminal");
		(yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2718 "y.tab.c"
    break;


#line 2722 "y.tab.c"

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

#line 1025 "1905066.y"

int main(int argc,char *argv[])
{
	FILE* fp;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	
	yyin=fp;
	errorOut.open("1905066_error.txt");
	logout.open("1905066_log.txt");
	parseTreeOut.open("1905066_parseTree.txt");
	
	
	asmInit();
	
	yyparse();
	yylex_destroy();

	generate_asm_file();
	generate_Optimize_Code();
	closeAsmFiles();
	
	errorOut.close();
	logout.close();
	parseTreeOut.close();
	

	return 0;
}

