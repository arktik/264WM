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
 * \file mb_access.h
 *
 * \brief
 *    Functions for macroblock neighborhoods
 *
 * \author
 *     Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Karsten Suehring
 *     - Alexis Michael Tourapis         <alexismt@ieee.org>  
 *************************************************************************************
 */

#ifndef _MB_ACCESS_H_
#define _MB_ACCESS_H_

extern void CheckAvailabilityOfNeighbors(Macroblock *currMB);
extern void CheckAvailabilityOfNeighborsMBAFF(Macroblock *currMB);
extern void CheckAvailabilityOfNeighborsNormal(Macroblock *currMB);

extern void getAffNeighbour         (Macroblock *currMB, int xN, int yN, int mb_size[2], PixelPos *pix);
extern void getNonAffNeighbour      (Macroblock *currMB, int xN, int yN, int mb_size[2], PixelPos *pix);
extern void get4x4Neighbour         (Macroblock *currMB, int xN, int yN, int mb_size[2], PixelPos *pix);
extern void get4x4NeighbourBase     (Macroblock *currMB, int block_x, int block_y, int mb_size[2], PixelPos *pix);
extern Boolean mb_is_available      (int mbAddr, Macroblock *currMB);
extern void get_mb_pos              (VideoParameters *p_Vid, int mb_addr, int mb_size[2], short *x, short *y);
extern void get_mb_block_pos_normal (BlockPos *PicPos, int mb_addr, short *x, short *y);
extern void get_mb_block_pos_mbaff  (BlockPos *PicPos, int mb_addr, short *x, short *y);


#endif
