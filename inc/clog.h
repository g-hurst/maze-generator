#ifndef stdio_h
#  include <stdio.h>
#endif
#ifndef windows_h
#include <windows.h>
#endif
#ifndef stdbool_h
#  include <stdbool.h>
#endif

#ifndef __CLOG_H__
#  define __CLOG_H__
#  define ANSI_RED      "\x1b[31m" 
#  define ANSI_GREEN	"\x1b[32m"
#  define ANSI_YELLOW   "\x1b[33m"
#  define ANSI_BLUE		"\x1b[34m"
#  define ANSI_MAGENTA	"\x1b[35m"
#  define ANSI_CYAN		"\x1b[36m"
#  define ANSI_RESET	"\x1b[0m"

#  ifndef NDEBUG
#    define log_msg(msg) 		fprintf(stdout, "%s\n",       	      (msg))
#    define log_int(n)			fprintf(stdout, "%s == %d\n",         (#n),    	    (n))
#    define log_str(s)			fprintf(stdout, "%s == \"%s\"\n",     (#s),    	    (s))
#    define log_float(n)		fprintf(stdout, "%s == \'%.016f\'\n", (#n),         (n))
#    define log_char(ch)		fprintf(stdout, "%s == \'%c\'\n",     (#ch),        (ch))
#    define log_bool(condition) fprintf(stdout, "%s == %s\n", 		  (#condition), (condition) ? "true" : "false")
#    define log_addr(addr)		fprintf(stdout, "%s == %p\n",         (#addr), 	    (void*)(addr))

#  	 define logf_(...)       	fprintf(stdout, __VA_ARGS__)
// #    define __mu_file_out__ 	isatty(STDOUT_FILENO)  				   
// #    define __mu_color(color, ...)         \
// 		do{                               \
// 			if (__mu_file_out__) {        \
// 				logf_(color __VA_ARGS__); \
// 				logf_(ANSI_RESET);	      \
// 			}                             \
// 			else{                         \
// 				logf_(__VA_ARGS__);       \
// 			}                             \
// 		}while(false)


// #    define logf_red(...)     __mu_color(ANSI_RED,     __VA_ARGS__)
// #  	 define logf_green(...)   __mu_color(ANSI_GREEN,   __VA_ARGS__)
// #  	 define logf_yellow(...)  __mu_color(ANSI_YELLOW,  __VA_ARGS__)
// #  	 define logf_blue(...)    __mu_color(ANSI_BLUE,    __VA_ARGS__)
// #  	 define logf_magenta(...) __mu_color(ANSI_MAGENTA, __VA_ARGS__)
// #  	 define logf_cyan(...)    __mu_color(ANSI_CYAN,    __VA_ARGS__)

#  else
#    define log_msg(msg)
#    define log_int(n)
#    define log_float(n)
#    define log_str(s)
#    define log_char(ch)
#    define log_bool(condition)
#    define log_addr(addr)

#    define logf_(format,        ...)
// #    define logf_red(format,     ...)
// #    define logf_green(format,   ...)
// #    define logf_yellow(format,  ...)
// #    define logf_blue(format,    ...)
// #    define logf_magenta(format, ...)
// #    define logf_cyan(format,    ...)
 #  endif
#endif 
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
