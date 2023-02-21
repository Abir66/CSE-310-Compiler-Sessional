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
    INCOP = 278,                   /* INCOP  */
    DECOP = 279,                   /* DECOP  */
    ASSIGNOP = 280,                /* ASSIGNOP  */
    NOT = 281,                     /* NOT  */
    ID = 282,                      /* ID  */
    INT = 283,                     /* INT  */
    FLOAT = 284,                   /* FLOAT  */
    DOUBLE = 285,                  /* DOUBLE  */
    CONST_INT = 286,               /* CONST_INT  */
    CONST_FLOAT = 287,             /* CONST_FLOAT  */
    CHAR = 288,                    /* CHAR  */
    VOID = 289,                    /* VOID  */
    ADDOP = 290,                   /* ADDOP  */
    MULOP = 291,                   /* MULOP  */
    RELOP = 292,                   /* RELOP  */
    LOGICOP = 293,                 /* LOGICOP  */
    BITOP = 294,                   /* BITOP  */
    LOWER_THAN_ELSE = 295          /* LOWER_THAN_ELSE  */
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
#define INCOP 278
#define DECOP 279
#define ASSIGNOP 280
#define NOT 281
#define ID 282
#define INT 283
#define FLOAT 284
#define DOUBLE 285
#define CONST_INT 286
#define CONST_FLOAT 287
#define CHAR 288
#define VOID 289
#define ADDOP 290
#define MULOP 291
#define RELOP 292
#define LOGICOP 293
#define BITOP 294
#define LOWER_THAN_ELSE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "1905066.y"

    SymbolInfo* symbolInfo; 

#line 223 "y.tab.c"

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
  YYSYMBOL_INCOP = 23,                     /* INCOP  */
  YYSYMBOL_DECOP = 24,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 25,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_ID = 27,                        /* ID  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_FLOAT = 29,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 30,                    /* DOUBLE  */
  YYSYMBOL_CONST_INT = 31,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 32,               /* CONST_FLOAT  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_VOID = 34,                      /* VOID  */
  YYSYMBOL_ADDOP = 35,                     /* ADDOP  */
  YYSYMBOL_MULOP = 36,                     /* MULOP  */
  YYSYMBOL_RELOP = 37,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 38,                   /* LOGICOP  */
  YYSYMBOL_BITOP = 39,                     /* BITOP  */
  YYSYMBOL_LOWER_THAN_ELSE = 40,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_start = 42,                     /* start  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_unit = 44,                      /* unit  */
  YYSYMBOL_func_declaration = 45,          /* func_declaration  */
  YYSYMBOL_func_definition = 46,           /* func_definition  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_parameter_list = 49,            /* parameter_list  */
  YYSYMBOL_compound_statement = 50,        /* compound_statement  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_var_declaration = 53,           /* var_declaration  */
  YYSYMBOL_type_specifier = 54,            /* type_specifier  */
  YYSYMBOL_declaration_list = 55,          /* declaration_list  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_P = 63,                         /* P  */
  YYSYMBOL_expression_statement = 64,      /* expression_statement  */
  YYSYMBOL_variable = 65,                  /* variable  */
  YYSYMBOL_N = 66,                         /* N  */
  YYSYMBOL_M = 67,                         /* M  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_logic_expression = 69,          /* logic_expression  */
  YYSYMBOL_rel_expression = 70,            /* rel_expression  */
  YYSYMBOL_simple_expression = 71,         /* simple_expression  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_unary_expression = 73,          /* unary_expression  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_argument_list = 75,             /* argument_list  */
  YYSYMBOL_arguments = 76                  /* arguments  */
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
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    41,    46,    53,    58,    64,    72,    81,
      91,    91,   113,   113,   132,   144,   153,   162,   173,   173,
     188,   188,   197,   222,   228,   234,   242,   249,   257,   265,
     276,   276,   287,   287,   298,   303,   329,   337,   337,   337,
     360,   370,   389,   389,   423,   449,   462,   466,   471,   481,
     500,   534,   541,   554,   560,   613,   619,   656,   663,   697,
     704,   726,   734,   787,   808,   839,   850,   863,   925,   935,
     947,   954,   970,   989,   995,  1001,  1008
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
  "COMMA", "SEMICOLON", "PRINTLN", "INCOP", "DECOP", "ASSIGNOP", "NOT",
  "ID", "INT", "FLOAT", "DOUBLE", "CONST_INT", "CONST_FLOAT", "CHAR",
  "VOID", "ADDOP", "MULOP", "RELOP", "LOGICOP", "BITOP", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "$@3", "$@4", "var_declaration", "type_specifier", "declaration_list",
  "statements", "$@5", "$@6", "statement", "$@7", "$@8", "$@9", "P",
  "expression_statement", "variable", "N", "M", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -76,   -76,   -76,    15,    16,   -76,   -76,   -76,   -76,
      -6,   -76,   -76,    -7,    38,     4,     6,     2,   -76,    26,
      -2,    36,    62,    66,   -76,    70,    68,    16,   -76,   -76,
      56,    75,   -76,   -76,    70,    64,    78,   -76,    76,   -76,
     -76,   -76,    77,    74,   -76,   -76,   -76,    85,    90,   -76,
      84,    84,   -76,    93,    84,    43,   -76,   -76,    84,   -76,
     -76,    86,   -76,   -76,    46,    91,   -76,    79,    29,    82,
     -76,   -76,    74,    84,    -4,   100,    99,   106,    84,    49,
     -76,    84,    84,   -76,   104,   -76,   -76,    84,   -76,   -76,
      84,    84,    84,   -76,   -76,   -76,    84,   -76,   -76,   108,
     -76,   109,   105,   107,   -76,    84,    82,    92,   -76,   113,
      -4,   -76,   110,   -76,    84,   -76,   -76,   -76,   -76,   114,
     -76,   -76,    74,   -76,   -76,   126,    84,    74,   -76,   -76,
     -76,   -76,   117,    74,   -76,   -76,    74,   -76
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
      14,    27,    52,     0,    21,    19,    32,     0,     0,    52,
       0,     0,    47,     0,     0,    49,    69,    70,     0,    36,
      34,     0,    31,    35,    66,     0,    53,    55,    57,    59,
      61,    65,     0,     0,     0,     0,     0,     0,     0,    66,
      64,    74,     0,    63,    28,    71,    72,     0,    48,    52,
       0,     0,     0,    33,    46,    52,     0,    45,    68,     0,
      76,     0,    73,     0,    54,     0,    60,    58,    62,     0,
       0,    42,     0,    67,     0,    50,    56,    52,    37,     0,
      44,    75,     0,    52,    52,    40,     0,     0,    51,    38,
      43,    52,     0,     0,    52,    41,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   128,   -76,   -76,   -76,   -76,   -76,     1,
     -76,   -76,    55,     9,   -76,   -76,   -76,   -76,   -71,   -76,
     -76,   -76,   -76,   -69,   -38,   -76,   -49,   -48,   -75,    30,
      45,    44,   -50,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    25,    20,    59,
      37,    38,    60,    61,    14,    42,    43,    72,    62,   123,
     132,   119,   109,    63,    64,   131,    46,    65,    66,    67,
      68,    69,    70,    71,   101,   102
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    93,    76,    77,    80,    95,   100,    15,    83,    10,
      51,    16,   104,    26,    10,    11,    79,    52,    27,    19,
      79,    13,    54,    55,    21,    94,    32,    56,    57,    23,
      99,    58,     1,     2,   103,    39,    35,    22,     3,   121,
     105,   118,   108,    79,     1,     2,   110,    24,   111,    79,
       3,   125,    79,    79,    79,     9,   130,    81,    17,    18,
       9,    82,   135,    28,    90,   137,    91,    79,   122,    85,
      86,    87,    85,    86,   126,   127,    79,    47,   129,    48,
      49,    29,   133,    50,    30,   136,    31,    36,    51,    33,
      31,    40,   -20,    44,    45,    52,    53,    41,    51,    73,
      54,    55,     1,     2,    74,    56,    57,    78,     3,    58,
      54,    55,    88,    84,    96,    56,    57,    89,    92,    58,
      97,    98,    16,   112,   113,   114,   115,    90,   117,   124,
     128,   120,   134,    12,   106,   116,   107
};

static const yytype_uint8 yycheck[] =
{
      49,    72,    50,    51,    54,    74,    81,    14,    58,     0,
      14,    18,    87,    15,     5,     0,    54,    21,    20,    15,
      58,    27,    26,    27,    15,    73,    25,    31,    32,    27,
      78,    35,    28,    29,    82,    34,    27,    31,    34,   114,
      89,   110,    92,    81,    28,    29,    95,    21,    96,    87,
      34,   122,    90,    91,    92,     0,   127,    14,    20,    21,
       5,    18,   133,    27,    35,   136,    37,   105,   117,    23,
      24,    25,    23,    24,   123,   124,   114,     3,   126,     5,
       6,    19,   131,     9,    18,   134,    16,    31,    14,    21,
      16,    27,    17,    17,    17,    21,    22,    19,    14,    14,
      26,    27,    28,    29,    14,    31,    32,    14,    34,    35,
      26,    27,    21,    27,    14,    31,    32,    38,    36,    35,
      21,    15,    18,    15,    15,    20,    19,    35,    15,    15,
       4,    21,    15,     5,    90,   105,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,    34,    42,    43,    44,    45,    46,    53,
      54,     0,    44,    27,    55,    14,    18,    20,    21,    15,
      49,    54,    31,    27,    21,    48,    15,    20,    27,    19,
      18,    16,    50,    21,    47,    54,    31,    51,    52,    50,
      27,    19,    56,    57,    17,    17,    67,     3,     5,     6,
       9,    14,    21,    22,    26,    27,    31,    32,    35,    50,
      53,    54,    59,    64,    65,    68,    69,    70,    71,    72,
      73,    74,    58,    14,    14,    67,    68,    68,    14,    65,
      73,    14,    18,    73,    27,    23,    24,    25,    21,    38,
      35,    37,    36,    59,    68,    64,    14,    21,    15,    68,
      69,    75,    76,    68,    69,    67,    72,    71,    73,    63,
      67,    68,    15,    15,    20,    19,    70,    15,    64,    62,
      21,    69,    67,    60,    15,    59,    67,    67,     4,    68,
      59,    66,    61,    67,    15,    59,    67,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      47,    46,    48,    46,    49,    49,    49,    49,    51,    50,
      52,    50,    53,    54,    54,    54,    55,    55,    55,    55,
      57,    56,    58,    56,    59,    59,    59,    60,    61,    59,
      59,    59,    62,    59,    59,    59,    63,    64,    64,    65,
      65,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       0,     2,     0,     4,     1,     1,     1,     0,     0,    12,
       7,    11,     0,     8,     5,     3,     0,     1,     2,     1,
       4,     0,     0,     1,     3,     1,     4,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
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
#line 1375 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 41 "1905066.y"
                       {
		printLog("program : program unit");
		(yyval.symbolInfo) = new SymbolInfo("program", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1385 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 46 "1905066.y"
              {
		printLog("program : unit");
		(yyval.symbolInfo) = new SymbolInfo("program", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1395 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 53 "1905066.y"
                       {
		printLog("unit : var_declaration");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1405 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 59 "1905066.y"
        {
		printLog("unit : func_declaration");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1415 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 65 "1905066.y"
        {
		printLog("unit : func_definition");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1425 "y.tab.c"
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
#line 1439 "y.tab.c"
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
#line 1452 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 91 "1905066.y"
                                                                 { 
		addFunction((yyvsp[-3].symbolInfo), (yyvsp[-4].symbolInfo)->getDataType(), true);
		inGlobalScope = false;
		genFunctioninitCode((yyvsp[-3].symbolInfo)->getName());
	}
#line 1462 "y.tab.c"
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
#line 1485 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 113 "1905066.y"
                                          { 
		addFunction((yyvsp[-2].symbolInfo), (yyvsp[-3].symbolInfo)->getDataType(), true); 
		inGlobalScope = false;
		genFunctioninitCode((yyvsp[-2].symbolInfo)->getName());
	}
#line 1495 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 117 "1905066.y"
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
#line 1513 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 132 "1905066.y"
                                                        {
		printLog("parameter_list : parameter_list COMMA type_specifier ID");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", (yyvsp[-3].symbolInfo)->getType());

		(yyvsp[0].symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());

		if(!checkParamRedeclaration((yyvsp[0].symbolInfo))) params.push_back((yyvsp[0].symbolInfo));
		
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

	}
#line 1530 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 144 "1905066.y"
                                              {
		printLog("parameter_list : parameter_list COMMA type_specifier");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", (yyvsp[-2].symbolInfo)->getType());

		SymbolInfo* id = new SymbolInfo("", "ID", (yyvsp[0].symbolInfo)->getDataType());
		params.push_back(id);

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1544 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 153 "1905066.y"
                            {
		printLog("parameter_list : type_specifier ID");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", "non-terminal");

		(yyvsp[0].symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		if(!checkParamRedeclaration((yyvsp[0].symbolInfo))) params.push_back((yyvsp[0].symbolInfo));
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1558 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 162 "1905066.y"
                         {
		printLog("parameter_list : type_specifier");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", "non-terminal");

		SymbolInfo* id = new SymbolInfo("", "ID", (yyvsp[0].symbolInfo)->getDataType());
		params.push_back(id);

		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1572 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 173 "1905066.y"
                           {symbolTable->enterScope(); addParamsToScope();}
#line 1578 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@3 statements RCURL  */
#line 173 "1905066.y"
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
#line 1598 "y.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 188 "1905066.y"
                {symbolTable->enterScope(); addParamsToScope();}
#line 1604 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL $@4 RCURL  */
#line 188 "1905066.y"
                                                                       {
		printLog("compound_statement : LCURL RCURL");
		(yyval.symbolInfo) = new SymbolInfo("compound_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
#line 1616 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 197 "1905066.y"
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
#line 1644 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 222 "1905066.y"
                     {
		printLog("type_specifier : INT");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "INT", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1655 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 228 "1905066.y"
                {
		printLog("type_specifier : FLOAT");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "FLOAT", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1666 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 234 "1905066.y"
               {
		printLog("type_specifier : VOID");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "VOID", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1677 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 242 "1905066.y"
                                             {
		printLog("declaration_list : declaration_list COMMA ID");
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1689 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 249 "1905066.y"
                                                            {
		printLog("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		(yyvsp[-3].symbolInfo)->setArray(true, std::stoi((yyvsp[-1].symbolInfo)->getName()));
		vars.push_back((yyvsp[-3].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo),(yyvsp[-4].symbolInfo),(yyvsp[-3].symbolInfo),(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1702 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 257 "1905066.y"
             {
		printLog("declaration_list : ID");
		vars.clear();
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1715 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 265 "1905066.y"
                                     {
		printLog("declaration_list : ID LTHIRD CONST_INT RTHIRD");
		vars.clear();
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		(yyvsp[-3].symbolInfo)->setArray(true, std::stoi((yyvsp[-1].symbolInfo)->getName()));
		vars.push_back((yyvsp[-3].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo),(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1729 "y.tab.c"
    break;

  case 30: /* $@5: %empty  */
#line 276 "1905066.y"
             {genComment("------------------ Line " + to_string(line_count) + " ------------------");}
#line 1735 "y.tab.c"
    break;

  case 31: /* statements: $@5 statement  */
#line 276 "1905066.y"
                                                                                                                 {
		printLog("statements : statement");
		(yyval.symbolInfo) = new SymbolInfo("statements", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------ code generation ------------------
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
		
		// std::cout<<"here - "<<$2->getLabel()<<std::endl;
		// backpatch($1->getNextList(), $2->getLabel());
	}
#line 1751 "y.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 287 "1905066.y"
                       {genComment("------------------ Line " + to_string(line_count) + " ------------------");}
#line 1757 "y.tab.c"
    break;

  case 33: /* statements: statements M $@6 statement  */
#line 287 "1905066.y"
                                                                                                                           {
		printLog("statements : statements statement");
		(yyval.symbolInfo) = new SymbolInfo("statements", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------ code generation ------------------
		backpatch((yyvsp[-3].symbolInfo)->getNextList(), (yyvsp[-2].symbolInfo)->getLabel());
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
	}
#line 1771 "y.tab.c"
    break;

  case 34: /* statement: var_declaration  */
#line 298 "1905066.y"
                            {
		printLog("statement : var_declaration");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1781 "y.tab.c"
    break;

  case 35: /* statement: expression_statement  */
#line 303 "1905066.y"
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
#line 1812 "y.tab.c"
    break;

  case 36: /* statement: compound_statement  */
#line 329 "1905066.y"
                             {
		printLog("statement : compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------ code generation ------------------
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
	}
#line 1825 "y.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 337 "1905066.y"
                                                                 { normal_expression_to_logic((yyvsp[0].symbolInfo), false); }
#line 1831 "y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 337 "1905066.y"
                                                                                                                         {genCode("\tPOP AX"); genCode("\tJMP " + (yyvsp[-4].symbolInfo)->getLabel());}
#line 1837 "y.tab.c"
    break;

  case 39: /* statement: FOR LPAREN expression_statement M expression_statement $@7 M expression $@8 RPAREN M statement  */
#line 337 "1905066.y"
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
#line 1865 "y.tab.c"
    break;

  case 40: /* statement: IF LPAREN expression P RPAREN M statement  */
#line 360 "1905066.y"
                                                                          {
		printLog("statement : IF LPAREN expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-6].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		backpatch((yyvsp[-4].symbolInfo)->getTrueList(), (yyvsp[-1].symbolInfo)->getLabel());
		(yyval.symbolInfo)->setNextList(merge((yyvsp[-4].symbolInfo)->getFalseList(), (yyvsp[0].symbolInfo)->getNextList()));

	}
#line 1880 "y.tab.c"
    break;

  case 41: /* statement: IF LPAREN expression P RPAREN M statement ELSE N M statement  */
#line 370 "1905066.y"
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
#line 1904 "y.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 389 "1905066.y"
                                    { normal_expression_to_logic((yyvsp[0].symbolInfo)); }
#line 1910 "y.tab.c"
    break;

  case 43: /* statement: WHILE M LPAREN expression $@9 RPAREN M statement  */
#line 389 "1905066.y"
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
#line 1931 "y.tab.c"
    break;

  case 44: /* statement: PRINTLN LPAREN expression RPAREN SEMICOLON  */
#line 423 "1905066.y"
                                                      {
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");

		if(!(yyvsp[-2].symbolInfo)->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch((yyvsp[-2].symbolInfo)->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch((yyvsp[-2].symbolInfo)->getFalseList(), label);

			label = new_label();
			genCode(label + ":");
			backpatch((yyval.symbolInfo)->getNextList(), label);
			(yyval.symbolInfo)->setNextList({});		
		}

		genCode("\tPOP AX");
		genCode("\tCALL print_output");
		genCode("\tCALL new_line");
	}
#line 1962 "y.tab.c"
    break;

  case 45: /* statement: RETURN expression SEMICOLON  */
#line 449 "1905066.y"
                                      {
		printLog("statement : RETURN expression SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		genCode("\tPOP AX");
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
		
	}
#line 1978 "y.tab.c"
    break;

  case 46: /* P: %empty  */
#line 462 "1905066.y"
    {	
		normal_expression_to_logic((yyvsp[0].symbolInfo)); 
	}
#line 1986 "y.tab.c"
    break;

  case 47: /* expression_statement: SEMICOLON  */
#line 466 "1905066.y"
                                 {
		printLog("expression_statement : SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("expression_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1996 "y.tab.c"
    break;

  case 48: /* expression_statement: expression SEMICOLON  */
#line 471 "1905066.y"
                               {
		printLog("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("expression_statement", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[-1].symbolInfo));
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		//------------------code generation------------------
		genCode("\tPOP AX");
	}
#line 2009 "y.tab.c"
    break;

  case 49: /* variable: ID  */
#line 481 "1905066.y"
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
#line 2033 "y.tab.c"
    break;

  case 50: /* variable: ID LTHIRD expression RTHIRD  */
#line 500 "1905066.y"
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
#line 2070 "y.tab.c"
    break;

  case 51: /* N: %empty  */
#line 534 "1905066.y"
    {
		(yyval.symbolInfo) = new SymbolInfo();
		(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 2080 "y.tab.c"
    break;

  case 52: /* M: %empty  */
#line 541 "1905066.y"
    {
		std::string label = new_label();
		(yyval.symbolInfo) = new SymbolInfo();
		(yyval.symbolInfo)->setLabel(label);

		//------------------code generation------------------
		genCode(label + ":");
	}
#line 2093 "y.tab.c"
    break;

  case 53: /* expression: logic_expression  */
#line 554 "1905066.y"
                              {
		printLog("expression : logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2104 "y.tab.c"
    break;

  case 54: /* expression: variable ASSIGNOP logic_expression  */
#line 560 "1905066.y"
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
#line 2160 "y.tab.c"
    break;

  case 55: /* logic_expression: rel_expression  */
#line 613 "1905066.y"
                                  {
		printLog("logic_expression : rel_expression");
		(yyval.symbolInfo) = new SymbolInfo("logic_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2171 "y.tab.c"
    break;

  case 56: /* logic_expression: rel_expression LOGICOP M rel_expression  */
#line 619 "1905066.y"
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
#line 2211 "y.tab.c"
    break;

  case 57: /* rel_expression: simple_expression  */
#line 656 "1905066.y"
                                   {
		printLog("rel_expression : simple_expression");
		(yyval.symbolInfo) = new SymbolInfo("rel_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2223 "y.tab.c"
    break;

  case 58: /* rel_expression: simple_expression RELOP simple_expression  */
#line 663 "1905066.y"
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
#line 2260 "y.tab.c"
    break;

  case 59: /* simple_expression: term  */
#line 697 "1905066.y"
                         {
		printLog("simple_expression : term");
		(yyval.symbolInfo) = new SymbolInfo("simple_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2272 "y.tab.c"
    break;

  case 60: /* simple_expression: simple_expression ADDOP term  */
#line 704 "1905066.y"
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
#line 2297 "y.tab.c"
    break;

  case 61: /* term: unary_expression  */
#line 726 "1905066.y"
                        {
		printLog("term : unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("term", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
	}
#line 2310 "y.tab.c"
    break;

  case 62: /* term: term MULOP unary_expression  */
#line 734 "1905066.y"
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
		genCode("\tXOR DX, DX");
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
#line 2366 "y.tab.c"
    break;

  case 63: /* unary_expression: ADDOP unary_expression  */
#line 787 "1905066.y"
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
#line 2392 "y.tab.c"
    break;

  case 64: /* unary_expression: NOT unary_expression  */
#line 808 "1905066.y"
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
#line 2428 "y.tab.c"
    break;

  case 65: /* unary_expression: factor  */
#line 839 "1905066.y"
                 {
		printLog("unary_expression : factor");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getValue());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
	}
#line 2442 "y.tab.c"
    break;

  case 66: /* factor: variable  */
#line 850 "1905066.y"
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
#line 2460 "y.tab.c"
    break;

  case 67: /* factor: ID LPAREN argument_list RPAREN  */
#line 863 "1905066.y"
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
#line 2527 "y.tab.c"
    break;

  case 68: /* factor: LPAREN expression RPAREN  */
#line 925 "1905066.y"
                                   {
		printLog("factor : LPAREN expression RPAREN");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		(yyval.symbolInfo)->setTrueList((yyvsp[-1].symbolInfo)->getTrueList());
		(yyval.symbolInfo)->setFalseList((yyvsp[-1].symbolInfo)->getFalseList());
	}
#line 2542 "y.tab.c"
    break;

  case 69: /* factor: CONST_INT  */
#line 935 "1905066.y"
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
#line 2559 "y.tab.c"
    break;

  case 70: /* factor: CONST_FLOAT  */
#line 947 "1905066.y"
                      {
		printLog("factor : CONST_FLOAT");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("FLOAT");
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getName());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2571 "y.tab.c"
    break;

  case 71: /* factor: variable INCOP  */
#line 954 "1905066.y"
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
#line 2592 "y.tab.c"
    break;

  case 72: /* factor: variable DECOP  */
#line 970 "1905066.y"
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
#line 2614 "y.tab.c"
    break;

  case 73: /* argument_list: arguments  */
#line 989 "1905066.y"
                          {
		printLog("argument_list : arguments");
		(yyval.symbolInfo) = new SymbolInfo("argument_list", "non-terminal");
		(yyval.symbolInfo)->setParams((yyvsp[0].symbolInfo)->getParams());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2625 "y.tab.c"
    break;

  case 74: /* argument_list: %empty  */
#line 995 "1905066.y"
          {
		printLog("argument_list : ");
		(yyval.symbolInfo) = new SymbolInfo("argument_list", "non-terminal");
	}
#line 2634 "y.tab.c"
    break;

  case 75: /* arguments: arguments COMMA logic_expression  */
#line 1001 "1905066.y"
                                             {
		printLog("arguments : arguments COMMA logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("arguments", "non-terminal");
		(yyval.symbolInfo)->setParams((yyvsp[-2].symbolInfo)->getParams());
		(yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo));					 
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 2646 "y.tab.c"
    break;

  case 76: /* arguments: logic_expression  */
#line 1008 "1905066.y"
                           {
		printLog("arguments : logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("arguments", "non-terminal");
		(yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2657 "y.tab.c"
    break;


#line 2661 "y.tab.c"

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

#line 1016 "1905066.y"

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

