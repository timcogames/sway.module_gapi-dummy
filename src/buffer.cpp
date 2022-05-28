#include <sway/gapi/dummy/buffer.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

BufferRef_t Buffer::createInstance(const BufferCreateInfo &createInfo) {
  auto instance = std::make_shared<Buffer>(createInfo.desc);
  if (instance->allocate(createInfo.data)) {
    return instance;
  }

  return nullptr;
}

Buffer::Buffer(const BufferDescriptor &desc)
    : ABufferBase(desc)
    , target_(desc.target)
    , usage_(desc.usage)
    , byteStride_(desc.byteStride)
    , capacity_(desc.capacity) {
  // Empty
}

Buffer::~Buffer() {
  // Empty
}

bool Buffer::allocate([[maybe_unused]] const void *data) { return true; }

void Buffer::updateSubdata(
    [[maybe_unused]] u32_t offset, [[maybe_unused]] u32_t size, [[maybe_unused]] const void *source) {
  // Empty
}

void Buffer::updateSubdata([[maybe_unused]] const void *source) {
  // Empty
}

void *Buffer::map() { return nullptr; }

void Buffer::unmap() {
  // Empty
}

void Buffer::bind() {
  // Empty
}

void Buffer::unbind() {
  // Empty
}

BufferTarget_t Buffer::getTarget() const { return target_; }

BufferUsage_t Buffer::getUsage() const { return usage_; }

s32_t Buffer::getCapacity() const { return capacity_; }

s32_t Buffer::getByteStride() const { return byteStride_; }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
