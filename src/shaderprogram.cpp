#include <sway/gapi/dummy/shaderprogram.h>
#include <sway/gapi/dummy/shader.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

DLLAPI_EXPORT ShaderProgramRef_t createShaderProgram() {
	auto instance = boost::make_shared<ShaderProgram>();
	return instance;
}

ShaderProgram::ShaderProgram()
	: _linked(false)
	, _validated(false) {
	// Empty
}

ShaderProgram::~ShaderProgram() {
	// Empty
}

void ShaderProgram::attach(ShaderRef_t shader) {
	boost::ignore_unused(shader);
}

void ShaderProgram::detach(u32_t attachedId) {
	boost::ignore_unused(attachedId);
}

void ShaderProgram::link() {
	_linked = true;
}

bool ShaderProgram::isLinked() const {
	return _linked;
}

void ShaderProgram::validate() {
	_validated = true;
}

bool ShaderProgram::isValidated() const {
	return _validated;
}

void ShaderProgram::use() {
	// Empty
}

void ShaderProgram::unuse() {
	// Empty
}

bool ShaderProgram::isUsed() const {
	return false;
}

void ShaderProgram::setUniformVec4f(const std::string & uniform, const math::vec4f_t & vec) {
	boost::ignore_unused(uniform);
	boost::ignore_unused(vec);
}

void ShaderProgram::setUniformCol4f(const std::string & uniform, const math::col4f_t & col) {
	boost::ignore_unused(uniform);
	boost::ignore_unused(col);
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
