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
 *    wp_mcprec.h
 *
 * \brief
 *    Headerfile for Improved Motion Compensatation Precision Scheme using Weighted Prediction
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Athanasios Leontaris            <aleon@dolby.com>
 *
 * \date
 *    16 July 2008
 *
 **************************************************************************
 */

#ifndef _WP_MCPREC_H_
#define _WP_MCPREC_H_

typedef struct
{
  int PicNum;              // PicNum/FrameNum
  int POCNum;              // POC
}
WeightedPredRefX;

typedef struct
{
  int algorithm;
}
WPXPass;

typedef struct wpx_object
{
  int               num_wp_ref_list[2];         // num of elements in each of the above matrices [LIST]
  WeightedPredRefX *wp_ref_list[2];             // structure with reordering and WP information for ref frames [LIST]
  WPXPass          *curr_wp_rd_pass;
  WPXPass           wp_rd_passes[3];            // frame_picture [0...4] (MultiRefWeightedPred == 2)
}
WPXObject;

extern void   wpxInitWPXObject( VideoParameters *p_Vid );
extern void   wpxFreeWPXObject( VideoParameters *p_Vid );
extern void   wpxInitWPXPasses( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void   wpxModifyRefPicList( Slice *currSlice );
// Note that at some point, InputParameters p_Inp contents should be copied into VideoParameters *p_Vid. 
// This would eliminate need of having to use both structures
extern int    wpxDetermineWP( Slice *currSlice, int clist, int n );
extern void   wpxAdaptRefNum( Slice *currSlice );

#endif
