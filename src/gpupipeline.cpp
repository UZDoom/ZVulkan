
#include "gpupipeline.h"
#include "gpubindgroup.h"
#include "gpudevice.h"
#include "vulkanbuilders.h"

GPUPipelineLayout::GPUPipelineLayout(GPUDevice* device, const GPUPipelineLayoutDesc& desc) : device(device), desc(desc)
{
	PipelineLayoutBuilder builder;
	layout = builder.Create(device->getVulkanDevice());
}

/////////////////////////////////////////////////////////////////////////////

GPUComputePipeline::GPUComputePipeline(GPUDevice* device, const GPUComputePipelineDesc& desc) : device(device), desc(desc)
{
	ComputePipelineBuilder builder;
	pipeline = builder.Create(device->getVulkanDevice());
}

std::shared_ptr<GPUBindGroupLayout> GPUComputePipeline::getBindLayout(int index)
{
	return desc.layout->desc.bindGroupLayouts[index];
}

/////////////////////////////////////////////////////////////////////////////

GPURenderPipeline::GPURenderPipeline(GPUDevice* device, const GPURenderPipelineDesc& desc) : device(device), desc(desc)
{
	GraphicsPipelineBuilder builder;
	pipeline = builder.Create(device->getVulkanDevice());
}

std::shared_ptr<GPUBindGroupLayout> GPURenderPipeline::getBindLayout(int index)
{
	return desc.layout->desc.bindGroupLayouts[index];
}
