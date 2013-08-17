/*
 * Utility functions needed for (some) EABI conformant tool chains.
 *
 * (C) Copyright 2009 Wolfgang Denk <wd@denx.de>
 *
 * This program is Free Software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 */

#include <common.h>

int raise (int signum)
{
	//printf("raise: Signal # %d caught\n", signum);
	printf("\n");
        printf("\n");
	printf("########################################################\n");
	printf("#   Modified by cheng du guo qian #\n");
	printf("########################################################\n");
	return 0;
}

/* Dummy function to avoid linker complaints */
void __aeabi_unwind_cpp_pr0(void)
{
};
