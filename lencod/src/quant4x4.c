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
 * \file quant4x4.c
 *
 * \brief
 *    Quantization process for a 4x4 block
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Alexis Michael Tourapis                  <alexismt@ieee.org>
 *
 *************************************************************************************
 */

#include "contributors.h"
#include "global.h"
#include "quant4x4.h"

/*!
************************************************************************
* \brief
*    Quantization initialization function
*
************************************************************************
*/
void init_quant_4x4(Slice *currSlice)
{
  VideoParameters *p_Vid = currSlice->p_Vid;
  InputParameters *p_Inp = currSlice->p_Inp;

  if (currSlice->UseRDOQuant == 1)
  {
    currSlice->quant_4x4     = quant_4x4_trellis;
    if (p_Inp->RDOQ_DC == 1)
      currSlice->quant_dc4x4 = quant_dc4x4_trellis;
    else
      currSlice->quant_dc4x4 = quant_dc4x4_normal;
    currSlice->quant_ac4x4   = quant_ac4x4_trellis;
    if (currSlice->symbol_mode == CAVLC)
    {
      currSlice->rdoq_4x4   = rdoq_4x4_CAVLC;
      currSlice->rdoq_dc    = rdoq_dc_CAVLC;
      currSlice->rdoq_ac4x4 = rdoq_ac4x4_CAVLC;
    }
    else
    {
      currSlice->rdoq_4x4   = rdoq_4x4_CABAC;
      currSlice->rdoq_dc    = rdoq_dc_CABAC;
      currSlice->rdoq_ac4x4 = rdoq_ac4x4_CABAC;
    }
  }
  else if (p_Vid->AdaptiveRounding)
  {
    currSlice->quant_4x4     = quant_4x4_around;
    currSlice->quant_dc4x4   = quant_dc4x4_normal;
    currSlice->quant_ac4x4   = quant_ac4x4_around;
  }
  else
  {
    currSlice->quant_4x4   = quant_4x4_normal;
    currSlice->quant_dc4x4 = quant_dc4x4_normal;
    currSlice->quant_ac4x4 = quant_ac4x4_normal;
  }
}

