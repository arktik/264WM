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
 *    pred_struct.h
 *
 * \author
 *    Athanasios Leontaris           <aleon@dolby.com>   
 *
 * \date
 *    June 8, 2009
 *
 * \brief
 *    Header file for prediction structure function headers
 **************************************************************************
 */

#ifndef _PRED_STRUCT_H_
#define _PRED_STRUCT_H_

#include "global.h"
#include "pred_struct_types.h"
#include "explicit_seq.h"

extern void get_poc_type_zero( VideoParameters *p_Vid, InputParameters *p_Inp, FrameUnitStruct *p_frm_struct );
extern void get_poc_type_one( VideoParameters *p_Vid, InputParameters *p_Inp, FrameUnitStruct *p_frm_struct );
extern void init_poc(VideoParameters *p_Vid);
extern SeqStructure * init_seq_structure( VideoParameters *p_Vid, InputParameters *p_Inp, int *memory_size );
extern void free_seq_structure( SeqStructure *p_seq_struct );
extern void populate_frm_struct( VideoParameters *p_Vid, InputParameters *p_Inp, SeqStructure *p_seq_struct, int num_to_populate, int init_frames_to_code );
extern void populate_frame_explicit( ExpFrameInfo *info, InputParameters *p_Inp, FrameUnitStruct *p_frm_struct, int num_slices );
extern void populate_frame_slice_type( InputParameters *p_Inp, FrameUnitStruct *p_frm_struct, int slice_type, int num_slices );
extern void populate_reg_pic( InputParameters *p_Inp, PicStructure *p_pic, FrameUnitStruct *p_frm_struct, int num_slices, int is_bot_fld );
extern void populate_frm_struct_mvc( VideoParameters *p_Vid, InputParameters *p_Inp, SeqStructure *p_seq_struct, int start, int end );

#endif
