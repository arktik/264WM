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
 * \file quantChroma_normal.c
 *
 * \brief
 *    Quantization process for a Chroma block
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
#include "q_matrix.h"
#include "quant4x4.h"
#include "quantChroma.h"


/*!
 ************************************************************************
 * \brief
 *    Quantization process for All coefficients for a 2x2 DC block
 *
 * \par Input:
 *
 * \par Output:
 *
 ************************************************************************
 */
int quant_dc2x2_normal(Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                       LevelQuantParams *q_params_4x4, int **fadjust, const byte (*pos_scan)[2])
{
  QuantParameters *p_Quant = currMB->p_Vid->p_Quant;
  Boolean is_cavlc = (Boolean) (currMB->p_Slice->symbol_mode == CAVLC);
  int coeff_ctr;

  int *m7;
  int scaled_coeff;

  int   level, run = 0;
  int   nonzero = FALSE;  
  int   qp_per = p_Quant->qp_per_matrix[qp];
  int   q_bits = Q_BITS + qp_per + 1;
  //const byte *p_scan = &pos_scan[0][0];
  int*  DCL = &DCLevel[0];
  int*  DCR = &DCRun[0];

  m7 = *tblock;

  // Quantization
  for (coeff_ctr=0; coeff_ctr < 4; coeff_ctr++)
  {
    // we need to update q_params_4x4->OffsetComp to a 4x1 array that would contain offset info for 
    // every 2x2 DC position
    if (*m7)
    {
      scaled_coeff = iabs (*m7) * q_params_4x4->ScaleComp;
      level = (scaled_coeff + (q_params_4x4->OffsetComp << 1) ) >> q_bits;

      if (level  != 0)
      {
        if (is_cavlc)
          level = imin(level, CAVLC_LEVEL_LIMIT);

        level = isignab(level, *m7);

        *m7++ = ((level * q_params_4x4->InvScaleComp) << qp_per);

        *DCL++ = level;
        *DCR++ = run;
        run    = 0;
        nonzero = TRUE;
      }
      else
      {
        run++;
        *m7++ = 0;
      }
    }
    else
    {
      run++;
      m7++;
    }
  }

  *DCL = 0;

  return nonzero;
}

/*!
 ************************************************************************
 * \brief
 *    Quantization process for All coefficients for a 2x2 DC block
 *
 * \par Input:
 *
 * \par Output:
 *
 ************************************************************************
 */
int quant_dc4x2_normal(Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                       LevelQuantParams *q_params_4x4, int **fadjust, const byte (*pos_scan)[2])
{
  QuantParameters *p_Quant = currMB->p_Vid->p_Quant;
  Boolean is_cavlc = (Boolean) (currMB->p_Slice->symbol_mode == CAVLC);
  int i,j, coeff_ctr;

  int *m7;
  int scaled_coeff;

  int   level, run = 0;
  int   nonzero = FALSE;  
  int   qp_per = p_Quant->qp_per_matrix[qp];
  int   q_bits = Q_BITS + qp_per + 1;
  const byte *p_scan = &pos_scan[0][0];
  int*  DCL = &DCLevel[0];
  int*  DCR = &DCRun[0];

  // Quantization
  for (coeff_ctr = 0; coeff_ctr < 8; coeff_ctr++)
  {
    j = *p_scan++;  // note that in this part, somehow coefficients were transposed from 2x4 to 4x2.
    i = *p_scan++;  

    m7 = &tblock[j][i];

    if (*m7 != 0)
    {
      scaled_coeff = iabs (*m7) * q_params_4x4->ScaleComp;
      level = (scaled_coeff + (q_params_4x4->OffsetComp << 1) ) >> q_bits;

      if (level  != 0)
      {
        if (is_cavlc)
          level = imin(level, CAVLC_LEVEL_LIMIT);
        level = isignab(level, *m7);

        *m7 = ((level * q_params_4x4->InvScaleComp) << qp_per);

        *DCL++ = level;
        *DCR++ = run;
        // reset zero level counter
        run    = 0;
        nonzero = TRUE;
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

  *DCL = 0;

  return nonzero;
}



