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
 *
 * \file transform.h
 *
 * \brief
 *    prototypes of transform functions
 *
 * \date
 *    10 July 2007
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    Alexis Michael Tourapis
 **************************************************************************/

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

extern void forward4x4   (int **block , int **tblock, int pos_y, int pos_x);
extern void inverse4x4   (int **tblock, int **block , int pos_y, int pos_x);
extern void forward8x8   (int **block , int **tblock, int pos_y, int pos_x);
extern void inverse8x8   (int **tblock, int **block , int pos_x);
extern void hadamard4x4  (int **block , int **tblock);
extern void ihadamard4x4 (int **tblock, int **block);
extern void hadamard4x2  (int **block , int **tblock);
extern void ihadamard4x2 (int **tblock, int **block);
extern void hadamard2x2  (int **block , int tblock[4]);
extern void ihadamard2x2 (int block[4], int tblock[4]);

#endif //_TRANSFORM_H_
