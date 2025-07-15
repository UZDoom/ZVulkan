#pragma once

#include <memory>
#include "vulkanobjects.h"

class GPUDevice;
class GPUTextureView;

class GPUSamplerDesc
{
public:
};

class GPUSampler
{
public:
	GPUSampler(GPUDevice* device, const GPUSamplerDesc& desc);

	// no destroy

	GPUDevice* device = nullptr;
	GPUSamplerDesc desc;

	std::unique_ptr<VulkanSampler> sampler;
};

class GPUTextureDesc
{
public:
};

class GPUTexture
{
public:
	GPUTexture(GPUDevice* device, const GPUTextureDesc& desc);

	std::shared_ptr<GPUTextureView> createView();
	void destroy();

	GPUDevice* device = nullptr;
	GPUTextureDesc desc;

	std::unique_ptr<VulkanImage> image;
};

class GPUTextureView
{
public:
	GPUTextureView(GPUTexture* texture);

	// no destroy

	std::unique_ptr<VulkanImageView> view;
};

class GPUExternalTextureDesc
{
public:
};

class GPUExternalTexture
{
public:
	GPUExternalTexture(GPUDevice* device, const GPUExternalTextureDesc& desc);

	GPUDevice* device = nullptr;
	GPUExternalTextureDesc desc;
};
