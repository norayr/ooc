(*	$Id: Out.Mod,v 1.1 2001/12/27 07:07:26 sgreenhill Exp $	*)
MODULE Out [FOREIGN "C"; LINK FILE "Out.c" END];
<* Warnings := FALSE *>

PROCEDURE Open*;
PROCEDURE Char* (ch: CHAR);
PROCEDURE String* (s: ARRAY OF CHAR);
PROCEDURE Int* (i, n: LONGINT);
(*PROCEDURE Real* (x: REAL; n: INTEGER);*)
(*PROCEDURE LongReal* (x: LONGREAL; n: INTEGER);*)
PROCEDURE Ln*;

END Out.
