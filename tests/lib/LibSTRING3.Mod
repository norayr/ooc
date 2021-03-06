MODULE LibSTRING3;

IMPORT
  Out := Out0, String := Object;

(* This module checks that the predefined type STRING can be used as an
   alias for Object.String.  *)

PROCEDURE Write (s: STRING);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO s.length-1 DO
      Out.Char(" "); Out.Int(ORD(s.CharAt(i)), 0);
    END;
    Out.Ln;
  END Write;

PROCEDURE Test*;
  VAR
    s, s2: STRING;  (* STRING in declaration: resolved in CreateNamespace *)
  BEGIN
    s := String.NewUTF16("abc");
    Write (s);

    (* assignment of string constant to STRING variable *)
    s := 100X+101X+102X;
    Write (s);
    Write (100X+101X+102X);

    (* assignment of character constant *)
    Write(200X);
  END Test;
  
END LibSTRING3.
