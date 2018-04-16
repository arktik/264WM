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
 * \file img_dist_ssim.c
 *
 * \brief
 *    Compute structural similarity (SSIM) index using the encoded image and the reference image
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Woo-Shik Kim                    <wooshik.kim@usc.edu>
 *     - Zhen Li                         <zli@dolby.com> 
 *     - Alexis Michael Tourapis         <alexismt@ieee.org>
 *************************************************************************************
 */
#include "contributors.h"
#include "global.h"
#include "img_distortion.h"
#include "enc_statistics.h"

//#define UNBIASED_VARIANCE // unbiased estimation of the variance

float compute_ssim (VideoParameters *p_Vid, InputParameters *p_Inp, imgpel **refImg, imgpel **encImg, int height, int width, int win_height, int win_width, int comp)
{

  static const float K1 = 0.01f, K2 = 0.03f;
  float max_pix_value_sqd;
  float C1, C2;
  float win_pixels = (float) (win_width * win_height);
#ifdef UNBIASED_VARIANCE
  float win_pixels_bias = win_pixels - 1;
#else
  float win_pixels_bias = win_pixels;
#endif
  float mb_ssim, meanOrg, meanEnc;
  float varOrg, varEnc, covOrgEnc;
  int imeanOrg, imeanEnc, ivarOrg, ivarEnc, icovOrgEnc;
  float cur_distortion = 0.0;
  int i, j, n, m, win_cnt = 0;
  int overlapSize = p_Inp->SSIMOverlapSize;

  max_pix_value_sqd = (float) (p_Vid->max_pel_value_comp[comp] * p_Vid->max_pel_value_comp[comp]);
  C1 = K1 * K1 * max_pix_value_sqd;
  C2 = K2 * K2 * max_pix_value_sqd;

  for (j = 0; j <= height - win_height; j += overlapSize)
  {
    for (i = 0; i <= width - win_width; i += overlapSize)
    {
      imeanOrg = 0;
      imeanEnc = 0; 
      ivarOrg  = 0;
      ivarEnc  = 0;
      icovOrgEnc = 0;

      for ( n = j;n < j + win_height;n ++)
      {
        for (m = i;m < i + win_width;m ++)
        {
          imeanOrg   += refImg[n][m];
          imeanEnc   += encImg[n][m];
          ivarOrg    += refImg[n][m] * refImg[n][m];
          ivarEnc    += encImg[n][m] * encImg[n][m];
          icovOrgEnc += refImg[n][m] * encImg[n][m];
        }
      }

      meanOrg = (float) imeanOrg / win_pixels;
      meanEnc = (float) imeanEnc / win_pixels;

      varOrg    = ((float) ivarOrg - ((float) imeanOrg) * meanOrg) / win_pixels_bias;
      varEnc    = ((float) ivarEnc - ((float) imeanEnc) * meanEnc) / win_pixels_bias;
      covOrgEnc = ((float) icovOrgEnc - ((float) imeanOrg) * meanEnc) / win_pixels_bias;

      mb_ssim  = (float) ((2.0 * meanOrg * meanEnc + C1) * (2.0 * covOrgEnc + C2));
      mb_ssim /= (float) (meanOrg * meanOrg + meanEnc * meanEnc + C1) * (varOrg + varEnc + C2);

      cur_distortion += mb_ssim;
      win_cnt++;
    }
  }

  cur_distortion /= (float) win_cnt;

  if (cur_distortion >= 1.0 && cur_distortion < 1.01) // avoid float accuracy problem at very low QP(e.g.2)
    cur_distortion = 1.0;

  return cur_distortion;
}

/*!
 ************************************************************************
 * \brief
 *    Find SSIM for all three components
 ************************************************************************
 */
void find_ssim (VideoParameters *p_Vid, InputParameters *p_Inp, ImageStructure *ref, ImageStructure *src, DistMetric *metricSSIM)
{
  DistortionParams *p_Dist = p_Vid->p_Dist;
  FrameFormat *format = &ref->format;

  metricSSIM->value[0] = compute_ssim (p_Vid, p_Inp, ref->data[0], src->data[0], format->height[0], format->width[0], BLOCK_SIZE_8x8, BLOCK_SIZE_8x8, 0);
  // Chroma.
  if (format->yuv_format != YUV400)
  {     
    metricSSIM->value[1]  = compute_ssim (p_Vid, p_Inp, ref->data[1], src->data[1], format->height[1], format->width[1], p_Vid->mb_cr_size_y, p_Vid->mb_cr_size_x, 1);
    metricSSIM->value[2]  = compute_ssim (p_Vid, p_Inp, ref->data[2], src->data[2], format->height[1], format->width[1], p_Vid->mb_cr_size_y, p_Vid->mb_cr_size_x, 2);
  }

  {
    accumulate_average(metricSSIM,  p_Dist->frame_ctr);
    accumulate_avslice(metricSSIM,  p_Vid->type, p_Vid->p_Stats->frame_ctr[p_Vid->type]);
  }
}

