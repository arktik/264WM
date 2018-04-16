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
 ******************************************************************************************
 * \file
 *    me_distortion_otf.h
 *
 * \brief
 *    Headerfile for motion estimation distortion with subpel interpolation on-the-fly
 ******************************************************************************************
 */

#ifndef _ME_DISTORTION_OTF_H_
#define _ME_DISTORTION_OTF_H_

// SAD functions
extern distblk computeSAD_otf         (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// Weighted Prediction SAD functions
extern distblk computeSADWP_otf     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// SATD
extern distblk computeSATD_otf       (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSATDWP_otf     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// SSE
extern distblk computeSSE_otf        (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSSEWP_otf      (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// Bipred SAD
extern distblk computeBiPredSAD1_otf     (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPredSAD2_otf     (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);

// Bipred SATD
extern distblk computeBiPredSATD1_otf    (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPredSATD2_otf    (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);

// Bipred SSE
extern distblk computeBiPredSSE1_otf     (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPredSSE2_otf     (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);

#endif
