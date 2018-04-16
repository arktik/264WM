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
 * \file io_raw.h
 *
 * \brief
 *    I/O functions related to raw images
 *
 * \author
 *     - Alexis Michael Tourapis         <alexismt@ieee.org>
 *
 ************************************************************************
 */

#ifndef _IO_RAW_H_
#define _IO_RAW_H_

extern int ReadFrameConcatenated  (InputParameters *p_Inp, VideoDataFile *input_file, int FrameNoInFile, int HeaderSize, FrameFormat *source, unsigned char *buf);
extern int ReadFrameSeparate      (InputParameters *p_Inp, VideoDataFile *input_file, int FrameNoInFile, int HeaderSize, FrameFormat *source, unsigned char *buf);

#endif

