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
 *    rc_quadratic.h
 *
 * \author
 *    Zhengguo LI
 *    Athanasios Leontaris
 *
 * \date
 *    14 Jan 2003
 *
 * \brief
 *    Headerfile for rate control
 **************************************************************************
 */

#ifndef _RC_QUADRATIC_H_
#define _RC_QUADRATIC_H_

#include "rc_types.h"

// rate control functions
// init/copy
extern void rc_alloc_quadratic( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic **p_quad );
extern void rc_free_quadratic ( RCQuadratic **p_quad );
extern void rc_copy_quadratic ( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *dst, RCQuadratic *src );

// rate control (externally visible)
extern void rc_init_seq          (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen);
extern void rc_init_GOP          (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int np, int nb);
extern void rc_update_pict_frame (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int nbits);
extern void rc_init_pict         (VideoParameters *p_Vid, InputParameters *p_Inp, 
                           RCQuadratic *p_quad, RCGeneric *p_gen, int fieldpic, int topfield, int targetcomputation, float mult);
extern void rc_update_pict       (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int nbits);
extern void rc_update_picture    (VideoParameters *p_Vid, InputParameters *p_Inp, int bits);

extern int  updateQPRC0(VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield);
extern int  updateQPRC1(VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield);
extern int  updateQPRC2(VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield);
extern int  updateQPRC3(VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield);

// internal functions
extern void updateQPInterlace   ( RCQuadratic *p_quad, RCGeneric *p_gen );
extern void updateQPNonPicAFF   ( seq_parameter_set_rbsp_t *active_sps, RCQuadratic *p_quad );
extern void updateBottomField   ( InputParameters *p_Inp, RCQuadratic *p_quad );
extern int  updateFirstP        ( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield );
extern int  updateNegativeTarget( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield, int m_Qp );
extern int  updateFirstBU       ( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield );
extern void updateLastBU        ( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen, int topfield );
extern void predictCurrPicMAD   ( InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen );
extern void updateModelQPBU     ( VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, int m_Qp );
extern void updateQPInterlaceBU ( RCQuadratic *p_quad, RCGeneric *p_gen );
extern void updateModelQPFrame  ( RCQuadratic *p_quad, int m_Bits );

extern void updateRCModel    (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen);
extern void updateMADModel   (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, RCGeneric *p_gen);
extern void RCModelEstimator (VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, int n_windowSize, Boolean *m_rgRejected);
extern void MADModelEstimator(VideoParameters *p_Vid, InputParameters *p_Inp, RCQuadratic *p_quad, int n_windowSize, Boolean *PictureRejected);
extern int  updateComplexity (VideoParameters *p_Vid, RCQuadratic *p_quad, RCGeneric *p_gen, Boolean is_updated, int nbits );
extern void updatePparams    (RCQuadratic *p_quad, RCGeneric *p_gen, int complexity );
extern void updateBparams    (RCQuadratic *p_quad, RCGeneric *p_gen, int complexity );

// external generic functions
extern int  rc_handle_mb         ( Macroblock *currMB, int prev_mb);
extern void rc_init_top_field    ( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void rc_init_bottom_field ( VideoParameters *p_Vid, InputParameters *p_Inp, int TopFieldBits );
extern void rc_init_frame_rdpic  ( VideoParameters *p_Vid, InputParameters *p_Inp, float rateRatio );
extern void rc_allocate_memory   ( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void rc_free_memory       ( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void rc_update_mb_stats   ( Macroblock *currMB);
extern void rc_save_state        ( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void rc_restore_state     ( VideoParameters *p_Vid, InputParameters *p_Inp );

#endif
