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
 ************************************************************************
 * \file
 *    macroblock.h
 *
 * \brief
 *    Arrays for macroblock processing
 *
 * \author
 *    Inge Lille-Langoy               <inge.lille-langoy@telenor.com>     \n
 *    Telenor Satellite Services                                          \n
 *    P.O.Box 6914 St.Olavs plass                                         \n
 *    N-0130 Oslo, Norway
 *
 ************************************************************************/

#ifndef _MACROBLOCK_H_
#define _MACROBLOCK_H_

#include "block.h"
#include "macroblock_p444.h"

static const int block8x8_idx[3][4][4] = 
{
  { 
    {0, 1, 0, 0},
    {2, 3, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  },
  {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {2, 3, 0, 0},
    {2, 3, 0, 0}
  },
  {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {2, 2, 3, 3},
    {2, 2, 3, 3}
  }
};

static const short part_size[8][2] = 
{
  {4, 4},
  {4, 4},
  {4, 2},
  {2, 4},
  {2, 2},
  {2, 1},
  {1, 2},
  {1, 1}
};

static const short block_size[8][2] = 
{
  {16, 16},
  {16, 16},
  {16, 8},
  {8, 16},
  {8, 8},
  {8, 4},
  {4, 8},
  {4, 4}
};

extern void  next_macroblock  (Macroblock* currMB);
extern void  start_macroblock (Slice *currSlice, Macroblock** currMB, int mb_addr, Boolean mb_field);
extern void  reset_macroblock (Macroblock *currMB);
extern void  end_macroblock   (Macroblock* currMB, Boolean *end_of_slice, Boolean *recode_macroblock);
extern void  write_macroblock (Macroblock* currMB, int eos_bit);


extern int  reset_block(Macroblock* currMB, int *cbp, int64 *cbp_blk, int block8x8);

extern int  luma_residual_coding_16x16     (Macroblock *, int, int[2]);
extern int  luma_residual_coding_8x8       (Macroblock *, int*, int64*, int, short, int[2], char *);
extern void luma_residual_coding           (Macroblock *);
extern void luma_residual_coding_sp        (Macroblock *);
extern void chroma_residual_coding         (Macroblock *);
extern void chroma_residual_coding_sp      (Macroblock *);
extern void chroma_residual_coding_si      (Macroblock *);
extern void intra_chroma_RD_decision       (Macroblock *, RD_PARAMS *);
extern void intra_chroma_RD_decision_mbaff (Macroblock *, RD_PARAMS *);

extern byte transform_decision             (Macroblock *, int, distblk*);
extern int  B8Mode2Value                   (Slice *, short, short);

extern int  write_p_slice_MB_layer         (Macroblock *, int , int *);
extern int  write_b_slice_MB_layer         (Macroblock *, int , int *);
extern int  write_i_slice_MB_layer         (Macroblock *, int , int *);

extern void write_terminating_bit (Slice* currSlice, int bit);

extern int writeMotionInfo2NAL (Macroblock* currMB);
extern int  write_p_slice_motion_info_to_NAL (Macroblock* currMB);
extern int  write_b_slice_motion_info_to_NAL  (Macroblock* currMB);
extern int  write_p_slice_motion_info_to_NAL (Macroblock* currMB);
extern int  writeReferenceFrame   (Macroblock *currMB, int i, int j, int list_idx, int  ref);
extern int  writeMotionVector8x8  (Macroblock *currMB, int  i0, int  j0, int  i1, int  j1, int  refframe, int  list_idx, int  mv_mode, short bipred_me);

extern int  writeCoeff4x4_CABAC   (Macroblock *currMB, ColorPlane, int, int, int);
extern int  writeCoeff8x8_CABAC   (Macroblock* currMB, ColorPlane, int, int);
extern int  writeCoeff8x8         (Macroblock* currMB, ColorPlane, int, int, int);
extern int  writeCoeff16x16_CABAC (Macroblock* currMB, ColorPlane);
extern int  writeCoeff16x16_CAVLC (Macroblock* currMB, ColorPlane);

extern int  writeCoeff4x4_CAVLC_normal (Macroblock* currMB, int block_type, int b8, int b4, int param);
extern int  writeCoeff4x4_CAVLC_444    (Macroblock* currMB, int block_type, int b8, int b4, int param);

extern int   predict_nnz       (Macroblock *currMB, int block_type, int i,int j);
extern int   predict_nnz_chroma(Macroblock *currMB, int i,int j);

extern void set_modes_and_reframe (Macroblock* currMB, int b8, short* p_dir, int list_mode[2], char *list_ref_idx);
extern void set_modes_and_reframe_i_slice (Macroblock* currMB, int b8, short* p_dir, int list_mode[2], char *list_ref_idx);
extern void set_modes_and_reframe_b_slice (Macroblock* currMB, int b8, short* p_dir, int list_mode[2], char *list_ref_idx);
extern void set_modes_and_reframe_p_slice (Macroblock* currMB, int b8, short* p_dir, int list_mode[2], char *list_ref_idx);
extern Macroblock *alloc_mbs(VideoParameters *p_Vid, int mb_num, int layers);
extern void free_mbs(Macroblock *pMBs, int mb_num);
extern void setup_mbs(Macroblock *pMBs, int mb_num, int layer_id);



#endif

