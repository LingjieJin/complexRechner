/* snd_codecontrol.h */

#ifndef _snd_codecontrol_h_
#define _snd_codecontrol_h_

/********** don't edit this *******/
#ifndef OS_MS_WINDOWS
  #define OS_MS_WINDOWS 1
#endif
#ifndef OS_LINUX
  #define OS_LINUX      2
#endif

/* for Linux, you may call gcc with option -DLINUX to
   define symbol LINUX and thus switch platforms without
   having to edit this file
*/
#ifdef LINUX
  #define PLATFORM  OS_LINUX
#endif

/********* end of: "don't edit this" *******/

/********************************************************/
/* select the platform snd_lib will be running on:               */
/* un-commend ONE of the following define instructions     */
/********************************************************/
#ifndef PLATFORM
  #define PLATFORM  OS_MS_WINDOWS 
  /* #define PLATFORM  OS_LINUX */
#endif





#endif
