#include <Const6.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Const6__P(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = b;
l1_loop:
  if (!i0) goto l1_loop;
  Out0__String("bar", 4);
  return;
  ;
}

void Const6__Test(void) {

  Const6__P(1u);
  Out0__Ln();
  return;
  ;
}

void OOC_Const6_init(void) {

  return;
  ;
}

/* --- */
