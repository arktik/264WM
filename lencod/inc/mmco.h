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
 *    mmco.h
 * \brief
 *    MMCO example operations.
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Alexis Michael Tourapis                     <alexismt@ieee.org>
 *     - Athanasios Leontaris                        <aleon@dolby.com>
 ***************************************************************************************
 */

#ifndef _MMCO_H_
#define _MMCO_H_

extern void mmco_long_term(VideoParameters *p_Vid, int current_pic_num);
extern void poc_based_ref_management_frame_pic(DecodedPictureBuffer *p_Dpb, int current_pic_num);
#if CRA
extern void cra_ref_management_frame_pic(DecodedPictureBuffer *p_Dpb, int current_pic_num);
#endif
#if HM50_LIKE_MMCO
extern void hm50_ref_management_frame_pic(DecodedPictureBuffer *p_Dpb, int current_pic_num);
#endif
#if LD_REF_SETTING
extern void low_delay_ref_management_frame_pic(DecodedPictureBuffer *p_Dpb, int current_pic_num);
#endif
extern void poc_based_ref_management_field_pic(DecodedPictureBuffer *p_Dpb, int current_pic_num);
extern void tlyr_based_ref_management_frame_pic(VideoParameters *p_Vid, int current_pic_num); 

#endif 
