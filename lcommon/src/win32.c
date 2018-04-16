/*
***********************************************************************
* COPYRIGHT AND WARRANTY INFORMATION
*
* Copyright 2001, International Telecommunications Union, Geneva
*
* DISCLAIMER OF WARRANTY
*
* These software programs are available to the user without any
* license fee or royalty on an "as is" basis. The ITU disclaims
* any and all warranties, whether express, implied, or
* statutory, including any implied warranties of merchantability
* or of fitness for a particular purpose.  In no event shall the
* contributor or the ITU be liable for any incidental, punitive, or
* consequential damages of any kind whatsoever arising from the
* use of these programs.
*
* This disclaimer of warranty extends to the user of these programs
* and user's customers, employees, agents, transferees, successors,
* and assigns.
*
* The ITU does not represent or warrant that the programs furnished
* hereunder are free of infringement of any third-party patents.
* Commercial implementations of ITU-T Recommendations, including
* shareware, may be subject to royalty fees to patent holders.
* Information regarding the ITU-T patent policy is available from
* the ITU Web site at http://www.itu.int.
*
* THIS IS NOT A GRANT OF PATENT RIGHTS - SEE THE ITU-T PATENT POLICY.
************************************************************************
*/


/*!
 *************************************************************************************
 * \file win32.c
 *
 * \brief
 *    Platform dependent code
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Karsten Suehring
 *************************************************************************************
 */

#include "global.h"


#ifdef _WIN32

static LARGE_INTEGER freq;

void gettime(TIME_T* time)
{
#ifndef TIMING_DISABLE
  QueryPerformanceCounter(time);
#endif
}

int64 timediff(TIME_T* start, TIME_T* end)
{
#ifndef TIMING_DISABLE
  return (int64)((end->QuadPart - start->QuadPart));
#else
  return 0;
#endif
}

void init_time(void)
{
  QueryPerformanceFrequency(&freq);
}

int64 timenorm(int64  cur_time)
{
#ifndef TIMING_DISABLE
  return (int64)(cur_time * 1000 /(freq.QuadPart));
#else
  return 1;
#endif
}

#else

static struct timezone tz;

void gettime(TIME_T* time)
{
  gettimeofday(time, &tz);
}

void init_time(void)
{
}

int64 timediff(TIME_T* start, TIME_T* end)
{
  int t1, t2;

  t1 =  end->tv_sec  - start->tv_sec;
  t2 =  end->tv_usec - start->tv_usec;
  return (int64) t2 + (int64) t1 * (int64) 1000000;
}

int64 timenorm(int64 cur_time)
{
  return (int64)(cur_time / (int64) 1000);
}
#endif
