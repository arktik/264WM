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
 * \file get_block_otf.h
 *
 * \brief
 *    get predicted (chroma|luma) block with subpel interpolation computes on-the-fly
 *
 *
 *************************************************************************************
 */


#ifndef _GET_BLOCK_OTF_H_
#define _GET_BLOCK_OTF_H_

void get_block_luma_otf_L2(  VideoParameters *p_Vid,  //!< video encoding parameters for current picture
                      imgpel*   mpred,         //!< array of prediction values (row by row)
                      int*   tmp_pred,         //!< array of temporary prediction values (row by row), used for some hal-pel interpolations
                      int    pic_pix_x,        //!< motion shifted horizontal coordinate of block
                      int    pic_pix_y,        //!< motion shifted vertical   coordinate of block
                      int    block_size_x,   //!< horizontal block size
                      int    block_size_y,   //!< vertical block size
                      StorablePicture *ref,    //!< reference picture list
                      int    pl                //!< plane
                    );

void get_block_luma_otf_L1(  VideoParameters *p_Vid,  //!< video encoding parameters for current picture
                      imgpel*   mpred,         //!< array of prediction values (row by row)
                      int*   tmp_pred,         //!< array of temporary prediction values (row by row), used for some hal-pel interpolations
                      int    pic_pix_x,        //!< motion shifted horizontal coordinate of block
                      int    pic_pix_y,        //!< motion shifted vertical   coordinate of block
                      int    block_size_x,   //!< horizontal block size
                      int    block_size_y,   //!< vertical block size
                      StorablePicture *ref,    //!< reference picture list
                      int    pl                //!< plane
                    ) ;


void get_block_chroma_otf_L2 ( VideoParameters *p_Vid, //!< video encoding parameters for current picture
                        imgpel* mpred,          //!< array to store prediction values
                        int*   tmp_pred,
                        int    pic_pix_x,          //!< motion shifted horizontal coordinate of block
                        int    pic_pix_y,          //!< motion shifted vertical  block
                        int    block_size_x, //!< horizontal block size
                        int    block_size_y, //!< vertical block size                                      
                        StorablePicture *ref,  //!< reference picture list
                        int    uv                //!< chroma component
                        ) ;

void me_get_block_chroma_otf_L1 ( VideoParameters *p_Vid, //!< video encoding parameters for current picture
                        imgpel* mpred,          //!< array to store prediction values
                        int*   tmp_pred,
                        int    pic_pix_x,          //!< motion shifted horizontal coordinate of block
                        int    pic_pix_y,          //!< motion shifted vertical  block
                        int    block_size_x, //!< horizontal block size
                        int    block_size_y, //!< vertical block size                                      
                        StorablePicture *ref,  //!< reference picture list
                        int    uv                //!< chroma component
                        ) ;

void mc_get_block_chroma_otf_L1 ( VideoParameters *p_Vid, //!< video encoding parameters for current picture
                        imgpel* mpred,          //!< array to store prediction values
                        int*   tmp_pred,
                        int    pic_pix_x,          //!< motion shifted horizontal coordinate of block
                        int    pic_pix_y,          //!< motion shifted vertical  block
                        int    block_size_x, //!< horizontal block size
                        int    block_size_y, //!< vertical block size                                      
                        StorablePicture *ref,  //!< reference picture list
                        int    uv                //!< chroma component
                        ) ;




//static inline int is_pel( int x, int y, int bx, int by ) 
//{
//  return ( (((x & bx)==0) && ((y & by)==0)) ? (1):(0) );
//}
//
//static inline int is_hpel( int x, int y, int bx, int by ) 
//{
//  return ( ((( (x & bx)==2)&&((y & by)==2)) || (((x & bx)==2)&&((y & by)==0)) || (((x & bx)==0)&&((y & by)==2)) ) ? (1):(0) );
//}
//
//static inline int is_qpel( int x, int y, int bx, int by ) 
//{
//  return ( !is_pel(x,y,bx,by) && !is_hpel(x,y,bx,by) );
//}

static inline int is_qpel( int x, int y, int bx, int by ) 
{
  return ( ((x&bx)%2) || ((y&by)%2) ) ? (1):(0) ;
}

#endif

