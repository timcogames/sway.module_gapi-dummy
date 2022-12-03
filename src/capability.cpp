#include <sway/gapi/dummy/capability.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

auto Capability::createInstance() -> CapabilityRef_t {
  auto instance = std::make_shared<Capability>();
  return instance;
}

Capability::Capability() {
  // Empty
}

Capability::~Capability() {
  // Empty
}

auto Capability::getVersion() const -> core::Version { return core::Version(); }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
