(*	$Id: Out.Mod,v 1.4 2002/05/12 14:31:55 sgreenhill Exp $	*)
MODULE Out [FOREIGN "C"; LINK FILE "Out.c" END];
<* Warnings := FALSE *>

PROCEDURE Open*;
PROCEDURE Char* (ch: CHAR);
PROCEDURE String* (s: ARRAY OF CHAR);
PROCEDURE Int* (i, n: LONGINT);
PROCEDURE Bool* (b : BOOLEAN);
PROCEDURE Set* (s : SET);
PROCEDURE Real* (x: REAL; n: LONGINT);
(*PROCEDURE LongReal* (x: LONGREAL; n: INTEGER);*)
PROCEDURE Ln*;

END Out.
