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
 **************************************************************************************
 * \file
 *    parset.h
 * \brief
 *    Picture and Sequence Parameter Sets, encoder operations
 *
 * \date 25 November 2002
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Stephan Wenger        <stewe@cs.tu-berlin.de>
 ***************************************************************************************
 */


#ifndef _PARSET_H_
#define _PARSET_H_

#include "parsetcommon.h"
#include "nalu.h"
#include "sei.h"

extern void generate_parameter_sets (VideoParameters *p_Vid);
extern void FreeParameterSets     (VideoParameters *p_Vid);

extern NALU_t *GenerateSeq_parameter_set_NALU (VideoParameters *p_Vid);
extern NALU_t *GeneratePic_parameter_set_NALU (VideoParameters *p_Vid, int);
extern NALU_t *GenerateSEImessage_NALU(InputParameters *p_Inp);
#if (MVC_EXTENSION_ENABLE)
extern NALU_t *GenerateSubsetSeq_parameter_set_NALU (VideoParameters *p_Vid);
#endif

// The following are local helpers, but may come handy in the future, hence public
extern void GenerateSequenceParameterSet(seq_parameter_set_rbsp_t *sps, VideoParameters *p_Vid, int SPS_id);
extern void GeneratePictureParameterSet( pic_parameter_set_rbsp_t *pps, seq_parameter_set_rbsp_t *sps, 
                                 VideoParameters *p_Vid,
                                 InputParameters *p_Inp, int PPS_id,
                                 int WeightedPrediction, int WeightedBiprediction,
                                 int cb_qp_index_offset, int cr_qp_index_offset);

extern int  Scaling_List(short *scalingListinput, short *scalingList, int sizeOfScalingList, short *UseDefaultScalingMatrix, Bitstream *bitstream);
#if (MVC_EXTENSION_ENABLE)
extern int  GenerateSeq_parameter_set_rbsp (VideoParameters *p_Vid, seq_parameter_set_rbsp_t *sps, byte *buf, short Is_Subset);
#else
extern int  GenerateSeq_parameter_set_rbsp (VideoParameters *p_Vid, seq_parameter_set_rbsp_t *sps, byte *buf);
#endif
extern int  GeneratePic_parameter_set_rbsp (VideoParameters *p_Vid, pic_parameter_set_rbsp_t *pps, byte *buf);
extern int  GenerateSEImessage_rbsp (InputParameters *p_Inp, int id, byte *buf);
extern void FreeSPS (seq_parameter_set_rbsp_t *sps);
extern void FreePPS (pic_parameter_set_rbsp_t *pps);

extern int  WriteHRDParameters(seq_parameter_set_rbsp_t *sps, Bitstream *bitstream);
extern void GenerateVUIParameters(seq_parameter_set_rbsp_t *sps, InputParameters *p_Inp);

extern pic_parameter_set_rbsp_t *AllocPPS (void);
extern seq_parameter_set_rbsp_t *AllocSPS (void);


#endif
