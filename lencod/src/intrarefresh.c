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
 *****************************************************************************
 *
 * \file intrarefresh.c
 *
 * \brief
 *    Encoder support for pseudo-random intra macroblock refresh
 *
 * \date
 *    16 June 2002
 *
 * \author
 *    Stephan Wenger   stewe@cs.tu-berlin.de
 *****************************************************************************/

#include "global.h"


/*!
 ************************************************************************
 * \brief
 *    RandomIntraInit: Initializes Random Intra module.  Should be called
 *    only after initialization (or changes) of the picture size or the
 *    random intra refresh value.  In version jm2.1 it is impossible to
 *    change those values on-the-fly, hence RandomIntraInit should be
 *    called immediately after the parsing of the config file
 *
 * \par Input:
 *    xsize, ysize: size of the picture (in MBs)
 *    refresh     : refresh rate in MBs per picture
 ************************************************************************
 */
void RandomIntraInit(VideoParameters *p_Vid, int xsize, int ysize, int refresh)
{
  int i, pos;

  srand (1);      // A fixed random initializer to make things reproducible
  p_Vid->NumberOfMBs = xsize * ysize;
  p_Vid->NumberIntraPerPicture = refresh;

  if (refresh != 0)
  {
    p_Vid->RefreshPattern = malloc (sizeof (int) * p_Vid->NumberOfMBs);
    if (p_Vid->RefreshPattern == NULL) no_mem_exit("RandomIntraInit: p_Vid->RefreshPattern");

    p_Vid->IntraMBs = malloc (sizeof (int) * refresh);
    if (p_Vid->IntraMBs == NULL) no_mem_exit("RandomIntraInit: p_Vid->IntraMBs");

    for (i= 0; i<p_Vid->NumberOfMBs; i++)
      p_Vid->RefreshPattern[i] = -1;

    for (i=0; i<p_Vid->NumberOfMBs; i++)
    {
      do
      {
        pos = rand() % p_Vid->NumberOfMBs;
      } while (p_Vid->RefreshPattern [pos] != -1);
      p_Vid->RefreshPattern [pos] = i;
    }
    /*
    for (i=0; i<p_Vid->NumberOfMBs; i++) printf ("%d\t", p_Vid->RefreshPattern[i]);
    getchar();
    */
  }
  else
  {
    p_Vid->RefreshPattern = NULL;
    p_Vid->IntraMBs = NULL;
  }
}

/*!
 ************************************************************************
 * \brief
 *    RandomIntra: Code an MB as Intra?
 *
 * \par Input
 *    MacroblockNumberInScanOrder
 * \par Output
 *    1 if an MB should be forced to Intra, according the the
 *      RefreshPattern
 *    0 otherwise
 *
 ************************************************************************
 */
int RandomIntra (VideoParameters *p_Vid, int mb)
{
  int i;

  for (i=0; i<p_Vid->NumberIntraPerPicture; i++)
    if (p_Vid->IntraMBs[i] == mb)
      return 1;
  return 0;
}


/*!
 ************************************************************************
 * \brief
 *    RandomIntraNewPicture: Selects new set of MBs for forced Intra
 *
 * \par
 *    This function should be called exactly once per picture, and
 *    requires a finished initialization
 *
 ************************************************************************
 */
void RandomIntraNewPicture (VideoParameters *p_Vid)
{
  int i, j;

  p_Vid->WalkAround += p_Vid->NumberIntraPerPicture;
  for (j=0, i = p_Vid->WalkAround; j<p_Vid->NumberIntraPerPicture; j++, i++)
    p_Vid->IntraMBs[j] = p_Vid->RefreshPattern [i%p_Vid->NumberOfMBs];
}

void RandomIntraUninit(VideoParameters *p_Vid)
{
  if (p_Vid->NumberIntraPerPicture >0 )
  {
    free(p_Vid->RefreshPattern);
    free(p_Vid->IntraMBs);
  }
}
