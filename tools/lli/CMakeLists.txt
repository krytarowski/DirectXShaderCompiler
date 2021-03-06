# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.
add_subdirectory(ChildTarget)

set(LLVM_LINK_COMPONENTS
  CodeGen
  Core
  ExecutionEngine
  IRReader
  Instrumentation
  Interpreter
#  MC     # HLSL Change
#  MCJIT  # HLSL Change
  Object
  OrcJIT
  RuntimeDyld
  SelectionDAG
  Support
  Target
  TransformUtils
  native
  )

if( LLVM_USE_OPROFILE )
  set(LLVM_LINK_COMPONENTS
    ${LLVM_LINK_COMPONENTS}
    OProfileJIT
    )
endif( LLVM_USE_OPROFILE )

if( LLVM_USE_INTEL_JITEVENTS )
  set(LLVM_LINK_COMPONENTS
    ${LLVM_LINK_COMPONENTS}
    DebugInfoDWARF
    IntelJITEvents
    Object
    )
endif( LLVM_USE_INTEL_JITEVENTS )

add_llvm_tool(lli
  lli.cpp
  OrcLazyJIT.cpp
  RemoteMemoryManager.cpp
  RemoteTarget.cpp
  RemoteTargetExternal.cpp
  )
export_executable_symbols(lli)
