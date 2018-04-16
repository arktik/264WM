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
 ************************************************************************
 * \file
 *     me_fullfast.h
 *
 * \author
 *    Alexis Michael Tourapis        <alexis.tourapis@dolby.com>
 *
 * \date
 *    9 September 2006
 *
 * \brief
 *    Headerfile for Fast Full Search motion estimation
 **************************************************************************
 */


#ifndef _ME_FULLFAST_H_
#define _ME_FULLFAST_H_
typedef struct me_full_fast
{
  int          **search_setup_done;     //!< flag if all block SAD's have been calculated yet
  MotionVector **search_center; //!< absolute search center for fast full motion search
  MotionVector **search_center_padded; //!< absolute search center for fast full motion search
  int          **pos_00;             //!< position of (0,0) vector
  distpel   *****BlockSAD;        //!< SAD for all blocksize, ref. frames and motion vectors
  int          **max_search_range;
} MEFullFast;

extern distblk fast_full_search_motion_estimation ( Macroblock *, MotionVector *, MEBlock *, distblk, int );
extern void    initialize_fast_full_search        ( VideoParameters *, InputParameters * );
extern void    reset_fast_full_search             ( VideoParameters * );
extern void    clear_fast_full_search             ( VideoParameters * );
extern void    setup_fast_full_search             ( Macroblock *, MEBlock *, int );
extern void    update_full_search_large_blocks    ( MEFullFast *, int, int, int );

#endif

