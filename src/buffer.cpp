#include <sway/gapi/dummy/buffer.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

auto Buffer::createInstance(const BufferCreateInfo &createInfo) -> BufferRef_t {
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

auto Buffer::map() -> void * { return nullptr; }

void Buffer::unmap() {
  // Empty
}

void Buffer::bind() {
  // Empty
}

void Buffer::unbind() {
  // Empty
}

auto Buffer::getTarget() const -> BufferTarget_t { return target_; }

auto Buffer::getUsage() const -> BufferUsage_t { return usage_; }

auto Buffer::getCapacity() const -> s32_t { return capacity_; }

auto Buffer::getByteStride() const -> s32_t { return byteStride_; }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
