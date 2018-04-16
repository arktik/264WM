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
 * \file vlc.h
 *
 * \brief
 *    Prototypes for VLC coding funtions
 * \author
 *     Karsten Suehring
 *************************************************************************************
 */

#ifndef _VLC_H_
#define _VLC_H_

#include "enc_statistics.h"

extern Boolean write_u_1  (char *tracestring, int value, Bitstream *bitstream);
extern int     write_se_v (char *tracestring, int value, Bitstream *bitstream);
extern int     write_ue_v (char *tracestring, int value, Bitstream *bitstream);
extern int     write_u_v  (int n, char *tracestring, int value, Bitstream *bitstream);

extern void levrun_linfo_c2x2(int level,int run,int *len,int *info);
extern void levrun_linfo_inter(int level,int run,int *len,int *info);

extern void writeSE_Fix                  (SyntaxElement *se, Bitstream *bitstream);
extern void writeSE_UVLC                 (SyntaxElement *se, DataPartition *dp);
extern void writeSE_SVLC                 (SyntaxElement *se, DataPartition *dp);
extern void writeSE_Flag                 (SyntaxElement *se, DataPartition *dp);
extern void writeSE_invFlag              (SyntaxElement *se, DataPartition *dp);
extern void writeSE_Dummy                (SyntaxElement *se, DataPartition *dp);

extern void  writeRefPic_NRef_CAVLC      (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void  writeRefPic_2Ref_CAVLC      (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void  writeRefPic_Dummy           (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);

extern void  writeCBP_VLC                (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void  writeIntraPredMode_CAVLC    (SyntaxElement *se, DataPartition *dp);
extern int   writeSyntaxElement2Buf_UVLC (SyntaxElement *se, Bitstream* this_streamBuffer );
extern void  writeUVLC2buffer            (SyntaxElement *se, Bitstream *currStream);
extern void  writeVlcByteAlign           (VideoParameters *p_Vid, Bitstream* currStream, StatParameters *cur_stats);
extern int   writeSyntaxElement2Buf_Fixed(SyntaxElement *se, Bitstream* this_streamBuffer );
extern int   symbol2uvlc                 (SyntaxElement *se);
extern void  ue_linfo       (int n, int dummy, int *len,int *info);
extern void  se_linfo       (int mvd, int dummy, int *len,int *info);
extern void  cbp_linfo_intra_normal(int cbp, int dummy, int *len,int *info);
extern void  cbp_linfo_intra_other (int cbp, int dummy, int *len,int *info);
extern void  cbp_linfo_inter_normal(int cbp, int dummy, int *len,int *info);
extern void  cbp_linfo_inter_other (int cbp, int dummy, int *len,int *info);

extern int   writeSyntaxElement_VLC(SyntaxElement *se, DataPartition *this_dataPart);
extern int   writeSyntaxElement_TotalZeros(SyntaxElement *se, DataPartition *this_dataPart);
extern int   writeSyntaxElement_TotalZerosChromaDC(VideoParameters *p_Vid, SyntaxElement *se, DataPartition *this_dataPart);
extern int   writeSyntaxElement_Run(SyntaxElement *se, DataPartition *this_dataPart);
extern int   writeSyntaxElement_NumCoeffTrailingOnes(SyntaxElement *se, DataPartition *this_dataPart);
extern int   writeSyntaxElement_NumCoeffTrailingOnesChromaDC(VideoParameters *p_Vid, SyntaxElement *se, DataPartition *this_dataPart);
extern int   writeSyntaxElement_Level_VLC1(SyntaxElement *se, DataPartition *this_dataPart, int profile_idc);
extern int   writeSyntaxElement_Level_VLCN(SyntaxElement *se, int vlc, DataPartition *this_dataPart, int profile_idc);

extern void writeUVLC_CAVLC (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeSVLC_CAVLC (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);
extern void writeFlag_CAVLC (Macroblock *currMB, SyntaxElement *se, DataPartition *dp);

extern void reset_mb_nz_coeff(VideoParameters *p_Vid, int mb_number); 
extern int bs_bitlength(Bitstream *bitstream);
extern int GetBits(byte *buffer,
                   int totbitoffset,
                   int *info, 
                   int bitcount,
                   int numbits);
#endif

