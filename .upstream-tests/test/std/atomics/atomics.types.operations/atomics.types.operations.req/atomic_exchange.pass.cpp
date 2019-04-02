//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads
//  ... fails assertion line 31

// <cuda/std/atomic>

// template <class T>
//     T
//     atomic_exchange(volatile atomic<T>* obj, T desr);
//
// template <class T>
//     T
//     atomic_exchange(atomic<T>* obj, T desr);

#include <cuda/std/atomic>
#include <cuda/std/type_traits>
#include <cuda/std/cassert>

#include "atomic_helpers.h"

template <class T>
struct TestFn {
  __host__ __device__
  void operator()() const {
    typedef cuda::std::atomic<T> A;
    A t;
    cuda::std::atomic_init(&t, T(1));
    assert(cuda::std::atomic_exchange(&t, T(2)) == T(1));
    assert(t == T(2));
    volatile A vt;
    cuda::std::atomic_init(&vt, T(3));
    assert(cuda::std::atomic_exchange(&vt, T(4)) == T(3));
    assert(vt == T(4));
  }
};


int main(int, char**)
{
    TestEachAtomicType<TestFn>()();

  return 0;
}
