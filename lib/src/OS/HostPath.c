/*
<* IF TARGET_OS="Win32" THEN *>

(* "Normalisation" of windows file paths:
 * - backslash is converted to forward slash
 * - drive identifier "C:" is converted to "/C$"
 * - drive-relative paths (eg. c:test) are converted to absolute paths
 *
 * The normalised path can be used within a URI, and obeys the unix convention
 * that a leading "/" indicates an absolute path. 
 * 
 * "Denormalisation" of windows paths:
 * - backslashes cause problems in many contexts. Windows usually treats
 *   forward and back slashes equivalently, so we retain only forward slashes.
 * - (HACK) OOC treats paths like "c:/.." as relative, erroneously applying 
 *   transformations on repository paths. For now, we treat all absolute paths
 *   as relative to the CURRENT drive.
 *)

PROCEDURE NormalisePath(VAR path : ARRAY OF CHAR; VAR res : Msg.Msg);
VAR
  drive : CHAR;
  pos, id : INTEGER;
  cwd : ARRAY 1024 * 4 OF CHAR;

  PROCEDURE EndsWithSeparator(VAR string : ARRAY OF CHAR) : BOOLEAN;
  VAR 
    lenString : INTEGER; ch : CHAR;
  BEGIN
    lenString := Strings.Length(string);
    IF lenString = 0 THEN RETURN FALSE END;
    ch := string[lenString-1];
    RETURN (ch = '\') OR (ch = '/');
  END EndsWithSeparator;

BEGIN
  res := ProcessParameters.done;
  IF CharClass.IsAlpha(path[0]) & (path[1] = ':') THEN
    (* leading drive identifier *)
    IF (path[2] # '\') & (path[2] # '/') THEN
      (* drive identifier with relative path. Use working directory on that
         drive.  *)
      drive := path[0];
      IF (drive >= 'A') & (drive <= 'Z') THEN
        id := ORD(drive) - ORD('A') + 1;
      ELSE
        id := ORD(drive) - ORD('a') + 1;
      END;
      ProcessParameters.getdcwd (id, cwd, res);
      IF (res # ProcessParameters.done) THEN RETURN END;
      IF ~EndsWithSeparator(cwd) THEN
        Strings.Append("/", cwd)
      END;
      Strings.Delete(path, 0, 2);
      Strings.Insert(cwd, 0, path);
    END;
    path[1] := '$';
    Strings.Insert("/", 0, path);
  END;
(* Replace '\' with '/' *)
  pos := 0;
  WHILE path[pos] # 0X DO
    IF path[pos] = '\' THEN
      path[pos] := '/';
    END;
    INC(pos)
  END;
END NormalisePath;

PROCEDURE DenormalisePath(VAR path : ARRAY OF CHAR);
VAR pos : INTEGER;
BEGIN
  IF (path[0] = '/') & CharClass.IsAlpha(path[1]) & (path[2] = '$') THEN
    path[2] := ':';
    (* Strings.Delete(path, 0, 1); *)
    (* HACK: OOC treats paths like "c:/.." as relative, erroneously applying 
       transformations on repository paths. For now, we treat all absolute
       paths as relative to the CURRENT drive. *)
    Strings.Delete(path, 0, 3);
  END;
END DenormalisePath;

<* ELSE *>

PROCEDURE NormalisePath(VAR path : ARRAY OF CHAR; VAR res : Msg.Msg);
BEGIN
  res := NIL;
END NormalisePath;

PROCEDURE DenormalisePath(VAR path : ARRAY OF CHAR);
BEGIN
END DenormalisePath;

<* END *>
*/

#ifdef WIN32
#include <io.h>
#include <direct.h>
#include <ctype.h>
#else
#include <unistd.h>
#endif
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <__oo2c.h>
#include <__config.h>
#include <OS/HostPath.d>


#ifdef WIN32
static int endsWithSeparator(char * path) {
  int len;

  len = strlen(path);
  return (path[len] == '/') || (path[len] == '\\');
}

void OS_HostPath__Normalize(OOC_CHAR8 path[], OOC_LEN path_0d, Msg__Msg *res) {
  char newpath [4096]; 
  int drive, pos;
  *res = NULL;
  if (isalpha(path[0]) && (path[1] == ':')) {
    /* leading drive identifier */
    if ((path[2] != '\\') && (path[2] != '/')) {
      /* drive identifier with relative path. */
      drive = tolower(path[0]) - 'a' + 1;
      if (_getdcwd(drive, newpath, sizeof(newpath))) {
        if (!endsWithSeparator(newpath)) {
          strcat(newpath, "/");
        }
        strcat(newpath, path+2);
        strcpy(path, newpath);
      } else {
	IO_StdChannels__IOError(NULL);
      }
    }
    path[1] = '$';
    memmove(path+1, path, strlen(path)+1);
    path[0] = '/';
  }
  pos = 0;
  while (path[pos]) {
    if (path[pos] == '\\') {
      path[pos] = '/';
    }
    ++pos;
  }
}

void OS_HostPath__Denormalize(OOC_CHAR8 path[], OOC_LEN path_0d, Msg__Msg *res) {
  *res = NULL;
  if ( (path[0] == '/') && isalpha(path[1]) && (path[2] == '$')) {
    path[2] = ':';
    memmove(path, path+3, strlen(path));
  }
}

#else
Object__String OS_HostPath__Normalize(Object__String path) {
  return path;
}

Object__String OS_HostPath__Denormalize(Object__String path) {
  return path;
}
#endif

void OOC_OS_HostPath_init(void) {
}
