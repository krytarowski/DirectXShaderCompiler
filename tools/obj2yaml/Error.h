//===- Error.h - system_error extensions for obj2yaml -----------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Error.h                                                                   //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_TOOLS_OBJ2YAML_ERROR_H
#define LLVM_TOOLS_OBJ2YAML_ERROR_H

#include <system_error>

namespace llvm {
const std::error_category &obj2yaml_category();

enum class obj2yaml_error {
  success = 0,
  file_not_found,
  unrecognized_file_format,
  unsupported_obj_file_format
};

inline std::error_code make_error_code(obj2yaml_error e) {
  return std::error_code(static_cast<int>(e), obj2yaml_category());
}

} // namespace llvm

namespace std {
template <> struct is_error_code_enum<llvm::obj2yaml_error> : std::true_type {};
}

#endif
