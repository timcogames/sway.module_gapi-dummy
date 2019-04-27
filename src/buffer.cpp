#include <sway/gapi/dummy/buffer.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

BufferRef_t Buffer::createInstance(const BufferCreateInfo & createInfo) {
	auto instance = std::make_shared<Buffer>(createInfo.desc);
	if (instance->allocate(createInfo.data))
		return instance;

	return nullptr;
}

Buffer::Buffer(const BufferDescriptor & desc) : ABufferBase(desc)
	, _target(desc.target)
	, _usage(desc.usage)
	, _byteStride(desc.byteStride)
	, _capacity(desc.capacity) {
	// Empty
}

Buffer::~Buffer() {
	// Empty
}

bool Buffer::allocate(const void * data) {
	boost::ignore_unused(data);
	return true;
}

void Buffer::updateSubdata(u32_t offset, u32_t size, const void * source) {
	boost::ignore_unused(offset);
	boost::ignore_unused(size);
	boost::ignore_unused(source);
}

void Buffer::updateSubdata(const void * source) {
	boost::ignore_unused(source);
}

void * Buffer::map() {
	return NULL;
}

void Buffer::unmap() {
	// Empty
}

void Buffer::bind() {
	// Empty
}

void Buffer::unbind() {
	// Empty
}

BufferTarget_t Buffer::getTarget() const {
	return _target;
}

BufferUsage_t Buffer::getUsage() const {
	return _usage;
}

s32_t Buffer::getCapacity() const {
	return _capacity;
}

s32_t Buffer::getByteStride() const {
	return _byteStride;
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
