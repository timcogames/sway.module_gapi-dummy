#include <sway/gapi/dummy/drawcall.h>
#include <sway/gapi/dummy/buffer.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

DLLAPI_EXPORT DrawCallRef_t createDrawCall() {
	auto instance = boost::make_shared<DrawCall>();
	return instance;
}

void DrawCall::execute(PrimitiveType_t topology, s32_t count, BufferRef_t ibo, Type_t type) {
	boost::ignore_unused(topology);
	boost::ignore_unused(count);
	boost::ignore_unused(ibo);
	boost::ignore_unused(type);
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
