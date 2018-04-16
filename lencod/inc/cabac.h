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
 *    Headerfile for entropy coding routines
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

static const byte maxpos       [] = {15, 14, 63, 31, 31, 15,  3, 14,  7, 15, 15, 14, 63, 31, 31, 15, 15, 14, 63, 31, 31, 15};
static const byte c1isdc       [] = { 1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1};

static const byte type2ctx_bcbp[] = { 0,  1,  2,  3,  3,  4,  5,  6,  5,  5, 10, 11, 12, 13, 13, 14, 16, 17, 18, 19, 19, 20};
static const byte type2ctx_map [] = { 0,  1,  2,  3,  4,  5,  6,  7,  6,  6, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}; // 8
static const byte type2ctx_last[] = { 0,  1,  2,  3,  4,  5,  6,  7,  6,  6, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}; // 8
static const byte type2ctx_one [] = { 0,  1,  2,  3,  3,  4,  5,  6,  5,  5, 10, 11, 12, 13, 13, 14, 16, 17, 18, 19, 19, 20}; // 7
static const byte type2ctx_abs [] = { 0,  1,  2,  3,  3,  4,  5,  6,  5,  5, 10, 11, 12, 13, 13, 14, 16, 17, 18, 19, 19, 20}; // 7
static const byte max_c2       [] = { 4,  4,  4,  4,  4,  4,  3,  4,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4}; // 9


extern const byte* pos2ctx_map     [];
extern const byte* pos2ctx_map_int [];
extern const byte* pos2ctx_last    [];

// CABAC
extern MotionInfoContexts* create_contexts_MotionInfo  (void);
extern TextureInfoContexts* create_contexts_TextureInfo(void);

extern void delete_contexts_MotionInfo  (MotionInfoContexts *enco_ctx);
extern void delete_contexts_TextureInfo (TextureInfoContexts *enco_ctx);
extern void writeMB_I_typeInfo_CABAC    (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeMB_B_typeInfo_CABAC    (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeMB_P_typeInfo_CABAC    (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeIntraPredMode_CABAC  (SyntaxElement *se, DataPartition *dp);
extern void writeB8_typeInfo_CABAC    (SyntaxElement *se, DataPartition *dp);
extern void writeB8_B_typeInfo_CABAC  (SyntaxElement *se, DataPartition *dp);

extern void writeRefPic_B_CABAC        (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeRefPic_P_CABAC        (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);

extern void writeMVD_CABAC             (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeCBP_CABAC             (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeDquant_CABAC          (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeRunLevel_CABAC        (Macroblock* currMB, SyntaxElement *se, DataPartition *dp);
extern void writeCIPredMode_CABAC      (Macroblock* currMB, SyntaxElement *se, DataPartition *dp);
extern void print_ctx_TextureInfo      (TextureInfoContexts *enco_ctx);
extern void writeMB_Pskip_flagInfo_CABAC(Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeMB_Bskip_flagInfo_CABAC(Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeFieldModeInfo_CABAC   (Macroblock *currMB, SyntaxElement *se, DataPartition *dp); //GB
extern void writeCBP_BIT_CABAC         (Macroblock *currMB, int b8, int bit, int cbp, EncodingEnvironmentPtr eep_dp, TextureInfoContexts *ctx);

extern void CheckAvailabilityOfNeighborsCABAC (Macroblock* currMB);
extern void writeMB_transform_size_CABAC(Macroblock *currMB, SyntaxElement *se, DataPartition *dp);

extern void write_and_store_CBP_block_bit_444 (Macroblock* currMB, EncodingEnvironmentPtr eep_dp, int type, int cbp_bit, TextureInfoContexts*  tex_ctx);
extern void write_and_store_CBP_block_bit     (Macroblock* currMB, EncodingEnvironmentPtr eep_dp, int type, int cbp_bit, TextureInfoContexts*  tex_ctx);


#endif  // CABAC_H

