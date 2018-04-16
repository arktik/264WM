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
 * \file quant8x8_normal.c
 *
 * \brief
 *    Quantization process for a 8x8 block without any adaptation
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Alexis Michael Tourapis                  <alexismt@ieee.org>
 *
 *************************************************************************************
 */

#include "contributors.h"

#include <math.h>

#include "global.h"

#include "image.h"
#include "mb_access.h"
#include "vlc.h"
#include "transform.h"
#include "mc_prediction.h"
#include "q_offsets.h"
#include "q_matrix.h"
#include "quant8x8.h"


/*!
 ************************************************************************
 * \brief
 *    Quantization process for All coefficients for a 8x8 block
 *
 * \par Input:
 *
 * \par Output:
 *
 ************************************************************************
 */
int quant_8x8_normal(Macroblock *currMB, int **tblock, struct quant_methods *q_method)
{
  VideoParameters *p_Vid = currMB->p_Vid;
  QuantParameters *p_Quant = p_Vid->p_Quant;
  int block_x = q_method->block_x;
  int*  ACLevel = q_method->ACLevel;
  int*  ACRun   = q_method->ACRun;
  int  qp = q_method->qp;
  LevelQuantParams **q_params_8x8 = q_method->q_params;
  const byte (*pos_scan)[2] = q_method->pos_scan;
  const byte *c_cost = q_method->c_cost;
  int *coeff_cost = q_method->coeff_cost;

  int i,j, coeff_ctr;

  int *m7;
  int scaled_coeff;

  int   level, run = 0;
  int   nonzero = FALSE;
  int   qp_per = p_Quant->qp_per_matrix[qp];
  int   q_bits = Q_BITS_8 + qp_per;
  const byte *p_scan = &pos_scan[0][0];
  int*  ACL = &ACLevel[0];
  int*  ACR = &ACRun[0];

  // Quantization
  for (coeff_ctr = 0; coeff_ctr < 64; coeff_ctr++)
  {
    i = *p_scan++;  // horizontal position
    j = *p_scan++;  // vertical position

    m7 = &tblock[j][block_x + i];
    if (*m7 != 0)
    {
      scaled_coeff = iabs (*m7) * q_params_8x8[j][i].ScaleComp;
      level = (scaled_coeff + q_params_8x8[j][i].OffsetComp) >> q_bits;

      if (level != 0)
      {
        nonzero = TRUE;

        *coeff_cost += (level > 1) ? MAX_VALUE : c_cost[run];

        level  = isignab(level, *m7);
        *m7    = rshift_rnd_sf(((level * q_params_8x8[j][i].InvScaleComp) << qp_per), 6);
        *ACL++ = level;
        *ACR++ = run; 
        // reset zero level counter
        run    = 0;
      }
      else
      {
        run++;
        *m7 = 0;
      }
    }
    else
    {
      run++;
    }
  }

  *ACL = 0;

  return nonzero;
}

/*!
 ************************************************************************
 * \brief
 *    Quantization process for All coefficients for a 8x8 block 
 *    CAVLC version
 *
 * \par Input:
 *
 * \par Output:
 *
 ************************************************************************
 */
int quant_8x8cavlc_normal(Macroblock *currMB, int **tblock, struct quant_methods *q_method, int***  cofAC)
{
  QuantParameters *p_Quant = currMB->p_Vid->p_Quant;
  int block_x = q_method->block_x;

  int  qp = q_method->qp;
  LevelQuantParams **q_params_8x8 = q_method->q_params;
  const byte (*pos_scan)[2] = q_method->pos_scan;
  const byte *c_cost = q_method->c_cost;
  int *coeff_cost = q_method->coeff_cost;  


  int i,j, k, coeff_ctr;

  int *m7;
  int scaled_coeff;  

  int level, runs[4] = { 0 };
  int nonzero = FALSE; 
  int qp_per = p_Quant->qp_per_matrix[qp];  
  int q_bits = Q_BITS_8 + qp_per;
  const byte *p_scan = &pos_scan[0][0];
  int*  ACL[4];  
  int*  ACR[4];

  for (k = 0; k < 4; k++)
  {
    ACL[k] = &cofAC[k][0][0];
    ACR[k] = &cofAC[k][1][0];
  }

  // Quantization
  for (k = 0; k < 4; k++)
  {
    for (coeff_ctr = 0; coeff_ctr < 16; coeff_ctr++)
    {
      i = *p_scan++;  // horizontal position
      j = *p_scan++;  // vertical position

      m7 = &tblock[j][block_x + i];
      if (*m7 != 0)
      {
      scaled_coeff = iabs (*m7) * q_params_8x8[j][i].ScaleComp;
      level = (scaled_coeff + q_params_8x8[j][i].OffsetComp) >> q_bits;

      if (level != 0)
      {
        level = imin(level, CAVLC_LEVEL_LIMIT);

        nonzero=TRUE;

        *coeff_cost += (level > 1) ? MAX_VALUE : c_cost[runs[k]];

        level  = isignab(level, *m7);
        *m7    = rshift_rnd_sf(((level * q_params_8x8[j][i].InvScaleComp) << qp_per), 6);

        *(ACL[k])++ = level;
        *(ACR[k])++ = runs[k];
        // reset zero level counter
        runs[k] = 0;
      }
      else
      {        
          runs[k]++;
          *m7 = 0;      
        }
      }
      else
      {
        runs[k]++;
      }
    }
  }

  for(k = 0; k < 4; k++)
    *(ACL[k]) = 0;

  return nonzero;
}

