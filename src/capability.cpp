#include <sway/gapi/dummy/capability.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

DLLAPI_EXPORT CapabilityRef_t createCapability() {
	auto instance = boost::make_shared<Capability>();
	return instance;
}

Capability::Capability() {
	// Empty
}

Capability::~Capability() {
	// Empty
}

core::Version Capability::getVersion() const {
	return core::Version();
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
