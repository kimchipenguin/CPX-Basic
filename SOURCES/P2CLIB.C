/* Run-time library for use with "p2c", the Pascal to C translator */

/* "p2c"  Copyright (C) 1989, 1990, 1991 Free Software Foundation.
 * By Dave Gillespie, daveg@csvax.cs.caltech.edu.  Version --VERSION--.
 * This file may be copied, modified, etc. in any way.  It is not restricted
 */

/*
** file changed by J.S. 1993
** removed unneeded functions 
*/
#ifndef NO_TIME








void PASCAL_MAIN(int argc, char **argv)
{
    P_argc = argc;
    P_argv = argv;
    __top_jb = NULL;


/* HP and Turbo Pascal string functions: */
/* Trim blanks at left end of string. */
char *strltrim(register char *s)
{
    while (Isspace(*s++)) ;
    return s - 1;
}

void _Escape(int code)
{
    P_escapecode = code;
    if (__top_jb) {
	__p2c_jmp_buf *jb = __top_jb;
	__top_jb = jb->next;
	longjmp(jb->jbuf, 1);
    }
    if (code == 0) exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}

{
    P_ioresult = code;
    _Escape(-10);
}

void *BASalloc(long num)
{
	void *temp=malloc(num);
	char *ptr;
	if(temp==NULL) _Escape(-2);
	ptr=(char*)temp;
	while(num-->0) *ptr++=0;
	return temp;
}

void *BASrealloc(void *buf,long num)
{
	void *temp;
	if((temp=realloc(buf,num))==NULL) _Escape(-2);
	return temp;
}

/* End. */