#include <sway/gapi/dummy/buffer.hpp>
#include <sway/gapi/dummy/drawcall.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

auto DrawCall::createInstance() -> DrawCallRef_t {
  auto instance = std::make_shared<DrawCall>();
  return instance;
}

void DrawCall::execute([[maybe_unused]] TopologyType_t topology, [[maybe_unused]] s32_t count,
    [[maybe_unused]] BufferRef_t ibo, [[maybe_unused]] core::detail::DataType_t type) {
  // Empty
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
