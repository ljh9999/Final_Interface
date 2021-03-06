/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_CORE_KERNELS_COLLECTIVE_NCCL_H_
#define TENSORFLOW_CORE_KERNELS_COLLECTIVE_NCCL_H_

#include "tensorflow/core/framework/collective.h"

namespace tensorflow {
#ifdef GOOGLE_CUDA

class NcclBase : public CollectiveImplementationInterface {
 public:
  explicit NcclBase(CollectiveType type, const string& name);
  ~NcclBase() override = default;

  // No-op for this collective implementation.
  Status InitializeCollectiveParams(CollectiveParams* col_params) override;

  // Initializes the device objects and device localities.
  Status InitializeCollectiveContext(CollectiveContext* col_ctx) override;

  // Initialize nccl communicator key.
  Status InitializeCollectiveGroupRuntimeDetails(
      CollGroupRuntimeDetails* col_group_runtime_details) override;

 protected:
  const string NcclCollectiveKey(const string& exec_key, int step_id);

  const CollectiveType type_;
  const string name_;
  CollectiveContext* col_ctx_;          // Not owned
  const CollectiveParams* col_params_;  // Not owned
};

#endif  // GOOGLE_CUDA
}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_KERNELS_COLLECTIVE_NCCL_H_
