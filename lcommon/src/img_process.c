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
* \file img_process.c
*
* \brief
*    Input data Image Processing functions
*
* \author
*    Main contributors (see contributors.h for copyright, address and affiliation details)
*      - Alexis Michael Tourapis <alexis.tourapis@dolby.com>
*
*************************************************************************************
*/

#include "contributors.h"
#include "global.h"
#include "img_process.h"
#include "io_image.h"
#include "memalloc.h"
#include "fast_memory.h"

static inline void ResetImage(ImageData *imgOut)
{
  fast_memset(imgOut->frm_data[0][0], 0, imgOut->format.height[0] * imgOut->format.width[0] * sizeof (imgpel));

  if (imgOut->format.yuv_format != YUV400)
  {
    if (sizeof(imgpel) == sizeof(char))
    {
      fast_memset(imgOut->frm_data[1][0], 128, imgOut->format.height[1] * imgOut->format.width[1] * sizeof (imgpel));
      fast_memset(imgOut->frm_data[2][0], 128, imgOut->format.height[2] * imgOut->format.width[2] * sizeof (imgpel));
    }
    else
    {
      int i, j, k;
      imgpel med_value;
      for (k = 1; k <=2; k++)
      {
        med_value = (imgpel) (imgOut->format.max_value[k] + 1) >> 1;
        for (j = 0; j < imgOut->format.height[k]; j++)
        {
          for (i = 0; i < imgOut->format.width[k]; i++)
          {
            imgOut->frm_data[k][j][i] = med_value;
          }
        }
      }
    }
  }
}


static inline void CPImage(ImageData *imgOut, ImageData *imgIn)
{
  memcpy(imgOut->frm_data[0][0], imgIn->frm_data[0][0], imgIn->format.height[0] * imgIn->format.width[0] * sizeof (imgpel));

  if (imgIn->format.yuv_format != YUV400)
  {
    memcpy(imgOut->frm_data[1][0], imgIn->frm_data[1][0], imgIn->format.height[1] * imgIn->format.width[1] * sizeof (imgpel));
    memcpy(imgOut->frm_data[2][0], imgIn->frm_data[2][0], imgIn->format.height[2] * imgIn->format.width[2] * sizeof (imgpel));
  }
}

// to be modified
static inline void FilterImage(ImageData *imgOut, ImageData *imgIn)
{
  memcpy(imgOut->frm_data[0][0], imgIn->frm_data[0][0], imgIn->format.height[0] * imgIn->format.width[0] * sizeof (imgpel));

  if (imgIn->format.yuv_format != YUV400)
  {
    memcpy(imgOut->frm_data[1][0], imgIn->frm_data[1][0], imgIn->format.height[1] * imgIn->format.width[1] * sizeof (imgpel));
    memcpy(imgOut->frm_data[2][0], imgIn->frm_data[2][0], imgIn->format.height[2] * imgIn->format.width[2] * sizeof (imgpel));
  }
}

// Line interleaving for 3:2 pulldown
static inline void BlendImageLines(ImageData *imgIn0, ImageData *imgIn1)
{
  int j;
  for (j = 1; j < imgIn1->format.height[0]; j += 2)
    memcpy(imgIn0->frm_data[0][j], imgIn1->frm_data[0][j], imgIn1->format.width[0] * sizeof (imgpel));

  if (imgIn1->format.yuv_format != YUV400)
  {
    for (j = 1; j < imgIn1->format.height[1]; j += 2)
    {
      memcpy(imgIn0->frm_data[1][j], imgIn1->frm_data[1][j], imgIn1->format.width[1] * sizeof (imgpel));
    }
    for (j = 1; j < imgIn1->format.height[2]; j += 2)
    {
      memcpy(imgIn0->frm_data[2][j], imgIn1->frm_data[2][j], imgIn1->format.width[2] * sizeof (imgpel));
    }
  }
}

// to be modified
static inline void FilterImageSep(ImageData *imgOut, ImageData *imgIn)
{
  int i, j;
  static const int SepFilter[6] = {1, -5, 20, 20, -5, 1};
  int max_width  = imgOut->format.width[0] - 1;
  int max_height = imgOut->format.height[0] - 1;

  int **temp_data = new_mem2Dint(imgIn->format.height[0], imgIn->format.width[0]); // temp memory for filtering. Could be allocated once to speed up code
  imgpel *frm_data = NULL;

  // implementation was not optimized. only just implemented as proof of concept
  // horizontal filtering
  for (j = 0; j < imgOut->format.height[0]; j++)
  {
    frm_data = imgIn->frm_data[0][j];
    for (i = 0; i < imgOut->format.width[0]; i++)
    {
      temp_data[j][i] = 
        SepFilter[0] * frm_data[iClip3(0, max_width, i - 2)] +
        SepFilter[1] * frm_data[iClip3(0, max_width, i - 1)] +
        SepFilter[2] * frm_data[iClip3(0, max_width, i    )] +
        SepFilter[3] * frm_data[iClip3(0, max_width, i + 1)] +
        SepFilter[4] * frm_data[iClip3(0, max_width, i + 2)] +
        SepFilter[5] * frm_data[iClip3(0, max_width, i + 3)];
    }
  }

  for (j = 0; j < imgOut->format.height[0]; j++)
  {
    frm_data = imgOut->frm_data[0][j];
    for (i = 0; i < imgOut->format.width[0]; i++)
    {
      frm_data[i] = (imgpel) iClip3(0, imgOut->format.max_value[0], rshift_rnd_sign(
        SepFilter[0] * temp_data[iClip3(0, max_height, j - 2)][i] +
        SepFilter[1] * temp_data[iClip3(0, max_height, j - 1)][i] +
        SepFilter[2] * temp_data[iClip3(0, max_height, j    )][i] +
        SepFilter[3] * temp_data[iClip3(0, max_height, j + 1)][i] +
        SepFilter[4] * temp_data[iClip3(0, max_height, j + 2)][i] +
        SepFilter[5] * temp_data[iClip3(0, max_height, j + 3)][i], 10));
    }
  }

  if (imgOut->format.yuv_format != YUV400)
  {
    int k;

    for (k = 1; k <=2; k++)
    {
      max_width  = imgOut->format.width[k] - 1;
      max_height = imgOut->format.height[k] - 1;

      // horizontal filtering
      for (j = 0; j < imgOut->format.height[k]; j++)
      {
        frm_data = imgIn->frm_data[k][j];
        for (i = 0; i < imgOut->format.width[k]; i++)
        {
          temp_data[j][i] = 
            SepFilter[0] * frm_data[iClip3(0, max_width, i - 2)] +
            SepFilter[1] * frm_data[iClip3(0, max_width, i - 1)] +
            SepFilter[2] * frm_data[iClip3(0, max_width, i    )] +
            SepFilter[3] * frm_data[iClip3(0, max_width, i + 1)] +
            SepFilter[4] * frm_data[iClip3(0, max_width, i + 2)] +
            SepFilter[5] * frm_data[iClip3(0, max_width, i + 3)];
        }
      }

      for (j = 0; j < imgOut->format.height[k]; j++)
      {
        frm_data = imgOut->frm_data[k][j];
        for (i = 0; i < imgOut->format.width[k]; i++)
        {
          frm_data[i] = (imgpel) iClip3(0, imgOut->format.max_value[k], rshift_rnd_sign(
            SepFilter[0] * temp_data[iClip3(0, max_height, j - 2)][i] +
            SepFilter[1] * temp_data[iClip3(0, max_height, j - 1)][i] +
            SepFilter[2] * temp_data[iClip3(0, max_height, j    )][i] +
            SepFilter[3] * temp_data[iClip3(0, max_height, j + 1)][i] +
            SepFilter[4] * temp_data[iClip3(0, max_height, j + 2)][i] +
            SepFilter[5] * temp_data[iClip3(0, max_height, j + 3)][i], 10));
        }
      }
    }
  }

  free_mem2Dint(temp_data);
}


// to be modified
static inline void MuxImages(ImageData *imgOut, ImageData *imgIn0, ImageData *imgIn1, ImageData *Map)
{
  int i, j;
  for (j = 0; j < imgOut->format.height[0]; j++)
  {
    for (i = 0; i < imgOut->format.width[0]; i++)
    {
      imgOut->frm_data[0][j][i] = (imgpel) rshift_rnd_sf(imgIn0->frm_data[0][j][i] * (Map->format.max_value[0] - Map->frm_data[0][j][i]) + imgIn1->frm_data[0][j][i] * Map->frm_data[0][j][i], Map->format.bit_depth[0]);
    }
  }
  
  if (imgOut->format.yuv_format != YUV400)
  {
    int k;
    for (k = 1; k <=2; k++)
    {
      for (j = 0; j < imgOut->format.height[k]; j++)
      {
        for (i = 0; i < imgOut->format.width[k]; i++)
        {
          imgOut->frm_data[k][j][i] = (imgpel) rshift_rnd_sf(imgIn0->frm_data[k][j][i] * (Map->format.max_value[k] - Map->frm_data[k][j][i]) + imgIn1->frm_data[k][j][i] * Map->frm_data[k][j][i], Map->format.bit_depth[k]);
        }
      }
    }
  }
}

static inline void YV12toYUV(ImageData *imgOut, ImageData *imgIn)
{
  memcpy(imgOut->frm_data[0][0], imgIn->frm_data[0][0], imgIn->format.height[0] * imgIn->format.width[0] * sizeof (imgpel));

  if (imgIn->format.yuv_format != YUV400)
  {
    memcpy(imgOut->frm_data[1][0], imgIn->frm_data[2][0], imgIn->format.height[1] * imgIn->format.width[1] * sizeof (imgpel));
    memcpy(imgOut->frm_data[2][0], imgIn->frm_data[1][0], imgIn->format.height[2] * imgIn->format.width[2] * sizeof (imgpel));
  }
}

void process_image( VideoParameters *p_Vid, InputParameters *p_Inp )
{
  switch( p_Inp->ProcessInput )
  {
  default:
  case 0:
    CPImage(&p_Vid->imgData, &p_Vid->imgData0);
    if (p_Inp->enable_32_pulldown)
      BlendImageLines(&p_Vid->imgData, &p_Vid->imgData4);
    break;
  case 1:
    FilterImage(&p_Vid->imgData, &p_Vid->imgData0);
    if (p_Inp->enable_32_pulldown)
    {
      FilterImage(&p_Vid->imgData32, &p_Vid->imgData4);
      BlendImageLines(&p_Vid->imgData, &p_Vid->imgData32);
    }
    break;
  case 2:
    YV12toYUV(&p_Vid->imgData, &p_Vid->imgData0);
    if (p_Inp->enable_32_pulldown)
    {
      YV12toYUV(&p_Vid->imgData32, &p_Vid->imgData4);
      BlendImageLines(&p_Vid->imgData, &p_Vid->imgData32);
    }
    break;
  case 3:
    MuxImages(&p_Vid->imgData, &p_Vid->imgData0, &p_Vid->imgData1, &p_Vid->imgData2);
    if (p_Inp->enable_32_pulldown)
    {
      MuxImages(&p_Vid->imgData32, &p_Vid->imgData4, &p_Vid->imgData5, &p_Vid->imgData6);
      BlendImageLines(&p_Vid->imgData, &p_Vid->imgData32);
    }

    break;
  case 4:
    FilterImageSep(&p_Vid->imgData, &p_Vid->imgData0);
    if (p_Inp->enable_32_pulldown)
    {
      FilterImageSep(&p_Vid->imgData, &p_Vid->imgData4);
      BlendImageLines(&p_Vid->imgData, &p_Vid->imgData32);
    }

    break;
  }
}



