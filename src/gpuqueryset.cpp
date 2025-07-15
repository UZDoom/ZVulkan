
#include "gpuqueryset.h"
#include "gpudevice.h"
#include "vulkanbuilders.h"

GPUQuerySet::GPUQuerySet(GPUDevice* device, const GPUQuerySetDesc& desc) : device(device), desc(desc)
{
	QueryPoolBuilder builder;
	queryPool = builder.Create(device->getVulkanDevice());
}

void GPUQuerySet::destroy()
{
}
