#include <sway/gapi/dummy/vertexlayout.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

VertexLayoutRef_t VertexLayout::createInstance(ShaderProgramRef_t program) {
  auto instance = std::make_shared<VertexLayout>(program);
  return instance;
}

VertexLayout::VertexLayout(ShaderProgramRef_t program)
    : IVertexLayoutBase(program) {
  // Empty
}

VertexLayout::~VertexLayout() {
  // Empty
}

void VertexLayout::addAttribute([[maybe_unused]] VertexAttributeDescriptor desc) {
  // Empty
}

void VertexLayout::enable() {
  // Empty
}

void VertexLayout::disable() {
  // Empty
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
