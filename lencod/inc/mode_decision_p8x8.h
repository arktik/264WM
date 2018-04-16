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
 *    mode_decision_p8x8.h
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Alexis Michael Tourapis         <alexismt@ieee.org>
 *
 * \date
 *    1 September 2009
 *
 * \brief
 *    Headerfile for 8x8 mode decision
 **************************************************************************
 */

#ifndef _MODE_DECISION_P8x8_H_
#define _MODE_DECISION_P8x8_H_

//==== MODULE PARAMETERS ====
extern void submacroblock_mode_decision_p_slice (Macroblock *currMB, RD_PARAMS *, RD_8x8DATA *, int ****, int, distblk *);
extern void submacroblock_mode_decision_b_slice (Macroblock *currMB, RD_PARAMS *, RD_8x8DATA *, int ****, int, distblk *);
extern void submacroblock_mode_decision_low(Macroblock *currMB, RD_PARAMS *, RD_8x8DATA *, int ****, int *, int, distblk *, distblk *, distblk *, int);
extern void copy_part_info(Info8x8 *b8x8, Info8x8 *part);

#endif

