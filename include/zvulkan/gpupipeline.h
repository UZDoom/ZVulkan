#pragma once

#include <string>
#include <vector>
#include <memory>
#include "vulkanobjects.h"

class GPUDevice;
class GPUBindGroupLayout;

class GPUPipelineLayoutDesc
{
public:
	std::vector<std::shared_ptr<GPUBindGroupLayout>> bindGroupLayouts;
	std::string label;
};

class GPUPipelineLayout
{
public:
	GPUPipelineLayout(GPUDevice* device, const GPUPipelineLayoutDesc& desc);

	GPUDevice* device = nullptr;
	GPUPipelineLayoutDesc desc;

	std::unique_ptr<VulkanPipelineLayout> layout;
};

class GPUComputePipelineDesc
{
public:
	std::shared_ptr<GPUPipelineLayout> layout;
	// GPUComputeShaderDesc compute;
	std::string label;
};

class GPUComputePipeline
{
public:
	GPUComputePipeline(GPUDevice* device, const GPUComputePipelineDesc& desc);

	std::shared_ptr<GPUBindGroupLayout> getBindLayout(int index);

	GPUDevice* device = nullptr;
	GPUComputePipelineDesc desc;

	std::unique_ptr<VulkanPipeline> pipeline;
};

class GPURenderPipelineDesc
{
public:
	std::shared_ptr<GPUPipelineLayout> layout;
	// GPUDepthStencilDesc depthStencil;
	// GPUFragmentShaderDesc fragment;
	// GPUVertexShaderDesc vertex;
	// GPUMultisampleDesc multisample;
	// GPUPrimitiveDesc primitive;
	std::string label;
};

class GPURenderPipeline
{
public:
	GPURenderPipeline(GPUDevice* device, const GPURenderPipelineDesc& desc);

	std::shared_ptr<GPUBindGroupLayout> getBindLayout(int index);

	GPUDevice* device = nullptr;
	GPURenderPipelineDesc desc;

	std::unique_ptr<VulkanPipeline> pipeline;
};
