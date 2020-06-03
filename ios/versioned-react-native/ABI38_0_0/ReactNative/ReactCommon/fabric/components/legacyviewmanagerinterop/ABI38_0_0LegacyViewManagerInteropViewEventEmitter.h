/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>

#include <folly/dynamic.h>
#include <ABI38_0_0React/components/view/ViewEventEmitter.h>
#include <ABI38_0_0React/core/EventEmitter.h>

namespace ABI38_0_0facebook {
namespace ABI38_0_0React {

class LegacyViewManagerInteropViewEventEmitter;

using SharedLegacyViewManagerInteropViewEventEmitter =
    std::shared_ptr<const LegacyViewManagerInteropViewEventEmitter>;

class LegacyViewManagerInteropViewEventEmitter : public ViewEventEmitter {
 public:
  using ViewEventEmitter::ViewEventEmitter;

  void dispatchEvent(std::string const &type, folly::dynamic const &payload)
      const;
};

} // namespace ABI38_0_0React
} // namespace ABI38_0_0facebook
