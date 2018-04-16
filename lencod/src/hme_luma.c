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
* \file hme_luma.c
*
* \brief
*    HME luma preparatiom functions
*
* \author
*    Main contributors (see contributors.h for copyright, address and affiliation details)
*      - Yuwen He
*      - Alexis Tourapis
*
*************************************************************************************
*/

#include "contributors.h"
#include <limits.h>

#include "global.h"
#include "image.h"
#include "img_luma.h"
#include "me_hme.h"

/*!
 ************************************************************************
 * \brief
  *
 * \param 
 ************************************************************************
 */

static void fillHMEIntImageMargin(imgpel **dstImg, int size_x, int size_y, int offset_x, int offset_y)
{
  int i, j;
  int size_x_minus1 = size_x - 1;
  int size_x_padded = size_x+2*offset_x;
  int size_y_padded = size_y+2*offset_y;
  
  imgpel *wBufSrc, *wBufDst;
  
  // Copy top line
  wBufDst = dstImg[-offset_y]-offset_x;
  wBufSrc = dstImg[0];
  // left IMG_PAD_SIZE
  for (i = 0; i < offset_x; i++)
    *(wBufDst++) = *wBufSrc;
  // center 0-(s->size_x)
  memcpy(wBufDst, wBufSrc, size_x * sizeof(imgpel));
  wBufDst += size_x;
  // right IMG_PAD_SIZE
  for (i = 0; i < offset_x; i++)
    *(wBufDst++) = wBufSrc[size_x_minus1];
  
  // Now copy remaining pad lines
  wBufSrc = dstImg[-offset_y]-offset_x;
  for (j = 1-offset_y; j < 0; j++)
  {
    memcpy(dstImg[j]-offset_x, wBufSrc, size_x_padded * sizeof(imgpel));
  }
  
  for (j = 0; j < size_y; j++)
  {
    wBufDst = dstImg[j]-offset_x; // 4:4:4 independent mode
    wBufSrc = dstImg[j];
    // left IMG_PAD_SIZE
    for (i = 0; i < offset_x; i++)
      *(wBufDst++) = wBufSrc[0];
    wBufDst += size_x;
    // right IMG_PAD_SIZE
    for (i = 0; i < offset_x; i++)
      *(wBufDst++) = wBufSrc[size_x_minus1];
  }
  
  // Replicate bottom pad lines
  wBufSrc = dstImg[size_y-1]-offset_x;
  for (j = size_y; j < size_y_padded-offset_y; j++)
  {
    memcpy(dstImg[j]-offset_x, wBufSrc, size_x_padded * sizeof(imgpel));
  }
}



void GetHMEIntImagesLuma( VideoParameters *p_Vid, int size_x, int size_y, imgpel ***cImgInt)
{
  int iLevel, iWidth, iHeight;
  int iPyramidLevels = p_Vid->pHMEInfo->iPyramidLevels;
  //// INTEGER PEL POSITIONS ////
  for(iLevel=0; iLevel<iPyramidLevels; iLevel++)
  {
    iWidth = size_x>>iLevel;
    iHeight = size_y>>iLevel;
    // simply copy the integer pels
    fillHMEIntImageMargin(cImgInt[iLevel], iWidth, iHeight, IMG_PAD_SIZE_X, IMG_PAD_SIZE_Y);
  }
}
