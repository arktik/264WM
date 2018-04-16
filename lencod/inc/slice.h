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
 *    slice.h
 *
 * \date
 *    16 July 2008
 *
 * \brief
 *    Headerfile for slice-related functions
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Athanasios Leontaris            <aleon@dolby.com>
 *     - Karsten Suehring
 *     - Alexis Michael Tourapis         <alexismt@ieee.org> 

 **************************************************************************
 */

#ifndef _SLICE_H_
#define _SLICE_H_

#include "global.h"
#include "mbuffer.h"
#include "rdopt_coding_state.h"

static const int QP2QUANT[40]=
{
   1, 1, 1, 1, 2, 2, 2, 2,
   3, 3, 3, 4, 4, 4, 5, 6,
   6, 7, 8, 9,10,11,13,14,
  16,18,20,23,25,29,32,36,
  40,45,51,57,64,72,81,91
};


extern int  encode_one_slice       ( VideoParameters *p_Vid, int SliceGroupId, int TotalCodedMBs );
extern int  encode_one_slice_MBAFF ( VideoParameters *p_Vid, int SliceGroupId, int TotalCodedMBs );
extern void init_slice             ( VideoParameters *p_Vid, Slice **currSlice, int start_mb_addr );
extern void init_slice_lite        ( VideoParameters *p_Vid, Slice **currSlice, int start_mb_addr );
extern void free_slice_list        ( Picture *currPic );

extern void SetLagrangianMultipliersOn (Slice *currSlice);
extern void SetLagrangianMultipliersOff(Slice *currSlice);
extern void  free_slice                (Slice *currSlice);


#endif
