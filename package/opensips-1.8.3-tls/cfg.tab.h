/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 302 "cfg.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


