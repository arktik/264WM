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
 * \file quant8x8.c
 *
 * \brief
 *    Quantization process for a 8x8 block
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
#include "quant8x8.h"


/*!
************************************************************************
* \brief
*    Quantization initialization function
*
************************************************************************
*/
void init_quant_8x8(Slice *currSlice)
{
  VideoParameters *p_Vid  = currSlice->p_Vid; 
  // We may wish to have all these parameters switched at the slice level for speed up.
  if (currSlice->UseRDOQuant == 1)
  {
    currSlice->quant_8x8 = quant_8x8_trellis;
    currSlice->quant_8x8cavlc = quant_8x8cavlc_trellis;
  }
  else if (p_Vid->AdaptiveRounding)
  {
    currSlice->quant_8x8 = quant_8x8_around;
    currSlice->quant_8x8cavlc = quant_8x8cavlc_around;
  }
  else
  {
    currSlice->quant_8x8 = quant_8x8_normal;
    currSlice->quant_8x8cavlc = quant_8x8cavlc_normal;
  }
}

