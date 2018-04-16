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
 *    wp_lms.h
 *
 * \author
 *    Alexis Michael Tourapis
 *
 * \date
 *    22. February 2008
 *
 * \brief
 *    Headerfile for weighted prediction support using LMS
 **************************************************************************
 */

#ifndef _WP_LMS_H_
#define _WP_LMS_H_

extern void EstimateWPPSliceAlg1(Slice *currSlice, int offset);
extern void EstimateWPBSliceAlg1(Slice *currSlice);
extern int  TestWPPSliceAlg1    (Slice *currSlice, int offset);
extern int  TestWPBSliceAlg1    (Slice *currSlice, int method);
extern void   ComputeExplicitWPParamsLMS(Slice *currSlice,
                                         int select_offset,
                                         int start_mb,
                                         int end_mb, 
                                         short default_weight[3],
                                         short weight[6][MAX_REFERENCE_PICTURES][3],
                                         short offset[6][MAX_REFERENCE_PICTURES][3]);
extern void   ComputeExplicitWPParamsJNT(Slice *currSlice,
                                         int start_mb,
                                         int end_mb, 
                                         short default_weight[3],
                                         short weight[6][MAX_REFERENCE_PICTURES][3],
                                         short offset[6][MAX_REFERENCE_PICTURES][3]);



#endif

