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
 * \file image.h
 *
 * \brief
 *    headers for image processing
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Karsten Suehring
 *     - Inge Lille-Langoy               <inge.lille-langoy@telenor.com>
 *     - Alexis Michael Tourapis         <alexismt@ieee.org> 
 *  
 ************************************************************************
 */
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "mbuffer.h"

typedef struct coding_info {
  short type;
  int   intras;   
  int   sumFrameQP; 
  int   num_ref_idx_l0; 
  int   num_ref_idx_l1; 
  pic_parameter_set_rbsp_t *active_pps;
} CodingInfo;

extern int     encode_one_frame      ( VideoParameters *p_Vid, InputParameters *p_Inp);
extern Boolean dummy_slice_too_big   ( int bits_slice);
extern void    copy_rdopt_data       ( Macroblock *currMB);       // For MB level field/frame coding tools
extern void    UnifiedOneForthPix    ( VideoParameters *p_Vid, StorablePicture *s);
extern void    GenerateHMELayers     ( VideoParameters *p_Vid, StorablePicture *s);
// For 4:4:4 independent mode
extern void    UnifiedOneForthPix_JV ( VideoParameters *p_Vid, int nplane, StorablePicture *s);
extern void    frame_picture         ( VideoParameters *p_Vid, Picture *frame, ImageData *imgData, int rd_pass);
extern byte    get_idr_flag          ( VideoParameters *p_Vid );
extern byte    get_random_access_flag( VideoParameters *p_Vid );
extern void    write_non_vcl_nalu    ( VideoParameters *p_Vid);
extern void    write_non_vcl_nalu_bot_fld( VideoParameters *p_Vid );
#if (MVC_EXTENSION_ENABLE)
extern void    write_non_vcl_nalu_mvc( VideoParameters *p_Vid);
#endif

extern void    frame_picture_mp      ( VideoParameters *p_Vid, InputParameters *p_Inp );
extern void    restore_coding_info   ( VideoParameters *p_Vid, CodingInfo *coding_info );
extern void    store_coding_info     ( VideoParameters *p_Vid, CodingInfo *coding_info );
extern void    store_coding_and_rc_info( VideoParameters *p_Vid, CodingInfo *coding_info );
extern void    swap_frame_buffer     ( VideoParameters *p_Vid, int a, int b );
extern void    frame_picture_mp_exit ( VideoParameters *p_Vid, CodingInfo *coding_info );


extern void GenerateImagePyramid(VideoParameters *p_Vid, int size_x, int size_y, imgpel ***pHmeImage, int offset_x, int offset_y);
extern void GetHMEIntImagesLuma( VideoParameters *p_Vid, int size_x, int size_y, imgpel ***cImgInt);

extern void    GenerateHMEBuffers    ( VideoParameters *p_Vid, int size_x, int size_y, imgpel ***pHmeImage, int offset_x, int offset_y);
extern void    OutputImage           ( char *pcPrefix, int iFrameNo, int iLevel, imgpel **pImg, int iWidth, int iHeight, int iXOffset, int iYOffset);
extern void    copy_params           ( VideoParameters *p_Vid, StorablePicture *enc_picture, seq_parameter_set_rbsp_t *active_sps);
extern void    OtfCompatibility_copyWithPadding ( imgpel **dstImg, imgpel **srcImg, int size_x, int size_y, int padding_x, int padding_y ); // JLT

#endif

