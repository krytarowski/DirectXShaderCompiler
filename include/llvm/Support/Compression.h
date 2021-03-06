//===-- llvm/Support/Compression.h ---Compression----------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Compression.h                                                             //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file contains basic functions for compression/uncompression.         //
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_SUPPORT_COMPRESSION_H
#define LLVM_SUPPORT_COMPRESSION_H

#include "llvm/Support/DataTypes.h"

namespace llvm {
template <typename T> class SmallVectorImpl;
class StringRef;

namespace zlib {

enum CompressionLevel {
  NoCompression,
  DefaultCompression,
  BestSpeedCompression,
  BestSizeCompression
};

enum Status {
  StatusOK,
  StatusUnsupported,    // zlib is unavailable
  StatusOutOfMemory,    // there was not enough memory
  StatusBufferTooShort, // there was not enough room in the output buffer
  StatusInvalidArg,     // invalid input parameter
  StatusInvalidData     // data was corrupted or incomplete
};

bool isAvailable();

Status compress(StringRef InputBuffer, SmallVectorImpl<char> &CompressedBuffer,
                CompressionLevel Level = DefaultCompression);

Status uncompress(StringRef InputBuffer,
                  SmallVectorImpl<char> &UncompressedBuffer,
                  size_t UncompressedSize);

uint32_t crc32(StringRef Buffer);

}  // End of namespace zlib

} // End of namespace llvm

#endif

