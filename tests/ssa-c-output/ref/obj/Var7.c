#include "./Var7.d"
#include "__oo2c.h"

static OOC_INT16 Var7__Len(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 *str;
  OOC_PUSH_VPAR_STACK

  i0 = str_0d;
  i0 = i0*1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,i0)
  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,i0)
  i0=-1;
l1_loop:
  i0 = i0+1;
  i1 = i0*1;
  i1 = (OOC_INT32)str+i1;
  i1 = *(OOC_UINT8*)i1;
  i1 = i1=='\000';
  if (i1) goto l4;
  
  goto l1_loop;
l4:
  OOC_POP_VPAR_STACK
  return i0;
}

void Var7__Test() {
  register OOC_INT32 i0;

  i0 = Var7__Len((void*)"", 1);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var7__Len((void*)"abc", 4);
  Out__Int(i0, 0);
  Out__Ln();
}

void Var7_init(void) {

}

/* --- */
