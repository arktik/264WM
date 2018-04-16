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
 ***************************************************************************
 * \file
 *    ratectl.h
 *
 * \author
 *    Zhengguo LI
 *    Athanasios Leontaris
 *
 * \date
 *    14 Jan 2003
 *
 * \brief
 *    Headerfile for rate control
 **************************************************************************
 */

#ifndef _RATE_CTL_H_
#define _RATE_CTL_H_

#include "global.h"
#include "rc_quadratic.h"


// generic functions
extern int    Qstep2QP          ( double Qstep, int qp_offset );
extern double QP2Qstep          ( int QP );
extern int    ComputeMBMAD      ( int diff[16][16] );
extern double ComputeFrameMAD   ( VideoParameters *p_Vid );
extern void   rc_store_mad      ( Macroblock *currMB );

// rate control functions
// init/copy
extern void  rc_alloc_generic           ( VideoParameters *p_Vid, RCGeneric **p_quad );
extern void  rc_free_generic            ( RCGeneric **p_quad );
extern void  rc_copy_generic            ( VideoParameters *p_Vid, RCGeneric *dst, RCGeneric *src );
extern void  rc_init_gop_params         ( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void  rc_init_frame              ( VideoParameters *p_Vid, InputParameters *p_Inp);
extern void  rc_init_sequence           ( VideoParameters *p_Vid, InputParameters *p_Inp);
extern void  rc_store_slice_header_bits ( VideoParameters *p_Vid, InputParameters *p_Inp, int len);

#endif

