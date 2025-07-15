
#include "gputexture.h"
#include "gpudevice.h"
#include "vulkanbuilders.h"

GPUSampler::GPUSampler(GPUDevice* device, const GPUSamplerDesc& desc) : device(device), desc(desc)
{
	SamplerBuilder builder;
	sampler = builder.Create(device->getVulkanDevice());
}

/////////////////////////////////////////////////////////////////////////////

GPUTexture::GPUTexture(GPUDevice* device, const GPUTextureDesc& desc) : device(device), desc(desc)
{
	ImageBuilder builder;
	image = builder.Create(device->getVulkanDevice());
}

std::shared_ptr<GPUTextureView> GPUTexture::createView()
{
	return std::make_shared<GPUTextureView>(this);
}

void GPUTexture::destroy()
{
}

/////////////////////////////////////////////////////////////////////////////

GPUTextureView::GPUTextureView(GPUTexture* texture)
{
	ImageViewBuilder builder;
	view = builder.Create(texture->device->getVulkanDevice());
}

/////////////////////////////////////////////////////////////////////////////

GPUExternalTexture::GPUExternalTexture(GPUDevice* device, const GPUExternalTextureDesc& desc) : device(device), desc(desc)
{
}
