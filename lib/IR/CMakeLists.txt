# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.
add_llvm_library(LLVMCore
  AsmWriter.cpp
  Attributes.cpp
  AutoUpgrade.cpp
  BasicBlock.cpp
  Comdat.cpp
  ConstantFold.cpp
  ConstantRange.cpp
  Constants.cpp
  Core.cpp
  DIBuilder.cpp
  DataLayout.cpp
  DebugInfo.cpp
  DebugInfoMetadata.cpp
  DebugLoc.cpp
  DiagnosticInfo.cpp
  DiagnosticPrinter.cpp
  Dominators.cpp
  Function.cpp
  GCOV.cpp
  GVMaterializer.cpp
  Globals.cpp
  IRBuilder.cpp
  IRPrintingPasses.cpp
  InlineAsm.cpp
  Instruction.cpp
  Instructions.cpp
  IntrinsicInst.cpp
  LLVMContext.cpp
  LLVMContextImpl.cpp
  LegacyPassManager.cpp
  MDBuilder.cpp
  Mangler.cpp
  Metadata.cpp
  MetadataTracking.cpp
  Module.cpp
  Operator.cpp
  Pass.cpp
  PassManager.cpp
  PassRegistry.cpp
  Statepoint.cpp
  Type.cpp
  TypeFinder.cpp
  Use.cpp
  User.cpp
  Value.cpp
  ValueSymbolTable.cpp
  ValueTypes.cpp
  Verifier.cpp

  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/IR
  )

add_dependencies(LLVMCore intrinsics_gen)
