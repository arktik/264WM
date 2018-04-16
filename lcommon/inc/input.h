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
 * \file input.h
 *
 * \brief
 *    Input related definitions
 *
 * \author
 *
 ************************************************************************
 */

#ifndef _INPUT_H_
#define _INPUT_H_

extern int testEndian(void);
extern void initInput(VideoParameters *p_Vid, FrameFormat *source, FrameFormat *output);
extern void AllocateFrameMemory (VideoParameters *p_Vid, InputParameters *p_Inp, FrameFormat *source);
extern void DeleteFrameMemory (VideoParameters *p_Vid);

extern int  read_one_frame (VideoParameters *p_Vid, VideoDataFile *input_file, int FrameNoInFile, int HeaderSize, FrameFormat *source, FrameFormat *output, imgpel **pImage[3]);
extern void pad_borders    ( FrameFormat output, int img_size_x, int img_size_y, int img_size_x_cr, int img_size_y_cr, imgpel **pImage[3]);

#endif

