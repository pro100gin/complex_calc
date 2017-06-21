#ifndef OPERATIONS_H
#define OPERATIONS_H

#define _SVID_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>




typedef struct tagComplex{
	double re;
	double im;
} m_complex;

m_complex* add(m_complex*, m_complex*);
m_complex* sub(m_complex*, m_complex*);
m_complex* mult(m_complex*, m_complex*);
m_complex* divi(m_complex*, m_complex*);

#endif
