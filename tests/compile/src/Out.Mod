(*	$Id: Out.Mod,v 1.3 2002/02/08 14:13:48 sgreenhill Exp $	*)
MODULE Out [FOREIGN "C"; LINK FILE "Out.c" END];
<* Warnings := FALSE *>

PROCEDURE Open*;
PROCEDURE Char* (ch: CHAR);
PROCEDURE String* (s: ARRAY OF CHAR);
PROCEDURE Int* (i, n: LONGINT);
PROCEDURE Bool* (b : BOOLEAN);
PROCEDURE Set* (s : SET);
(*PROCEDURE Real* (x: REAL; n: INTEGER);*)
(*PROCEDURE LongReal* (x: LONGREAL; n: INTEGER);*)
PROCEDURE Ln*;

END Out.
