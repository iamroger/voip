/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 76 "cfg.y"


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#include "route.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "pvar.h"
#include "blacklists.h"
#include "xlog.h"
#include "tcp_server.h"
#include "tcp_conn.h"
#include "db/db_insertq.h"


#include "config.h"
#ifdef USE_TLS
#include "tls/tls_config.h"
#include "tls/tls_domain.h"
#endif

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H


extern int yylex();
static void yyerror(char* s);
static void yyerrorf(char* fmt, ...);
static char* tmp;
static int i_tmp;
static void* cmd_tmp;
static struct socket_id* lst_tmp;
static int rt;  /* Type of route block for find_export */
static str* str_tmp;
static str s_tmp;
static str tstr;
static struct ip_addr* ip_tmp;
static pv_spec_t *spec;
static pv_elem_t *pvmodel;
static struct bl_rule *bl_head = 0;
static struct bl_rule *bl_tail = 0;
static struct stat statf;

action_elem_t elems[MAX_ACTION_ELEMS];

static inline void warn(char* s);
static struct socket_id* mk_listen_id(char*, int, int);
static struct socket_id* set_listen_id_adv(struct socket_id *, char *, int);

static char *mpath=NULL;
static char mpath_buf[256];
static int  mpath_len = 0;

extern int line;

#define mk_action0(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		_res = mk_action(_type, 0, 0, line); \
	} while(0)
#define mk_action1(_res, _type, _p1_type, _p1) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		_res = mk_action(_type, 1, elems, line); \
	} while(0)
#define	mk_action2(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		_res = mk_action(_type, 2, elems, line); \
	} while(0)
#define mk_action3(_res, _type, _p1_type, _p2_type, _p3_type, _p1, _p2, _p3) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		elems[2].type = _p3_type; \
		elems[2].u.data = _p3; \
		_res = mk_action(_type, 3, elems, line); \
	} while(0)



/* Line 268 of yacc.c  */
#line 182 "cfg.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FORWARD = 258,
     SEND = 259,
     DROP = 260,
     EXIT = 261,
     RETURN = 262,
     LOG_TOK = 263,
     ERROR = 264,
     ROUTE = 265,
     ROUTE_FAILURE = 266,
     ROUTE_ONREPLY = 267,
     ROUTE_BRANCH = 268,
     ROUTE_ERROR = 269,
     ROUTE_LOCAL = 270,
     ROUTE_STARTUP = 271,
     ROUTE_TIMER = 272,
     SET_HOST = 273,
     SET_HOSTPORT = 274,
     PREFIX = 275,
     STRIP = 276,
     STRIP_TAIL = 277,
     APPEND_BRANCH = 278,
     REMOVE_BRANCH = 279,
     PV_PRINTF = 280,
     SET_USER = 281,
     SET_USERPASS = 282,
     SET_PORT = 283,
     SET_URI = 284,
     REVERT_URI = 285,
     SET_DSTURI = 286,
     RESET_DSTURI = 287,
     ISDSTURISET = 288,
     FORCE_RPORT = 289,
     FORCE_LOCAL_RPORT = 290,
     FORCE_TCP_ALIAS = 291,
     IF = 292,
     ELSE = 293,
     SWITCH = 294,
     CASE = 295,
     DEFAULT = 296,
     SBREAK = 297,
     WHILE = 298,
     SET_ADV_ADDRESS = 299,
     SET_ADV_PORT = 300,
     FORCE_SEND_SOCKET = 301,
     SERIALIZE_BRANCHES = 302,
     NEXT_BRANCHES = 303,
     USE_BLACKLIST = 304,
     UNUSE_BLACKLIST = 305,
     MAX_LEN = 306,
     SETDEBUG = 307,
     SETFLAG = 308,
     RESETFLAG = 309,
     ISFLAGSET = 310,
     SETBFLAG = 311,
     RESETBFLAG = 312,
     ISBFLAGSET = 313,
     SETSFLAG = 314,
     RESETSFLAG = 315,
     ISSFLAGSET = 316,
     METHOD = 317,
     URI = 318,
     FROM_URI = 319,
     TO_URI = 320,
     SRCIP = 321,
     SRCPORT = 322,
     DSTIP = 323,
     DSTPORT = 324,
     PROTO = 325,
     AF = 326,
     MYSELF = 327,
     MSGLEN = 328,
     UDP = 329,
     TCP = 330,
     TLS = 331,
     SCTP = 332,
     NULLV = 333,
     CACHE_STORE = 334,
     CACHE_FETCH = 335,
     CACHE_REMOVE = 336,
     CACHE_ADD = 337,
     CACHE_SUB = 338,
     XDBG = 339,
     XLOG = 340,
     XLOG_BUF_SIZE = 341,
     XLOG_FORCE_COLOR = 342,
     RAISE_EVENT = 343,
     SUBSCRIBE_EVENT = 344,
     CONSTRUCT_URI = 345,
     GET_TIMESTAMP = 346,
     DEBUG = 347,
     FORK = 348,
     LOGSTDERROR = 349,
     LOGFACILITY = 350,
     LOGNAME = 351,
     AVP_ALIASES = 352,
     LISTEN = 353,
     ALIAS = 354,
     AUTO_ALIASES = 355,
     DNS = 356,
     REV_DNS = 357,
     DNS_TRY_IPV6 = 358,
     DNS_RETR_TIME = 359,
     DNS_RETR_NO = 360,
     DNS_SERVERS_NO = 361,
     DNS_USE_SEARCH = 362,
     MAX_WHILE_LOOPS = 363,
     PORT = 364,
     CHILDREN = 365,
     CHECK_VIA = 366,
     MEMLOG = 367,
     MEMDUMP = 368,
     EXECMSGTHRESHOLD = 369,
     EXECDNSTHRESHOLD = 370,
     TCPTHRESHOLD = 371,
     QUERYBUFFERSIZE = 372,
     QUERYFLUSHTIME = 373,
     SIP_WARNING = 374,
     SOCK_MODE = 375,
     SOCK_USER = 376,
     SOCK_GROUP = 377,
     UNIX_SOCK = 378,
     UNIX_SOCK_CHILDREN = 379,
     UNIX_TX_TIMEOUT = 380,
     SERVER_SIGNATURE = 381,
     SERVER_HEADER = 382,
     USER_AGENT_HEADER = 383,
     LOADMODULE = 384,
     MPATH = 385,
     MODPARAM = 386,
     MAXBUFFER = 387,
     USER = 388,
     GROUP = 389,
     CHROOT = 390,
     WDIR = 391,
     MHOMED = 392,
     DISABLE_TCP = 393,
     TCP_ACCEPT_ALIASES = 394,
     TCP_CHILDREN = 395,
     TCP_CONNECT_TIMEOUT = 396,
     TCP_SEND_TIMEOUT = 397,
     TCP_CON_LIFETIME = 398,
     TCP_POLL_METHOD = 399,
     TCP_MAX_CONNECTIONS = 400,
     TCP_OPT_CRLF_PINGPONG = 401,
     TCP_NO_NEW_CONN_BFLAG = 402,
     TCP_KEEPALIVE = 403,
     TCP_KEEPCOUNT = 404,
     TCP_KEEPIDLE = 405,
     TCP_KEEPINTERVAL = 406,
     DISABLE_TLS = 407,
     TLSLOG = 408,
     TLS_PORT_NO = 409,
     TLS_METHOD = 410,
     TLS_HANDSHAKE_TIMEOUT = 411,
     TLS_SEND_TIMEOUT = 412,
     TLS_SERVER_DOMAIN = 413,
     TLS_CLIENT_DOMAIN = 414,
     TLS_CLIENT_DOMAIN_AVP = 415,
     SSLv23 = 416,
     SSLv2 = 417,
     SSLv3 = 418,
     TLSv1 = 419,
     TLS_VERIFY_CLIENT = 420,
     TLS_VERIFY_SERVER = 421,
     TLS_REQUIRE_CLIENT_CERTIFICATE = 422,
     TLS_CERTIFICATE = 423,
     TLS_PRIVATE_KEY = 424,
     TLS_CA_LIST = 425,
     TLS_CIPHERS_LIST = 426,
     ADVERTISED_ADDRESS = 427,
     ADVERTISED_PORT = 428,
     DISABLE_CORE = 429,
     OPEN_FD_LIMIT = 430,
     MCAST_LOOPBACK = 431,
     MCAST_TTL = 432,
     TOS = 433,
     DISABLE_DNS_FAILOVER = 434,
     DISABLE_DNS_BLACKLIST = 435,
     DST_BLACKLIST = 436,
     DISABLE_STATELESS_FWD = 437,
     DB_VERSION_TABLE = 438,
     DB_DEFAULT_URL = 439,
     DISABLE_503_TRANSLATION = 440,
     EQUAL = 441,
     EQUAL_T = 442,
     GT = 443,
     LT = 444,
     GTE = 445,
     LTE = 446,
     DIFF = 447,
     MATCH = 448,
     NOTMATCH = 449,
     COLONEQ = 450,
     PLUSEQ = 451,
     MINUSEQ = 452,
     SLASHEQ = 453,
     MULTEQ = 454,
     MODULOEQ = 455,
     BANDEQ = 456,
     BOREQ = 457,
     BXOREQ = 458,
     AND = 459,
     OR = 460,
     BRSHIFT = 461,
     BLSHIFT = 462,
     BXOR = 463,
     BAND = 464,
     BOR = 465,
     MODULO = 466,
     MULT = 467,
     SLASH = 468,
     MINUS = 469,
     PLUS = 470,
     BNOT = 471,
     NOT = 472,
     NUMBER = 473,
     ZERO = 474,
     ID = 475,
     STRING = 476,
     SCRIPTVAR = 477,
     IPV6ADDR = 478,
     COMMA = 479,
     SEMICOLON = 480,
     RPAREN = 481,
     LPAREN = 482,
     LBRACE = 483,
     RBRACE = 484,
     LBRACK = 485,
     RBRACK = 486,
     AS = 487,
     USE_CHILDREN = 488,
     DOT = 489,
     CR = 490,
     COLON = 491,
     ANY = 492,
     SCRIPTVARERR = 493
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 186 "cfg.y"

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct _pv_spec *specval;



/* Line 293 of yacc.c  */
#line 470 "cfg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 482 "cfg.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  200
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4019

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  607
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1249

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    18,
      21,    22,    25,    26,    29,    30,    33,    34,    37,    38,
      41,    42,    45,    46,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    76,    79,    81,
      85,    89,    95,    99,   101,   104,   106,   110,   114,   120,
     126,   134,   136,   139,   149,   160,   164,   166,   169,   173,
     177,   181,   185,   189,   193,   197,   201,   205,   209,   213,
     217,   221,   225,   229,   233,   237,   240,   244,   247,   251,
     254,   258,   261,   265,   268,   272,   276,   280,   284,   288,
     292,   296,   300,   304,   308,   312,   316,   320,   324,   328,
     332,   336,   340,   344,   348,   352,   356,   360,   364,   368,
     372,   376,   380,   384,   388,   392,   396,   400,   404,   408,
     412,   416,   420,   424,   428,   432,   436,   440,   444,   448,
     452,   456,   460,   464,   468,   472,   476,   480,   484,   488,
     492,   496,   500,   504,   508,   512,   516,   520,   524,   528,
     532,   536,   540,   544,   548,   552,   556,   560,   564,   568,
     572,   576,   580,   584,   588,   592,   596,   600,   604,   608,
     612,   616,   620,   624,   628,   632,   636,   640,   644,   648,
     652,   656,   660,   664,   668,   670,   672,   676,   680,   684,
     688,   692,   696,   700,   704,   708,   712,   716,   720,   724,
     728,   732,   736,   740,   744,   748,   752,   756,   760,   764,
     768,   772,   776,   780,   784,   788,   792,   796,   800,   804,
     808,   811,   815,   818,   826,   830,   834,   838,   842,   846,
     850,   854,   857,   860,   863,   872,   881,   884,   886,   888,
     896,   898,   900,   904,   905,   916,   917,   928,   929,   938,
     940,   943,   945,   948,   952,   956,   960,   964,   968,   972,
     976,   980,   984,   988,   992,   996,  1000,  1004,  1008,  1012,
    1016,  1020,  1024,  1028,  1032,  1036,  1040,  1044,  1048,  1052,
    1056,  1060,  1064,  1068,  1072,  1076,  1078,  1080,  1082,  1087,
    1095,  1098,  1106,  1109,  1114,  1122,  1125,  1133,  1136,  1141,
    1144,  1149,  1152,  1157,  1160,  1170,  1173,  1177,  1181,  1184,
    1188,  1192,  1194,  1196,  1198,  1200,  1202,  1204,  1206,  1208,
    1210,  1212,  1214,  1216,  1218,  1220,  1222,  1224,  1226,  1228,
    1230,  1232,  1234,  1236,  1238,  1242,  1246,  1250,  1254,  1258,
    1262,  1266,  1270,  1273,  1277,  1281,  1285,  1289,  1293,  1297,
    1301,  1305,  1309,  1312,  1316,  1320,  1323,  1327,  1331,  1334,
    1338,  1342,  1345,  1349,  1353,  1356,  1360,  1364,  1368,  1371,
    1375,  1379,  1383,  1386,  1390,  1394,  1398,  1401,  1405,  1409,
    1413,  1417,  1420,  1424,  1428,  1430,  1434,  1436,  1438,  1440,
    1444,  1448,  1450,  1452,  1454,  1456,  1458,  1460,  1462,  1464,
    1466,  1468,  1470,  1472,  1474,  1476,  1478,  1480,  1484,  1488,
    1492,  1496,  1500,  1504,  1508,  1512,  1516,  1520,  1523,  1527,
    1531,  1535,  1539,  1541,  1543,  1545,  1549,  1552,  1554,  1558,
    1561,  1564,  1566,  1569,  1572,  1574,  1576,  1578,  1581,  1583,
    1586,  1590,  1596,  1600,  1608,  1611,  1613,  1616,  1618,  1625,
    1631,  1636,  1640,  1647,  1653,  1658,  1662,  1666,  1669,  1671,
    1675,  1677,  1681,  1686,  1690,  1693,  1698,  1703,  1710,  1713,
    1718,  1722,  1724,  1728,  1730,  1735,  1740,  1744,  1746,  1751,
    1758,  1761,  1766,  1771,  1775,  1778,  1783,  1786,  1791,  1794,
    1799,  1802,  1807,  1810,  1815,  1818,  1823,  1826,  1833,  1838,
    1841,  1848,  1853,  1856,  1863,  1868,  1871,  1878,  1881,  1886,
    1891,  1894,  1899,  1904,  1907,  1912,  1917,  1920,  1925,  1930,
    1933,  1938,  1943,  1946,  1951,  1958,  1963,  1967,  1969,  1974,
    1979,  1986,  1993,  1998,  2001,  2006,  2011,  2014,  2019,  2024,
    2027,  2032,  2037,  2040,  2045,  2050,  2053,  2058,  2062,  2064,
    2069,  2072,  2077,  2081,  2083,  2087,  2089,  2093,  2095,  2099,
    2101,  2106,  2110,  2112,  2117,  2122,  2127,  2130,  2135,  2140,
    2143,  2148,  2153,  2156,  2161,  2166,  2169,  2173,  2178,  2181,
    2186,  2191,  2194,  2199,  2204,  2207,  2216,  2227,  2238,  2245,
    2254,  2265,  2276,  2287,  2298,  2302,  2307,  2312,  2315,  2320,
    2325,  2332,  2337,  2344,  2353,  2360,  2369,  2384
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     240,     0,    -1,   241,    -1,   241,   242,    -1,   242,    -1,
     241,     1,    -1,   261,    -1,   262,    -1,    -1,   243,   277,
      -1,    -1,   244,   278,    -1,    -1,   245,   279,    -1,    -1,
     246,   280,    -1,    -1,   247,   281,    -1,    -1,   248,   282,
      -1,    -1,   249,   283,    -1,    -1,   250,   284,    -1,   235,
      -1,   263,    -1,   221,    -1,   297,    -1,    74,    -1,    75,
      -1,    76,    -1,    77,    -1,   237,    -1,   218,    -1,   237,
      -1,   218,    -1,   215,   218,    -1,   214,   218,    -1,   251,
      -1,   251,   236,   253,    -1,   252,   236,   251,    -1,   252,
     236,   251,   236,   253,    -1,   251,   236,     1,    -1,   255,
      -1,   255,   256,    -1,   255,    -1,   255,   233,   218,    -1,
     255,   232,   251,    -1,   255,   232,   251,   233,   218,    -1,
     255,   232,   251,   236,   253,    -1,   255,   232,   251,   236,
     253,   233,   218,    -1,   257,    -1,   257,   258,    -1,   227,
     252,   224,   295,   224,   253,   224,   221,   226,    -1,   217,
     227,   252,   224,   295,   224,   253,   224,   221,   226,    -1,
     260,   224,   259,    -1,   259,    -1,   260,     1,    -1,    92,
     186,   254,    -1,    92,   186,     1,    -1,    93,   186,   218,
      -1,    93,   186,     1,    -1,    94,   186,   218,    -1,    94,
     186,     1,    -1,    95,   186,   220,    -1,    95,   186,     1,
      -1,    96,   186,   221,    -1,    96,   186,     1,    -1,    97,
     186,   221,    -1,    97,   186,     1,    -1,   101,   186,   218,
      -1,   101,   186,     1,    -1,   102,   186,   218,    -1,   102,
     186,     1,    -1,   103,   186,   218,    -1,   103,     1,    -1,
     104,   186,   218,    -1,   104,     1,    -1,   105,   186,   218,
      -1,   105,     1,    -1,   106,   186,   218,    -1,   106,     1,
      -1,   107,   186,   218,    -1,   107,     1,    -1,   109,   186,
     218,    -1,   109,   186,     1,    -1,   108,   186,   218,    -1,
     108,   186,     1,    -1,   132,   186,   218,    -1,   132,   186,
       1,    -1,   110,   186,   218,    -1,   110,   186,     1,    -1,
     111,   186,   218,    -1,   111,   186,     1,    -1,   112,   186,
     218,    -1,   112,   186,     1,    -1,   113,   186,   218,    -1,
     113,   186,     1,    -1,   114,   186,   218,    -1,   114,   186,
       1,    -1,   115,   186,   218,    -1,   115,   186,     1,    -1,
     116,   186,   218,    -1,   116,   186,     1,    -1,   117,   186,
     218,    -1,   117,   186,     1,    -1,   118,   186,   218,    -1,
     118,   186,     1,    -1,   119,   186,   218,    -1,   119,   186,
       1,    -1,   133,   186,   221,    -1,   133,   186,   220,    -1,
     133,   186,     1,    -1,   134,   186,   221,    -1,   134,   186,
     220,    -1,   134,   186,     1,    -1,   135,   186,   221,    -1,
     135,   186,   220,    -1,   135,   186,     1,    -1,   136,   186,
     221,    -1,   136,   186,   220,    -1,   136,   186,     1,    -1,
     137,   186,   218,    -1,   137,   186,     1,    -1,   138,   186,
     218,    -1,   138,   186,     1,    -1,   139,   186,   218,    -1,
     139,   186,     1,    -1,   140,   186,   218,    -1,   140,   186,
       1,    -1,   141,   186,   218,    -1,   141,   186,     1,    -1,
     142,   186,   218,    -1,   142,   186,     1,    -1,   143,   186,
     218,    -1,   143,   186,     1,    -1,   144,   186,   220,    -1,
     144,   186,   221,    -1,   144,   186,     1,    -1,   145,   186,
     218,    -1,   145,   186,     1,    -1,   146,   186,   218,    -1,
     146,   186,     1,    -1,   147,   186,   218,    -1,   147,   186,
       1,    -1,   148,   186,   218,    -1,   148,   186,     1,    -1,
     149,   186,   218,    -1,   149,   186,     1,    -1,   150,   186,
     218,    -1,   150,   186,     1,    -1,   151,   186,   218,    -1,
     151,   186,     1,    -1,   152,   186,   218,    -1,   152,   186,
       1,    -1,   153,   186,   218,    -1,   153,   186,     1,    -1,
     154,   186,   218,    -1,   154,   186,     1,    -1,   155,   186,
     161,    -1,   155,   186,   162,    -1,   155,   186,   163,    -1,
     155,   186,   164,    -1,   155,   186,     1,    -1,   165,   186,
     218,    -1,   165,   186,     1,    -1,   166,   186,   218,    -1,
     166,   186,     1,    -1,   167,   186,   218,    -1,   167,   186,
       1,    -1,   168,   186,   221,    -1,   168,   186,     1,    -1,
     169,   186,   221,    -1,   169,   186,     1,    -1,   170,   186,
     221,    -1,   170,   186,     1,    -1,   171,   186,   221,    -1,
     171,   186,     1,    -1,   156,   186,   218,    -1,   156,   186,
       1,    -1,   157,   186,   218,    -1,   157,   186,     1,    -1,
     160,   186,   221,    -1,   160,   186,     1,    -1,   267,    -1,
     269,    -1,   126,   186,   218,    -1,   126,   186,     1,    -1,
     127,   186,   221,    -1,   127,   186,     1,    -1,   128,   186,
     221,    -1,   128,   186,     1,    -1,    86,   186,   218,    -1,
      87,   186,   218,    -1,    86,   186,     1,    -1,    87,   186,
       1,    -1,    98,   186,   258,    -1,    98,   186,     1,    -1,
      99,   186,   256,    -1,    99,   186,     1,    -1,   100,   186,
     218,    -1,   100,   186,     1,    -1,   172,   186,   251,    -1,
     172,   186,     1,    -1,   173,   186,   218,    -1,   173,   186,
       1,    -1,   174,   186,   218,    -1,   174,   186,     1,    -1,
     175,   186,   218,    -1,   175,   186,     1,    -1,   176,   186,
     218,    -1,   176,   186,     1,    -1,   177,   186,   218,    -1,
     177,   186,     1,    -1,   178,   186,   218,    -1,   178,   186,
     220,    -1,   178,   186,     1,    -1,   130,   186,   221,    -1,
     130,   186,     1,    -1,   179,   186,   218,    -1,   179,     1,
      -1,   180,   186,   218,    -1,   180,     1,    -1,   181,   186,
     220,   236,   228,   260,   229,    -1,   182,   186,   218,    -1,
     183,   186,   221,    -1,   183,   186,     1,    -1,   184,   186,
     221,    -1,   184,   186,     1,    -1,   185,   186,   218,    -1,
     185,   186,     1,    -1,     1,   186,    -1,   129,   221,    -1,
     129,     1,    -1,   131,   227,   221,   224,   221,   224,   221,
     226,    -1,   131,   227,   221,   224,   221,   224,   254,   226,
      -1,   131,     1,    -1,   264,    -1,   266,    -1,   218,   234,
     218,   234,   218,   234,   218,    -1,   223,    -1,   265,    -1,
     230,   265,   231,    -1,    -1,   158,   230,   263,   236,   253,
     231,   268,   228,   272,   229,    -1,    -1,   159,   230,   263,
     236,   253,   231,   270,   228,   273,   229,    -1,    -1,   159,
     230,   221,   231,   271,   228,   273,   229,    -1,   274,    -1,
     272,   274,    -1,   275,    -1,   273,   275,    -1,   155,   186,
     161,    -1,   155,   186,   162,    -1,   155,   186,   163,    -1,
     155,   186,   164,    -1,   155,   186,     1,    -1,   168,   186,
     221,    -1,   168,   186,     1,    -1,   169,   186,   221,    -1,
     169,   186,     1,    -1,   170,   186,   221,    -1,   170,   186,
       1,    -1,   171,   186,   221,    -1,   171,   186,     1,    -1,
     165,   186,   218,    -1,   165,   186,     1,    -1,   167,   186,
     218,    -1,   167,   186,     1,    -1,   155,   186,   161,    -1,
     155,   186,   162,    -1,   155,   186,   163,    -1,   155,   186,
     164,    -1,   155,   186,     1,    -1,   168,   186,   221,    -1,
     168,   186,     1,    -1,   169,   186,   221,    -1,   169,   186,
       1,    -1,   170,   186,   221,    -1,   170,   186,     1,    -1,
     171,   186,   221,    -1,   171,   186,     1,    -1,   166,   186,
     218,    -1,   166,   186,     1,    -1,   220,    -1,   218,    -1,
     221,    -1,    10,   228,   303,   229,    -1,    10,   230,   276,
     231,   228,   303,   229,    -1,    10,     1,    -1,    11,   230,
     276,   231,   228,   303,   229,    -1,    11,     1,    -1,    12,
     228,   303,   229,    -1,    12,   230,   276,   231,   228,   303,
     229,    -1,    12,     1,    -1,    13,   230,   276,   231,   228,
     303,   229,    -1,    13,     1,    -1,    14,   228,   303,   229,
      -1,    14,     1,    -1,    15,   228,   303,   229,    -1,    15,
       1,    -1,    16,   228,   303,   229,    -1,    16,     1,    -1,
      17,   230,   276,   224,   218,   231,   228,   303,   229,    -1,
      17,     1,    -1,   285,   204,   285,    -1,   285,   205,   285,
      -1,   217,   285,    -1,   227,   285,   226,    -1,   230,   299,
     231,    -1,   293,    -1,   187,    -1,   192,    -1,   188,    -1,
     189,    -1,   190,    -1,   191,    -1,   193,    -1,   194,    -1,
     286,    -1,   287,    -1,   286,    -1,   287,    -1,   288,    -1,
      63,    -1,    64,    -1,    65,    -1,   222,    -1,   238,    -1,
     294,    -1,   301,    -1,   254,    -1,   292,    -1,   291,   290,
     297,    -1,    68,   286,   295,    -1,    68,   290,   297,    -1,
      66,   286,   295,    -1,    66,   290,   297,    -1,    62,   290,
     221,    -1,    62,   290,   220,    -1,    62,   290,     1,    -1,
      62,     1,    -1,   292,   290,   292,    -1,   292,   290,   221,
      -1,   292,   290,   220,    -1,   292,   289,   254,    -1,   292,
     286,    72,    -1,   292,   286,    78,    -1,   291,   290,   221,
      -1,   291,   286,    72,    -1,   291,   290,     1,    -1,   291,
       1,    -1,    67,   289,   218,    -1,    67,   289,     1,    -1,
      67,     1,    -1,    69,   289,   218,    -1,    69,   289,     1,
      -1,    69,     1,    -1,    70,   289,   252,    -1,    70,   289,
       1,    -1,    70,     1,    -1,    71,   289,   218,    -1,    71,
     289,     1,    -1,    71,     1,    -1,    73,   289,   218,    -1,
      73,   289,    51,    -1,    73,   289,     1,    -1,    73,     1,
      -1,    66,   290,   221,    -1,    66,   286,    72,    -1,    66,
     290,     1,    -1,    66,     1,    -1,    68,   290,   221,    -1,
      68,   286,    72,    -1,    68,   290,     1,    -1,    68,     1,
      -1,    72,   286,   291,    -1,    72,   286,    66,    -1,    72,
     286,    68,    -1,    72,   286,     1,    -1,    72,     1,    -1,
     263,   213,   263,    -1,   263,   213,   218,    -1,   263,    -1,
     263,   213,     1,    -1,   234,    -1,   214,    -1,   220,    -1,
     297,   296,   220,    -1,   297,   234,     1,    -1,   186,    -1,
     195,    -1,   196,    -1,   197,    -1,   198,    -1,   199,    -1,
     200,    -1,   201,    -1,   202,    -1,   203,    -1,   254,    -1,
     221,    -1,   220,    -1,   292,    -1,   294,    -1,   313,    -1,
     299,   215,   299,    -1,   299,   214,   299,    -1,   299,   212,
     299,    -1,   299,   213,   299,    -1,   299,   211,   299,    -1,
     299,   209,   299,    -1,   299,   210,   299,    -1,   299,   208,
     299,    -1,   299,   207,   299,    -1,   299,   206,   299,    -1,
     216,   299,    -1,   227,   299,   226,    -1,   292,   298,   299,
      -1,   292,   186,    78,    -1,   292,   195,    78,    -1,   313,
      -1,   305,    -1,   300,    -1,   228,   303,   229,    -1,   228,
     229,    -1,   304,    -1,   228,   303,   229,    -1,   228,   229,
      -1,   303,   304,    -1,   304,    -1,   303,     1,    -1,   313,
     225,    -1,   305,    -1,   306,    -1,   307,    -1,   300,   225,
      -1,   225,    -1,   313,     1,    -1,    37,   285,   302,    -1,
      37,   285,   302,    38,   302,    -1,    43,   285,   302,    -1,
      39,   227,   292,   226,   228,   308,   229,    -1,   309,   311,
      -1,   309,    -1,   309,   310,    -1,   310,    -1,    40,   254,
     236,   303,    42,   225,    -1,    40,   254,   236,    42,   225,
      -1,    40,   254,   236,   303,    -1,    40,   254,   236,    -1,
      40,   221,   236,   303,    42,   225,    -1,    40,   221,   236,
      42,   225,    -1,    40,   221,   236,   303,    -1,    40,   221,
     236,    -1,    41,   236,   303,    -1,    41,   236,    -1,   221,
      -1,   312,   224,   221,    -1,   218,    -1,   312,   224,   218,
      -1,     3,   227,   221,   226,    -1,     3,   227,   226,    -1,
       3,     1,    -1,     3,   227,     1,   226,    -1,     4,   227,
     221,   226,    -1,     4,   227,   221,   224,   221,   226,    -1,
       4,     1,    -1,     4,   227,     1,   226,    -1,     5,   227,
     226,    -1,     5,    -1,     6,   227,   226,    -1,     6,    -1,
       7,   227,   254,   226,    -1,     7,   227,   292,   226,    -1,
       7,   227,   226,    -1,     7,    -1,     8,   227,   221,   226,
      -1,     8,   227,   254,   224,   221,   226,    -1,     8,     1,
      -1,     8,   227,     1,   226,    -1,    52,   227,   254,   226,
      -1,    52,   227,   226,    -1,    52,     1,    -1,    53,   227,
     218,   226,    -1,    53,     1,    -1,    54,   227,   218,   226,
      -1,    54,     1,    -1,    55,   227,   218,   226,    -1,    55,
       1,    -1,    59,   227,   218,   226,    -1,    59,     1,    -1,
      60,   227,   218,   226,    -1,    60,     1,    -1,    61,   227,
     218,   226,    -1,    61,     1,    -1,    56,   227,   218,   224,
     218,   226,    -1,    56,   227,   218,   226,    -1,    56,     1,
      -1,    57,   227,   218,   224,   218,   226,    -1,    57,   227,
     218,   226,    -1,    57,     1,    -1,    58,   227,   218,   224,
     218,   226,    -1,    58,   227,   218,   226,    -1,    58,     1,
      -1,     9,   227,   221,   224,   221,   226,    -1,     9,     1,
      -1,     9,   227,     1,   226,    -1,    10,   227,   276,   226,
      -1,    10,     1,    -1,    10,   227,     1,   226,    -1,    18,
     227,   221,   226,    -1,    18,     1,    -1,    18,   227,     1,
     226,    -1,    20,   227,   221,   226,    -1,    20,     1,    -1,
      20,   227,     1,   226,    -1,    22,   227,   218,   226,    -1,
      22,     1,    -1,    22,   227,     1,   226,    -1,    21,   227,
     218,   226,    -1,    21,     1,    -1,    21,   227,     1,   226,
      -1,    23,   227,   221,   224,   221,   226,    -1,    23,   227,
     221,   226,    -1,    23,   227,   226,    -1,    23,    -1,    24,
     227,   218,   226,    -1,    24,   227,   292,   226,    -1,    25,
     227,   221,   224,   221,   226,    -1,    25,   227,   292,   224,
     221,   226,    -1,    19,   227,   221,   226,    -1,    19,     1,
      -1,    19,   227,     1,   226,    -1,    28,   227,   221,   226,
      -1,    28,     1,    -1,    28,   227,     1,   226,    -1,    26,
     227,   221,   226,    -1,    26,     1,    -1,    26,   227,     1,
     226,    -1,    27,   227,   221,   226,    -1,    27,     1,    -1,
      27,   227,     1,   226,    -1,    29,   227,   221,   226,    -1,
      29,     1,    -1,    29,   227,     1,   226,    -1,    30,   227,
     226,    -1,    30,    -1,    31,   227,   221,   226,    -1,    31,
       1,    -1,    31,   227,     1,   226,    -1,    32,   227,   226,
      -1,    32,    -1,    33,   227,   226,    -1,    33,    -1,    34,
     227,   226,    -1,    34,    -1,    35,   227,   226,    -1,    35,
      -1,    36,   227,   218,   226,    -1,    36,   227,   226,    -1,
      36,    -1,    36,   227,     1,   226,    -1,    44,   227,   251,
     226,    -1,    44,   227,     1,   226,    -1,    44,     1,    -1,
      45,   227,   218,   226,    -1,    45,   227,     1,   226,    -1,
      45,     1,    -1,    46,   227,   255,   226,    -1,    46,   227,
       1,   226,    -1,    46,     1,    -1,    47,   227,   218,   226,
      -1,    47,   227,     1,   226,    -1,    47,     1,    -1,    48,
     227,   226,    -1,    48,   227,     1,   226,    -1,    48,     1,
      -1,    49,   227,   221,   226,    -1,    49,   227,     1,   226,
      -1,    49,     1,    -1,    50,   227,   221,   226,    -1,    50,
     227,     1,   226,    -1,    50,     1,    -1,    79,   227,   221,
     224,   221,   224,   221,   226,    -1,    79,   227,   221,   224,
     221,   224,   221,   224,   218,   226,    -1,    79,   227,   221,
     224,   221,   224,   221,   224,   292,   226,    -1,    81,   227,
     221,   224,   221,   226,    -1,    80,   227,   221,   224,   221,
     224,   292,   226,    -1,    82,   227,   221,   224,   221,   224,
     218,   224,   218,   226,    -1,    82,   227,   221,   224,   221,
     224,   292,   224,   218,   226,    -1,    83,   227,   221,   224,
     221,   224,   218,   224,   218,   226,    -1,    83,   227,   221,
     224,   221,   224,   292,   224,   218,   226,    -1,   220,   227,
     226,    -1,   220,   227,   312,   226,    -1,   220,   227,     1,
     226,    -1,   220,     1,    -1,    84,   227,   221,   226,    -1,
      85,   227,   221,   226,    -1,    85,   227,   221,   224,   221,
     226,    -1,    88,   227,   221,   226,    -1,    88,   227,   221,
     224,   292,   226,    -1,    88,   227,   221,   224,   292,   224,
     292,   226,    -1,    89,   227,   221,   224,   221,   226,    -1,
      89,   227,   221,   224,   221,   224,   218,   226,    -1,    90,
     227,   221,   224,   221,   224,   221,   224,   221,   224,   221,
     224,   292,   226,    -1,    91,   227,   292,   224,   292,   226,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   470,   470,   473,   474,   475,   478,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   487,   487,   489,   492,   505,   512,   525,   526,
     527,   535,   542,   545,   546,   549,   550,   551,   555,   556,
     557,   558,   559,   562,   563,   567,   568,   569,   570,   571,
     572,   575,   576,   580,   587,   597,   598,   599,   603,   610,
     611,   612,   613,   614,   615,   621,   622,   623,   624,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   692,   693,   700,   701,   708,
     709,   716,   717,   724,   725,   732,   733,   747,   761,   762,
     769,   770,   777,   778,   788,   789,   796,   797,   808,   809,
     820,   821,   832,   833,   840,   841,   848,   849,   856,   857,
     867,   877,   887,   897,   906,   914,   915,   923,   924,   931,
     932,   942,   943,   953,   954,   964,   965,   975,   976,   983,
     984,   991,   992,  1003,  1004,  1005,  1006,  1007,  1008,  1011,
    1012,  1015,  1016,  1017,  1018,  1019,  1021,  1037,  1040,  1045,
    1047,  1048,  1049,  1055,  1057,  1069,  1071,  1074,  1075,  1078,
    1079,  1086,  1087,  1094,  1095,  1099,  1126,  1127,  1135,  1136,
    1139,  1140,  1143,  1144,  1154,  1157,  1158,  1159,  1160,  1161,
    1162,  1165,  1168,  1207,  1208,  1214,  1220,  1224,  1225,  1228,
    1262,  1282,  1283,  1286,  1286,  1297,  1297,  1308,  1308,  1319,
    1320,  1323,  1324,  1327,  1334,  1341,  1348,  1355,  1356,  1363,
    1365,  1372,  1374,  1381,  1382,  1389,  1390,  1397,  1398,  1405,
    1409,  1416,  1423,  1430,  1437,  1439,  1446,  1448,  1455,  1457,
    1464,  1465,  1472,  1473,  1480,  1483,  1486,  1493,  1498,  1506,
    1521,  1524,  1530,  1533,  1541,  1547,  1550,  1556,  1559,  1567,
    1570,  1578,  1581,  1589,  1592,  1604,  1607,  1608,  1609,  1610,
    1611,  1612,  1615,  1616,  1619,  1620,  1621,  1622,  1624,  1625,
    1628,  1629,  1632,  1633,  1634,  1637,  1638,  1639,  1642,  1656,
    1661,  1662,  1663,  1665,  1668,  1670,  1672,  1674,  1676,  1680,
    1682,  1684,  1685,  1688,  1691,  1694,  1697,  1700,  1703,  1706,
    1708,  1710,  1711,  1714,  1716,  1717,  1718,  1720,  1721,  1722,
    1724,  1727,  1728,  1730,  1731,  1732,  1734,  1736,  1737,  1738,
    1752,  1754,  1756,  1758,  1772,  1774,  1776,  1778,  1780,  1782,
    1784,  1786,  1791,  1792,  1803,  1804,  1811,  1812,  1815,  1816,
    1828,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1854,  1857,
    1860,  1863,  1866,  1869,  1872,  1875,  1878,  1881,  1884,  1887,
    1900,  1913,  1935,  1936,  1937,  1938,  1939,  1942,  1943,  1944,
    1947,  1948,  1949,  1952,  1953,  1954,  1955,  1956,  1957,  1958,
    1961,  1969,  1979,  1987,  1996,  1997,  1999,  2000,  2003,  2012,
    2021,  2029,  2037,  2046,  2055,  2063,  2074,  2080,  2088,  2093,
    2102,  2106,  2113,  2119,  2126,  2127,  2130,  2136,  2142,  2143,
    2145,  2146,  2147,  2148,  2149,  2155,  2161,  2167,  2173,  2176,
    2182,  2183,  2185,  2187,  2188,  2189,  2191,  2192,  2194,  2195,
    2197,  2198,  2200,  2201,  2203,  2204,  2206,  2207,  2211,  2214,
    2215,  2219,  2223,  2224,  2228,  2232,  2233,  2239,  2240,  2242,
    2248,  2249,  2251,  2253,  2254,  2257,  2259,  2260,  2262,  2264,
    2265,  2268,  2270,  2271,  2273,  2281,  2283,  2285,  2287,  2289,
    2292,  2315,  2330,  2332,  2333,  2335,  2337,  2338,  2340,  2342,
    2343,  2345,  2347,  2348,  2350,  2352,  2353,  2355,  2356,  2357,
    2359,  2360,  2362,  2364,  2365,  2366,  2367,  2369,  2370,  2372,
    2374,  2382,  2389,  2396,  2399,  2403,  2405,  2406,  2422,  2424,
    2425,  2429,  2432,  2433,  2437,  2440,  2441,  2444,  2447,  2448,
    2452,  2455,  2456,  2460,  2463,  2464,  2473,  2485,  2498,  2505,
    2514,  2525,  2536,  2547,  2558,  2575,  2592,  2594,  2596,  2598,
    2600,  2602,  2604,  2606,  2608,  2610,  2612,  2626
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "SEND", "DROP", "EXIT",
  "RETURN", "LOG_TOK", "ERROR", "ROUTE", "ROUTE_FAILURE", "ROUTE_ONREPLY",
  "ROUTE_BRANCH", "ROUTE_ERROR", "ROUTE_LOCAL", "ROUTE_STARTUP",
  "ROUTE_TIMER", "SET_HOST", "SET_HOSTPORT", "PREFIX", "STRIP",
  "STRIP_TAIL", "APPEND_BRANCH", "REMOVE_BRANCH", "PV_PRINTF", "SET_USER",
  "SET_USERPASS", "SET_PORT", "SET_URI", "REVERT_URI", "SET_DSTURI",
  "RESET_DSTURI", "ISDSTURISET", "FORCE_RPORT", "FORCE_LOCAL_RPORT",
  "FORCE_TCP_ALIAS", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "SBREAK",
  "WHILE", "SET_ADV_ADDRESS", "SET_ADV_PORT", "FORCE_SEND_SOCKET",
  "SERIALIZE_BRANCHES", "NEXT_BRANCHES", "USE_BLACKLIST",
  "UNUSE_BLACKLIST", "MAX_LEN", "SETDEBUG", "SETFLAG", "RESETFLAG",
  "ISFLAGSET", "SETBFLAG", "RESETBFLAG", "ISBFLAGSET", "SETSFLAG",
  "RESETSFLAG", "ISSFLAGSET", "METHOD", "URI", "FROM_URI", "TO_URI",
  "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "PROTO", "AF", "MYSELF",
  "MSGLEN", "UDP", "TCP", "TLS", "SCTP", "NULLV", "CACHE_STORE",
  "CACHE_FETCH", "CACHE_REMOVE", "CACHE_ADD", "CACHE_SUB", "XDBG", "XLOG",
  "XLOG_BUF_SIZE", "XLOG_FORCE_COLOR", "RAISE_EVENT", "SUBSCRIBE_EVENT",
  "CONSTRUCT_URI", "GET_TIMESTAMP", "DEBUG", "FORK", "LOGSTDERROR",
  "LOGFACILITY", "LOGNAME", "AVP_ALIASES", "LISTEN", "ALIAS",
  "AUTO_ALIASES", "DNS", "REV_DNS", "DNS_TRY_IPV6", "DNS_RETR_TIME",
  "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH", "MAX_WHILE_LOOPS",
  "PORT", "CHILDREN", "CHECK_VIA", "MEMLOG", "MEMDUMP", "EXECMSGTHRESHOLD",
  "EXECDNSTHRESHOLD", "TCPTHRESHOLD", "QUERYBUFFERSIZE", "QUERYFLUSHTIME",
  "SIP_WARNING", "SOCK_MODE", "SOCK_USER", "SOCK_GROUP", "UNIX_SOCK",
  "UNIX_SOCK_CHILDREN", "UNIX_TX_TIMEOUT", "SERVER_SIGNATURE",
  "SERVER_HEADER", "USER_AGENT_HEADER", "LOADMODULE", "MPATH", "MODPARAM",
  "MAXBUFFER", "USER", "GROUP", "CHROOT", "WDIR", "MHOMED", "DISABLE_TCP",
  "TCP_ACCEPT_ALIASES", "TCP_CHILDREN", "TCP_CONNECT_TIMEOUT",
  "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME", "TCP_POLL_METHOD",
  "TCP_MAX_CONNECTIONS", "TCP_OPT_CRLF_PINGPONG", "TCP_NO_NEW_CONN_BFLAG",
  "TCP_KEEPALIVE", "TCP_KEEPCOUNT", "TCP_KEEPIDLE", "TCP_KEEPINTERVAL",
  "DISABLE_TLS", "TLSLOG", "TLS_PORT_NO", "TLS_METHOD",
  "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT", "TLS_SERVER_DOMAIN",
  "TLS_CLIENT_DOMAIN", "TLS_CLIENT_DOMAIN_AVP", "SSLv23", "SSLv2", "SSLv3",
  "TLSv1", "TLS_VERIFY_CLIENT", "TLS_VERIFY_SERVER",
  "TLS_REQUIRE_CLIENT_CERTIFICATE", "TLS_CERTIFICATE", "TLS_PRIVATE_KEY",
  "TLS_CA_LIST", "TLS_CIPHERS_LIST", "ADVERTISED_ADDRESS",
  "ADVERTISED_PORT", "DISABLE_CORE", "OPEN_FD_LIMIT", "MCAST_LOOPBACK",
  "MCAST_TTL", "TOS", "DISABLE_DNS_FAILOVER", "DISABLE_DNS_BLACKLIST",
  "DST_BLACKLIST", "DISABLE_STATELESS_FWD", "DB_VERSION_TABLE",
  "DB_DEFAULT_URL", "DISABLE_503_TRANSLATION", "EQUAL", "EQUAL_T", "GT",
  "LT", "GTE", "LTE", "DIFF", "MATCH", "NOTMATCH", "COLONEQ", "PLUSEQ",
  "MINUSEQ", "SLASHEQ", "MULTEQ", "MODULOEQ", "BANDEQ", "BOREQ", "BXOREQ",
  "AND", "OR", "BRSHIFT", "BLSHIFT", "BXOR", "BAND", "BOR", "MODULO",
  "MULT", "SLASH", "MINUS", "PLUS", "BNOT", "NOT", "NUMBER", "ZERO", "ID",
  "STRING", "SCRIPTVAR", "IPV6ADDR", "COMMA", "SEMICOLON", "RPAREN",
  "LPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "AS", "USE_CHILDREN",
  "DOT", "CR", "COLON", "ANY", "SCRIPTVARERR", "$accept", "cfg",
  "statements", "statement", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "listen_id", "proto", "port", "snumber", "phostport",
  "id_lst", "listen_def", "listen_lst", "blst_elem", "blst_elem_list",
  "assign_stm", "module_stm", "ip", "ipv4", "ipv6addr", "ipv6",
  "tls_server_domain_stm", "$@9", "tls_client_domain_stm", "$@10", "$@11",
  "tls_server_decls", "tls_client_decls", "tls_server_var",
  "tls_client_var", "route_name", "route_stm", "failure_route_stm",
  "onreply_route_stm", "branch_route_stm", "error_route_stm",
  "local_route_stm", "startup_route_stm", "timer_route_stm", "exp",
  "equalop", "compop", "matchop", "intop", "strop", "uri_type",
  "script_var", "exp_elem", "exp_cond", "ipnet", "host_sep", "host",
  "assignop", "assignexp", "assign_cmd", "exp_stm", "stm", "actions",
  "action", "if_cmd", "while_cmd", "switch_cmd", "switch_stm", "case_stms",
  "case_stm", "default_stm", "module_func_param", "cmd", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   239,   240,   241,   241,   241,   242,   242,   243,   242,
     244,   242,   245,   242,   246,   242,   247,   242,   248,   242,
     249,   242,   250,   242,   242,   251,   251,   251,   252,   252,
     252,   252,   252,   253,   253,   254,   254,   254,   255,   255,
     255,   255,   255,   256,   256,   257,   257,   257,   257,   257,
     257,   258,   258,   259,   259,   260,   260,   260,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   262,   262,   262,   262,   262,   263,   263,   264,
     265,   266,   266,   268,   267,   270,   269,   271,   269,   272,
     272,   273,   273,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   276,   276,   276,   277,   277,
     277,   278,   278,   279,   279,   279,   280,   280,   281,   281,
     282,   282,   283,   283,   284,   284,   285,   285,   285,   285,
     285,   285,   286,   286,   287,   287,   287,   287,   288,   288,
     289,   289,   290,   290,   290,   291,   291,   291,   292,   292,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   295,   295,   295,   295,   296,   296,   297,   297,
     297,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   300,
     300,   300,   301,   301,   301,   301,   301,   302,   302,   302,
     303,   303,   303,   304,   304,   304,   304,   304,   304,   304,
     305,   305,   306,   307,   308,   308,   309,   309,   310,   310,
     310,   310,   310,   310,   310,   310,   311,   311,   312,   312,
     312,   312,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     3,
       3,     5,     3,     1,     2,     1,     3,     3,     5,     5,
       7,     1,     2,     9,    10,     3,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     2,     7,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     8,     8,     2,     1,     1,     7,
       1,     1,     3,     0,    10,     0,    10,     0,     8,     1,
       2,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     7,
       2,     7,     2,     4,     7,     2,     7,     2,     4,     2,
       4,     2,     4,     2,     9,     2,     3,     3,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     3,     3,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       3,     2,     3,     3,     1,     3,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     1,     1,     1,     3,     2,     1,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     2,     1,     2,
       3,     5,     3,     7,     2,     1,     2,     1,     6,     5,
       4,     3,     6,     5,     4,     3,     3,     2,     1,     3,
       1,     3,     4,     3,     2,     4,     4,     6,     2,     4,
       3,     1,     3,     1,     4,     4,     3,     1,     4,     6,
       2,     4,     4,     3,     2,     4,     2,     4,     2,     4,
       2,     4,     2,     4,     2,     4,     2,     6,     4,     2,
       6,     4,     2,     6,     4,     2,     6,     2,     4,     4,
       2,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     6,     4,     3,     1,     4,     4,
       6,     6,     4,     2,     4,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     4,     3,     1,     4,
       2,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       4,     3,     1,     4,     4,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     3,     4,     2,     4,
       4,     2,     4,     4,     2,     8,    10,    10,     6,     8,
      10,    10,    10,    10,     3,     4,     4,     2,     4,     4,
       6,     4,     6,     8,     6,     8,    14,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,   184,   185,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
      77,     0,    79,     0,    81,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   232,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,   222,     0,     0,     0,     0,     0,     0,
       1,     5,     3,     0,     9,     0,    11,     0,    13,     0,
      15,     0,    17,     0,    19,     0,    21,     0,    23,   194,
     192,   195,   193,    59,     0,     0,    35,    58,    61,    60,
      63,    62,    65,    64,    67,    66,    69,    68,   197,    28,
      29,    30,    31,     0,   388,    26,   240,     0,    32,    38,
       0,    45,    51,   196,    25,   237,   241,   238,    27,   199,
      43,   198,   201,   200,    71,    70,    73,    72,    74,    76,
      78,    80,    82,    87,    86,    85,    84,    91,    90,    93,
      92,    95,    94,    97,    96,    99,    98,   101,   100,   103,
     102,   105,   104,   107,   106,   109,   108,   187,   186,   189,
     188,   191,   190,   218,   217,     0,    89,    88,   112,   111,
     110,   115,   114,   113,   118,   117,   116,   121,   120,   119,
     123,   122,   125,   124,   127,   126,   129,   128,   131,   130,
     133,   132,   135,   134,   138,   136,   137,   140,   139,   142,
     141,   144,   143,   146,   145,   148,   147,   150,   149,   152,
     151,   154,   153,   156,   155,   158,   157,   163,   159,   160,
     161,   162,   179,   178,   181,   180,     0,     0,     0,   183,
     182,   165,   164,   167,   166,   169,   168,   171,   170,   173,
     172,   175,   174,   177,   176,   203,   202,   205,   204,   207,
     206,   209,   208,   211,   210,   213,   212,   216,   214,   215,
     219,   221,     0,   224,   226,   225,   228,   227,   230,   229,
     290,     0,     0,   292,     0,   295,     0,     0,   297,     0,
     299,     0,   301,     0,   303,     0,   305,     0,    37,    36,
       0,     0,     0,     0,     0,     0,    52,   387,     0,     0,
      44,     0,     0,   247,     0,     0,     0,     0,   471,   473,
     477,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,     0,     0,     0,   548,     0,   553,   555,
     557,   559,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   328,   438,   329,     0,     0,
       0,   431,   434,   435,   436,     0,   286,   285,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
      42,    33,    34,    39,    40,    47,    46,   390,   389,     0,
       0,     0,     0,     0,   464,     0,   468,     0,     0,     0,
       0,   480,     0,   507,     0,   510,     0,   513,     0,   533,
       0,   516,     0,   522,     0,   519,     0,     0,     0,     0,
     539,     0,   542,     0,   536,     0,   545,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,   325,   326,   327,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,     0,   333,   311,   330,   424,   331,
     423,   422,     0,     0,   566,     0,   569,     0,   572,     0,
     575,     0,   578,     0,   581,     0,   584,     0,   484,     0,
     486,     0,   488,     0,   490,     0,   499,     0,   502,     0,
     505,     0,   492,     0,   494,     0,   496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   597,
       0,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,     0,   437,   432,   288,   430,   439,   433,     0,     0,
     293,     0,     0,   298,   300,   302,     0,     0,     0,     0,
       0,     0,   243,     0,   245,     0,     0,    56,     0,     0,
       0,   463,     0,     0,   470,   472,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     547,     0,     0,   552,   554,   556,   558,     0,     0,   561,
     342,   312,   314,   315,   316,   317,   313,   318,   319,   322,
     323,   324,     0,   372,   322,     0,   355,   320,   321,     0,
     376,   322,     0,   358,     0,   361,     0,   364,     0,   381,
       0,   368,     0,   308,     0,   426,     0,     0,     0,     0,
       0,   402,     0,   401,     0,   404,   405,     0,   406,     0,
       0,     0,   440,   427,   352,   322,     0,   322,   323,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,     0,     0,     0,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,   458,   594,     0,   420,   421,   419,     0,     0,     0,
       0,     0,     0,    41,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,     0,     0,     0,
      57,     0,   223,   465,   462,   469,     0,   466,   474,   475,
     481,   478,     0,   508,     0,   511,   509,   514,   512,   534,
     532,   517,   515,   523,   521,   520,   518,     0,   525,   528,
     529,     0,     0,   540,   538,   543,   541,   537,   535,   546,
     544,   551,   549,   563,   560,   341,   340,   339,   370,   384,
     337,   371,   369,   338,   354,   353,   374,   335,   375,   373,
     336,   357,   356,   360,   359,   363,   362,   380,   378,   379,
     377,   367,   366,   365,   309,   425,   322,     0,   322,     0,
     417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   310,   306,   307,   429,     0,     0,   350,
     351,   349,   334,   347,   348,   346,   345,   344,   343,     0,
     565,   564,   568,   567,   571,   570,   574,   573,   577,   580,
     579,   583,   582,   482,   485,   487,   489,     0,   498,     0,
     501,     0,   504,   491,   493,   495,     0,     0,     0,     0,
       0,   598,     0,   599,     0,   601,     0,     0,     0,   596,
       0,   595,     0,     0,     0,     0,     0,     0,     0,   234,
     235,     0,     0,     0,     0,     0,     0,     0,   248,   252,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,   418,   416,   415,   414,   412,   413,   411,   409,   410,
     408,   407,   428,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   461,   459,
     289,   291,   294,   296,     0,   239,    50,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   274,   270,   271,   272,
     273,   284,   283,   276,   275,   278,   277,   280,   279,   282,
     281,     0,     0,     0,   467,   479,   506,   524,   530,   531,
     385,   383,   382,     0,     0,   445,   447,   497,   500,   503,
       0,     0,   588,     0,     0,   600,     0,   602,     0,   604,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   250,   246,     0,     0,     0,     0,   443,     0,   446,
     444,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   257,   253,   254,   255,   256,   267,   266,   269,   268,
     259,   258,   261,   260,   263,   262,   265,   264,     0,     0,
     455,   451,   457,     0,   585,   589,     0,     0,     0,     0,
     603,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
       0,   449,     0,   586,   587,   590,   591,   592,   593,     0,
       0,    53,   452,   448,     0,    54,     0,     0,   606
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   249,   250,   533,   793,   251,   261,   252,   253,
     697,   698,   100,   101,   254,   255,   256,   257,   102,   868,
     103,   877,   541,  1104,   875,  1105,   876,   519,   204,   206,
     208,   210,   212,   214,   216,   218,   603,   767,   760,   761,
     809,   810,   794,   508,   606,   796,   930,   439,   258,   671,
     797,   509,   609,   802,   510,   511,   512,   513,   514,  1134,
    1135,  1136,  1170,   853,   515
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -855
static const yytype_int16 yypact[] =
{
    3784,  -110,   -87,   -56,   -15,    -9,    -4,    26,   113,   296,
     387,   388,   410,   434,   525,    33,    42,    47,    53,    58,
     542,   546,   589,   590,   591,   602,   612,   615,   623,   638,
     655,   657,   673,   685,   689,   121,   692,    52,   710,   762,
     774,   775,   776,   785,   796,   800,   849,   862,   865,   868,
     869,   872,   874,   876,   884,   890,   892,   896,   898,   900,
     902,   906,   908,   916,     8,   316,   917,   918,   920,   922,
     923,   925,   926,   939,   940,   941,   942,   943,   964,   966,
     967,    64,   492,   968,   989,   994,  1004,  1012,  -855,   226,
    2493,  -855,   221,   705,   760,   761,   735,   772,   826,   955,
    -855,  -855,  -855,  -855,  -855,   248,   489,   336,   547,   548,
      27,   143,   196,    36,    51,   551,   552,   562,  -855,   843,
    -855,   853,  -855,   963,  -855,   981,  -855,   987,   563,   564,
     565,   566,   567,   568,   574,   575,   576,   577,   578,   581,
     582,   209,   231,  -855,  -855,   236,  -855,   702,   584,   107,
     174,   235,   335,   585,   586,   588,   604,   605,   617,   618,
     338,   620,   621,   622,   643,   646,   647,   656,   667,   679,
     680,   508,   681,   683,   -23,  -134,   339,   718,   732,   733,
     351,   478,   480,   482,    72,   734,   736,   737,   738,   739,
     370,  -855,   990,  -855,   992,   991,  1006,   483,   484,   740,
    -855,  -110,  -855,    48,  -855,    30,  -855,    55,  -855,    38,
    -855,    54,  -855,    63,  -855,    70,  -855,    45,  -855,  -855,
    -855,  -855,  -855,  -855,  1007,  1009,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,   973,  -855,  -855,  -855,  1003,  -855,  1013,
    1015,   -96,  1328,  -855,  -855,  -855,  -855,  -855,  -157,  -855,
    1328,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  1028,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  1017,   997,  1026,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  1061,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  3637,   382,  -855,   382,  -855,  3637,   382,  -855,   382,
    -855,  3637,  -855,  3637,  -855,  3637,  -855,   382,  -855,  -855,
    1080,  1073,    24,  1105,  1105,  1090,  -855,  -855,   377,  1099,
    -855,  1100,  -152,  -855,  -152,  1092,    67,    73,  1102,  1103,
    1104,    74,    77,    78,    79,    80,    81,    92,    93,  1106,
    1109,  1111,    94,    97,    99,   102,  1125,   103,  1126,  1127,
    1128,  1129,  1150,  2677,  1152,  2677,   104,   108,   117,   118,
     119,   120,   123,   128,   138,   145,   150,   164,   165,   166,
     169,   214,   215,  1153,  1154,  1163,  1174,  1179,  1180,  1181,
    1188,  1189,  1190,  1198,   223,  -855,  -855,  -855,  1582,  1097,
     984,  -855,  -855,  -855,  -855,    39,  -855,  -855,  -855,  1096,
    1108,  1112,  1195,  1201,  1211,  1339,  1438,  1210,  1203,  -855,
    -855,  -855,  -855,  -855,  1199,   -76,  -855,  -855,  -855,  1214,
    1220,  1224,  1223,   -54,  -855,   153,  -855,   485,  1227,  1229,
       3,  -855,   322,  -855,   487,  -855,   233,  -855,   488,  -855,
     493,  -855,   494,  -855,   741,  -855,   745,     1,  -132,   535,
    -855,   505,  -855,   506,  -855,   509,  -855,   510,  1250,  -855,
     522,  1252,  1253,  1254,  1263,   247,   995,  -855,  -855,  -855,
    1086,  1222,  1095,  1317,  1323,  1350,    43,  1449,  2677,  2677,
    3006,  2766,  -855,  2917,  1123,  1798,  -855,  -855,  -855,  -855,
    -855,  -855,  -150,  2917,  -855,   257,  -855,   759,  -855,    66,
    -855,   766,  -855,   132,  -855,   523,  -855,   524,  -855,   658,
    -855,  1282,  -855,  1283,  -855,  1284,  -855,  1285,  -855,  1298,
    -855,  1306,  -855,  1307,  -855,  1312,  -855,  1313,  1311,  1314,
    1315,  1322,  1324,  1326,  1329,  1331,  1332,  1333,  -150,  -855,
      25,  1455,  1456,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  2766,  -855,  -855,  -855,  -855,  -855,  -855,  1316,  1327,
    -855,  1334,  1335,  -855,  -855,  -855,  1338,  1342,  -152,  1348,
    -152,   -12,  -855,  1008,  -855,  1330,   -14,  -855,    41,  1352,
    1353,  -855,  1354,   -13,  -855,  -855,  -855,  1355,  1356,  1357,
    1378,  1382,  1381,  1384,  1391,  1402,  1404,  1405,  1407,  1409,
    1417,  1418,  1426,  1427,  1433,  1435,   250,  -855,  1436,  1439,
    1440,  1453,  1452,  1454,  1477,  1479,  1480,  1481,  1502,  1517,
    -855,  1525,  1526,  -855,  -855,  -855,  -855,  1531,  1533,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,   350,  -855,   -25,   360,  -855,  -855,  -855,   777,
    -855,   -22,   372,  -855,   804,  -855,    40,  -855,   806,  -855,
     122,  -855,   163,  -855,  -135,  -855,  1566,  1086,  1095,  2766,
     606,  -855,  2766,  -855,  1123,  1815,  -855,  1527,  -855,  2677,
    2677,  3157,  1641,  -855,  -855,  1609,   374,   875,   -34,   503,
     625,  1535,  -855,  1536,  1537,  1538,  1539,  1540,  1541,  1543,
    1563,  1567,  -855,  1579,  1580,  1581,  1583,  -855,  1584,  1607,
    1618,  1629,   321,   449,   474,  1630,  1631,  1632,  1458,  1568,
    1611,  1645,  1646,  1654,   601,   636,  1647,  1662,  1664,  1663,
    -855,  -855,  -855,   644,  -855,  -855,  1754,  3637,  3637,  3637,
    3637,  1556,  1574,  -855,  -855,  1598,  1666,  1678,  1677,  1705,
    1720,  1721,  1722,  1723,  1744,  1561,  -855,  1704,   -14,  1709,
    -855,   -54,  -855,  -855,  -855,  -855,  1713,  -855,  -855,  -855,
    -855,  -855,  1734,  -855,  1749,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  1757,  -855,  -855,
    -855,  1758,  1789,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  1799,
    -855,  -855,  -855,  -157,  -855,  -855,  -855,  -855,  -855,  -855,
    -157,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  1939,   529,  1942,   530,
    -855,  1653,   531,  2766,  2766,  2766,  2766,  2766,  2766,  2766,
    2766,  2766,  2766,  -855,  -855,  -855,  -855,  1665,  3246,  -855,
    -855,  -855,  -157,  -855,  -855,  -855,  -855,  -855,  -855,  1791,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  1802,  -855,  1814,
    -855,  1816,  -855,  -855,  -855,  -855,  1795,  1812,  1837,  1839,
    1840,  -855,  1841,  -855,  -150,  -855,  1850,  1861,  -150,  -855,
     550,  -855,  1793,  1892,  2020,  2119,  1807,  1818,  1819,  -855,
    -855,   930,   561,   807,   532,   533,   534,   537,  -855,  -855,
    1008,  1859,   -23,  -855,  1858,  1860,  1862,  1863,  1864,  1865,
      22,  -855,   786,   786,   786,   786,   786,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  2045,  1866,  1867,  1868,  1871,  1872,
    1880,  1873,  1874,  1881,   676,   754,  1889,  1890,  -855,  -855,
    -855,  -855,  -855,  -855,  3637,  -855,  -855,  1901,  1929,  1932,
    1933,  1945,  1946,  1947,  1605,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  1788,   -23,  1910,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,   973,  -855,   635,  1906,   707,  -855,  -855,  -855,  -855,
    1915,  -150,  -855,   -46,   -44,  -855,  -150,  -855,  1941,  -855,
    1936,  -855,  2247,   719,   828,   829,   538,   540,   541,   543,
    -855,  -855,  -855,  1937,  -152,  1924,  1934,  -855,  1948,  -855,
    -855,   757,  1955,  1958,  1959,  1961,  1962,  1963,  1964,  1967,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -152,  1968,
    3397,  3486,  3637,   -39,  -855,  -855,  1969,  1970,  1975,  1976,
    -855,  -855,  1974,  1972,  1984,  1981,   379,  1986,   885,  2346,
    1971,  1987,  1988,  1989,  1990,  1991,  1994,  1998,  1995,  -855,
    1997,  -855,  1999,  -855,  -855,  -855,  -855,  -855,  -855,  2002,
    2000,  -855,  -855,  -855,  1996,  -855,  -150,  2001,  -855
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -855,  -855,  -855,  2122,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -171,   101,  -435,  -107,  -111,  1965,  -855,  1977,
    1347,  -855,  -855,  -855,  -173,  -855,  1983,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  1182,  1130,  -854,  1215,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -430,   262,   486,  -855,
     712,   265,  -446,  -467,  -855,  -443,  -755,  -855,  -714,  -855,
    -654,  -440,  -855,  -602,  -411,  -506,  -437,  -855,  -855,  -855,
    -855,  1098,  -855,  -855,  -451
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -457
static const yytype_int16 yytable[] =
{
     227,   366,   368,   260,   675,   521,   605,   540,   605,   542,
     524,   812,   525,   386,   526,   675,   937,   856,   675,   675,
     675,  1049,   611,  1130,   611,   530,   849,   604,   232,   604,
     607,   413,   607,   608,   118,   608,   610,   238,   610,   418,
     676,   943,   880,   120,   779,   613,   426,   928,   122,   410,
     936,   933,   259,   146,   124,   420,   415,   437,   940,   126,
     239,   240,   241,   242,   422,   191,   531,   817,   544,   799,
     800,   424,   505,   385,   546,   551,   104,   438,   553,   555,
     557,   559,   561,   708,   243,   532,   728,   367,   507,   246,
     505,   954,   982,   563,   565,   570,   247,   803,   572,   105,
     574,   729,   731,   576,   579,   614,   507,   803,   308,   616,
     239,   240,   241,   242,   239,   240,   241,   242,   618,   620,
     622,   624,   143,   947,   626,   239,   240,   241,   242,   628,
     106,   605,   605,   821,   795,   960,   434,   435,   961,   630,
     239,   240,   241,   242,   234,   811,   632,   611,   611,   260,
     798,   634,   604,   604,   699,   607,   607,   689,   608,   608,
     690,   610,   610,   695,   951,   636,   638,   640,   783,   784,
     642,   107,  1173,   696,  1175,   311,   505,   108,   505,  1220,
    -321,  -321,   109,   505,  -321,   587,   588,   589,   948,   786,
     949,   848,   507,   243,   507,   243,   243,   236,   246,   507,
     246,   246,   224,   225,   795,   247,   226,   247,   247,   866,
     299,   886,   110,   887,   952,   644,   646,   224,   225,   119,
     798,   226,   726,   248,   659,   505,   200,   727,   121,   706,
     751,   203,   301,   123,   714,   756,   314,   303,   174,   125,
    1131,   507,   531,   850,   127,   246,   851,   233,   747,   219,
     192,   852,   247,   863,   243,   865,   244,   245,   813,   246,
     414,   532,   534,   535,   677,   881,   247,  1049,   419,   243,
     882,   244,   245,   248,   246,   427,   411,   248,   412,   147,
     675,   247,   421,   416,   243,   417,   244,   245,   248,   246,
     243,   423,   244,   245,   545,   246,   247,  1123,   425,   111,
     547,   552,   247,   248,   554,   556,   558,   560,   562,  1062,
    1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,   564,
     566,   571,   795,   709,   573,   795,   575,   309,   310,   577,
     580,   615,   605,   605,   950,   617,   317,   223,   798,   334,
     369,   798,   144,   988,   619,   621,   623,   625,   611,   611,
     627,   925,   377,   604,   604,   629,   607,   607,   822,   608,
     608,   931,   610,   610,   235,   631,   602,  1163,   602,   974,
     975,   397,   633,   938,   700,   980,  1073,   635,   537,   701,
     673,   953,   446,   447,   448,   449,   450,   451,   452,   453,
     977,   637,   639,   641,   312,   313,   643,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   237,   474,  -454,
    -454,  1230,   475,   476,   477,   478,   479,   480,   481,   482,
     300,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   645,   647,   707,   814,   711,  1032,  1033,  1034,  1035,
     660,   516,   302,   517,   518,   315,   316,   304,   493,   494,
     495,   496,   497,   498,   499,   748,   220,   500,   501,   502,
     503,   675,   803,   749,   907,   243,   908,   244,   245,   379,
     246,   381,   112,   383,   404,   406,   702,   247,   712,   716,
     221,   602,   602,   193,   718,   720,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   795,   732,   734,   818,   357,
     736,   738,   798,   798,   798,   798,   798,   798,   798,   798,
     798,   798,   828,   741,   823,   825,   675,   675,   675,   675,
     931,   938,   980,  1113,  1115,  1117,   224,   225,  1119,  1190,
     226,  1192,  1194,   710,  1196,  1007,   175,  1008,   228,   230,
     224,   225,   262,   264,   226,   318,   319,  1084,   335,   336,
     370,  1087,  1106,   266,   273,   275,   277,   279,   281,   283,
     926,   927,   378,   113,   114,   285,   287,   289,   291,   293,
     244,   932,   295,   297,   867,   306,   320,   322,   398,   324,
     399,   929,   244,   939,   244,   981,   115,  -386,   929,   504,
     516,   505,   517,   518,   506,   326,   328,   659,  -454,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,   507,   330,   332,
     116,   337,   339,   341,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,   343,  -403,   675,   345,   347,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,   349,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,   351,   358,
     359,   360,   361,  1009,  1172,  1010,  1174,  1176,   194,  1177,
     353,   355,   362,  1152,   364,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,   602,   602,  -403,  -403,  -403,  -403,  1011,   380,
    1012,   382,   985,   384,   405,   407,   703,   222,   713,   717,
     675,   117,   675,   675,   719,   721,   205,   224,   225,   371,
    1181,   226,  1107,  1108,  1109,  1110,   733,   735,   128,  1199,
     737,   739,   129,   373,   375,   387,  1221,   389,   391,   393,
     395,   408,   722,   742,   824,   826,   724,  1133,  1168,   211,
     932,   939,   981,  1114,  1116,  1118,   730,   505,  1120,  1191,
     815,  1193,  1195,  1213,  1197,   229,   231,   819,  1088,   263,
     265,  1089,   207,   507,   209,   130,   131,   132,   934,  1247,
     267,   274,   276,   278,   280,   282,   284,   213,   133,  1216,
    1218,  1219,   286,   288,   290,   292,   294,   879,   134,   296,
     298,   135,   307,   321,   323,   941,   325,   945,  1111,   136,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,   327,   329,   137,  1022,  -403,  1023,  -403,  1186,
    1188,  -403,  -403,   660,  -403,   331,   333,  -403,   338,   340,
     342,   138,   215,   139,  -403,   986,   987,   505,   759,   224,
     225,   762,   764,   226,   771,   765,  1165,   772,   780,   140,
    1024,   344,  1025,   507,   346,   348,   805,   807,  1030,   806,
    1031,   141,   224,   225,   350,   142,   226,   944,   145,   929,
    1182,  1183,  1184,  1185,   827,   352,   673,  1132,   446,   447,
     448,   449,   450,   451,   452,   453,   148,   354,   356,   363,
    1146,   365,  1147,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   305,   474,  -450,  -450,  1232,   475,   476,
     477,   478,   479,   480,   481,   482,   372,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   983,   149,   929,
     374,   376,   388,   984,   390,   392,   394,   396,   409,   723,
     150,   151,   152,   725,   493,   494,   495,   496,   497,   498,
     499,   153,   217,   500,   501,   502,   503,   816,  1148,  1051,
    1149,  1203,   154,  1204,   820,   673,   155,   446,   447,   448,
     449,   450,   451,   452,   453,   935,   750,   968,   969,   970,
     971,   972,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   942,   474,   946,  1112,  1166,   475,   476,   477,
     478,   479,   480,   481,   482,   156,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,  1187,  1189,   157,   956,
     958,   158,   957,   959,   159,   160,   805,   807,   161,   962,
     162,   268,   163,   493,   494,   495,   496,   497,   498,   499,
     164,   269,   500,   501,   502,   503,   165,   768,   166,   768,
     768,   768,   167,   768,   168,  1097,   169,   763,   170,  -320,
    -320,   808,   171,  -320,   172,  1098,   770,  1099,  1100,  1101,
    1102,  1103,   173,   176,   177,   504,   178,   505,   179,   180,
     506,   181,   182,   673,  -450,   446,   447,   448,   449,   450,
     451,   452,   453,   507,   804,   183,   184,   185,   186,   187,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     188,   474,   189,   190,   195,   475,   476,   477,   478,   479,
     480,   481,   482,   869,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   870,   196,   871,   872,   873,   874,
     197,   270,   751,   752,   753,   754,   755,   756,   757,   758,
     198,   493,   494,   495,   496,   497,   498,   499,   199,   271,
     500,   501,   502,   503,   504,   272,   505,   430,   400,   506,
     401,   402,   673,   674,   446,   447,   448,   449,   450,   451,
     452,   453,   507,   766,   403,   428,   246,   429,   443,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   432,
     474,   433,   441,   442,   475,   476,   477,   478,   479,   480,
     481,   482,   444,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   751,   752,   753,   754,   755,   756,   757,
     758,   808,   751,   752,   753,   754,   755,   756,   757,   758,
     493,   494,   495,   496,   497,   498,   499,   445,   528,   500,
     501,   502,   503,   769,   529,   774,   776,   778,   536,   782,
     751,   752,   753,   754,   755,   756,   757,   758,   773,   538,
     543,   539,   672,   243,   775,   244,   245,   678,   246,   548,
     549,   550,   504,   567,   505,   247,   568,   506,   569,   679,
     673,   680,   446,   447,   448,   449,   450,   451,   452,   453,
     507,   777,   578,   581,   582,   583,   584,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   585,   474,   612,
     648,   649,   475,   476,   477,   478,   479,   480,   481,   482,
     650,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   651,   239,   240,   241,   242,   652,   653,   654,   751,
     752,   753,   754,   755,   756,   655,   656,   657,   493,   494,
     495,   496,   497,   498,   499,   658,   681,   500,   501,   502,
     503,   504,   682,   505,   686,   688,   506,   687,   691,   673,
     683,   446,   447,   448,   449,   450,   451,   452,   453,   507,
     781,   692,   693,   704,   694,   705,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   740,   474,   743,   744,
     745,   475,   476,   477,   478,   479,   480,   481,   482,   746,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     829,   830,   831,   832,   751,   752,   753,   754,   755,   756,
     751,   752,   753,   754,   755,   756,   833,   493,   494,   495,
     496,   497,   498,   499,   834,   835,   500,   501,   502,   503,
     836,   837,   838,   854,   855,   839,   840,   751,   752,   753,
     754,   755,   756,   841,   857,   842,   243,   843,   244,   245,
     844,   246,   845,   846,   847,   858,   861,   878,   247,   504,
     862,   505,   859,   860,   506,   248,   864,   673,   684,   446,
     447,   448,   449,   450,   451,   452,   453,   507,   883,   884,
     885,   888,   889,   890,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   891,   474,   892,   893,   894,   475,
     476,   477,   478,   479,   480,   481,   482,   895,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   896,   520,
     897,   898,   522,   899,   523,   900,   751,   752,   753,   754,
     755,   756,   527,   901,   902,   493,   494,   495,   496,   497,
     498,   499,   903,   904,   500,   501,   502,   503,   504,   905,
     505,   906,   909,   506,   911,   910,   673,   685,   446,   447,
     448,   449,   450,   451,   452,   453,   507,   912,   913,   978,
     914,   979,  1016,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   915,   474,   916,   917,   918,   475,   476,
     477,   478,   479,   480,   481,   482,   869,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   870,   919,   871,
     872,   873,   874,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   920,   493,   494,   495,   496,   497,   498,
     499,   921,   922,   500,   501,   502,   503,   923,   973,   924,
    1097,   989,   990,   991,   992,   993,   994,   995,   661,   996,
    1098,   715,  1099,  1100,  1101,  1102,  1103,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   504,  1036,   505,   997,
    1048,   506,  1017,   998,   673,   955,   446,   447,   448,   449,
     450,   451,   452,   453,   507,   999,  1000,  1001,  1037,  1002,
    1003,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,  1038,   474,  1004,  1160,  1018,   475,   476,   477,   478,
     479,   480,   481,   482,  1005,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,  1006,  1013,  1014,  1015,   963,
     964,   965,   966,   967,   968,   969,   970,   971,   972,  1019,
    1020,  1026,   493,   494,   495,   496,   497,   498,   499,  1061,
    1021,   500,   501,   502,   503,   504,  1027,   505,  1028,  1029,
     506,  1042,  1039,   673,  1072,   446,   447,   448,   449,   450,
     451,   452,   453,   507,  1040,  1041,  1043,  1044,  1045,  1046,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
    1047,   474,  1050,  1052,  1054,   475,   476,   477,   478,   479,
     480,   481,   482,   869,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   870,  1055,   871,   872,   873,   874,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
    1056,   493,   494,   495,   496,   497,   498,   499,  1057,  1058,
     500,   501,   502,   503,   661,   751,   752,   753,   754,   755,
     756,   757,   758,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   751,   752,   753,   754,   755,   756,   757,   758,
    1059,   928,  1060,   504,   936,   505,  1078,  1162,   506,  1074,
    1075,   673,  1090,   446,   447,   448,   449,   450,   451,   452,
     453,   507,  1076,  1079,  1077,  1094,  1095,  1096,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,  1080,   474,
    1081,  1082,  1083,   475,   476,   477,   478,   479,   480,   481,
     482,  1085,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,  1086,  1122,  1124,  1133,  1125,  1153,  1126,  1127,
    1128,  1129,  1137,  1138,  1139,  1140,  1141,  1143,  1144,   493,
     494,   495,   496,   497,   498,   499,  1142,  1145,   500,   501,
     502,   503,   504,  1150,   505,  1154,  1151,   506,  1155,  1156,
     673,  1091,   446,   447,   448,   449,   450,   451,   452,   453,
     507,  1157,  1158,  1159,  1164,  1167,  1171,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,  1179,   474,  1178,
    1200,  1198,   475,   476,   477,   478,   479,   480,   481,   482,
    1201,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,  1205,  1206,  1207,  1202,  1208,  1209,  1222,  1223,  1210,
    1211,  1212,  1214,  1224,  1225,  1226,  1227,  1233,   493,   494,
     495,   496,   497,   498,   499,  1228,  1229,   500,   501,   502,
     503,  1231,   202,  1234,  1235,  1236,  1237,  1238,  1239,  1240,
    1246,  1241,  1242,  1244,  1243,   440,  1245,  1248,  1053,   436,
     431,     0,  1121,  1169,  1161,     0,     0,     0,     0,     0,
     504,     0,   505,     0,     0,   506,     0,     0,   673,  1092,
     446,   447,   448,   449,   450,   451,   452,   453,   507,     0,
       0,     0,     0,     0,     0,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   474,     0,     0,     0,
     475,   476,   477,   478,   479,   480,   481,   482,     0,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   495,   496,
     497,   498,   499,     0,     0,   500,   501,   502,   503,   504,
       0,   505,     0,     0,   506,     0,     0,   673,  1093,   446,
     447,   448,   449,   450,   451,   452,   453,   507,     0,     0,
       0,     0,     0,     0,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   474,     0,     0,     0,   475,
     476,   477,   478,   479,   480,   481,   482,     0,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,   499,     0,     0,   500,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   505,
       0,     0,   506,     0,     0,     0,  1180,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
       0,     0,     0,    -2,   201,     0,     0,     0,     0,     0,
       0,     0,     0,    -8,   -10,   -12,   -14,   -16,   -18,   -20,
     -22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,   505,     0,
       0,   506,     0,     0,     0,  -456,     0,     0,     0,     2,
       3,     0,     0,     0,   507,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
     446,   447,   448,   449,   450,   451,   452,   453,     0,     0,
       0,     0,     0,     0,     0,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,   476,   477,   478,   479,   480,   481,   482,    88,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,     0,     0,     0,     0,     0,   493,   494,   495,   496,
     497,   498,   499,     0,     0,   500,   501,   502,   503,   446,
     447,   448,   449,   450,   451,   452,   453,     0,     0,     0,
       0,     0,     0,     0,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,     0,     0,     0,     0,     0,     0,     0,
     476,   477,   478,   479,   480,   481,   482,     0,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   586,   587,
     588,   589,   787,   591,   788,   593,   594,   595,   596,   597,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,   499,     0,     0,   500,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   225,     0,   598,   226,     0,   504,     0,   505,
       0,     0,     0,     0,   599,   600,     0,   601,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
     446,   447,   448,   449,   450,   451,   452,   453,     0,     0,
       0,     0,     0,     0,     0,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   474,     0,     0,     0,
     475,   476,   477,   478,   479,   480,   481,   482,     0,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,     0,
     224,   225,   789,     0,   226,     0,   790,   791,   505,     0,
       0,     0,     0,   792,     0,     0,   493,   494,   495,   496,
     497,   498,   499,     0,   507,   500,   501,   502,   503,   446,
     447,   448,   449,   450,   451,   452,   453,     0,     0,     0,
       0,     0,     0,     0,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   474,     0,     0,     0,   475,
     476,   477,   478,   479,   480,   481,   482,     0,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,   499,     0,     0,   500,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   799,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   505,
       0,     0,   506,     0,     0,   801,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
     446,   447,   448,   449,   450,   451,   452,   453,     0,     0,
       0,     0,     0,     0,     0,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   474,     0,     0,     0,
     475,   476,   477,   478,   479,   480,   481,   482,     0,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,   504,     0,   505,     0,
       0,   506,     0,     0,     0,   785,   493,   494,   495,   496,
     497,   498,   499,     0,   507,   500,   501,   502,   503,   446,
     447,   448,   449,   450,   451,   452,   453,     0,     0,     0,
       0,     0,     0,     0,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   474,     0,     0,     0,   475,
     476,   477,   478,   479,   480,   481,   482,     0,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,   499,     0,     0,   500,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   505,
       0,     0,   506,     0,     0,     0,   976,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
     446,   447,   448,   449,   450,   451,   452,   453,     0,     0,
       0,     0,     0,     0,     0,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   474,     0,     0,  1215,
     475,   476,   477,   478,   479,   480,   481,   482,     0,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,   504,     0,   505,     0,
       0,   506,     0,     0,   801,     0,   493,   494,   495,   496,
     497,   498,   499,     0,   507,   500,   501,   502,   503,   446,
     447,   448,   449,   450,   451,   452,   453,     0,     0,     0,
       0,     0,     0,     0,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   474,     0,     0,  1217,   475,
     476,   477,   478,   479,   480,   481,   482,     0,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,   499,     0,     0,   500,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   505,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
     446,   447,   448,   449,   450,   451,   452,   453,     0,     0,
       0,     0,     0,     0,     0,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   474,     0,     0,     0,
     475,   476,   477,   478,   479,   480,   481,   482,     0,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,   504,     0,   505,     0,
       0,   506,     0,     0,     0,     0,   493,   494,   495,   496,
     497,   498,   499,     0,   507,   500,   501,   502,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,    -8,   -10,   -12,   -14,   -16,   -18,
     -20,   -22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   505,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,   507,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-855))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     107,   174,   175,   114,   510,   416,   473,   442,   475,   444,
     421,   613,   423,   184,   425,   521,   771,   671,   524,   525,
     526,   875,   473,     1,   475,     1,     1,   473,     1,   475,
     473,     1,   475,   473,     1,   475,   473,     1,   475,     1,
       1,     1,     1,     1,     1,   475,     1,    72,     1,     1,
      72,   765,     1,     1,     1,     1,     1,   214,   772,     1,
      74,    75,    76,    77,     1,     1,   218,     1,     1,   204,
     205,     1,   222,     1,     1,     1,   186,   234,     1,     1,
       1,     1,     1,   550,   218,   237,   218,   221,   238,   223,
     222,   226,   806,     1,     1,     1,   230,   603,     1,   186,
       1,   568,   569,     1,     1,     1,   238,   613,     1,     1,
      74,    75,    76,    77,    74,    75,    76,    77,     1,     1,
       1,     1,     1,     1,     1,    74,    75,    76,    77,     1,
     186,   598,   599,     1,   601,   789,   232,   233,   792,     1,
      74,    75,    76,    77,     1,   612,     1,   598,   599,   260,
     601,     1,   598,   599,     1,   598,   599,   233,   598,   599,
     236,   598,   599,   217,     1,     1,     1,     1,   598,   599,
       1,   186,   218,   227,   218,     1,   222,   186,   222,   218,
     214,   215,   186,   222,   218,    63,    64,    65,    66,   600,
      68,   658,   238,   218,   238,   218,   218,     1,   223,   238,
     223,   223,   214,   215,   671,   230,   218,   230,   230,   221,
       1,   224,   186,   226,    51,     1,     1,   214,   215,   186,
     671,   218,   221,   237,     1,   222,     0,   226,   186,   226,
     187,    10,     1,   186,     1,   192,     1,     1,   230,   186,
     218,   238,   218,   218,   186,   223,   221,   220,     1,     1,
     186,   226,   230,   688,   218,   690,   220,   221,     1,   223,
     230,   237,   433,   434,   225,   224,   230,  1121,   230,   218,
     229,   220,   221,   237,   223,   230,   228,   237,   230,   227,
     786,   230,   228,   228,   218,   230,   220,   221,   237,   223,
     218,   228,   220,   221,   227,   223,   230,  1052,   228,   186,
     227,   227,   230,   237,   227,   227,   227,   227,   227,   963,
     964,   965,   966,   967,   968,   969,   970,   971,   972,   227,
     227,   227,   789,     1,   227,   792,   227,   220,   221,   227,
     227,   227,   799,   800,   780,   227,     1,     1,   789,     1,
       1,   792,   221,   810,   227,   227,   227,   227,   799,   800,
     227,     1,     1,   799,   800,   227,   799,   800,   226,   799,
     800,     1,   799,   800,   221,   227,   473,  1122,   475,   799,
     800,     1,   227,     1,   221,     1,   978,   227,     1,   226,
       1,   218,     3,     4,     5,     6,     7,     8,     9,    10,
     801,   227,   227,   227,   220,   221,   227,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,   221,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     221,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   227,   227,   550,   615,   552,   857,   858,   859,   860,
     227,   218,   221,   220,   221,   220,   221,   221,    79,    80,
      81,    82,    83,    84,    85,   218,   218,    88,    89,    90,
      91,   977,   978,   226,   224,   218,   226,   220,   221,     1,
     223,     1,   186,     1,     1,     1,     1,   230,     1,     1,
       1,   598,   599,     1,     1,     1,   963,   964,   965,   966,
     967,   968,   969,   970,   971,   972,     1,     1,   619,     1,
       1,     1,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   629,     1,     1,     1,  1032,  1033,  1034,  1035,
       1,     1,     1,     1,     1,     1,   214,   215,     1,     1,
     218,     1,     1,   221,     1,   224,   230,   226,     1,     1,
     214,   215,     1,     1,   218,   220,   221,  1024,   220,   221,
     221,  1028,     1,     1,     1,     1,     1,     1,     1,     1,
     220,   221,   221,   186,   186,     1,     1,     1,     1,     1,
     220,   221,     1,     1,   691,     1,     1,     1,   218,     1,
     220,   764,   220,   221,   220,   221,   186,   220,   771,   220,
     218,   222,   220,   221,   225,     1,     1,     1,   229,     3,
       4,     5,     6,     7,     8,     9,    10,   238,     1,     1,
     186,     1,     1,     1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     1,    39,  1152,     1,     1,    43,
      44,    45,    46,    47,    48,    49,    50,     1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     1,   161,
     162,   163,   164,   224,  1141,   226,  1143,  1144,   186,  1146,
       1,     1,     1,  1094,     1,    79,    80,    81,    82,    83,
      84,    85,   799,   800,    88,    89,    90,    91,   224,   221,
     226,   221,   809,   221,   221,   221,   221,   218,   221,   221,
    1216,   186,  1218,  1219,   221,   221,    11,   214,   215,     1,
       1,   218,   161,   162,   163,   164,   221,   221,   186,  1164,
     221,   221,   186,     1,     1,     1,  1203,     1,     1,     1,
       1,     1,     1,   221,   221,   221,     1,    40,    41,    14,
     221,   221,   221,   221,   221,   221,   221,   222,   221,   221,
       1,   221,   221,  1198,   221,   218,   218,     1,   218,   218,
     218,   221,    12,   238,    13,   186,   186,   186,     1,  1246,
     218,   218,   218,   218,   218,   218,   218,    15,   186,  1200,
    1201,  1202,   218,   218,   218,   218,   218,   696,   186,   218,
     218,   186,   218,   218,   218,     1,   218,     1,     1,   186,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   218,   218,   186,   224,   220,   226,   222,     1,
       1,   225,   226,   227,   228,   218,   218,   231,   218,   218,
     218,   186,    16,   186,   238,   220,   221,   222,   586,   214,
     215,   586,   590,   218,   592,   590,   221,   592,   596,   186,
     224,   218,   226,   238,   218,   218,   604,   605,   224,   604,
     226,   186,   214,   215,   218,   186,   218,   776,   186,  1052,
     161,   162,   163,   164,   226,   218,     1,  1060,     3,     4,
       5,     6,     7,     8,     9,    10,   186,   218,   218,   218,
     224,   218,   226,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,   221,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   218,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    72,   186,  1122,
     218,   218,   218,    78,   218,   218,   218,   218,   218,   218,
     186,   186,   186,   218,    79,    80,    81,    82,    83,    84,
      85,   186,    17,    88,    89,    90,    91,   218,   224,   878,
     226,   224,   186,   226,   218,     1,   186,     3,     4,     5,
       6,     7,     8,     9,    10,   218,     1,   211,   212,   213,
     214,   215,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   218,    39,   218,   218,  1133,    43,    44,    45,
      46,    47,    48,    49,    50,   186,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   218,   218,   186,   787,
     788,   186,   787,   788,   186,   186,   794,   795,   186,   794,
     186,   218,   186,    79,    80,    81,    82,    83,    84,    85,
     186,   218,    88,    89,    90,    91,   186,   591,   186,   593,
     594,   595,   186,   597,   186,   155,   186,     1,   186,   214,
     215,   605,   186,   218,   186,   165,     1,   167,   168,   169,
     170,   171,   186,   186,   186,   220,   186,   222,   186,   186,
     225,   186,   186,     1,   229,     3,     4,     5,     6,     7,
       8,     9,    10,   238,     1,   186,   186,   186,   186,   186,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     186,    39,   186,   186,   186,    43,    44,    45,    46,    47,
      48,    49,    50,   155,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   166,   186,   168,   169,   170,   171,
     186,   218,   187,   188,   189,   190,   191,   192,   193,   194,
     186,    79,    80,    81,    82,    83,    84,    85,   186,   218,
      88,    89,    90,    91,   220,   218,   222,   234,   218,   225,
     218,   220,     1,   229,     3,     4,     5,     6,     7,     8,
       9,    10,   238,     1,   218,   218,   223,   218,   231,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   236,
      39,   236,   224,   236,    43,    44,    45,    46,    47,    48,
      49,    50,   236,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   187,   188,   189,   190,   191,   192,   193,
     194,   795,   187,   188,   189,   190,   191,   192,   193,   194,
      79,    80,    81,    82,    83,    84,    85,   236,   218,    88,
      89,    90,    91,   591,   231,   593,   594,   595,   218,   597,
     187,   188,   189,   190,   191,   192,   193,   194,     1,   220,
     228,   221,   225,   218,     1,   220,   221,   231,   223,   227,
     227,   227,   220,   227,   222,   230,   227,   225,   227,   231,
       1,   229,     3,     4,     5,     6,     7,     8,     9,    10,
     238,     1,   227,   227,   227,   227,   227,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,   227,    39,   227,
     227,   227,    43,    44,    45,    46,    47,    48,    49,    50,
     227,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   227,    74,    75,    76,    77,   227,   227,   227,   187,
     188,   189,   190,   191,   192,   227,   227,   227,    79,    80,
      81,    82,    83,    84,    85,   227,   231,    88,    89,    90,
      91,   220,   231,   222,   224,   236,   225,   234,   224,     1,
     229,     3,     4,     5,     6,     7,     8,     9,    10,   238,
       1,   231,   228,   226,   231,   226,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   226,    39,   226,   226,
     226,    43,    44,    45,    46,    47,    48,    49,    50,   226,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     218,   218,   218,   218,   187,   188,   189,   190,   191,   192,
     187,   188,   189,   190,   191,   192,   218,    79,    80,    81,
      82,    83,    84,    85,   218,   218,    88,    89,    90,    91,
     218,   218,   221,    78,    78,   221,   221,   187,   188,   189,
     190,   191,   192,   221,   228,   221,   218,   221,   220,   221,
     221,   223,   221,   221,   221,   228,   218,   227,   230,   220,
     218,   222,   228,   228,   225,   237,   218,     1,   229,     3,
       4,     5,     6,     7,     8,     9,    10,   238,   226,   226,
     226,   226,   226,   226,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,   226,    39,   224,   226,   224,    43,
      44,    45,    46,    47,    48,    49,    50,   226,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   226,   414,
     226,   226,   417,   226,   419,   226,   187,   188,   189,   190,
     191,   192,   427,   226,   226,    79,    80,    81,    82,    83,
      84,    85,   226,   226,    88,    89,    90,    91,   220,   226,
     222,   226,   226,   225,   224,   226,     1,   229,     3,     4,
       5,     6,     7,     8,     9,    10,   238,   224,   226,    38,
     226,    72,   224,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,   226,    39,   226,   226,   226,    43,    44,
      45,    46,    47,    48,    49,    50,   155,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   166,   226,   168,
     169,   170,   171,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   226,    79,    80,    81,    82,    83,    84,
      85,   226,   226,    88,    89,    90,    91,   226,   231,   226,
     155,   226,   226,   226,   226,   226,   226,   226,   186,   226,
     165,   556,   167,   168,   169,   170,   171,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   220,   231,   222,   226,
     229,   225,   224,   226,     1,   229,     3,     4,     5,     6,
       7,     8,     9,    10,   238,   226,   226,   226,   234,   226,
     226,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   233,    39,   226,   229,   224,    43,    44,    45,    46,
      47,    48,    49,    50,   226,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   226,   226,   226,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   224,
     224,   224,    79,    80,    81,    82,    83,    84,    85,   226,
     226,    88,    89,    90,    91,   220,   224,   222,   224,   226,
     225,   186,   226,     1,   229,     3,     4,     5,     6,     7,
       8,     9,    10,   238,   226,   228,   186,   186,   186,   186,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     186,    39,   228,   224,   221,    43,    44,    45,    46,    47,
      48,    49,    50,   155,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   166,   221,   168,   169,   170,   171,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     221,    79,    80,    81,    82,    83,    84,    85,   221,   221,
      88,    89,    90,    91,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   187,   188,   189,   190,   191,   192,   193,   194,
     221,    72,   213,   220,    72,   222,   221,   229,   225,   228,
     218,     1,   229,     3,     4,     5,     6,     7,     8,     9,
      10,   238,   218,   221,   218,   228,   218,   218,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   221,    39,
     221,   221,   221,    43,    44,    45,    46,    47,    48,    49,
      50,   221,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   221,   224,   226,    40,   226,   186,   226,   226,
     226,   226,   226,   226,   226,   224,   224,   224,   224,    79,
      80,    81,    82,    83,    84,    85,   226,   226,    88,    89,
      90,    91,   220,   224,   222,   186,   226,   225,   186,   186,
       1,   229,     3,     4,     5,     6,     7,     8,     9,    10,
     238,   186,   186,   186,   224,   229,   221,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,   221,    39,   218,
     236,   224,    43,    44,    45,    46,    47,    48,    49,    50,
     236,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   226,   224,   224,   236,   224,   224,   218,   218,   226,
     226,   224,   224,   218,   218,   221,   224,   226,    79,    80,
      81,    82,    83,    84,    85,   221,   225,    88,    89,    90,
      91,   225,    90,   226,   226,   226,   226,   226,   224,   221,
     224,   226,   225,   221,   225,   260,   226,   226,   881,   252,
     247,    -1,  1050,  1135,  1104,    -1,    -1,    -1,    -1,    -1,
     220,    -1,   222,    -1,    -1,   225,    -1,    -1,     1,   229,
       3,     4,     5,     6,     7,     8,     9,    10,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    -1,    -1,    88,    89,    90,    91,   220,
      -1,   222,    -1,    -1,   225,    -1,    -1,     1,   229,     3,
       4,     5,     6,     7,     8,     9,    10,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,
      -1,    -1,   225,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    -1,    -1,   229,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,   238,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,   235,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    -1,    -1,    88,    89,    90,    91,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,   217,   218,    -1,   220,    -1,   222,
      -1,    -1,    -1,    -1,   227,   228,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    -1,   238,    88,    89,    90,    91,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,
      -1,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    -1,    -1,   229,    79,    80,    81,    82,
      83,    84,    85,    -1,   238,    88,    89,    90,    91,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,
      -1,    -1,   225,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    -1,   228,    -1,    79,    80,    81,    82,
      83,    84,    85,    -1,   238,    88,    89,    90,    91,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    -1,   238,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,   238,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    86,    87,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   235,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     261,   262,   267,   269,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,     1,   186,
       1,   186,     1,   186,     1,   186,     1,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,     1,   221,   186,     1,   227,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   230,   230,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,     1,   186,     1,   186,   186,   186,   186,   186,   186,
       0,     1,   242,    10,   277,    11,   278,    12,   279,    13,
     280,    14,   281,    15,   282,    16,   283,    17,   284,     1,
     218,     1,   218,     1,   214,   215,   218,   254,     1,   218,
       1,   218,     1,   220,     1,   221,     1,   221,     1,    74,
      75,    76,    77,   218,   220,   221,   223,   230,   237,   251,
     252,   255,   257,   258,   263,   264,   265,   266,   297,     1,
     255,   256,     1,   218,     1,   218,     1,   218,   218,   218,
     218,   218,   218,     1,   218,     1,   218,     1,   218,     1,
     218,     1,   218,     1,   218,     1,   218,     1,   218,     1,
     218,     1,   218,     1,   218,     1,   218,     1,   218,     1,
     221,     1,   221,     1,   221,   221,     1,   218,     1,   220,
     221,     1,   220,   221,     1,   220,   221,     1,   220,   221,
       1,   218,     1,   218,     1,   218,     1,   218,     1,   218,
       1,   218,     1,   218,     1,   220,   221,     1,   218,     1,
     218,     1,   218,     1,   218,     1,   218,     1,   218,     1,
     218,     1,   218,     1,   218,     1,   218,     1,   161,   162,
     163,   164,     1,   218,     1,   218,   263,   221,   263,     1,
     221,     1,   218,     1,   218,     1,   218,     1,   221,     1,
     221,     1,   221,     1,   221,     1,   251,     1,   218,     1,
     218,     1,   218,     1,   218,     1,   218,     1,   218,   220,
     218,   218,   220,   218,     1,   221,     1,   221,     1,   218,
       1,   228,   230,     1,   230,     1,   228,   230,     1,   230,
       1,   228,     1,   228,     1,   228,     1,   230,   218,   218,
     234,   265,   236,   236,   232,   233,   258,   214,   234,   296,
     256,   224,   236,   231,   236,   236,     3,     4,     5,     6,
       7,     8,     9,    10,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    39,    43,    44,    45,    46,    47,
      48,    49,    50,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    79,    80,    81,    82,    83,    84,    85,
      88,    89,    90,    91,   220,   222,   225,   238,   292,   300,
     303,   304,   305,   306,   307,   313,   218,   220,   221,   276,
     276,   303,   276,   276,   303,   303,   303,   276,   218,   231,
       1,   218,   237,   253,   251,   251,   218,     1,   220,   221,
     253,   271,   253,   228,     1,   227,     1,   227,   227,   227,
     227,     1,   227,     1,   227,     1,   227,     1,   227,     1,
     227,     1,   227,     1,   227,     1,   227,   227,   227,   227,
       1,   227,     1,   227,     1,   227,     1,   227,   227,     1,
     227,   227,   227,   227,   227,   227,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   217,   227,
     228,   230,   254,   285,   291,   292,   293,   294,   300,   301,
     305,   313,   227,   285,     1,   227,     1,   227,     1,   227,
       1,   227,     1,   227,     1,   227,     1,   227,     1,   227,
       1,   227,     1,   227,     1,   227,     1,   227,     1,   227,
       1,   227,     1,   227,     1,   227,     1,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,     1,
     227,   186,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   298,   225,     1,   229,   304,     1,   225,   231,   231,
     229,   231,   231,   229,   229,   229,   224,   234,   236,   233,
     236,   224,   231,   228,   231,   217,   227,   259,   260,     1,
     221,   226,     1,   221,   226,   226,   226,   254,   292,     1,
     221,   254,     1,   221,     1,   276,     1,   221,     1,   221,
       1,   221,     1,   218,     1,   218,   221,   226,   218,   292,
     221,   292,     1,   221,     1,   221,     1,   221,     1,   221,
     226,     1,   221,   226,   226,   226,   226,     1,   218,   226,
       1,   187,   188,   189,   190,   191,   192,   193,   194,   286,
     287,   288,   290,     1,   286,   290,     1,   286,   287,   289,
       1,   286,   290,     1,   289,     1,   289,     1,   289,     1,
     286,     1,   289,   285,   285,   229,   303,    66,    68,   216,
     220,   221,   227,   254,   291,   292,   294,   299,   313,   204,
     205,   228,   302,   304,     1,   286,   290,   286,   287,   289,
     290,   292,   302,     1,   251,     1,   218,     1,   255,     1,
     218,     1,   226,     1,   221,     1,   221,   226,   254,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   292,     1,
     218,   221,   226,   312,    78,    78,   299,   228,   228,   228,
     228,   218,   218,   253,   218,   253,   221,   254,   268,   155,
     166,   168,   169,   170,   171,   273,   275,   270,   227,   252,
       1,   224,   229,   226,   226,   226,   224,   226,   226,   226,
     226,   226,   224,   226,   224,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   224,   226,   226,
     226,   224,   224,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,     1,   220,   221,    72,   263,
     295,     1,   221,   297,     1,   218,    72,   295,     1,   221,
     297,     1,   218,     1,   252,     1,   218,     1,    66,    68,
     291,     1,    51,   218,   226,   229,   286,   290,   286,   290,
     299,   299,   290,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   231,   285,   285,   229,   303,    38,    72,
       1,   221,   297,    72,    78,   254,   220,   221,   292,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   224,   226,   224,
     226,   224,   226,   226,   226,   226,   224,   224,   224,   224,
     224,   226,   224,   226,   224,   226,   224,   224,   224,   226,
     224,   226,   303,   303,   303,   303,   231,   234,   233,   226,
     226,   228,   186,   186,   186,   186,   186,   186,   229,   275,
     228,   252,   224,   259,   221,   221,   221,   221,   221,   221,
     213,   226,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   229,   302,   228,   218,   218,   218,   221,   221,
     221,   221,   221,   221,   292,   221,   221,   292,   218,   221,
     229,   229,   229,   229,   228,   218,   218,   155,   165,   167,
     168,   169,   170,   171,   272,   274,     1,   161,   162,   163,
     164,     1,   218,     1,   221,     1,   221,     1,   221,     1,
     221,   273,   224,   295,   226,   226,   226,   226,   226,   226,
       1,   218,   263,    40,   308,   309,   310,   226,   226,   226,
     224,   224,   226,   224,   224,   226,   224,   226,   224,   226,
     224,   226,   303,   186,   186,   186,   186,   186,   186,   186,
     229,   274,   229,   295,   224,   221,   254,   229,    41,   310,
     311,   221,   292,   218,   292,   218,   292,   292,   218,   221,
     229,     1,   161,   162,   163,   164,     1,   218,     1,   218,
       1,   221,     1,   221,     1,   221,     1,   221,   224,   253,
     236,   236,   236,   224,   226,   226,   224,   224,   224,   224,
     226,   226,   224,   253,   224,    42,   303,    42,   303,   303,
     218,   292,   218,   218,   218,   218,   221,   224,   221,   225,
      42,   225,    42,   226,   226,   226,   226,   226,   226,   224,
     221,   226,   225,   225,   221,   226,   224,   292,   226
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1806 of yacc.c  */
#line 473 "cfg.y"
    {}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 474 "cfg.y"
    {}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 475 "cfg.y"
    { yyerror(""); YYABORT;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 480 "cfg.y"
    {rt=REQUEST_ROUTE;}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 481 "cfg.y"
    {rt=FAILURE_ROUTE;}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 482 "cfg.y"
    {rt=ONREPLY_ROUTE;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 483 "cfg.y"
    {rt=BRANCH_ROUTE;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 484 "cfg.y"
    {rt=ERROR_ROUTE;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 485 "cfg.y"
    {rt=LOCAL_ROUTE;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 486 "cfg.y"
    {rt=STARTUP_ROUTE;}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 487 "cfg.y"
    {rt=TIMER_ROUTE;}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 492 "cfg.y"
    {	tmp=ip_addr2a((yyvsp[(1) - (1)].ipaddr));
							if(tmp==0){
								LM_CRIT("cfg. parser: bad ip address.\n");
								(yyval.strval)=0;
							}else{
								(yyval.strval)=pkg_malloc(strlen(tmp)+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									strncpy((yyval.strval), tmp, strlen(tmp)+1);
								}
							}
						}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 505 "cfg.y"
    {	(yyval.strval)=pkg_malloc(strlen((yyvsp[(1) - (1)].strval))+1);
							if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
							}else{
									strncpy((yyval.strval), (yyvsp[(1) - (1)].strval), strlen((yyvsp[(1) - (1)].strval))+1);
							}
						}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 512 "cfg.y"
    {	if ((yyvsp[(1) - (1)].strval)==0) {
								(yyval.strval) = 0;
							} else {
								(yyval.strval)=pkg_malloc(strlen((yyvsp[(1) - (1)].strval))+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									strncpy((yyval.strval), (yyvsp[(1) - (1)].strval), strlen((yyvsp[(1) - (1)].strval))+1);
								}
							}
						}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 525 "cfg.y"
    { (yyval.intval)=PROTO_UDP; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 526 "cfg.y"
    { (yyval.intval)=PROTO_TCP; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 527 "cfg.y"
    {
			#ifdef USE_TLS
				(yyval.intval)=PROTO_TLS;
			#else
				(yyval.intval)=PROTO_TCP;
				warn("tls support not compiled in");
			#endif
			}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 535 "cfg.y"
    { 
			#ifdef USE_SCTP
				(yyval.intval)=PROTO_SCTP;
			#else
				yyerror("sctp support not compiled in\n");YYABORT;
			#endif
			}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 542 "cfg.y"
    { (yyval.intval)=0; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 545 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 546 "cfg.y"
    { (yyval.intval)=0; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 549 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 550 "cfg.y"
    { (yyval.intval)=(yyvsp[(2) - (2)].intval); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 551 "cfg.y"
    { (yyval.intval)=-(yyvsp[(2) - (2)].intval); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 555 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (1)].strval), 0, 0); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 556 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (3)].strval), 0, (yyvsp[(3) - (3)].intval)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 557 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (3)].strval), (yyvsp[(1) - (3)].intval), 0); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 558 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (5)].strval), (yyvsp[(1) - (5)].intval), (yyvsp[(5) - (5)].intval));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 559 "cfg.y"
    { (yyval.sockid)=0; yyerror(" port number expected"); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 562 "cfg.y"
    {  (yyval.sockid)=(yyvsp[(1) - (1)].sockid) ; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 563 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (2)].sockid); (yyval.sockid)->next=(yyvsp[(2) - (2)].sockid); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 567 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (1)].sockid); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 568 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (3)].sockid); (yyval.sockid)->children=(yyvsp[(3) - (3)].intval); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 569 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (3)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (3)].sockid), (yyvsp[(3) - (3)].strval), 5060); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 570 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (5)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (5)].sockid), (yyvsp[(3) - (5)].strval), 5060); (yyvsp[(1) - (5)].sockid)->children=(yyvsp[(5) - (5)].intval); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 571 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (5)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (5)].sockid), (yyvsp[(3) - (5)].strval), (yyvsp[(5) - (5)].intval)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 572 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (7)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (7)].sockid), (yyvsp[(3) - (7)].strval), (yyvsp[(5) - (7)].intval)); (yyvsp[(1) - (7)].sockid)->children=(yyvsp[(7) - (7)].intval); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 575 "cfg.y"
    {  (yyval.sockid)=(yyvsp[(1) - (1)].sockid) ; }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 576 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (2)].sockid); (yyval.sockid)->next=(yyvsp[(2) - (2)].sockid); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 580 "cfg.y"
    {
				s_tmp.s=(yyvsp[(8) - (9)].strval);
				s_tmp.len=strlen((yyvsp[(8) - (9)].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[(4) - (9)].ipnet),&s_tmp,(yyvsp[(6) - (9)].intval),(yyvsp[(2) - (9)].intval),0)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 587 "cfg.y"
    {
				s_tmp.s=(yyvsp[(9) - (10)].strval);
				s_tmp.len=strlen((yyvsp[(9) - (10)].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[(5) - (10)].ipnet),&s_tmp,
				(yyvsp[(7) - (10)].intval),(yyvsp[(3) - (10)].intval),BLR_APPLY_CONTRARY)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 597 "cfg.y"
    {}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 598 "cfg.y"
    {}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 599 "cfg.y"
    { yyerror("bad black list element");}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 603 "cfg.y"
    { 
#ifdef CHANGEABLE_DEBUG_LEVEL
					*debug=(yyvsp[(3) - (3)].intval);
#else
					debug=(yyvsp[(3) - (3)].intval);
#endif
			}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 610 "cfg.y"
    { yyerror("number  expected"); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 611 "cfg.y"
    { dont_fork= !dont_fork ? ! (yyvsp[(3) - (3)].intval):1; }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 612 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 613 "cfg.y"
    { if (!config_check) log_stderr=(yyvsp[(3) - (3)].intval); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 614 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 615 "cfg.y"
    {
					if ( (i_tmp=str2facility((yyvsp[(3) - (3)].strval)))==-1)
						yyerror("bad facility (see syslog(3) man page)");
					if (!config_check)
						log_facility=i_tmp;
									}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 621 "cfg.y"
    { yyerror("ID expected"); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 622 "cfg.y"
    { log_name=(yyvsp[(3) - (3)].strval); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 623 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 624 "cfg.y"
    { 
/*				if ($3!=0 && $3[0]!=0)
					if ( add_avp_galias_str($3)!=0 )
						yyerror("invalid AVP aliases");;*/
				yyerror("AVP_ALIASES shouldn't be used anymore\n");
			}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 630 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 631 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_DNS:0; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 632 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 633 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_REV_DNS:0; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 634 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 635 "cfg.y"
    { dns_try_ipv6=(yyvsp[(3) - (3)].intval); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 636 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 637 "cfg.y"
    { dns_retr_time=(yyvsp[(3) - (3)].intval); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 638 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 639 "cfg.y"
    { dns_retr_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 640 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 641 "cfg.y"
    { dns_servers_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 642 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 643 "cfg.y"
    { dns_search_list=(yyvsp[(3) - (3)].intval); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 644 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 645 "cfg.y"
    { port_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 646 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 647 "cfg.y"
    { max_while_loops=(yyvsp[(3) - (3)].intval); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 648 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 649 "cfg.y"
    { maxbuffer=(yyvsp[(3) - (3)].intval); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 650 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 651 "cfg.y"
    { children_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 652 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 653 "cfg.y"
    { check_via=(yyvsp[(3) - (3)].intval); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 654 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 655 "cfg.y"
    { memlog=(yyvsp[(3) - (3)].intval); memdump=(yyvsp[(3) - (3)].intval); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 656 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 657 "cfg.y"
    { memdump=(yyvsp[(3) - (3)].intval); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 658 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 659 "cfg.y"
    { execmsgthreshold=(yyvsp[(3) - (3)].intval); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 660 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 661 "cfg.y"
    { execdnsthreshold=(yyvsp[(3) - (3)].intval); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 662 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 663 "cfg.y"
    { tcpthreshold=(yyvsp[(3) - (3)].intval); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 664 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 665 "cfg.y"
    { query_buffer_size=(yyvsp[(3) - (3)].intval); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 666 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 667 "cfg.y"
    { query_flush_time=(yyvsp[(3) - (3)].intval); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 668 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 669 "cfg.y"
    { sip_warning=(yyvsp[(3) - (3)].intval); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 670 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 671 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 672 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 673 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 674 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 675 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 676 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 677 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 678 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 679 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 680 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 681 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 682 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 683 "cfg.y"
    { mhomed=(yyvsp[(3) - (3)].intval); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 684 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 685 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 692 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 693 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_accept_aliases=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 700 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 701 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_children_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 708 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 709 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_connect_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 716 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 717 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 724 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 725 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_con_lifetime=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 732 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 733 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_poll_method=get_poll_type((yyvsp[(3) - (3)].strval));
										if (tcp_poll_method==POLL_NONE){
											LM_CRIT("bad poll method name:"
												" %s\n, try one of %s.\n",
												(yyvsp[(3) - (3)].strval), poll_support);
											yyerror("bad tcp_poll_method "
												"value");
										}
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 747 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_poll_method=get_poll_type((yyvsp[(3) - (3)].strval));
										if (tcp_poll_method==POLL_NONE){
											LM_CRIT("bad poll method name:"
												" %s\n, try one of %s.\n",
												(yyvsp[(3) - (3)].strval), poll_support);
											yyerror("bad tcp_poll_method "
												"value");
										}
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 761 "cfg.y"
    { yyerror("poll method name expected"); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 762 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_max_connections=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 769 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 770 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_crlf_pingpong=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 777 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 778 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_no_new_conn_bflag=(yyvsp[(3) - (3)].intval);
				if (!flag_in_range( (flag_t)tcp_no_new_conn_bflag ) )
					yyerror("invalid TCP no_new_conn Branch Flag");
				flag_idx2mask( &tcp_no_new_conn_bflag );
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 788 "cfg.y"
    { yyerror("number value expected"); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 789 "cfg.y"
    {
			#ifdef USE_TCP
			        tcp_keepalive=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 796 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 797 "cfg.y"
    { 
			#ifdef USE_TCP
			    #ifndef HAVE_TCP_KEEPCNT
				warn("cannot be enabled (no OS support)");
			    #else
			        tcp_keepcount=(yyvsp[(3) - (3)].intval);
			    #endif
		        #else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 808 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 809 "cfg.y"
    { 
			#ifdef USE_TCP
			    #ifndef HAVE_TCP_KEEPIDLE
				warn("cannot be enabled (no OS support)");
			    #else
			        tcp_keepidle=(yyvsp[(3) - (3)].intval);
			    #endif
		        #else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 820 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 821 "cfg.y"
    { 
			#ifdef USE_TCP
			    #ifndef HAVE_TCP_KEEPINTVL
				warn("cannot be enabled (no OS support)");
			    #else
			        tcp_keepinterval=(yyvsp[(3) - (3)].intval);
			    #endif
		        #else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 832 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 833 "cfg.y"
    {
									#ifdef USE_TLS
										tls_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 840 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 841 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_log=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 848 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 849 "cfg.y"
    {
									#ifdef USE_TLS
										tls_port_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 856 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 857 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv23;
										tls_default_client_domain->method =
											TLS_USE_SSLv23;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 867 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv2;
										tls_default_client_domain->method =
											TLS_USE_SSLv2;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 877 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv3;
										tls_default_client_domain->method =
											TLS_USE_SSLv3;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 887 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_TLSv1;
										tls_default_client_domain->method =
											TLS_USE_TLSv1;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 897 "cfg.y"
    {
									#ifdef USE_TLS
										yyerror("SSLv23, SSLv2, SSLv3 or TLSv1"
													" expected");
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 906 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->verify_cert
											= (yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 914 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 915 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_client_domain->verify_cert
											=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 923 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 924 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->require_client_cert=(yyvsp[(3) - (3)].intval);
									#else
										warn( "tls support not compiled in");
									#endif
									}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 931 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 932 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->cert_file=
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->cert_file=
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 942 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 943 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->pkey_file=
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->pkey_file=
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 953 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 954 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->ca_file =
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->ca_file =
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 964 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 965 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->ciphers_list
											= (yyvsp[(3) - (3)].strval);
										tls_default_client_domain->ciphers_list
											= (yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 975 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 976 "cfg.y"
    {
									#ifdef USE_TLS
										tls_handshake_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 983 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 984 "cfg.y"
    {
									#ifdef USE_TLS
										tls_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 991 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 992 "cfg.y"
    {
									#ifdef USE_TLS
										tstr.s = (yyvsp[(3) - (3)].strval);
										tstr.len = strlen(tstr.s);
										if (parse_avp_spec(&tstr, &tls_client_domain_avp)) {
											yyerror("cannot parse tls_client_avp");
										}
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1003 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1006 "cfg.y"
    { server_signature=(yyvsp[(3) - (3)].intval); }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1007 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1008 "cfg.y"
    { server_header.s=(yyvsp[(3) - (3)].strval);
									server_header.len=strlen((yyvsp[(3) - (3)].strval));
									}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1011 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1012 "cfg.y"
    { user_agent_header.s=(yyvsp[(3) - (3)].strval);
									user_agent_header.len=strlen((yyvsp[(3) - (3)].strval));
									}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1015 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1016 "cfg.y"
    { xlog_buf_size = (yyvsp[(3) - (3)].intval); }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1017 "cfg.y"
    { xlog_force_color = (yyvsp[(3) - (3)].intval); }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1018 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1019 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1021 "cfg.y"
    {
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next){
								if (add_listen_iface(	lst_tmp->name,
														lst_tmp->port,
														lst_tmp->proto,
														lst_tmp->adv_name,
														lst_tmp->adv_port,
														lst_tmp->children,
														0
													)!=0){
									LM_CRIT("cfg. parser: failed"
											" to add listen address\n");
									break;
								}
							}
							 }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1037 "cfg.y"
    { yyerror("ip address or hostname "
						"expected (use quotes if the hostname includes"
						" config keywords)"); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 1040 "cfg.y"
    { 
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next)
								add_alias(lst_tmp->name, strlen(lst_tmp->name),
											lst_tmp->port, lst_tmp->proto);
							  }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 1045 "cfg.y"
    { yyerror("hostname expected (use quotes"
							" if the hostname includes config keywords)"); }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 1047 "cfg.y"
    { auto_aliases=(yyvsp[(3) - (3)].intval); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 1048 "cfg.y"
    { yyerror("number  expected"); }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 1049 "cfg.y"
    {
								if ((yyvsp[(3) - (3)].strval)) {
									default_global_address.s=(yyvsp[(3) - (3)].strval);
									default_global_address.len=strlen((yyvsp[(3) - (3)].strval));
								}
								}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 1055 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 1057 "cfg.y"
    {
								tmp=int2str((yyvsp[(3) - (3)].intval), &i_tmp);
								if ((default_global_port.s=pkg_malloc(i_tmp))
										==0){
										LM_CRIT("cfg. parser: out of memory.\n");
										default_global_port.len=0;
								}else{
									default_global_port.len=i_tmp;
									memcpy(default_global_port.s, tmp,
											default_global_port.len);
								};
								}
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 1069 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 1071 "cfg.y"
    {
										disable_core_dump=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1074 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1075 "cfg.y"
    {
										open_files_limit=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1078 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1079 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_loopback=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1086 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1087 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_ttl=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1094 "cfg.y"
    { yyerror("number expected as tos"); }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1095 "cfg.y"
    { tos = (yyvsp[(3) - (3)].intval);
							if (tos<=0)
								yyerror("invalid tos value");
		 }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1099 "cfg.y"
    { if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_LOWDELAY")) {
								tos=IPTOS_LOWDELAY;
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_THROUGHPUT")) {
								tos=IPTOS_THROUGHPUT;
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_RELIABILITY")) {
								tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_MINCOST")) {
								tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_LOWCOST")) {
								tos=IPTOS_LOWCOST;
#endif
							} else {
								yyerror("invalid tos value - allowed: "
									"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
									"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
									",IPTOS_LOWCOST"
#endif
#if defined(IPTOS_MINCOST)
									",IPTOS_MINCOST"
#endif
									"\n");
							}
		 }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1126 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1127 "cfg.y"
    { mpath=(yyvsp[(3) - (3)].strval); strcpy(mpath_buf, (yyvsp[(3) - (3)].strval));
								mpath_len=strlen((yyvsp[(3) - (3)].strval)); 
								if(mpath_buf[mpath_len-1]!='/') {
									mpath_buf[mpath_len]='/';
									mpath_len++;
									mpath_buf[mpath_len]='\0';
								}
							}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1135 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1136 "cfg.y"
    {
										disable_dns_failover=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1139 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1140 "cfg.y"
    {
										disable_dns_blacklist=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1143 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1144 "cfg.y"
    {
				s_tmp.s = (yyvsp[(3) - (7)].strval);
				s_tmp.len = strlen((yyvsp[(3) - (7)].strval));
				if ( create_bl_head( BL_CORE_ID, BL_READONLY_LIST,
				bl_head, bl_tail, &s_tmp)==0) {
					yyerror("failed to create blacklist\n");
					YYABORT;
				}
				bl_head = bl_tail = 0;
				}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1154 "cfg.y"
    {
				sl_fwd_disabled=(yyvsp[(3) - (3)].intval);
				}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1157 "cfg.y"
    { db_version_table=(yyvsp[(3) - (3)].strval); }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1158 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1159 "cfg.y"
    { db_default_url=(yyvsp[(3) - (3)].strval); }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1160 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1161 "cfg.y"
    { disable_503_translation=(yyvsp[(3) - (3)].intval); }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1162 "cfg.y"
    {
				yyerror("string value expected");
				}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1165 "cfg.y"
    { yyerror("unknown config variable"); }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1168 "cfg.y"
    {
			if(*(yyvsp[(2) - (2)].strval)!='/' && mpath!=NULL
					&& strlen((yyvsp[(2) - (2)].strval))+mpath_len<255)
			{
				strcpy(mpath_buf+mpath_len, (yyvsp[(2) - (2)].strval));
				if (stat(mpath_buf, &statf) == -1) {
					i_tmp = strlen(mpath_buf);
					if(strchr((yyvsp[(2) - (2)].strval), '/')==NULL &&
							strncmp(mpath_buf+i_tmp-3, ".so", 3)==0)
					{
						if(i_tmp+strlen((yyvsp[(2) - (2)].strval))<255)
						{
							strcpy(mpath_buf+i_tmp-3, "/");
							strcpy(mpath_buf+i_tmp-2, (yyvsp[(2) - (2)].strval));
							if (stat(mpath_buf, &statf) == -1) {
								mpath_buf[mpath_len]='\0';
								LM_ERR("module '%s' not found in '%s'\n",
									(yyvsp[(2) - (2)].strval), mpath_buf);
								yyerror("failed to load module");
							}
						} else {
							yyerror("failed to load module - path too long");
						}
					} else {
						yyerror("failed to load module - not found");
					}
				}
				LM_DBG("loading module %s\n", mpath_buf);
				if (sr_load_module(mpath_buf)!=0){
					yyerror("failed to load module");
				}
				mpath_buf[mpath_len]='\0';
			} else {
				LM_DBG("loading module %s\n", (yyvsp[(2) - (2)].strval));
				if (sr_load_module((yyvsp[(2) - (2)].strval))!=0){
					yyerror("failed to load module");
				}
			}
		}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1207 "cfg.y"
    { yyerror("string expected");  }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1208 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), STR_PARAM, (yyvsp[(7) - (8)].strval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1214 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), INT_PARAM, (void*)(yyvsp[(7) - (8)].intval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1220 "cfg.y"
    { yyerror("Invalid arguments"); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1224 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1225 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1228 "cfg.y"
    { 
											(yyval.ipaddr)=pkg_malloc(
													sizeof(struct ip_addr));
											if ((yyval.ipaddr)==0){
												LM_CRIT("cfg. "
													"parser: out of memory.\n"
													);
											}else{
												memset((yyval.ipaddr), 0, 
													sizeof(struct ip_addr));
												(yyval.ipaddr)->af=AF_INET;
												(yyval.ipaddr)->len=4;
												if (((yyvsp[(1) - (7)].intval)>255) || ((yyvsp[(1) - (7)].intval)<0) ||
													((yyvsp[(3) - (7)].intval)>255) || ((yyvsp[(3) - (7)].intval)<0) ||
													((yyvsp[(5) - (7)].intval)>255) || ((yyvsp[(5) - (7)].intval)<0) ||
													((yyvsp[(7) - (7)].intval)>255) || ((yyvsp[(7) - (7)].intval)<0)){
													yyerror("invalid ipv4"
															"address");
													(yyval.ipaddr)->u.addr32[0]=0;
													/* $$=0; */
												}else{
													(yyval.ipaddr)->u.addr[0]=(yyvsp[(1) - (7)].intval);
													(yyval.ipaddr)->u.addr[1]=(yyvsp[(3) - (7)].intval);
													(yyval.ipaddr)->u.addr[2]=(yyvsp[(5) - (7)].intval);
													(yyval.ipaddr)->u.addr[3]=(yyvsp[(7) - (7)].intval);
													/*
													$$=htonl( ($1<<24)|
													($3<<16)| ($5<<8)|$7 );
													*/
												}
											}
												}
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 1262 "cfg.y"
    {
					(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
					if ((yyval.ipaddr)==0){
						LM_CRIT("ERROR: cfg. parser: out of memory.\n");
					}else{
						memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
						(yyval.ipaddr)->af=AF_INET6;
						(yyval.ipaddr)->len=16;
					#ifdef USE_IPV6
						if (inet_pton(AF_INET6, (yyvsp[(1) - (1)].strval), (yyval.ipaddr)->u.addr)<=0){
							yyerror("bad ipv6 address");
						}
					#else
						yyerror("ipv6 address & no ipv6 support compiled in");
						YYABORT;
					#endif
					}
				}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 1282 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1283 "cfg.y"
    {(yyval.ipaddr)=(yyvsp[(2) - (3)].ipaddr); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1286 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_server_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval))) 
								yyerror("tls_new_server_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 1297 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval)))
								yyerror("tls_new_client_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 1308 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain_name((yyvsp[(3) - (4)].strval), strlen((yyvsp[(3) - (4)].strval))))
								yyerror("tls_new_client_domain_name failed");
						#else	
							warn("tls support not compiled in");
						#endif
							}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 1327 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 1334 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 1341 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 1348 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 1355 "cfg.y"
    { yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 1356 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 1363 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 1365 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 1372 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 1374 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 1381 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1382 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1389 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1390 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1397 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1398 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->require_client_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn( "tls support not compiled in");
						#endif
								}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1405 "cfg.y"
    { 
						yyerror("boolean value expected"); }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1409 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1416 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1423 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1430 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1437 "cfg.y"
    {
						yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1439 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1446 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1448 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1455 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1457 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1464 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1465 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1472 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1473 "cfg.y"
    {
						#ifdef USE_TLS
									tls_client_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1480 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1483 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
				}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1486 "cfg.y"
    {
				tmp=int2str((yyvsp[(1) - (1)].intval), &i_tmp);
				if (((yyval.strval)=pkg_malloc(i_tmp+1))==0)
					yyerror("cfg. parser: out of memory.\n");
				memcpy( (yyval.strval), tmp, i_tmp);
				(yyval.strval)[i_tmp] = 0;
				}
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1493 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
		}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1498 "cfg.y"
    {
						if (rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"request routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &rlist[DEFAULT_RT].a);
					}
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1506 "cfg.y"
    { 
						if ( strtol((yyvsp[(3) - (7)].strval),&tmp,10)==0 && *tmp==0) {
							/* route[0] detected */
							if (rlist[DEFAULT_RT].a!=0) {
								yyerror("overwritting(2) default "
									"request routing table");
								YYABORT;
							}
							push((yyvsp[(6) - (7)].action), &rlist[DEFAULT_RT].a);
						} else {
							i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),rlist,RT_NO,1);
							if (i_tmp==-1) YYABORT;
							push((yyvsp[(6) - (7)].action), &rlist[i_tmp].a);
						}
					}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1521 "cfg.y"
    { yyerror("invalid  route  statement"); }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1524 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),failure_rlist,
								FAILURE_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &failure_rlist[i_tmp].a);
					}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1530 "cfg.y"
    { yyerror("invalid failure_route statement"); }
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1533 "cfg.y"
    {
						if (onreply_rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"onreply routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &onreply_rlist[DEFAULT_RT].a);
					}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1541 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),onreply_rlist,
								ONREPLY_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &onreply_rlist[i_tmp].a);
					}
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 1547 "cfg.y"
    { yyerror("invalid onreply_route statement"); }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 1550 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),branch_rlist,
								BRANCH_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &branch_rlist[i_tmp].a);
					}
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 1556 "cfg.y"
    { yyerror("invalid branch_route statement"); }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1559 "cfg.y"
    {
						if (error_rlist.a!=0) {
							yyerror("overwritting default "
								"error routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &error_rlist.a);
					}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1567 "cfg.y"
    { yyerror("invalid error_route statement"); }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1570 "cfg.y"
    {
						if (local_rlist.a!=0) {
							yyerror("re-definition of local "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &local_rlist.a);
					}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1578 "cfg.y"
    { yyerror("invalid local_route statement"); }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1581 "cfg.y"
    {
						if (startup_rlist.a!=0) {
							yyerror("re-definition of startup "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &startup_rlist.a);
					}
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1589 "cfg.y"
    { yyerror("invalid startup_route statement"); }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 1592 "cfg.y"
    {
						i_tmp = 0;
						while (timer_rlist[i_tmp].a!=0 && i_tmp < TIMER_RT_NO) {
							i_tmp++;
						}
						if(i_tmp == TIMER_RT_NO) {
							yyerror("Too many timer routes defined\n");
							YYABORT;
						}
						timer_rlist[i_tmp].interval = (yyvsp[(5) - (9)].intval);
						push((yyvsp[(8) - (9)].action), &timer_rlist[i_tmp].a);
					}
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1604 "cfg.y"
    { yyerror("invalid timer_route statement"); }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1607 "cfg.y"
    { (yyval.expr)=mk_exp(AND_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1608 "cfg.y"
    { (yyval.expr)=mk_exp(OR_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1609 "cfg.y"
    { (yyval.expr)=mk_exp(NOT_OP, (yyvsp[(2) - (2)].expr), 0);  }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1610 "cfg.y"
    { (yyval.expr)=mk_exp(EVAL_OP, (yyvsp[(2) - (3)].expr), 0); }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1611 "cfg.y"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1612 "cfg.y"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1615 "cfg.y"
    {(yyval.intval)=EQUAL_OP; }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1616 "cfg.y"
    {(yyval.intval)=DIFF_OP; }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1619 "cfg.y"
    {(yyval.intval)=GT_OP; }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1620 "cfg.y"
    {(yyval.intval)=LT_OP; }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1621 "cfg.y"
    {(yyval.intval)=GTE_OP; }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1622 "cfg.y"
    {(yyval.intval)=LTE_OP; }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1624 "cfg.y"
    {(yyval.intval)=MATCH_OP; }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1625 "cfg.y"
    {(yyval.intval)=NOTMATCH_OP; }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1628 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1629 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1632 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1633 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1634 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1637 "cfg.y"
    {(yyval.intval)=URI_O;}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 1638 "cfg.y"
    {(yyval.intval)=FROM_URI_O;}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 1639 "cfg.y"
    {(yyval.intval)=TO_URI_O;}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 1642 "cfg.y"
    { 
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				if (spec==NULL){
					yyerror("no more pkg memory\n");
				}
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[(1) - (1)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable");
				}
				(yyval.specval) = spec;
			}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1656 "cfg.y"
    {
			(yyval.specval)=0; yyerror("invalid script variable name");
		}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1661 "cfg.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1662 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1663 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, NUMBER_O, 0, NUMBER_ST, 
											(void*)(yyvsp[(1) - (1)].intval) ); }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1665 "cfg.y"
    {
				(yyval.expr)=mk_elem(NO_OP, SCRIPTVAR_O,0,SCRIPTVAR_ST,(void*)(yyvsp[(1) - (1)].specval));
			}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1668 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1670 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1672 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 1674 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 1676 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 1680 "cfg.y"
    {(yyval.expr)= mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
									}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 1682 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 1684 "cfg.y"
    { (yyval.expr)=0; yyerror("string expected"); }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 1685 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
										"== , !=, or =~ expected");
						}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 1688 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),SCRIPTVAR_ST,(void*)(yyvsp[(3) - (3)].specval));
			}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 1691 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 1694 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 1697 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),NUMBER_ST,(void *)(yyvsp[(3) - (3)].intval));
			}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1700 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), MYSELF_ST, 0);
			}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1703 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), NULLV_ST, 0);
			}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1706 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 				}
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1708 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, MYSELF_ST, 0);
								}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1710 "cfg.y"
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1711 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
									" == , != or =~ expected");
					}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1714 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 1716 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1717 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1718 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1720 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1721 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1722 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), PROTO_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 1724 "cfg.y"
    { (yyval.expr)=0;
								yyerror("protocol expected (udp, tcp or tls)");
							}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 1727 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1728 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), AF_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1730 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 1731 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1732 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1734 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) BUF_SIZE); }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1736 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1737 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1738 "cfg.y"
    {	s_tmp.s=(yyvsp[(3) - (3)].strval);
									s_tmp.len=strlen((yyvsp[(3) - (3)].strval));
									ip_tmp=str2ip(&s_tmp);
									if (ip_tmp==0)
										ip_tmp=str2ip6(&s_tmp);
									if (ip_tmp){
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST,
												mk_net_bitlen(ip_tmp, 
														ip_tmp->len*8) );
									}else{
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST,
												(yyvsp[(3) - (3)].strval));
									}
								}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1752 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1754 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 "expected" ); }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1756 "cfg.y"
    { (yyval.expr)=0; 
						 yyerror("invalid operator, ==, != or =~ expected");}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1758 "cfg.y"
    {	s_tmp.s=(yyvsp[(3) - (3)].strval);
									s_tmp.len=strlen((yyvsp[(3) - (3)].strval));
									ip_tmp=str2ip(&s_tmp);
									if (ip_tmp==0)
										ip_tmp=str2ip6(&s_tmp);
									if (ip_tmp){
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST,
												mk_net_bitlen(ip_tmp, 
														ip_tmp->len*8) );
									}else{
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST,
												(yyvsp[(3) - (3)].strval));
									}
								}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1772 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1774 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 			"expected" ); }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1776 "cfg.y"
    { (yyval.expr)=0; 
						yyerror("invalid operator, ==, != or =~ expected");}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1778 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval), 0, MYSELF_ST, 0);
								}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1780 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1782 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1784 "cfg.y"
    {	(yyval.expr)=0; 
									yyerror(" URI, SRCIP or DSTIP expected"); }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1786 "cfg.y"
    { (yyval.expr)=0; 
							yyerror ("invalid operator, == or != expected");
						}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1791 "cfg.y"
    { (yyval.ipnet)=mk_net((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].ipaddr)); }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1792 "cfg.y"
    {	if (((yyvsp[(3) - (3)].intval)<0) || ((yyvsp[(3) - (3)].intval)>(long)(yyvsp[(1) - (3)].ipaddr)->len*8)){
								yyerror("invalid bit number in netmask");
								(yyval.ipnet)=0;
							}else{
								(yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].intval));
							/*
								$$=mk_net($1, 
										htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
							*/
							}
						}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1803 "cfg.y"
    { (yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (1)].ipaddr), (yyvsp[(1) - (1)].ipaddr)->len*8); }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1804 "cfg.y"
    { (yyval.ipnet)=0;
						 yyerror("netmask (eg:255.0.0.0 or 8) expected");
						}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1811 "cfg.y"
    {(yyval.strval)=".";}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1812 "cfg.y"
    {(yyval.strval)="-"; }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1815 "cfg.y"
    { (yyval.strval)=(yyvsp[(1) - (1)].strval); }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 1816 "cfg.y"
    { (yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[(1) - (3)].strval))+1+strlen((yyvsp[(3) - (3)].strval))+1);
						  if ((yyval.strval)==0){
							LM_CRIT("cfg. parser: memory allocation"
										" failure while parsing host\n");
						  }else{
							memcpy((yyval.strval), (yyvsp[(1) - (3)].strval), strlen((yyvsp[(1) - (3)].strval)));
							(yyval.strval)[strlen((yyvsp[(1) - (3)].strval))]=*(yyvsp[(2) - (3)].strval);
							memcpy((yyval.strval)+strlen((yyvsp[(1) - (3)].strval))+1, (yyvsp[(3) - (3)].strval), strlen((yyvsp[(3) - (3)].strval)));
							(yyval.strval)[strlen((yyvsp[(1) - (3)].strval))+1+strlen((yyvsp[(3) - (3)].strval))]=0;
						  }
						  pkg_free((yyvsp[(1) - (3)].strval)); pkg_free((yyvsp[(3) - (3)].strval));
						}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 1828 "cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[(1) - (3)].strval)); yyerror("invalid hostname (use quotes if hostname has config keywords)"); }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 1832 "cfg.y"
    { (yyval.intval) = EQ_T; }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 1833 "cfg.y"
    { (yyval.intval) = COLONEQ_T; }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 1834 "cfg.y"
    { (yyval.intval) = PLUSEQ_T; }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 1835 "cfg.y"
    { (yyval.intval) = MINUSEQ_T;}
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1836 "cfg.y"
    { (yyval.intval) = DIVEQ_T; }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 1837 "cfg.y"
    { (yyval.intval) = MULTEQ_T; }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 1838 "cfg.y"
    { (yyval.intval) = MODULOEQ_T; }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1839 "cfg.y"
    { (yyval.intval) = BANDEQ_T; }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1840 "cfg.y"
    { (yyval.intval) = BOREQ_T; }
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1841 "cfg.y"
    { (yyval.intval) = BXOREQ_T; }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1845 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, NUMBERV_O, (void*)(yyvsp[(1) - (1)].intval), 0, 0); }
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1846 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 1847 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); }
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 1848 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, SCRIPTVAR_O, (yyvsp[(1) - (1)].specval), 0, 0); }
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 1849 "cfg.y"
    { (yyval.expr)= (yyvsp[(1) - (1)].expr); }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 1850 "cfg.y"
    { (yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 1851 "cfg.y"
    { 
				(yyval.expr) = mk_elem(PLUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 1854 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MINUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr)); 
			}
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 1857 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MULT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 1860 "cfg.y"
    { 
				(yyval.expr) = mk_elem(DIV_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 1863 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MODULO_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 1866 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BAND_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 1869 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 1872 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BXOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 1875 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BLSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 1878 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BRSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 1881 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BNOT_OP, EXPR_O, (yyvsp[(2) - (2)].expr), 0, 0);
			}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 1884 "cfg.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 1887 "cfg.y"
    {	
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), (yyvsp[(2) - (3)].intval),
					SCRIPTVAR_ST,
					EXPR_ST,
					(yyvsp[(1) - (3)].specval),
					(yyvsp[(3) - (3)].expr));
		}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 1900 "cfg.y"
    {
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), EQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[(1) - (3)].specval),
					0);
		}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 1913 "cfg.y"
    {
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			/* not all can get NULL with := */
			switch((yyvsp[(1) - (3)].specval)->type) {
				case PVT_AVP:
				break;
				default:
					yyerror("invalid left operand in NULL assignment");
			}
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), COLONEQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[(1) - (3)].specval),
					0);
		}
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 1935 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 1936 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 1937 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 1938 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 1939 "cfg.y"
    { (yyval.action)=0; }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 1942 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 1943 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 1944 "cfg.y"
    { (yyval.action)=0; }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 1947 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 1948 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 1949 "cfg.y"
    { (yyval.action)=0; yyerror("bad command!)"); }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 1952 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 1953 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 1954 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 1955 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 1956 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);}
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 1957 "cfg.y"
    {(yyval.action)=0;}
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 1958 "cfg.y"
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 1961 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 NOSUBTYPE,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action),
													 0);
									}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 1969 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (5)].expr),
													 (yyvsp[(3) - (5)].action),
													 (yyvsp[(5) - (5)].action));
									}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 1979 "cfg.y"
    { mk_action2( (yyval.action), WHILE_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action));
									}
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 1987 "cfg.y"
    {
											mk_action2( (yyval.action), SWITCH_T,
														SCRIPTVAR_ST,
														ACTIONS_ST,
														(yyvsp[(3) - (7)].specval),
														(yyvsp[(6) - (7)].action));
									}
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 1996 "cfg.y"
    { (yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 1997 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 1999 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); }
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 2000 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 2004 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].intval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 2013 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].intval),
													0,
													(void*)1);
											}
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 2021 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].intval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									}
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 2029 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].intval),
													0,
													(void*)0);
							}
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 2038 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].strval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											}
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 2047 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].strval),
													0,
													(void*)1);
											}
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 2055 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].strval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									}
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 2063 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].strval),
													0,
													(void*)0);
							}
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 2074 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													(yyvsp[(3) - (3)].action),
													0);
									}
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 2080 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													0,
													0);
									}
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 2088 "cfg.y"
    {
										elems[1].type = STRING_ST;
										elems[1].u.data = (yyvsp[(1) - (1)].strval);
										(yyval.intval)=1;
										}
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 2093 "cfg.y"
    {
										if ((yyvsp[(1) - (3)].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[(1) - (3)].intval)+1].type = STRING_ST;
										elems[(yyvsp[(1) - (3)].intval)+1].u.data = (yyvsp[(3) - (3)].strval);
										(yyval.intval)=(yyvsp[(1) - (3)].intval)+1;
										}
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 2102 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										}
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 2106 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										}
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 2113 "cfg.y"
    { mk_action2( (yyval.action), FORWARD_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										}
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 2119 "cfg.y"
    {
										mk_action2( (yyval.action), FORWARD_T,
											0,
											0,
											0,
											0);
										}
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 2126 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 2127 "cfg.y"
    { (yyval.action)=0; yyerror("bad forward "
										"argument"); }
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 2130 "cfg.y"
    { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										}
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 2136 "cfg.y"
    { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											STRING_ST,
											(yyvsp[(3) - (6)].strval),
											(yyvsp[(5) - (6)].strval));
										}
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 2142 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 2143 "cfg.y"
    { (yyval.action)=0; yyerror("bad send"
													"argument"); }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 2145 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 2146 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 2147 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 2148 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 2149 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].intval),
																0);
												}
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 2155 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																SCRIPTVAR_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].specval),
																0);
												}
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 2161 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												}
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 2167 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												}
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 2173 "cfg.y"
    {mk_action2( (yyval.action), LOG_T, NUMBER_ST, 
													STRING_ST,(void*)4,(yyvsp[(3) - (4)].strval));
									}
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 2176 "cfg.y"
    {mk_action2( (yyval.action), LOG_T,
																NUMBER_ST, 
																STRING_ST,
																(void*)(yyvsp[(3) - (6)].intval),
																(yyvsp[(5) - (6)].strval));
												}
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 2182 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 2183 "cfg.y"
    { (yyval.action)=0; yyerror("bad log"
									"argument"); }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 2185 "cfg.y"
    {mk_action2((yyval.action), SET_DEBUG_T, NUMBER_ST,
									0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 2187 "cfg.y"
    {mk_action2( (yyval.action), SET_DEBUG_T, 0, 0, 0, 0 ); }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 2188 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2189 "cfg.y"
    {mk_action2((yyval.action), SETFLAG_T, NUMBER_ST, 0,
													(void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2191 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2192 "cfg.y"
    {mk_action2( (yyval.action), RESETFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2194 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2195 "cfg.y"
    {mk_action2( (yyval.action), ISFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2197 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2198 "cfg.y"
    {mk_action2( (yyval.action), SETSFLAG_T, NUMBER_ST,
										0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2200 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2201 "cfg.y"
    {mk_action2( (yyval.action), RESETSFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2203 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2204 "cfg.y"
    {mk_action2( (yyval.action), ISSFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2206 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2207 "cfg.y"
    {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2211 "cfg.y"
    {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2214 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2215 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); }
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2219 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2223 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2224 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2228 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); }
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2232 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2233 "cfg.y"
    {mk_action2( (yyval.action), ERROR_T,
																STRING_ST, 
																STRING_ST,
																(yyvsp[(3) - (6)].strval),
																(yyvsp[(5) - (6)].strval));
												  }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2239 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2240 "cfg.y"
    { (yyval.action)=0; yyerror("bad error"
														"argument"); }
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2242 "cfg.y"
    { 
						i_tmp = get_script_route_idx( (yyvsp[(3) - (4)].strval), rlist, RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						mk_action2( (yyval.action), ROUTE_T, NUMBER_ST,
							0, (void*)(long)i_tmp, 0);
					}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2248 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2249 "cfg.y"
    { (yyval.action)=0; yyerror("bad route"
						"argument"); }
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2251 "cfg.y"
    { mk_action2( (yyval.action), SET_HOST_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2253 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2254 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2257 "cfg.y"
    { mk_action2( (yyval.action), PREFIX_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2259 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2260 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2262 "cfg.y"
    { mk_action2( (yyval.action), STRIP_TAIL_T, 
									NUMBER_ST, 0, (void *) (yyvsp[(3) - (4)].intval), 0); }
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2264 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2265 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); }
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2268 "cfg.y"
    { mk_action2( (yyval.action), STRIP_T, NUMBER_ST,
														0, (void *) (yyvsp[(3) - (4)].intval), 0); }
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2270 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2271 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2273 "cfg.y"
    { 
				{   qvalue_t q;
				if (str2q(&q, (yyvsp[(5) - (6)].strval), strlen((yyvsp[(5) - (6)].strval))) < 0) {
					yyerror("bad argument, q value expected");
				}
				mk_action2( (yyval.action), APPEND_BRANCH_T, STR_ST, NUMBER_ST, (yyvsp[(3) - (6)].strval),
						(void *)(long)q); } 
		}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2281 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, (yyvsp[(3) - (4)].strval), (void *)Q_UNSPECIFIED) ; }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2283 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED) ; }
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2285 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED ) ; }
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2287 "cfg.y"
    {
						mk_action1((yyval.action), REMOVE_BRANCH_T, NUMBER_ST, (void*)(yyvsp[(3) - (4)].intval));}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2289 "cfg.y"
    {
						mk_action1( (yyval.action), REMOVE_BRANCH_T, SCRIPTVAR_ST, (yyvsp[(3) - (4)].specval));}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2292 "cfg.y"
    {
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[(3) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable in first parameter");
				}
				if(!pv_is_w(spec))
					yyerror("read-only script variable in first parameter");

				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, spec, pvmodel) ;
			}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2315 "cfg.y"
    {
				if(!pv_is_w((yyvsp[(3) - (6)].specval)))
					yyerror("read-only script variable in first parameter");
				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, (yyvsp[(3) - (6)].specval), pvmodel) ;
			}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2330 "cfg.y"
    { mk_action2( (yyval.action), SET_HOSTPORT_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2332 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2333 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
												" string expected"); }
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2335 "cfg.y"
    { mk_action2( (yyval.action), SET_PORT_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2337 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2338 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2340 "cfg.y"
    { mk_action2( (yyval.action), SET_USER_T,
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2342 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2343 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2345 "cfg.y"
    { mk_action2( (yyval.action), SET_USERPASS_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2347 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2348 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2350 "cfg.y"
    { mk_action2( (yyval.action), SET_URI_T, STR_ST, 
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2352 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2353 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); }
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2355 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); }
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 2356 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 2357 "cfg.y"
    { mk_action2( (yyval.action), SET_DSTURI_T,
													STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2359 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2360 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); }
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2362 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T,
															0,0,0,0); }
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2364 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T, 0,0,0,0); }
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 2365 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); }
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2366 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); }
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2367 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,
															0, 0, 0, 0); }
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 2369 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,0, 0, 0, 0); }
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 2370 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 2372 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); }
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 2374 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,NUMBER_ST, 0,
										(void*)(yyvsp[(3) - (4)].intval), 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
												}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 2382 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0); 
					#else
						yyerror("tcp support not compiled in");
					#endif
										}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2389 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
										}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2396 "cfg.y"
    {(yyval.action)=0; 
					yyerror("bad argument, number expected");
					}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 2399 "cfg.y"
    {
								mk_action2( (yyval.action), SET_ADV_ADDR_T, STR_ST,
											0, (yyvsp[(3) - (4)].strval), 0);
								}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 2403 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 2405 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 2406 "cfg.y"
    {
								(yyval.action)=0;
								tmp=int2str((yyvsp[(3) - (4)].intval), &i_tmp);
								if ((str_tmp=pkg_malloc(sizeof(str)))==0){
										LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									if ((str_tmp->s=pkg_malloc(i_tmp))==0){
										LM_CRIT("cfg. parser: out of memory.\n");
									}else{
										memcpy(str_tmp->s, tmp, i_tmp);
										str_tmp->len=i_tmp;
										mk_action2( (yyval.action), SET_ADV_PORT_T, STR_ST,
													0, str_tmp, 0);
									}
								}
								            }
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 2422 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
								"string expected"); }
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 2424 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 2425 "cfg.y"
    {
								mk_action2( (yyval.action), FORCE_SEND_SOCKET_T,
									SOCKID_ST, 0, (yyvsp[(3) - (4)].sockid), 0);
								}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 2429 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
								" [proto:]host[:port] expected");
								}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 2432 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 2433 "cfg.y"
    {
								mk_action2( (yyval.action), SERIALIZE_BRANCHES_T,
									NUMBER_ST, 0, (void*)(long)(yyvsp[(3) - (4)].intval), 0);
								}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 2437 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" number expected");
								}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 2440 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 2441 "cfg.y"
    {
								mk_action2( (yyval.action), NEXT_BRANCHES_T, 0, 0, 0, 0);
								}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 2444 "cfg.y"
    {(yyval.action)=0; yyerror("no argument is"
								" expected");
								}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 2447 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 2448 "cfg.y"
    {
								mk_action2( (yyval.action), USE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 2452 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 2455 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 2456 "cfg.y"
    {
								mk_action2( (yyval.action), UNUSE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 2460 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 2463 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 2464 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_STORE_T,
													STR_ST,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].strval));
							}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 2474 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].strval); 
								elems[3].type = NUMBER_ST; 
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_STORE_T, 4, elems, line); 
							}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 2486 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].strval); 
								elems[3].type = SCRIPTVAR_ST; 
								elems[3].u.data = (yyvsp[(9) - (10)].specval);
								(yyval.action) = mk_action(CACHE_STORE_T, 4, elems, line); 
							}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 2498 "cfg.y"
    { 
									mk_action2( (yyval.action), CACHE_REMOVE_T,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (6)].strval),
													(yyvsp[(5) - (6)].strval));
							}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 2505 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_FETCH_T,
													STR_ST,
													STR_ST,
													SCRIPTVAR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].specval));
							}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 2514 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = NUMBER_ST; 
								elems[2].u.number = (yyvsp[(7) - (10)].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_ADD_T, 4, elems, line); 
							}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 2525 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = SCRIPTVAR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_ADD_T, 4, elems, line); 
							}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 2536 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = NUMBER_ST; 
								elems[2].u.number = (yyvsp[(7) - (10)].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_SUB_T, 4, elems, line); 
							}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 2547 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = SCRIPTVAR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_SUB_T, 4, elems, line); 
							}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 2558 "cfg.y"
    {
						 			cmd_tmp=(void*)find_cmd_export_t((yyvsp[(1) - (3)].strval), 0, rt);
									if (cmd_tmp==0){
										if (find_cmd_export_t((yyvsp[(1) - (3)].strval), 0, 0)) {
											yyerror("Command cannot be "
												"used in the block\n");
										} else {
											yyerrorf("unknown command <%s>, "
												"missing loadmodule?", (yyvsp[(1) - (3)].strval));
										}
										(yyval.action)=0;
									}else{
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										(yyval.action) = mk_action(MODULE_T, 1, elems, line);
									}
								}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 2575 "cfg.y"
    {
									cmd_tmp=(void*)find_cmd_export_t((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].intval), rt);
									if (cmd_tmp==0){
										if (find_cmd_export_t((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].intval), 0)) {
											yyerror("Command cannot be "
												"used in the block\n");
										} else {
											yyerrorf("unknown command <%s>, "
												"missing loadmodule?", (yyvsp[(1) - (4)].strval));
										}
										(yyval.action)=0;
									}else{
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										(yyval.action) = mk_action(MODULE_T, (yyvsp[(3) - (4)].intval)+1, elems, line);
									}
								}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 2592 "cfg.y"
    { (yyval.action)=0; yyerrorf("bad arguments for "
												"command <%s>", (yyvsp[(1) - (4)].strval)); }
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 2594 "cfg.y"
    { (yyval.action)=0; yyerrorf("bare word <%s> found, command calls need '()'", (yyvsp[(1) - (2)].strval)); }
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 2596 "cfg.y"
    {
				mk_action1((yyval.action), XDBG_T, STR_ST, (yyvsp[(3) - (4)].strval));	}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 2598 "cfg.y"
    {
				mk_action1((yyval.action), XLOG_T, STR_ST, (yyvsp[(3) - (4)].strval)); }
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 2600 "cfg.y"
    {
				mk_action2((yyval.action), XLOG_T, STR_ST, STR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].strval)); }
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 2602 "cfg.y"
    {
				mk_action1((yyval.action), RAISE_EVENT_T, STR_ST, (yyvsp[(3) - (4)].strval)); }
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 2604 "cfg.y"
    {
				mk_action2((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].specval)); }
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 2606 "cfg.y"
    {
				mk_action3((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, SCRIPTVAR_ST, (yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].specval), (yyvsp[(7) - (8)].specval)); }
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 2608 "cfg.y"
    {
				mk_action2((yyval.action), SUBSCRIBE_EVENT_T, STR_ST, STR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].strval)); }
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 2610 "cfg.y"
    {
				mk_action3((yyval.action), SUBSCRIBE_EVENT_T, STR_ST, STR_ST, NUMBER_ST, (yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), (void*)(long)(yyvsp[(7) - (8)].intval)); }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 2612 "cfg.y"
    {
				elems[0].type = STR_ST; 
				elems[0].u.data = (yyvsp[(3) - (14)].strval); 
				elems[1].type = STR_ST; 
				elems[1].u.data = (yyvsp[(5) - (14)].strval); 
				elems[2].type = STR_ST; 
				elems[2].u.data = (yyvsp[(7) - (14)].strval); 
				elems[3].type = STR_ST; 
				elems[3].u.data = (yyvsp[(9) - (14)].strval);
				elems[4].type = STR_ST; 
				elems[4].u.data = (yyvsp[(11) - (14)].strval);
				elems[5].type = SCRIPTVAR_ST; 
				elems[5].u.data = (yyvsp[(13) - (14)].specval);
				(yyval.action) = mk_action(CONSTRUCT_URI_T,6,elems,line); }
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 2626 "cfg.y"
    {
				elems[0].type = SCRIPTVAR_ST;
				elems[0].u.data = (yyvsp[(3) - (6)].specval);
				elems[1].type = SCRIPTVAR_ST;
				elems[1].u.data = (yyvsp[(5) - (6)].specval); 
				(yyval.action) = mk_action(GET_TIMESTAMP_T,2,elems,line); }
    break;



/* Line 1806 of yacc.c  */
#line 8969 "cfg.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 2641 "cfg.y"


extern int column;
extern int startcolumn;
extern char *finame;

#define get_cfg_file_name \
	((finame) ? finame : cfg_file ? cfg_file : "default")

static inline void warn(char* s)
{
	LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
			get_cfg_file_name, line, startcolumn, column, s);
}

static void yyerror(char* s)
{
	LM_CRIT("parse error in config file %s, line %d, column %d-%d: %s\n",
			get_cfg_file_name, line, startcolumn, column, s);
	cfg_errors++;
}

#define ERROR_MAXLEN 1024
static void yyerrorf(char *fmt, ...)
{
	char *tmp = pkg_malloc(ERROR_MAXLEN);
	va_list ap;
	va_start(ap, fmt);

	vsnprintf(tmp, ERROR_MAXLEN, fmt, ap);
	yyerror(tmp);

	pkg_free(tmp);
	va_end(ap);
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0){
		LM_CRIT("cfg. parser: out of memory.\n");
	}else{
		l->name=host;
		l->port=port;
		l->proto=proto;
		l->adv_name=NULL;
		l->adv_port=0;
		l->next=0;
	}
	return l;
}

static struct socket_id* set_listen_id_adv(struct socket_id* sock,
											char *adv_name,
											int adv_port)
{
	sock->adv_name=adv_name;
	sock->adv_port=adv_port;
	return sock;
}

