#include <sway/gapi/dummy/drawcall.h>
#include <sway/gapi/dummy/buffer.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

DrawCallRef_t DrawCall::createInstance() {
	auto instance = std::make_shared<DrawCall>();
	return instance;
}

void DrawCall::execute(TopologyType_t topology, s32_t count, BufferRef_t ibo, core::detail::DataType_t type) {
	boost::ignore_unused(topology);
	boost::ignore_unused(count);
	boost::ignore_unused(ibo);
	boost::ignore_unused(type);
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
