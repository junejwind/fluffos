/*
 * lint.h
 *
 * This file is now exclusively for prototypes for system functions where
 * we haven't found the right header yet ...
 *
 * The goal is to have as little as possible in this file
 */

#ifndef LINT_H_
#define LINT_H_

#include "std.h"

#if defined(_SEQUENT_) || defined(SVR4)
#  include <malloc.h>
#endif

/*******************************************************
 *  Declarations and/or prototypes for lib functions.  *
 *******************************************************/

#ifdef USE_POSIX_SIGNALS
   int port_sigblock();
   int port_sigmask();

#  ifndef _M_UNIX
     void (*port_signal()) ();
#  endif

   int port_sigsetmask();
#endif

#ifdef NeXT
   int _setjmp();
   void _longjmp();
#endif

#if defined(sun) && !defined(SunOS_5) && defined(__STDC__)
#  ifdef BUFSIZ
     int fprintf(FILE *, char *,...);
     int fputs(char *, FILE *);
     int fputc(char, FILE *);
     int fwrite(char *, int, int, FILE *);
     int fread(char *, int, int, FILE *);
#  endif
   int printf(char *,...);
   int sscanf(char *, char *,...);
   void perror(char *);
   int mkdir PROT((const char *, unsigned short));
   int system PROT((char *));
   int atoi PROT((const char *));
   void abort PROT(());
   void qsort PROT((char *, int, int, int (*) ()));
   int setsockopt PROT((int, int, int, char *, int));
   int fseek PROT_STDIO((FILE *, long, int));
   int wait PROT((int *));
   unsigned int alarm PROT((unsigned int));
   int ioctl PROT((int,...));
   extern int rename PROT((char *, char *));
   int readlink PROT((char *, char *, int));
   int symlink PROT((char *, char *));
   extern int fchmod PROT((int, int));
#endif

#if (defined(SVR4) && !defined(sgi)) || defined(__386BSD__)
   void exit PROT((int));
#endif

#if !defined(MSDOS) && !defined(SunOS_5) && !defined(NeXT)
#  if !defined(_AIX) && !defined(_SEQUENT_) && !defined(_YACC_) && \
	!defined(linux) && !defined(sun) && !defined(sgi) && !defined(LATTICE)
     void *malloc PROT((unsigned));
     void *realloc PROT((void *, unsigned));
     void free PROT((void *));
#  endif
#  ifndef sgi
#    ifndef LATTICE
       int fclose PROT_STDIO((FILE *));
#    endif
     int pclose PROT_STDIO((FILE *));
#  endif

#  if !defined(linux) && !defined(LATTICE)
     int gethostname PROT((char *, int));
#  endif
#  if !defined(LATTICE) && !defined(sgi)
     void abort PROT(());
     int fflush PROT_STDIO((FILE *));
     int fclose PROT_STDIO((FILE *));
#  endif

   int pipe PROT((int *));
   int dup2 PROT((int, int));

#  ifndef LATTICE
     int close PROT((int));
#  endif
#  ifndef sgi
     int _filbuf();
#  endif

#  if defined(__386BSD__) || defined(linux) || defined(__bsdi__)
     char *crypt PROT((const char *, const char *));
#  else
     char *crypt PROT((char *, char *));
#  endif
#  ifdef sun
     char *_crypt PROT((char *, char *));
#  endif

#  ifdef DRAND48
#    ifndef sgi
       double drand48 PROT((void));
       void srand48 PROT((long));
#    endif
#  endif
#  ifdef RANDOM
     long random PROT((void));
#  endif

/* Beek - Ok, who *does* need this??? */
#  if !defined(sgi) && !defined(NeXT) && !defined(hpux) && !defined(sun) && \
   !defined(_AIX) && !defined(LATTICE) && !defined(OS2) && !defined(__bsdi__)\
   && !defined(linux)
    int getpeername PROT((int, struct sockaddr *, int *));
    int shutdown PROT((int, int));
#  endif
#endif

#endif
