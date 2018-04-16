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
 ***********************************************************************
 * \file
 *    dec_statistics.c
 * \brief
 *    Decoder statistics handling.
 * \author
 *  Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Alexis Michael Tourapis <alexismt@ieee.org>
 ***********************************************************************
 */

#include "global.h"
#include "dec_statistics.h"
#include "memalloc.h"

/*!
 ***********************************************************************
 * \brief
 *    allocates and initializes decoder statistics memory
 * \param stats
 *    Decoder statistics
 * \return
 ***********************************************************************
 */
void init_dec_stats(DecStatParameters *stats)
{ 
  int i, j;
  int64 *hist;
  for (i = 0; i < NUM_SLICE_TYPES; i++)
  {
    stats->frame_ctr[i] = 0;
    for (j = 0; j < MAXMODE; j++)
    {
      stats->mode_use          [i][j]    = 0; 
      stats->mode_use_transform[i][j][0] = 0;
      stats->mode_use_transform[i][j][1] = 0;
    }
  }

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      if ((hist = (int64 *) malloc (4096 * sizeof (int64)))== NULL)
        no_mem_exit ("init_dec_stats: stats->histogram_mv");
      memset(hist, 0, 4096 * sizeof (int64));
      stats->histogram_mv[i][j] = hist + 2048;
    }
    if ((hist = (int64 *) malloc (17 * sizeof (int64)))== NULL)
      no_mem_exit ("init_dec_stats: stats->histogram_refs");
    memset(hist, 0, 17 * sizeof (int64));
    stats->histogram_refs[i] = hist + 1;
  }
}

void delete_dec_stats(DecStatParameters *stats)
{ 
  int i, j;

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      stats->histogram_mv[i][j] -= 2048;
      free(stats->histogram_mv[i][j]);
    }
    stats->histogram_refs[i] -= 1;
    free(stats->histogram_refs[i]);
  }
}
