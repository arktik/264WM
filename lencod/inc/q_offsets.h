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
 *    q_offsets.h
 *
 * \brief
 *    Headerfile for q_offsets array
 *
 * \date
 *    18. Nov 2004
 ***************************************************************************
 */

#ifndef _Q_OFFSETS_H_
#define _Q_OFFSETS_H_

static const int OffsetBits = 11;

extern void init_qoffset            (VideoParameters *p_Vid);
extern void CalculateOffset4x4Param (VideoParameters *p_Vid);
extern void CalculateOffset8x8Param (VideoParameters *p_Vid);
extern void free_QOffsets           (QuantParameters *p_Quant, InputParameters *p_Inp);
extern void InitOffsetParam (QuantParameters *p_Quant, InputParameters *p_Inp);
#endif
