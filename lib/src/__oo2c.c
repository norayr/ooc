/*      $Id: __oo2c.c,v 1.8 2002/06/22 21:47:44 mva Exp $        */
/*  Run-time system for C back-ends of OOC2
    Copyright (C) 2001, 2002  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include "__oo2c.h"
#include <stdio.h>

/* --- stack for copies of array value parameters (see __dynvar.h): */
void* _ooc_top_vs;
void* _ooc_end_vs;

/* --- string compare */
OOC_INT32 _cmp8(const OOC_CHAR8* l, const OOC_CHAR8* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}

OOC_INT32 _cmp16(const OOC_CHAR8* l, const OOC_CHAR8* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}

/* --- functions to handle exceptions and failed run-time checks: */
#define PREFIX "## "
#define EXIT_RUNTIME_ERROR exit(127)

void _assertion_failed(OOC_INT32 code, OOC_CHARPOS pos) {
  (void)fprintf(stderr, PREFIX "Assertion failed, code: " 
		OOC_INT32_FORMAT "\n", code);
  exit(code);
}

void _index_out_of_range(OOC_LEN index, OOC_LEN length) {
  (void)fprintf(stderr, PREFIX "Array index out of range: " 
		OOC_LEN_FORMAT " not in 0 <= x < "
		OOC_LEN_FORMAT "\n", index, length);
  EXIT_RUNTIME_ERROR;
}


