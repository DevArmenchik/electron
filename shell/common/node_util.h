// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ELECTRON_SHELL_COMMON_NODE_UTIL_H_
#define ELECTRON_SHELL_COMMON_NODE_UTIL_H_

#include <vector>

#include "build/build_config.h"
#include "v8/include/v8.h"

namespace node {
class Environment;
}

namespace electron::util {

// Run a script with JS source bundled inside the binary as if it's wrapped
// in a function called with a null receiver and arguments specified in C++.
// The returned value is empty if an exception is encountered.
// JS code run with this method can assume that their top-level
// declarations won't affect the global scope.
v8::MaybeLocal<v8::Value> CompileAndCall(
    v8::Local<v8::Context> context,
    const char* id,
    std::vector<v8::Local<v8::String>>* parameters,
    std::vector<v8::Local<v8::Value>>* arguments);

#if BUILDFLAG(IS_MAC)
// Unset all environment variables that start with NODE_. Return false if there
// is no node env at all.
bool UnsetAllNodeEnvs();
#endif

}  // namespace electron::util

#endif  // ELECTRON_SHELL_COMMON_NODE_UTIL_H_
