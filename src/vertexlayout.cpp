#include <sway/gapi/dummy/vertexlayout.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

DLLAPI_EXPORT VertexLayoutRef_t createVertexLayout(ShaderProgramRef_t program) {
	auto instance = boost::make_shared<VertexLayout>(program);
	return instance;
}

VertexLayout::VertexLayout(ShaderProgramRef_t program) : IVertexLayoutBase(program) {
	// Empty
}

VertexLayout::~VertexLayout() {
	// Empty
}

void VertexLayout::addAttribute(VertexAttributeDescriptor desc) {
	boost::ignore_unused(desc);
}

void VertexLayout::enable() {
	// Empty
}

void VertexLayout::disable() {
	// Empty
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
