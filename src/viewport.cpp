#include <sway/gapi/dummy/viewport.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

auto Viewport::createInstance() -> ViewportRef_t {
  auto instance = std::make_shared<Viewport>();
  return instance;
}

Viewport::Viewport() {
  // Empty
}

void Viewport::set(
    [[maybe_unused]] s32_t x, [[maybe_unused]] s32_t y, [[maybe_unused]] s32_t w, [[maybe_unused]] s32_t h) {
  // Empty
}

void Viewport::set(s32_t w, s32_t h) { set(0, 0, w, h); }

auto Viewport::get() const -> math::rect4i_t { return math::TRect<s32_t>(); }

auto Viewport::aspect() const -> f32_t { return 0.0f; }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
