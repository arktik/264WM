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
 *  \file dec_statistics.h
 *
 *  \brief
 *     Various decoding statistics
 *
 *  \author
 *      Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Alexis Tourapis                 <alexismt@ieee.org>
 *
 **************************************************************************
 */

#ifndef _DEC_STATISTICS_H_
#define _DEC_STATISTICS_H_
#include "global.h"

typedef struct dec_stat_parameters
{
  int    frame_ctr           [NUM_SLICE_TYPES];          //!< Counter for different frame coding types (assumes one slice type per frame)
  int64  mode_use            [NUM_SLICE_TYPES][MAXMODE]; //!< Macroblock mode usage per slice
  int64  mode_use_transform  [NUM_SLICE_TYPES][MAXMODE][2];

  int64  *histogram_mv  [2][2];    //!< mv histogram (per list and per direction)
  int64  *histogram_refs[2];       //!< reference histogram (per list)
} DecStatParameters;

extern void init_dec_stats  (DecStatParameters *stats);
extern void delete_dec_stats(DecStatParameters *stats);


#endif
