#include <sway/gapi/dummy/viewport.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

DLLAPI_EXPORT ViewportRef_t createViewport() {
	auto instance = boost::make_shared<Viewport>();
	return instance;
}

Viewport::Viewport() {
	// Empty
}

void Viewport::set(s32_t x, s32_t y, s32_t w, s32_t h) {
	boost::ignore_unused(x);
	boost::ignore_unused(y);
	boost::ignore_unused(w);
	boost::ignore_unused(h);
}

void Viewport::set(s32_t w, s32_t h) {
	set(0, 0, w, h);
}

math::rect4i_t Viewport::get() const {
	return math::TRect<s32_t>();
}

f32_t Viewport::aspect() const {
	return 0.0f;
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
