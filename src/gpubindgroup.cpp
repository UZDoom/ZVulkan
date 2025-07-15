
#include "gpubindgroup.h"
#include "gpudevice.h"
#include "gpubuffer.h"
#include "gputexture.h"
#include "vulkanbuilders.h"

GPUBindGroup::GPUBindGroup(GPUDevice* device, const GPUBindGroupDesc& desc) : device(device), desc(desc)
{
	descriptorSet = desc.layout->pool->allocate(desc.layout->layout.get());

	WriteDescriptors writer;
	int index = 0;
	const auto& layoutBindings = desc.layout->desc.bindings;
	for (const GPUBindGroupBinding& binding : desc.bindings)
	{
		const GPUBindGroupLayoutBinding& bindingInfo = layoutBindings[index++];
		if (bindingInfo.type == GPUBindGroupLayoutBindingType::buffer)
		{
			if (bindingInfo.buffer.type == GPUBindGroupLayoutBufferType::uniform)
				writer.AddBuffer(descriptorSet.get(), binding.bindingIndex, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, binding.resource.buffer.buffer->buffer.get());
			else if (bindingInfo.buffer.type == GPUBindGroupLayoutBufferType::readOnlyStorage)
				writer.AddBuffer(descriptorSet.get(), binding.bindingIndex, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, binding.resource.buffer.buffer->buffer.get());
			else if (bindingInfo.buffer.type == GPUBindGroupLayoutBufferType::storage)
				writer.AddBuffer(descriptorSet.get(), binding.bindingIndex, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, binding.resource.buffer.buffer->buffer.get());
		}
		else if (bindingInfo.type == GPUBindGroupLayoutBindingType::texture)
		{
		}
		else if (bindingInfo.type == GPUBindGroupLayoutBindingType::sampler)
		{
		}
		else if (bindingInfo.type == GPUBindGroupLayoutBindingType::storageTexture)
		{
		}
		else if (bindingInfo.type == GPUBindGroupLayoutBindingType::externalTexture)
		{
		}
	}
	writer.Execute(device->getVulkanDevice());
}

/////////////////////////////////////////////////////////////////////////////

GPUBindGroupLayout::GPUBindGroupLayout(GPUDevice* device, const GPUBindGroupLayoutDesc& desc) : device(device), desc(desc)
{
	DescriptorSetLayoutBuilder builder;
	layout = builder.Create(device->getVulkanDevice());

	DescriptorPoolBuilder poolBuilder;
	pool = poolBuilder.Create(device->getVulkanDevice());
}
