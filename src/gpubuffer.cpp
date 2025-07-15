
#include "gpubuffer.h"
#include "gpucommands.h"
#include "gpudevice.h"
#include "vulkanbuilders.h"

GPUBuffer::GPUBuffer(GPUDevice* device, const GPUBufferDesc& desc) : device(device), desc(desc)
{
	BufferBuilder builder;
	buffer = builder.Create(device->getVulkanDevice());
}

GPUPromise GPUBuffer::mapAsync()
{
	return {};
}

void GPUBuffer::unmap()
{
}

void GPUBuffer::destroy()
{
}
