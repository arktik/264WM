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
 *    list_reorder.h
 *
 * \date
 *    25 Feb 2009
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

#ifndef _LIST_REORDER_H_
#define _LIST_REORDER_H_

#include "global.h"
#include "mbuffer.h"

extern void init_ref_pic_list_reordering( Slice *currSlice, int refReorderMethod, int useDistortionReordering);
extern void reorder_lists               ( Slice *currSlice );
extern void wp_mcprec_reorder_lists     ( Slice *currSlice );


extern void poc_ref_pic_reorder_frame_default( Slice *currSlice, unsigned num_ref_idx_lX_active, int list_no );
extern void poc_ref_pic_reorder_field        ( Slice *currSlice, unsigned num_ref_idx_lX_active, int list_no );
extern void poc_ref_pic_reorder_field_enh    ( Slice *currSlice, unsigned num_ref_idx_lX_active, int list_no );

extern void tlyr_ref_pic_reorder_frame_default   ( Slice *currSlice, unsigned num_ref_idx_lX_active, int list_no );
extern void reorder_against_default_ref_pic_lists( Slice *currSlice, int cur_list );
extern void poc_ref_pic_reorder_frame_enh        ( Slice *currSlice, unsigned num_ref_idx_lX_active, int list_no );
extern void mse_ref_pic_reorder_frame            ( Slice *currSlice, unsigned num_ref_idx_lX_active, int list_no );
extern void set_default_ref_pic_lists( Slice *currSlice );

#endif
