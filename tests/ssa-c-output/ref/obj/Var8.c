#include "./Var8.d"
#include "__oo2c.h"

static void Var8__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = str_0d;
  i0 = i0-1;
  i1 = 0<=i0;
  if (i1) goto l2;
  goto l6;
l2:
  i2=0;
l3_loop:
  i3 = (OOC_INT32)str+i2;
  *(OOC_UINT8*)i3 = '\000';
  i2 = i2+1;
  i3 = i2<=i0;
  if (!i3) goto l5;
  
  goto l3_loop;
l5:
l6:
  return;
}

void Var8__Test() {
  OOC_CHAR8 Var8__Test_s4[4];

  Var8__Zero((void*)(OOC_INT32)Var8__Test_s4, 4);
  return;
}

void Var8_init(void) {
}