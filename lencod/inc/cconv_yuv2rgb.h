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
 *    cconv_yuv2rgb.h
 *
 * \author
 *    Woo-Shik Kim
 *
 * \date
 *    29 May 2008
 *
 * \brief
 *    Headerfile for YUV to RGB color conversion
 **************************************************************************
 */

#ifndef _CCONV_YUV2RGB_H_
#define _CCONV_YUV2RGB_H_

#include "img_distortion.h"

extern void init_YUVtoRGB    (VideoParameters *p_Vid, InputParameters *p_Inp);
extern void YUVtoRGB         (VideoParameters *p_Vid, ImageStructure *YUV, ImageStructure *RGB);
extern int  create_RGB_memory(VideoParameters *p_Vid);
extern void delete_RGB_memory(VideoParameters *p_Vid);

#endif

