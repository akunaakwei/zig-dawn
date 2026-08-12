
#include "dawn/native/wgpu_structs_autogen.h"

#include <cstring>
#include <tuple>

#include "src/utils/assert.h"

#if defined(__GNUC__) || defined(__clang__)
// error: 'offsetof' within non-standard-layout type 'wgpu::XXX' is conditionally-supported
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif

namespace dawn::native {

    static_assert(sizeof(ChainedStruct) == sizeof(WGPUChainedStruct),
            "sizeof mismatch for ChainedStruct");
    static_assert(alignof(ChainedStruct) == alignof(WGPUChainedStruct),
            "alignof mismatch for ChainedStruct");
    static_assert(offsetof(ChainedStruct, nextInChain) == offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ChainedStruct::nextInChain");
    static_assert(offsetof(ChainedStruct, sType) == offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ChainedStruct::sType");


    bool StringView::operator==(const StringView& rhs) const {
        return data == rhs.data && length == rhs.length;
    }

    // NOLINTBEGIN(bugprone-invalid-enum-default-initialization)


    static_assert(sizeof(AdapterPropertiesD3D) == sizeof(WGPUAdapterPropertiesD3D), "sizeof mismatch for AdapterPropertiesD3D");
    static_assert(alignof(AdapterPropertiesD3D) == alignof(WGPUAdapterPropertiesD3D), "alignof mismatch for AdapterPropertiesD3D");

    static_assert(offsetof(AdapterPropertiesD3D, nextInChain) == offsetof(WGPUAdapterPropertiesD3D, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for AdapterPropertiesD3D::nextInChain");
    static_assert(offsetof(AdapterPropertiesD3D, sType) == offsetof(WGPUAdapterPropertiesD3D, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for AdapterPropertiesD3D::sType");
    static_assert(offsetof(AdapterPropertiesD3D, shaderModel) == offsetof(WGPUAdapterPropertiesD3D, shaderModel),
                 "offsetof mismatch for AdapterPropertiesD3D::shaderModel");

    bool AdapterPropertiesD3D::operator==(const AdapterPropertiesD3D& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (shaderModel != rhs.shaderModel) { return false; }
        return true;
    }


    static_assert(sizeof(AdapterPropertiesDrm) == sizeof(WGPUAdapterPropertiesDrm), "sizeof mismatch for AdapterPropertiesDrm");
    static_assert(alignof(AdapterPropertiesDrm) == alignof(WGPUAdapterPropertiesDrm), "alignof mismatch for AdapterPropertiesDrm");

    static_assert(offsetof(AdapterPropertiesDrm, nextInChain) == offsetof(WGPUAdapterPropertiesDrm, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for AdapterPropertiesDrm::nextInChain");
    static_assert(offsetof(AdapterPropertiesDrm, sType) == offsetof(WGPUAdapterPropertiesDrm, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for AdapterPropertiesDrm::sType");
    static_assert(offsetof(AdapterPropertiesDrm, hasPrimary) == offsetof(WGPUAdapterPropertiesDrm, hasPrimary),
                 "offsetof mismatch for AdapterPropertiesDrm::hasPrimary");
    static_assert(offsetof(AdapterPropertiesDrm, hasRender) == offsetof(WGPUAdapterPropertiesDrm, hasRender),
                 "offsetof mismatch for AdapterPropertiesDrm::hasRender");
    static_assert(offsetof(AdapterPropertiesDrm, primaryMajor) == offsetof(WGPUAdapterPropertiesDrm, primaryMajor),
                 "offsetof mismatch for AdapterPropertiesDrm::primaryMajor");
    static_assert(offsetof(AdapterPropertiesDrm, primaryMinor) == offsetof(WGPUAdapterPropertiesDrm, primaryMinor),
                 "offsetof mismatch for AdapterPropertiesDrm::primaryMinor");
    static_assert(offsetof(AdapterPropertiesDrm, renderMajor) == offsetof(WGPUAdapterPropertiesDrm, renderMajor),
                 "offsetof mismatch for AdapterPropertiesDrm::renderMajor");
    static_assert(offsetof(AdapterPropertiesDrm, renderMinor) == offsetof(WGPUAdapterPropertiesDrm, renderMinor),
                 "offsetof mismatch for AdapterPropertiesDrm::renderMinor");

    bool AdapterPropertiesDrm::operator==(const AdapterPropertiesDrm& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (hasPrimary != rhs.hasPrimary) { return false; }
        if (hasRender != rhs.hasRender) { return false; }
        if (primaryMajor != rhs.primaryMajor) { return false; }
        if (primaryMinor != rhs.primaryMinor) { return false; }
        if (renderMajor != rhs.renderMajor) { return false; }
        if (renderMinor != rhs.renderMinor) { return false; }
        return true;
    }


    static_assert(sizeof(AdapterPropertiesVk) == sizeof(WGPUAdapterPropertiesVk), "sizeof mismatch for AdapterPropertiesVk");
    static_assert(alignof(AdapterPropertiesVk) == alignof(WGPUAdapterPropertiesVk), "alignof mismatch for AdapterPropertiesVk");

    static_assert(offsetof(AdapterPropertiesVk, nextInChain) == offsetof(WGPUAdapterPropertiesVk, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for AdapterPropertiesVk::nextInChain");
    static_assert(offsetof(AdapterPropertiesVk, sType) == offsetof(WGPUAdapterPropertiesVk, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for AdapterPropertiesVk::sType");
    static_assert(offsetof(AdapterPropertiesVk, driverVersion) == offsetof(WGPUAdapterPropertiesVk, driverVersion),
                 "offsetof mismatch for AdapterPropertiesVk::driverVersion");

    bool AdapterPropertiesVk::operator==(const AdapterPropertiesVk& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (driverVersion != rhs.driverVersion) { return false; }
        return true;
    }


    static_assert(sizeof(AdapterPropertiesWGPU) == sizeof(WGPUAdapterPropertiesWGPU), "sizeof mismatch for AdapterPropertiesWGPU");
    static_assert(alignof(AdapterPropertiesWGPU) == alignof(WGPUAdapterPropertiesWGPU), "alignof mismatch for AdapterPropertiesWGPU");

    static_assert(offsetof(AdapterPropertiesWGPU, nextInChain) == offsetof(WGPUAdapterPropertiesWGPU, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for AdapterPropertiesWGPU::nextInChain");
    static_assert(offsetof(AdapterPropertiesWGPU, sType) == offsetof(WGPUAdapterPropertiesWGPU, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for AdapterPropertiesWGPU::sType");
    static_assert(offsetof(AdapterPropertiesWGPU, backendType) == offsetof(WGPUAdapterPropertiesWGPU, backendType),
                 "offsetof mismatch for AdapterPropertiesWGPU::backendType");

    bool AdapterPropertiesWGPU::operator==(const AdapterPropertiesWGPU& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (backendType != rhs.backendType) { return false; }
        return true;
    }


    static_assert(sizeof(BindingResource) == sizeof(WGPUBindingResource), "sizeof mismatch for BindingResource");
    static_assert(alignof(BindingResource) == alignof(WGPUBindingResource), "alignof mismatch for BindingResource");

    static_assert(offsetof(BindingResource, nextInChain) == offsetof(WGPUBindingResource, nextInChain),
            "offsetof mismatch for BindingResource::nextInChain");
    static_assert(offsetof(BindingResource, buffer) == offsetof(WGPUBindingResource, buffer),
                 "offsetof mismatch for BindingResource::buffer");
    static_assert(offsetof(BindingResource, offset) == offsetof(WGPUBindingResource, offset),
                 "offsetof mismatch for BindingResource::offset");
    static_assert(offsetof(BindingResource, size) == offsetof(WGPUBindingResource, size),
                 "offsetof mismatch for BindingResource::size");
    static_assert(offsetof(BindingResource, sampler) == offsetof(WGPUBindingResource, sampler),
                 "offsetof mismatch for BindingResource::sampler");
    static_assert(offsetof(BindingResource, textureView) == offsetof(WGPUBindingResource, textureView),
                 "offsetof mismatch for BindingResource::textureView");

    bool BindingResource::operator==(const BindingResource& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (buffer != rhs.buffer) { return false; }
        if (offset != rhs.offset) { return false; }
        if (size != rhs.size) { return false; }
        if (sampler != rhs.sampler) { return false; }
        if (textureView != rhs.textureView) { return false; }
        return true;
    }


    static_assert(sizeof(BlendComponent) == sizeof(WGPUBlendComponent), "sizeof mismatch for BlendComponent");
    static_assert(alignof(BlendComponent) == alignof(WGPUBlendComponent), "alignof mismatch for BlendComponent");

    static_assert(offsetof(BlendComponent, operation) == offsetof(WGPUBlendComponent, operation),
                 "offsetof mismatch for BlendComponent::operation");
    static_assert(offsetof(BlendComponent, srcFactor) == offsetof(WGPUBlendComponent, srcFactor),
                 "offsetof mismatch for BlendComponent::srcFactor");
    static_assert(offsetof(BlendComponent, dstFactor) == offsetof(WGPUBlendComponent, dstFactor),
                 "offsetof mismatch for BlendComponent::dstFactor");

    BlendComponent BlendComponent::WithTrivialFrontendDefaults() const {
        BlendComponent copy;
        copy.operation = (operation == wgpu::BlendOperation::Undefined)
            ? wgpu::BlendOperation::Add
            : operation;
        copy.srcFactor = (srcFactor == wgpu::BlendFactor::Undefined)
            ? wgpu::BlendFactor::One
            : srcFactor;
        copy.dstFactor = (dstFactor == wgpu::BlendFactor::Undefined)
            ? wgpu::BlendFactor::Zero
            : dstFactor;
        return copy;
    }
    bool BlendComponent::operator==(const BlendComponent& rhs) const {
        if (operation != rhs.operation) { return false; }
        if (srcFactor != rhs.srcFactor) { return false; }
        if (dstFactor != rhs.dstFactor) { return false; }
        return true;
    }


    static_assert(sizeof(BufferBindingLayout) == sizeof(WGPUBufferBindingLayout), "sizeof mismatch for BufferBindingLayout");
    static_assert(alignof(BufferBindingLayout) == alignof(WGPUBufferBindingLayout), "alignof mismatch for BufferBindingLayout");

    static_assert(offsetof(BufferBindingLayout, nextInChain) == offsetof(WGPUBufferBindingLayout, nextInChain),
            "offsetof mismatch for BufferBindingLayout::nextInChain");
    static_assert(offsetof(BufferBindingLayout, type) == offsetof(WGPUBufferBindingLayout, type),
                 "offsetof mismatch for BufferBindingLayout::type");
    static_assert(offsetof(BufferBindingLayout, hasDynamicOffset) == offsetof(WGPUBufferBindingLayout, hasDynamicOffset),
                 "offsetof mismatch for BufferBindingLayout::hasDynamicOffset");
    static_assert(offsetof(BufferBindingLayout, minBindingSize) == offsetof(WGPUBufferBindingLayout, minBindingSize),
                 "offsetof mismatch for BufferBindingLayout::minBindingSize");

    BufferBindingLayout BufferBindingLayout::WithTrivialFrontendDefaults() const {
        BufferBindingLayout copy;
        copy.nextInChain = nextInChain;
        copy.type = (type == wgpu::BufferBindingType::Undefined)
            ? wgpu::BufferBindingType::Uniform
            : type;
        copy.hasDynamicOffset = hasDynamicOffset;
        copy.minBindingSize = minBindingSize;
        return copy;
    }
    bool BufferBindingLayout::operator==(const BufferBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (type != rhs.type) { return false; }
        if (hasDynamicOffset != rhs.hasDynamicOffset) { return false; }
        if (minBindingSize != rhs.minBindingSize) { return false; }
        return true;
    }


    static_assert(sizeof(BufferHostMappedPointer) == sizeof(WGPUBufferHostMappedPointer), "sizeof mismatch for BufferHostMappedPointer");
    static_assert(alignof(BufferHostMappedPointer) == alignof(WGPUBufferHostMappedPointer), "alignof mismatch for BufferHostMappedPointer");

    static_assert(offsetof(BufferHostMappedPointer, nextInChain) == offsetof(WGPUBufferHostMappedPointer, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for BufferHostMappedPointer::nextInChain");
    static_assert(offsetof(BufferHostMappedPointer, sType) == offsetof(WGPUBufferHostMappedPointer, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for BufferHostMappedPointer::sType");
    static_assert(offsetof(BufferHostMappedPointer, pointer) == offsetof(WGPUBufferHostMappedPointer, pointer),
                 "offsetof mismatch for BufferHostMappedPointer::pointer");
    static_assert(offsetof(BufferHostMappedPointer, disposeCallback) == offsetof(WGPUBufferHostMappedPointer, disposeCallback),
                 "offsetof mismatch for BufferHostMappedPointer::disposeCallback");
    static_assert(offsetof(BufferHostMappedPointer, userdata) == offsetof(WGPUBufferHostMappedPointer, userdata),
                 "offsetof mismatch for BufferHostMappedPointer::userdata");

    bool BufferHostMappedPointer::operator==(const BufferHostMappedPointer& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (pointer != rhs.pointer) { return false; }
        if (disposeCallback != rhs.disposeCallback) { return false; }
        if (userdata != rhs.userdata) { return false; }
        return true;
    }


    static_assert(sizeof(Color) == sizeof(WGPUColor), "sizeof mismatch for Color");
    static_assert(alignof(Color) == alignof(WGPUColor), "alignof mismatch for Color");

    static_assert(offsetof(Color, r) == offsetof(WGPUColor, r),
                 "offsetof mismatch for Color::r");
    static_assert(offsetof(Color, g) == offsetof(WGPUColor, g),
                 "offsetof mismatch for Color::g");
    static_assert(offsetof(Color, b) == offsetof(WGPUColor, b),
                 "offsetof mismatch for Color::b");
    static_assert(offsetof(Color, a) == offsetof(WGPUColor, a),
                 "offsetof mismatch for Color::a");

    bool Color::operator==(const Color& rhs) const {
        if (r != rhs.r) { return false; }
        if (g != rhs.g) { return false; }
        if (b != rhs.b) { return false; }
        if (a != rhs.a) { return false; }
        return true;
    }


    static_assert(sizeof(ColorSpaceDawn) == sizeof(WGPUColorSpaceDawn), "sizeof mismatch for ColorSpaceDawn");
    static_assert(alignof(ColorSpaceDawn) == alignof(WGPUColorSpaceDawn), "alignof mismatch for ColorSpaceDawn");

    static_assert(offsetof(ColorSpaceDawn, nextInChain) == offsetof(WGPUColorSpaceDawn, nextInChain),
            "offsetof mismatch for ColorSpaceDawn::nextInChain");
    static_assert(offsetof(ColorSpaceDawn, primaries) == offsetof(WGPUColorSpaceDawn, primaries),
                 "offsetof mismatch for ColorSpaceDawn::primaries");
    static_assert(offsetof(ColorSpaceDawn, transfer) == offsetof(WGPUColorSpaceDawn, transfer),
                 "offsetof mismatch for ColorSpaceDawn::transfer");
    static_assert(offsetof(ColorSpaceDawn, yCbCrRange) == offsetof(WGPUColorSpaceDawn, yCbCrRange),
                 "offsetof mismatch for ColorSpaceDawn::yCbCrRange");
    static_assert(offsetof(ColorSpaceDawn, yCbCrMatrix) == offsetof(WGPUColorSpaceDawn, yCbCrMatrix),
                 "offsetof mismatch for ColorSpaceDawn::yCbCrMatrix");
    static_assert(offsetof(ColorSpaceDawn, hdrReferenceWhiteLuminance) == offsetof(WGPUColorSpaceDawn, hdrReferenceWhiteLuminance),
                 "offsetof mismatch for ColorSpaceDawn::hdrReferenceWhiteLuminance");

    bool ColorSpaceDawn::operator==(const ColorSpaceDawn& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (primaries != rhs.primaries) { return false; }
        if (transfer != rhs.transfer) { return false; }
        if (yCbCrRange != rhs.yCbCrRange) { return false; }
        if (yCbCrMatrix != rhs.yCbCrMatrix) { return false; }
        if (hdrReferenceWhiteLuminance != rhs.hdrReferenceWhiteLuminance) { return false; }
        return true;
    }


    static_assert(sizeof(ColorTargetStateExpandResolveTextureDawn) == sizeof(WGPUColorTargetStateExpandResolveTextureDawn), "sizeof mismatch for ColorTargetStateExpandResolveTextureDawn");
    static_assert(alignof(ColorTargetStateExpandResolveTextureDawn) == alignof(WGPUColorTargetStateExpandResolveTextureDawn), "alignof mismatch for ColorTargetStateExpandResolveTextureDawn");

    static_assert(offsetof(ColorTargetStateExpandResolveTextureDawn, nextInChain) == offsetof(WGPUColorTargetStateExpandResolveTextureDawn, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ColorTargetStateExpandResolveTextureDawn::nextInChain");
    static_assert(offsetof(ColorTargetStateExpandResolveTextureDawn, sType) == offsetof(WGPUColorTargetStateExpandResolveTextureDawn, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ColorTargetStateExpandResolveTextureDawn::sType");
    static_assert(offsetof(ColorTargetStateExpandResolveTextureDawn, enabled) == offsetof(WGPUColorTargetStateExpandResolveTextureDawn, enabled),
                 "offsetof mismatch for ColorTargetStateExpandResolveTextureDawn::enabled");

    bool ColorTargetStateExpandResolveTextureDawn::operator==(const ColorTargetStateExpandResolveTextureDawn& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (enabled != rhs.enabled) { return false; }
        return true;
    }


    static_assert(sizeof(CommandBufferDescriptor) == sizeof(WGPUCommandBufferDescriptor), "sizeof mismatch for CommandBufferDescriptor");
    static_assert(alignof(CommandBufferDescriptor) == alignof(WGPUCommandBufferDescriptor), "alignof mismatch for CommandBufferDescriptor");

    static_assert(offsetof(CommandBufferDescriptor, nextInChain) == offsetof(WGPUCommandBufferDescriptor, nextInChain),
            "offsetof mismatch for CommandBufferDescriptor::nextInChain");
    static_assert(offsetof(CommandBufferDescriptor, label) == offsetof(WGPUCommandBufferDescriptor, label),
                 "offsetof mismatch for CommandBufferDescriptor::label");

    bool CommandBufferDescriptor::operator==(const CommandBufferDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(CompatibilityModeLimits) == sizeof(WGPUCompatibilityModeLimits), "sizeof mismatch for CompatibilityModeLimits");
    static_assert(alignof(CompatibilityModeLimits) == alignof(WGPUCompatibilityModeLimits), "alignof mismatch for CompatibilityModeLimits");

    static_assert(offsetof(CompatibilityModeLimits, nextInChain) == offsetof(WGPUCompatibilityModeLimits, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for CompatibilityModeLimits::nextInChain");
    static_assert(offsetof(CompatibilityModeLimits, sType) == offsetof(WGPUCompatibilityModeLimits, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for CompatibilityModeLimits::sType");
    static_assert(offsetof(CompatibilityModeLimits, maxStorageBuffersInVertexStage) == offsetof(WGPUCompatibilityModeLimits, maxStorageBuffersInVertexStage),
                 "offsetof mismatch for CompatibilityModeLimits::maxStorageBuffersInVertexStage");
    static_assert(offsetof(CompatibilityModeLimits, maxStorageTexturesInVertexStage) == offsetof(WGPUCompatibilityModeLimits, maxStorageTexturesInVertexStage),
                 "offsetof mismatch for CompatibilityModeLimits::maxStorageTexturesInVertexStage");
    static_assert(offsetof(CompatibilityModeLimits, maxStorageBuffersInFragmentStage) == offsetof(WGPUCompatibilityModeLimits, maxStorageBuffersInFragmentStage),
                 "offsetof mismatch for CompatibilityModeLimits::maxStorageBuffersInFragmentStage");
    static_assert(offsetof(CompatibilityModeLimits, maxStorageTexturesInFragmentStage) == offsetof(WGPUCompatibilityModeLimits, maxStorageTexturesInFragmentStage),
                 "offsetof mismatch for CompatibilityModeLimits::maxStorageTexturesInFragmentStage");

    bool CompatibilityModeLimits::operator==(const CompatibilityModeLimits& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (maxStorageBuffersInVertexStage != rhs.maxStorageBuffersInVertexStage) { return false; }
        if (maxStorageTexturesInVertexStage != rhs.maxStorageTexturesInVertexStage) { return false; }
        if (maxStorageBuffersInFragmentStage != rhs.maxStorageBuffersInFragmentStage) { return false; }
        if (maxStorageTexturesInFragmentStage != rhs.maxStorageTexturesInFragmentStage) { return false; }
        return true;
    }


    static_assert(sizeof(ConstantEntry) == sizeof(WGPUConstantEntry), "sizeof mismatch for ConstantEntry");
    static_assert(alignof(ConstantEntry) == alignof(WGPUConstantEntry), "alignof mismatch for ConstantEntry");

    static_assert(offsetof(ConstantEntry, nextInChain) == offsetof(WGPUConstantEntry, nextInChain),
            "offsetof mismatch for ConstantEntry::nextInChain");
    static_assert(offsetof(ConstantEntry, key) == offsetof(WGPUConstantEntry, key),
                 "offsetof mismatch for ConstantEntry::key");
    static_assert(offsetof(ConstantEntry, value) == offsetof(WGPUConstantEntry, value),
                 "offsetof mismatch for ConstantEntry::value");

    bool ConstantEntry::operator==(const ConstantEntry& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (key != rhs.key) { return false; }
        if (value != rhs.value) { return false; }
        return true;
    }


    static_assert(sizeof(CopyTextureForBrowserOptions) == sizeof(WGPUCopyTextureForBrowserOptions), "sizeof mismatch for CopyTextureForBrowserOptions");
    static_assert(alignof(CopyTextureForBrowserOptions) == alignof(WGPUCopyTextureForBrowserOptions), "alignof mismatch for CopyTextureForBrowserOptions");

    static_assert(offsetof(CopyTextureForBrowserOptions, nextInChain) == offsetof(WGPUCopyTextureForBrowserOptions, nextInChain),
            "offsetof mismatch for CopyTextureForBrowserOptions::nextInChain");
    static_assert(offsetof(CopyTextureForBrowserOptions, flipY) == offsetof(WGPUCopyTextureForBrowserOptions, flipY),
                 "offsetof mismatch for CopyTextureForBrowserOptions::flipY");
    static_assert(offsetof(CopyTextureForBrowserOptions, needsColorSpaceConversion) == offsetof(WGPUCopyTextureForBrowserOptions, needsColorSpaceConversion),
                 "offsetof mismatch for CopyTextureForBrowserOptions::needsColorSpaceConversion");
    static_assert(offsetof(CopyTextureForBrowserOptions, srcAlphaMode) == offsetof(WGPUCopyTextureForBrowserOptions, srcAlphaMode),
                 "offsetof mismatch for CopyTextureForBrowserOptions::srcAlphaMode");
    static_assert(offsetof(CopyTextureForBrowserOptions, srcTransferFunctionParameters) == offsetof(WGPUCopyTextureForBrowserOptions, srcTransferFunctionParameters),
                 "offsetof mismatch for CopyTextureForBrowserOptions::srcTransferFunctionParameters");
    static_assert(offsetof(CopyTextureForBrowserOptions, conversionMatrix) == offsetof(WGPUCopyTextureForBrowserOptions, conversionMatrix),
                 "offsetof mismatch for CopyTextureForBrowserOptions::conversionMatrix");
    static_assert(offsetof(CopyTextureForBrowserOptions, dstTransferFunctionParameters) == offsetof(WGPUCopyTextureForBrowserOptions, dstTransferFunctionParameters),
                 "offsetof mismatch for CopyTextureForBrowserOptions::dstTransferFunctionParameters");
    static_assert(offsetof(CopyTextureForBrowserOptions, dstAlphaMode) == offsetof(WGPUCopyTextureForBrowserOptions, dstAlphaMode),
                 "offsetof mismatch for CopyTextureForBrowserOptions::dstAlphaMode");
    static_assert(offsetof(CopyTextureForBrowserOptions, internalUsage) == offsetof(WGPUCopyTextureForBrowserOptions, internalUsage),
                 "offsetof mismatch for CopyTextureForBrowserOptions::internalUsage");

    bool CopyTextureForBrowserOptions::operator==(const CopyTextureForBrowserOptions& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (flipY != rhs.flipY) { return false; }
        if (needsColorSpaceConversion != rhs.needsColorSpaceConversion) { return false; }
        if (srcAlphaMode != rhs.srcAlphaMode) { return false; }
        if (srcTransferFunctionParameters != rhs.srcTransferFunctionParameters) { return false; }
        if (conversionMatrix != rhs.conversionMatrix) { return false; }
        if (dstTransferFunctionParameters != rhs.dstTransferFunctionParameters) { return false; }
        if (dstAlphaMode != rhs.dstAlphaMode) { return false; }
        if (internalUsage != rhs.internalUsage) { return false; }
        return true;
    }


    static_assert(sizeof(DawnAdapterPropertiesPowerPreference) == sizeof(WGPUDawnAdapterPropertiesPowerPreference), "sizeof mismatch for DawnAdapterPropertiesPowerPreference");
    static_assert(alignof(DawnAdapterPropertiesPowerPreference) == alignof(WGPUDawnAdapterPropertiesPowerPreference), "alignof mismatch for DawnAdapterPropertiesPowerPreference");

    static_assert(offsetof(DawnAdapterPropertiesPowerPreference, nextInChain) == offsetof(WGPUDawnAdapterPropertiesPowerPreference, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnAdapterPropertiesPowerPreference::nextInChain");
    static_assert(offsetof(DawnAdapterPropertiesPowerPreference, sType) == offsetof(WGPUDawnAdapterPropertiesPowerPreference, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnAdapterPropertiesPowerPreference::sType");
    static_assert(offsetof(DawnAdapterPropertiesPowerPreference, powerPreference) == offsetof(WGPUDawnAdapterPropertiesPowerPreference, powerPreference),
                 "offsetof mismatch for DawnAdapterPropertiesPowerPreference::powerPreference");

    bool DawnAdapterPropertiesPowerPreference::operator==(const DawnAdapterPropertiesPowerPreference& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (powerPreference != rhs.powerPreference) { return false; }
        return true;
    }


    static_assert(sizeof(DawnBufferDescriptorErrorInfoFromWireClient) == sizeof(WGPUDawnBufferDescriptorErrorInfoFromWireClient), "sizeof mismatch for DawnBufferDescriptorErrorInfoFromWireClient");
    static_assert(alignof(DawnBufferDescriptorErrorInfoFromWireClient) == alignof(WGPUDawnBufferDescriptorErrorInfoFromWireClient), "alignof mismatch for DawnBufferDescriptorErrorInfoFromWireClient");

    static_assert(offsetof(DawnBufferDescriptorErrorInfoFromWireClient, nextInChain) == offsetof(WGPUDawnBufferDescriptorErrorInfoFromWireClient, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnBufferDescriptorErrorInfoFromWireClient::nextInChain");
    static_assert(offsetof(DawnBufferDescriptorErrorInfoFromWireClient, sType) == offsetof(WGPUDawnBufferDescriptorErrorInfoFromWireClient, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnBufferDescriptorErrorInfoFromWireClient::sType");
    static_assert(offsetof(DawnBufferDescriptorErrorInfoFromWireClient, outOfMemory) == offsetof(WGPUDawnBufferDescriptorErrorInfoFromWireClient, outOfMemory),
                 "offsetof mismatch for DawnBufferDescriptorErrorInfoFromWireClient::outOfMemory");

    bool DawnBufferDescriptorErrorInfoFromWireClient::operator==(const DawnBufferDescriptorErrorInfoFromWireClient& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (outOfMemory != rhs.outOfMemory) { return false; }
        return true;
    }


    static_assert(sizeof(DawnCacheDeviceDescriptor) == sizeof(WGPUDawnCacheDeviceDescriptor), "sizeof mismatch for DawnCacheDeviceDescriptor");
    static_assert(alignof(DawnCacheDeviceDescriptor) == alignof(WGPUDawnCacheDeviceDescriptor), "alignof mismatch for DawnCacheDeviceDescriptor");

    static_assert(offsetof(DawnCacheDeviceDescriptor, nextInChain) == offsetof(WGPUDawnCacheDeviceDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnCacheDeviceDescriptor::nextInChain");
    static_assert(offsetof(DawnCacheDeviceDescriptor, sType) == offsetof(WGPUDawnCacheDeviceDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnCacheDeviceDescriptor::sType");
    static_assert(offsetof(DawnCacheDeviceDescriptor, isolationKey) == offsetof(WGPUDawnCacheDeviceDescriptor, isolationKey),
                 "offsetof mismatch for DawnCacheDeviceDescriptor::isolationKey");
    static_assert(offsetof(DawnCacheDeviceDescriptor, dawnLoadCacheDataCallbackInfo) == offsetof(WGPUDawnCacheDeviceDescriptor, dawnLoadCacheDataCallbackInfo),
                 "offsetof mismatch for DawnCacheDeviceDescriptor::dawnLoadCacheDataCallbackInfo");
    static_assert(offsetof(DawnCacheDeviceDescriptor, dawnStoreCacheDataCallbackInfo) == offsetof(WGPUDawnCacheDeviceDescriptor, dawnStoreCacheDataCallbackInfo),
                 "offsetof mismatch for DawnCacheDeviceDescriptor::dawnStoreCacheDataCallbackInfo");

    bool DawnCacheDeviceDescriptor::operator==(const DawnCacheDeviceDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (isolationKey != rhs.isolationKey) { return false; }
        return true;
    }


    static_assert(sizeof(DawnCompilationMessageUtf16) == sizeof(WGPUDawnCompilationMessageUtf16), "sizeof mismatch for DawnCompilationMessageUtf16");
    static_assert(alignof(DawnCompilationMessageUtf16) == alignof(WGPUDawnCompilationMessageUtf16), "alignof mismatch for DawnCompilationMessageUtf16");

    static_assert(offsetof(DawnCompilationMessageUtf16, nextInChain) == offsetof(WGPUDawnCompilationMessageUtf16, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnCompilationMessageUtf16::nextInChain");
    static_assert(offsetof(DawnCompilationMessageUtf16, sType) == offsetof(WGPUDawnCompilationMessageUtf16, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnCompilationMessageUtf16::sType");
    static_assert(offsetof(DawnCompilationMessageUtf16, linePos) == offsetof(WGPUDawnCompilationMessageUtf16, linePos),
                 "offsetof mismatch for DawnCompilationMessageUtf16::linePos");
    static_assert(offsetof(DawnCompilationMessageUtf16, offset) == offsetof(WGPUDawnCompilationMessageUtf16, offset),
                 "offsetof mismatch for DawnCompilationMessageUtf16::offset");
    static_assert(offsetof(DawnCompilationMessageUtf16, length) == offsetof(WGPUDawnCompilationMessageUtf16, length),
                 "offsetof mismatch for DawnCompilationMessageUtf16::length");

    bool DawnCompilationMessageUtf16::operator==(const DawnCompilationMessageUtf16& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (linePos != rhs.linePos) { return false; }
        if (offset != rhs.offset) { return false; }
        if (length != rhs.length) { return false; }
        return true;
    }


    static_assert(sizeof(DawnConsumeAdapterDescriptor) == sizeof(WGPUDawnConsumeAdapterDescriptor), "sizeof mismatch for DawnConsumeAdapterDescriptor");
    static_assert(alignof(DawnConsumeAdapterDescriptor) == alignof(WGPUDawnConsumeAdapterDescriptor), "alignof mismatch for DawnConsumeAdapterDescriptor");

    static_assert(offsetof(DawnConsumeAdapterDescriptor, nextInChain) == offsetof(WGPUDawnConsumeAdapterDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnConsumeAdapterDescriptor::nextInChain");
    static_assert(offsetof(DawnConsumeAdapterDescriptor, sType) == offsetof(WGPUDawnConsumeAdapterDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnConsumeAdapterDescriptor::sType");
    static_assert(offsetof(DawnConsumeAdapterDescriptor, consumeAdapter) == offsetof(WGPUDawnConsumeAdapterDescriptor, consumeAdapter),
                 "offsetof mismatch for DawnConsumeAdapterDescriptor::consumeAdapter");

    bool DawnConsumeAdapterDescriptor::operator==(const DawnConsumeAdapterDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (consumeAdapter != rhs.consumeAdapter) { return false; }
        return true;
    }


    static_assert(sizeof(DawnDeviceAllocatorControl) == sizeof(WGPUDawnDeviceAllocatorControl), "sizeof mismatch for DawnDeviceAllocatorControl");
    static_assert(alignof(DawnDeviceAllocatorControl) == alignof(WGPUDawnDeviceAllocatorControl), "alignof mismatch for DawnDeviceAllocatorControl");

    static_assert(offsetof(DawnDeviceAllocatorControl, nextInChain) == offsetof(WGPUDawnDeviceAllocatorControl, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnDeviceAllocatorControl::nextInChain");
    static_assert(offsetof(DawnDeviceAllocatorControl, sType) == offsetof(WGPUDawnDeviceAllocatorControl, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnDeviceAllocatorControl::sType");
    static_assert(offsetof(DawnDeviceAllocatorControl, allocatorHeapBlockSize) == offsetof(WGPUDawnDeviceAllocatorControl, allocatorHeapBlockSize),
                 "offsetof mismatch for DawnDeviceAllocatorControl::allocatorHeapBlockSize");

    bool DawnDeviceAllocatorControl::operator==(const DawnDeviceAllocatorControl& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (allocatorHeapBlockSize != rhs.allocatorHeapBlockSize) { return false; }
        return true;
    }


    static_assert(sizeof(DawnDrmFormatProperties) == sizeof(WGPUDawnDrmFormatProperties), "sizeof mismatch for DawnDrmFormatProperties");
    static_assert(alignof(DawnDrmFormatProperties) == alignof(WGPUDawnDrmFormatProperties), "alignof mismatch for DawnDrmFormatProperties");

    static_assert(offsetof(DawnDrmFormatProperties, modifier) == offsetof(WGPUDawnDrmFormatProperties, modifier),
                 "offsetof mismatch for DawnDrmFormatProperties::modifier");
    static_assert(offsetof(DawnDrmFormatProperties, modifierPlaneCount) == offsetof(WGPUDawnDrmFormatProperties, modifierPlaneCount),
                 "offsetof mismatch for DawnDrmFormatProperties::modifierPlaneCount");

    bool DawnDrmFormatProperties::operator==(const DawnDrmFormatProperties& rhs) const {
        if (modifier != rhs.modifier) { return false; }
        if (modifierPlaneCount != rhs.modifierPlaneCount) { return false; }
        return true;
    }


    static_assert(sizeof(DawnEncoderInternalUsageDescriptor) == sizeof(WGPUDawnEncoderInternalUsageDescriptor), "sizeof mismatch for DawnEncoderInternalUsageDescriptor");
    static_assert(alignof(DawnEncoderInternalUsageDescriptor) == alignof(WGPUDawnEncoderInternalUsageDescriptor), "alignof mismatch for DawnEncoderInternalUsageDescriptor");

    static_assert(offsetof(DawnEncoderInternalUsageDescriptor, nextInChain) == offsetof(WGPUDawnEncoderInternalUsageDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnEncoderInternalUsageDescriptor::nextInChain");
    static_assert(offsetof(DawnEncoderInternalUsageDescriptor, sType) == offsetof(WGPUDawnEncoderInternalUsageDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnEncoderInternalUsageDescriptor::sType");
    static_assert(offsetof(DawnEncoderInternalUsageDescriptor, useInternalUsages) == offsetof(WGPUDawnEncoderInternalUsageDescriptor, useInternalUsages),
                 "offsetof mismatch for DawnEncoderInternalUsageDescriptor::useInternalUsages");

    bool DawnEncoderInternalUsageDescriptor::operator==(const DawnEncoderInternalUsageDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (useInternalUsages != rhs.useInternalUsages) { return false; }
        return true;
    }


    static_assert(sizeof(DawnFakeBufferOOMForTesting) == sizeof(WGPUDawnFakeBufferOOMForTesting), "sizeof mismatch for DawnFakeBufferOOMForTesting");
    static_assert(alignof(DawnFakeBufferOOMForTesting) == alignof(WGPUDawnFakeBufferOOMForTesting), "alignof mismatch for DawnFakeBufferOOMForTesting");

    static_assert(offsetof(DawnFakeBufferOOMForTesting, nextInChain) == offsetof(WGPUDawnFakeBufferOOMForTesting, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnFakeBufferOOMForTesting::nextInChain");
    static_assert(offsetof(DawnFakeBufferOOMForTesting, sType) == offsetof(WGPUDawnFakeBufferOOMForTesting, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnFakeBufferOOMForTesting::sType");
    static_assert(offsetof(DawnFakeBufferOOMForTesting, fakeOOMAtWireClientMap) == offsetof(WGPUDawnFakeBufferOOMForTesting, fakeOOMAtWireClientMap),
                 "offsetof mismatch for DawnFakeBufferOOMForTesting::fakeOOMAtWireClientMap");
    static_assert(offsetof(DawnFakeBufferOOMForTesting, fakeOOMAtNativeMap) == offsetof(WGPUDawnFakeBufferOOMForTesting, fakeOOMAtNativeMap),
                 "offsetof mismatch for DawnFakeBufferOOMForTesting::fakeOOMAtNativeMap");
    static_assert(offsetof(DawnFakeBufferOOMForTesting, fakeOOMAtDevice) == offsetof(WGPUDawnFakeBufferOOMForTesting, fakeOOMAtDevice),
                 "offsetof mismatch for DawnFakeBufferOOMForTesting::fakeOOMAtDevice");

    bool DawnFakeBufferOOMForTesting::operator==(const DawnFakeBufferOOMForTesting& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (fakeOOMAtWireClientMap != rhs.fakeOOMAtWireClientMap) { return false; }
        if (fakeOOMAtNativeMap != rhs.fakeOOMAtNativeMap) { return false; }
        if (fakeOOMAtDevice != rhs.fakeOOMAtDevice) { return false; }
        return true;
    }


    static_assert(sizeof(DawnFakeDeviceInitializeErrorForTesting) == sizeof(WGPUDawnFakeDeviceInitializeErrorForTesting), "sizeof mismatch for DawnFakeDeviceInitializeErrorForTesting");
    static_assert(alignof(DawnFakeDeviceInitializeErrorForTesting) == alignof(WGPUDawnFakeDeviceInitializeErrorForTesting), "alignof mismatch for DawnFakeDeviceInitializeErrorForTesting");

    static_assert(offsetof(DawnFakeDeviceInitializeErrorForTesting, nextInChain) == offsetof(WGPUDawnFakeDeviceInitializeErrorForTesting, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnFakeDeviceInitializeErrorForTesting::nextInChain");
    static_assert(offsetof(DawnFakeDeviceInitializeErrorForTesting, sType) == offsetof(WGPUDawnFakeDeviceInitializeErrorForTesting, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnFakeDeviceInitializeErrorForTesting::sType");

    bool DawnFakeDeviceInitializeErrorForTesting::operator==(const DawnFakeDeviceInitializeErrorForTesting& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        return true;
    }


    static_assert(sizeof(DawnHostMappedPointerLimits) == sizeof(WGPUDawnHostMappedPointerLimits), "sizeof mismatch for DawnHostMappedPointerLimits");
    static_assert(alignof(DawnHostMappedPointerLimits) == alignof(WGPUDawnHostMappedPointerLimits), "alignof mismatch for DawnHostMappedPointerLimits");

    static_assert(offsetof(DawnHostMappedPointerLimits, nextInChain) == offsetof(WGPUDawnHostMappedPointerLimits, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnHostMappedPointerLimits::nextInChain");
    static_assert(offsetof(DawnHostMappedPointerLimits, sType) == offsetof(WGPUDawnHostMappedPointerLimits, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnHostMappedPointerLimits::sType");
    static_assert(offsetof(DawnHostMappedPointerLimits, hostMappedPointerAlignment) == offsetof(WGPUDawnHostMappedPointerLimits, hostMappedPointerAlignment),
                 "offsetof mismatch for DawnHostMappedPointerLimits::hostMappedPointerAlignment");

    bool DawnHostMappedPointerLimits::operator==(const DawnHostMappedPointerLimits& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (hostMappedPointerAlignment != rhs.hostMappedPointerAlignment) { return false; }
        return true;
    }


    static_assert(sizeof(DawnInjectedInvalidSType) == sizeof(WGPUDawnInjectedInvalidSType), "sizeof mismatch for DawnInjectedInvalidSType");
    static_assert(alignof(DawnInjectedInvalidSType) == alignof(WGPUDawnInjectedInvalidSType), "alignof mismatch for DawnInjectedInvalidSType");

    static_assert(offsetof(DawnInjectedInvalidSType, nextInChain) == offsetof(WGPUDawnInjectedInvalidSType, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnInjectedInvalidSType::nextInChain");
    static_assert(offsetof(DawnInjectedInvalidSType, sType) == offsetof(WGPUDawnInjectedInvalidSType, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnInjectedInvalidSType::sType");
    static_assert(offsetof(DawnInjectedInvalidSType, invalidSType) == offsetof(WGPUDawnInjectedInvalidSType, invalidSType),
                 "offsetof mismatch for DawnInjectedInvalidSType::invalidSType");

    bool DawnInjectedInvalidSType::operator==(const DawnInjectedInvalidSType& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (invalidSType != rhs.invalidSType) { return false; }
        return true;
    }


    static_assert(sizeof(DawnRenderPassSampleCount) == sizeof(WGPUDawnRenderPassSampleCount), "sizeof mismatch for DawnRenderPassSampleCount");
    static_assert(alignof(DawnRenderPassSampleCount) == alignof(WGPUDawnRenderPassSampleCount), "alignof mismatch for DawnRenderPassSampleCount");

    static_assert(offsetof(DawnRenderPassSampleCount, nextInChain) == offsetof(WGPUDawnRenderPassSampleCount, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnRenderPassSampleCount::nextInChain");
    static_assert(offsetof(DawnRenderPassSampleCount, sType) == offsetof(WGPUDawnRenderPassSampleCount, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnRenderPassSampleCount::sType");
    static_assert(offsetof(DawnRenderPassSampleCount, sampleCount) == offsetof(WGPUDawnRenderPassSampleCount, sampleCount),
                 "offsetof mismatch for DawnRenderPassSampleCount::sampleCount");

    bool DawnRenderPassSampleCount::operator==(const DawnRenderPassSampleCount& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sampleCount != rhs.sampleCount) { return false; }
        return true;
    }


    static_assert(sizeof(DawnShaderModuleSPIRVOptionsDescriptor) == sizeof(WGPUDawnShaderModuleSPIRVOptionsDescriptor), "sizeof mismatch for DawnShaderModuleSPIRVOptionsDescriptor");
    static_assert(alignof(DawnShaderModuleSPIRVOptionsDescriptor) == alignof(WGPUDawnShaderModuleSPIRVOptionsDescriptor), "alignof mismatch for DawnShaderModuleSPIRVOptionsDescriptor");

    static_assert(offsetof(DawnShaderModuleSPIRVOptionsDescriptor, nextInChain) == offsetof(WGPUDawnShaderModuleSPIRVOptionsDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnShaderModuleSPIRVOptionsDescriptor::nextInChain");
    static_assert(offsetof(DawnShaderModuleSPIRVOptionsDescriptor, sType) == offsetof(WGPUDawnShaderModuleSPIRVOptionsDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnShaderModuleSPIRVOptionsDescriptor::sType");
    static_assert(offsetof(DawnShaderModuleSPIRVOptionsDescriptor, allowNonUniformDerivatives) == offsetof(WGPUDawnShaderModuleSPIRVOptionsDescriptor, allowNonUniformDerivatives),
                 "offsetof mismatch for DawnShaderModuleSPIRVOptionsDescriptor::allowNonUniformDerivatives");

    bool DawnShaderModuleSPIRVOptionsDescriptor::operator==(const DawnShaderModuleSPIRVOptionsDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (allowNonUniformDerivatives != rhs.allowNonUniformDerivatives) { return false; }
        return true;
    }


    static_assert(sizeof(DawnTexelCopyBufferRowAlignmentLimits) == sizeof(WGPUDawnTexelCopyBufferRowAlignmentLimits), "sizeof mismatch for DawnTexelCopyBufferRowAlignmentLimits");
    static_assert(alignof(DawnTexelCopyBufferRowAlignmentLimits) == alignof(WGPUDawnTexelCopyBufferRowAlignmentLimits), "alignof mismatch for DawnTexelCopyBufferRowAlignmentLimits");

    static_assert(offsetof(DawnTexelCopyBufferRowAlignmentLimits, nextInChain) == offsetof(WGPUDawnTexelCopyBufferRowAlignmentLimits, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnTexelCopyBufferRowAlignmentLimits::nextInChain");
    static_assert(offsetof(DawnTexelCopyBufferRowAlignmentLimits, sType) == offsetof(WGPUDawnTexelCopyBufferRowAlignmentLimits, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnTexelCopyBufferRowAlignmentLimits::sType");
    static_assert(offsetof(DawnTexelCopyBufferRowAlignmentLimits, minTexelCopyBufferRowAlignment) == offsetof(WGPUDawnTexelCopyBufferRowAlignmentLimits, minTexelCopyBufferRowAlignment),
                 "offsetof mismatch for DawnTexelCopyBufferRowAlignmentLimits::minTexelCopyBufferRowAlignment");

    bool DawnTexelCopyBufferRowAlignmentLimits::operator==(const DawnTexelCopyBufferRowAlignmentLimits& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (minTexelCopyBufferRowAlignment != rhs.minTexelCopyBufferRowAlignment) { return false; }
        return true;
    }


    static_assert(sizeof(DawnTextureInternalUsageDescriptor) == sizeof(WGPUDawnTextureInternalUsageDescriptor), "sizeof mismatch for DawnTextureInternalUsageDescriptor");
    static_assert(alignof(DawnTextureInternalUsageDescriptor) == alignof(WGPUDawnTextureInternalUsageDescriptor), "alignof mismatch for DawnTextureInternalUsageDescriptor");

    static_assert(offsetof(DawnTextureInternalUsageDescriptor, nextInChain) == offsetof(WGPUDawnTextureInternalUsageDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnTextureInternalUsageDescriptor::nextInChain");
    static_assert(offsetof(DawnTextureInternalUsageDescriptor, sType) == offsetof(WGPUDawnTextureInternalUsageDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnTextureInternalUsageDescriptor::sType");
    static_assert(offsetof(DawnTextureInternalUsageDescriptor, internalUsage) == offsetof(WGPUDawnTextureInternalUsageDescriptor, internalUsage),
                 "offsetof mismatch for DawnTextureInternalUsageDescriptor::internalUsage");

    bool DawnTextureInternalUsageDescriptor::operator==(const DawnTextureInternalUsageDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (internalUsage != rhs.internalUsage) { return false; }
        return true;
    }


    static_assert(sizeof(DawnTogglesDescriptor) == sizeof(WGPUDawnTogglesDescriptor), "sizeof mismatch for DawnTogglesDescriptor");
    static_assert(alignof(DawnTogglesDescriptor) == alignof(WGPUDawnTogglesDescriptor), "alignof mismatch for DawnTogglesDescriptor");

    static_assert(offsetof(DawnTogglesDescriptor, nextInChain) == offsetof(WGPUDawnTogglesDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnTogglesDescriptor::nextInChain");
    static_assert(offsetof(DawnTogglesDescriptor, sType) == offsetof(WGPUDawnTogglesDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnTogglesDescriptor::sType");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using DawnTogglesDescriptorenabledTogglesSpan = decltype(std::declval<DawnTogglesDescriptor>().enabledToggles);
    
    static_assert(offsetof(DawnTogglesDescriptor, enabledToggles) + DawnTogglesDescriptorenabledTogglesSpan::GetOffsetOfSize() == offsetof(WGPUDawnTogglesDescriptor, enabledToggleCount),
                 "offsetof mismatch for DawnTogglesDescriptor::enabledToggles::mSize");
    static_assert(offsetof(DawnTogglesDescriptor, enabledToggles) + DawnTogglesDescriptorenabledTogglesSpan::GetOffsetOfData() == offsetof(WGPUDawnTogglesDescriptor, enabledToggles),
                 "offsetof mismatch for DawnTogglesDescriptor::enabledToggles::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using DawnTogglesDescriptordisabledTogglesSpan = decltype(std::declval<DawnTogglesDescriptor>().disabledToggles);
    
    static_assert(offsetof(DawnTogglesDescriptor, disabledToggles) + DawnTogglesDescriptordisabledTogglesSpan::GetOffsetOfSize() == offsetof(WGPUDawnTogglesDescriptor, disabledToggleCount),
                 "offsetof mismatch for DawnTogglesDescriptor::disabledToggles::mSize");
    static_assert(offsetof(DawnTogglesDescriptor, disabledToggles) + DawnTogglesDescriptordisabledTogglesSpan::GetOffsetOfData() == offsetof(WGPUDawnTogglesDescriptor, disabledToggles),
                 "offsetof mismatch for DawnTogglesDescriptor::disabledToggles::mData");

    bool DawnTogglesDescriptor::operator==(const DawnTogglesDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (enabledToggles.size() != rhs.enabledToggles.size()) { return false; }
        if (enabledToggles.data() != rhs.enabledToggles.data()) { return false; }
        if (disabledToggles.size() != rhs.disabledToggles.size()) { return false; }
        if (disabledToggles.data() != rhs.disabledToggles.data()) { return false; }
        return true;
    }


    static_assert(sizeof(DawnWGSLBlocklist) == sizeof(WGPUDawnWGSLBlocklist), "sizeof mismatch for DawnWGSLBlocklist");
    static_assert(alignof(DawnWGSLBlocklist) == alignof(WGPUDawnWGSLBlocklist), "alignof mismatch for DawnWGSLBlocklist");

    static_assert(offsetof(DawnWGSLBlocklist, nextInChain) == offsetof(WGPUDawnWGSLBlocklist, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnWGSLBlocklist::nextInChain");
    static_assert(offsetof(DawnWGSLBlocklist, sType) == offsetof(WGPUDawnWGSLBlocklist, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnWGSLBlocklist::sType");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using DawnWGSLBlocklistblocklistedFeaturesSpan = decltype(std::declval<DawnWGSLBlocklist>().blocklistedFeatures);
    
    static_assert(offsetof(DawnWGSLBlocklist, blocklistedFeatures) + DawnWGSLBlocklistblocklistedFeaturesSpan::GetOffsetOfSize() == offsetof(WGPUDawnWGSLBlocklist, blocklistedFeatureCount),
                 "offsetof mismatch for DawnWGSLBlocklist::blocklistedFeatures::mSize");
    static_assert(offsetof(DawnWGSLBlocklist, blocklistedFeatures) + DawnWGSLBlocklistblocklistedFeaturesSpan::GetOffsetOfData() == offsetof(WGPUDawnWGSLBlocklist, blocklistedFeatures),
                 "offsetof mismatch for DawnWGSLBlocklist::blocklistedFeatures::mData");

    bool DawnWGSLBlocklist::operator==(const DawnWGSLBlocklist& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (blocklistedFeatures.size() != rhs.blocklistedFeatures.size()) { return false; }
        if (blocklistedFeatures.data() != rhs.blocklistedFeatures.data()) { return false; }
        return true;
    }


    static_assert(sizeof(DawnWireWGSLControl) == sizeof(WGPUDawnWireWGSLControl), "sizeof mismatch for DawnWireWGSLControl");
    static_assert(alignof(DawnWireWGSLControl) == alignof(WGPUDawnWireWGSLControl), "alignof mismatch for DawnWireWGSLControl");

    static_assert(offsetof(DawnWireWGSLControl, nextInChain) == offsetof(WGPUDawnWireWGSLControl, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnWireWGSLControl::nextInChain");
    static_assert(offsetof(DawnWireWGSLControl, sType) == offsetof(WGPUDawnWireWGSLControl, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnWireWGSLControl::sType");
    static_assert(offsetof(DawnWireWGSLControl, enableExperimental) == offsetof(WGPUDawnWireWGSLControl, enableExperimental),
                 "offsetof mismatch for DawnWireWGSLControl::enableExperimental");
    static_assert(offsetof(DawnWireWGSLControl, enableUnsafe) == offsetof(WGPUDawnWireWGSLControl, enableUnsafe),
                 "offsetof mismatch for DawnWireWGSLControl::enableUnsafe");
    static_assert(offsetof(DawnWireWGSLControl, enableTesting) == offsetof(WGPUDawnWireWGSLControl, enableTesting),
                 "offsetof mismatch for DawnWireWGSLControl::enableTesting");

    bool DawnWireWGSLControl::operator==(const DawnWireWGSLControl& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (enableExperimental != rhs.enableExperimental) { return false; }
        if (enableUnsafe != rhs.enableUnsafe) { return false; }
        if (enableTesting != rhs.enableTesting) { return false; }
        return true;
    }


    static_assert(sizeof(Extent2D) == sizeof(WGPUExtent2D), "sizeof mismatch for Extent2D");
    static_assert(alignof(Extent2D) == alignof(WGPUExtent2D), "alignof mismatch for Extent2D");

    static_assert(offsetof(Extent2D, width) == offsetof(WGPUExtent2D, width),
                 "offsetof mismatch for Extent2D::width");
    static_assert(offsetof(Extent2D, height) == offsetof(WGPUExtent2D, height),
                 "offsetof mismatch for Extent2D::height");

    bool Extent2D::operator==(const Extent2D& rhs) const {
        if (width != rhs.width) { return false; }
        if (height != rhs.height) { return false; }
        return true;
    }


    static_assert(sizeof(Extent3D) == sizeof(WGPUExtent3D), "sizeof mismatch for Extent3D");
    static_assert(alignof(Extent3D) == alignof(WGPUExtent3D), "alignof mismatch for Extent3D");

    static_assert(offsetof(Extent3D, width) == offsetof(WGPUExtent3D, width),
                 "offsetof mismatch for Extent3D::width");
    static_assert(offsetof(Extent3D, height) == offsetof(WGPUExtent3D, height),
                 "offsetof mismatch for Extent3D::height");
    static_assert(offsetof(Extent3D, depthOrArrayLayers) == offsetof(WGPUExtent3D, depthOrArrayLayers),
                 "offsetof mismatch for Extent3D::depthOrArrayLayers");

    bool Extent3D::operator==(const Extent3D& rhs) const {
        if (width != rhs.width) { return false; }
        if (height != rhs.height) { return false; }
        if (depthOrArrayLayers != rhs.depthOrArrayLayers) { return false; }
        return true;
    }


    static_assert(sizeof(ExternalTextureBindingEntry) == sizeof(WGPUExternalTextureBindingEntry), "sizeof mismatch for ExternalTextureBindingEntry");
    static_assert(alignof(ExternalTextureBindingEntry) == alignof(WGPUExternalTextureBindingEntry), "alignof mismatch for ExternalTextureBindingEntry");

    static_assert(offsetof(ExternalTextureBindingEntry, nextInChain) == offsetof(WGPUExternalTextureBindingEntry, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ExternalTextureBindingEntry::nextInChain");
    static_assert(offsetof(ExternalTextureBindingEntry, sType) == offsetof(WGPUExternalTextureBindingEntry, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ExternalTextureBindingEntry::sType");
    static_assert(offsetof(ExternalTextureBindingEntry, externalTexture) == offsetof(WGPUExternalTextureBindingEntry, externalTexture),
                 "offsetof mismatch for ExternalTextureBindingEntry::externalTexture");

    bool ExternalTextureBindingEntry::operator==(const ExternalTextureBindingEntry& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (externalTexture != rhs.externalTexture) { return false; }
        return true;
    }


    static_assert(sizeof(ExternalTextureBindingLayout) == sizeof(WGPUExternalTextureBindingLayout), "sizeof mismatch for ExternalTextureBindingLayout");
    static_assert(alignof(ExternalTextureBindingLayout) == alignof(WGPUExternalTextureBindingLayout), "alignof mismatch for ExternalTextureBindingLayout");

    static_assert(offsetof(ExternalTextureBindingLayout, nextInChain) == offsetof(WGPUExternalTextureBindingLayout, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ExternalTextureBindingLayout::nextInChain");
    static_assert(offsetof(ExternalTextureBindingLayout, sType) == offsetof(WGPUExternalTextureBindingLayout, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ExternalTextureBindingLayout::sType");

    bool ExternalTextureBindingLayout::operator==(const ExternalTextureBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        return true;
    }


    static_assert(sizeof(Future) == sizeof(WGPUFuture), "sizeof mismatch for Future");
    static_assert(alignof(Future) == alignof(WGPUFuture), "alignof mismatch for Future");

    static_assert(offsetof(Future, id) == offsetof(WGPUFuture, id),
                 "offsetof mismatch for Future::id");

    bool Future::operator==(const Future& rhs) const {
        if (id != rhs.id) { return false; }
        return true;
    }


    static_assert(sizeof(InstanceLimits) == sizeof(WGPUInstanceLimits), "sizeof mismatch for InstanceLimits");
    static_assert(alignof(InstanceLimits) == alignof(WGPUInstanceLimits), "alignof mismatch for InstanceLimits");

    static_assert(offsetof(InstanceLimits, nextInChain) == offsetof(WGPUInstanceLimits, nextInChain),
            "offsetof mismatch for InstanceLimits::nextInChain");
    static_assert(offsetof(InstanceLimits, timedWaitAnyMaxCount) == offsetof(WGPUInstanceLimits, timedWaitAnyMaxCount),
                 "offsetof mismatch for InstanceLimits::timedWaitAnyMaxCount");

    bool InstanceLimits::operator==(const InstanceLimits& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (timedWaitAnyMaxCount != rhs.timedWaitAnyMaxCount) { return false; }
        return true;
    }


    static_assert(sizeof(MemoryHeapInfo) == sizeof(WGPUMemoryHeapInfo), "sizeof mismatch for MemoryHeapInfo");
    static_assert(alignof(MemoryHeapInfo) == alignof(WGPUMemoryHeapInfo), "alignof mismatch for MemoryHeapInfo");

    static_assert(offsetof(MemoryHeapInfo, properties) == offsetof(WGPUMemoryHeapInfo, properties),
                 "offsetof mismatch for MemoryHeapInfo::properties");
    static_assert(offsetof(MemoryHeapInfo, size) == offsetof(WGPUMemoryHeapInfo, size),
                 "offsetof mismatch for MemoryHeapInfo::size");

    bool MemoryHeapInfo::operator==(const MemoryHeapInfo& rhs) const {
        if (properties != rhs.properties) { return false; }
        if (size != rhs.size) { return false; }
        return true;
    }


    static_assert(sizeof(MultisampleState) == sizeof(WGPUMultisampleState), "sizeof mismatch for MultisampleState");
    static_assert(alignof(MultisampleState) == alignof(WGPUMultisampleState), "alignof mismatch for MultisampleState");

    static_assert(offsetof(MultisampleState, nextInChain) == offsetof(WGPUMultisampleState, nextInChain),
            "offsetof mismatch for MultisampleState::nextInChain");
    static_assert(offsetof(MultisampleState, count) == offsetof(WGPUMultisampleState, count),
                 "offsetof mismatch for MultisampleState::count");
    static_assert(offsetof(MultisampleState, mask) == offsetof(WGPUMultisampleState, mask),
                 "offsetof mismatch for MultisampleState::mask");
    static_assert(offsetof(MultisampleState, alphaToCoverageEnabled) == offsetof(WGPUMultisampleState, alphaToCoverageEnabled),
                 "offsetof mismatch for MultisampleState::alphaToCoverageEnabled");

    bool MultisampleState::operator==(const MultisampleState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (count != rhs.count) { return false; }
        if (mask != rhs.mask) { return false; }
        if (alphaToCoverageEnabled != rhs.alphaToCoverageEnabled) { return false; }
        return true;
    }


    static_assert(sizeof(Origin2D) == sizeof(WGPUOrigin2D), "sizeof mismatch for Origin2D");
    static_assert(alignof(Origin2D) == alignof(WGPUOrigin2D), "alignof mismatch for Origin2D");

    static_assert(offsetof(Origin2D, x) == offsetof(WGPUOrigin2D, x),
                 "offsetof mismatch for Origin2D::x");
    static_assert(offsetof(Origin2D, y) == offsetof(WGPUOrigin2D, y),
                 "offsetof mismatch for Origin2D::y");

    bool Origin2D::operator==(const Origin2D& rhs) const {
        if (x != rhs.x) { return false; }
        if (y != rhs.y) { return false; }
        return true;
    }


    static_assert(sizeof(Origin3D) == sizeof(WGPUOrigin3D), "sizeof mismatch for Origin3D");
    static_assert(alignof(Origin3D) == alignof(WGPUOrigin3D), "alignof mismatch for Origin3D");

    static_assert(offsetof(Origin3D, x) == offsetof(WGPUOrigin3D, x),
                 "offsetof mismatch for Origin3D::x");
    static_assert(offsetof(Origin3D, y) == offsetof(WGPUOrigin3D, y),
                 "offsetof mismatch for Origin3D::y");
    static_assert(offsetof(Origin3D, z) == offsetof(WGPUOrigin3D, z),
                 "offsetof mismatch for Origin3D::z");

    bool Origin3D::operator==(const Origin3D& rhs) const {
        if (x != rhs.x) { return false; }
        if (y != rhs.y) { return false; }
        if (z != rhs.z) { return false; }
        return true;
    }


    static_assert(sizeof(PassTimestampWrites) == sizeof(WGPUPassTimestampWrites), "sizeof mismatch for PassTimestampWrites");
    static_assert(alignof(PassTimestampWrites) == alignof(WGPUPassTimestampWrites), "alignof mismatch for PassTimestampWrites");

    static_assert(offsetof(PassTimestampWrites, nextInChain) == offsetof(WGPUPassTimestampWrites, nextInChain),
            "offsetof mismatch for PassTimestampWrites::nextInChain");
    static_assert(offsetof(PassTimestampWrites, querySet) == offsetof(WGPUPassTimestampWrites, querySet),
                 "offsetof mismatch for PassTimestampWrites::querySet");
    static_assert(offsetof(PassTimestampWrites, beginningOfPassWriteIndex) == offsetof(WGPUPassTimestampWrites, beginningOfPassWriteIndex),
                 "offsetof mismatch for PassTimestampWrites::beginningOfPassWriteIndex");
    static_assert(offsetof(PassTimestampWrites, endOfPassWriteIndex) == offsetof(WGPUPassTimestampWrites, endOfPassWriteIndex),
                 "offsetof mismatch for PassTimestampWrites::endOfPassWriteIndex");

    bool PassTimestampWrites::operator==(const PassTimestampWrites& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (querySet != rhs.querySet) { return false; }
        if (beginningOfPassWriteIndex != rhs.beginningOfPassWriteIndex) { return false; }
        if (endOfPassWriteIndex != rhs.endOfPassWriteIndex) { return false; }
        return true;
    }


    static_assert(sizeof(PipelineLayoutResourceTable) == sizeof(WGPUPipelineLayoutResourceTable), "sizeof mismatch for PipelineLayoutResourceTable");
    static_assert(alignof(PipelineLayoutResourceTable) == alignof(WGPUPipelineLayoutResourceTable), "alignof mismatch for PipelineLayoutResourceTable");

    static_assert(offsetof(PipelineLayoutResourceTable, nextInChain) == offsetof(WGPUPipelineLayoutResourceTable, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for PipelineLayoutResourceTable::nextInChain");
    static_assert(offsetof(PipelineLayoutResourceTable, sType) == offsetof(WGPUPipelineLayoutResourceTable, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for PipelineLayoutResourceTable::sType");
    static_assert(offsetof(PipelineLayoutResourceTable, usesResourceTable) == offsetof(WGPUPipelineLayoutResourceTable, usesResourceTable),
                 "offsetof mismatch for PipelineLayoutResourceTable::usesResourceTable");

    bool PipelineLayoutResourceTable::operator==(const PipelineLayoutResourceTable& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (usesResourceTable != rhs.usesResourceTable) { return false; }
        return true;
    }


    static_assert(sizeof(PipelineLayoutStorageAttachment) == sizeof(WGPUPipelineLayoutStorageAttachment), "sizeof mismatch for PipelineLayoutStorageAttachment");
    static_assert(alignof(PipelineLayoutStorageAttachment) == alignof(WGPUPipelineLayoutStorageAttachment), "alignof mismatch for PipelineLayoutStorageAttachment");

    static_assert(offsetof(PipelineLayoutStorageAttachment, nextInChain) == offsetof(WGPUPipelineLayoutStorageAttachment, nextInChain),
            "offsetof mismatch for PipelineLayoutStorageAttachment::nextInChain");
    static_assert(offsetof(PipelineLayoutStorageAttachment, offset) == offsetof(WGPUPipelineLayoutStorageAttachment, offset),
                 "offsetof mismatch for PipelineLayoutStorageAttachment::offset");
    static_assert(offsetof(PipelineLayoutStorageAttachment, format) == offsetof(WGPUPipelineLayoutStorageAttachment, format),
                 "offsetof mismatch for PipelineLayoutStorageAttachment::format");

    bool PipelineLayoutStorageAttachment::operator==(const PipelineLayoutStorageAttachment& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (offset != rhs.offset) { return false; }
        if (format != rhs.format) { return false; }
        return true;
    }


    static_assert(sizeof(PrimitiveState) == sizeof(WGPUPrimitiveState), "sizeof mismatch for PrimitiveState");
    static_assert(alignof(PrimitiveState) == alignof(WGPUPrimitiveState), "alignof mismatch for PrimitiveState");

    static_assert(offsetof(PrimitiveState, nextInChain) == offsetof(WGPUPrimitiveState, nextInChain),
            "offsetof mismatch for PrimitiveState::nextInChain");
    static_assert(offsetof(PrimitiveState, topology) == offsetof(WGPUPrimitiveState, topology),
                 "offsetof mismatch for PrimitiveState::topology");
    static_assert(offsetof(PrimitiveState, stripIndexFormat) == offsetof(WGPUPrimitiveState, stripIndexFormat),
                 "offsetof mismatch for PrimitiveState::stripIndexFormat");
    static_assert(offsetof(PrimitiveState, frontFace) == offsetof(WGPUPrimitiveState, frontFace),
                 "offsetof mismatch for PrimitiveState::frontFace");
    static_assert(offsetof(PrimitiveState, cullMode) == offsetof(WGPUPrimitiveState, cullMode),
                 "offsetof mismatch for PrimitiveState::cullMode");
    static_assert(offsetof(PrimitiveState, unclippedDepth) == offsetof(WGPUPrimitiveState, unclippedDepth),
                 "offsetof mismatch for PrimitiveState::unclippedDepth");

    PrimitiveState PrimitiveState::WithTrivialFrontendDefaults() const {
        PrimitiveState copy;
        copy.nextInChain = nextInChain;
        copy.topology = (topology == wgpu::PrimitiveTopology::Undefined)
            ? wgpu::PrimitiveTopology::TriangleList
            : topology;
        copy.stripIndexFormat = stripIndexFormat;
        copy.frontFace = (frontFace == wgpu::FrontFace::Undefined)
            ? wgpu::FrontFace::CCW
            : frontFace;
        copy.cullMode = (cullMode == wgpu::CullMode::Undefined)
            ? wgpu::CullMode::None
            : cullMode;
        copy.unclippedDepth = unclippedDepth;
        return copy;
    }
    bool PrimitiveState::operator==(const PrimitiveState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (topology != rhs.topology) { return false; }
        if (stripIndexFormat != rhs.stripIndexFormat) { return false; }
        if (frontFace != rhs.frontFace) { return false; }
        if (cullMode != rhs.cullMode) { return false; }
        if (unclippedDepth != rhs.unclippedDepth) { return false; }
        return true;
    }


    static_assert(sizeof(QuerySetDescriptor) == sizeof(WGPUQuerySetDescriptor), "sizeof mismatch for QuerySetDescriptor");
    static_assert(alignof(QuerySetDescriptor) == alignof(WGPUQuerySetDescriptor), "alignof mismatch for QuerySetDescriptor");

    static_assert(offsetof(QuerySetDescriptor, nextInChain) == offsetof(WGPUQuerySetDescriptor, nextInChain),
            "offsetof mismatch for QuerySetDescriptor::nextInChain");
    static_assert(offsetof(QuerySetDescriptor, label) == offsetof(WGPUQuerySetDescriptor, label),
                 "offsetof mismatch for QuerySetDescriptor::label");
    static_assert(offsetof(QuerySetDescriptor, type) == offsetof(WGPUQuerySetDescriptor, type),
                 "offsetof mismatch for QuerySetDescriptor::type");
    static_assert(offsetof(QuerySetDescriptor, count) == offsetof(WGPUQuerySetDescriptor, count),
                 "offsetof mismatch for QuerySetDescriptor::count");

    bool QuerySetDescriptor::operator==(const QuerySetDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (type != rhs.type) { return false; }
        if (count != rhs.count) { return false; }
        return true;
    }


    static_assert(sizeof(QueueDescriptor) == sizeof(WGPUQueueDescriptor), "sizeof mismatch for QueueDescriptor");
    static_assert(alignof(QueueDescriptor) == alignof(WGPUQueueDescriptor), "alignof mismatch for QueueDescriptor");

    static_assert(offsetof(QueueDescriptor, nextInChain) == offsetof(WGPUQueueDescriptor, nextInChain),
            "offsetof mismatch for QueueDescriptor::nextInChain");
    static_assert(offsetof(QueueDescriptor, label) == offsetof(WGPUQueueDescriptor, label),
                 "offsetof mismatch for QueueDescriptor::label");

    bool QueueDescriptor::operator==(const QueueDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(RenderBundleDescriptor) == sizeof(WGPURenderBundleDescriptor), "sizeof mismatch for RenderBundleDescriptor");
    static_assert(alignof(RenderBundleDescriptor) == alignof(WGPURenderBundleDescriptor), "alignof mismatch for RenderBundleDescriptor");

    static_assert(offsetof(RenderBundleDescriptor, nextInChain) == offsetof(WGPURenderBundleDescriptor, nextInChain),
            "offsetof mismatch for RenderBundleDescriptor::nextInChain");
    static_assert(offsetof(RenderBundleDescriptor, label) == offsetof(WGPURenderBundleDescriptor, label),
                 "offsetof mismatch for RenderBundleDescriptor::label");

    bool RenderBundleDescriptor::operator==(const RenderBundleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(RenderBundleEncoderResourceTable) == sizeof(WGPURenderBundleEncoderResourceTable), "sizeof mismatch for RenderBundleEncoderResourceTable");
    static_assert(alignof(RenderBundleEncoderResourceTable) == alignof(WGPURenderBundleEncoderResourceTable), "alignof mismatch for RenderBundleEncoderResourceTable");

    static_assert(offsetof(RenderBundleEncoderResourceTable, nextInChain) == offsetof(WGPURenderBundleEncoderResourceTable, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RenderBundleEncoderResourceTable::nextInChain");
    static_assert(offsetof(RenderBundleEncoderResourceTable, sType) == offsetof(WGPURenderBundleEncoderResourceTable, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RenderBundleEncoderResourceTable::sType");
    static_assert(offsetof(RenderBundleEncoderResourceTable, usesResourceTable) == offsetof(WGPURenderBundleEncoderResourceTable, usesResourceTable),
                 "offsetof mismatch for RenderBundleEncoderResourceTable::usesResourceTable");

    bool RenderBundleEncoderResourceTable::operator==(const RenderBundleEncoderResourceTable& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (usesResourceTable != rhs.usesResourceTable) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassDepthStencilAttachment) == sizeof(WGPURenderPassDepthStencilAttachment), "sizeof mismatch for RenderPassDepthStencilAttachment");
    static_assert(alignof(RenderPassDepthStencilAttachment) == alignof(WGPURenderPassDepthStencilAttachment), "alignof mismatch for RenderPassDepthStencilAttachment");

    static_assert(offsetof(RenderPassDepthStencilAttachment, nextInChain) == offsetof(WGPURenderPassDepthStencilAttachment, nextInChain),
            "offsetof mismatch for RenderPassDepthStencilAttachment::nextInChain");
    static_assert(offsetof(RenderPassDepthStencilAttachment, view) == offsetof(WGPURenderPassDepthStencilAttachment, view),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::view");
    static_assert(offsetof(RenderPassDepthStencilAttachment, depthLoadOp) == offsetof(WGPURenderPassDepthStencilAttachment, depthLoadOp),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::depthLoadOp");
    static_assert(offsetof(RenderPassDepthStencilAttachment, depthStoreOp) == offsetof(WGPURenderPassDepthStencilAttachment, depthStoreOp),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::depthStoreOp");
    static_assert(offsetof(RenderPassDepthStencilAttachment, depthClearValue) == offsetof(WGPURenderPassDepthStencilAttachment, depthClearValue),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::depthClearValue");
    static_assert(offsetof(RenderPassDepthStencilAttachment, depthReadOnly) == offsetof(WGPURenderPassDepthStencilAttachment, depthReadOnly),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::depthReadOnly");
    static_assert(offsetof(RenderPassDepthStencilAttachment, stencilLoadOp) == offsetof(WGPURenderPassDepthStencilAttachment, stencilLoadOp),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::stencilLoadOp");
    static_assert(offsetof(RenderPassDepthStencilAttachment, stencilStoreOp) == offsetof(WGPURenderPassDepthStencilAttachment, stencilStoreOp),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::stencilStoreOp");
    static_assert(offsetof(RenderPassDepthStencilAttachment, stencilClearValue) == offsetof(WGPURenderPassDepthStencilAttachment, stencilClearValue),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::stencilClearValue");
    static_assert(offsetof(RenderPassDepthStencilAttachment, stencilReadOnly) == offsetof(WGPURenderPassDepthStencilAttachment, stencilReadOnly),
                 "offsetof mismatch for RenderPassDepthStencilAttachment::stencilReadOnly");

    bool RenderPassDepthStencilAttachment::operator==(const RenderPassDepthStencilAttachment& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (view != rhs.view) { return false; }
        if (depthLoadOp != rhs.depthLoadOp) { return false; }
        if (depthStoreOp != rhs.depthStoreOp) { return false; }
        if (depthClearValue != rhs.depthClearValue) { return false; }
        if (depthReadOnly != rhs.depthReadOnly) { return false; }
        if (stencilLoadOp != rhs.stencilLoadOp) { return false; }
        if (stencilStoreOp != rhs.stencilStoreOp) { return false; }
        if (stencilClearValue != rhs.stencilClearValue) { return false; }
        if (stencilReadOnly != rhs.stencilReadOnly) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassDescriptorResolveRect) == sizeof(WGPURenderPassDescriptorResolveRect), "sizeof mismatch for RenderPassDescriptorResolveRect");
    static_assert(alignof(RenderPassDescriptorResolveRect) == alignof(WGPURenderPassDescriptorResolveRect), "alignof mismatch for RenderPassDescriptorResolveRect");

    static_assert(offsetof(RenderPassDescriptorResolveRect, nextInChain) == offsetof(WGPURenderPassDescriptorResolveRect, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RenderPassDescriptorResolveRect::nextInChain");
    static_assert(offsetof(RenderPassDescriptorResolveRect, sType) == offsetof(WGPURenderPassDescriptorResolveRect, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RenderPassDescriptorResolveRect::sType");
    static_assert(offsetof(RenderPassDescriptorResolveRect, colorOffsetX) == offsetof(WGPURenderPassDescriptorResolveRect, colorOffsetX),
                 "offsetof mismatch for RenderPassDescriptorResolveRect::colorOffsetX");
    static_assert(offsetof(RenderPassDescriptorResolveRect, colorOffsetY) == offsetof(WGPURenderPassDescriptorResolveRect, colorOffsetY),
                 "offsetof mismatch for RenderPassDescriptorResolveRect::colorOffsetY");
    static_assert(offsetof(RenderPassDescriptorResolveRect, resolveOffsetX) == offsetof(WGPURenderPassDescriptorResolveRect, resolveOffsetX),
                 "offsetof mismatch for RenderPassDescriptorResolveRect::resolveOffsetX");
    static_assert(offsetof(RenderPassDescriptorResolveRect, resolveOffsetY) == offsetof(WGPURenderPassDescriptorResolveRect, resolveOffsetY),
                 "offsetof mismatch for RenderPassDescriptorResolveRect::resolveOffsetY");
    static_assert(offsetof(RenderPassDescriptorResolveRect, width) == offsetof(WGPURenderPassDescriptorResolveRect, width),
                 "offsetof mismatch for RenderPassDescriptorResolveRect::width");
    static_assert(offsetof(RenderPassDescriptorResolveRect, height) == offsetof(WGPURenderPassDescriptorResolveRect, height),
                 "offsetof mismatch for RenderPassDescriptorResolveRect::height");

    bool RenderPassDescriptorResolveRect::operator==(const RenderPassDescriptorResolveRect& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (colorOffsetX != rhs.colorOffsetX) { return false; }
        if (colorOffsetY != rhs.colorOffsetY) { return false; }
        if (resolveOffsetX != rhs.resolveOffsetX) { return false; }
        if (resolveOffsetY != rhs.resolveOffsetY) { return false; }
        if (width != rhs.width) { return false; }
        if (height != rhs.height) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassMaxDrawCount) == sizeof(WGPURenderPassMaxDrawCount), "sizeof mismatch for RenderPassMaxDrawCount");
    static_assert(alignof(RenderPassMaxDrawCount) == alignof(WGPURenderPassMaxDrawCount), "alignof mismatch for RenderPassMaxDrawCount");

    static_assert(offsetof(RenderPassMaxDrawCount, nextInChain) == offsetof(WGPURenderPassMaxDrawCount, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RenderPassMaxDrawCount::nextInChain");
    static_assert(offsetof(RenderPassMaxDrawCount, sType) == offsetof(WGPURenderPassMaxDrawCount, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RenderPassMaxDrawCount::sType");
    static_assert(offsetof(RenderPassMaxDrawCount, maxDrawCount) == offsetof(WGPURenderPassMaxDrawCount, maxDrawCount),
                 "offsetof mismatch for RenderPassMaxDrawCount::maxDrawCount");

    bool RenderPassMaxDrawCount::operator==(const RenderPassMaxDrawCount& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (maxDrawCount != rhs.maxDrawCount) { return false; }
        return true;
    }


    static_assert(sizeof(RequestAdapterWebGPUBackendOptions) == sizeof(WGPURequestAdapterWebGPUBackendOptions), "sizeof mismatch for RequestAdapterWebGPUBackendOptions");
    static_assert(alignof(RequestAdapterWebGPUBackendOptions) == alignof(WGPURequestAdapterWebGPUBackendOptions), "alignof mismatch for RequestAdapterWebGPUBackendOptions");

    static_assert(offsetof(RequestAdapterWebGPUBackendOptions, nextInChain) == offsetof(WGPURequestAdapterWebGPUBackendOptions, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RequestAdapterWebGPUBackendOptions::nextInChain");
    static_assert(offsetof(RequestAdapterWebGPUBackendOptions, sType) == offsetof(WGPURequestAdapterWebGPUBackendOptions, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RequestAdapterWebGPUBackendOptions::sType");

    bool RequestAdapterWebGPUBackendOptions::operator==(const RequestAdapterWebGPUBackendOptions& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        return true;
    }


    static_assert(sizeof(RequestAdapterWebXROptions) == sizeof(WGPURequestAdapterWebXROptions), "sizeof mismatch for RequestAdapterWebXROptions");
    static_assert(alignof(RequestAdapterWebXROptions) == alignof(WGPURequestAdapterWebXROptions), "alignof mismatch for RequestAdapterWebXROptions");

    static_assert(offsetof(RequestAdapterWebXROptions, nextInChain) == offsetof(WGPURequestAdapterWebXROptions, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RequestAdapterWebXROptions::nextInChain");
    static_assert(offsetof(RequestAdapterWebXROptions, sType) == offsetof(WGPURequestAdapterWebXROptions, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RequestAdapterWebXROptions::sType");
    static_assert(offsetof(RequestAdapterWebXROptions, xrCompatible) == offsetof(WGPURequestAdapterWebXROptions, xrCompatible),
                 "offsetof mismatch for RequestAdapterWebXROptions::xrCompatible");

    bool RequestAdapterWebXROptions::operator==(const RequestAdapterWebXROptions& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (xrCompatible != rhs.xrCompatible) { return false; }
        return true;
    }


    static_assert(sizeof(ResourceTableDescriptor) == sizeof(WGPUResourceTableDescriptor), "sizeof mismatch for ResourceTableDescriptor");
    static_assert(alignof(ResourceTableDescriptor) == alignof(WGPUResourceTableDescriptor), "alignof mismatch for ResourceTableDescriptor");

    static_assert(offsetof(ResourceTableDescriptor, nextInChain) == offsetof(WGPUResourceTableDescriptor, nextInChain),
            "offsetof mismatch for ResourceTableDescriptor::nextInChain");
    static_assert(offsetof(ResourceTableDescriptor, label) == offsetof(WGPUResourceTableDescriptor, label),
                 "offsetof mismatch for ResourceTableDescriptor::label");
    static_assert(offsetof(ResourceTableDescriptor, size) == offsetof(WGPUResourceTableDescriptor, size),
                 "offsetof mismatch for ResourceTableDescriptor::size");

    bool ResourceTableDescriptor::operator==(const ResourceTableDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (size != rhs.size) { return false; }
        return true;
    }


    static_assert(sizeof(SamplerBindingLayout) == sizeof(WGPUSamplerBindingLayout), "sizeof mismatch for SamplerBindingLayout");
    static_assert(alignof(SamplerBindingLayout) == alignof(WGPUSamplerBindingLayout), "alignof mismatch for SamplerBindingLayout");

    static_assert(offsetof(SamplerBindingLayout, nextInChain) == offsetof(WGPUSamplerBindingLayout, nextInChain),
            "offsetof mismatch for SamplerBindingLayout::nextInChain");
    static_assert(offsetof(SamplerBindingLayout, type) == offsetof(WGPUSamplerBindingLayout, type),
                 "offsetof mismatch for SamplerBindingLayout::type");

    SamplerBindingLayout SamplerBindingLayout::WithTrivialFrontendDefaults() const {
        SamplerBindingLayout copy;
        copy.nextInChain = nextInChain;
        copy.type = (type == wgpu::SamplerBindingType::Undefined)
            ? wgpu::SamplerBindingType::Filtering
            : type;
        return copy;
    }
    bool SamplerBindingLayout::operator==(const SamplerBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (type != rhs.type) { return false; }
        return true;
    }


    static_assert(sizeof(ShaderModuleCompilationOptions) == sizeof(WGPUShaderModuleCompilationOptions), "sizeof mismatch for ShaderModuleCompilationOptions");
    static_assert(alignof(ShaderModuleCompilationOptions) == alignof(WGPUShaderModuleCompilationOptions), "alignof mismatch for ShaderModuleCompilationOptions");

    static_assert(offsetof(ShaderModuleCompilationOptions, nextInChain) == offsetof(WGPUShaderModuleCompilationOptions, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ShaderModuleCompilationOptions::nextInChain");
    static_assert(offsetof(ShaderModuleCompilationOptions, sType) == offsetof(WGPUShaderModuleCompilationOptions, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ShaderModuleCompilationOptions::sType");
    static_assert(offsetof(ShaderModuleCompilationOptions, strictMath) == offsetof(WGPUShaderModuleCompilationOptions, strictMath),
                 "offsetof mismatch for ShaderModuleCompilationOptions::strictMath");

    bool ShaderModuleCompilationOptions::operator==(const ShaderModuleCompilationOptions& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (strictMath != rhs.strictMath) { return false; }
        return true;
    }


    static_assert(sizeof(ShaderSourceSPIRV) == sizeof(WGPUShaderSourceSPIRV), "sizeof mismatch for ShaderSourceSPIRV");
    static_assert(alignof(ShaderSourceSPIRV) == alignof(WGPUShaderSourceSPIRV), "alignof mismatch for ShaderSourceSPIRV");

    static_assert(offsetof(ShaderSourceSPIRV, nextInChain) == offsetof(WGPUShaderSourceSPIRV, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ShaderSourceSPIRV::nextInChain");
    static_assert(offsetof(ShaderSourceSPIRV, sType) == offsetof(WGPUShaderSourceSPIRV, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ShaderSourceSPIRV::sType");
    static_assert(offsetof(ShaderSourceSPIRV, codeSize) == offsetof(WGPUShaderSourceSPIRV, codeSize),
                 "offsetof mismatch for ShaderSourceSPIRV::codeSize");
    static_assert(offsetof(ShaderSourceSPIRV, code) == offsetof(WGPUShaderSourceSPIRV, code),
                 "offsetof mismatch for ShaderSourceSPIRV::code");

    bool ShaderSourceSPIRV::operator==(const ShaderSourceSPIRV& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (codeSize != rhs.codeSize) { return false; }
        if (code != rhs.code) { return false; }
        return true;
    }


    static_assert(sizeof(ShaderSourceWGSL) == sizeof(WGPUShaderSourceWGSL), "sizeof mismatch for ShaderSourceWGSL");
    static_assert(alignof(ShaderSourceWGSL) == alignof(WGPUShaderSourceWGSL), "alignof mismatch for ShaderSourceWGSL");

    static_assert(offsetof(ShaderSourceWGSL, nextInChain) == offsetof(WGPUShaderSourceWGSL, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for ShaderSourceWGSL::nextInChain");
    static_assert(offsetof(ShaderSourceWGSL, sType) == offsetof(WGPUShaderSourceWGSL, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for ShaderSourceWGSL::sType");
    static_assert(offsetof(ShaderSourceWGSL, code) == offsetof(WGPUShaderSourceWGSL, code),
                 "offsetof mismatch for ShaderSourceWGSL::code");

    bool ShaderSourceWGSL::operator==(const ShaderSourceWGSL& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (code != rhs.code) { return false; }
        return true;
    }


    static_assert(sizeof(SharedBufferMemoryBeginAccessDescriptor) == sizeof(WGPUSharedBufferMemoryBeginAccessDescriptor), "sizeof mismatch for SharedBufferMemoryBeginAccessDescriptor");
    static_assert(alignof(SharedBufferMemoryBeginAccessDescriptor) == alignof(WGPUSharedBufferMemoryBeginAccessDescriptor), "alignof mismatch for SharedBufferMemoryBeginAccessDescriptor");

    static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, nextInChain) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, nextInChain),
            "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::nextInChain");
    static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, initialized) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, initialized),
                 "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::initialized");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedBufferMemoryBeginAccessDescriptorfencesSpan = decltype(std::declval<SharedBufferMemoryBeginAccessDescriptor>().fences);
    
    static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, fences) + SharedBufferMemoryBeginAccessDescriptorfencesSpan::GetOffsetOfSize() == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, fenceCount),
                 "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::fences::mSize");
    static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, fences) + SharedBufferMemoryBeginAccessDescriptorfencesSpan::GetOffsetOfData() == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, fences),
                 "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::fences::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedBufferMemoryBeginAccessDescriptorsignaledValuesSpan = decltype(std::declval<SharedBufferMemoryBeginAccessDescriptor>().signaledValues);
    
    static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, signaledValues) + SharedBufferMemoryBeginAccessDescriptorsignaledValuesSpan::GetOffsetOfSize() == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, signaledValueCount),
                 "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::signaledValues::mSize");
    static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, signaledValues) + SharedBufferMemoryBeginAccessDescriptorsignaledValuesSpan::GetOffsetOfData() == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, signaledValues),
                 "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::signaledValues::mData");

    bool SharedBufferMemoryBeginAccessDescriptor::operator==(const SharedBufferMemoryBeginAccessDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (initialized != rhs.initialized) { return false; }
        if (fences.size() != rhs.fences.size()) { return false; }
        if (fences.data() != rhs.fences.data()) { return false; }
        if (signaledValues.size() != rhs.signaledValues.size()) { return false; }
        if (signaledValues.data() != rhs.signaledValues.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SharedBufferMemoryEndAccessState) == sizeof(WGPUSharedBufferMemoryEndAccessState), "sizeof mismatch for SharedBufferMemoryEndAccessState");
    static_assert(alignof(SharedBufferMemoryEndAccessState) == alignof(WGPUSharedBufferMemoryEndAccessState), "alignof mismatch for SharedBufferMemoryEndAccessState");

    static_assert(offsetof(SharedBufferMemoryEndAccessState, nextInChain) == offsetof(WGPUSharedBufferMemoryEndAccessState, nextInChain),
            "offsetof mismatch for SharedBufferMemoryEndAccessState::nextInChain");
    static_assert(offsetof(SharedBufferMemoryEndAccessState, initialized) == offsetof(WGPUSharedBufferMemoryEndAccessState, initialized),
                 "offsetof mismatch for SharedBufferMemoryEndAccessState::initialized");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedBufferMemoryEndAccessStatefencesSpan = decltype(std::declval<SharedBufferMemoryEndAccessState>().fences);
    
    static_assert(offsetof(SharedBufferMemoryEndAccessState, fences) + SharedBufferMemoryEndAccessStatefencesSpan::GetOffsetOfSize() == offsetof(WGPUSharedBufferMemoryEndAccessState, fenceCount),
                 "offsetof mismatch for SharedBufferMemoryEndAccessState::fences::mSize");
    static_assert(offsetof(SharedBufferMemoryEndAccessState, fences) + SharedBufferMemoryEndAccessStatefencesSpan::GetOffsetOfData() == offsetof(WGPUSharedBufferMemoryEndAccessState, fences),
                 "offsetof mismatch for SharedBufferMemoryEndAccessState::fences::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedBufferMemoryEndAccessStatesignaledValuesSpan = decltype(std::declval<SharedBufferMemoryEndAccessState>().signaledValues);
    
    static_assert(offsetof(SharedBufferMemoryEndAccessState, signaledValues) + SharedBufferMemoryEndAccessStatesignaledValuesSpan::GetOffsetOfSize() == offsetof(WGPUSharedBufferMemoryEndAccessState, signaledValueCount),
                 "offsetof mismatch for SharedBufferMemoryEndAccessState::signaledValues::mSize");
    static_assert(offsetof(SharedBufferMemoryEndAccessState, signaledValues) + SharedBufferMemoryEndAccessStatesignaledValuesSpan::GetOffsetOfData() == offsetof(WGPUSharedBufferMemoryEndAccessState, signaledValues),
                 "offsetof mismatch for SharedBufferMemoryEndAccessState::signaledValues::mData");

    bool SharedBufferMemoryEndAccessState::operator==(const SharedBufferMemoryEndAccessState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (initialized != rhs.initialized) { return false; }
        if (fences.size() != rhs.fences.size()) { return false; }
        if (fences.data() != rhs.fences.data()) { return false; }
        if (signaledValues.size() != rhs.signaledValues.size()) { return false; }
        if (signaledValues.data() != rhs.signaledValues.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SharedBufferMemoryFromWindowsHandleDescriptor) == sizeof(WGPUSharedBufferMemoryFromWindowsHandleDescriptor), "sizeof mismatch for SharedBufferMemoryFromWindowsHandleDescriptor");
    static_assert(alignof(SharedBufferMemoryFromWindowsHandleDescriptor) == alignof(WGPUSharedBufferMemoryFromWindowsHandleDescriptor), "alignof mismatch for SharedBufferMemoryFromWindowsHandleDescriptor");

    static_assert(offsetof(SharedBufferMemoryFromWindowsHandleDescriptor, nextInChain) == offsetof(WGPUSharedBufferMemoryFromWindowsHandleDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedBufferMemoryFromWindowsHandleDescriptor::nextInChain");
    static_assert(offsetof(SharedBufferMemoryFromWindowsHandleDescriptor, sType) == offsetof(WGPUSharedBufferMemoryFromWindowsHandleDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedBufferMemoryFromWindowsHandleDescriptor::sType");
    static_assert(offsetof(SharedBufferMemoryFromWindowsHandleDescriptor, handle) == offsetof(WGPUSharedBufferMemoryFromWindowsHandleDescriptor, handle),
                 "offsetof mismatch for SharedBufferMemoryFromWindowsHandleDescriptor::handle");
    static_assert(offsetof(SharedBufferMemoryFromWindowsHandleDescriptor, size) == offsetof(WGPUSharedBufferMemoryFromWindowsHandleDescriptor, size),
                 "offsetof mismatch for SharedBufferMemoryFromWindowsHandleDescriptor::size");

    bool SharedBufferMemoryFromWindowsHandleDescriptor::operator==(const SharedBufferMemoryFromWindowsHandleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        if (size != rhs.size) { return false; }
        return true;
    }


    static_assert(sizeof(SharedBufferMemoryProperties) == sizeof(WGPUSharedBufferMemoryProperties), "sizeof mismatch for SharedBufferMemoryProperties");
    static_assert(alignof(SharedBufferMemoryProperties) == alignof(WGPUSharedBufferMemoryProperties), "alignof mismatch for SharedBufferMemoryProperties");

    static_assert(offsetof(SharedBufferMemoryProperties, nextInChain) == offsetof(WGPUSharedBufferMemoryProperties, nextInChain),
            "offsetof mismatch for SharedBufferMemoryProperties::nextInChain");
    static_assert(offsetof(SharedBufferMemoryProperties, usage) == offsetof(WGPUSharedBufferMemoryProperties, usage),
                 "offsetof mismatch for SharedBufferMemoryProperties::usage");
    static_assert(offsetof(SharedBufferMemoryProperties, size) == offsetof(WGPUSharedBufferMemoryProperties, size),
                 "offsetof mismatch for SharedBufferMemoryProperties::size");

    bool SharedBufferMemoryProperties::operator==(const SharedBufferMemoryProperties& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (usage != rhs.usage) { return false; }
        if (size != rhs.size) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceDXGISharedHandleDescriptor) == sizeof(WGPUSharedFenceDXGISharedHandleDescriptor), "sizeof mismatch for SharedFenceDXGISharedHandleDescriptor");
    static_assert(alignof(SharedFenceDXGISharedHandleDescriptor) == alignof(WGPUSharedFenceDXGISharedHandleDescriptor), "alignof mismatch for SharedFenceDXGISharedHandleDescriptor");

    static_assert(offsetof(SharedFenceDXGISharedHandleDescriptor, nextInChain) == offsetof(WGPUSharedFenceDXGISharedHandleDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceDXGISharedHandleDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceDXGISharedHandleDescriptor, sType) == offsetof(WGPUSharedFenceDXGISharedHandleDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceDXGISharedHandleDescriptor::sType");
    static_assert(offsetof(SharedFenceDXGISharedHandleDescriptor, handle) == offsetof(WGPUSharedFenceDXGISharedHandleDescriptor, handle),
                 "offsetof mismatch for SharedFenceDXGISharedHandleDescriptor::handle");

    bool SharedFenceDXGISharedHandleDescriptor::operator==(const SharedFenceDXGISharedHandleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceDXGISharedHandleExportInfo) == sizeof(WGPUSharedFenceDXGISharedHandleExportInfo), "sizeof mismatch for SharedFenceDXGISharedHandleExportInfo");
    static_assert(alignof(SharedFenceDXGISharedHandleExportInfo) == alignof(WGPUSharedFenceDXGISharedHandleExportInfo), "alignof mismatch for SharedFenceDXGISharedHandleExportInfo");

    static_assert(offsetof(SharedFenceDXGISharedHandleExportInfo, nextInChain) == offsetof(WGPUSharedFenceDXGISharedHandleExportInfo, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceDXGISharedHandleExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceDXGISharedHandleExportInfo, sType) == offsetof(WGPUSharedFenceDXGISharedHandleExportInfo, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceDXGISharedHandleExportInfo::sType");
    static_assert(offsetof(SharedFenceDXGISharedHandleExportInfo, handle) == offsetof(WGPUSharedFenceDXGISharedHandleExportInfo, handle),
                 "offsetof mismatch for SharedFenceDXGISharedHandleExportInfo::handle");

    bool SharedFenceDXGISharedHandleExportInfo::operator==(const SharedFenceDXGISharedHandleExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceEGLSyncDescriptor) == sizeof(WGPUSharedFenceEGLSyncDescriptor), "sizeof mismatch for SharedFenceEGLSyncDescriptor");
    static_assert(alignof(SharedFenceEGLSyncDescriptor) == alignof(WGPUSharedFenceEGLSyncDescriptor), "alignof mismatch for SharedFenceEGLSyncDescriptor");

    static_assert(offsetof(SharedFenceEGLSyncDescriptor, nextInChain) == offsetof(WGPUSharedFenceEGLSyncDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceEGLSyncDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceEGLSyncDescriptor, sType) == offsetof(WGPUSharedFenceEGLSyncDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceEGLSyncDescriptor::sType");
    static_assert(offsetof(SharedFenceEGLSyncDescriptor, sync) == offsetof(WGPUSharedFenceEGLSyncDescriptor, sync),
                 "offsetof mismatch for SharedFenceEGLSyncDescriptor::sync");

    bool SharedFenceEGLSyncDescriptor::operator==(const SharedFenceEGLSyncDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sync != rhs.sync) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceEGLSyncExportInfo) == sizeof(WGPUSharedFenceEGLSyncExportInfo), "sizeof mismatch for SharedFenceEGLSyncExportInfo");
    static_assert(alignof(SharedFenceEGLSyncExportInfo) == alignof(WGPUSharedFenceEGLSyncExportInfo), "alignof mismatch for SharedFenceEGLSyncExportInfo");

    static_assert(offsetof(SharedFenceEGLSyncExportInfo, nextInChain) == offsetof(WGPUSharedFenceEGLSyncExportInfo, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceEGLSyncExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceEGLSyncExportInfo, sType) == offsetof(WGPUSharedFenceEGLSyncExportInfo, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceEGLSyncExportInfo::sType");
    static_assert(offsetof(SharedFenceEGLSyncExportInfo, sync) == offsetof(WGPUSharedFenceEGLSyncExportInfo, sync),
                 "offsetof mismatch for SharedFenceEGLSyncExportInfo::sync");

    bool SharedFenceEGLSyncExportInfo::operator==(const SharedFenceEGLSyncExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sync != rhs.sync) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceMTLSharedEventDescriptor) == sizeof(WGPUSharedFenceMTLSharedEventDescriptor), "sizeof mismatch for SharedFenceMTLSharedEventDescriptor");
    static_assert(alignof(SharedFenceMTLSharedEventDescriptor) == alignof(WGPUSharedFenceMTLSharedEventDescriptor), "alignof mismatch for SharedFenceMTLSharedEventDescriptor");

    static_assert(offsetof(SharedFenceMTLSharedEventDescriptor, nextInChain) == offsetof(WGPUSharedFenceMTLSharedEventDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceMTLSharedEventDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceMTLSharedEventDescriptor, sType) == offsetof(WGPUSharedFenceMTLSharedEventDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceMTLSharedEventDescriptor::sType");
    static_assert(offsetof(SharedFenceMTLSharedEventDescriptor, sharedEvent) == offsetof(WGPUSharedFenceMTLSharedEventDescriptor, sharedEvent),
                 "offsetof mismatch for SharedFenceMTLSharedEventDescriptor::sharedEvent");

    bool SharedFenceMTLSharedEventDescriptor::operator==(const SharedFenceMTLSharedEventDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sharedEvent != rhs.sharedEvent) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceMTLSharedEventExportInfo) == sizeof(WGPUSharedFenceMTLSharedEventExportInfo), "sizeof mismatch for SharedFenceMTLSharedEventExportInfo");
    static_assert(alignof(SharedFenceMTLSharedEventExportInfo) == alignof(WGPUSharedFenceMTLSharedEventExportInfo), "alignof mismatch for SharedFenceMTLSharedEventExportInfo");

    static_assert(offsetof(SharedFenceMTLSharedEventExportInfo, nextInChain) == offsetof(WGPUSharedFenceMTLSharedEventExportInfo, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceMTLSharedEventExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceMTLSharedEventExportInfo, sType) == offsetof(WGPUSharedFenceMTLSharedEventExportInfo, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceMTLSharedEventExportInfo::sType");
    static_assert(offsetof(SharedFenceMTLSharedEventExportInfo, sharedEvent) == offsetof(WGPUSharedFenceMTLSharedEventExportInfo, sharedEvent),
                 "offsetof mismatch for SharedFenceMTLSharedEventExportInfo::sharedEvent");

    bool SharedFenceMTLSharedEventExportInfo::operator==(const SharedFenceMTLSharedEventExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sharedEvent != rhs.sharedEvent) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceSyncFDDescriptor) == sizeof(WGPUSharedFenceSyncFDDescriptor), "sizeof mismatch for SharedFenceSyncFDDescriptor");
    static_assert(alignof(SharedFenceSyncFDDescriptor) == alignof(WGPUSharedFenceSyncFDDescriptor), "alignof mismatch for SharedFenceSyncFDDescriptor");

    static_assert(offsetof(SharedFenceSyncFDDescriptor, nextInChain) == offsetof(WGPUSharedFenceSyncFDDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceSyncFDDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceSyncFDDescriptor, sType) == offsetof(WGPUSharedFenceSyncFDDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceSyncFDDescriptor::sType");
    static_assert(offsetof(SharedFenceSyncFDDescriptor, handle) == offsetof(WGPUSharedFenceSyncFDDescriptor, handle),
                 "offsetof mismatch for SharedFenceSyncFDDescriptor::handle");

    bool SharedFenceSyncFDDescriptor::operator==(const SharedFenceSyncFDDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceSyncFDExportInfo) == sizeof(WGPUSharedFenceSyncFDExportInfo), "sizeof mismatch for SharedFenceSyncFDExportInfo");
    static_assert(alignof(SharedFenceSyncFDExportInfo) == alignof(WGPUSharedFenceSyncFDExportInfo), "alignof mismatch for SharedFenceSyncFDExportInfo");

    static_assert(offsetof(SharedFenceSyncFDExportInfo, nextInChain) == offsetof(WGPUSharedFenceSyncFDExportInfo, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceSyncFDExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceSyncFDExportInfo, sType) == offsetof(WGPUSharedFenceSyncFDExportInfo, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceSyncFDExportInfo::sType");
    static_assert(offsetof(SharedFenceSyncFDExportInfo, handle) == offsetof(WGPUSharedFenceSyncFDExportInfo, handle),
                 "offsetof mismatch for SharedFenceSyncFDExportInfo::handle");

    bool SharedFenceSyncFDExportInfo::operator==(const SharedFenceSyncFDExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceVkSemaphoreOpaqueFDDescriptor) == sizeof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor), "sizeof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor");
    static_assert(alignof(SharedFenceVkSemaphoreOpaqueFDDescriptor) == alignof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor), "alignof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor");

    static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDDescriptor, nextInChain) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDDescriptor, sType) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor::sType");
    static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDDescriptor, handle) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor, handle),
                 "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor::handle");

    bool SharedFenceVkSemaphoreOpaqueFDDescriptor::operator==(const SharedFenceVkSemaphoreOpaqueFDDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceVkSemaphoreOpaqueFDExportInfo) == sizeof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo), "sizeof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo");
    static_assert(alignof(SharedFenceVkSemaphoreOpaqueFDExportInfo) == alignof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo), "alignof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo");

    static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDExportInfo, nextInChain) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDExportInfo, sType) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo::sType");
    static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDExportInfo, handle) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo, handle),
                 "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo::handle");

    bool SharedFenceVkSemaphoreOpaqueFDExportInfo::operator==(const SharedFenceVkSemaphoreOpaqueFDExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceVkSemaphoreZirconHandleDescriptor) == sizeof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor), "sizeof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor");
    static_assert(alignof(SharedFenceVkSemaphoreZirconHandleDescriptor) == alignof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor), "alignof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor");

    static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleDescriptor, nextInChain) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleDescriptor, sType) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor::sType");
    static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleDescriptor, handle) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor, handle),
                 "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor::handle");

    bool SharedFenceVkSemaphoreZirconHandleDescriptor::operator==(const SharedFenceVkSemaphoreZirconHandleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceVkSemaphoreZirconHandleExportInfo) == sizeof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo), "sizeof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo");
    static_assert(alignof(SharedFenceVkSemaphoreZirconHandleExportInfo) == alignof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo), "alignof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo");

    static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleExportInfo, nextInChain) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleExportInfo, sType) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo::sType");
    static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleExportInfo, handle) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo, handle),
                 "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo::handle");

    bool SharedFenceVkSemaphoreZirconHandleExportInfo::operator==(const SharedFenceVkSemaphoreZirconHandleExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryAHardwareBufferDescriptor) == sizeof(WGPUSharedTextureMemoryAHardwareBufferDescriptor), "sizeof mismatch for SharedTextureMemoryAHardwareBufferDescriptor");
    static_assert(alignof(SharedTextureMemoryAHardwareBufferDescriptor) == alignof(WGPUSharedTextureMemoryAHardwareBufferDescriptor), "alignof mismatch for SharedTextureMemoryAHardwareBufferDescriptor");

    static_assert(offsetof(SharedTextureMemoryAHardwareBufferDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryAHardwareBufferDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryAHardwareBufferDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryAHardwareBufferDescriptor, sType) == offsetof(WGPUSharedTextureMemoryAHardwareBufferDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryAHardwareBufferDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryAHardwareBufferDescriptor, handle) == offsetof(WGPUSharedTextureMemoryAHardwareBufferDescriptor, handle),
                 "offsetof mismatch for SharedTextureMemoryAHardwareBufferDescriptor::handle");

    bool SharedTextureMemoryAHardwareBufferDescriptor::operator==(const SharedTextureMemoryAHardwareBufferDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryD3D11BeginState) == sizeof(WGPUSharedTextureMemoryD3D11BeginState), "sizeof mismatch for SharedTextureMemoryD3D11BeginState");
    static_assert(alignof(SharedTextureMemoryD3D11BeginState) == alignof(WGPUSharedTextureMemoryD3D11BeginState), "alignof mismatch for SharedTextureMemoryD3D11BeginState");

    static_assert(offsetof(SharedTextureMemoryD3D11BeginState, nextInChain) == offsetof(WGPUSharedTextureMemoryD3D11BeginState, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryD3D11BeginState::nextInChain");
    static_assert(offsetof(SharedTextureMemoryD3D11BeginState, sType) == offsetof(WGPUSharedTextureMemoryD3D11BeginState, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryD3D11BeginState::sType");
    static_assert(offsetof(SharedTextureMemoryD3D11BeginState, requiresEndAccessFence) == offsetof(WGPUSharedTextureMemoryD3D11BeginState, requiresEndAccessFence),
                 "offsetof mismatch for SharedTextureMemoryD3D11BeginState::requiresEndAccessFence");

    bool SharedTextureMemoryD3D11BeginState::operator==(const SharedTextureMemoryD3D11BeginState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (requiresEndAccessFence != rhs.requiresEndAccessFence) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryD3DSwapchainBeginState) == sizeof(WGPUSharedTextureMemoryD3DSwapchainBeginState), "sizeof mismatch for SharedTextureMemoryD3DSwapchainBeginState");
    static_assert(alignof(SharedTextureMemoryD3DSwapchainBeginState) == alignof(WGPUSharedTextureMemoryD3DSwapchainBeginState), "alignof mismatch for SharedTextureMemoryD3DSwapchainBeginState");

    static_assert(offsetof(SharedTextureMemoryD3DSwapchainBeginState, nextInChain) == offsetof(WGPUSharedTextureMemoryD3DSwapchainBeginState, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryD3DSwapchainBeginState::nextInChain");
    static_assert(offsetof(SharedTextureMemoryD3DSwapchainBeginState, sType) == offsetof(WGPUSharedTextureMemoryD3DSwapchainBeginState, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryD3DSwapchainBeginState::sType");
    static_assert(offsetof(SharedTextureMemoryD3DSwapchainBeginState, isSwapchain) == offsetof(WGPUSharedTextureMemoryD3DSwapchainBeginState, isSwapchain),
                 "offsetof mismatch for SharedTextureMemoryD3DSwapchainBeginState::isSwapchain");

    bool SharedTextureMemoryD3DSwapchainBeginState::operator==(const SharedTextureMemoryD3DSwapchainBeginState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (isSwapchain != rhs.isSwapchain) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryDmaBufPlane) == sizeof(WGPUSharedTextureMemoryDmaBufPlane), "sizeof mismatch for SharedTextureMemoryDmaBufPlane");
    static_assert(alignof(SharedTextureMemoryDmaBufPlane) == alignof(WGPUSharedTextureMemoryDmaBufPlane), "alignof mismatch for SharedTextureMemoryDmaBufPlane");

    static_assert(offsetof(SharedTextureMemoryDmaBufPlane, fd) == offsetof(WGPUSharedTextureMemoryDmaBufPlane, fd),
                 "offsetof mismatch for SharedTextureMemoryDmaBufPlane::fd");
    static_assert(offsetof(SharedTextureMemoryDmaBufPlane, offset) == offsetof(WGPUSharedTextureMemoryDmaBufPlane, offset),
                 "offsetof mismatch for SharedTextureMemoryDmaBufPlane::offset");
    static_assert(offsetof(SharedTextureMemoryDmaBufPlane, stride) == offsetof(WGPUSharedTextureMemoryDmaBufPlane, stride),
                 "offsetof mismatch for SharedTextureMemoryDmaBufPlane::stride");

    bool SharedTextureMemoryDmaBufPlane::operator==(const SharedTextureMemoryDmaBufPlane& rhs) const {
        if (fd != rhs.fd) { return false; }
        if (offset != rhs.offset) { return false; }
        if (stride != rhs.stride) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryDXGISharedHandleDescriptor) == sizeof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor), "sizeof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor");
    static_assert(alignof(SharedTextureMemoryDXGISharedHandleDescriptor) == alignof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor), "alignof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor");

    static_assert(offsetof(SharedTextureMemoryDXGISharedHandleDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryDXGISharedHandleDescriptor, sType) == offsetof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryDXGISharedHandleDescriptor, handle) == offsetof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, handle),
                 "offsetof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor::handle");
    static_assert(offsetof(SharedTextureMemoryDXGISharedHandleDescriptor, useKeyedMutex) == offsetof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, useKeyedMutex),
                 "offsetof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor::useKeyedMutex");

    bool SharedTextureMemoryDXGISharedHandleDescriptor::operator==(const SharedTextureMemoryDXGISharedHandleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (handle != rhs.handle) { return false; }
        if (useKeyedMutex != rhs.useKeyedMutex) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryEGLImageDescriptor) == sizeof(WGPUSharedTextureMemoryEGLImageDescriptor), "sizeof mismatch for SharedTextureMemoryEGLImageDescriptor");
    static_assert(alignof(SharedTextureMemoryEGLImageDescriptor) == alignof(WGPUSharedTextureMemoryEGLImageDescriptor), "alignof mismatch for SharedTextureMemoryEGLImageDescriptor");

    static_assert(offsetof(SharedTextureMemoryEGLImageDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryEGLImageDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryEGLImageDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryEGLImageDescriptor, sType) == offsetof(WGPUSharedTextureMemoryEGLImageDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryEGLImageDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryEGLImageDescriptor, image) == offsetof(WGPUSharedTextureMemoryEGLImageDescriptor, image),
                 "offsetof mismatch for SharedTextureMemoryEGLImageDescriptor::image");

    bool SharedTextureMemoryEGLImageDescriptor::operator==(const SharedTextureMemoryEGLImageDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (image != rhs.image) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryIOSurfaceDescriptor) == sizeof(WGPUSharedTextureMemoryIOSurfaceDescriptor), "sizeof mismatch for SharedTextureMemoryIOSurfaceDescriptor");
    static_assert(alignof(SharedTextureMemoryIOSurfaceDescriptor) == alignof(WGPUSharedTextureMemoryIOSurfaceDescriptor), "alignof mismatch for SharedTextureMemoryIOSurfaceDescriptor");

    static_assert(offsetof(SharedTextureMemoryIOSurfaceDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryIOSurfaceDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryIOSurfaceDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryIOSurfaceDescriptor, sType) == offsetof(WGPUSharedTextureMemoryIOSurfaceDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryIOSurfaceDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryIOSurfaceDescriptor, ioSurface) == offsetof(WGPUSharedTextureMemoryIOSurfaceDescriptor, ioSurface),
                 "offsetof mismatch for SharedTextureMemoryIOSurfaceDescriptor::ioSurface");
    static_assert(offsetof(SharedTextureMemoryIOSurfaceDescriptor, allowStorageBinding) == offsetof(WGPUSharedTextureMemoryIOSurfaceDescriptor, allowStorageBinding),
                 "offsetof mismatch for SharedTextureMemoryIOSurfaceDescriptor::allowStorageBinding");

    bool SharedTextureMemoryIOSurfaceDescriptor::operator==(const SharedTextureMemoryIOSurfaceDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (ioSurface != rhs.ioSurface) { return false; }
        if (allowStorageBinding != rhs.allowStorageBinding) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryOpaqueFDDescriptor) == sizeof(WGPUSharedTextureMemoryOpaqueFDDescriptor), "sizeof mismatch for SharedTextureMemoryOpaqueFDDescriptor");
    static_assert(alignof(SharedTextureMemoryOpaqueFDDescriptor) == alignof(WGPUSharedTextureMemoryOpaqueFDDescriptor), "alignof mismatch for SharedTextureMemoryOpaqueFDDescriptor");

    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, sType) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, vkImageCreateInfo) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, vkImageCreateInfo),
                 "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::vkImageCreateInfo");
    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, memoryFD) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, memoryFD),
                 "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::memoryFD");
    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, memoryTypeIndex) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, memoryTypeIndex),
                 "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::memoryTypeIndex");
    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, allocationSize) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, allocationSize),
                 "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::allocationSize");
    static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, dedicatedAllocation) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, dedicatedAllocation),
                 "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::dedicatedAllocation");

    bool SharedTextureMemoryOpaqueFDDescriptor::operator==(const SharedTextureMemoryOpaqueFDDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (vkImageCreateInfo != rhs.vkImageCreateInfo) { return false; }
        if (memoryFD != rhs.memoryFD) { return false; }
        if (memoryTypeIndex != rhs.memoryTypeIndex) { return false; }
        if (allocationSize != rhs.allocationSize) { return false; }
        if (dedicatedAllocation != rhs.dedicatedAllocation) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryVkDedicatedAllocationDescriptor) == sizeof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor), "sizeof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor");
    static_assert(alignof(SharedTextureMemoryVkDedicatedAllocationDescriptor) == alignof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor), "alignof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor");

    static_assert(offsetof(SharedTextureMemoryVkDedicatedAllocationDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryVkDedicatedAllocationDescriptor, sType) == offsetof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryVkDedicatedAllocationDescriptor, dedicatedAllocation) == offsetof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor, dedicatedAllocation),
                 "offsetof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor::dedicatedAllocation");

    bool SharedTextureMemoryVkDedicatedAllocationDescriptor::operator==(const SharedTextureMemoryVkDedicatedAllocationDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (dedicatedAllocation != rhs.dedicatedAllocation) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryVkImageLayoutBeginState) == sizeof(WGPUSharedTextureMemoryVkImageLayoutBeginState), "sizeof mismatch for SharedTextureMemoryVkImageLayoutBeginState");
    static_assert(alignof(SharedTextureMemoryVkImageLayoutBeginState) == alignof(WGPUSharedTextureMemoryVkImageLayoutBeginState), "alignof mismatch for SharedTextureMemoryVkImageLayoutBeginState");

    static_assert(offsetof(SharedTextureMemoryVkImageLayoutBeginState, nextInChain) == offsetof(WGPUSharedTextureMemoryVkImageLayoutBeginState, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryVkImageLayoutBeginState::nextInChain");
    static_assert(offsetof(SharedTextureMemoryVkImageLayoutBeginState, sType) == offsetof(WGPUSharedTextureMemoryVkImageLayoutBeginState, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryVkImageLayoutBeginState::sType");
    static_assert(offsetof(SharedTextureMemoryVkImageLayoutBeginState, oldLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutBeginState, oldLayout),
                 "offsetof mismatch for SharedTextureMemoryVkImageLayoutBeginState::oldLayout");
    static_assert(offsetof(SharedTextureMemoryVkImageLayoutBeginState, newLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutBeginState, newLayout),
                 "offsetof mismatch for SharedTextureMemoryVkImageLayoutBeginState::newLayout");

    bool SharedTextureMemoryVkImageLayoutBeginState::operator==(const SharedTextureMemoryVkImageLayoutBeginState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (oldLayout != rhs.oldLayout) { return false; }
        if (newLayout != rhs.newLayout) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryVkImageLayoutEndState) == sizeof(WGPUSharedTextureMemoryVkImageLayoutEndState), "sizeof mismatch for SharedTextureMemoryVkImageLayoutEndState");
    static_assert(alignof(SharedTextureMemoryVkImageLayoutEndState) == alignof(WGPUSharedTextureMemoryVkImageLayoutEndState), "alignof mismatch for SharedTextureMemoryVkImageLayoutEndState");

    static_assert(offsetof(SharedTextureMemoryVkImageLayoutEndState, nextInChain) == offsetof(WGPUSharedTextureMemoryVkImageLayoutEndState, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryVkImageLayoutEndState::nextInChain");
    static_assert(offsetof(SharedTextureMemoryVkImageLayoutEndState, sType) == offsetof(WGPUSharedTextureMemoryVkImageLayoutEndState, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryVkImageLayoutEndState::sType");
    static_assert(offsetof(SharedTextureMemoryVkImageLayoutEndState, oldLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutEndState, oldLayout),
                 "offsetof mismatch for SharedTextureMemoryVkImageLayoutEndState::oldLayout");
    static_assert(offsetof(SharedTextureMemoryVkImageLayoutEndState, newLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutEndState, newLayout),
                 "offsetof mismatch for SharedTextureMemoryVkImageLayoutEndState::newLayout");

    bool SharedTextureMemoryVkImageLayoutEndState::operator==(const SharedTextureMemoryVkImageLayoutEndState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (oldLayout != rhs.oldLayout) { return false; }
        if (newLayout != rhs.newLayout) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryZirconHandleDescriptor) == sizeof(WGPUSharedTextureMemoryZirconHandleDescriptor), "sizeof mismatch for SharedTextureMemoryZirconHandleDescriptor");
    static_assert(alignof(SharedTextureMemoryZirconHandleDescriptor) == alignof(WGPUSharedTextureMemoryZirconHandleDescriptor), "alignof mismatch for SharedTextureMemoryZirconHandleDescriptor");

    static_assert(offsetof(SharedTextureMemoryZirconHandleDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryZirconHandleDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryZirconHandleDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryZirconHandleDescriptor, sType) == offsetof(WGPUSharedTextureMemoryZirconHandleDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryZirconHandleDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryZirconHandleDescriptor, memoryFD) == offsetof(WGPUSharedTextureMemoryZirconHandleDescriptor, memoryFD),
                 "offsetof mismatch for SharedTextureMemoryZirconHandleDescriptor::memoryFD");
    static_assert(offsetof(SharedTextureMemoryZirconHandleDescriptor, allocationSize) == offsetof(WGPUSharedTextureMemoryZirconHandleDescriptor, allocationSize),
                 "offsetof mismatch for SharedTextureMemoryZirconHandleDescriptor::allocationSize");

    bool SharedTextureMemoryZirconHandleDescriptor::operator==(const SharedTextureMemoryZirconHandleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (memoryFD != rhs.memoryFD) { return false; }
        if (allocationSize != rhs.allocationSize) { return false; }
        return true;
    }


    static_assert(sizeof(StaticSamplerBindingLayout) == sizeof(WGPUStaticSamplerBindingLayout), "sizeof mismatch for StaticSamplerBindingLayout");
    static_assert(alignof(StaticSamplerBindingLayout) == alignof(WGPUStaticSamplerBindingLayout), "alignof mismatch for StaticSamplerBindingLayout");

    static_assert(offsetof(StaticSamplerBindingLayout, nextInChain) == offsetof(WGPUStaticSamplerBindingLayout, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for StaticSamplerBindingLayout::nextInChain");
    static_assert(offsetof(StaticSamplerBindingLayout, sType) == offsetof(WGPUStaticSamplerBindingLayout, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for StaticSamplerBindingLayout::sType");
    static_assert(offsetof(StaticSamplerBindingLayout, sampler) == offsetof(WGPUStaticSamplerBindingLayout, sampler),
                 "offsetof mismatch for StaticSamplerBindingLayout::sampler");
    static_assert(offsetof(StaticSamplerBindingLayout, sampledTextureBinding) == offsetof(WGPUStaticSamplerBindingLayout, sampledTextureBinding),
                 "offsetof mismatch for StaticSamplerBindingLayout::sampledTextureBinding");

    bool StaticSamplerBindingLayout::operator==(const StaticSamplerBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sampler != rhs.sampler) { return false; }
        if (sampledTextureBinding != rhs.sampledTextureBinding) { return false; }
        return true;
    }


    static_assert(sizeof(StencilFaceState) == sizeof(WGPUStencilFaceState), "sizeof mismatch for StencilFaceState");
    static_assert(alignof(StencilFaceState) == alignof(WGPUStencilFaceState), "alignof mismatch for StencilFaceState");

    static_assert(offsetof(StencilFaceState, compare) == offsetof(WGPUStencilFaceState, compare),
                 "offsetof mismatch for StencilFaceState::compare");
    static_assert(offsetof(StencilFaceState, failOp) == offsetof(WGPUStencilFaceState, failOp),
                 "offsetof mismatch for StencilFaceState::failOp");
    static_assert(offsetof(StencilFaceState, depthFailOp) == offsetof(WGPUStencilFaceState, depthFailOp),
                 "offsetof mismatch for StencilFaceState::depthFailOp");
    static_assert(offsetof(StencilFaceState, passOp) == offsetof(WGPUStencilFaceState, passOp),
                 "offsetof mismatch for StencilFaceState::passOp");

    StencilFaceState StencilFaceState::WithTrivialFrontendDefaults() const {
        StencilFaceState copy;
        copy.compare = (compare == wgpu::CompareFunction::Undefined)
            ? wgpu::CompareFunction::Always
            : compare;
        copy.failOp = (failOp == wgpu::StencilOperation::Undefined)
            ? wgpu::StencilOperation::Keep
            : failOp;
        copy.depthFailOp = (depthFailOp == wgpu::StencilOperation::Undefined)
            ? wgpu::StencilOperation::Keep
            : depthFailOp;
        copy.passOp = (passOp == wgpu::StencilOperation::Undefined)
            ? wgpu::StencilOperation::Keep
            : passOp;
        return copy;
    }
    bool StencilFaceState::operator==(const StencilFaceState& rhs) const {
        if (compare != rhs.compare) { return false; }
        if (failOp != rhs.failOp) { return false; }
        if (depthFailOp != rhs.depthFailOp) { return false; }
        if (passOp != rhs.passOp) { return false; }
        return true;
    }


    static_assert(sizeof(StorageTextureBindingLayout) == sizeof(WGPUStorageTextureBindingLayout), "sizeof mismatch for StorageTextureBindingLayout");
    static_assert(alignof(StorageTextureBindingLayout) == alignof(WGPUStorageTextureBindingLayout), "alignof mismatch for StorageTextureBindingLayout");

    static_assert(offsetof(StorageTextureBindingLayout, nextInChain) == offsetof(WGPUStorageTextureBindingLayout, nextInChain),
            "offsetof mismatch for StorageTextureBindingLayout::nextInChain");
    static_assert(offsetof(StorageTextureBindingLayout, access) == offsetof(WGPUStorageTextureBindingLayout, access),
                 "offsetof mismatch for StorageTextureBindingLayout::access");
    static_assert(offsetof(StorageTextureBindingLayout, format) == offsetof(WGPUStorageTextureBindingLayout, format),
                 "offsetof mismatch for StorageTextureBindingLayout::format");
    static_assert(offsetof(StorageTextureBindingLayout, viewDimension) == offsetof(WGPUStorageTextureBindingLayout, viewDimension),
                 "offsetof mismatch for StorageTextureBindingLayout::viewDimension");

    StorageTextureBindingLayout StorageTextureBindingLayout::WithTrivialFrontendDefaults() const {
        StorageTextureBindingLayout copy;
        copy.nextInChain = nextInChain;
        copy.access = (access == wgpu::StorageTextureAccess::Undefined)
            ? wgpu::StorageTextureAccess::WriteOnly
            : access;
        copy.format = format;
        copy.viewDimension = (viewDimension == wgpu::TextureViewDimension::Undefined)
            ? wgpu::TextureViewDimension::e2D
            : viewDimension;
        return copy;
    }
    bool StorageTextureBindingLayout::operator==(const StorageTextureBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (access != rhs.access) { return false; }
        if (format != rhs.format) { return false; }
        if (viewDimension != rhs.viewDimension) { return false; }
        return true;
    }


    static_assert(sizeof(SubgroupMatrixConfig) == sizeof(WGPUSubgroupMatrixConfig), "sizeof mismatch for SubgroupMatrixConfig");
    static_assert(alignof(SubgroupMatrixConfig) == alignof(WGPUSubgroupMatrixConfig), "alignof mismatch for SubgroupMatrixConfig");

    static_assert(offsetof(SubgroupMatrixConfig, componentType) == offsetof(WGPUSubgroupMatrixConfig, componentType),
                 "offsetof mismatch for SubgroupMatrixConfig::componentType");
    static_assert(offsetof(SubgroupMatrixConfig, resultComponentType) == offsetof(WGPUSubgroupMatrixConfig, resultComponentType),
                 "offsetof mismatch for SubgroupMatrixConfig::resultComponentType");
    static_assert(offsetof(SubgroupMatrixConfig, M) == offsetof(WGPUSubgroupMatrixConfig, M),
                 "offsetof mismatch for SubgroupMatrixConfig::M");
    static_assert(offsetof(SubgroupMatrixConfig, N) == offsetof(WGPUSubgroupMatrixConfig, N),
                 "offsetof mismatch for SubgroupMatrixConfig::N");
    static_assert(offsetof(SubgroupMatrixConfig, K) == offsetof(WGPUSubgroupMatrixConfig, K),
                 "offsetof mismatch for SubgroupMatrixConfig::K");

    bool SubgroupMatrixConfig::operator==(const SubgroupMatrixConfig& rhs) const {
        if (componentType != rhs.componentType) { return false; }
        if (resultComponentType != rhs.resultComponentType) { return false; }
        if (M != rhs.M) { return false; }
        if (N != rhs.N) { return false; }
        if (K != rhs.K) { return false; }
        return true;
    }


    static_assert(sizeof(SupportedFeatures) == sizeof(WGPUSupportedFeatures), "sizeof mismatch for SupportedFeatures");
    static_assert(alignof(SupportedFeatures) == alignof(WGPUSupportedFeatures), "alignof mismatch for SupportedFeatures");

    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SupportedFeaturesfeaturesSpan = decltype(std::declval<SupportedFeatures>().features);
    
    static_assert(offsetof(SupportedFeatures, features) + SupportedFeaturesfeaturesSpan::GetOffsetOfSize() == offsetof(WGPUSupportedFeatures, featureCount),
                 "offsetof mismatch for SupportedFeatures::features::mSize");
    static_assert(offsetof(SupportedFeatures, features) + SupportedFeaturesfeaturesSpan::GetOffsetOfData() == offsetof(WGPUSupportedFeatures, features),
                 "offsetof mismatch for SupportedFeatures::features::mData");

    bool SupportedFeatures::operator==(const SupportedFeatures& rhs) const {
        if (features.size() != rhs.features.size()) { return false; }
        if (features.data() != rhs.features.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SupportedInstanceFeatures) == sizeof(WGPUSupportedInstanceFeatures), "sizeof mismatch for SupportedInstanceFeatures");
    static_assert(alignof(SupportedInstanceFeatures) == alignof(WGPUSupportedInstanceFeatures), "alignof mismatch for SupportedInstanceFeatures");

    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SupportedInstanceFeaturesfeaturesSpan = decltype(std::declval<SupportedInstanceFeatures>().features);
    
    static_assert(offsetof(SupportedInstanceFeatures, features) + SupportedInstanceFeaturesfeaturesSpan::GetOffsetOfSize() == offsetof(WGPUSupportedInstanceFeatures, featureCount),
                 "offsetof mismatch for SupportedInstanceFeatures::features::mSize");
    static_assert(offsetof(SupportedInstanceFeatures, features) + SupportedInstanceFeaturesfeaturesSpan::GetOffsetOfData() == offsetof(WGPUSupportedInstanceFeatures, features),
                 "offsetof mismatch for SupportedInstanceFeatures::features::mData");

    bool SupportedInstanceFeatures::operator==(const SupportedInstanceFeatures& rhs) const {
        if (features.size() != rhs.features.size()) { return false; }
        if (features.data() != rhs.features.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SupportedWGSLLanguageFeatures) == sizeof(WGPUSupportedWGSLLanguageFeatures), "sizeof mismatch for SupportedWGSLLanguageFeatures");
    static_assert(alignof(SupportedWGSLLanguageFeatures) == alignof(WGPUSupportedWGSLLanguageFeatures), "alignof mismatch for SupportedWGSLLanguageFeatures");

    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SupportedWGSLLanguageFeaturesfeaturesSpan = decltype(std::declval<SupportedWGSLLanguageFeatures>().features);
    
    static_assert(offsetof(SupportedWGSLLanguageFeatures, features) + SupportedWGSLLanguageFeaturesfeaturesSpan::GetOffsetOfSize() == offsetof(WGPUSupportedWGSLLanguageFeatures, featureCount),
                 "offsetof mismatch for SupportedWGSLLanguageFeatures::features::mSize");
    static_assert(offsetof(SupportedWGSLLanguageFeatures, features) + SupportedWGSLLanguageFeaturesfeaturesSpan::GetOffsetOfData() == offsetof(WGPUSupportedWGSLLanguageFeatures, features),
                 "offsetof mismatch for SupportedWGSLLanguageFeatures::features::mData");

    bool SupportedWGSLLanguageFeatures::operator==(const SupportedWGSLLanguageFeatures& rhs) const {
        if (features.size() != rhs.features.size()) { return false; }
        if (features.data() != rhs.features.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceCapabilities) == sizeof(WGPUSurfaceCapabilities), "sizeof mismatch for SurfaceCapabilities");
    static_assert(alignof(SurfaceCapabilities) == alignof(WGPUSurfaceCapabilities), "alignof mismatch for SurfaceCapabilities");

    static_assert(offsetof(SurfaceCapabilities, nextInChain) == offsetof(WGPUSurfaceCapabilities, nextInChain),
            "offsetof mismatch for SurfaceCapabilities::nextInChain");
    static_assert(offsetof(SurfaceCapabilities, usages) == offsetof(WGPUSurfaceCapabilities, usages),
                 "offsetof mismatch for SurfaceCapabilities::usages");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SurfaceCapabilitiesformatsSpan = decltype(std::declval<SurfaceCapabilities>().formats);
    
    static_assert(offsetof(SurfaceCapabilities, formats) + SurfaceCapabilitiesformatsSpan::GetOffsetOfSize() == offsetof(WGPUSurfaceCapabilities, formatCount),
                 "offsetof mismatch for SurfaceCapabilities::formats::mSize");
    static_assert(offsetof(SurfaceCapabilities, formats) + SurfaceCapabilitiesformatsSpan::GetOffsetOfData() == offsetof(WGPUSurfaceCapabilities, formats),
                 "offsetof mismatch for SurfaceCapabilities::formats::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SurfaceCapabilitiespresentModesSpan = decltype(std::declval<SurfaceCapabilities>().presentModes);
    
    static_assert(offsetof(SurfaceCapabilities, presentModes) + SurfaceCapabilitiespresentModesSpan::GetOffsetOfSize() == offsetof(WGPUSurfaceCapabilities, presentModeCount),
                 "offsetof mismatch for SurfaceCapabilities::presentModes::mSize");
    static_assert(offsetof(SurfaceCapabilities, presentModes) + SurfaceCapabilitiespresentModesSpan::GetOffsetOfData() == offsetof(WGPUSurfaceCapabilities, presentModes),
                 "offsetof mismatch for SurfaceCapabilities::presentModes::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SurfaceCapabilitiesalphaModesSpan = decltype(std::declval<SurfaceCapabilities>().alphaModes);
    
    static_assert(offsetof(SurfaceCapabilities, alphaModes) + SurfaceCapabilitiesalphaModesSpan::GetOffsetOfSize() == offsetof(WGPUSurfaceCapabilities, alphaModeCount),
                 "offsetof mismatch for SurfaceCapabilities::alphaModes::mSize");
    static_assert(offsetof(SurfaceCapabilities, alphaModes) + SurfaceCapabilitiesalphaModesSpan::GetOffsetOfData() == offsetof(WGPUSurfaceCapabilities, alphaModes),
                 "offsetof mismatch for SurfaceCapabilities::alphaModes::mData");

    bool SurfaceCapabilities::operator==(const SurfaceCapabilities& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (usages != rhs.usages) { return false; }
        if (formats.size() != rhs.formats.size()) { return false; }
        if (formats.data() != rhs.formats.data()) { return false; }
        if (presentModes.size() != rhs.presentModes.size()) { return false; }
        if (presentModes.data() != rhs.presentModes.data()) { return false; }
        if (alphaModes.size() != rhs.alphaModes.size()) { return false; }
        if (alphaModes.data() != rhs.alphaModes.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceColorManagement) == sizeof(WGPUSurfaceColorManagement), "sizeof mismatch for SurfaceColorManagement");
    static_assert(alignof(SurfaceColorManagement) == alignof(WGPUSurfaceColorManagement), "alignof mismatch for SurfaceColorManagement");

    static_assert(offsetof(SurfaceColorManagement, nextInChain) == offsetof(WGPUSurfaceColorManagement, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceColorManagement::nextInChain");
    static_assert(offsetof(SurfaceColorManagement, sType) == offsetof(WGPUSurfaceColorManagement, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceColorManagement::sType");
    static_assert(offsetof(SurfaceColorManagement, colorSpace) == offsetof(WGPUSurfaceColorManagement, colorSpace),
                 "offsetof mismatch for SurfaceColorManagement::colorSpace");
    static_assert(offsetof(SurfaceColorManagement, toneMappingMode) == offsetof(WGPUSurfaceColorManagement, toneMappingMode),
                 "offsetof mismatch for SurfaceColorManagement::toneMappingMode");

    bool SurfaceColorManagement::operator==(const SurfaceColorManagement& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (colorSpace != rhs.colorSpace) { return false; }
        if (toneMappingMode != rhs.toneMappingMode) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceConfiguration) == sizeof(WGPUSurfaceConfiguration), "sizeof mismatch for SurfaceConfiguration");
    static_assert(alignof(SurfaceConfiguration) == alignof(WGPUSurfaceConfiguration), "alignof mismatch for SurfaceConfiguration");

    static_assert(offsetof(SurfaceConfiguration, nextInChain) == offsetof(WGPUSurfaceConfiguration, nextInChain),
            "offsetof mismatch for SurfaceConfiguration::nextInChain");
    static_assert(offsetof(SurfaceConfiguration, device) == offsetof(WGPUSurfaceConfiguration, device),
                 "offsetof mismatch for SurfaceConfiguration::device");
    static_assert(offsetof(SurfaceConfiguration, format) == offsetof(WGPUSurfaceConfiguration, format),
                 "offsetof mismatch for SurfaceConfiguration::format");
    static_assert(offsetof(SurfaceConfiguration, usage) == offsetof(WGPUSurfaceConfiguration, usage),
                 "offsetof mismatch for SurfaceConfiguration::usage");
    static_assert(offsetof(SurfaceConfiguration, width) == offsetof(WGPUSurfaceConfiguration, width),
                 "offsetof mismatch for SurfaceConfiguration::width");
    static_assert(offsetof(SurfaceConfiguration, height) == offsetof(WGPUSurfaceConfiguration, height),
                 "offsetof mismatch for SurfaceConfiguration::height");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SurfaceConfigurationviewFormatsSpan = decltype(std::declval<SurfaceConfiguration>().viewFormats);
    
    static_assert(offsetof(SurfaceConfiguration, viewFormats) + SurfaceConfigurationviewFormatsSpan::GetOffsetOfSize() == offsetof(WGPUSurfaceConfiguration, viewFormatCount),
                 "offsetof mismatch for SurfaceConfiguration::viewFormats::mSize");
    static_assert(offsetof(SurfaceConfiguration, viewFormats) + SurfaceConfigurationviewFormatsSpan::GetOffsetOfData() == offsetof(WGPUSurfaceConfiguration, viewFormats),
                 "offsetof mismatch for SurfaceConfiguration::viewFormats::mData");
    static_assert(offsetof(SurfaceConfiguration, alphaMode) == offsetof(WGPUSurfaceConfiguration, alphaMode),
                 "offsetof mismatch for SurfaceConfiguration::alphaMode");
    static_assert(offsetof(SurfaceConfiguration, presentMode) == offsetof(WGPUSurfaceConfiguration, presentMode),
                 "offsetof mismatch for SurfaceConfiguration::presentMode");

    SurfaceConfiguration SurfaceConfiguration::WithTrivialFrontendDefaults() const {
        SurfaceConfiguration copy;
        copy.nextInChain = nextInChain;
        copy.device = device;
        copy.format = format;
        copy.usage = usage;
        copy.width = width;
        copy.height = height;
        copy.viewFormats = viewFormats;
        copy.alphaMode = alphaMode;
        copy.presentMode = (presentMode == wgpu::PresentMode::Undefined)
            ? wgpu::PresentMode::Fifo
            : presentMode;
        return copy;
    }
    bool SurfaceConfiguration::operator==(const SurfaceConfiguration& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (device != rhs.device) { return false; }
        if (format != rhs.format) { return false; }
        if (usage != rhs.usage) { return false; }
        if (width != rhs.width) { return false; }
        if (height != rhs.height) { return false; }
        if (viewFormats.size() != rhs.viewFormats.size()) { return false; }
        if (viewFormats.data() != rhs.viewFormats.data()) { return false; }
        if (alphaMode != rhs.alphaMode) { return false; }
        if (presentMode != rhs.presentMode) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceDescriptorFromWindowsCoreWindow) == sizeof(WGPUSurfaceDescriptorFromWindowsCoreWindow), "sizeof mismatch for SurfaceDescriptorFromWindowsCoreWindow");
    static_assert(alignof(SurfaceDescriptorFromWindowsCoreWindow) == alignof(WGPUSurfaceDescriptorFromWindowsCoreWindow), "alignof mismatch for SurfaceDescriptorFromWindowsCoreWindow");

    static_assert(offsetof(SurfaceDescriptorFromWindowsCoreWindow, nextInChain) == offsetof(WGPUSurfaceDescriptorFromWindowsCoreWindow, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceDescriptorFromWindowsCoreWindow::nextInChain");
    static_assert(offsetof(SurfaceDescriptorFromWindowsCoreWindow, sType) == offsetof(WGPUSurfaceDescriptorFromWindowsCoreWindow, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceDescriptorFromWindowsCoreWindow::sType");
    static_assert(offsetof(SurfaceDescriptorFromWindowsCoreWindow, coreWindow) == offsetof(WGPUSurfaceDescriptorFromWindowsCoreWindow, coreWindow),
                 "offsetof mismatch for SurfaceDescriptorFromWindowsCoreWindow::coreWindow");

    bool SurfaceDescriptorFromWindowsCoreWindow::operator==(const SurfaceDescriptorFromWindowsCoreWindow& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (coreWindow != rhs.coreWindow) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceDescriptorFromWindowsUWPSwapChainPanel) == sizeof(WGPUSurfaceDescriptorFromWindowsUWPSwapChainPanel), "sizeof mismatch for SurfaceDescriptorFromWindowsUWPSwapChainPanel");
    static_assert(alignof(SurfaceDescriptorFromWindowsUWPSwapChainPanel) == alignof(WGPUSurfaceDescriptorFromWindowsUWPSwapChainPanel), "alignof mismatch for SurfaceDescriptorFromWindowsUWPSwapChainPanel");

    static_assert(offsetof(SurfaceDescriptorFromWindowsUWPSwapChainPanel, nextInChain) == offsetof(WGPUSurfaceDescriptorFromWindowsUWPSwapChainPanel, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceDescriptorFromWindowsUWPSwapChainPanel::nextInChain");
    static_assert(offsetof(SurfaceDescriptorFromWindowsUWPSwapChainPanel, sType) == offsetof(WGPUSurfaceDescriptorFromWindowsUWPSwapChainPanel, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceDescriptorFromWindowsUWPSwapChainPanel::sType");
    static_assert(offsetof(SurfaceDescriptorFromWindowsUWPSwapChainPanel, swapChainPanel) == offsetof(WGPUSurfaceDescriptorFromWindowsUWPSwapChainPanel, swapChainPanel),
                 "offsetof mismatch for SurfaceDescriptorFromWindowsUWPSwapChainPanel::swapChainPanel");

    bool SurfaceDescriptorFromWindowsUWPSwapChainPanel::operator==(const SurfaceDescriptorFromWindowsUWPSwapChainPanel& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (swapChainPanel != rhs.swapChainPanel) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceDescriptorFromWindowsWinUISwapChainPanel) == sizeof(WGPUSurfaceDescriptorFromWindowsWinUISwapChainPanel), "sizeof mismatch for SurfaceDescriptorFromWindowsWinUISwapChainPanel");
    static_assert(alignof(SurfaceDescriptorFromWindowsWinUISwapChainPanel) == alignof(WGPUSurfaceDescriptorFromWindowsWinUISwapChainPanel), "alignof mismatch for SurfaceDescriptorFromWindowsWinUISwapChainPanel");

    static_assert(offsetof(SurfaceDescriptorFromWindowsWinUISwapChainPanel, nextInChain) == offsetof(WGPUSurfaceDescriptorFromWindowsWinUISwapChainPanel, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceDescriptorFromWindowsWinUISwapChainPanel::nextInChain");
    static_assert(offsetof(SurfaceDescriptorFromWindowsWinUISwapChainPanel, sType) == offsetof(WGPUSurfaceDescriptorFromWindowsWinUISwapChainPanel, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceDescriptorFromWindowsWinUISwapChainPanel::sType");
    static_assert(offsetof(SurfaceDescriptorFromWindowsWinUISwapChainPanel, swapChainPanel) == offsetof(WGPUSurfaceDescriptorFromWindowsWinUISwapChainPanel, swapChainPanel),
                 "offsetof mismatch for SurfaceDescriptorFromWindowsWinUISwapChainPanel::swapChainPanel");

    bool SurfaceDescriptorFromWindowsWinUISwapChainPanel::operator==(const SurfaceDescriptorFromWindowsWinUISwapChainPanel& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (swapChainPanel != rhs.swapChainPanel) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceSourceAndroidNativeWindow) == sizeof(WGPUSurfaceSourceAndroidNativeWindow), "sizeof mismatch for SurfaceSourceAndroidNativeWindow");
    static_assert(alignof(SurfaceSourceAndroidNativeWindow) == alignof(WGPUSurfaceSourceAndroidNativeWindow), "alignof mismatch for SurfaceSourceAndroidNativeWindow");

    static_assert(offsetof(SurfaceSourceAndroidNativeWindow, nextInChain) == offsetof(WGPUSurfaceSourceAndroidNativeWindow, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceSourceAndroidNativeWindow::nextInChain");
    static_assert(offsetof(SurfaceSourceAndroidNativeWindow, sType) == offsetof(WGPUSurfaceSourceAndroidNativeWindow, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceSourceAndroidNativeWindow::sType");
    static_assert(offsetof(SurfaceSourceAndroidNativeWindow, window) == offsetof(WGPUSurfaceSourceAndroidNativeWindow, window),
                 "offsetof mismatch for SurfaceSourceAndroidNativeWindow::window");

    bool SurfaceSourceAndroidNativeWindow::operator==(const SurfaceSourceAndroidNativeWindow& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (window != rhs.window) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceSourceMetalLayer) == sizeof(WGPUSurfaceSourceMetalLayer), "sizeof mismatch for SurfaceSourceMetalLayer");
    static_assert(alignof(SurfaceSourceMetalLayer) == alignof(WGPUSurfaceSourceMetalLayer), "alignof mismatch for SurfaceSourceMetalLayer");

    static_assert(offsetof(SurfaceSourceMetalLayer, nextInChain) == offsetof(WGPUSurfaceSourceMetalLayer, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceSourceMetalLayer::nextInChain");
    static_assert(offsetof(SurfaceSourceMetalLayer, sType) == offsetof(WGPUSurfaceSourceMetalLayer, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceSourceMetalLayer::sType");
    static_assert(offsetof(SurfaceSourceMetalLayer, layer) == offsetof(WGPUSurfaceSourceMetalLayer, layer),
                 "offsetof mismatch for SurfaceSourceMetalLayer::layer");

    bool SurfaceSourceMetalLayer::operator==(const SurfaceSourceMetalLayer& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (layer != rhs.layer) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceSourceWaylandSurface) == sizeof(WGPUSurfaceSourceWaylandSurface), "sizeof mismatch for SurfaceSourceWaylandSurface");
    static_assert(alignof(SurfaceSourceWaylandSurface) == alignof(WGPUSurfaceSourceWaylandSurface), "alignof mismatch for SurfaceSourceWaylandSurface");

    static_assert(offsetof(SurfaceSourceWaylandSurface, nextInChain) == offsetof(WGPUSurfaceSourceWaylandSurface, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceSourceWaylandSurface::nextInChain");
    static_assert(offsetof(SurfaceSourceWaylandSurface, sType) == offsetof(WGPUSurfaceSourceWaylandSurface, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceSourceWaylandSurface::sType");
    static_assert(offsetof(SurfaceSourceWaylandSurface, display) == offsetof(WGPUSurfaceSourceWaylandSurface, display),
                 "offsetof mismatch for SurfaceSourceWaylandSurface::display");
    static_assert(offsetof(SurfaceSourceWaylandSurface, surface) == offsetof(WGPUSurfaceSourceWaylandSurface, surface),
                 "offsetof mismatch for SurfaceSourceWaylandSurface::surface");

    bool SurfaceSourceWaylandSurface::operator==(const SurfaceSourceWaylandSurface& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (display != rhs.display) { return false; }
        if (surface != rhs.surface) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceSourceWindowsHWND) == sizeof(WGPUSurfaceSourceWindowsHWND), "sizeof mismatch for SurfaceSourceWindowsHWND");
    static_assert(alignof(SurfaceSourceWindowsHWND) == alignof(WGPUSurfaceSourceWindowsHWND), "alignof mismatch for SurfaceSourceWindowsHWND");

    static_assert(offsetof(SurfaceSourceWindowsHWND, nextInChain) == offsetof(WGPUSurfaceSourceWindowsHWND, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceSourceWindowsHWND::nextInChain");
    static_assert(offsetof(SurfaceSourceWindowsHWND, sType) == offsetof(WGPUSurfaceSourceWindowsHWND, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceSourceWindowsHWND::sType");
    static_assert(offsetof(SurfaceSourceWindowsHWND, hinstance) == offsetof(WGPUSurfaceSourceWindowsHWND, hinstance),
                 "offsetof mismatch for SurfaceSourceWindowsHWND::hinstance");
    static_assert(offsetof(SurfaceSourceWindowsHWND, hwnd) == offsetof(WGPUSurfaceSourceWindowsHWND, hwnd),
                 "offsetof mismatch for SurfaceSourceWindowsHWND::hwnd");

    bool SurfaceSourceWindowsHWND::operator==(const SurfaceSourceWindowsHWND& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (hinstance != rhs.hinstance) { return false; }
        if (hwnd != rhs.hwnd) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceSourceXCBWindow) == sizeof(WGPUSurfaceSourceXCBWindow), "sizeof mismatch for SurfaceSourceXCBWindow");
    static_assert(alignof(SurfaceSourceXCBWindow) == alignof(WGPUSurfaceSourceXCBWindow), "alignof mismatch for SurfaceSourceXCBWindow");

    static_assert(offsetof(SurfaceSourceXCBWindow, nextInChain) == offsetof(WGPUSurfaceSourceXCBWindow, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceSourceXCBWindow::nextInChain");
    static_assert(offsetof(SurfaceSourceXCBWindow, sType) == offsetof(WGPUSurfaceSourceXCBWindow, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceSourceXCBWindow::sType");
    static_assert(offsetof(SurfaceSourceXCBWindow, connection) == offsetof(WGPUSurfaceSourceXCBWindow, connection),
                 "offsetof mismatch for SurfaceSourceXCBWindow::connection");
    static_assert(offsetof(SurfaceSourceXCBWindow, window) == offsetof(WGPUSurfaceSourceXCBWindow, window),
                 "offsetof mismatch for SurfaceSourceXCBWindow::window");

    bool SurfaceSourceXCBWindow::operator==(const SurfaceSourceXCBWindow& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (connection != rhs.connection) { return false; }
        if (window != rhs.window) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceSourceXlibWindow) == sizeof(WGPUSurfaceSourceXlibWindow), "sizeof mismatch for SurfaceSourceXlibWindow");
    static_assert(alignof(SurfaceSourceXlibWindow) == alignof(WGPUSurfaceSourceXlibWindow), "alignof mismatch for SurfaceSourceXlibWindow");

    static_assert(offsetof(SurfaceSourceXlibWindow, nextInChain) == offsetof(WGPUSurfaceSourceXlibWindow, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SurfaceSourceXlibWindow::nextInChain");
    static_assert(offsetof(SurfaceSourceXlibWindow, sType) == offsetof(WGPUSurfaceSourceXlibWindow, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SurfaceSourceXlibWindow::sType");
    static_assert(offsetof(SurfaceSourceXlibWindow, display) == offsetof(WGPUSurfaceSourceXlibWindow, display),
                 "offsetof mismatch for SurfaceSourceXlibWindow::display");
    static_assert(offsetof(SurfaceSourceXlibWindow, window) == offsetof(WGPUSurfaceSourceXlibWindow, window),
                 "offsetof mismatch for SurfaceSourceXlibWindow::window");

    bool SurfaceSourceXlibWindow::operator==(const SurfaceSourceXlibWindow& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (display != rhs.display) { return false; }
        if (window != rhs.window) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceTexture) == sizeof(WGPUSurfaceTexture), "sizeof mismatch for SurfaceTexture");
    static_assert(alignof(SurfaceTexture) == alignof(WGPUSurfaceTexture), "alignof mismatch for SurfaceTexture");

    static_assert(offsetof(SurfaceTexture, nextInChain) == offsetof(WGPUSurfaceTexture, nextInChain),
            "offsetof mismatch for SurfaceTexture::nextInChain");
    static_assert(offsetof(SurfaceTexture, texture) == offsetof(WGPUSurfaceTexture, texture),
                 "offsetof mismatch for SurfaceTexture::texture");
    static_assert(offsetof(SurfaceTexture, status) == offsetof(WGPUSurfaceTexture, status),
                 "offsetof mismatch for SurfaceTexture::status");

    bool SurfaceTexture::operator==(const SurfaceTexture& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (texture != rhs.texture) { return false; }
        if (status != rhs.status) { return false; }
        return true;
    }


    static_assert(sizeof(TexelBufferBindingEntry) == sizeof(WGPUTexelBufferBindingEntry), "sizeof mismatch for TexelBufferBindingEntry");
    static_assert(alignof(TexelBufferBindingEntry) == alignof(WGPUTexelBufferBindingEntry), "alignof mismatch for TexelBufferBindingEntry");

    static_assert(offsetof(TexelBufferBindingEntry, nextInChain) == offsetof(WGPUTexelBufferBindingEntry, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for TexelBufferBindingEntry::nextInChain");
    static_assert(offsetof(TexelBufferBindingEntry, sType) == offsetof(WGPUTexelBufferBindingEntry, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for TexelBufferBindingEntry::sType");
    static_assert(offsetof(TexelBufferBindingEntry, texelBufferView) == offsetof(WGPUTexelBufferBindingEntry, texelBufferView),
                 "offsetof mismatch for TexelBufferBindingEntry::texelBufferView");

    bool TexelBufferBindingEntry::operator==(const TexelBufferBindingEntry& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (texelBufferView != rhs.texelBufferView) { return false; }
        return true;
    }


    static_assert(sizeof(TexelBufferBindingLayout) == sizeof(WGPUTexelBufferBindingLayout), "sizeof mismatch for TexelBufferBindingLayout");
    static_assert(alignof(TexelBufferBindingLayout) == alignof(WGPUTexelBufferBindingLayout), "alignof mismatch for TexelBufferBindingLayout");

    static_assert(offsetof(TexelBufferBindingLayout, nextInChain) == offsetof(WGPUTexelBufferBindingLayout, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for TexelBufferBindingLayout::nextInChain");
    static_assert(offsetof(TexelBufferBindingLayout, sType) == offsetof(WGPUTexelBufferBindingLayout, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for TexelBufferBindingLayout::sType");
    static_assert(offsetof(TexelBufferBindingLayout, access) == offsetof(WGPUTexelBufferBindingLayout, access),
                 "offsetof mismatch for TexelBufferBindingLayout::access");
    static_assert(offsetof(TexelBufferBindingLayout, format) == offsetof(WGPUTexelBufferBindingLayout, format),
                 "offsetof mismatch for TexelBufferBindingLayout::format");

    TexelBufferBindingLayout TexelBufferBindingLayout::WithTrivialFrontendDefaults() const {
        TexelBufferBindingLayout copy;
        copy.nextInChain = nextInChain;
        copy.sType = sType;
        copy.access = (access == wgpu::TexelBufferAccess::Undefined)
            ? wgpu::TexelBufferAccess::ReadWrite
            : access;
        copy.format = format;
        return copy;
    }
    bool TexelBufferBindingLayout::operator==(const TexelBufferBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (access != rhs.access) { return false; }
        if (format != rhs.format) { return false; }
        return true;
    }


    static_assert(sizeof(TexelBufferViewDescriptor) == sizeof(WGPUTexelBufferViewDescriptor), "sizeof mismatch for TexelBufferViewDescriptor");
    static_assert(alignof(TexelBufferViewDescriptor) == alignof(WGPUTexelBufferViewDescriptor), "alignof mismatch for TexelBufferViewDescriptor");

    static_assert(offsetof(TexelBufferViewDescriptor, nextInChain) == offsetof(WGPUTexelBufferViewDescriptor, nextInChain),
            "offsetof mismatch for TexelBufferViewDescriptor::nextInChain");
    static_assert(offsetof(TexelBufferViewDescriptor, label) == offsetof(WGPUTexelBufferViewDescriptor, label),
                 "offsetof mismatch for TexelBufferViewDescriptor::label");
    static_assert(offsetof(TexelBufferViewDescriptor, format) == offsetof(WGPUTexelBufferViewDescriptor, format),
                 "offsetof mismatch for TexelBufferViewDescriptor::format");
    static_assert(offsetof(TexelBufferViewDescriptor, offset) == offsetof(WGPUTexelBufferViewDescriptor, offset),
                 "offsetof mismatch for TexelBufferViewDescriptor::offset");
    static_assert(offsetof(TexelBufferViewDescriptor, size) == offsetof(WGPUTexelBufferViewDescriptor, size),
                 "offsetof mismatch for TexelBufferViewDescriptor::size");

    bool TexelBufferViewDescriptor::operator==(const TexelBufferViewDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (format != rhs.format) { return false; }
        if (offset != rhs.offset) { return false; }
        if (size != rhs.size) { return false; }
        return true;
    }


    static_assert(sizeof(TexelCopyBufferLayout) == sizeof(WGPUTexelCopyBufferLayout), "sizeof mismatch for TexelCopyBufferLayout");
    static_assert(alignof(TexelCopyBufferLayout) == alignof(WGPUTexelCopyBufferLayout), "alignof mismatch for TexelCopyBufferLayout");

    static_assert(offsetof(TexelCopyBufferLayout, offset) == offsetof(WGPUTexelCopyBufferLayout, offset),
                 "offsetof mismatch for TexelCopyBufferLayout::offset");
    static_assert(offsetof(TexelCopyBufferLayout, bytesPerRow) == offsetof(WGPUTexelCopyBufferLayout, bytesPerRow),
                 "offsetof mismatch for TexelCopyBufferLayout::bytesPerRow");
    static_assert(offsetof(TexelCopyBufferLayout, rowsPerImage) == offsetof(WGPUTexelCopyBufferLayout, rowsPerImage),
                 "offsetof mismatch for TexelCopyBufferLayout::rowsPerImage");

    bool TexelCopyBufferLayout::operator==(const TexelCopyBufferLayout& rhs) const {
        if (offset != rhs.offset) { return false; }
        if (bytesPerRow != rhs.bytesPerRow) { return false; }
        if (rowsPerImage != rhs.rowsPerImage) { return false; }
        return true;
    }


    static_assert(sizeof(TextureBindingLayout) == sizeof(WGPUTextureBindingLayout), "sizeof mismatch for TextureBindingLayout");
    static_assert(alignof(TextureBindingLayout) == alignof(WGPUTextureBindingLayout), "alignof mismatch for TextureBindingLayout");

    static_assert(offsetof(TextureBindingLayout, nextInChain) == offsetof(WGPUTextureBindingLayout, nextInChain),
            "offsetof mismatch for TextureBindingLayout::nextInChain");
    static_assert(offsetof(TextureBindingLayout, sampleType) == offsetof(WGPUTextureBindingLayout, sampleType),
                 "offsetof mismatch for TextureBindingLayout::sampleType");
    static_assert(offsetof(TextureBindingLayout, viewDimension) == offsetof(WGPUTextureBindingLayout, viewDimension),
                 "offsetof mismatch for TextureBindingLayout::viewDimension");
    static_assert(offsetof(TextureBindingLayout, multisampled) == offsetof(WGPUTextureBindingLayout, multisampled),
                 "offsetof mismatch for TextureBindingLayout::multisampled");

    TextureBindingLayout TextureBindingLayout::WithTrivialFrontendDefaults() const {
        TextureBindingLayout copy;
        copy.nextInChain = nextInChain;
        copy.sampleType = (sampleType == wgpu::TextureSampleType::Undefined)
            ? wgpu::TextureSampleType::Float
            : sampleType;
        copy.viewDimension = (viewDimension == wgpu::TextureViewDimension::Undefined)
            ? wgpu::TextureViewDimension::e2D
            : viewDimension;
        copy.multisampled = multisampled;
        return copy;
    }
    bool TextureBindingLayout::operator==(const TextureBindingLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (sampleType != rhs.sampleType) { return false; }
        if (viewDimension != rhs.viewDimension) { return false; }
        if (multisampled != rhs.multisampled) { return false; }
        return true;
    }


    static_assert(sizeof(TextureBindingViewDimension) == sizeof(WGPUTextureBindingViewDimension), "sizeof mismatch for TextureBindingViewDimension");
    static_assert(alignof(TextureBindingViewDimension) == alignof(WGPUTextureBindingViewDimension), "alignof mismatch for TextureBindingViewDimension");

    static_assert(offsetof(TextureBindingViewDimension, nextInChain) == offsetof(WGPUTextureBindingViewDimension, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for TextureBindingViewDimension::nextInChain");
    static_assert(offsetof(TextureBindingViewDimension, sType) == offsetof(WGPUTextureBindingViewDimension, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for TextureBindingViewDimension::sType");
    static_assert(offsetof(TextureBindingViewDimension, textureBindingViewDimension) == offsetof(WGPUTextureBindingViewDimension, textureBindingViewDimension),
                 "offsetof mismatch for TextureBindingViewDimension::textureBindingViewDimension");

    bool TextureBindingViewDimension::operator==(const TextureBindingViewDimension& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (textureBindingViewDimension != rhs.textureBindingViewDimension) { return false; }
        return true;
    }


    static_assert(sizeof(TextureComponentSwizzle) == sizeof(WGPUTextureComponentSwizzle), "sizeof mismatch for TextureComponentSwizzle");
    static_assert(alignof(TextureComponentSwizzle) == alignof(WGPUTextureComponentSwizzle), "alignof mismatch for TextureComponentSwizzle");

    static_assert(offsetof(TextureComponentSwizzle, r) == offsetof(WGPUTextureComponentSwizzle, r),
                 "offsetof mismatch for TextureComponentSwizzle::r");
    static_assert(offsetof(TextureComponentSwizzle, g) == offsetof(WGPUTextureComponentSwizzle, g),
                 "offsetof mismatch for TextureComponentSwizzle::g");
    static_assert(offsetof(TextureComponentSwizzle, b) == offsetof(WGPUTextureComponentSwizzle, b),
                 "offsetof mismatch for TextureComponentSwizzle::b");
    static_assert(offsetof(TextureComponentSwizzle, a) == offsetof(WGPUTextureComponentSwizzle, a),
                 "offsetof mismatch for TextureComponentSwizzle::a");

    TextureComponentSwizzle TextureComponentSwizzle::WithTrivialFrontendDefaults() const {
        TextureComponentSwizzle copy;
        copy.r = (r == wgpu::ComponentSwizzle::Undefined)
            ? wgpu::ComponentSwizzle::R
            : r;
        copy.g = (g == wgpu::ComponentSwizzle::Undefined)
            ? wgpu::ComponentSwizzle::G
            : g;
        copy.b = (b == wgpu::ComponentSwizzle::Undefined)
            ? wgpu::ComponentSwizzle::B
            : b;
        copy.a = (a == wgpu::ComponentSwizzle::Undefined)
            ? wgpu::ComponentSwizzle::A
            : a;
        return copy;
    }
    bool TextureComponentSwizzle::operator==(const TextureComponentSwizzle& rhs) const {
        if (r != rhs.r) { return false; }
        if (g != rhs.g) { return false; }
        if (b != rhs.b) { return false; }
        if (a != rhs.a) { return false; }
        return true;
    }


    static_assert(sizeof(VertexAttribute) == sizeof(WGPUVertexAttribute), "sizeof mismatch for VertexAttribute");
    static_assert(alignof(VertexAttribute) == alignof(WGPUVertexAttribute), "alignof mismatch for VertexAttribute");

    static_assert(offsetof(VertexAttribute, nextInChain) == offsetof(WGPUVertexAttribute, nextInChain),
            "offsetof mismatch for VertexAttribute::nextInChain");
    static_assert(offsetof(VertexAttribute, format) == offsetof(WGPUVertexAttribute, format),
                 "offsetof mismatch for VertexAttribute::format");
    static_assert(offsetof(VertexAttribute, offset) == offsetof(WGPUVertexAttribute, offset),
                 "offsetof mismatch for VertexAttribute::offset");
    static_assert(offsetof(VertexAttribute, shaderLocation) == offsetof(WGPUVertexAttribute, shaderLocation),
                 "offsetof mismatch for VertexAttribute::shaderLocation");

    bool VertexAttribute::operator==(const VertexAttribute& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (format != rhs.format) { return false; }
        if (offset != rhs.offset) { return false; }
        if (shaderLocation != rhs.shaderLocation) { return false; }
        return true;
    }


    static_assert(sizeof(YCbCrVkDescriptor) == sizeof(WGPUYCbCrVkDescriptor), "sizeof mismatch for YCbCrVkDescriptor");
    static_assert(alignof(YCbCrVkDescriptor) == alignof(WGPUYCbCrVkDescriptor), "alignof mismatch for YCbCrVkDescriptor");

    static_assert(offsetof(YCbCrVkDescriptor, nextInChain) == offsetof(WGPUYCbCrVkDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for YCbCrVkDescriptor::nextInChain");
    static_assert(offsetof(YCbCrVkDescriptor, sType) == offsetof(WGPUYCbCrVkDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for YCbCrVkDescriptor::sType");
    static_assert(offsetof(YCbCrVkDescriptor, vkFormat) == offsetof(WGPUYCbCrVkDescriptor, vkFormat),
                 "offsetof mismatch for YCbCrVkDescriptor::vkFormat");
    static_assert(offsetof(YCbCrVkDescriptor, vkYCbCrModel) == offsetof(WGPUYCbCrVkDescriptor, vkYCbCrModel),
                 "offsetof mismatch for YCbCrVkDescriptor::vkYCbCrModel");
    static_assert(offsetof(YCbCrVkDescriptor, vkYCbCrRange) == offsetof(WGPUYCbCrVkDescriptor, vkYCbCrRange),
                 "offsetof mismatch for YCbCrVkDescriptor::vkYCbCrRange");
    static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleRed) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleRed),
                 "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleRed");
    static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleGreen) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleGreen),
                 "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleGreen");
    static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleBlue) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleBlue),
                 "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleBlue");
    static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleAlpha) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleAlpha),
                 "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleAlpha");
    static_assert(offsetof(YCbCrVkDescriptor, vkXChromaOffset) == offsetof(WGPUYCbCrVkDescriptor, vkXChromaOffset),
                 "offsetof mismatch for YCbCrVkDescriptor::vkXChromaOffset");
    static_assert(offsetof(YCbCrVkDescriptor, vkYChromaOffset) == offsetof(WGPUYCbCrVkDescriptor, vkYChromaOffset),
                 "offsetof mismatch for YCbCrVkDescriptor::vkYChromaOffset");
    static_assert(offsetof(YCbCrVkDescriptor, vkChromaFilter) == offsetof(WGPUYCbCrVkDescriptor, vkChromaFilter),
                 "offsetof mismatch for YCbCrVkDescriptor::vkChromaFilter");
    static_assert(offsetof(YCbCrVkDescriptor, forceExplicitReconstruction) == offsetof(WGPUYCbCrVkDescriptor, forceExplicitReconstruction),
                 "offsetof mismatch for YCbCrVkDescriptor::forceExplicitReconstruction");
    static_assert(offsetof(YCbCrVkDescriptor, externalFormat) == offsetof(WGPUYCbCrVkDescriptor, externalFormat),
                 "offsetof mismatch for YCbCrVkDescriptor::externalFormat");

    YCbCrVkDescriptor YCbCrVkDescriptor::WithTrivialFrontendDefaults() const {
        YCbCrVkDescriptor copy;
        copy.nextInChain = nextInChain;
        copy.sType = sType;
        copy.vkFormat = vkFormat;
        copy.vkYCbCrModel = vkYCbCrModel;
        copy.vkYCbCrRange = vkYCbCrRange;
        copy.vkComponentSwizzleRed = vkComponentSwizzleRed;
        copy.vkComponentSwizzleGreen = vkComponentSwizzleGreen;
        copy.vkComponentSwizzleBlue = vkComponentSwizzleBlue;
        copy.vkComponentSwizzleAlpha = vkComponentSwizzleAlpha;
        copy.vkXChromaOffset = vkXChromaOffset;
        copy.vkYChromaOffset = vkYChromaOffset;
        copy.vkChromaFilter = (vkChromaFilter == wgpu::FilterMode::Undefined)
            ? wgpu::FilterMode::Nearest
            : vkChromaFilter;
        copy.forceExplicitReconstruction = forceExplicitReconstruction;
        copy.externalFormat = externalFormat;
        return copy;
    }
    bool YCbCrVkDescriptor::operator==(const YCbCrVkDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (vkFormat != rhs.vkFormat) { return false; }
        if (vkYCbCrModel != rhs.vkYCbCrModel) { return false; }
        if (vkYCbCrRange != rhs.vkYCbCrRange) { return false; }
        if (vkComponentSwizzleRed != rhs.vkComponentSwizzleRed) { return false; }
        if (vkComponentSwizzleGreen != rhs.vkComponentSwizzleGreen) { return false; }
        if (vkComponentSwizzleBlue != rhs.vkComponentSwizzleBlue) { return false; }
        if (vkComponentSwizzleAlpha != rhs.vkComponentSwizzleAlpha) { return false; }
        if (vkXChromaOffset != rhs.vkXChromaOffset) { return false; }
        if (vkYChromaOffset != rhs.vkYChromaOffset) { return false; }
        if (vkChromaFilter != rhs.vkChromaFilter) { return false; }
        if (forceExplicitReconstruction != rhs.forceExplicitReconstruction) { return false; }
        if (externalFormat != rhs.externalFormat) { return false; }
        return true;
    }


    static_assert(sizeof(AdapterPropertiesMemoryHeaps) == sizeof(WGPUAdapterPropertiesMemoryHeaps), "sizeof mismatch for AdapterPropertiesMemoryHeaps");
    static_assert(alignof(AdapterPropertiesMemoryHeaps) == alignof(WGPUAdapterPropertiesMemoryHeaps), "alignof mismatch for AdapterPropertiesMemoryHeaps");

    static_assert(offsetof(AdapterPropertiesMemoryHeaps, nextInChain) == offsetof(WGPUAdapterPropertiesMemoryHeaps, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for AdapterPropertiesMemoryHeaps::nextInChain");
    static_assert(offsetof(AdapterPropertiesMemoryHeaps, sType) == offsetof(WGPUAdapterPropertiesMemoryHeaps, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for AdapterPropertiesMemoryHeaps::sType");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using AdapterPropertiesMemoryHeapsheapInfoSpan = decltype(std::declval<AdapterPropertiesMemoryHeaps>().heapInfo);
    
    static_assert(offsetof(AdapterPropertiesMemoryHeaps, heapInfo) + AdapterPropertiesMemoryHeapsheapInfoSpan::GetOffsetOfSize() == offsetof(WGPUAdapterPropertiesMemoryHeaps, heapCount),
                 "offsetof mismatch for AdapterPropertiesMemoryHeaps::heapInfo::mSize");
    static_assert(offsetof(AdapterPropertiesMemoryHeaps, heapInfo) + AdapterPropertiesMemoryHeapsheapInfoSpan::GetOffsetOfData() == offsetof(WGPUAdapterPropertiesMemoryHeaps, heapInfo),
                 "offsetof mismatch for AdapterPropertiesMemoryHeaps::heapInfo::mData");

    bool AdapterPropertiesMemoryHeaps::operator==(const AdapterPropertiesMemoryHeaps& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (heapInfo.size() != rhs.heapInfo.size()) { return false; }
        if (heapInfo.data() != rhs.heapInfo.data()) { return false; }
        return true;
    }


    static_assert(sizeof(AdapterPropertiesSubgroupMatrixConfigs) == sizeof(WGPUAdapterPropertiesSubgroupMatrixConfigs), "sizeof mismatch for AdapterPropertiesSubgroupMatrixConfigs");
    static_assert(alignof(AdapterPropertiesSubgroupMatrixConfigs) == alignof(WGPUAdapterPropertiesSubgroupMatrixConfigs), "alignof mismatch for AdapterPropertiesSubgroupMatrixConfigs");

    static_assert(offsetof(AdapterPropertiesSubgroupMatrixConfigs, nextInChain) == offsetof(WGPUAdapterPropertiesSubgroupMatrixConfigs, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for AdapterPropertiesSubgroupMatrixConfigs::nextInChain");
    static_assert(offsetof(AdapterPropertiesSubgroupMatrixConfigs, sType) == offsetof(WGPUAdapterPropertiesSubgroupMatrixConfigs, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for AdapterPropertiesSubgroupMatrixConfigs::sType");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using AdapterPropertiesSubgroupMatrixConfigsconfigsSpan = decltype(std::declval<AdapterPropertiesSubgroupMatrixConfigs>().configs);
    
    static_assert(offsetof(AdapterPropertiesSubgroupMatrixConfigs, configs) + AdapterPropertiesSubgroupMatrixConfigsconfigsSpan::GetOffsetOfSize() == offsetof(WGPUAdapterPropertiesSubgroupMatrixConfigs, configCount),
                 "offsetof mismatch for AdapterPropertiesSubgroupMatrixConfigs::configs::mSize");
    static_assert(offsetof(AdapterPropertiesSubgroupMatrixConfigs, configs) + AdapterPropertiesSubgroupMatrixConfigsconfigsSpan::GetOffsetOfData() == offsetof(WGPUAdapterPropertiesSubgroupMatrixConfigs, configs),
                 "offsetof mismatch for AdapterPropertiesSubgroupMatrixConfigs::configs::mData");

    bool AdapterPropertiesSubgroupMatrixConfigs::operator==(const AdapterPropertiesSubgroupMatrixConfigs& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (configs.size() != rhs.configs.size()) { return false; }
        if (configs.data() != rhs.configs.data()) { return false; }
        return true;
    }


    static_assert(sizeof(AHardwareBufferProperties) == sizeof(WGPUAHardwareBufferProperties), "sizeof mismatch for AHardwareBufferProperties");
    static_assert(alignof(AHardwareBufferProperties) == alignof(WGPUAHardwareBufferProperties), "alignof mismatch for AHardwareBufferProperties");

    static_assert(offsetof(AHardwareBufferProperties, yCbCrInfo) == offsetof(WGPUAHardwareBufferProperties, yCbCrInfo),
                 "offsetof mismatch for AHardwareBufferProperties::yCbCrInfo");

    AHardwareBufferProperties AHardwareBufferProperties::WithTrivialFrontendDefaults() const {
        AHardwareBufferProperties copy;
        copy.yCbCrInfo = yCbCrInfo.WithTrivialFrontendDefaults();
        return copy;
    }
    bool AHardwareBufferProperties::operator==(const AHardwareBufferProperties& rhs) const {
        if (yCbCrInfo != rhs.yCbCrInfo) { return false; }
        return true;
    }


    static_assert(sizeof(BindGroupEntry) == sizeof(WGPUBindGroupEntry), "sizeof mismatch for BindGroupEntry");
    static_assert(alignof(BindGroupEntry) == alignof(WGPUBindGroupEntry), "alignof mismatch for BindGroupEntry");

    static_assert(offsetof(BindGroupEntry, nextInChain) == offsetof(WGPUBindGroupEntry, nextInChain),
            "offsetof mismatch for BindGroupEntry::nextInChain");
    static_assert(offsetof(BindGroupEntry, binding) == offsetof(WGPUBindGroupEntry, binding),
                 "offsetof mismatch for BindGroupEntry::binding");
    static_assert(offsetof(BindGroupEntry, buffer) == offsetof(WGPUBindGroupEntry, buffer),
                 "offsetof mismatch for BindGroupEntry::buffer");
    static_assert(offsetof(BindGroupEntry, offset) == offsetof(WGPUBindGroupEntry, offset),
                 "offsetof mismatch for BindGroupEntry::offset");
    static_assert(offsetof(BindGroupEntry, size) == offsetof(WGPUBindGroupEntry, size),
                 "offsetof mismatch for BindGroupEntry::size");
    static_assert(offsetof(BindGroupEntry, sampler) == offsetof(WGPUBindGroupEntry, sampler),
                 "offsetof mismatch for BindGroupEntry::sampler");
    static_assert(offsetof(BindGroupEntry, textureView) == offsetof(WGPUBindGroupEntry, textureView),
                 "offsetof mismatch for BindGroupEntry::textureView");

    bool BindGroupEntry::operator==(const BindGroupEntry& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (binding != rhs.binding) { return false; }
        if (buffer != rhs.buffer) { return false; }
        if (offset != rhs.offset) { return false; }
        if (size != rhs.size) { return false; }
        if (sampler != rhs.sampler) { return false; }
        if (textureView != rhs.textureView) { return false; }
        return true;
    }


    static_assert(sizeof(BindGroupLayoutEntry) == sizeof(WGPUBindGroupLayoutEntry), "sizeof mismatch for BindGroupLayoutEntry");
    static_assert(alignof(BindGroupLayoutEntry) == alignof(WGPUBindGroupLayoutEntry), "alignof mismatch for BindGroupLayoutEntry");

    static_assert(offsetof(BindGroupLayoutEntry, nextInChain) == offsetof(WGPUBindGroupLayoutEntry, nextInChain),
            "offsetof mismatch for BindGroupLayoutEntry::nextInChain");
    static_assert(offsetof(BindGroupLayoutEntry, binding) == offsetof(WGPUBindGroupLayoutEntry, binding),
                 "offsetof mismatch for BindGroupLayoutEntry::binding");
    static_assert(offsetof(BindGroupLayoutEntry, visibility) == offsetof(WGPUBindGroupLayoutEntry, visibility),
                 "offsetof mismatch for BindGroupLayoutEntry::visibility");
    static_assert(offsetof(BindGroupLayoutEntry, bindingArraySize) == offsetof(WGPUBindGroupLayoutEntry, bindingArraySize),
                 "offsetof mismatch for BindGroupLayoutEntry::bindingArraySize");
    static_assert(offsetof(BindGroupLayoutEntry, buffer) == offsetof(WGPUBindGroupLayoutEntry, buffer),
                 "offsetof mismatch for BindGroupLayoutEntry::buffer");
    static_assert(offsetof(BindGroupLayoutEntry, sampler) == offsetof(WGPUBindGroupLayoutEntry, sampler),
                 "offsetof mismatch for BindGroupLayoutEntry::sampler");
    static_assert(offsetof(BindGroupLayoutEntry, texture) == offsetof(WGPUBindGroupLayoutEntry, texture),
                 "offsetof mismatch for BindGroupLayoutEntry::texture");
    static_assert(offsetof(BindGroupLayoutEntry, storageTexture) == offsetof(WGPUBindGroupLayoutEntry, storageTexture),
                 "offsetof mismatch for BindGroupLayoutEntry::storageTexture");

    BindGroupLayoutEntry BindGroupLayoutEntry::WithTrivialFrontendDefaults() const {
        BindGroupLayoutEntry copy;
        copy.nextInChain = nextInChain;
        copy.binding = binding;
        copy.visibility = visibility;
        copy.bindingArraySize = bindingArraySize;
        copy.buffer = buffer.WithTrivialFrontendDefaults();
        copy.sampler = sampler.WithTrivialFrontendDefaults();
        copy.texture = texture.WithTrivialFrontendDefaults();
        copy.storageTexture = storageTexture.WithTrivialFrontendDefaults();
        return copy;
    }
    bool BindGroupLayoutEntry::operator==(const BindGroupLayoutEntry& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (binding != rhs.binding) { return false; }
        if (visibility != rhs.visibility) { return false; }
        if (bindingArraySize != rhs.bindingArraySize) { return false; }
        if (buffer != rhs.buffer) { return false; }
        if (sampler != rhs.sampler) { return false; }
        if (texture != rhs.texture) { return false; }
        if (storageTexture != rhs.storageTexture) { return false; }
        return true;
    }


    static_assert(sizeof(BlendState) == sizeof(WGPUBlendState), "sizeof mismatch for BlendState");
    static_assert(alignof(BlendState) == alignof(WGPUBlendState), "alignof mismatch for BlendState");

    static_assert(offsetof(BlendState, color) == offsetof(WGPUBlendState, color),
                 "offsetof mismatch for BlendState::color");
    static_assert(offsetof(BlendState, alpha) == offsetof(WGPUBlendState, alpha),
                 "offsetof mismatch for BlendState::alpha");

    BlendState BlendState::WithTrivialFrontendDefaults() const {
        BlendState copy;
        copy.color = color.WithTrivialFrontendDefaults();
        copy.alpha = alpha.WithTrivialFrontendDefaults();
        return copy;
    }
    bool BlendState::operator==(const BlendState& rhs) const {
        if (color != rhs.color) { return false; }
        if (alpha != rhs.alpha) { return false; }
        return true;
    }


    static_assert(sizeof(BufferDescriptor) == sizeof(WGPUBufferDescriptor), "sizeof mismatch for BufferDescriptor");
    static_assert(alignof(BufferDescriptor) == alignof(WGPUBufferDescriptor), "alignof mismatch for BufferDescriptor");

    static_assert(offsetof(BufferDescriptor, nextInChain) == offsetof(WGPUBufferDescriptor, nextInChain),
            "offsetof mismatch for BufferDescriptor::nextInChain");
    static_assert(offsetof(BufferDescriptor, label) == offsetof(WGPUBufferDescriptor, label),
                 "offsetof mismatch for BufferDescriptor::label");
    static_assert(offsetof(BufferDescriptor, usage) == offsetof(WGPUBufferDescriptor, usage),
                 "offsetof mismatch for BufferDescriptor::usage");
    static_assert(offsetof(BufferDescriptor, size) == offsetof(WGPUBufferDescriptor, size),
                 "offsetof mismatch for BufferDescriptor::size");
    static_assert(offsetof(BufferDescriptor, mappedAtCreation) == offsetof(WGPUBufferDescriptor, mappedAtCreation),
                 "offsetof mismatch for BufferDescriptor::mappedAtCreation");

    bool BufferDescriptor::operator==(const BufferDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (usage != rhs.usage) { return false; }
        if (size != rhs.size) { return false; }
        if (mappedAtCreation != rhs.mappedAtCreation) { return false; }
        return true;
    }


    static_assert(sizeof(CommandEncoderDescriptor) == sizeof(WGPUCommandEncoderDescriptor), "sizeof mismatch for CommandEncoderDescriptor");
    static_assert(alignof(CommandEncoderDescriptor) == alignof(WGPUCommandEncoderDescriptor), "alignof mismatch for CommandEncoderDescriptor");

    static_assert(offsetof(CommandEncoderDescriptor, nextInChain) == offsetof(WGPUCommandEncoderDescriptor, nextInChain),
            "offsetof mismatch for CommandEncoderDescriptor::nextInChain");
    static_assert(offsetof(CommandEncoderDescriptor, label) == offsetof(WGPUCommandEncoderDescriptor, label),
                 "offsetof mismatch for CommandEncoderDescriptor::label");

    bool CommandEncoderDescriptor::operator==(const CommandEncoderDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(CompilationMessage) == sizeof(WGPUCompilationMessage), "sizeof mismatch for CompilationMessage");
    static_assert(alignof(CompilationMessage) == alignof(WGPUCompilationMessage), "alignof mismatch for CompilationMessage");

    static_assert(offsetof(CompilationMessage, nextInChain) == offsetof(WGPUCompilationMessage, nextInChain),
            "offsetof mismatch for CompilationMessage::nextInChain");
    static_assert(offsetof(CompilationMessage, message) == offsetof(WGPUCompilationMessage, message),
                 "offsetof mismatch for CompilationMessage::message");
    static_assert(offsetof(CompilationMessage, type) == offsetof(WGPUCompilationMessage, type),
                 "offsetof mismatch for CompilationMessage::type");
    static_assert(offsetof(CompilationMessage, lineNum) == offsetof(WGPUCompilationMessage, lineNum),
                 "offsetof mismatch for CompilationMessage::lineNum");
    static_assert(offsetof(CompilationMessage, linePos) == offsetof(WGPUCompilationMessage, linePos),
                 "offsetof mismatch for CompilationMessage::linePos");
    static_assert(offsetof(CompilationMessage, offset) == offsetof(WGPUCompilationMessage, offset),
                 "offsetof mismatch for CompilationMessage::offset");
    static_assert(offsetof(CompilationMessage, length) == offsetof(WGPUCompilationMessage, length),
                 "offsetof mismatch for CompilationMessage::length");

    bool CompilationMessage::operator==(const CompilationMessage& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (message != rhs.message) { return false; }
        if (type != rhs.type) { return false; }
        if (lineNum != rhs.lineNum) { return false; }
        if (linePos != rhs.linePos) { return false; }
        if (offset != rhs.offset) { return false; }
        if (length != rhs.length) { return false; }
        return true;
    }


    static_assert(sizeof(ComputePassDescriptor) == sizeof(WGPUComputePassDescriptor), "sizeof mismatch for ComputePassDescriptor");
    static_assert(alignof(ComputePassDescriptor) == alignof(WGPUComputePassDescriptor), "alignof mismatch for ComputePassDescriptor");

    static_assert(offsetof(ComputePassDescriptor, nextInChain) == offsetof(WGPUComputePassDescriptor, nextInChain),
            "offsetof mismatch for ComputePassDescriptor::nextInChain");
    static_assert(offsetof(ComputePassDescriptor, label) == offsetof(WGPUComputePassDescriptor, label),
                 "offsetof mismatch for ComputePassDescriptor::label");
    static_assert(offsetof(ComputePassDescriptor, timestampWrites) == offsetof(WGPUComputePassDescriptor, timestampWrites),
                 "offsetof mismatch for ComputePassDescriptor::timestampWrites");

    bool ComputePassDescriptor::operator==(const ComputePassDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (timestampWrites != rhs.timestampWrites) { return false; }
        return true;
    }


    static_assert(sizeof(ComputeState) == sizeof(WGPUComputeState), "sizeof mismatch for ComputeState");
    static_assert(alignof(ComputeState) == alignof(WGPUComputeState), "alignof mismatch for ComputeState");

    static_assert(offsetof(ComputeState, nextInChain) == offsetof(WGPUComputeState, nextInChain),
            "offsetof mismatch for ComputeState::nextInChain");
    static_assert(offsetof(ComputeState, module) == offsetof(WGPUComputeState, module),
                 "offsetof mismatch for ComputeState::module");
    static_assert(offsetof(ComputeState, entryPoint) == offsetof(WGPUComputeState, entryPoint),
                 "offsetof mismatch for ComputeState::entryPoint");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using ComputeStateconstantsSpan = decltype(std::declval<ComputeState>().constants);
    
    static_assert(offsetof(ComputeState, constants) + ComputeStateconstantsSpan::GetOffsetOfSize() == offsetof(WGPUComputeState, constantCount),
                 "offsetof mismatch for ComputeState::constants::mSize");
    static_assert(offsetof(ComputeState, constants) + ComputeStateconstantsSpan::GetOffsetOfData() == offsetof(WGPUComputeState, constants),
                 "offsetof mismatch for ComputeState::constants::mData");

    bool ComputeState::operator==(const ComputeState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (module != rhs.module) { return false; }
        if (entryPoint != rhs.entryPoint) { return false; }
        if (constants.size() != rhs.constants.size()) { return false; }
        if (constants.data() != rhs.constants.data()) { return false; }
        return true;
    }


    static_assert(sizeof(DawnDrmFormatCapabilities) == sizeof(WGPUDawnDrmFormatCapabilities), "sizeof mismatch for DawnDrmFormatCapabilities");
    static_assert(alignof(DawnDrmFormatCapabilities) == alignof(WGPUDawnDrmFormatCapabilities), "alignof mismatch for DawnDrmFormatCapabilities");

    static_assert(offsetof(DawnDrmFormatCapabilities, nextInChain) == offsetof(WGPUDawnDrmFormatCapabilities, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for DawnDrmFormatCapabilities::nextInChain");
    static_assert(offsetof(DawnDrmFormatCapabilities, sType) == offsetof(WGPUDawnDrmFormatCapabilities, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for DawnDrmFormatCapabilities::sType");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using DawnDrmFormatCapabilitiespropertiesSpan = decltype(std::declval<DawnDrmFormatCapabilities>().properties);
    
    static_assert(offsetof(DawnDrmFormatCapabilities, properties) + DawnDrmFormatCapabilitiespropertiesSpan::GetOffsetOfSize() == offsetof(WGPUDawnDrmFormatCapabilities, propertiesCount),
                 "offsetof mismatch for DawnDrmFormatCapabilities::properties::mSize");
    static_assert(offsetof(DawnDrmFormatCapabilities, properties) + DawnDrmFormatCapabilitiespropertiesSpan::GetOffsetOfData() == offsetof(WGPUDawnDrmFormatCapabilities, properties),
                 "offsetof mismatch for DawnDrmFormatCapabilities::properties::mData");

    bool DawnDrmFormatCapabilities::operator==(const DawnDrmFormatCapabilities& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (properties.size() != rhs.properties.size()) { return false; }
        if (properties.data() != rhs.properties.data()) { return false; }
        return true;
    }


    static_assert(sizeof(DepthStencilState) == sizeof(WGPUDepthStencilState), "sizeof mismatch for DepthStencilState");
    static_assert(alignof(DepthStencilState) == alignof(WGPUDepthStencilState), "alignof mismatch for DepthStencilState");

    static_assert(offsetof(DepthStencilState, nextInChain) == offsetof(WGPUDepthStencilState, nextInChain),
            "offsetof mismatch for DepthStencilState::nextInChain");
    static_assert(offsetof(DepthStencilState, format) == offsetof(WGPUDepthStencilState, format),
                 "offsetof mismatch for DepthStencilState::format");
    static_assert(offsetof(DepthStencilState, depthWriteEnabled) == offsetof(WGPUDepthStencilState, depthWriteEnabled),
                 "offsetof mismatch for DepthStencilState::depthWriteEnabled");
    static_assert(offsetof(DepthStencilState, depthCompare) == offsetof(WGPUDepthStencilState, depthCompare),
                 "offsetof mismatch for DepthStencilState::depthCompare");
    static_assert(offsetof(DepthStencilState, stencilFront) == offsetof(WGPUDepthStencilState, stencilFront),
                 "offsetof mismatch for DepthStencilState::stencilFront");
    static_assert(offsetof(DepthStencilState, stencilBack) == offsetof(WGPUDepthStencilState, stencilBack),
                 "offsetof mismatch for DepthStencilState::stencilBack");
    static_assert(offsetof(DepthStencilState, stencilReadMask) == offsetof(WGPUDepthStencilState, stencilReadMask),
                 "offsetof mismatch for DepthStencilState::stencilReadMask");
    static_assert(offsetof(DepthStencilState, stencilWriteMask) == offsetof(WGPUDepthStencilState, stencilWriteMask),
                 "offsetof mismatch for DepthStencilState::stencilWriteMask");
    static_assert(offsetof(DepthStencilState, depthBias) == offsetof(WGPUDepthStencilState, depthBias),
                 "offsetof mismatch for DepthStencilState::depthBias");
    static_assert(offsetof(DepthStencilState, depthBiasSlopeScale) == offsetof(WGPUDepthStencilState, depthBiasSlopeScale),
                 "offsetof mismatch for DepthStencilState::depthBiasSlopeScale");
    static_assert(offsetof(DepthStencilState, depthBiasClamp) == offsetof(WGPUDepthStencilState, depthBiasClamp),
                 "offsetof mismatch for DepthStencilState::depthBiasClamp");

    DepthStencilState DepthStencilState::WithTrivialFrontendDefaults() const {
        DepthStencilState copy;
        copy.nextInChain = nextInChain;
        copy.format = format;
        copy.depthWriteEnabled = depthWriteEnabled;
        copy.depthCompare = depthCompare;
        copy.stencilFront = stencilFront.WithTrivialFrontendDefaults();
        copy.stencilBack = stencilBack.WithTrivialFrontendDefaults();
        copy.stencilReadMask = stencilReadMask;
        copy.stencilWriteMask = stencilWriteMask;
        copy.depthBias = depthBias;
        copy.depthBiasSlopeScale = depthBiasSlopeScale;
        copy.depthBiasClamp = depthBiasClamp;
        return copy;
    }
    bool DepthStencilState::operator==(const DepthStencilState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (format != rhs.format) { return false; }
        if (depthWriteEnabled != rhs.depthWriteEnabled) { return false; }
        if (depthCompare != rhs.depthCompare) { return false; }
        if (stencilFront != rhs.stencilFront) { return false; }
        if (stencilBack != rhs.stencilBack) { return false; }
        if (stencilReadMask != rhs.stencilReadMask) { return false; }
        if (stencilWriteMask != rhs.stencilWriteMask) { return false; }
        if (depthBias != rhs.depthBias) { return false; }
        if (depthBiasSlopeScale != rhs.depthBiasSlopeScale) { return false; }
        if (depthBiasClamp != rhs.depthBiasClamp) { return false; }
        return true;
    }


    static_assert(sizeof(ExternalTextureDescriptor) == sizeof(WGPUExternalTextureDescriptor), "sizeof mismatch for ExternalTextureDescriptor");
    static_assert(alignof(ExternalTextureDescriptor) == alignof(WGPUExternalTextureDescriptor), "alignof mismatch for ExternalTextureDescriptor");

    static_assert(offsetof(ExternalTextureDescriptor, nextInChain) == offsetof(WGPUExternalTextureDescriptor, nextInChain),
            "offsetof mismatch for ExternalTextureDescriptor::nextInChain");
    static_assert(offsetof(ExternalTextureDescriptor, label) == offsetof(WGPUExternalTextureDescriptor, label),
                 "offsetof mismatch for ExternalTextureDescriptor::label");
    static_assert(offsetof(ExternalTextureDescriptor, plane0) == offsetof(WGPUExternalTextureDescriptor, plane0),
                 "offsetof mismatch for ExternalTextureDescriptor::plane0");
    static_assert(offsetof(ExternalTextureDescriptor, plane1) == offsetof(WGPUExternalTextureDescriptor, plane1),
                 "offsetof mismatch for ExternalTextureDescriptor::plane1");
    static_assert(offsetof(ExternalTextureDescriptor, cropOrigin) == offsetof(WGPUExternalTextureDescriptor, cropOrigin),
                 "offsetof mismatch for ExternalTextureDescriptor::cropOrigin");
    static_assert(offsetof(ExternalTextureDescriptor, cropSize) == offsetof(WGPUExternalTextureDescriptor, cropSize),
                 "offsetof mismatch for ExternalTextureDescriptor::cropSize");
    static_assert(offsetof(ExternalTextureDescriptor, apparentSize) == offsetof(WGPUExternalTextureDescriptor, apparentSize),
                 "offsetof mismatch for ExternalTextureDescriptor::apparentSize");
    static_assert(offsetof(ExternalTextureDescriptor, doYuvToRgbConversionOnly) == offsetof(WGPUExternalTextureDescriptor, doYuvToRgbConversionOnly),
                 "offsetof mismatch for ExternalTextureDescriptor::doYuvToRgbConversionOnly");
    static_assert(offsetof(ExternalTextureDescriptor, yuvToRgbConversionMatrix) == offsetof(WGPUExternalTextureDescriptor, yuvToRgbConversionMatrix),
                 "offsetof mismatch for ExternalTextureDescriptor::yuvToRgbConversionMatrix");
    static_assert(offsetof(ExternalTextureDescriptor, srcTransferFunctionParameters) == offsetof(WGPUExternalTextureDescriptor, srcTransferFunctionParameters),
                 "offsetof mismatch for ExternalTextureDescriptor::srcTransferFunctionParameters");
    static_assert(offsetof(ExternalTextureDescriptor, dstTransferFunctionParameters) == offsetof(WGPUExternalTextureDescriptor, dstTransferFunctionParameters),
                 "offsetof mismatch for ExternalTextureDescriptor::dstTransferFunctionParameters");
    static_assert(offsetof(ExternalTextureDescriptor, gamutConversionMatrix) == offsetof(WGPUExternalTextureDescriptor, gamutConversionMatrix),
                 "offsetof mismatch for ExternalTextureDescriptor::gamutConversionMatrix");
    static_assert(offsetof(ExternalTextureDescriptor, mirrored) == offsetof(WGPUExternalTextureDescriptor, mirrored),
                 "offsetof mismatch for ExternalTextureDescriptor::mirrored");
    static_assert(offsetof(ExternalTextureDescriptor, rotation) == offsetof(WGPUExternalTextureDescriptor, rotation),
                 "offsetof mismatch for ExternalTextureDescriptor::rotation");

    bool ExternalTextureDescriptor::operator==(const ExternalTextureDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (plane0 != rhs.plane0) { return false; }
        if (plane1 != rhs.plane1) { return false; }
        if (cropOrigin != rhs.cropOrigin) { return false; }
        if (cropSize != rhs.cropSize) { return false; }
        if (apparentSize != rhs.apparentSize) { return false; }
        if (doYuvToRgbConversionOnly != rhs.doYuvToRgbConversionOnly) { return false; }
        if (yuvToRgbConversionMatrix != rhs.yuvToRgbConversionMatrix) { return false; }
        if (srcTransferFunctionParameters != rhs.srcTransferFunctionParameters) { return false; }
        if (dstTransferFunctionParameters != rhs.dstTransferFunctionParameters) { return false; }
        if (gamutConversionMatrix != rhs.gamutConversionMatrix) { return false; }
        if (mirrored != rhs.mirrored) { return false; }
        if (rotation != rhs.rotation) { return false; }
        return true;
    }


    static_assert(sizeof(FutureWaitInfo) == sizeof(WGPUFutureWaitInfo), "sizeof mismatch for FutureWaitInfo");
    static_assert(alignof(FutureWaitInfo) == alignof(WGPUFutureWaitInfo), "alignof mismatch for FutureWaitInfo");

    static_assert(offsetof(FutureWaitInfo, future) == offsetof(WGPUFutureWaitInfo, future),
                 "offsetof mismatch for FutureWaitInfo::future");
    static_assert(offsetof(FutureWaitInfo, completed) == offsetof(WGPUFutureWaitInfo, completed),
                 "offsetof mismatch for FutureWaitInfo::completed");

    bool FutureWaitInfo::operator==(const FutureWaitInfo& rhs) const {
        if (future != rhs.future) { return false; }
        if (completed != rhs.completed) { return false; }
        return true;
    }


    static_assert(sizeof(ImageCopyExternalTexture) == sizeof(WGPUImageCopyExternalTexture), "sizeof mismatch for ImageCopyExternalTexture");
    static_assert(alignof(ImageCopyExternalTexture) == alignof(WGPUImageCopyExternalTexture), "alignof mismatch for ImageCopyExternalTexture");

    static_assert(offsetof(ImageCopyExternalTexture, nextInChain) == offsetof(WGPUImageCopyExternalTexture, nextInChain),
            "offsetof mismatch for ImageCopyExternalTexture::nextInChain");
    static_assert(offsetof(ImageCopyExternalTexture, externalTexture) == offsetof(WGPUImageCopyExternalTexture, externalTexture),
                 "offsetof mismatch for ImageCopyExternalTexture::externalTexture");
    static_assert(offsetof(ImageCopyExternalTexture, origin) == offsetof(WGPUImageCopyExternalTexture, origin),
                 "offsetof mismatch for ImageCopyExternalTexture::origin");
    static_assert(offsetof(ImageCopyExternalTexture, naturalSize) == offsetof(WGPUImageCopyExternalTexture, naturalSize),
                 "offsetof mismatch for ImageCopyExternalTexture::naturalSize");

    bool ImageCopyExternalTexture::operator==(const ImageCopyExternalTexture& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (externalTexture != rhs.externalTexture) { return false; }
        if (origin != rhs.origin) { return false; }
        if (naturalSize != rhs.naturalSize) { return false; }
        return true;
    }


    static_assert(sizeof(InstanceDescriptor) == sizeof(WGPUInstanceDescriptor), "sizeof mismatch for InstanceDescriptor");
    static_assert(alignof(InstanceDescriptor) == alignof(WGPUInstanceDescriptor), "alignof mismatch for InstanceDescriptor");

    static_assert(offsetof(InstanceDescriptor, nextInChain) == offsetof(WGPUInstanceDescriptor, nextInChain),
            "offsetof mismatch for InstanceDescriptor::nextInChain");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using InstanceDescriptorrequiredFeaturesSpan = decltype(std::declval<InstanceDescriptor>().requiredFeatures);
    
    static_assert(offsetof(InstanceDescriptor, requiredFeatures) + InstanceDescriptorrequiredFeaturesSpan::GetOffsetOfSize() == offsetof(WGPUInstanceDescriptor, requiredFeatureCount),
                 "offsetof mismatch for InstanceDescriptor::requiredFeatures::mSize");
    static_assert(offsetof(InstanceDescriptor, requiredFeatures) + InstanceDescriptorrequiredFeaturesSpan::GetOffsetOfData() == offsetof(WGPUInstanceDescriptor, requiredFeatures),
                 "offsetof mismatch for InstanceDescriptor::requiredFeatures::mData");
    static_assert(offsetof(InstanceDescriptor, requiredLimits) == offsetof(WGPUInstanceDescriptor, requiredLimits),
                 "offsetof mismatch for InstanceDescriptor::requiredLimits");

    bool InstanceDescriptor::operator==(const InstanceDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (requiredFeatures.size() != rhs.requiredFeatures.size()) { return false; }
        if (requiredFeatures.data() != rhs.requiredFeatures.data()) { return false; }
        if (requiredLimits != rhs.requiredLimits) { return false; }
        return true;
    }


    static_assert(sizeof(Limits) == sizeof(WGPULimits), "sizeof mismatch for Limits");
    static_assert(alignof(Limits) == alignof(WGPULimits), "alignof mismatch for Limits");

    static_assert(offsetof(Limits, nextInChain) == offsetof(WGPULimits, nextInChain),
            "offsetof mismatch for Limits::nextInChain");
    static_assert(offsetof(Limits, maxTextureDimension1D) == offsetof(WGPULimits, maxTextureDimension1D),
                 "offsetof mismatch for Limits::maxTextureDimension1D");
    static_assert(offsetof(Limits, maxTextureDimension2D) == offsetof(WGPULimits, maxTextureDimension2D),
                 "offsetof mismatch for Limits::maxTextureDimension2D");
    static_assert(offsetof(Limits, maxTextureDimension3D) == offsetof(WGPULimits, maxTextureDimension3D),
                 "offsetof mismatch for Limits::maxTextureDimension3D");
    static_assert(offsetof(Limits, maxTextureArrayLayers) == offsetof(WGPULimits, maxTextureArrayLayers),
                 "offsetof mismatch for Limits::maxTextureArrayLayers");
    static_assert(offsetof(Limits, maxBindGroups) == offsetof(WGPULimits, maxBindGroups),
                 "offsetof mismatch for Limits::maxBindGroups");
    static_assert(offsetof(Limits, maxBindGroupsPlusVertexBuffers) == offsetof(WGPULimits, maxBindGroupsPlusVertexBuffers),
                 "offsetof mismatch for Limits::maxBindGroupsPlusVertexBuffers");
    static_assert(offsetof(Limits, maxBindingsPerBindGroup) == offsetof(WGPULimits, maxBindingsPerBindGroup),
                 "offsetof mismatch for Limits::maxBindingsPerBindGroup");
    static_assert(offsetof(Limits, maxDynamicUniformBuffersPerPipelineLayout) == offsetof(WGPULimits, maxDynamicUniformBuffersPerPipelineLayout),
                 "offsetof mismatch for Limits::maxDynamicUniformBuffersPerPipelineLayout");
    static_assert(offsetof(Limits, maxDynamicStorageBuffersPerPipelineLayout) == offsetof(WGPULimits, maxDynamicStorageBuffersPerPipelineLayout),
                 "offsetof mismatch for Limits::maxDynamicStorageBuffersPerPipelineLayout");
    static_assert(offsetof(Limits, maxSampledTexturesPerShaderStage) == offsetof(WGPULimits, maxSampledTexturesPerShaderStage),
                 "offsetof mismatch for Limits::maxSampledTexturesPerShaderStage");
    static_assert(offsetof(Limits, maxSamplersPerShaderStage) == offsetof(WGPULimits, maxSamplersPerShaderStage),
                 "offsetof mismatch for Limits::maxSamplersPerShaderStage");
    static_assert(offsetof(Limits, maxStorageBuffersPerShaderStage) == offsetof(WGPULimits, maxStorageBuffersPerShaderStage),
                 "offsetof mismatch for Limits::maxStorageBuffersPerShaderStage");
    static_assert(offsetof(Limits, maxStorageTexturesPerShaderStage) == offsetof(WGPULimits, maxStorageTexturesPerShaderStage),
                 "offsetof mismatch for Limits::maxStorageTexturesPerShaderStage");
    static_assert(offsetof(Limits, maxUniformBuffersPerShaderStage) == offsetof(WGPULimits, maxUniformBuffersPerShaderStage),
                 "offsetof mismatch for Limits::maxUniformBuffersPerShaderStage");
    static_assert(offsetof(Limits, maxUniformBufferBindingSize) == offsetof(WGPULimits, maxUniformBufferBindingSize),
                 "offsetof mismatch for Limits::maxUniformBufferBindingSize");
    static_assert(offsetof(Limits, maxStorageBufferBindingSize) == offsetof(WGPULimits, maxStorageBufferBindingSize),
                 "offsetof mismatch for Limits::maxStorageBufferBindingSize");
    static_assert(offsetof(Limits, minUniformBufferOffsetAlignment) == offsetof(WGPULimits, minUniformBufferOffsetAlignment),
                 "offsetof mismatch for Limits::minUniformBufferOffsetAlignment");
    static_assert(offsetof(Limits, minStorageBufferOffsetAlignment) == offsetof(WGPULimits, minStorageBufferOffsetAlignment),
                 "offsetof mismatch for Limits::minStorageBufferOffsetAlignment");
    static_assert(offsetof(Limits, maxVertexBuffers) == offsetof(WGPULimits, maxVertexBuffers),
                 "offsetof mismatch for Limits::maxVertexBuffers");
    static_assert(offsetof(Limits, maxBufferSize) == offsetof(WGPULimits, maxBufferSize),
                 "offsetof mismatch for Limits::maxBufferSize");
    static_assert(offsetof(Limits, maxVertexAttributes) == offsetof(WGPULimits, maxVertexAttributes),
                 "offsetof mismatch for Limits::maxVertexAttributes");
    static_assert(offsetof(Limits, maxVertexBufferArrayStride) == offsetof(WGPULimits, maxVertexBufferArrayStride),
                 "offsetof mismatch for Limits::maxVertexBufferArrayStride");
    static_assert(offsetof(Limits, maxInterStageShaderVariables) == offsetof(WGPULimits, maxInterStageShaderVariables),
                 "offsetof mismatch for Limits::maxInterStageShaderVariables");
    static_assert(offsetof(Limits, maxColorAttachments) == offsetof(WGPULimits, maxColorAttachments),
                 "offsetof mismatch for Limits::maxColorAttachments");
    static_assert(offsetof(Limits, maxColorAttachmentBytesPerSample) == offsetof(WGPULimits, maxColorAttachmentBytesPerSample),
                 "offsetof mismatch for Limits::maxColorAttachmentBytesPerSample");
    static_assert(offsetof(Limits, maxComputeWorkgroupStorageSize) == offsetof(WGPULimits, maxComputeWorkgroupStorageSize),
                 "offsetof mismatch for Limits::maxComputeWorkgroupStorageSize");
    static_assert(offsetof(Limits, maxComputeInvocationsPerWorkgroup) == offsetof(WGPULimits, maxComputeInvocationsPerWorkgroup),
                 "offsetof mismatch for Limits::maxComputeInvocationsPerWorkgroup");
    static_assert(offsetof(Limits, maxComputeWorkgroupSizeX) == offsetof(WGPULimits, maxComputeWorkgroupSizeX),
                 "offsetof mismatch for Limits::maxComputeWorkgroupSizeX");
    static_assert(offsetof(Limits, maxComputeWorkgroupSizeY) == offsetof(WGPULimits, maxComputeWorkgroupSizeY),
                 "offsetof mismatch for Limits::maxComputeWorkgroupSizeY");
    static_assert(offsetof(Limits, maxComputeWorkgroupSizeZ) == offsetof(WGPULimits, maxComputeWorkgroupSizeZ),
                 "offsetof mismatch for Limits::maxComputeWorkgroupSizeZ");
    static_assert(offsetof(Limits, maxComputeWorkgroupsPerDimension) == offsetof(WGPULimits, maxComputeWorkgroupsPerDimension),
                 "offsetof mismatch for Limits::maxComputeWorkgroupsPerDimension");
    static_assert(offsetof(Limits, maxImmediateSize) == offsetof(WGPULimits, maxImmediateSize),
                 "offsetof mismatch for Limits::maxImmediateSize");

    bool Limits::operator==(const Limits& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (maxTextureDimension1D != rhs.maxTextureDimension1D) { return false; }
        if (maxTextureDimension2D != rhs.maxTextureDimension2D) { return false; }
        if (maxTextureDimension3D != rhs.maxTextureDimension3D) { return false; }
        if (maxTextureArrayLayers != rhs.maxTextureArrayLayers) { return false; }
        if (maxBindGroups != rhs.maxBindGroups) { return false; }
        if (maxBindGroupsPlusVertexBuffers != rhs.maxBindGroupsPlusVertexBuffers) { return false; }
        if (maxBindingsPerBindGroup != rhs.maxBindingsPerBindGroup) { return false; }
        if (maxDynamicUniformBuffersPerPipelineLayout != rhs.maxDynamicUniformBuffersPerPipelineLayout) { return false; }
        if (maxDynamicStorageBuffersPerPipelineLayout != rhs.maxDynamicStorageBuffersPerPipelineLayout) { return false; }
        if (maxSampledTexturesPerShaderStage != rhs.maxSampledTexturesPerShaderStage) { return false; }
        if (maxSamplersPerShaderStage != rhs.maxSamplersPerShaderStage) { return false; }
        if (maxStorageBuffersPerShaderStage != rhs.maxStorageBuffersPerShaderStage) { return false; }
        if (maxStorageTexturesPerShaderStage != rhs.maxStorageTexturesPerShaderStage) { return false; }
        if (maxUniformBuffersPerShaderStage != rhs.maxUniformBuffersPerShaderStage) { return false; }
        if (maxUniformBufferBindingSize != rhs.maxUniformBufferBindingSize) { return false; }
        if (maxStorageBufferBindingSize != rhs.maxStorageBufferBindingSize) { return false; }
        if (minUniformBufferOffsetAlignment != rhs.minUniformBufferOffsetAlignment) { return false; }
        if (minStorageBufferOffsetAlignment != rhs.minStorageBufferOffsetAlignment) { return false; }
        if (maxVertexBuffers != rhs.maxVertexBuffers) { return false; }
        if (maxBufferSize != rhs.maxBufferSize) { return false; }
        if (maxVertexAttributes != rhs.maxVertexAttributes) { return false; }
        if (maxVertexBufferArrayStride != rhs.maxVertexBufferArrayStride) { return false; }
        if (maxInterStageShaderVariables != rhs.maxInterStageShaderVariables) { return false; }
        if (maxColorAttachments != rhs.maxColorAttachments) { return false; }
        if (maxColorAttachmentBytesPerSample != rhs.maxColorAttachmentBytesPerSample) { return false; }
        if (maxComputeWorkgroupStorageSize != rhs.maxComputeWorkgroupStorageSize) { return false; }
        if (maxComputeInvocationsPerWorkgroup != rhs.maxComputeInvocationsPerWorkgroup) { return false; }
        if (maxComputeWorkgroupSizeX != rhs.maxComputeWorkgroupSizeX) { return false; }
        if (maxComputeWorkgroupSizeY != rhs.maxComputeWorkgroupSizeY) { return false; }
        if (maxComputeWorkgroupSizeZ != rhs.maxComputeWorkgroupSizeZ) { return false; }
        if (maxComputeWorkgroupsPerDimension != rhs.maxComputeWorkgroupsPerDimension) { return false; }
        if (maxImmediateSize != rhs.maxImmediateSize) { return false; }
        return true;
    }


    static_assert(sizeof(PipelineLayoutPixelLocalStorage) == sizeof(WGPUPipelineLayoutPixelLocalStorage), "sizeof mismatch for PipelineLayoutPixelLocalStorage");
    static_assert(alignof(PipelineLayoutPixelLocalStorage) == alignof(WGPUPipelineLayoutPixelLocalStorage), "alignof mismatch for PipelineLayoutPixelLocalStorage");

    static_assert(offsetof(PipelineLayoutPixelLocalStorage, nextInChain) == offsetof(WGPUPipelineLayoutPixelLocalStorage, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for PipelineLayoutPixelLocalStorage::nextInChain");
    static_assert(offsetof(PipelineLayoutPixelLocalStorage, sType) == offsetof(WGPUPipelineLayoutPixelLocalStorage, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for PipelineLayoutPixelLocalStorage::sType");
    static_assert(offsetof(PipelineLayoutPixelLocalStorage, totalPixelLocalStorageSize) == offsetof(WGPUPipelineLayoutPixelLocalStorage, totalPixelLocalStorageSize),
                 "offsetof mismatch for PipelineLayoutPixelLocalStorage::totalPixelLocalStorageSize");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using PipelineLayoutPixelLocalStoragestorageAttachmentsSpan = decltype(std::declval<PipelineLayoutPixelLocalStorage>().storageAttachments);
    
    static_assert(offsetof(PipelineLayoutPixelLocalStorage, storageAttachments) + PipelineLayoutPixelLocalStoragestorageAttachmentsSpan::GetOffsetOfSize() == offsetof(WGPUPipelineLayoutPixelLocalStorage, storageAttachmentCount),
                 "offsetof mismatch for PipelineLayoutPixelLocalStorage::storageAttachments::mSize");
    static_assert(offsetof(PipelineLayoutPixelLocalStorage, storageAttachments) + PipelineLayoutPixelLocalStoragestorageAttachmentsSpan::GetOffsetOfData() == offsetof(WGPUPipelineLayoutPixelLocalStorage, storageAttachments),
                 "offsetof mismatch for PipelineLayoutPixelLocalStorage::storageAttachments::mData");

    bool PipelineLayoutPixelLocalStorage::operator==(const PipelineLayoutPixelLocalStorage& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (totalPixelLocalStorageSize != rhs.totalPixelLocalStorageSize) { return false; }
        if (storageAttachments.size() != rhs.storageAttachments.size()) { return false; }
        if (storageAttachments.data() != rhs.storageAttachments.data()) { return false; }
        return true;
    }


    static_assert(sizeof(RenderBundleEncoderDescriptor) == sizeof(WGPURenderBundleEncoderDescriptor), "sizeof mismatch for RenderBundleEncoderDescriptor");
    static_assert(alignof(RenderBundleEncoderDescriptor) == alignof(WGPURenderBundleEncoderDescriptor), "alignof mismatch for RenderBundleEncoderDescriptor");

    static_assert(offsetof(RenderBundleEncoderDescriptor, nextInChain) == offsetof(WGPURenderBundleEncoderDescriptor, nextInChain),
            "offsetof mismatch for RenderBundleEncoderDescriptor::nextInChain");
    static_assert(offsetof(RenderBundleEncoderDescriptor, label) == offsetof(WGPURenderBundleEncoderDescriptor, label),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::label");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using RenderBundleEncoderDescriptorcolorFormatsSpan = decltype(std::declval<RenderBundleEncoderDescriptor>().colorFormats);
    
    static_assert(offsetof(RenderBundleEncoderDescriptor, colorFormats) + RenderBundleEncoderDescriptorcolorFormatsSpan::GetOffsetOfSize() == offsetof(WGPURenderBundleEncoderDescriptor, colorFormatCount),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormats::mSize");
    static_assert(offsetof(RenderBundleEncoderDescriptor, colorFormats) + RenderBundleEncoderDescriptorcolorFormatsSpan::GetOffsetOfData() == offsetof(WGPURenderBundleEncoderDescriptor, colorFormats),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormats::mData");
    static_assert(offsetof(RenderBundleEncoderDescriptor, depthStencilFormat) == offsetof(WGPURenderBundleEncoderDescriptor, depthStencilFormat),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::depthStencilFormat");
    static_assert(offsetof(RenderBundleEncoderDescriptor, sampleCount) == offsetof(WGPURenderBundleEncoderDescriptor, sampleCount),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::sampleCount");
    static_assert(offsetof(RenderBundleEncoderDescriptor, depthReadOnly) == offsetof(WGPURenderBundleEncoderDescriptor, depthReadOnly),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::depthReadOnly");
    static_assert(offsetof(RenderBundleEncoderDescriptor, stencilReadOnly) == offsetof(WGPURenderBundleEncoderDescriptor, stencilReadOnly),
                 "offsetof mismatch for RenderBundleEncoderDescriptor::stencilReadOnly");

    bool RenderBundleEncoderDescriptor::operator==(const RenderBundleEncoderDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (colorFormats.size() != rhs.colorFormats.size()) { return false; }
        if (colorFormats.data() != rhs.colorFormats.data()) { return false; }
        if (depthStencilFormat != rhs.depthStencilFormat) { return false; }
        if (sampleCount != rhs.sampleCount) { return false; }
        if (depthReadOnly != rhs.depthReadOnly) { return false; }
        if (stencilReadOnly != rhs.stencilReadOnly) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassColorAttachment) == sizeof(WGPURenderPassColorAttachment), "sizeof mismatch for RenderPassColorAttachment");
    static_assert(alignof(RenderPassColorAttachment) == alignof(WGPURenderPassColorAttachment), "alignof mismatch for RenderPassColorAttachment");

    static_assert(offsetof(RenderPassColorAttachment, nextInChain) == offsetof(WGPURenderPassColorAttachment, nextInChain),
            "offsetof mismatch for RenderPassColorAttachment::nextInChain");
    static_assert(offsetof(RenderPassColorAttachment, view) == offsetof(WGPURenderPassColorAttachment, view),
                 "offsetof mismatch for RenderPassColorAttachment::view");
    static_assert(offsetof(RenderPassColorAttachment, depthSlice) == offsetof(WGPURenderPassColorAttachment, depthSlice),
                 "offsetof mismatch for RenderPassColorAttachment::depthSlice");
    static_assert(offsetof(RenderPassColorAttachment, resolveTarget) == offsetof(WGPURenderPassColorAttachment, resolveTarget),
                 "offsetof mismatch for RenderPassColorAttachment::resolveTarget");
    static_assert(offsetof(RenderPassColorAttachment, loadOp) == offsetof(WGPURenderPassColorAttachment, loadOp),
                 "offsetof mismatch for RenderPassColorAttachment::loadOp");
    static_assert(offsetof(RenderPassColorAttachment, storeOp) == offsetof(WGPURenderPassColorAttachment, storeOp),
                 "offsetof mismatch for RenderPassColorAttachment::storeOp");
    static_assert(offsetof(RenderPassColorAttachment, clearValue) == offsetof(WGPURenderPassColorAttachment, clearValue),
                 "offsetof mismatch for RenderPassColorAttachment::clearValue");

    bool RenderPassColorAttachment::operator==(const RenderPassColorAttachment& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (view != rhs.view) { return false; }
        if (depthSlice != rhs.depthSlice) { return false; }
        if (resolveTarget != rhs.resolveTarget) { return false; }
        if (loadOp != rhs.loadOp) { return false; }
        if (storeOp != rhs.storeOp) { return false; }
        if (clearValue != rhs.clearValue) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassRenderAreaRect) == sizeof(WGPURenderPassRenderAreaRect), "sizeof mismatch for RenderPassRenderAreaRect");
    static_assert(alignof(RenderPassRenderAreaRect) == alignof(WGPURenderPassRenderAreaRect), "alignof mismatch for RenderPassRenderAreaRect");

    static_assert(offsetof(RenderPassRenderAreaRect, nextInChain) == offsetof(WGPURenderPassRenderAreaRect, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RenderPassRenderAreaRect::nextInChain");
    static_assert(offsetof(RenderPassRenderAreaRect, sType) == offsetof(WGPURenderPassRenderAreaRect, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RenderPassRenderAreaRect::sType");
    static_assert(offsetof(RenderPassRenderAreaRect, origin) == offsetof(WGPURenderPassRenderAreaRect, origin),
                 "offsetof mismatch for RenderPassRenderAreaRect::origin");
    static_assert(offsetof(RenderPassRenderAreaRect, size) == offsetof(WGPURenderPassRenderAreaRect, size),
                 "offsetof mismatch for RenderPassRenderAreaRect::size");

    bool RenderPassRenderAreaRect::operator==(const RenderPassRenderAreaRect& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (origin != rhs.origin) { return false; }
        if (size != rhs.size) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassStorageAttachment) == sizeof(WGPURenderPassStorageAttachment), "sizeof mismatch for RenderPassStorageAttachment");
    static_assert(alignof(RenderPassStorageAttachment) == alignof(WGPURenderPassStorageAttachment), "alignof mismatch for RenderPassStorageAttachment");

    static_assert(offsetof(RenderPassStorageAttachment, nextInChain) == offsetof(WGPURenderPassStorageAttachment, nextInChain),
            "offsetof mismatch for RenderPassStorageAttachment::nextInChain");
    static_assert(offsetof(RenderPassStorageAttachment, offset) == offsetof(WGPURenderPassStorageAttachment, offset),
                 "offsetof mismatch for RenderPassStorageAttachment::offset");
    static_assert(offsetof(RenderPassStorageAttachment, storage) == offsetof(WGPURenderPassStorageAttachment, storage),
                 "offsetof mismatch for RenderPassStorageAttachment::storage");
    static_assert(offsetof(RenderPassStorageAttachment, loadOp) == offsetof(WGPURenderPassStorageAttachment, loadOp),
                 "offsetof mismatch for RenderPassStorageAttachment::loadOp");
    static_assert(offsetof(RenderPassStorageAttachment, storeOp) == offsetof(WGPURenderPassStorageAttachment, storeOp),
                 "offsetof mismatch for RenderPassStorageAttachment::storeOp");
    static_assert(offsetof(RenderPassStorageAttachment, clearValue) == offsetof(WGPURenderPassStorageAttachment, clearValue),
                 "offsetof mismatch for RenderPassStorageAttachment::clearValue");

    bool RenderPassStorageAttachment::operator==(const RenderPassStorageAttachment& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (offset != rhs.offset) { return false; }
        if (storage != rhs.storage) { return false; }
        if (loadOp != rhs.loadOp) { return false; }
        if (storeOp != rhs.storeOp) { return false; }
        if (clearValue != rhs.clearValue) { return false; }
        return true;
    }


    static_assert(sizeof(RequestAdapterOptions) == sizeof(WGPURequestAdapterOptions), "sizeof mismatch for RequestAdapterOptions");
    static_assert(alignof(RequestAdapterOptions) == alignof(WGPURequestAdapterOptions), "alignof mismatch for RequestAdapterOptions");

    static_assert(offsetof(RequestAdapterOptions, nextInChain) == offsetof(WGPURequestAdapterOptions, nextInChain),
            "offsetof mismatch for RequestAdapterOptions::nextInChain");
    static_assert(offsetof(RequestAdapterOptions, featureLevel) == offsetof(WGPURequestAdapterOptions, featureLevel),
                 "offsetof mismatch for RequestAdapterOptions::featureLevel");
    static_assert(offsetof(RequestAdapterOptions, powerPreference) == offsetof(WGPURequestAdapterOptions, powerPreference),
                 "offsetof mismatch for RequestAdapterOptions::powerPreference");
    static_assert(offsetof(RequestAdapterOptions, forceFallbackAdapter) == offsetof(WGPURequestAdapterOptions, forceFallbackAdapter),
                 "offsetof mismatch for RequestAdapterOptions::forceFallbackAdapter");
    static_assert(offsetof(RequestAdapterOptions, backendType) == offsetof(WGPURequestAdapterOptions, backendType),
                 "offsetof mismatch for RequestAdapterOptions::backendType");
    static_assert(offsetof(RequestAdapterOptions, compatibleSurface) == offsetof(WGPURequestAdapterOptions, compatibleSurface),
                 "offsetof mismatch for RequestAdapterOptions::compatibleSurface");

    RequestAdapterOptions RequestAdapterOptions::WithTrivialFrontendDefaults() const {
        RequestAdapterOptions copy;
        copy.nextInChain = nextInChain;
        copy.featureLevel = (featureLevel == wgpu::FeatureLevel::Undefined)
            ? wgpu::FeatureLevel::Core
            : featureLevel;
        copy.powerPreference = powerPreference;
        copy.forceFallbackAdapter = forceFallbackAdapter;
        copy.backendType = backendType;
        copy.compatibleSurface = compatibleSurface;
        return copy;
    }
    bool RequestAdapterOptions::operator==(const RequestAdapterOptions& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (featureLevel != rhs.featureLevel) { return false; }
        if (powerPreference != rhs.powerPreference) { return false; }
        if (forceFallbackAdapter != rhs.forceFallbackAdapter) { return false; }
        if (backendType != rhs.backendType) { return false; }
        if (compatibleSurface != rhs.compatibleSurface) { return false; }
        return true;
    }


    static_assert(sizeof(SamplerDescriptor) == sizeof(WGPUSamplerDescriptor), "sizeof mismatch for SamplerDescriptor");
    static_assert(alignof(SamplerDescriptor) == alignof(WGPUSamplerDescriptor), "alignof mismatch for SamplerDescriptor");

    static_assert(offsetof(SamplerDescriptor, nextInChain) == offsetof(WGPUSamplerDescriptor, nextInChain),
            "offsetof mismatch for SamplerDescriptor::nextInChain");
    static_assert(offsetof(SamplerDescriptor, label) == offsetof(WGPUSamplerDescriptor, label),
                 "offsetof mismatch for SamplerDescriptor::label");
    static_assert(offsetof(SamplerDescriptor, addressModeU) == offsetof(WGPUSamplerDescriptor, addressModeU),
                 "offsetof mismatch for SamplerDescriptor::addressModeU");
    static_assert(offsetof(SamplerDescriptor, addressModeV) == offsetof(WGPUSamplerDescriptor, addressModeV),
                 "offsetof mismatch for SamplerDescriptor::addressModeV");
    static_assert(offsetof(SamplerDescriptor, addressModeW) == offsetof(WGPUSamplerDescriptor, addressModeW),
                 "offsetof mismatch for SamplerDescriptor::addressModeW");
    static_assert(offsetof(SamplerDescriptor, magFilter) == offsetof(WGPUSamplerDescriptor, magFilter),
                 "offsetof mismatch for SamplerDescriptor::magFilter");
    static_assert(offsetof(SamplerDescriptor, minFilter) == offsetof(WGPUSamplerDescriptor, minFilter),
                 "offsetof mismatch for SamplerDescriptor::minFilter");
    static_assert(offsetof(SamplerDescriptor, mipmapFilter) == offsetof(WGPUSamplerDescriptor, mipmapFilter),
                 "offsetof mismatch for SamplerDescriptor::mipmapFilter");
    static_assert(offsetof(SamplerDescriptor, lodMinClamp) == offsetof(WGPUSamplerDescriptor, lodMinClamp),
                 "offsetof mismatch for SamplerDescriptor::lodMinClamp");
    static_assert(offsetof(SamplerDescriptor, lodMaxClamp) == offsetof(WGPUSamplerDescriptor, lodMaxClamp),
                 "offsetof mismatch for SamplerDescriptor::lodMaxClamp");
    static_assert(offsetof(SamplerDescriptor, compare) == offsetof(WGPUSamplerDescriptor, compare),
                 "offsetof mismatch for SamplerDescriptor::compare");
    static_assert(offsetof(SamplerDescriptor, maxAnisotropy) == offsetof(WGPUSamplerDescriptor, maxAnisotropy),
                 "offsetof mismatch for SamplerDescriptor::maxAnisotropy");

    SamplerDescriptor SamplerDescriptor::WithTrivialFrontendDefaults() const {
        SamplerDescriptor copy;
        copy.nextInChain = nextInChain;
        copy.label = label;
        copy.addressModeU = (addressModeU == wgpu::AddressMode::Undefined)
            ? wgpu::AddressMode::ClampToEdge
            : addressModeU;
        copy.addressModeV = (addressModeV == wgpu::AddressMode::Undefined)
            ? wgpu::AddressMode::ClampToEdge
            : addressModeV;
        copy.addressModeW = (addressModeW == wgpu::AddressMode::Undefined)
            ? wgpu::AddressMode::ClampToEdge
            : addressModeW;
        copy.magFilter = (magFilter == wgpu::FilterMode::Undefined)
            ? wgpu::FilterMode::Nearest
            : magFilter;
        copy.minFilter = (minFilter == wgpu::FilterMode::Undefined)
            ? wgpu::FilterMode::Nearest
            : minFilter;
        copy.mipmapFilter = (mipmapFilter == wgpu::MipmapFilterMode::Undefined)
            ? wgpu::MipmapFilterMode::Nearest
            : mipmapFilter;
        copy.lodMinClamp = lodMinClamp;
        copy.lodMaxClamp = lodMaxClamp;
        copy.compare = compare;
        copy.maxAnisotropy = maxAnisotropy;
        return copy;
    }
    bool SamplerDescriptor::operator==(const SamplerDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (addressModeU != rhs.addressModeU) { return false; }
        if (addressModeV != rhs.addressModeV) { return false; }
        if (addressModeW != rhs.addressModeW) { return false; }
        if (magFilter != rhs.magFilter) { return false; }
        if (minFilter != rhs.minFilter) { return false; }
        if (mipmapFilter != rhs.mipmapFilter) { return false; }
        if (lodMinClamp != rhs.lodMinClamp) { return false; }
        if (lodMaxClamp != rhs.lodMaxClamp) { return false; }
        if (compare != rhs.compare) { return false; }
        if (maxAnisotropy != rhs.maxAnisotropy) { return false; }
        return true;
    }


    static_assert(sizeof(ShaderModuleDescriptor) == sizeof(WGPUShaderModuleDescriptor), "sizeof mismatch for ShaderModuleDescriptor");
    static_assert(alignof(ShaderModuleDescriptor) == alignof(WGPUShaderModuleDescriptor), "alignof mismatch for ShaderModuleDescriptor");

    static_assert(offsetof(ShaderModuleDescriptor, nextInChain) == offsetof(WGPUShaderModuleDescriptor, nextInChain),
            "offsetof mismatch for ShaderModuleDescriptor::nextInChain");
    static_assert(offsetof(ShaderModuleDescriptor, label) == offsetof(WGPUShaderModuleDescriptor, label),
                 "offsetof mismatch for ShaderModuleDescriptor::label");

    bool ShaderModuleDescriptor::operator==(const ShaderModuleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(SharedBufferMemoryDescriptor) == sizeof(WGPUSharedBufferMemoryDescriptor), "sizeof mismatch for SharedBufferMemoryDescriptor");
    static_assert(alignof(SharedBufferMemoryDescriptor) == alignof(WGPUSharedBufferMemoryDescriptor), "alignof mismatch for SharedBufferMemoryDescriptor");

    static_assert(offsetof(SharedBufferMemoryDescriptor, nextInChain) == offsetof(WGPUSharedBufferMemoryDescriptor, nextInChain),
            "offsetof mismatch for SharedBufferMemoryDescriptor::nextInChain");
    static_assert(offsetof(SharedBufferMemoryDescriptor, label) == offsetof(WGPUSharedBufferMemoryDescriptor, label),
                 "offsetof mismatch for SharedBufferMemoryDescriptor::label");

    bool SharedBufferMemoryDescriptor::operator==(const SharedBufferMemoryDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceDescriptor) == sizeof(WGPUSharedFenceDescriptor), "sizeof mismatch for SharedFenceDescriptor");
    static_assert(alignof(SharedFenceDescriptor) == alignof(WGPUSharedFenceDescriptor), "alignof mismatch for SharedFenceDescriptor");

    static_assert(offsetof(SharedFenceDescriptor, nextInChain) == offsetof(WGPUSharedFenceDescriptor, nextInChain),
            "offsetof mismatch for SharedFenceDescriptor::nextInChain");
    static_assert(offsetof(SharedFenceDescriptor, label) == offsetof(WGPUSharedFenceDescriptor, label),
                 "offsetof mismatch for SharedFenceDescriptor::label");

    bool SharedFenceDescriptor::operator==(const SharedFenceDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(SharedFenceExportInfo) == sizeof(WGPUSharedFenceExportInfo), "sizeof mismatch for SharedFenceExportInfo");
    static_assert(alignof(SharedFenceExportInfo) == alignof(WGPUSharedFenceExportInfo), "alignof mismatch for SharedFenceExportInfo");

    static_assert(offsetof(SharedFenceExportInfo, nextInChain) == offsetof(WGPUSharedFenceExportInfo, nextInChain),
            "offsetof mismatch for SharedFenceExportInfo::nextInChain");
    static_assert(offsetof(SharedFenceExportInfo, type) == offsetof(WGPUSharedFenceExportInfo, type),
                 "offsetof mismatch for SharedFenceExportInfo::type");

    bool SharedFenceExportInfo::operator==(const SharedFenceExportInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (type != rhs.type) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryAHardwareBufferProperties) == sizeof(WGPUSharedTextureMemoryAHardwareBufferProperties), "sizeof mismatch for SharedTextureMemoryAHardwareBufferProperties");
    static_assert(alignof(SharedTextureMemoryAHardwareBufferProperties) == alignof(WGPUSharedTextureMemoryAHardwareBufferProperties), "alignof mismatch for SharedTextureMemoryAHardwareBufferProperties");

    static_assert(offsetof(SharedTextureMemoryAHardwareBufferProperties, nextInChain) == offsetof(WGPUSharedTextureMemoryAHardwareBufferProperties, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryAHardwareBufferProperties::nextInChain");
    static_assert(offsetof(SharedTextureMemoryAHardwareBufferProperties, sType) == offsetof(WGPUSharedTextureMemoryAHardwareBufferProperties, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryAHardwareBufferProperties::sType");
    static_assert(offsetof(SharedTextureMemoryAHardwareBufferProperties, yCbCrInfo) == offsetof(WGPUSharedTextureMemoryAHardwareBufferProperties, yCbCrInfo),
                 "offsetof mismatch for SharedTextureMemoryAHardwareBufferProperties::yCbCrInfo");

    SharedTextureMemoryAHardwareBufferProperties SharedTextureMemoryAHardwareBufferProperties::WithTrivialFrontendDefaults() const {
        SharedTextureMemoryAHardwareBufferProperties copy;
        copy.nextInChain = nextInChain;
        copy.sType = sType;
        copy.yCbCrInfo = yCbCrInfo.WithTrivialFrontendDefaults();
        return copy;
    }
    bool SharedTextureMemoryAHardwareBufferProperties::operator==(const SharedTextureMemoryAHardwareBufferProperties& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (yCbCrInfo != rhs.yCbCrInfo) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryBeginAccessDescriptor) == sizeof(WGPUSharedTextureMemoryBeginAccessDescriptor), "sizeof mismatch for SharedTextureMemoryBeginAccessDescriptor");
    static_assert(alignof(SharedTextureMemoryBeginAccessDescriptor) == alignof(WGPUSharedTextureMemoryBeginAccessDescriptor), "alignof mismatch for SharedTextureMemoryBeginAccessDescriptor");

    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, nextInChain),
            "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, concurrentRead) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, concurrentRead),
                 "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::concurrentRead");
    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, initialized) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, initialized),
                 "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::initialized");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedTextureMemoryBeginAccessDescriptorfencesSpan = decltype(std::declval<SharedTextureMemoryBeginAccessDescriptor>().fences);
    
    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, fences) + SharedTextureMemoryBeginAccessDescriptorfencesSpan::GetOffsetOfSize() == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, fenceCount),
                 "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::fences::mSize");
    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, fences) + SharedTextureMemoryBeginAccessDescriptorfencesSpan::GetOffsetOfData() == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, fences),
                 "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::fences::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedTextureMemoryBeginAccessDescriptorsignaledValuesSpan = decltype(std::declval<SharedTextureMemoryBeginAccessDescriptor>().signaledValues);
    
    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, signaledValues) + SharedTextureMemoryBeginAccessDescriptorsignaledValuesSpan::GetOffsetOfSize() == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, signaledValueCount),
                 "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::signaledValues::mSize");
    static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, signaledValues) + SharedTextureMemoryBeginAccessDescriptorsignaledValuesSpan::GetOffsetOfData() == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, signaledValues),
                 "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::signaledValues::mData");

    bool SharedTextureMemoryBeginAccessDescriptor::operator==(const SharedTextureMemoryBeginAccessDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (concurrentRead != rhs.concurrentRead) { return false; }
        if (initialized != rhs.initialized) { return false; }
        if (fences.size() != rhs.fences.size()) { return false; }
        if (fences.data() != rhs.fences.data()) { return false; }
        if (signaledValues.size() != rhs.signaledValues.size()) { return false; }
        if (signaledValues.data() != rhs.signaledValues.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryDmaBufDescriptor) == sizeof(WGPUSharedTextureMemoryDmaBufDescriptor), "sizeof mismatch for SharedTextureMemoryDmaBufDescriptor");
    static_assert(alignof(SharedTextureMemoryDmaBufDescriptor) == alignof(WGPUSharedTextureMemoryDmaBufDescriptor), "alignof mismatch for SharedTextureMemoryDmaBufDescriptor");

    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, sType) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::sType");
    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, size) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, size),
                 "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::size");
    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, drmFormat) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, drmFormat),
                 "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::drmFormat");
    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, drmModifier) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, drmModifier),
                 "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::drmModifier");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedTextureMemoryDmaBufDescriptorplanesSpan = decltype(std::declval<SharedTextureMemoryDmaBufDescriptor>().planes);
    
    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, planes) + SharedTextureMemoryDmaBufDescriptorplanesSpan::GetOffsetOfSize() == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, planeCount),
                 "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::planes::mSize");
    static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, planes) + SharedTextureMemoryDmaBufDescriptorplanesSpan::GetOffsetOfData() == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, planes),
                 "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::planes::mData");

    bool SharedTextureMemoryDmaBufDescriptor::operator==(const SharedTextureMemoryDmaBufDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (size != rhs.size) { return false; }
        if (drmFormat != rhs.drmFormat) { return false; }
        if (drmModifier != rhs.drmModifier) { return false; }
        if (planes.size() != rhs.planes.size()) { return false; }
        if (planes.data() != rhs.planes.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryMetalEndAccessState) == sizeof(WGPUSharedTextureMemoryMetalEndAccessState), "sizeof mismatch for SharedTextureMemoryMetalEndAccessState");
    static_assert(alignof(SharedTextureMemoryMetalEndAccessState) == alignof(WGPUSharedTextureMemoryMetalEndAccessState), "alignof mismatch for SharedTextureMemoryMetalEndAccessState");

    static_assert(offsetof(SharedTextureMemoryMetalEndAccessState, nextInChain) == offsetof(WGPUSharedTextureMemoryMetalEndAccessState, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for SharedTextureMemoryMetalEndAccessState::nextInChain");
    static_assert(offsetof(SharedTextureMemoryMetalEndAccessState, sType) == offsetof(WGPUSharedTextureMemoryMetalEndAccessState, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for SharedTextureMemoryMetalEndAccessState::sType");
    static_assert(offsetof(SharedTextureMemoryMetalEndAccessState, commandsScheduledFuture) == offsetof(WGPUSharedTextureMemoryMetalEndAccessState, commandsScheduledFuture),
                 "offsetof mismatch for SharedTextureMemoryMetalEndAccessState::commandsScheduledFuture");

    bool SharedTextureMemoryMetalEndAccessState::operator==(const SharedTextureMemoryMetalEndAccessState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (commandsScheduledFuture != rhs.commandsScheduledFuture) { return false; }
        return true;
    }


    static_assert(sizeof(SurfaceDescriptor) == sizeof(WGPUSurfaceDescriptor), "sizeof mismatch for SurfaceDescriptor");
    static_assert(alignof(SurfaceDescriptor) == alignof(WGPUSurfaceDescriptor), "alignof mismatch for SurfaceDescriptor");

    static_assert(offsetof(SurfaceDescriptor, nextInChain) == offsetof(WGPUSurfaceDescriptor, nextInChain),
            "offsetof mismatch for SurfaceDescriptor::nextInChain");
    static_assert(offsetof(SurfaceDescriptor, label) == offsetof(WGPUSurfaceDescriptor, label),
                 "offsetof mismatch for SurfaceDescriptor::label");

    bool SurfaceDescriptor::operator==(const SurfaceDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(TexelCopyBufferInfo) == sizeof(WGPUTexelCopyBufferInfo), "sizeof mismatch for TexelCopyBufferInfo");
    static_assert(alignof(TexelCopyBufferInfo) == alignof(WGPUTexelCopyBufferInfo), "alignof mismatch for TexelCopyBufferInfo");

    static_assert(offsetof(TexelCopyBufferInfo, layout) == offsetof(WGPUTexelCopyBufferInfo, layout),
                 "offsetof mismatch for TexelCopyBufferInfo::layout");
    static_assert(offsetof(TexelCopyBufferInfo, buffer) == offsetof(WGPUTexelCopyBufferInfo, buffer),
                 "offsetof mismatch for TexelCopyBufferInfo::buffer");

    bool TexelCopyBufferInfo::operator==(const TexelCopyBufferInfo& rhs) const {
        if (layout != rhs.layout) { return false; }
        if (buffer != rhs.buffer) { return false; }
        return true;
    }


    static_assert(sizeof(TexelCopyTextureInfo) == sizeof(WGPUTexelCopyTextureInfo), "sizeof mismatch for TexelCopyTextureInfo");
    static_assert(alignof(TexelCopyTextureInfo) == alignof(WGPUTexelCopyTextureInfo), "alignof mismatch for TexelCopyTextureInfo");

    static_assert(offsetof(TexelCopyTextureInfo, texture) == offsetof(WGPUTexelCopyTextureInfo, texture),
                 "offsetof mismatch for TexelCopyTextureInfo::texture");
    static_assert(offsetof(TexelCopyTextureInfo, mipLevel) == offsetof(WGPUTexelCopyTextureInfo, mipLevel),
                 "offsetof mismatch for TexelCopyTextureInfo::mipLevel");
    static_assert(offsetof(TexelCopyTextureInfo, origin) == offsetof(WGPUTexelCopyTextureInfo, origin),
                 "offsetof mismatch for TexelCopyTextureInfo::origin");
    static_assert(offsetof(TexelCopyTextureInfo, aspect) == offsetof(WGPUTexelCopyTextureInfo, aspect),
                 "offsetof mismatch for TexelCopyTextureInfo::aspect");

    TexelCopyTextureInfo TexelCopyTextureInfo::WithTrivialFrontendDefaults() const {
        TexelCopyTextureInfo copy;
        copy.texture = texture;
        copy.mipLevel = mipLevel;
        copy.origin = origin;
        copy.aspect = (aspect == wgpu::TextureAspect::Undefined)
            ? wgpu::TextureAspect::All
            : aspect;
        return copy;
    }
    bool TexelCopyTextureInfo::operator==(const TexelCopyTextureInfo& rhs) const {
        if (texture != rhs.texture) { return false; }
        if (mipLevel != rhs.mipLevel) { return false; }
        if (origin != rhs.origin) { return false; }
        if (aspect != rhs.aspect) { return false; }
        return true;
    }


    static_assert(sizeof(TextureComponentSwizzleDescriptor) == sizeof(WGPUTextureComponentSwizzleDescriptor), "sizeof mismatch for TextureComponentSwizzleDescriptor");
    static_assert(alignof(TextureComponentSwizzleDescriptor) == alignof(WGPUTextureComponentSwizzleDescriptor), "alignof mismatch for TextureComponentSwizzleDescriptor");

    static_assert(offsetof(TextureComponentSwizzleDescriptor, nextInChain) == offsetof(WGPUTextureComponentSwizzleDescriptor, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for TextureComponentSwizzleDescriptor::nextInChain");
    static_assert(offsetof(TextureComponentSwizzleDescriptor, sType) == offsetof(WGPUTextureComponentSwizzleDescriptor, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for TextureComponentSwizzleDescriptor::sType");
    static_assert(offsetof(TextureComponentSwizzleDescriptor, swizzle) == offsetof(WGPUTextureComponentSwizzleDescriptor, swizzle),
                 "offsetof mismatch for TextureComponentSwizzleDescriptor::swizzle");

    TextureComponentSwizzleDescriptor TextureComponentSwizzleDescriptor::WithTrivialFrontendDefaults() const {
        TextureComponentSwizzleDescriptor copy;
        copy.nextInChain = nextInChain;
        copy.sType = sType;
        copy.swizzle = swizzle.WithTrivialFrontendDefaults();
        return copy;
    }
    bool TextureComponentSwizzleDescriptor::operator==(const TextureComponentSwizzleDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (swizzle != rhs.swizzle) { return false; }
        return true;
    }


    static_assert(sizeof(TextureDescriptor) == sizeof(WGPUTextureDescriptor), "sizeof mismatch for TextureDescriptor");
    static_assert(alignof(TextureDescriptor) == alignof(WGPUTextureDescriptor), "alignof mismatch for TextureDescriptor");

    static_assert(offsetof(TextureDescriptor, nextInChain) == offsetof(WGPUTextureDescriptor, nextInChain),
            "offsetof mismatch for TextureDescriptor::nextInChain");
    static_assert(offsetof(TextureDescriptor, label) == offsetof(WGPUTextureDescriptor, label),
                 "offsetof mismatch for TextureDescriptor::label");
    static_assert(offsetof(TextureDescriptor, usage) == offsetof(WGPUTextureDescriptor, usage),
                 "offsetof mismatch for TextureDescriptor::usage");
    static_assert(offsetof(TextureDescriptor, dimension) == offsetof(WGPUTextureDescriptor, dimension),
                 "offsetof mismatch for TextureDescriptor::dimension");
    static_assert(offsetof(TextureDescriptor, size) == offsetof(WGPUTextureDescriptor, size),
                 "offsetof mismatch for TextureDescriptor::size");
    static_assert(offsetof(TextureDescriptor, format) == offsetof(WGPUTextureDescriptor, format),
                 "offsetof mismatch for TextureDescriptor::format");
    static_assert(offsetof(TextureDescriptor, mipLevelCount) == offsetof(WGPUTextureDescriptor, mipLevelCount),
                 "offsetof mismatch for TextureDescriptor::mipLevelCount");
    static_assert(offsetof(TextureDescriptor, sampleCount) == offsetof(WGPUTextureDescriptor, sampleCount),
                 "offsetof mismatch for TextureDescriptor::sampleCount");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using TextureDescriptorviewFormatsSpan = decltype(std::declval<TextureDescriptor>().viewFormats);
    
    static_assert(offsetof(TextureDescriptor, viewFormats) + TextureDescriptorviewFormatsSpan::GetOffsetOfSize() == offsetof(WGPUTextureDescriptor, viewFormatCount),
                 "offsetof mismatch for TextureDescriptor::viewFormats::mSize");
    static_assert(offsetof(TextureDescriptor, viewFormats) + TextureDescriptorviewFormatsSpan::GetOffsetOfData() == offsetof(WGPUTextureDescriptor, viewFormats),
                 "offsetof mismatch for TextureDescriptor::viewFormats::mData");

    TextureDescriptor TextureDescriptor::WithTrivialFrontendDefaults() const {
        TextureDescriptor copy;
        copy.nextInChain = nextInChain;
        copy.label = label;
        copy.usage = usage;
        copy.dimension = (dimension == wgpu::TextureDimension::Undefined)
            ? wgpu::TextureDimension::e2D
            : dimension;
        copy.size = size;
        copy.format = format;
        copy.mipLevelCount = mipLevelCount;
        copy.sampleCount = sampleCount;
        copy.viewFormats = viewFormats;
        return copy;
    }
    bool TextureDescriptor::operator==(const TextureDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (usage != rhs.usage) { return false; }
        if (dimension != rhs.dimension) { return false; }
        if (size != rhs.size) { return false; }
        if (format != rhs.format) { return false; }
        if (mipLevelCount != rhs.mipLevelCount) { return false; }
        if (sampleCount != rhs.sampleCount) { return false; }
        if (viewFormats.size() != rhs.viewFormats.size()) { return false; }
        if (viewFormats.data() != rhs.viewFormats.data()) { return false; }
        return true;
    }


    static_assert(sizeof(VertexBufferLayout) == sizeof(WGPUVertexBufferLayout), "sizeof mismatch for VertexBufferLayout");
    static_assert(alignof(VertexBufferLayout) == alignof(WGPUVertexBufferLayout), "alignof mismatch for VertexBufferLayout");

    static_assert(offsetof(VertexBufferLayout, nextInChain) == offsetof(WGPUVertexBufferLayout, nextInChain),
            "offsetof mismatch for VertexBufferLayout::nextInChain");
    static_assert(offsetof(VertexBufferLayout, stepMode) == offsetof(WGPUVertexBufferLayout, stepMode),
                 "offsetof mismatch for VertexBufferLayout::stepMode");
    static_assert(offsetof(VertexBufferLayout, arrayStride) == offsetof(WGPUVertexBufferLayout, arrayStride),
                 "offsetof mismatch for VertexBufferLayout::arrayStride");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using VertexBufferLayoutattributesSpan = decltype(std::declval<VertexBufferLayout>().attributes);
    
    static_assert(offsetof(VertexBufferLayout, attributes) + VertexBufferLayoutattributesSpan::GetOffsetOfSize() == offsetof(WGPUVertexBufferLayout, attributeCount),
                 "offsetof mismatch for VertexBufferLayout::attributes::mSize");
    static_assert(offsetof(VertexBufferLayout, attributes) + VertexBufferLayoutattributesSpan::GetOffsetOfData() == offsetof(WGPUVertexBufferLayout, attributes),
                 "offsetof mismatch for VertexBufferLayout::attributes::mData");

    bool VertexBufferLayout::operator==(const VertexBufferLayout& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (stepMode != rhs.stepMode) { return false; }
        if (arrayStride != rhs.arrayStride) { return false; }
        if (attributes.size() != rhs.attributes.size()) { return false; }
        if (attributes.data() != rhs.attributes.data()) { return false; }
        return true;
    }


    static_assert(sizeof(AdapterInfo) == sizeof(WGPUAdapterInfo), "sizeof mismatch for AdapterInfo");
    static_assert(alignof(AdapterInfo) == alignof(WGPUAdapterInfo), "alignof mismatch for AdapterInfo");

    static_assert(offsetof(AdapterInfo, nextInChain) == offsetof(WGPUAdapterInfo, nextInChain),
            "offsetof mismatch for AdapterInfo::nextInChain");
    static_assert(offsetof(AdapterInfo, vendor) == offsetof(WGPUAdapterInfo, vendor),
                 "offsetof mismatch for AdapterInfo::vendor");
    static_assert(offsetof(AdapterInfo, architecture) == offsetof(WGPUAdapterInfo, architecture),
                 "offsetof mismatch for AdapterInfo::architecture");
    static_assert(offsetof(AdapterInfo, device) == offsetof(WGPUAdapterInfo, device),
                 "offsetof mismatch for AdapterInfo::device");
    static_assert(offsetof(AdapterInfo, description) == offsetof(WGPUAdapterInfo, description),
                 "offsetof mismatch for AdapterInfo::description");
    static_assert(offsetof(AdapterInfo, backendType) == offsetof(WGPUAdapterInfo, backendType),
                 "offsetof mismatch for AdapterInfo::backendType");
    static_assert(offsetof(AdapterInfo, adapterType) == offsetof(WGPUAdapterInfo, adapterType),
                 "offsetof mismatch for AdapterInfo::adapterType");
    static_assert(offsetof(AdapterInfo, vendorID) == offsetof(WGPUAdapterInfo, vendorID),
                 "offsetof mismatch for AdapterInfo::vendorID");
    static_assert(offsetof(AdapterInfo, deviceID) == offsetof(WGPUAdapterInfo, deviceID),
                 "offsetof mismatch for AdapterInfo::deviceID");
    static_assert(offsetof(AdapterInfo, subgroupMinSize) == offsetof(WGPUAdapterInfo, subgroupMinSize),
                 "offsetof mismatch for AdapterInfo::subgroupMinSize");
    static_assert(offsetof(AdapterInfo, subgroupMaxSize) == offsetof(WGPUAdapterInfo, subgroupMaxSize),
                 "offsetof mismatch for AdapterInfo::subgroupMaxSize");

    bool AdapterInfo::operator==(const AdapterInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (vendor != rhs.vendor) { return false; }
        if (architecture != rhs.architecture) { return false; }
        if (device != rhs.device) { return false; }
        if (description != rhs.description) { return false; }
        if (backendType != rhs.backendType) { return false; }
        if (adapterType != rhs.adapterType) { return false; }
        if (vendorID != rhs.vendorID) { return false; }
        if (deviceID != rhs.deviceID) { return false; }
        if (subgroupMinSize != rhs.subgroupMinSize) { return false; }
        if (subgroupMaxSize != rhs.subgroupMaxSize) { return false; }
        return true;
    }


    static_assert(sizeof(BindGroupDescriptor) == sizeof(WGPUBindGroupDescriptor), "sizeof mismatch for BindGroupDescriptor");
    static_assert(alignof(BindGroupDescriptor) == alignof(WGPUBindGroupDescriptor), "alignof mismatch for BindGroupDescriptor");

    static_assert(offsetof(BindGroupDescriptor, nextInChain) == offsetof(WGPUBindGroupDescriptor, nextInChain),
            "offsetof mismatch for BindGroupDescriptor::nextInChain");
    static_assert(offsetof(BindGroupDescriptor, label) == offsetof(WGPUBindGroupDescriptor, label),
                 "offsetof mismatch for BindGroupDescriptor::label");
    static_assert(offsetof(BindGroupDescriptor, layout) == offsetof(WGPUBindGroupDescriptor, layout),
                 "offsetof mismatch for BindGroupDescriptor::layout");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using BindGroupDescriptorentriesSpan = decltype(std::declval<BindGroupDescriptor>().entries);
    
    static_assert(offsetof(BindGroupDescriptor, entries) + BindGroupDescriptorentriesSpan::GetOffsetOfSize() == offsetof(WGPUBindGroupDescriptor, entryCount),
                 "offsetof mismatch for BindGroupDescriptor::entries::mSize");
    static_assert(offsetof(BindGroupDescriptor, entries) + BindGroupDescriptorentriesSpan::GetOffsetOfData() == offsetof(WGPUBindGroupDescriptor, entries),
                 "offsetof mismatch for BindGroupDescriptor::entries::mData");

    bool BindGroupDescriptor::operator==(const BindGroupDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (layout != rhs.layout) { return false; }
        if (entries.size() != rhs.entries.size()) { return false; }
        if (entries.data() != rhs.entries.data()) { return false; }
        return true;
    }


    static_assert(sizeof(BindGroupLayoutDescriptor) == sizeof(WGPUBindGroupLayoutDescriptor), "sizeof mismatch for BindGroupLayoutDescriptor");
    static_assert(alignof(BindGroupLayoutDescriptor) == alignof(WGPUBindGroupLayoutDescriptor), "alignof mismatch for BindGroupLayoutDescriptor");

    static_assert(offsetof(BindGroupLayoutDescriptor, nextInChain) == offsetof(WGPUBindGroupLayoutDescriptor, nextInChain),
            "offsetof mismatch for BindGroupLayoutDescriptor::nextInChain");
    static_assert(offsetof(BindGroupLayoutDescriptor, label) == offsetof(WGPUBindGroupLayoutDescriptor, label),
                 "offsetof mismatch for BindGroupLayoutDescriptor::label");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using BindGroupLayoutDescriptorentriesSpan = decltype(std::declval<BindGroupLayoutDescriptor>().entries);
    
    static_assert(offsetof(BindGroupLayoutDescriptor, entries) + BindGroupLayoutDescriptorentriesSpan::GetOffsetOfSize() == offsetof(WGPUBindGroupLayoutDescriptor, entryCount),
                 "offsetof mismatch for BindGroupLayoutDescriptor::entries::mSize");
    static_assert(offsetof(BindGroupLayoutDescriptor, entries) + BindGroupLayoutDescriptorentriesSpan::GetOffsetOfData() == offsetof(WGPUBindGroupLayoutDescriptor, entries),
                 "offsetof mismatch for BindGroupLayoutDescriptor::entries::mData");

    bool BindGroupLayoutDescriptor::operator==(const BindGroupLayoutDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (entries.size() != rhs.entries.size()) { return false; }
        if (entries.data() != rhs.entries.data()) { return false; }
        return true;
    }


    static_assert(sizeof(ColorTargetState) == sizeof(WGPUColorTargetState), "sizeof mismatch for ColorTargetState");
    static_assert(alignof(ColorTargetState) == alignof(WGPUColorTargetState), "alignof mismatch for ColorTargetState");

    static_assert(offsetof(ColorTargetState, nextInChain) == offsetof(WGPUColorTargetState, nextInChain),
            "offsetof mismatch for ColorTargetState::nextInChain");
    static_assert(offsetof(ColorTargetState, format) == offsetof(WGPUColorTargetState, format),
                 "offsetof mismatch for ColorTargetState::format");
    static_assert(offsetof(ColorTargetState, blend) == offsetof(WGPUColorTargetState, blend),
                 "offsetof mismatch for ColorTargetState::blend");
    static_assert(offsetof(ColorTargetState, writeMask) == offsetof(WGPUColorTargetState, writeMask),
                 "offsetof mismatch for ColorTargetState::writeMask");

    bool ColorTargetState::operator==(const ColorTargetState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (format != rhs.format) { return false; }
        if (blend != rhs.blend) { return false; }
        if (writeMask != rhs.writeMask) { return false; }
        return true;
    }


    static_assert(sizeof(CompilationInfo) == sizeof(WGPUCompilationInfo), "sizeof mismatch for CompilationInfo");
    static_assert(alignof(CompilationInfo) == alignof(WGPUCompilationInfo), "alignof mismatch for CompilationInfo");

    static_assert(offsetof(CompilationInfo, nextInChain) == offsetof(WGPUCompilationInfo, nextInChain),
            "offsetof mismatch for CompilationInfo::nextInChain");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using CompilationInfomessagesSpan = decltype(std::declval<CompilationInfo>().messages);
    
    static_assert(offsetof(CompilationInfo, messages) + CompilationInfomessagesSpan::GetOffsetOfSize() == offsetof(WGPUCompilationInfo, messageCount),
                 "offsetof mismatch for CompilationInfo::messages::mSize");
    static_assert(offsetof(CompilationInfo, messages) + CompilationInfomessagesSpan::GetOffsetOfData() == offsetof(WGPUCompilationInfo, messages),
                 "offsetof mismatch for CompilationInfo::messages::mData");

    bool CompilationInfo::operator==(const CompilationInfo& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (messages.size() != rhs.messages.size()) { return false; }
        if (messages.data() != rhs.messages.data()) { return false; }
        return true;
    }


    static_assert(sizeof(ComputePipelineDescriptor) == sizeof(WGPUComputePipelineDescriptor), "sizeof mismatch for ComputePipelineDescriptor");
    static_assert(alignof(ComputePipelineDescriptor) == alignof(WGPUComputePipelineDescriptor), "alignof mismatch for ComputePipelineDescriptor");

    static_assert(offsetof(ComputePipelineDescriptor, nextInChain) == offsetof(WGPUComputePipelineDescriptor, nextInChain),
            "offsetof mismatch for ComputePipelineDescriptor::nextInChain");
    static_assert(offsetof(ComputePipelineDescriptor, label) == offsetof(WGPUComputePipelineDescriptor, label),
                 "offsetof mismatch for ComputePipelineDescriptor::label");
    static_assert(offsetof(ComputePipelineDescriptor, layout) == offsetof(WGPUComputePipelineDescriptor, layout),
                 "offsetof mismatch for ComputePipelineDescriptor::layout");
    static_assert(offsetof(ComputePipelineDescriptor, compute) == offsetof(WGPUComputePipelineDescriptor, compute),
                 "offsetof mismatch for ComputePipelineDescriptor::compute");

    bool ComputePipelineDescriptor::operator==(const ComputePipelineDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (layout != rhs.layout) { return false; }
        if (compute != rhs.compute) { return false; }
        return true;
    }


    static_assert(sizeof(DawnFormatCapabilities) == sizeof(WGPUDawnFormatCapabilities), "sizeof mismatch for DawnFormatCapabilities");
    static_assert(alignof(DawnFormatCapabilities) == alignof(WGPUDawnFormatCapabilities), "alignof mismatch for DawnFormatCapabilities");

    static_assert(offsetof(DawnFormatCapabilities, nextInChain) == offsetof(WGPUDawnFormatCapabilities, nextInChain),
            "offsetof mismatch for DawnFormatCapabilities::nextInChain");

    bool DawnFormatCapabilities::operator==(const DawnFormatCapabilities& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        return true;
    }


    static_assert(sizeof(DeviceDescriptor) == sizeof(WGPUDeviceDescriptor), "sizeof mismatch for DeviceDescriptor");
    static_assert(alignof(DeviceDescriptor) == alignof(WGPUDeviceDescriptor), "alignof mismatch for DeviceDescriptor");

    static_assert(offsetof(DeviceDescriptor, nextInChain) == offsetof(WGPUDeviceDescriptor, nextInChain),
            "offsetof mismatch for DeviceDescriptor::nextInChain");
    static_assert(offsetof(DeviceDescriptor, label) == offsetof(WGPUDeviceDescriptor, label),
                 "offsetof mismatch for DeviceDescriptor::label");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using DeviceDescriptorrequiredFeaturesSpan = decltype(std::declval<DeviceDescriptor>().requiredFeatures);
    
    static_assert(offsetof(DeviceDescriptor, requiredFeatures) + DeviceDescriptorrequiredFeaturesSpan::GetOffsetOfSize() == offsetof(WGPUDeviceDescriptor, requiredFeatureCount),
                 "offsetof mismatch for DeviceDescriptor::requiredFeatures::mSize");
    static_assert(offsetof(DeviceDescriptor, requiredFeatures) + DeviceDescriptorrequiredFeaturesSpan::GetOffsetOfData() == offsetof(WGPUDeviceDescriptor, requiredFeatures),
                 "offsetof mismatch for DeviceDescriptor::requiredFeatures::mData");
    static_assert(offsetof(DeviceDescriptor, requiredLimits) == offsetof(WGPUDeviceDescriptor, requiredLimits),
                 "offsetof mismatch for DeviceDescriptor::requiredLimits");
    static_assert(offsetof(DeviceDescriptor, defaultQueue) == offsetof(WGPUDeviceDescriptor, defaultQueue),
                 "offsetof mismatch for DeviceDescriptor::defaultQueue");
    static_assert(offsetof(DeviceDescriptor, deviceLostCallbackInfo) == offsetof(WGPUDeviceDescriptor, deviceLostCallbackInfo),
                 "offsetof mismatch for DeviceDescriptor::deviceLostCallbackInfo");
    static_assert(offsetof(DeviceDescriptor, uncapturedErrorCallbackInfo) == offsetof(WGPUDeviceDescriptor, uncapturedErrorCallbackInfo),
                 "offsetof mismatch for DeviceDescriptor::uncapturedErrorCallbackInfo");

    bool DeviceDescriptor::operator==(const DeviceDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (requiredFeatures.size() != rhs.requiredFeatures.size()) { return false; }
        if (requiredFeatures.data() != rhs.requiredFeatures.data()) { return false; }
        if (requiredLimits != rhs.requiredLimits) { return false; }
        if (defaultQueue != rhs.defaultQueue) { return false; }
        return true;
    }


    static_assert(sizeof(PipelineLayoutDescriptor) == sizeof(WGPUPipelineLayoutDescriptor), "sizeof mismatch for PipelineLayoutDescriptor");
    static_assert(alignof(PipelineLayoutDescriptor) == alignof(WGPUPipelineLayoutDescriptor), "alignof mismatch for PipelineLayoutDescriptor");

    static_assert(offsetof(PipelineLayoutDescriptor, nextInChain) == offsetof(WGPUPipelineLayoutDescriptor, nextInChain),
            "offsetof mismatch for PipelineLayoutDescriptor::nextInChain");
    static_assert(offsetof(PipelineLayoutDescriptor, label) == offsetof(WGPUPipelineLayoutDescriptor, label),
                 "offsetof mismatch for PipelineLayoutDescriptor::label");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using PipelineLayoutDescriptorbindGroupLayoutsSpan = decltype(std::declval<PipelineLayoutDescriptor>().bindGroupLayouts);
    
    static_assert(offsetof(PipelineLayoutDescriptor, bindGroupLayouts) + PipelineLayoutDescriptorbindGroupLayoutsSpan::GetOffsetOfSize() == offsetof(WGPUPipelineLayoutDescriptor, bindGroupLayoutCount),
                 "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayouts::mSize");
    static_assert(offsetof(PipelineLayoutDescriptor, bindGroupLayouts) + PipelineLayoutDescriptorbindGroupLayoutsSpan::GetOffsetOfData() == offsetof(WGPUPipelineLayoutDescriptor, bindGroupLayouts),
                 "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayouts::mData");
    static_assert(offsetof(PipelineLayoutDescriptor, immediateSize) == offsetof(WGPUPipelineLayoutDescriptor, immediateSize),
                 "offsetof mismatch for PipelineLayoutDescriptor::immediateSize");

    bool PipelineLayoutDescriptor::operator==(const PipelineLayoutDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (bindGroupLayouts.size() != rhs.bindGroupLayouts.size()) { return false; }
        if (bindGroupLayouts.data() != rhs.bindGroupLayouts.data()) { return false; }
        if (immediateSize != rhs.immediateSize) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassPixelLocalStorage) == sizeof(WGPURenderPassPixelLocalStorage), "sizeof mismatch for RenderPassPixelLocalStorage");
    static_assert(alignof(RenderPassPixelLocalStorage) == alignof(WGPURenderPassPixelLocalStorage), "alignof mismatch for RenderPassPixelLocalStorage");

    static_assert(offsetof(RenderPassPixelLocalStorage, nextInChain) == offsetof(WGPURenderPassPixelLocalStorage, chain) + offsetof(WGPUChainedStruct, next),
            "offsetof mismatch for RenderPassPixelLocalStorage::nextInChain");
    static_assert(offsetof(RenderPassPixelLocalStorage, sType) == offsetof(WGPURenderPassPixelLocalStorage, chain) + offsetof(WGPUChainedStruct, sType),
            "offsetof mismatch for RenderPassPixelLocalStorage::sType");
    static_assert(offsetof(RenderPassPixelLocalStorage, totalPixelLocalStorageSize) == offsetof(WGPURenderPassPixelLocalStorage, totalPixelLocalStorageSize),
                 "offsetof mismatch for RenderPassPixelLocalStorage::totalPixelLocalStorageSize");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using RenderPassPixelLocalStoragestorageAttachmentsSpan = decltype(std::declval<RenderPassPixelLocalStorage>().storageAttachments);
    
    static_assert(offsetof(RenderPassPixelLocalStorage, storageAttachments) + RenderPassPixelLocalStoragestorageAttachmentsSpan::GetOffsetOfSize() == offsetof(WGPURenderPassPixelLocalStorage, storageAttachmentCount),
                 "offsetof mismatch for RenderPassPixelLocalStorage::storageAttachments::mSize");
    static_assert(offsetof(RenderPassPixelLocalStorage, storageAttachments) + RenderPassPixelLocalStoragestorageAttachmentsSpan::GetOffsetOfData() == offsetof(WGPURenderPassPixelLocalStorage, storageAttachments),
                 "offsetof mismatch for RenderPassPixelLocalStorage::storageAttachments::mData");

    bool RenderPassPixelLocalStorage::operator==(const RenderPassPixelLocalStorage& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (totalPixelLocalStorageSize != rhs.totalPixelLocalStorageSize) { return false; }
        if (storageAttachments.size() != rhs.storageAttachments.size()) { return false; }
        if (storageAttachments.data() != rhs.storageAttachments.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryDescriptor) == sizeof(WGPUSharedTextureMemoryDescriptor), "sizeof mismatch for SharedTextureMemoryDescriptor");
    static_assert(alignof(SharedTextureMemoryDescriptor) == alignof(WGPUSharedTextureMemoryDescriptor), "alignof mismatch for SharedTextureMemoryDescriptor");

    static_assert(offsetof(SharedTextureMemoryDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryDescriptor, nextInChain),
            "offsetof mismatch for SharedTextureMemoryDescriptor::nextInChain");
    static_assert(offsetof(SharedTextureMemoryDescriptor, label) == offsetof(WGPUSharedTextureMemoryDescriptor, label),
                 "offsetof mismatch for SharedTextureMemoryDescriptor::label");

    bool SharedTextureMemoryDescriptor::operator==(const SharedTextureMemoryDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryEndAccessState) == sizeof(WGPUSharedTextureMemoryEndAccessState), "sizeof mismatch for SharedTextureMemoryEndAccessState");
    static_assert(alignof(SharedTextureMemoryEndAccessState) == alignof(WGPUSharedTextureMemoryEndAccessState), "alignof mismatch for SharedTextureMemoryEndAccessState");

    static_assert(offsetof(SharedTextureMemoryEndAccessState, nextInChain) == offsetof(WGPUSharedTextureMemoryEndAccessState, nextInChain),
            "offsetof mismatch for SharedTextureMemoryEndAccessState::nextInChain");
    static_assert(offsetof(SharedTextureMemoryEndAccessState, initialized) == offsetof(WGPUSharedTextureMemoryEndAccessState, initialized),
                 "offsetof mismatch for SharedTextureMemoryEndAccessState::initialized");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedTextureMemoryEndAccessStatefencesSpan = decltype(std::declval<SharedTextureMemoryEndAccessState>().fences);
    
    static_assert(offsetof(SharedTextureMemoryEndAccessState, fences) + SharedTextureMemoryEndAccessStatefencesSpan::GetOffsetOfSize() == offsetof(WGPUSharedTextureMemoryEndAccessState, fenceCount),
                 "offsetof mismatch for SharedTextureMemoryEndAccessState::fences::mSize");
    static_assert(offsetof(SharedTextureMemoryEndAccessState, fences) + SharedTextureMemoryEndAccessStatefencesSpan::GetOffsetOfData() == offsetof(WGPUSharedTextureMemoryEndAccessState, fences),
                 "offsetof mismatch for SharedTextureMemoryEndAccessState::fences::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using SharedTextureMemoryEndAccessStatesignaledValuesSpan = decltype(std::declval<SharedTextureMemoryEndAccessState>().signaledValues);
    
    static_assert(offsetof(SharedTextureMemoryEndAccessState, signaledValues) + SharedTextureMemoryEndAccessStatesignaledValuesSpan::GetOffsetOfSize() == offsetof(WGPUSharedTextureMemoryEndAccessState, signaledValueCount),
                 "offsetof mismatch for SharedTextureMemoryEndAccessState::signaledValues::mSize");
    static_assert(offsetof(SharedTextureMemoryEndAccessState, signaledValues) + SharedTextureMemoryEndAccessStatesignaledValuesSpan::GetOffsetOfData() == offsetof(WGPUSharedTextureMemoryEndAccessState, signaledValues),
                 "offsetof mismatch for SharedTextureMemoryEndAccessState::signaledValues::mData");

    bool SharedTextureMemoryEndAccessState::operator==(const SharedTextureMemoryEndAccessState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (initialized != rhs.initialized) { return false; }
        if (fences.size() != rhs.fences.size()) { return false; }
        if (fences.data() != rhs.fences.data()) { return false; }
        if (signaledValues.size() != rhs.signaledValues.size()) { return false; }
        if (signaledValues.data() != rhs.signaledValues.data()) { return false; }
        return true;
    }


    static_assert(sizeof(SharedTextureMemoryProperties) == sizeof(WGPUSharedTextureMemoryProperties), "sizeof mismatch for SharedTextureMemoryProperties");
    static_assert(alignof(SharedTextureMemoryProperties) == alignof(WGPUSharedTextureMemoryProperties), "alignof mismatch for SharedTextureMemoryProperties");

    static_assert(offsetof(SharedTextureMemoryProperties, nextInChain) == offsetof(WGPUSharedTextureMemoryProperties, nextInChain),
            "offsetof mismatch for SharedTextureMemoryProperties::nextInChain");
    static_assert(offsetof(SharedTextureMemoryProperties, usage) == offsetof(WGPUSharedTextureMemoryProperties, usage),
                 "offsetof mismatch for SharedTextureMemoryProperties::usage");
    static_assert(offsetof(SharedTextureMemoryProperties, size) == offsetof(WGPUSharedTextureMemoryProperties, size),
                 "offsetof mismatch for SharedTextureMemoryProperties::size");
    static_assert(offsetof(SharedTextureMemoryProperties, format) == offsetof(WGPUSharedTextureMemoryProperties, format),
                 "offsetof mismatch for SharedTextureMemoryProperties::format");

    bool SharedTextureMemoryProperties::operator==(const SharedTextureMemoryProperties& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (usage != rhs.usage) { return false; }
        if (size != rhs.size) { return false; }
        if (format != rhs.format) { return false; }
        return true;
    }


    static_assert(sizeof(TextureViewDescriptor) == sizeof(WGPUTextureViewDescriptor), "sizeof mismatch for TextureViewDescriptor");
    static_assert(alignof(TextureViewDescriptor) == alignof(WGPUTextureViewDescriptor), "alignof mismatch for TextureViewDescriptor");

    static_assert(offsetof(TextureViewDescriptor, nextInChain) == offsetof(WGPUTextureViewDescriptor, nextInChain),
            "offsetof mismatch for TextureViewDescriptor::nextInChain");
    static_assert(offsetof(TextureViewDescriptor, label) == offsetof(WGPUTextureViewDescriptor, label),
                 "offsetof mismatch for TextureViewDescriptor::label");
    static_assert(offsetof(TextureViewDescriptor, format) == offsetof(WGPUTextureViewDescriptor, format),
                 "offsetof mismatch for TextureViewDescriptor::format");
    static_assert(offsetof(TextureViewDescriptor, dimension) == offsetof(WGPUTextureViewDescriptor, dimension),
                 "offsetof mismatch for TextureViewDescriptor::dimension");
    static_assert(offsetof(TextureViewDescriptor, baseMipLevel) == offsetof(WGPUTextureViewDescriptor, baseMipLevel),
                 "offsetof mismatch for TextureViewDescriptor::baseMipLevel");
    static_assert(offsetof(TextureViewDescriptor, mipLevelCount) == offsetof(WGPUTextureViewDescriptor, mipLevelCount),
                 "offsetof mismatch for TextureViewDescriptor::mipLevelCount");
    static_assert(offsetof(TextureViewDescriptor, baseArrayLayer) == offsetof(WGPUTextureViewDescriptor, baseArrayLayer),
                 "offsetof mismatch for TextureViewDescriptor::baseArrayLayer");
    static_assert(offsetof(TextureViewDescriptor, arrayLayerCount) == offsetof(WGPUTextureViewDescriptor, arrayLayerCount),
                 "offsetof mismatch for TextureViewDescriptor::arrayLayerCount");
    static_assert(offsetof(TextureViewDescriptor, aspect) == offsetof(WGPUTextureViewDescriptor, aspect),
                 "offsetof mismatch for TextureViewDescriptor::aspect");
    static_assert(offsetof(TextureViewDescriptor, usage) == offsetof(WGPUTextureViewDescriptor, usage),
                 "offsetof mismatch for TextureViewDescriptor::usage");

    TextureViewDescriptor TextureViewDescriptor::WithTrivialFrontendDefaults() const {
        TextureViewDescriptor copy;
        copy.nextInChain = nextInChain;
        copy.label = label;
        copy.format = format;
        copy.dimension = dimension;
        copy.baseMipLevel = baseMipLevel;
        copy.mipLevelCount = mipLevelCount;
        copy.baseArrayLayer = baseArrayLayer;
        copy.arrayLayerCount = arrayLayerCount;
        copy.aspect = (aspect == wgpu::TextureAspect::Undefined)
            ? wgpu::TextureAspect::All
            : aspect;
        copy.usage = usage;
        return copy;
    }
    bool TextureViewDescriptor::operator==(const TextureViewDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (format != rhs.format) { return false; }
        if (dimension != rhs.dimension) { return false; }
        if (baseMipLevel != rhs.baseMipLevel) { return false; }
        if (mipLevelCount != rhs.mipLevelCount) { return false; }
        if (baseArrayLayer != rhs.baseArrayLayer) { return false; }
        if (arrayLayerCount != rhs.arrayLayerCount) { return false; }
        if (aspect != rhs.aspect) { return false; }
        if (usage != rhs.usage) { return false; }
        return true;
    }


    static_assert(sizeof(VertexState) == sizeof(WGPUVertexState), "sizeof mismatch for VertexState");
    static_assert(alignof(VertexState) == alignof(WGPUVertexState), "alignof mismatch for VertexState");

    static_assert(offsetof(VertexState, nextInChain) == offsetof(WGPUVertexState, nextInChain),
            "offsetof mismatch for VertexState::nextInChain");
    static_assert(offsetof(VertexState, module) == offsetof(WGPUVertexState, module),
                 "offsetof mismatch for VertexState::module");
    static_assert(offsetof(VertexState, entryPoint) == offsetof(WGPUVertexState, entryPoint),
                 "offsetof mismatch for VertexState::entryPoint");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using VertexStateconstantsSpan = decltype(std::declval<VertexState>().constants);
    
    static_assert(offsetof(VertexState, constants) + VertexStateconstantsSpan::GetOffsetOfSize() == offsetof(WGPUVertexState, constantCount),
                 "offsetof mismatch for VertexState::constants::mSize");
    static_assert(offsetof(VertexState, constants) + VertexStateconstantsSpan::GetOffsetOfData() == offsetof(WGPUVertexState, constants),
                 "offsetof mismatch for VertexState::constants::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using VertexStatebuffersSpan = decltype(std::declval<VertexState>().buffers);
    
    static_assert(offsetof(VertexState, buffers) + VertexStatebuffersSpan::GetOffsetOfSize() == offsetof(WGPUVertexState, bufferCount),
                 "offsetof mismatch for VertexState::buffers::mSize");
    static_assert(offsetof(VertexState, buffers) + VertexStatebuffersSpan::GetOffsetOfData() == offsetof(WGPUVertexState, buffers),
                 "offsetof mismatch for VertexState::buffers::mData");

    bool VertexState::operator==(const VertexState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (module != rhs.module) { return false; }
        if (entryPoint != rhs.entryPoint) { return false; }
        if (constants.size() != rhs.constants.size()) { return false; }
        if (constants.data() != rhs.constants.data()) { return false; }
        if (buffers.size() != rhs.buffers.size()) { return false; }
        if (buffers.data() != rhs.buffers.data()) { return false; }
        return true;
    }


    static_assert(sizeof(FragmentState) == sizeof(WGPUFragmentState), "sizeof mismatch for FragmentState");
    static_assert(alignof(FragmentState) == alignof(WGPUFragmentState), "alignof mismatch for FragmentState");

    static_assert(offsetof(FragmentState, nextInChain) == offsetof(WGPUFragmentState, nextInChain),
            "offsetof mismatch for FragmentState::nextInChain");
    static_assert(offsetof(FragmentState, module) == offsetof(WGPUFragmentState, module),
                 "offsetof mismatch for FragmentState::module");
    static_assert(offsetof(FragmentState, entryPoint) == offsetof(WGPUFragmentState, entryPoint),
                 "offsetof mismatch for FragmentState::entryPoint");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using FragmentStateconstantsSpan = decltype(std::declval<FragmentState>().constants);
    
    static_assert(offsetof(FragmentState, constants) + FragmentStateconstantsSpan::GetOffsetOfSize() == offsetof(WGPUFragmentState, constantCount),
                 "offsetof mismatch for FragmentState::constants::mSize");
    static_assert(offsetof(FragmentState, constants) + FragmentStateconstantsSpan::GetOffsetOfData() == offsetof(WGPUFragmentState, constants),
                 "offsetof mismatch for FragmentState::constants::mData");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using FragmentStatetargetsSpan = decltype(std::declval<FragmentState>().targets);
    
    static_assert(offsetof(FragmentState, targets) + FragmentStatetargetsSpan::GetOffsetOfSize() == offsetof(WGPUFragmentState, targetCount),
                 "offsetof mismatch for FragmentState::targets::mSize");
    static_assert(offsetof(FragmentState, targets) + FragmentStatetargetsSpan::GetOffsetOfData() == offsetof(WGPUFragmentState, targets),
                 "offsetof mismatch for FragmentState::targets::mData");

    bool FragmentState::operator==(const FragmentState& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (module != rhs.module) { return false; }
        if (entryPoint != rhs.entryPoint) { return false; }
        if (constants.size() != rhs.constants.size()) { return false; }
        if (constants.data() != rhs.constants.data()) { return false; }
        if (targets.size() != rhs.targets.size()) { return false; }
        if (targets.data() != rhs.targets.data()) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPassDescriptor) == sizeof(WGPURenderPassDescriptor), "sizeof mismatch for RenderPassDescriptor");
    static_assert(alignof(RenderPassDescriptor) == alignof(WGPURenderPassDescriptor), "alignof mismatch for RenderPassDescriptor");

    static_assert(offsetof(RenderPassDescriptor, nextInChain) == offsetof(WGPURenderPassDescriptor, nextInChain),
            "offsetof mismatch for RenderPassDescriptor::nextInChain");
    static_assert(offsetof(RenderPassDescriptor, label) == offsetof(WGPURenderPassDescriptor, label),
                 "offsetof mismatch for RenderPassDescriptor::label");
    // TODO(https://crbug.com/524405497): Support fixed-length spans.
    using RenderPassDescriptorcolorAttachmentsSpan = decltype(std::declval<RenderPassDescriptor>().colorAttachments);
    
    static_assert(offsetof(RenderPassDescriptor, colorAttachments) + RenderPassDescriptorcolorAttachmentsSpan::GetOffsetOfSize() == offsetof(WGPURenderPassDescriptor, colorAttachmentCount),
                 "offsetof mismatch for RenderPassDescriptor::colorAttachments::mSize");
    static_assert(offsetof(RenderPassDescriptor, colorAttachments) + RenderPassDescriptorcolorAttachmentsSpan::GetOffsetOfData() == offsetof(WGPURenderPassDescriptor, colorAttachments),
                 "offsetof mismatch for RenderPassDescriptor::colorAttachments::mData");
    static_assert(offsetof(RenderPassDescriptor, depthStencilAttachment) == offsetof(WGPURenderPassDescriptor, depthStencilAttachment),
                 "offsetof mismatch for RenderPassDescriptor::depthStencilAttachment");
    static_assert(offsetof(RenderPassDescriptor, occlusionQuerySet) == offsetof(WGPURenderPassDescriptor, occlusionQuerySet),
                 "offsetof mismatch for RenderPassDescriptor::occlusionQuerySet");
    static_assert(offsetof(RenderPassDescriptor, timestampWrites) == offsetof(WGPURenderPassDescriptor, timestampWrites),
                 "offsetof mismatch for RenderPassDescriptor::timestampWrites");

    bool RenderPassDescriptor::operator==(const RenderPassDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (colorAttachments.size() != rhs.colorAttachments.size()) { return false; }
        if (colorAttachments.data() != rhs.colorAttachments.data()) { return false; }
        if (depthStencilAttachment != rhs.depthStencilAttachment) { return false; }
        if (occlusionQuerySet != rhs.occlusionQuerySet) { return false; }
        if (timestampWrites != rhs.timestampWrites) { return false; }
        return true;
    }


    static_assert(sizeof(RenderPipelineDescriptor) == sizeof(WGPURenderPipelineDescriptor), "sizeof mismatch for RenderPipelineDescriptor");
    static_assert(alignof(RenderPipelineDescriptor) == alignof(WGPURenderPipelineDescriptor), "alignof mismatch for RenderPipelineDescriptor");

    static_assert(offsetof(RenderPipelineDescriptor, nextInChain) == offsetof(WGPURenderPipelineDescriptor, nextInChain),
            "offsetof mismatch for RenderPipelineDescriptor::nextInChain");
    static_assert(offsetof(RenderPipelineDescriptor, label) == offsetof(WGPURenderPipelineDescriptor, label),
                 "offsetof mismatch for RenderPipelineDescriptor::label");
    static_assert(offsetof(RenderPipelineDescriptor, layout) == offsetof(WGPURenderPipelineDescriptor, layout),
                 "offsetof mismatch for RenderPipelineDescriptor::layout");
    static_assert(offsetof(RenderPipelineDescriptor, vertex) == offsetof(WGPURenderPipelineDescriptor, vertex),
                 "offsetof mismatch for RenderPipelineDescriptor::vertex");
    static_assert(offsetof(RenderPipelineDescriptor, primitive) == offsetof(WGPURenderPipelineDescriptor, primitive),
                 "offsetof mismatch for RenderPipelineDescriptor::primitive");
    static_assert(offsetof(RenderPipelineDescriptor, depthStencil) == offsetof(WGPURenderPipelineDescriptor, depthStencil),
                 "offsetof mismatch for RenderPipelineDescriptor::depthStencil");
    static_assert(offsetof(RenderPipelineDescriptor, multisample) == offsetof(WGPURenderPipelineDescriptor, multisample),
                 "offsetof mismatch for RenderPipelineDescriptor::multisample");
    static_assert(offsetof(RenderPipelineDescriptor, fragment) == offsetof(WGPURenderPipelineDescriptor, fragment),
                 "offsetof mismatch for RenderPipelineDescriptor::fragment");

    RenderPipelineDescriptor RenderPipelineDescriptor::WithTrivialFrontendDefaults() const {
        RenderPipelineDescriptor copy;
        copy.nextInChain = nextInChain;
        copy.label = label;
        copy.layout = layout;
        copy.vertex = vertex;
        copy.primitive = primitive.WithTrivialFrontendDefaults();
        copy.depthStencil = depthStencil;
        copy.multisample = multisample;
        copy.fragment = fragment;
        return copy;
    }
    bool RenderPipelineDescriptor::operator==(const RenderPipelineDescriptor& rhs) const {
if (nextInChain != rhs.nextInChain) { return false; }
        if (label != rhs.label) { return false; }
        if (layout != rhs.layout) { return false; }
        if (vertex != rhs.vertex) { return false; }
        if (primitive != rhs.primitive) { return false; }
        if (depthStencil != rhs.depthStencil) { return false; }
        if (multisample != rhs.multisample) { return false; }
        if (fragment != rhs.fragment) { return false; }
        return true;
    }

    // NOLINTEND(bugprone-invalid-enum-default-initialization)


    // SharedBufferMemoryEndAccessState
    SharedBufferMemoryEndAccessState::~SharedBufferMemoryEndAccessState() {
        FreeMembers();
    }

    SharedBufferMemoryEndAccessState::SharedBufferMemoryEndAccessState(SharedBufferMemoryEndAccessState&& rhs)
    : initialized(rhs.initialized),
      fences(rhs.fences),
      signaledValues(rhs.signaledValues){
        rhs.initialized = {};
        rhs.fences = {};
        rhs.signaledValues = {};
    }

    SharedBufferMemoryEndAccessState& SharedBufferMemoryEndAccessState::operator=(SharedBufferMemoryEndAccessState&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->initialized = std::move(rhs.initialized);
        this->fences = std::move(rhs.fences);
        this->signaledValues = std::move(rhs.signaledValues);
        rhs.initialized = {};
        rhs.fences = {};
        rhs.signaledValues = {};
        return *this;
    }

    void SharedBufferMemoryEndAccessState::FreeMembers() {
        bool needsFreeing = false;        if (!this->fences.empty()) { needsFreeing = true; }
        if (!this->signaledValues.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APISharedBufferMemoryEndAccessStateFreeMembers(*reinterpret_cast<WGPUSharedBufferMemoryEndAccessState*>(this));
        }
    }


    // SupportedFeatures
    SupportedFeatures::~SupportedFeatures() {
        FreeMembers();
    }

    SupportedFeatures::SupportedFeatures(SupportedFeatures&& rhs)
    : features(rhs.features){
        rhs.features = {};
    }

    SupportedFeatures& SupportedFeatures::operator=(SupportedFeatures&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->features = std::move(rhs.features);
        rhs.features = {};
        return *this;
    }

    void SupportedFeatures::FreeMembers() {
        bool needsFreeing = false;        if (!this->features.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APISupportedFeaturesFreeMembers(*reinterpret_cast<WGPUSupportedFeatures*>(this));
        }
    }


    // SupportedInstanceFeatures
    SupportedInstanceFeatures::~SupportedInstanceFeatures() {
        FreeMembers();
    }

    SupportedInstanceFeatures::SupportedInstanceFeatures(SupportedInstanceFeatures&& rhs)
    : features(rhs.features){
        rhs.features = {};
    }

    SupportedInstanceFeatures& SupportedInstanceFeatures::operator=(SupportedInstanceFeatures&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->features = std::move(rhs.features);
        rhs.features = {};
        return *this;
    }

    void SupportedInstanceFeatures::FreeMembers() {
        bool needsFreeing = false;        if (!this->features.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APISupportedInstanceFeaturesFreeMembers(*reinterpret_cast<WGPUSupportedInstanceFeatures*>(this));
        }
    }


    // SupportedWGSLLanguageFeatures
    SupportedWGSLLanguageFeatures::~SupportedWGSLLanguageFeatures() {
        FreeMembers();
    }

    SupportedWGSLLanguageFeatures::SupportedWGSLLanguageFeatures(SupportedWGSLLanguageFeatures&& rhs)
    : features(rhs.features){
        rhs.features = {};
    }

    SupportedWGSLLanguageFeatures& SupportedWGSLLanguageFeatures::operator=(SupportedWGSLLanguageFeatures&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->features = std::move(rhs.features);
        rhs.features = {};
        return *this;
    }

    void SupportedWGSLLanguageFeatures::FreeMembers() {
        bool needsFreeing = false;        if (!this->features.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APISupportedWGSLLanguageFeaturesFreeMembers(*reinterpret_cast<WGPUSupportedWGSLLanguageFeatures*>(this));
        }
    }


    // SurfaceCapabilities
    SurfaceCapabilities::~SurfaceCapabilities() {
        FreeMembers();
    }

    SurfaceCapabilities::SurfaceCapabilities(SurfaceCapabilities&& rhs)
    : usages(rhs.usages),
      formats(rhs.formats),
      presentModes(rhs.presentModes),
      alphaModes(rhs.alphaModes){
        rhs.usages = {};
        rhs.formats = {};
        rhs.presentModes = {};
        rhs.alphaModes = {};
    }

    SurfaceCapabilities& SurfaceCapabilities::operator=(SurfaceCapabilities&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->usages = std::move(rhs.usages);
        this->formats = std::move(rhs.formats);
        this->presentModes = std::move(rhs.presentModes);
        this->alphaModes = std::move(rhs.alphaModes);
        rhs.usages = {};
        rhs.formats = {};
        rhs.presentModes = {};
        rhs.alphaModes = {};
        return *this;
    }

    void SurfaceCapabilities::FreeMembers() {
        bool needsFreeing = false;        if (!this->formats.empty()) { needsFreeing = true; }
        if (!this->presentModes.empty()) { needsFreeing = true; }
        if (!this->alphaModes.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APISurfaceCapabilitiesFreeMembers(*reinterpret_cast<WGPUSurfaceCapabilities*>(this));
        }
    }


    // AdapterPropertiesMemoryHeaps
    AdapterPropertiesMemoryHeaps::~AdapterPropertiesMemoryHeaps() {
        FreeMembers();
    }

    AdapterPropertiesMemoryHeaps::AdapterPropertiesMemoryHeaps(AdapterPropertiesMemoryHeaps&& rhs)
    : heapInfo(rhs.heapInfo){
        rhs.heapInfo = {};
    }

    AdapterPropertiesMemoryHeaps& AdapterPropertiesMemoryHeaps::operator=(AdapterPropertiesMemoryHeaps&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->heapInfo = std::move(rhs.heapInfo);
        rhs.heapInfo = {};
        return *this;
    }

    void AdapterPropertiesMemoryHeaps::FreeMembers() {
        bool needsFreeing = false;        if (!this->heapInfo.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APIAdapterPropertiesMemoryHeapsFreeMembers(*reinterpret_cast<WGPUAdapterPropertiesMemoryHeaps*>(this));
        }
    }


    // AdapterPropertiesSubgroupMatrixConfigs
    AdapterPropertiesSubgroupMatrixConfigs::~AdapterPropertiesSubgroupMatrixConfigs() {
        FreeMembers();
    }

    AdapterPropertiesSubgroupMatrixConfigs::AdapterPropertiesSubgroupMatrixConfigs(AdapterPropertiesSubgroupMatrixConfigs&& rhs)
    : configs(rhs.configs){
        rhs.configs = {};
    }

    AdapterPropertiesSubgroupMatrixConfigs& AdapterPropertiesSubgroupMatrixConfigs::operator=(AdapterPropertiesSubgroupMatrixConfigs&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->configs = std::move(rhs.configs);
        rhs.configs = {};
        return *this;
    }

    void AdapterPropertiesSubgroupMatrixConfigs::FreeMembers() {
        bool needsFreeing = false;        if (!this->configs.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APIAdapterPropertiesSubgroupMatrixConfigsFreeMembers(*reinterpret_cast<WGPUAdapterPropertiesSubgroupMatrixConfigs*>(this));
        }
    }


    // DawnDrmFormatCapabilities
    DawnDrmFormatCapabilities::~DawnDrmFormatCapabilities() {
        FreeMembers();
    }

    DawnDrmFormatCapabilities::DawnDrmFormatCapabilities(DawnDrmFormatCapabilities&& rhs)
    : properties(rhs.properties){
        rhs.properties = {};
    }

    DawnDrmFormatCapabilities& DawnDrmFormatCapabilities::operator=(DawnDrmFormatCapabilities&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->properties = std::move(rhs.properties);
        rhs.properties = {};
        return *this;
    }

    void DawnDrmFormatCapabilities::FreeMembers() {
        bool needsFreeing = false;        if (!this->properties.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APIDawnDrmFormatCapabilitiesFreeMembers(*reinterpret_cast<WGPUDawnDrmFormatCapabilities*>(this));
        }
    }


    // AdapterInfo
    AdapterInfo::~AdapterInfo() {
        FreeMembers();
    }

    AdapterInfo::AdapterInfo(AdapterInfo&& rhs)
    : vendor(rhs.vendor),
      architecture(rhs.architecture),
      device(rhs.device),
      description(rhs.description),
      backendType(rhs.backendType),
      adapterType(rhs.adapterType),
      vendorID(rhs.vendorID),
      deviceID(rhs.deviceID),
      subgroupMinSize(rhs.subgroupMinSize),
      subgroupMaxSize(rhs.subgroupMaxSize){
        rhs.vendor = {};
        rhs.architecture = {};
        rhs.device = {};
        rhs.description = {};
        rhs.backendType = {};
        rhs.adapterType = {};
        rhs.vendorID = {};
        rhs.deviceID = {};
        rhs.subgroupMinSize = {};
        rhs.subgroupMaxSize = {};
    }

    AdapterInfo& AdapterInfo::operator=(AdapterInfo&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->vendor = std::move(rhs.vendor);
        this->architecture = std::move(rhs.architecture);
        this->device = std::move(rhs.device);
        this->description = std::move(rhs.description);
        this->backendType = std::move(rhs.backendType);
        this->adapterType = std::move(rhs.adapterType);
        this->vendorID = std::move(rhs.vendorID);
        this->deviceID = std::move(rhs.deviceID);
        this->subgroupMinSize = std::move(rhs.subgroupMinSize);
        this->subgroupMaxSize = std::move(rhs.subgroupMaxSize);
        rhs.vendor = {};
        rhs.architecture = {};
        rhs.device = {};
        rhs.description = {};
        rhs.backendType = {};
        rhs.adapterType = {};
        rhs.vendorID = {};
        rhs.deviceID = {};
        rhs.subgroupMinSize = {};
        rhs.subgroupMaxSize = {};
        return *this;
    }

    void AdapterInfo::FreeMembers() {
        bool needsFreeing = false;        if (this->vendor.data != nullptr) { needsFreeing = true; }        if (this->architecture.data != nullptr) { needsFreeing = true; }        if (this->device.data != nullptr) { needsFreeing = true; }        if (this->description.data != nullptr) { needsFreeing = true; }if (needsFreeing) {
            APIAdapterInfoFreeMembers(*reinterpret_cast<WGPUAdapterInfo*>(this));
        }
    }


    // SharedTextureMemoryEndAccessState
    SharedTextureMemoryEndAccessState::~SharedTextureMemoryEndAccessState() {
        FreeMembers();
    }

    SharedTextureMemoryEndAccessState::SharedTextureMemoryEndAccessState(SharedTextureMemoryEndAccessState&& rhs)
    : initialized(rhs.initialized),
      fences(rhs.fences),
      signaledValues(rhs.signaledValues){
        rhs.initialized = {};
        rhs.fences = {};
        rhs.signaledValues = {};
    }

    SharedTextureMemoryEndAccessState& SharedTextureMemoryEndAccessState::operator=(SharedTextureMemoryEndAccessState&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        FreeMembers();
        this->initialized = std::move(rhs.initialized);
        this->fences = std::move(rhs.fences);
        this->signaledValues = std::move(rhs.signaledValues);
        rhs.initialized = {};
        rhs.fences = {};
        rhs.signaledValues = {};
        return *this;
    }

    void SharedTextureMemoryEndAccessState::FreeMembers() {
        bool needsFreeing = false;        if (!this->fences.empty()) { needsFreeing = true; }
        if (!this->signaledValues.empty()) { needsFreeing = true; }
if (needsFreeing) {
            APISharedTextureMemoryEndAccessStateFreeMembers(*reinterpret_cast<WGPUSharedTextureMemoryEndAccessState*>(this));
        }
    }


} // namespace dawn::native
