#include <sway/gapi/dummy/capability.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

CapabilityRef_t Capability::createInstance() {
  auto instance = std::make_shared<Capability>();
  return instance;
}

Capability::Capability() {
  // Empty
}

Capability::~Capability() {
  // Empty
}

core::Version Capability::getVersion() const { return core::Version(); }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
