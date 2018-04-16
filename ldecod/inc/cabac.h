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
 *    cabac.h
 *
 * \brief
 *    Header file for entropy coding routines
 *
 * \author
 *    Detlev Marpe                                                         \n
 *    Copyright (C) 2000 HEINRICH HERTZ INSTITUTE All Rights Reserved.
 *
 * \date
 *    21. Oct 2000 (Changes by Tobias Oelbaum 28.08.2001)
 ***************************************************************************
 */

#ifndef _CABAC_H_
#define _CABAC_H_

#include "global.h"

extern MotionInfoContexts*  create_contexts_MotionInfo(void);
extern TextureInfoContexts* create_contexts_TextureInfo(void);
extern void delete_contexts_MotionInfo(MotionInfoContexts *enco_ctx);
extern void delete_contexts_TextureInfo(TextureInfoContexts *enco_ctx);

extern void cabac_new_slice(Slice *currSlice);

extern void readMB_typeInfo_CABAC_i_slice   (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readMB_typeInfo_CABAC_p_slice   (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readMB_typeInfo_CABAC_b_slice   (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readB8_typeInfo_CABAC_p_slice   (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readB8_typeInfo_CABAC_b_slice   (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readIntraPredMode_CABAC         (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readRefFrame_CABAC              (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void read_MVD_CABAC                  (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void read_mvd_CABAC_mbaff            (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void read_CBP_CABAC                  (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readRunLevel_CABAC              (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void read_dQuant_CABAC               (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readCIPredMode_CABAC            (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void read_skip_flag_CABAC_p_slice    (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void read_skip_flag_CABAC_b_slice    (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readFieldModeInfo_CABAC         (Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);
extern void readMB_transform_size_flag_CABAC(Macroblock *currMB, SyntaxElement *se, DecodingEnvironmentPtr dep_dp);

extern void readIPCM_CABAC(Slice *currSlice, struct datapartition_dec *dP);

extern int  cabac_startcode_follows(Slice *currSlice, int eos_bit);

extern int  readSyntaxElement_CABAC         (Macroblock *currMB, SyntaxElement *se, DataPartition *this_dataPart);

extern int check_next_mb_and_get_field_mode_CABAC_p_slice( Slice *currSlice, SyntaxElement *se, DataPartition  *act_dp);
extern int check_next_mb_and_get_field_mode_CABAC_b_slice( Slice *currSlice, SyntaxElement *se, DataPartition  *act_dp);

extern void CheckAvailabilityOfNeighborsCABAC(Macroblock *currMB);

extern void set_read_and_store_CBP(Macroblock **currMB, int chroma_format_idc);

#endif  // _CABAC_H_

