//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <cuda/std/cstddef>
#include <cuda/std/type_traits>

// size_t should:

//  1. be in namespace std.
//  2. be the same sizeof as void*.
//  3. be an unsigned integral.

int main(int, char**)
{
    static_assert(sizeof(cuda::std::size_t) == sizeof(void*),
                  "sizeof(cuda::std::size_t) == sizeof(void*)");
    static_assert(cuda::std::is_unsigned<cuda::std::size_t>::value,
                  "cuda::std::is_unsigned<cuda::std::size_t>::value");
    static_assert(cuda::std::is_integral<cuda::std::size_t>::value,
                  "cuda::std::is_integral<cuda::std::size_t>::value");

  return 0;
}
