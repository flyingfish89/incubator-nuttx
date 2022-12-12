/****************************************************************************
 * libs/libc/math/lib_scalbnf.c
<<<<<<< HEAD
 * get a float number of x*2^n
 *
 * This file is copy from musl libc
 * musl is an implementation of the C standard library built on top of the
 * Linux system call API, including interfaces defined in the base language
 * standard, POSIX, and widely agreed-upon extensions.
 * musl is lightweight, fast, simple, free, and strives to be correct in
 * the sense of standards-conformance and safety.
=======
 * get a double number of x*2^n
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
>>>>>>> 2fb834ef17 (1)
 *
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <math.h>
#include <stdint.h>

<<<<<<< HEAD
/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

#define FLT_MIN (0x1p-126f)

=======
#define FLT_MIN 0x1p-126f
>>>>>>> 2fb834ef17 (1)
/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: scalbnf
 *
 * Description:
 *   get a float number of x*2^n
 *
 ****************************************************************************/

float scalbnf(float x, int n)
{
  union
    {
      float f;
      uint32_t i;
    }u;

  float_t y = x;

  if (n > 127)
    {
      y *= 0x1p127f;
      n -= 127;
      if (n > 127)
        {
          y *= 0x1p127f;
          n -= 127;
          if (n > 127)
            {
              n = 127;
            }
        }
    }
  else if (n < -126)
    {
      y *= FLT_MIN * 0x1p24f;
      n += 126 - 24;
      if (n < -126)
        {
          y *= FLT_MIN * 0x1p24f;
          n += 126 - 24;
          if (n < -126)
            {
              n = -126;
            }
        }
    }

  u.i = (uint32_t)(0x7f + n) << 23;
  x = y * u.f;
  return x;
}

