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
 **************************************************************************
 *  \file distortion.h
 *  \brief  
 *     Distortion data header file
 *  \date 2.23.2009,
 *
 *  \author 
 *   Alexis Michael Tourapis        <alexismt@ieee.org>
 *
 **************************************************************************
 */

#ifndef _DISTORTION_H_
#define _DISTORTION_H_

// Distortion data structure. Could be extended in the future to support
// other data 
typedef struct distortion_data
{
  int      i4x4rd[4][4];         //! i4x4 rd cost
  distblk  i4x4  [4][4];         //! i4x4 cost
  distblk  i8x8  [2][2];         //! i8x8 cost
  int      i8x8rd[2][2];         //! i8x8 rd cost
  int      i16x16;
  int      i16x16rd;
  double   rd_cost;
} DistortionData;

#endif

