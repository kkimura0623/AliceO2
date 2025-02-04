// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
#ifndef O2_FRAMEWORK_DATAPROCESSINGHELPERS_H_
#define O2_FRAMEWORK_DATAPROCESSINGHELPERS_H_

#include <cstddef>

namespace o2::framework
{
struct ServiceRegistryRef;
struct ForwardChannelInfo;
struct ForwardChannelState;
struct OutputChannelInfo;
struct OutputChannelSpec;
struct OutputChannelState;

/// Generic helpers for DataProcessing releated functions.
struct DataProcessingHelpers {
  /// Send EndOfStream message to a given channel
  /// @param device the fair::mq::Device which needs to send the EndOfStream message
  /// @param channel the OutputChannelSpec of the channel which needs to be signaled
  ///        for EndOfStream
  static void sendEndOfStream(ServiceRegistryRef const& ref, OutputChannelSpec const& channel);
  /// @returns true if we did send the oldest possible timeslice message, false otherwise.
  static bool sendOldestPossibleTimeframe(ServiceRegistryRef const& ref, ForwardChannelInfo const& info, ForwardChannelState& state, size_t timeslice);
  /// @returns true if we did send the oldest possible timeslice message, false otherwise.
  static bool sendOldestPossibleTimeframe(ServiceRegistryRef const& ref, OutputChannelInfo const& info, OutputChannelState& state, size_t timeslice);
  /// Broadcast the oldest possible timeslice to all channels in output
  static void broadcastOldestPossibleTimeslice(ServiceRegistryRef const& ref, size_t timeslice);
};

} // namespace o2::framework
#endif // O2_FRAMEWORK_DATAPROCESSINGHELPERS_H_
