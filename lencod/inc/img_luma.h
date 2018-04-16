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
 *    img_luma.h
 *
 * \author
 *    Athanasios Leontaris           <aleon@dolby.com>
 *    Alexis Michael Tourapis        <alexis.tourapis@dolby.com>
 *
 * \date
 *    4. October 2006
 *
 * \brief
 *    Headerfile for luma interpolation functions
 **************************************************************************
 */

#ifndef _IMG_LUMA_H_
#define _IMG_LUMA_H_

static const int ONE_FOURTH_TAP[2][3] =
{
  {20, -5, 1},  // AVC Interpolation taps
  {20,-4, 0},   // Experimental - not valid
};

extern void getSubImagesLuma       ( VideoParameters *p_Vid, StorablePicture *s );
/*
extern void getSubImageInteger     ( StorablePicture *s, imgpel **dstImg, imgpel **srcImg);
extern void getSubImageInteger_s   ( StorablePicture *s, imgpel **dstImg, imgpel **srcImg);
extern void getHorSubImageSixTap   ( VideoParameters *p_Vid, StorablePicture *s, imgpel **dst_imgY, imgpel **ref_imgY);
extern void getVerSubImageSixTap   ( VideoParameters *p_Vid, StorablePicture *s, imgpel **dst_imgY, imgpel **ref_imgY);
extern void getVerSubImageSixTapTmp( VideoParameters *p_Vid, StorablePicture *s, imgpel **dst_imgY);
extern void getSubImageBiLinear    ( StorablePicture *s, imgpel **dstImg, imgpel **srcImgL, imgpel **srcImgR);
extern void getHorSubImageBiLinear ( StorablePicture *s, imgpel **dstImg, imgpel **srcImgL, imgpel **srcImgR);
extern void getVerSubImageBiLinear ( StorablePicture *s, imgpel **dstImg, imgpel **srcImgT, imgpel **srcImgB);
extern void getDiagSubImageBiLinear( StorablePicture *s, imgpel **dstImg, imgpel **srcImgT, imgpel **srcImgB);
*/
#endif // _IMG_LUMA_H_
