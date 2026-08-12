// Copyright 2021 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "src/dawn/native/ChainUtils.h"

#include <tuple>
#include <utility>

namespace dawn::native {

// Returns true iff the chain's SType matches the extension, false otherwise. If the SType was
// not already matched, sets the unpacked result accordingly. Otherwise, stores the duplicated
// SType in 'duplicate'.
template <typename Root, typename UnpackedPtrT, typename Ext>
bool UnpackExtension(typename UnpackedPtrT::TupleType& unpacked,
                     typename UnpackedPtrT::BitsetType& bitset,
                     typename UnpackedPtrT::ChainType chain, bool* duplicate) {
    DAWN_ASSERT(chain != nullptr);
    if (chain->sType == STypeFor<Ext>) {
        auto& member = std::get<Ext>(unpacked);
        if (member != nullptr && duplicate) {
            *duplicate = true;
        } else {
            member = reinterpret_cast<Ext>(chain);
            bitset.set(detail::UnpackedPtrIndexOf<UnpackedPtrT, Ext>);
        }
        return true;
    }
    return false;
}

// Tries to match all possible extensions, returning true iff one of the allowed extensions were
// matched, false otherwise. If the SType was not already matched, sets the unpacked result
// accordingly. Otherwise, stores the duplicated SType in 'duplicate'.
template <typename Root, typename UnpackedPtrT, typename AdditionalExts>
struct AdditionalExtensionUnpacker;
template <typename Root, typename UnpackedPtrT, typename... Exts>
struct AdditionalExtensionUnpacker<Root, UnpackedPtrT, detail::AdditionalExtensionsList<Exts...>> {
    static bool Unpack(UnpackedPtrT::TupleType& unpacked,
                       UnpackedPtrT::BitsetType& bitset,
                       UnpackedPtrT::ChainType chain,
                       bool* duplicate) {
        return ((UnpackExtension<Root, UnpackedPtrT, Exts>(unpacked, bitset, chain, duplicate)) ||
                ...);
    }
};

//
// UnpackedPtr chain helpers.
//
template <>
UnpackedPtr<BindingResource> Unpack<BindingResource>(UnpackedPtr<BindingResource>::PtrType chain) {
    UnpackedPtr<BindingResource> result(chain);
    for (UnpackedPtr<BindingResource>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindingResource,
                        UnpackedPtr<BindingResource>,
                        detail::AdditionalExtensions<BindingResource>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindingResource>> ValidateAndUnpack<BindingResource>(
    UnpackedPtr<BindingResource>::PtrType chain) {
    UnpackedPtr<BindingResource> result(chain);
    for (UnpackedPtr<BindingResource>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindingResource,
                        UnpackedPtr<BindingResource>,
                        detail::AdditionalExtensions<BindingResource>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BindingResource"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BindingResource"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindingResource"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BufferBindingLayout> Unpack<BufferBindingLayout>(UnpackedPtr<BufferBindingLayout>::PtrType chain) {
    UnpackedPtr<BufferBindingLayout> result(chain);
    for (UnpackedPtr<BufferBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferBindingLayout,
                        UnpackedPtr<BufferBindingLayout>,
                        detail::AdditionalExtensions<BufferBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BufferBindingLayout>> ValidateAndUnpack<BufferBindingLayout>(
    UnpackedPtr<BufferBindingLayout>::PtrType chain) {
    UnpackedPtr<BufferBindingLayout> result(chain);
    for (UnpackedPtr<BufferBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferBindingLayout,
                        UnpackedPtr<BufferBindingLayout>,
                        detail::AdditionalExtensions<BufferBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BufferBindingLayout"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BufferBindingLayout"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BufferBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ColorSpaceDawn> Unpack<ColorSpaceDawn>(UnpackedPtr<ColorSpaceDawn>::PtrType chain) {
    UnpackedPtr<ColorSpaceDawn> result(chain);
    for (UnpackedPtr<ColorSpaceDawn>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ColorSpaceDawn,
                        UnpackedPtr<ColorSpaceDawn>,
                        detail::AdditionalExtensions<ColorSpaceDawn>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ColorSpaceDawn>> ValidateAndUnpack<ColorSpaceDawn>(
    UnpackedPtr<ColorSpaceDawn>::PtrType chain) {
    UnpackedPtr<ColorSpaceDawn> result(chain);
    for (UnpackedPtr<ColorSpaceDawn>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ColorSpaceDawn,
                        UnpackedPtr<ColorSpaceDawn>,
                        detail::AdditionalExtensions<ColorSpaceDawn>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ColorSpaceDawn"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ColorSpaceDawn"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ColorSpaceDawn"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CommandBufferDescriptor> Unpack<CommandBufferDescriptor>(UnpackedPtr<CommandBufferDescriptor>::PtrType chain) {
    UnpackedPtr<CommandBufferDescriptor> result(chain);
    for (UnpackedPtr<CommandBufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandBufferDescriptor,
                        UnpackedPtr<CommandBufferDescriptor>,
                        detail::AdditionalExtensions<CommandBufferDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CommandBufferDescriptor>> ValidateAndUnpack<CommandBufferDescriptor>(
    UnpackedPtr<CommandBufferDescriptor>::PtrType chain) {
    UnpackedPtr<CommandBufferDescriptor> result(chain);
    for (UnpackedPtr<CommandBufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandBufferDescriptor,
                        UnpackedPtr<CommandBufferDescriptor>,
                        detail::AdditionalExtensions<CommandBufferDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "CommandBufferDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "CommandBufferDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CommandBufferDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ConstantEntry> Unpack<ConstantEntry>(UnpackedPtr<ConstantEntry>::PtrType chain) {
    UnpackedPtr<ConstantEntry> result(chain);
    for (UnpackedPtr<ConstantEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ConstantEntry,
                        UnpackedPtr<ConstantEntry>,
                        detail::AdditionalExtensions<ConstantEntry>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ConstantEntry>> ValidateAndUnpack<ConstantEntry>(
    UnpackedPtr<ConstantEntry>::PtrType chain) {
    UnpackedPtr<ConstantEntry> result(chain);
    for (UnpackedPtr<ConstantEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ConstantEntry,
                        UnpackedPtr<ConstantEntry>,
                        detail::AdditionalExtensions<ConstantEntry>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ConstantEntry"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ConstantEntry"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ConstantEntry"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CopyTextureForBrowserOptions> Unpack<CopyTextureForBrowserOptions>(UnpackedPtr<CopyTextureForBrowserOptions>::PtrType chain) {
    UnpackedPtr<CopyTextureForBrowserOptions> result(chain);
    for (UnpackedPtr<CopyTextureForBrowserOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CopyTextureForBrowserOptions,
                        UnpackedPtr<CopyTextureForBrowserOptions>,
                        detail::AdditionalExtensions<CopyTextureForBrowserOptions>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CopyTextureForBrowserOptions>> ValidateAndUnpack<CopyTextureForBrowserOptions>(
    UnpackedPtr<CopyTextureForBrowserOptions>::PtrType chain) {
    UnpackedPtr<CopyTextureForBrowserOptions> result(chain);
    for (UnpackedPtr<CopyTextureForBrowserOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CopyTextureForBrowserOptions,
                        UnpackedPtr<CopyTextureForBrowserOptions>,
                        detail::AdditionalExtensions<CopyTextureForBrowserOptions>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "CopyTextureForBrowserOptions"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "CopyTextureForBrowserOptions"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CopyTextureForBrowserOptions"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<InstanceLimits> Unpack<InstanceLimits>(UnpackedPtr<InstanceLimits>::PtrType chain) {
    UnpackedPtr<InstanceLimits> result(chain);
    for (UnpackedPtr<InstanceLimits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceLimits,
                        UnpackedPtr<InstanceLimits>,
                        detail::AdditionalExtensions<InstanceLimits>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<InstanceLimits>> ValidateAndUnpack<InstanceLimits>(
    UnpackedPtr<InstanceLimits>::PtrType chain) {
    UnpackedPtr<InstanceLimits> result(chain);
    for (UnpackedPtr<InstanceLimits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceLimits,
                        UnpackedPtr<InstanceLimits>,
                        detail::AdditionalExtensions<InstanceLimits>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "InstanceLimits"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "InstanceLimits"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "InstanceLimits"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<MultisampleState> Unpack<MultisampleState>(UnpackedPtr<MultisampleState>::PtrType chain) {
    UnpackedPtr<MultisampleState> result(chain);
    for (UnpackedPtr<MultisampleState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        MultisampleState,
                        UnpackedPtr<MultisampleState>,
                        detail::AdditionalExtensions<MultisampleState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<MultisampleState>> ValidateAndUnpack<MultisampleState>(
    UnpackedPtr<MultisampleState>::PtrType chain) {
    UnpackedPtr<MultisampleState> result(chain);
    for (UnpackedPtr<MultisampleState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        MultisampleState,
                        UnpackedPtr<MultisampleState>,
                        detail::AdditionalExtensions<MultisampleState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "MultisampleState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "MultisampleState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "MultisampleState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PassTimestampWrites> Unpack<PassTimestampWrites>(UnpackedPtr<PassTimestampWrites>::PtrType chain) {
    UnpackedPtr<PassTimestampWrites> result(chain);
    for (UnpackedPtr<PassTimestampWrites>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PassTimestampWrites,
                        UnpackedPtr<PassTimestampWrites>,
                        detail::AdditionalExtensions<PassTimestampWrites>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PassTimestampWrites>> ValidateAndUnpack<PassTimestampWrites>(
    UnpackedPtr<PassTimestampWrites>::PtrType chain) {
    UnpackedPtr<PassTimestampWrites> result(chain);
    for (UnpackedPtr<PassTimestampWrites>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PassTimestampWrites,
                        UnpackedPtr<PassTimestampWrites>,
                        detail::AdditionalExtensions<PassTimestampWrites>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "PassTimestampWrites"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "PassTimestampWrites"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PassTimestampWrites"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PipelineLayoutStorageAttachment> Unpack<PipelineLayoutStorageAttachment>(UnpackedPtr<PipelineLayoutStorageAttachment>::PtrType chain) {
    UnpackedPtr<PipelineLayoutStorageAttachment> result(chain);
    for (UnpackedPtr<PipelineLayoutStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutStorageAttachment,
                        UnpackedPtr<PipelineLayoutStorageAttachment>,
                        detail::AdditionalExtensions<PipelineLayoutStorageAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PipelineLayoutStorageAttachment>> ValidateAndUnpack<PipelineLayoutStorageAttachment>(
    UnpackedPtr<PipelineLayoutStorageAttachment>::PtrType chain) {
    UnpackedPtr<PipelineLayoutStorageAttachment> result(chain);
    for (UnpackedPtr<PipelineLayoutStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutStorageAttachment,
                        UnpackedPtr<PipelineLayoutStorageAttachment>,
                        detail::AdditionalExtensions<PipelineLayoutStorageAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "PipelineLayoutStorageAttachment"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "PipelineLayoutStorageAttachment"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PipelineLayoutStorageAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PrimitiveState> Unpack<PrimitiveState>(UnpackedPtr<PrimitiveState>::PtrType chain) {
    UnpackedPtr<PrimitiveState> result(chain);
    for (UnpackedPtr<PrimitiveState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PrimitiveState,
                        UnpackedPtr<PrimitiveState>,
                        detail::AdditionalExtensions<PrimitiveState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PrimitiveState>> ValidateAndUnpack<PrimitiveState>(
    UnpackedPtr<PrimitiveState>::PtrType chain) {
    UnpackedPtr<PrimitiveState> result(chain);
    for (UnpackedPtr<PrimitiveState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PrimitiveState,
                        UnpackedPtr<PrimitiveState>,
                        detail::AdditionalExtensions<PrimitiveState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "PrimitiveState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "PrimitiveState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PrimitiveState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<QuerySetDescriptor> Unpack<QuerySetDescriptor>(UnpackedPtr<QuerySetDescriptor>::PtrType chain) {
    UnpackedPtr<QuerySetDescriptor> result(chain);
    for (UnpackedPtr<QuerySetDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QuerySetDescriptor,
                        UnpackedPtr<QuerySetDescriptor>,
                        detail::AdditionalExtensions<QuerySetDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<QuerySetDescriptor>> ValidateAndUnpack<QuerySetDescriptor>(
    UnpackedPtr<QuerySetDescriptor>::PtrType chain) {
    UnpackedPtr<QuerySetDescriptor> result(chain);
    for (UnpackedPtr<QuerySetDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QuerySetDescriptor,
                        UnpackedPtr<QuerySetDescriptor>,
                        detail::AdditionalExtensions<QuerySetDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "QuerySetDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "QuerySetDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "QuerySetDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<QueueDescriptor> Unpack<QueueDescriptor>(UnpackedPtr<QueueDescriptor>::PtrType chain) {
    UnpackedPtr<QueueDescriptor> result(chain);
    for (UnpackedPtr<QueueDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QueueDescriptor,
                        UnpackedPtr<QueueDescriptor>,
                        detail::AdditionalExtensions<QueueDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<QueueDescriptor>> ValidateAndUnpack<QueueDescriptor>(
    UnpackedPtr<QueueDescriptor>::PtrType chain) {
    UnpackedPtr<QueueDescriptor> result(chain);
    for (UnpackedPtr<QueueDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QueueDescriptor,
                        UnpackedPtr<QueueDescriptor>,
                        detail::AdditionalExtensions<QueueDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "QueueDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "QueueDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "QueueDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderBundleDescriptor> Unpack<RenderBundleDescriptor>(UnpackedPtr<RenderBundleDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleDescriptor> result(chain);
    for (UnpackedPtr<RenderBundleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleDescriptor,
                        UnpackedPtr<RenderBundleDescriptor>,
                        detail::AdditionalExtensions<RenderBundleDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderBundleDescriptor>> ValidateAndUnpack<RenderBundleDescriptor>(
    UnpackedPtr<RenderBundleDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleDescriptor> result(chain);
    for (UnpackedPtr<RenderBundleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleDescriptor,
                        UnpackedPtr<RenderBundleDescriptor>,
                        detail::AdditionalExtensions<RenderBundleDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderBundleDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderBundleDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderBundleDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassDepthStencilAttachment> Unpack<RenderPassDepthStencilAttachment>(UnpackedPtr<RenderPassDepthStencilAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassDepthStencilAttachment> result(chain);
    for (UnpackedPtr<RenderPassDepthStencilAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassDepthStencilAttachment,
                        UnpackedPtr<RenderPassDepthStencilAttachment>,
                        detail::AdditionalExtensions<RenderPassDepthStencilAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassDepthStencilAttachment>> ValidateAndUnpack<RenderPassDepthStencilAttachment>(
    UnpackedPtr<RenderPassDepthStencilAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassDepthStencilAttachment> result(chain);
    for (UnpackedPtr<RenderPassDepthStencilAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassDepthStencilAttachment,
                        UnpackedPtr<RenderPassDepthStencilAttachment>,
                        detail::AdditionalExtensions<RenderPassDepthStencilAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderPassDepthStencilAttachment"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderPassDepthStencilAttachment"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassDepthStencilAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ResourceTableDescriptor> Unpack<ResourceTableDescriptor>(UnpackedPtr<ResourceTableDescriptor>::PtrType chain) {
    UnpackedPtr<ResourceTableDescriptor> result(chain);
    for (UnpackedPtr<ResourceTableDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ResourceTableDescriptor,
                        UnpackedPtr<ResourceTableDescriptor>,
                        detail::AdditionalExtensions<ResourceTableDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ResourceTableDescriptor>> ValidateAndUnpack<ResourceTableDescriptor>(
    UnpackedPtr<ResourceTableDescriptor>::PtrType chain) {
    UnpackedPtr<ResourceTableDescriptor> result(chain);
    for (UnpackedPtr<ResourceTableDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ResourceTableDescriptor,
                        UnpackedPtr<ResourceTableDescriptor>,
                        detail::AdditionalExtensions<ResourceTableDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ResourceTableDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ResourceTableDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ResourceTableDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SamplerBindingLayout> Unpack<SamplerBindingLayout>(UnpackedPtr<SamplerBindingLayout>::PtrType chain) {
    UnpackedPtr<SamplerBindingLayout> result(chain);
    for (UnpackedPtr<SamplerBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerBindingLayout,
                        UnpackedPtr<SamplerBindingLayout>,
                        detail::AdditionalExtensions<SamplerBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SamplerBindingLayout>> ValidateAndUnpack<SamplerBindingLayout>(
    UnpackedPtr<SamplerBindingLayout>::PtrType chain) {
    UnpackedPtr<SamplerBindingLayout> result(chain);
    for (UnpackedPtr<SamplerBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerBindingLayout,
                        UnpackedPtr<SamplerBindingLayout>,
                        detail::AdditionalExtensions<SamplerBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SamplerBindingLayout"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SamplerBindingLayout"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SamplerBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor> Unpack<SharedBufferMemoryBeginAccessDescriptor>(UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor> result(chain);
    for (UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryBeginAccessDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>> ValidateAndUnpack<SharedBufferMemoryBeginAccessDescriptor>(
    UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor> result(chain);
    for (UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryBeginAccessDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedBufferMemoryBeginAccessDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedBufferMemoryBeginAccessDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryBeginAccessDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryEndAccessState> Unpack<SharedBufferMemoryEndAccessState>(UnpackedPtr<SharedBufferMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryEndAccessState> result(chain);
    for (UnpackedPtr<SharedBufferMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryEndAccessState,
                        UnpackedPtr<SharedBufferMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedBufferMemoryEndAccessState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryEndAccessState>> ValidateAndUnpack<SharedBufferMemoryEndAccessState>(
    UnpackedPtr<SharedBufferMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryEndAccessState> result(chain);
    for (UnpackedPtr<SharedBufferMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryEndAccessState,
                        UnpackedPtr<SharedBufferMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedBufferMemoryEndAccessState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedBufferMemoryEndAccessState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedBufferMemoryEndAccessState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryEndAccessState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryProperties> Unpack<SharedBufferMemoryProperties>(UnpackedPtr<SharedBufferMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryProperties> result(chain);
    for (UnpackedPtr<SharedBufferMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryProperties,
                        UnpackedPtr<SharedBufferMemoryProperties>,
                        detail::AdditionalExtensions<SharedBufferMemoryProperties>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryProperties>> ValidateAndUnpack<SharedBufferMemoryProperties>(
    UnpackedPtr<SharedBufferMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryProperties> result(chain);
    for (UnpackedPtr<SharedBufferMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryProperties,
                        UnpackedPtr<SharedBufferMemoryProperties>,
                        detail::AdditionalExtensions<SharedBufferMemoryProperties>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedBufferMemoryProperties"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedBufferMemoryProperties"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryProperties"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<StorageTextureBindingLayout> Unpack<StorageTextureBindingLayout>(UnpackedPtr<StorageTextureBindingLayout>::PtrType chain) {
    UnpackedPtr<StorageTextureBindingLayout> result(chain);
    for (UnpackedPtr<StorageTextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        StorageTextureBindingLayout,
                        UnpackedPtr<StorageTextureBindingLayout>,
                        detail::AdditionalExtensions<StorageTextureBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<StorageTextureBindingLayout>> ValidateAndUnpack<StorageTextureBindingLayout>(
    UnpackedPtr<StorageTextureBindingLayout>::PtrType chain) {
    UnpackedPtr<StorageTextureBindingLayout> result(chain);
    for (UnpackedPtr<StorageTextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        StorageTextureBindingLayout,
                        UnpackedPtr<StorageTextureBindingLayout>,
                        detail::AdditionalExtensions<StorageTextureBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "StorageTextureBindingLayout"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "StorageTextureBindingLayout"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "StorageTextureBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceCapabilities> Unpack<SurfaceCapabilities>(UnpackedPtr<SurfaceCapabilities>::PtrType chain) {
    UnpackedPtr<SurfaceCapabilities> result(chain);
    for (UnpackedPtr<SurfaceCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceCapabilities,
                        UnpackedPtr<SurfaceCapabilities>,
                        detail::AdditionalExtensions<SurfaceCapabilities>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceCapabilities>> ValidateAndUnpack<SurfaceCapabilities>(
    UnpackedPtr<SurfaceCapabilities>::PtrType chain) {
    UnpackedPtr<SurfaceCapabilities> result(chain);
    for (UnpackedPtr<SurfaceCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceCapabilities,
                        UnpackedPtr<SurfaceCapabilities>,
                        detail::AdditionalExtensions<SurfaceCapabilities>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SurfaceCapabilities"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SurfaceCapabilities"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceCapabilities"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceConfiguration> Unpack<SurfaceConfiguration>(UnpackedPtr<SurfaceConfiguration>::PtrType chain) {
    UnpackedPtr<SurfaceConfiguration> result(chain);
    for (UnpackedPtr<SurfaceConfiguration>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceConfiguration,
                        UnpackedPtr<SurfaceConfiguration>,
                        detail::AdditionalExtensions<SurfaceConfiguration>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceConfiguration>> ValidateAndUnpack<SurfaceConfiguration>(
    UnpackedPtr<SurfaceConfiguration>::PtrType chain) {
    UnpackedPtr<SurfaceConfiguration> result(chain);
    for (UnpackedPtr<SurfaceConfiguration>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceConfiguration,
                        UnpackedPtr<SurfaceConfiguration>,
                        detail::AdditionalExtensions<SurfaceConfiguration>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SurfaceConfiguration"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SurfaceConfiguration"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceConfiguration"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceTexture> Unpack<SurfaceTexture>(UnpackedPtr<SurfaceTexture>::PtrType chain) {
    UnpackedPtr<SurfaceTexture> result(chain);
    for (UnpackedPtr<SurfaceTexture>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceTexture,
                        UnpackedPtr<SurfaceTexture>,
                        detail::AdditionalExtensions<SurfaceTexture>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceTexture>> ValidateAndUnpack<SurfaceTexture>(
    UnpackedPtr<SurfaceTexture>::PtrType chain) {
    UnpackedPtr<SurfaceTexture> result(chain);
    for (UnpackedPtr<SurfaceTexture>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceTexture,
                        UnpackedPtr<SurfaceTexture>,
                        detail::AdditionalExtensions<SurfaceTexture>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SurfaceTexture"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SurfaceTexture"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceTexture"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TexelBufferViewDescriptor> Unpack<TexelBufferViewDescriptor>(UnpackedPtr<TexelBufferViewDescriptor>::PtrType chain) {
    UnpackedPtr<TexelBufferViewDescriptor> result(chain);
    for (UnpackedPtr<TexelBufferViewDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TexelBufferViewDescriptor,
                        UnpackedPtr<TexelBufferViewDescriptor>,
                        detail::AdditionalExtensions<TexelBufferViewDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TexelBufferViewDescriptor>> ValidateAndUnpack<TexelBufferViewDescriptor>(
    UnpackedPtr<TexelBufferViewDescriptor>::PtrType chain) {
    UnpackedPtr<TexelBufferViewDescriptor> result(chain);
    for (UnpackedPtr<TexelBufferViewDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TexelBufferViewDescriptor,
                        UnpackedPtr<TexelBufferViewDescriptor>,
                        detail::AdditionalExtensions<TexelBufferViewDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "TexelBufferViewDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "TexelBufferViewDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TexelBufferViewDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureBindingLayout> Unpack<TextureBindingLayout>(UnpackedPtr<TextureBindingLayout>::PtrType chain) {
    UnpackedPtr<TextureBindingLayout> result(chain);
    for (UnpackedPtr<TextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureBindingLayout,
                        UnpackedPtr<TextureBindingLayout>,
                        detail::AdditionalExtensions<TextureBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureBindingLayout>> ValidateAndUnpack<TextureBindingLayout>(
    UnpackedPtr<TextureBindingLayout>::PtrType chain) {
    UnpackedPtr<TextureBindingLayout> result(chain);
    for (UnpackedPtr<TextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureBindingLayout,
                        UnpackedPtr<TextureBindingLayout>,
                        detail::AdditionalExtensions<TextureBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "TextureBindingLayout"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "TextureBindingLayout"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<VertexAttribute> Unpack<VertexAttribute>(UnpackedPtr<VertexAttribute>::PtrType chain) {
    UnpackedPtr<VertexAttribute> result(chain);
    for (UnpackedPtr<VertexAttribute>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexAttribute,
                        UnpackedPtr<VertexAttribute>,
                        detail::AdditionalExtensions<VertexAttribute>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<VertexAttribute>> ValidateAndUnpack<VertexAttribute>(
    UnpackedPtr<VertexAttribute>::PtrType chain) {
    UnpackedPtr<VertexAttribute> result(chain);
    for (UnpackedPtr<VertexAttribute>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexAttribute,
                        UnpackedPtr<VertexAttribute>,
                        detail::AdditionalExtensions<VertexAttribute>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "VertexAttribute"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "VertexAttribute"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "VertexAttribute"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupEntry> Unpack<BindGroupEntry>(UnpackedPtr<BindGroupEntry>::PtrType chain) {
    UnpackedPtr<BindGroupEntry> result(chain);
    for (UnpackedPtr<BindGroupEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<ExternalTextureBindingEntry>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupEntry>, ExternalTextureBindingEntry>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupEntry>, ExtPtrType>
                );
                break;
            }
            case STypeFor<TexelBufferBindingEntry>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupEntry>, TexelBufferBindingEntry>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupEntry>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupEntry,
                        UnpackedPtr<BindGroupEntry>,
                        detail::AdditionalExtensions<BindGroupEntry>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupEntry>> ValidateAndUnpack<BindGroupEntry>(
    UnpackedPtr<BindGroupEntry>::PtrType chain) {
    UnpackedPtr<BindGroupEntry> result(chain);
    for (UnpackedPtr<BindGroupEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<ExternalTextureBindingEntry>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupEntry>, ExternalTextureBindingEntry>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupEntry>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<TexelBufferBindingEntry>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupEntry>, TexelBufferBindingEntry>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupEntry>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupEntry,
                        UnpackedPtr<BindGroupEntry>,
                        detail::AdditionalExtensions<BindGroupEntry>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BindGroupEntry"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BindGroupEntry"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupEntry"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupLayoutEntry> Unpack<BindGroupLayoutEntry>(UnpackedPtr<BindGroupLayoutEntry>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutEntry> result(chain);
    for (UnpackedPtr<BindGroupLayoutEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<StaticSamplerBindingLayout>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, StaticSamplerBindingLayout>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                );
                break;
            }
            case STypeFor<ExternalTextureBindingLayout>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, ExternalTextureBindingLayout>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                );
                break;
            }
            case STypeFor<TexelBufferBindingLayout>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, TexelBufferBindingLayout>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutEntry,
                        UnpackedPtr<BindGroupLayoutEntry>,
                        detail::AdditionalExtensions<BindGroupLayoutEntry>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupLayoutEntry>> ValidateAndUnpack<BindGroupLayoutEntry>(
    UnpackedPtr<BindGroupLayoutEntry>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutEntry> result(chain);
    for (UnpackedPtr<BindGroupLayoutEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<StaticSamplerBindingLayout>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, StaticSamplerBindingLayout>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<ExternalTextureBindingLayout>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, ExternalTextureBindingLayout>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<TexelBufferBindingLayout>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, TexelBufferBindingLayout>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutEntry,
                        UnpackedPtr<BindGroupLayoutEntry>,
                        detail::AdditionalExtensions<BindGroupLayoutEntry>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BindGroupLayoutEntry"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BindGroupLayoutEntry"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupLayoutEntry"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BufferDescriptor> Unpack<BufferDescriptor>(UnpackedPtr<BufferDescriptor>::PtrType chain) {
    UnpackedPtr<BufferDescriptor> result(chain);
    for (UnpackedPtr<BufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<BufferHostMappedPointer>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, BufferHostMappedPointer>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnFakeBufferOOMForTesting>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, DawnFakeBufferOOMForTesting>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnBufferDescriptorErrorInfoFromWireClient>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, DawnBufferDescriptorErrorInfoFromWireClient>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferDescriptor,
                        UnpackedPtr<BufferDescriptor>,
                        detail::AdditionalExtensions<BufferDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BufferDescriptor>> ValidateAndUnpack<BufferDescriptor>(
    UnpackedPtr<BufferDescriptor>::PtrType chain) {
    UnpackedPtr<BufferDescriptor> result(chain);
    for (UnpackedPtr<BufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<BufferHostMappedPointer>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, BufferHostMappedPointer>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnFakeBufferOOMForTesting>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, DawnFakeBufferOOMForTesting>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnBufferDescriptorErrorInfoFromWireClient>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, DawnBufferDescriptorErrorInfoFromWireClient>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferDescriptor,
                        UnpackedPtr<BufferDescriptor>,
                        detail::AdditionalExtensions<BufferDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BufferDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BufferDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BufferDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CommandEncoderDescriptor> Unpack<CommandEncoderDescriptor>(UnpackedPtr<CommandEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<CommandEncoderDescriptor> result(chain);
    for (UnpackedPtr<CommandEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnEncoderInternalUsageDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<CommandEncoderDescriptor>, DawnEncoderInternalUsageDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<CommandEncoderDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandEncoderDescriptor,
                        UnpackedPtr<CommandEncoderDescriptor>,
                        detail::AdditionalExtensions<CommandEncoderDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CommandEncoderDescriptor>> ValidateAndUnpack<CommandEncoderDescriptor>(
    UnpackedPtr<CommandEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<CommandEncoderDescriptor> result(chain);
    for (UnpackedPtr<CommandEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnEncoderInternalUsageDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<CommandEncoderDescriptor>, DawnEncoderInternalUsageDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<CommandEncoderDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandEncoderDescriptor,
                        UnpackedPtr<CommandEncoderDescriptor>,
                        detail::AdditionalExtensions<CommandEncoderDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "CommandEncoderDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "CommandEncoderDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CommandEncoderDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CompilationMessage> Unpack<CompilationMessage>(UnpackedPtr<CompilationMessage>::PtrType chain) {
    UnpackedPtr<CompilationMessage> result(chain);
    for (UnpackedPtr<CompilationMessage>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnCompilationMessageUtf16>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<CompilationMessage>, DawnCompilationMessageUtf16>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<CompilationMessage>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationMessage,
                        UnpackedPtr<CompilationMessage>,
                        detail::AdditionalExtensions<CompilationMessage>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CompilationMessage>> ValidateAndUnpack<CompilationMessage>(
    UnpackedPtr<CompilationMessage>::PtrType chain) {
    UnpackedPtr<CompilationMessage> result(chain);
    for (UnpackedPtr<CompilationMessage>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnCompilationMessageUtf16>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<CompilationMessage>, DawnCompilationMessageUtf16>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<CompilationMessage>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationMessage,
                        UnpackedPtr<CompilationMessage>,
                        detail::AdditionalExtensions<CompilationMessage>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "CompilationMessage"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "CompilationMessage"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CompilationMessage"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ComputePassDescriptor> Unpack<ComputePassDescriptor>(UnpackedPtr<ComputePassDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePassDescriptor> result(chain);
    for (UnpackedPtr<ComputePassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePassDescriptor,
                        UnpackedPtr<ComputePassDescriptor>,
                        detail::AdditionalExtensions<ComputePassDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ComputePassDescriptor>> ValidateAndUnpack<ComputePassDescriptor>(
    UnpackedPtr<ComputePassDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePassDescriptor> result(chain);
    for (UnpackedPtr<ComputePassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePassDescriptor,
                        UnpackedPtr<ComputePassDescriptor>,
                        detail::AdditionalExtensions<ComputePassDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ComputePassDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ComputePassDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ComputePassDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ComputeState> Unpack<ComputeState>(UnpackedPtr<ComputeState>::PtrType chain) {
    UnpackedPtr<ComputeState> result(chain);
    for (UnpackedPtr<ComputeState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputeState,
                        UnpackedPtr<ComputeState>,
                        detail::AdditionalExtensions<ComputeState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ComputeState>> ValidateAndUnpack<ComputeState>(
    UnpackedPtr<ComputeState>::PtrType chain) {
    UnpackedPtr<ComputeState> result(chain);
    for (UnpackedPtr<ComputeState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputeState,
                        UnpackedPtr<ComputeState>,
                        detail::AdditionalExtensions<ComputeState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ComputeState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ComputeState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ComputeState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<DepthStencilState> Unpack<DepthStencilState>(UnpackedPtr<DepthStencilState>::PtrType chain) {
    UnpackedPtr<DepthStencilState> result(chain);
    for (UnpackedPtr<DepthStencilState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DepthStencilState,
                        UnpackedPtr<DepthStencilState>,
                        detail::AdditionalExtensions<DepthStencilState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<DepthStencilState>> ValidateAndUnpack<DepthStencilState>(
    UnpackedPtr<DepthStencilState>::PtrType chain) {
    UnpackedPtr<DepthStencilState> result(chain);
    for (UnpackedPtr<DepthStencilState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DepthStencilState,
                        UnpackedPtr<DepthStencilState>,
                        detail::AdditionalExtensions<DepthStencilState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "DepthStencilState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "DepthStencilState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "DepthStencilState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ExternalTextureDescriptor> Unpack<ExternalTextureDescriptor>(UnpackedPtr<ExternalTextureDescriptor>::PtrType chain) {
    UnpackedPtr<ExternalTextureDescriptor> result(chain);
    for (UnpackedPtr<ExternalTextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ExternalTextureDescriptor,
                        UnpackedPtr<ExternalTextureDescriptor>,
                        detail::AdditionalExtensions<ExternalTextureDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ExternalTextureDescriptor>> ValidateAndUnpack<ExternalTextureDescriptor>(
    UnpackedPtr<ExternalTextureDescriptor>::PtrType chain) {
    UnpackedPtr<ExternalTextureDescriptor> result(chain);
    for (UnpackedPtr<ExternalTextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ExternalTextureDescriptor,
                        UnpackedPtr<ExternalTextureDescriptor>,
                        detail::AdditionalExtensions<ExternalTextureDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ExternalTextureDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ExternalTextureDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ExternalTextureDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ImageCopyExternalTexture> Unpack<ImageCopyExternalTexture>(UnpackedPtr<ImageCopyExternalTexture>::PtrType chain) {
    UnpackedPtr<ImageCopyExternalTexture> result(chain);
    for (UnpackedPtr<ImageCopyExternalTexture>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ImageCopyExternalTexture,
                        UnpackedPtr<ImageCopyExternalTexture>,
                        detail::AdditionalExtensions<ImageCopyExternalTexture>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ImageCopyExternalTexture>> ValidateAndUnpack<ImageCopyExternalTexture>(
    UnpackedPtr<ImageCopyExternalTexture>::PtrType chain) {
    UnpackedPtr<ImageCopyExternalTexture> result(chain);
    for (UnpackedPtr<ImageCopyExternalTexture>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ImageCopyExternalTexture,
                        UnpackedPtr<ImageCopyExternalTexture>,
                        detail::AdditionalExtensions<ImageCopyExternalTexture>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ImageCopyExternalTexture"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ImageCopyExternalTexture"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ImageCopyExternalTexture"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<InstanceDescriptor> Unpack<InstanceDescriptor>(UnpackedPtr<InstanceDescriptor>::PtrType chain) {
    UnpackedPtr<InstanceDescriptor> result(chain);
    for (UnpackedPtr<InstanceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnTogglesDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnWGSLBlocklist>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWGSLBlocklist>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnWireWGSLControl>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWireWGSLControl>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceDescriptor,
                        UnpackedPtr<InstanceDescriptor>,
                        detail::AdditionalExtensions<InstanceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<InstanceDescriptor>> ValidateAndUnpack<InstanceDescriptor>(
    UnpackedPtr<InstanceDescriptor>::PtrType chain) {
    UnpackedPtr<InstanceDescriptor> result(chain);
    for (UnpackedPtr<InstanceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnTogglesDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnWGSLBlocklist>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWGSLBlocklist>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnWireWGSLControl>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWireWGSLControl>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceDescriptor,
                        UnpackedPtr<InstanceDescriptor>,
                        detail::AdditionalExtensions<InstanceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "InstanceDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "InstanceDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "InstanceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<Limits> Unpack<Limits>(UnpackedPtr<Limits>::PtrType chain) {
    UnpackedPtr<Limits> result(chain);
    for (UnpackedPtr<Limits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<CompatibilityModeLimits>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<Limits>, CompatibilityModeLimits>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<Limits>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnTexelCopyBufferRowAlignmentLimits>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<Limits>, DawnTexelCopyBufferRowAlignmentLimits>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<Limits>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnHostMappedPointerLimits>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<Limits>, DawnHostMappedPointerLimits>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<Limits>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        Limits,
                        UnpackedPtr<Limits>,
                        detail::AdditionalExtensions<Limits>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<Limits>> ValidateAndUnpack<Limits>(
    UnpackedPtr<Limits>::PtrType chain) {
    UnpackedPtr<Limits> result(chain);
    for (UnpackedPtr<Limits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<CompatibilityModeLimits>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<Limits>, CompatibilityModeLimits>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<Limits>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnTexelCopyBufferRowAlignmentLimits>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<Limits>, DawnTexelCopyBufferRowAlignmentLimits>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<Limits>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnHostMappedPointerLimits>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<Limits>, DawnHostMappedPointerLimits>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<Limits>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        Limits,
                        UnpackedPtr<Limits>,
                        detail::AdditionalExtensions<Limits>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "Limits"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "Limits"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "Limits"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderBundleEncoderDescriptor> Unpack<RenderBundleEncoderDescriptor>(UnpackedPtr<RenderBundleEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleEncoderDescriptor> result(chain);
    for (UnpackedPtr<RenderBundleEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<RenderBundleEncoderResourceTable>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderBundleEncoderDescriptor>, RenderBundleEncoderResourceTable>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderBundleEncoderDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleEncoderDescriptor,
                        UnpackedPtr<RenderBundleEncoderDescriptor>,
                        detail::AdditionalExtensions<RenderBundleEncoderDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderBundleEncoderDescriptor>> ValidateAndUnpack<RenderBundleEncoderDescriptor>(
    UnpackedPtr<RenderBundleEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleEncoderDescriptor> result(chain);
    for (UnpackedPtr<RenderBundleEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<RenderBundleEncoderResourceTable>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderBundleEncoderDescriptor>, RenderBundleEncoderResourceTable>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderBundleEncoderDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleEncoderDescriptor,
                        UnpackedPtr<RenderBundleEncoderDescriptor>,
                        detail::AdditionalExtensions<RenderBundleEncoderDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderBundleEncoderDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderBundleEncoderDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderBundleEncoderDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassColorAttachment> Unpack<RenderPassColorAttachment>(UnpackedPtr<RenderPassColorAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassColorAttachment> result(chain);
    for (UnpackedPtr<RenderPassColorAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassColorAttachment,
                        UnpackedPtr<RenderPassColorAttachment>,
                        detail::AdditionalExtensions<RenderPassColorAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassColorAttachment>> ValidateAndUnpack<RenderPassColorAttachment>(
    UnpackedPtr<RenderPassColorAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassColorAttachment> result(chain);
    for (UnpackedPtr<RenderPassColorAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassColorAttachment,
                        UnpackedPtr<RenderPassColorAttachment>,
                        detail::AdditionalExtensions<RenderPassColorAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderPassColorAttachment"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderPassColorAttachment"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassColorAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassStorageAttachment> Unpack<RenderPassStorageAttachment>(UnpackedPtr<RenderPassStorageAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassStorageAttachment> result(chain);
    for (UnpackedPtr<RenderPassStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassStorageAttachment,
                        UnpackedPtr<RenderPassStorageAttachment>,
                        detail::AdditionalExtensions<RenderPassStorageAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassStorageAttachment>> ValidateAndUnpack<RenderPassStorageAttachment>(
    UnpackedPtr<RenderPassStorageAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassStorageAttachment> result(chain);
    for (UnpackedPtr<RenderPassStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassStorageAttachment,
                        UnpackedPtr<RenderPassStorageAttachment>,
                        detail::AdditionalExtensions<RenderPassStorageAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderPassStorageAttachment"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderPassStorageAttachment"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassStorageAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RequestAdapterOptions> Unpack<RequestAdapterOptions>(UnpackedPtr<RequestAdapterOptions>::PtrType chain) {
    UnpackedPtr<RequestAdapterOptions> result(chain);
    for (UnpackedPtr<RequestAdapterOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<RequestAdapterWebXROptions>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, RequestAdapterWebXROptions>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                );
                break;
            }
            case STypeFor<RequestAdapterWebGPUBackendOptions>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, RequestAdapterWebGPUBackendOptions>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, DawnTogglesDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestAdapterOptions,
                        UnpackedPtr<RequestAdapterOptions>,
                        detail::AdditionalExtensions<RequestAdapterOptions>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RequestAdapterOptions>> ValidateAndUnpack<RequestAdapterOptions>(
    UnpackedPtr<RequestAdapterOptions>::PtrType chain) {
    UnpackedPtr<RequestAdapterOptions> result(chain);
    for (UnpackedPtr<RequestAdapterOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<RequestAdapterWebXROptions>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, RequestAdapterWebXROptions>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<RequestAdapterWebGPUBackendOptions>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, RequestAdapterWebGPUBackendOptions>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, DawnTogglesDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestAdapterOptions,
                        UnpackedPtr<RequestAdapterOptions>,
                        detail::AdditionalExtensions<RequestAdapterOptions>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RequestAdapterOptions"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RequestAdapterOptions"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RequestAdapterOptions"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SamplerDescriptor> Unpack<SamplerDescriptor>(UnpackedPtr<SamplerDescriptor>::PtrType chain) {
    UnpackedPtr<SamplerDescriptor> result(chain);
    for (UnpackedPtr<SamplerDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SamplerDescriptor>, YCbCrVkDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SamplerDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerDescriptor,
                        UnpackedPtr<SamplerDescriptor>,
                        detail::AdditionalExtensions<SamplerDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SamplerDescriptor>> ValidateAndUnpack<SamplerDescriptor>(
    UnpackedPtr<SamplerDescriptor>::PtrType chain) {
    UnpackedPtr<SamplerDescriptor> result(chain);
    for (UnpackedPtr<SamplerDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SamplerDescriptor>, YCbCrVkDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SamplerDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerDescriptor,
                        UnpackedPtr<SamplerDescriptor>,
                        detail::AdditionalExtensions<SamplerDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SamplerDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SamplerDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SamplerDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ShaderModuleDescriptor> Unpack<ShaderModuleDescriptor>(UnpackedPtr<ShaderModuleDescriptor>::PtrType chain) {
    UnpackedPtr<ShaderModuleDescriptor> result(chain);
    for (UnpackedPtr<ShaderModuleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<ShaderSourceSPIRV>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderSourceSPIRV>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<ShaderSourceWGSL>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderSourceWGSL>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnShaderModuleSPIRVOptionsDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, DawnShaderModuleSPIRVOptionsDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<ShaderModuleCompilationOptions>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleCompilationOptions>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ShaderModuleDescriptor,
                        UnpackedPtr<ShaderModuleDescriptor>,
                        detail::AdditionalExtensions<ShaderModuleDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ShaderModuleDescriptor>> ValidateAndUnpack<ShaderModuleDescriptor>(
    UnpackedPtr<ShaderModuleDescriptor>::PtrType chain) {
    UnpackedPtr<ShaderModuleDescriptor> result(chain);
    for (UnpackedPtr<ShaderModuleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<ShaderSourceSPIRV>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderSourceSPIRV>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<ShaderSourceWGSL>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderSourceWGSL>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnShaderModuleSPIRVOptionsDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, DawnShaderModuleSPIRVOptionsDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<ShaderModuleCompilationOptions>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleCompilationOptions>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ShaderModuleDescriptor,
                        UnpackedPtr<ShaderModuleDescriptor>,
                        detail::AdditionalExtensions<ShaderModuleDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ShaderModuleDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ShaderModuleDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ShaderModuleDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryDescriptor> Unpack<SharedBufferMemoryDescriptor>(UnpackedPtr<SharedBufferMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryDescriptor> result(chain);
    for (UnpackedPtr<SharedBufferMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedBufferMemoryFromWindowsHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedBufferMemoryDescriptor>, SharedBufferMemoryFromWindowsHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedBufferMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryDescriptor,
                        UnpackedPtr<SharedBufferMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryDescriptor>> ValidateAndUnpack<SharedBufferMemoryDescriptor>(
    UnpackedPtr<SharedBufferMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryDescriptor> result(chain);
    for (UnpackedPtr<SharedBufferMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedBufferMemoryFromWindowsHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedBufferMemoryDescriptor>, SharedBufferMemoryFromWindowsHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedBufferMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryDescriptor,
                        UnpackedPtr<SharedBufferMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedBufferMemoryDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedBufferMemoryDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedFenceDescriptor> Unpack<SharedFenceDescriptor>(UnpackedPtr<SharedFenceDescriptor>::PtrType chain) {
    UnpackedPtr<SharedFenceDescriptor> result(chain);
    for (UnpackedPtr<SharedFenceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreOpaqueFDDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceSyncFDDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceSyncFDDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreZirconHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceDXGISharedHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceMTLSharedEventDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceEGLSyncDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceEGLSyncDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceDescriptor,
                        UnpackedPtr<SharedFenceDescriptor>,
                        detail::AdditionalExtensions<SharedFenceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedFenceDescriptor>> ValidateAndUnpack<SharedFenceDescriptor>(
    UnpackedPtr<SharedFenceDescriptor>::PtrType chain) {
    UnpackedPtr<SharedFenceDescriptor> result(chain);
    for (UnpackedPtr<SharedFenceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreOpaqueFDDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceSyncFDDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceSyncFDDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreZirconHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceDXGISharedHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceMTLSharedEventDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceEGLSyncDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceEGLSyncDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceDescriptor,
                        UnpackedPtr<SharedFenceDescriptor>,
                        detail::AdditionalExtensions<SharedFenceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedFenceDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedFenceDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedFenceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedFenceExportInfo> Unpack<SharedFenceExportInfo>(UnpackedPtr<SharedFenceExportInfo>::PtrType chain) {
    UnpackedPtr<SharedFenceExportInfo> result(chain);
    for (UnpackedPtr<SharedFenceExportInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreOpaqueFDExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceSyncFDExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceSyncFDExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreZirconHandleExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceDXGISharedHandleExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceMTLSharedEventExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceEGLSyncExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceEGLSyncExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceExportInfo,
                        UnpackedPtr<SharedFenceExportInfo>,
                        detail::AdditionalExtensions<SharedFenceExportInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedFenceExportInfo>> ValidateAndUnpack<SharedFenceExportInfo>(
    UnpackedPtr<SharedFenceExportInfo>::PtrType chain) {
    UnpackedPtr<SharedFenceExportInfo> result(chain);
    for (UnpackedPtr<SharedFenceExportInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreOpaqueFDExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceSyncFDExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceSyncFDExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreZirconHandleExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceDXGISharedHandleExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceMTLSharedEventExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceEGLSyncExportInfo>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceEGLSyncExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceExportInfo,
                        UnpackedPtr<SharedFenceExportInfo>,
                        detail::AdditionalExtensions<SharedFenceExportInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedFenceExportInfo"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedFenceExportInfo"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedFenceExportInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor> Unpack<SharedTextureMemoryBeginAccessDescriptor>(UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor> result(chain);
    for (UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkImageLayoutBeginState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryVkImageLayoutBeginState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryD3DSwapchainBeginState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryD3DSwapchainBeginState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryD3D11BeginState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryD3D11BeginState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryBeginAccessDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>> ValidateAndUnpack<SharedTextureMemoryBeginAccessDescriptor>(
    UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor> result(chain);
    for (UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkImageLayoutBeginState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryVkImageLayoutBeginState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryD3DSwapchainBeginState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryD3DSwapchainBeginState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryD3D11BeginState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryD3D11BeginState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryBeginAccessDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedTextureMemoryBeginAccessDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedTextureMemoryBeginAccessDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryBeginAccessDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceDescriptor> Unpack<SurfaceDescriptor>(UnpackedPtr<SurfaceDescriptor>::PtrType chain) {
    UnpackedPtr<SurfaceDescriptor> result(chain);
    for (UnpackedPtr<SurfaceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SurfaceSourceAndroidNativeWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceAndroidNativeWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceSourceMetalLayer>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceMetalLayer>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceSourceWindowsHWND>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceWindowsHWND>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceSourceXCBWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceXCBWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceSourceXlibWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceXlibWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceSourceWaylandSurface>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceWaylandSurface>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsCoreWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsCoreWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsUWPSwapChainPanel>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsUWPSwapChainPanel>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsWinUISwapChainPanel>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsWinUISwapChainPanel>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceColorManagement>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceColorManagement>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceDescriptor,
                        UnpackedPtr<SurfaceDescriptor>,
                        detail::AdditionalExtensions<SurfaceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceDescriptor>> ValidateAndUnpack<SurfaceDescriptor>(
    UnpackedPtr<SurfaceDescriptor>::PtrType chain) {
    UnpackedPtr<SurfaceDescriptor> result(chain);
    for (UnpackedPtr<SurfaceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SurfaceSourceAndroidNativeWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceAndroidNativeWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceSourceMetalLayer>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceMetalLayer>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceSourceWindowsHWND>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceWindowsHWND>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceSourceXCBWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceXCBWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceSourceXlibWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceXlibWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceSourceWaylandSurface>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceSourceWaylandSurface>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsCoreWindow>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsCoreWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsUWPSwapChainPanel>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsUWPSwapChainPanel>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsWinUISwapChainPanel>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsWinUISwapChainPanel>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceColorManagement>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceColorManagement>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceDescriptor,
                        UnpackedPtr<SurfaceDescriptor>,
                        detail::AdditionalExtensions<SurfaceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SurfaceDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SurfaceDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureDescriptor> Unpack<TextureDescriptor>(UnpackedPtr<TextureDescriptor>::PtrType chain) {
    UnpackedPtr<TextureDescriptor> result(chain);
    for (UnpackedPtr<TextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<TextureBindingViewDimension>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, TextureBindingViewDimension>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnTextureInternalUsageDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, DawnTextureInternalUsageDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureDescriptor,
                        UnpackedPtr<TextureDescriptor>,
                        detail::AdditionalExtensions<TextureDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureDescriptor>> ValidateAndUnpack<TextureDescriptor>(
    UnpackedPtr<TextureDescriptor>::PtrType chain) {
    UnpackedPtr<TextureDescriptor> result(chain);
    for (UnpackedPtr<TextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<TextureBindingViewDimension>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, TextureBindingViewDimension>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnTextureInternalUsageDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, DawnTextureInternalUsageDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureDescriptor,
                        UnpackedPtr<TextureDescriptor>,
                        detail::AdditionalExtensions<TextureDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "TextureDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "TextureDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<VertexBufferLayout> Unpack<VertexBufferLayout>(UnpackedPtr<VertexBufferLayout>::PtrType chain) {
    UnpackedPtr<VertexBufferLayout> result(chain);
    for (UnpackedPtr<VertexBufferLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexBufferLayout,
                        UnpackedPtr<VertexBufferLayout>,
                        detail::AdditionalExtensions<VertexBufferLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<VertexBufferLayout>> ValidateAndUnpack<VertexBufferLayout>(
    UnpackedPtr<VertexBufferLayout>::PtrType chain) {
    UnpackedPtr<VertexBufferLayout> result(chain);
    for (UnpackedPtr<VertexBufferLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexBufferLayout,
                        UnpackedPtr<VertexBufferLayout>,
                        detail::AdditionalExtensions<VertexBufferLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "VertexBufferLayout"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "VertexBufferLayout"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "VertexBufferLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<AdapterInfo> Unpack<AdapterInfo>(UnpackedPtr<AdapterInfo>::PtrType chain) {
    UnpackedPtr<AdapterInfo> result(chain);
    for (UnpackedPtr<AdapterInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnAdapterPropertiesPowerPreference>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, DawnAdapterPropertiesPowerPreference>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesMemoryHeaps>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesMemoryHeaps>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesD3D>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesD3D>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesVk>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesVk>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesDrm>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesDrm>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesWGPU>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesWGPU>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesSubgroupMatrixConfigs>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesSubgroupMatrixConfigs>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        AdapterInfo,
                        UnpackedPtr<AdapterInfo>,
                        detail::AdditionalExtensions<AdapterInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<AdapterInfo>> ValidateAndUnpack<AdapterInfo>(
    UnpackedPtr<AdapterInfo>::PtrType chain) {
    UnpackedPtr<AdapterInfo> result(chain);
    for (UnpackedPtr<AdapterInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnAdapterPropertiesPowerPreference>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, DawnAdapterPropertiesPowerPreference>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesMemoryHeaps>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesMemoryHeaps>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesD3D>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesD3D>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesVk>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesVk>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesDrm>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesDrm>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesWGPU>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesWGPU>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesSubgroupMatrixConfigs>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<AdapterInfo>, AdapterPropertiesSubgroupMatrixConfigs>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterInfo>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        AdapterInfo,
                        UnpackedPtr<AdapterInfo>,
                        detail::AdditionalExtensions<AdapterInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "AdapterInfo"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "AdapterInfo"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "AdapterInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupDescriptor> Unpack<BindGroupDescriptor>(UnpackedPtr<BindGroupDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupDescriptor> result(chain);
    for (UnpackedPtr<BindGroupDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupDescriptor,
                        UnpackedPtr<BindGroupDescriptor>,
                        detail::AdditionalExtensions<BindGroupDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupDescriptor>> ValidateAndUnpack<BindGroupDescriptor>(
    UnpackedPtr<BindGroupDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupDescriptor> result(chain);
    for (UnpackedPtr<BindGroupDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupDescriptor,
                        UnpackedPtr<BindGroupDescriptor>,
                        detail::AdditionalExtensions<BindGroupDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BindGroupDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BindGroupDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupLayoutDescriptor> Unpack<BindGroupLayoutDescriptor>(UnpackedPtr<BindGroupLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutDescriptor> result(chain);
    for (UnpackedPtr<BindGroupLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutDescriptor,
                        UnpackedPtr<BindGroupLayoutDescriptor>,
                        detail::AdditionalExtensions<BindGroupLayoutDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupLayoutDescriptor>> ValidateAndUnpack<BindGroupLayoutDescriptor>(
    UnpackedPtr<BindGroupLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutDescriptor> result(chain);
    for (UnpackedPtr<BindGroupLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutDescriptor,
                        UnpackedPtr<BindGroupLayoutDescriptor>,
                        detail::AdditionalExtensions<BindGroupLayoutDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "BindGroupLayoutDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "BindGroupLayoutDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupLayoutDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ColorTargetState> Unpack<ColorTargetState>(UnpackedPtr<ColorTargetState>::PtrType chain) {
    UnpackedPtr<ColorTargetState> result(chain);
    for (UnpackedPtr<ColorTargetState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<ColorTargetStateExpandResolveTextureDawn>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ColorTargetState>, ColorTargetStateExpandResolveTextureDawn>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ColorTargetState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ColorTargetState,
                        UnpackedPtr<ColorTargetState>,
                        detail::AdditionalExtensions<ColorTargetState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ColorTargetState>> ValidateAndUnpack<ColorTargetState>(
    UnpackedPtr<ColorTargetState>::PtrType chain) {
    UnpackedPtr<ColorTargetState> result(chain);
    for (UnpackedPtr<ColorTargetState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<ColorTargetStateExpandResolveTextureDawn>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<ColorTargetState>, ColorTargetStateExpandResolveTextureDawn>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ColorTargetState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ColorTargetState,
                        UnpackedPtr<ColorTargetState>,
                        detail::AdditionalExtensions<ColorTargetState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ColorTargetState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ColorTargetState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ColorTargetState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CompilationInfo> Unpack<CompilationInfo>(UnpackedPtr<CompilationInfo>::PtrType chain) {
    UnpackedPtr<CompilationInfo> result(chain);
    for (UnpackedPtr<CompilationInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationInfo,
                        UnpackedPtr<CompilationInfo>,
                        detail::AdditionalExtensions<CompilationInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CompilationInfo>> ValidateAndUnpack<CompilationInfo>(
    UnpackedPtr<CompilationInfo>::PtrType chain) {
    UnpackedPtr<CompilationInfo> result(chain);
    for (UnpackedPtr<CompilationInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationInfo,
                        UnpackedPtr<CompilationInfo>,
                        detail::AdditionalExtensions<CompilationInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "CompilationInfo"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "CompilationInfo"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CompilationInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ComputePipelineDescriptor> Unpack<ComputePipelineDescriptor>(UnpackedPtr<ComputePipelineDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePipelineDescriptor> result(chain);
    for (UnpackedPtr<ComputePipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePipelineDescriptor,
                        UnpackedPtr<ComputePipelineDescriptor>,
                        detail::AdditionalExtensions<ComputePipelineDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ComputePipelineDescriptor>> ValidateAndUnpack<ComputePipelineDescriptor>(
    UnpackedPtr<ComputePipelineDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePipelineDescriptor> result(chain);
    for (UnpackedPtr<ComputePipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePipelineDescriptor,
                        UnpackedPtr<ComputePipelineDescriptor>,
                        detail::AdditionalExtensions<ComputePipelineDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "ComputePipelineDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "ComputePipelineDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ComputePipelineDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<DawnFormatCapabilities> Unpack<DawnFormatCapabilities>(UnpackedPtr<DawnFormatCapabilities>::PtrType chain) {
    UnpackedPtr<DawnFormatCapabilities> result(chain);
    for (UnpackedPtr<DawnFormatCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnDrmFormatCapabilities>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DawnFormatCapabilities>, DawnDrmFormatCapabilities>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DawnFormatCapabilities>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DawnFormatCapabilities,
                        UnpackedPtr<DawnFormatCapabilities>,
                        detail::AdditionalExtensions<DawnFormatCapabilities>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<DawnFormatCapabilities>> ValidateAndUnpack<DawnFormatCapabilities>(
    UnpackedPtr<DawnFormatCapabilities>::PtrType chain) {
    UnpackedPtr<DawnFormatCapabilities> result(chain);
    for (UnpackedPtr<DawnFormatCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnDrmFormatCapabilities>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DawnFormatCapabilities>, DawnDrmFormatCapabilities>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DawnFormatCapabilities>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DawnFormatCapabilities,
                        UnpackedPtr<DawnFormatCapabilities>,
                        detail::AdditionalExtensions<DawnFormatCapabilities>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "DawnFormatCapabilities"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "DawnFormatCapabilities"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "DawnFormatCapabilities"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<DeviceDescriptor> Unpack<DeviceDescriptor>(UnpackedPtr<DeviceDescriptor>::PtrType chain) {
    UnpackedPtr<DeviceDescriptor> result(chain);
    for (UnpackedPtr<DeviceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnConsumeAdapterDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnConsumeAdapterDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnTogglesDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnCacheDeviceDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnCacheDeviceDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnDeviceAllocatorControl>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnDeviceAllocatorControl>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnFakeDeviceInitializeErrorForTesting>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnFakeDeviceInitializeErrorForTesting>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DeviceDescriptor,
                        UnpackedPtr<DeviceDescriptor>,
                        detail::AdditionalExtensions<DeviceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<DeviceDescriptor>> ValidateAndUnpack<DeviceDescriptor>(
    UnpackedPtr<DeviceDescriptor>::PtrType chain) {
    UnpackedPtr<DeviceDescriptor> result(chain);
    for (UnpackedPtr<DeviceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnConsumeAdapterDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnConsumeAdapterDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnTogglesDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnCacheDeviceDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnCacheDeviceDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnDeviceAllocatorControl>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnDeviceAllocatorControl>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnFakeDeviceInitializeErrorForTesting>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnFakeDeviceInitializeErrorForTesting>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DeviceDescriptor,
                        UnpackedPtr<DeviceDescriptor>,
                        detail::AdditionalExtensions<DeviceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "DeviceDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "DeviceDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "DeviceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PipelineLayoutDescriptor> Unpack<PipelineLayoutDescriptor>(UnpackedPtr<PipelineLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<PipelineLayoutDescriptor> result(chain);
    for (UnpackedPtr<PipelineLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<PipelineLayoutResourceTable>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<PipelineLayoutDescriptor>, PipelineLayoutResourceTable>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<PipelineLayoutDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<PipelineLayoutPixelLocalStorage>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<PipelineLayoutDescriptor>, PipelineLayoutPixelLocalStorage>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<PipelineLayoutDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutDescriptor,
                        UnpackedPtr<PipelineLayoutDescriptor>,
                        detail::AdditionalExtensions<PipelineLayoutDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PipelineLayoutDescriptor>> ValidateAndUnpack<PipelineLayoutDescriptor>(
    UnpackedPtr<PipelineLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<PipelineLayoutDescriptor> result(chain);
    for (UnpackedPtr<PipelineLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<PipelineLayoutResourceTable>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<PipelineLayoutDescriptor>, PipelineLayoutResourceTable>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<PipelineLayoutDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<PipelineLayoutPixelLocalStorage>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<PipelineLayoutDescriptor>, PipelineLayoutPixelLocalStorage>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<PipelineLayoutDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutDescriptor,
                        UnpackedPtr<PipelineLayoutDescriptor>,
                        detail::AdditionalExtensions<PipelineLayoutDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "PipelineLayoutDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "PipelineLayoutDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PipelineLayoutDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryDescriptor> Unpack<SharedTextureMemoryDescriptor>(UnpackedPtr<SharedTextureMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryDescriptor> result(chain);
    for (UnpackedPtr<SharedTextureMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkDedicatedAllocationDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryVkDedicatedAllocationDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryAHardwareBufferDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryAHardwareBufferDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryDmaBufDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDmaBufDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryOpaqueFDDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryOpaqueFDDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryZirconHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryZirconHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDXGISharedHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryIOSurfaceDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryIOSurfaceDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryEGLImageDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryEGLImageDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryDescriptor,
                        UnpackedPtr<SharedTextureMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryDescriptor>> ValidateAndUnpack<SharedTextureMemoryDescriptor>(
    UnpackedPtr<SharedTextureMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryDescriptor> result(chain);
    for (UnpackedPtr<SharedTextureMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkDedicatedAllocationDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryVkDedicatedAllocationDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryAHardwareBufferDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryAHardwareBufferDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryDmaBufDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDmaBufDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryOpaqueFDDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryOpaqueFDDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryZirconHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryZirconHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDXGISharedHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryIOSurfaceDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryIOSurfaceDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryEGLImageDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryEGLImageDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryDescriptor,
                        UnpackedPtr<SharedTextureMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedTextureMemoryDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedTextureMemoryDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryEndAccessState> Unpack<SharedTextureMemoryEndAccessState>(UnpackedPtr<SharedTextureMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryEndAccessState> result(chain);
    for (UnpackedPtr<SharedTextureMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryMetalEndAccessState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryEndAccessState>, SharedTextureMemoryMetalEndAccessState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryEndAccessState>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryVkImageLayoutEndState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryEndAccessState>, SharedTextureMemoryVkImageLayoutEndState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryEndAccessState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryEndAccessState,
                        UnpackedPtr<SharedTextureMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedTextureMemoryEndAccessState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryEndAccessState>> ValidateAndUnpack<SharedTextureMemoryEndAccessState>(
    UnpackedPtr<SharedTextureMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryEndAccessState> result(chain);
    for (UnpackedPtr<SharedTextureMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryMetalEndAccessState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryEndAccessState>, SharedTextureMemoryMetalEndAccessState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryEndAccessState>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryVkImageLayoutEndState>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryEndAccessState>, SharedTextureMemoryVkImageLayoutEndState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryEndAccessState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryEndAccessState,
                        UnpackedPtr<SharedTextureMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedTextureMemoryEndAccessState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedTextureMemoryEndAccessState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedTextureMemoryEndAccessState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryEndAccessState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryProperties> Unpack<SharedTextureMemoryProperties>(UnpackedPtr<SharedTextureMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryProperties> result(chain);
    for (UnpackedPtr<SharedTextureMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryAHardwareBufferProperties>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryProperties>, SharedTextureMemoryAHardwareBufferProperties>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryProperties>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryProperties,
                        UnpackedPtr<SharedTextureMemoryProperties>,
                        detail::AdditionalExtensions<SharedTextureMemoryProperties>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryProperties>> ValidateAndUnpack<SharedTextureMemoryProperties>(
    UnpackedPtr<SharedTextureMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryProperties> result(chain);
    for (UnpackedPtr<SharedTextureMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryAHardwareBufferProperties>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryProperties>, SharedTextureMemoryAHardwareBufferProperties>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryProperties>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryProperties,
                        UnpackedPtr<SharedTextureMemoryProperties>,
                        detail::AdditionalExtensions<SharedTextureMemoryProperties>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "SharedTextureMemoryProperties"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "SharedTextureMemoryProperties"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryProperties"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureViewDescriptor> Unpack<TextureViewDescriptor>(UnpackedPtr<TextureViewDescriptor>::PtrType chain) {
    UnpackedPtr<TextureViewDescriptor> result(chain);
    for (UnpackedPtr<TextureViewDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<TextureComponentSwizzleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureViewDescriptor>, TextureComponentSwizzleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureViewDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureViewDescriptor>, YCbCrVkDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureViewDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureViewDescriptor,
                        UnpackedPtr<TextureViewDescriptor>,
                        detail::AdditionalExtensions<TextureViewDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureViewDescriptor>> ValidateAndUnpack<TextureViewDescriptor>(
    UnpackedPtr<TextureViewDescriptor>::PtrType chain) {
    UnpackedPtr<TextureViewDescriptor> result(chain);
    for (UnpackedPtr<TextureViewDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<TextureComponentSwizzleDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureViewDescriptor>, TextureComponentSwizzleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureViewDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<TextureViewDescriptor>, YCbCrVkDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureViewDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureViewDescriptor,
                        UnpackedPtr<TextureViewDescriptor>,
                        detail::AdditionalExtensions<TextureViewDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "TextureViewDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "TextureViewDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureViewDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<VertexState> Unpack<VertexState>(UnpackedPtr<VertexState>::PtrType chain) {
    UnpackedPtr<VertexState> result(chain);
    for (UnpackedPtr<VertexState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexState,
                        UnpackedPtr<VertexState>,
                        detail::AdditionalExtensions<VertexState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<VertexState>> ValidateAndUnpack<VertexState>(
    UnpackedPtr<VertexState>::PtrType chain) {
    UnpackedPtr<VertexState> result(chain);
    for (UnpackedPtr<VertexState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexState,
                        UnpackedPtr<VertexState>,
                        detail::AdditionalExtensions<VertexState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "VertexState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "VertexState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "VertexState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<FragmentState> Unpack<FragmentState>(UnpackedPtr<FragmentState>::PtrType chain) {
    UnpackedPtr<FragmentState> result(chain);
    for (UnpackedPtr<FragmentState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        FragmentState,
                        UnpackedPtr<FragmentState>,
                        detail::AdditionalExtensions<FragmentState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<FragmentState>> ValidateAndUnpack<FragmentState>(
    UnpackedPtr<FragmentState>::PtrType chain) {
    UnpackedPtr<FragmentState> result(chain);
    for (UnpackedPtr<FragmentState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        FragmentState,
                        UnpackedPtr<FragmentState>,
                        detail::AdditionalExtensions<FragmentState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "FragmentState"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "FragmentState"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "FragmentState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassDescriptor> Unpack<RenderPassDescriptor>(UnpackedPtr<RenderPassDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPassDescriptor> result(chain);
    for (UnpackedPtr<RenderPassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnRenderPassSampleCount>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, DawnRenderPassSampleCount>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<RenderPassMaxDrawCount>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassMaxDrawCount>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<RenderPassRenderAreaRect>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassRenderAreaRect>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<RenderPassDescriptorResolveRect>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassDescriptorResolveRect>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<RenderPassPixelLocalStorage>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassPixelLocalStorage>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassDescriptor,
                        UnpackedPtr<RenderPassDescriptor>,
                        detail::AdditionalExtensions<RenderPassDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassDescriptor>> ValidateAndUnpack<RenderPassDescriptor>(
    UnpackedPtr<RenderPassDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPassDescriptor> result(chain);
    for (UnpackedPtr<RenderPassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnRenderPassSampleCount>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, DawnRenderPassSampleCount>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<RenderPassMaxDrawCount>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassMaxDrawCount>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<RenderPassRenderAreaRect>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassRenderAreaRect>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<RenderPassDescriptorResolveRect>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassDescriptorResolveRect>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<RenderPassPixelLocalStorage>: {
                using ExtPtrType =
                    detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassPixelLocalStorage>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassDescriptor,
                        UnpackedPtr<RenderPassDescriptor>,
                        detail::AdditionalExtensions<RenderPassDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderPassDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderPassDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPipelineDescriptor> Unpack<RenderPipelineDescriptor>(UnpackedPtr<RenderPipelineDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPipelineDescriptor> result(chain);
    for (UnpackedPtr<RenderPipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPipelineDescriptor,
                        UnpackedPtr<RenderPipelineDescriptor>,
                        detail::AdditionalExtensions<RenderPipelineDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPipelineDescriptor>> ValidateAndUnpack<RenderPipelineDescriptor>(
    UnpackedPtr<RenderPipelineDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPipelineDescriptor> result(chain);
    for (UnpackedPtr<RenderPipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPipelineDescriptor,
                        UnpackedPtr<RenderPipelineDescriptor>,
                        detail::AdditionalExtensions<RenderPipelineDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    if (next->sType == wgpu::SType::DawnInjectedInvalidSType) {
                        // TODO(crbug.com/399470698): Need to reinterpret cast to base C type
                        // for now because in/out typing are differentiated in C++ bindings.
                        auto* ext = reinterpret_cast<const WGPUDawnInjectedInvalidSType*>(next);
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            wgpu::SType(ext->invalidSType), "RenderPipelineDescriptor"
                        );
                    } else {
                        return DAWN_VALIDATION_ERROR(
                            "Unexpected chained struct of type %s found on %s chain.",
                            next->sType, "RenderPipelineDescriptor"
                        );
                    }
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPipelineDescriptor"
            );
        }
    }
    return result;
}

}  // namespace dawn::native
