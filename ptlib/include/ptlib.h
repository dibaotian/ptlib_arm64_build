#ifndef PTLIB_PTLIB_H
#define PTLIB_PTLIB_H

#ifndef P_64BIT
#define P_64BIT
#endif

#ifdef __GNUC__

#pragma interface

#if !defined(__USE_STD__) && __GNUC__ >= 3
#define __USE_STD__
#endif

#endif

#ifdef __NUCLEUS_PLUS__
#include "nucpp.h"
#endif
#include "ptbuildopts.h"
#include <ptlib/contain.h>
#include <ptlib/ptime.h>
#include <ptlib/timeint.h>
#include <ptlib/timer.h>
#include <ptlib/pdirect.h>
#include <ptlib/filepath.h>
#include <ptlib/config.h>
#include <ptlib/args.h>
#include <ptlib/thread.h>
#include <ptlib/semaphor.h>
#include <ptlib/mutex.h>
#include <ptlib/syncpoint.h>
#include <ptlib/syncthrd.h>
#include <ptlib/psharedptr.h>
#include <ptlib/dynalink.h>
#include <ptlib/indchan.h>
#include <ptlib/file.h>
#include <ptlib/textfile.h>
#include <ptlib/sfile.h>
#include <ptlib/conchan.h>



#if P_USE_INLINES

#ifdef _WIN32
#include <ptlib/msos/ptlib/ptlib.inl>
#else
#include <ptlib/unix/ptlib/ptlib.inl>
#endif
#include <ptlib/osutil.inl>

#endif

#endif // PTLIB_PTLIB_H