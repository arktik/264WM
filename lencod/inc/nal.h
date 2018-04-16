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
 **************************************************************************************
 * \file
 *    nal.h
 * \brief
 *    NAL related headers
 *
 * \date 4 Agust 2008
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Karsten Suehring
 *      - Alexis Michael Tourapis         <alexismt@ieee.org> 
 ***************************************************************************************
 */


#ifndef _NAL_H_
#define _NAL_H_

#include "nalucommon.h"
#include "enc_statistics.h"

extern int  addCabacZeroWords(VideoParameters *p_Vid, NALU_t *nalu, StatParameters *cur_stats);
extern void SODBtoRBSP (Bitstream *currStream);
extern int  RBSPtoEBSP(byte *NaluBuffer, unsigned char *rbsp, int rbsp_size);

#endif
