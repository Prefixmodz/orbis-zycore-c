/***************************************************************************************************

  Zyan Core Library (Zyan-C)

  Original Author : Florian Bernd

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

#ifndef ZYCORE_ATOMIC_GNU_H
#define ZYCORE_ATOMIC_GNU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Zycore/Defines.h>
#include <Zycore/Types.h>

#include <sce_atomic.h>

/* ============================================================================================== */
/* Functions                                                                                      */
/* ============================================================================================== */

#if defined(ZYAN_CLANG) || defined(ZYAN_GCC) || defined(ZYAN_ICC)

/* ---------------------------------------------------------------------------------------------- */
/* Pointer sized                                                                                  */
/* ---------------------------------------------------------------------------------------------- */

ZYAN_INLINE ZyanUPointer ZyanAtomicCompareExchange(ZyanAtomicPointer* destination,
    ZyanUPointer comparand, ZyanUPointer value)
{
    return (ZyanUPointer)ZyanAtomicCompareExchange64((ZyanAtomic64*)destination, comparand, value);
}

ZYAN_INLINE ZyanUPointer ZyanAtomicIncrement(ZyanAtomicPointer* destination)
{
    return (ZyanUPointer)ZyanAtomicIncrement64((ZyanAtomic64*)destination);
}

ZYAN_INLINE ZyanUPointer ZyanAtomicDecrement(ZyanAtomicPointer* destination)
{
    return (ZyanUPointer)ZyanAtomicDecrement64((ZyanAtomic64*)destination);
}

/* ---------------------------------------------------------------------------------------------- */
/* 32-bit                                                                                         */
/* ---------------------------------------------------------------------------------------------- */

ZYAN_INLINE ZyanU32 ZyanAtomicCompareExchange32(ZyanAtomic32* destination,
    ZyanU32 comparand, ZyanU32 value)
{
    return (ZyanU32)(sceAtomicCompareAndSwap32((volatile __int32_t *)&destination->value, comparand, value));
}

ZYAN_INLINE ZyanU32 ZyanAtomicIncrement32(ZyanAtomic32* destination)
{
    return (ZyanU32)(sceAtomicIncrement32((volatile __int32_t*)&destination->value)) + 1;
}

ZYAN_INLINE ZyanU32 ZyanAtomicDecrement32(ZyanAtomic32* destination)
{
    return (ZyanU32)(sceAtomicDecrement32((volatile __int32_t*)&destination->value));
}

/* ---------------------------------------------------------------------------------------------- */
/* 64-bit                                                                                         */
/* ---------------------------------------------------------------------------------------------- */

ZYAN_INLINE ZyanU64 ZyanAtomicCompareExchange64(ZyanAtomic64* destination,
    ZyanU64 comparand, ZyanU64 value)
{
    return (ZyanU64)(sceAtomicCompareAndSwap64((volatile __int64_t*)&destination->value, comparand, value));
}

ZYAN_INLINE ZyanU64 ZyanAtomicIncrement64(ZyanAtomic64* destination)
{
    return (ZyanU64)(sceAtomicIncrement64((volatile __int64_t*)&destination->value)) + 1;
}

ZYAN_INLINE ZyanU64 ZyanAtomicDecrement64(ZyanAtomic64* destination)
{
    return (ZyanU64)(sceAtomicDecrement64((volatile __int64_t*)&destination->value));
}

/* ---------------------------------------------------------------------------------------------- */

#endif

/* ============================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ZYCORE_ATOMIC_GNU_H */
