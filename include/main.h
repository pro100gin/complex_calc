#ifndef MAIN_H
#define MAIN_H
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
char** file_filter(int*);

#endif
