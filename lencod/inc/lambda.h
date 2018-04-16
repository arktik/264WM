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
 *    lambda.h
 *
 * \date
 *    13 September 2009
 *
 * \brief
 *    Headerfile for lagrangian lambda related computations
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Alexis Michael Tourapis         <alexismt@ieee.org> 

 **************************************************************************
 */

#ifndef _LAMBDA_H_
#define _LAMBDA_H_

#include "global.h"

extern void get_implicit_lambda_p_slice (Slice *currSlice);
extern void get_implicit_lambda_b_slice (Slice *currSlice);
extern void get_implicit_lambda_i_slice (Slice *currSlice);
extern void get_implicit_lambda_sp_slice(Slice *currSlice);
extern void get_explicit_lambda         (Slice *currSlice);
extern void get_fixed_lambda            (Slice *currSlice);
extern void set_rdoq_lambda             (Slice *currSlice);

#endif
