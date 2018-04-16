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
 *    me_distortion.h
 *
 * \author
 *    Alexis Michael Tourapis        <alexis.tourapis@dolby.com>
 *    Athanasios Leontaris           <aleon@dolby.com>
 *
 * \date
 *    11. August 2006
 *
 * \brief
 *    Headerfile for motion estimation distortion
 **************************************************************************
 */

#ifndef _ME_DISTORTION_H_
#define _ME_DISTORTION_H_

extern distblk distortion4x4SAD(short* diff, distblk min_mcost);
extern distblk distortion4x4SSE(short* diff, distblk min_mcost);
extern distblk distortion4x4SATD(short* diff, distblk min_cost);
extern distblk distortion8x8SAD(short* diff, distblk min_mcost);
extern distblk distortion8x8SSE(short* diff, distblk min_mcost);
extern distblk distortion8x8SATD(short* diff, distblk min_cost);

extern int HadamardSAD4x4(short* diff);
extern int HadamardSAD8x8(short* diff);
// SAD functions
extern distblk computeSAD         (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD16x16    (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD16x8     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD8x16     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD8x8      (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD8x4      (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD4x8      (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAD4x4      (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// Weighted Prediction SAD functions
extern distblk computeSADWP     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP16x16  (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP16x8   (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP8x16   (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP8x8    (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP8x4    (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP4x8    (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSADWP4x4    (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// SATD
extern distblk computeSATD      (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSATDWP    (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT8x8D16x16(StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT4x4D16x16(StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT8x8D16x8 (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT4x4D16x8 (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT8x8D8x16 (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT4x4D8x16 (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT8x8D     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSAT4x4D     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// SSE
extern distblk computeSSE       (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);
extern distblk computeSSEWP     (StorablePicture *ref1, MEBlock*, distblk, MotionVector *);

// Bipred SAD
extern distblk computeBiPredSAD1    (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred16x16SAD1 (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred16x8SAD1  (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred8x16SAD1  (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred8x8SAD1   (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred8x4SAD1   (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred4x8SAD1   (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred4x4SAD1   (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPredSAD2    (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);

// Bipred SATD
extern distblk computeBiPredSATD1   (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPredSATD2   (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred16x16SATD1(StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred16x8SATD1 (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred8x8SATD1  (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPred8x16SATD1 (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);

// Bipred SSE
extern distblk computeBiPredSSE1    (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);
extern distblk computeBiPredSSE2    (StorablePicture *ref1, StorablePicture *ref2, MEBlock*, distblk, MotionVector *, MotionVector *);

extern void select_distortion   (VideoParameters *p_Vid, InputParameters *p_Inp);

extern void calcDifference(imgpel **origImg, int ox, int oy, imgpel **predImg, int px, int py, int width, int height, short *diff);
#endif
