#include "./Var7b.d"
#include "__oo2c.h"

static OOC_INT16 Var7b__Len(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0=-1;
l1_loop:
  i0 = i0+1;
  Var7b__i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 187)));
  i1 = i1==(OOC_CHAR8)'\000';
  if (!i1) goto l1_loop;
l5:
  return i0;
  ;
}

void Var7b__Test() {
  register OOC_INT32 i0;

  i0 = Var7b__Len("", 1);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var7b__Len("abc", 4);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void Var7b_init(void) {

  return;
  ;
}

/* --- */
