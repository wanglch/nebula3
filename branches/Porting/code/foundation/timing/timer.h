#pragma once
#ifndef TIMING_TIMER_H
#define TIMING_TIMER_H
//------------------------------------------------------------------------------
/**
    @class Timing::Timer
  
    A timer object is the most basic object for time measurement. More
    advanced timing classes often build on top of Timer.
    
    (C) 2006 Radon Labs GmbH
*/
#include "core/config.h"
#if (__WIN32__ || __XBOX360__)
#include "timing/win32/win32timer.h"
namespace Timing
{
class Timer : public Win32::Win32Timer
{ };
}
#elif (__WII__)
#include "timing/wii/wiitimer.h"
namespace Timing
{
class Timer : public Wii::WiiTimer
{ };
}
#elif (__APPLE__)
#include "timing/posix/posixtimer.h"
namespace Timing
{
class Timer : public Posix::PosixTimer
{ };
}
#else
#error "Timing::Timer not implemented on this platform!"
#endif
#endif