#include <sway/gapi/dummy/shader.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

ShaderRef_t Shader::createInstance(const ShaderCreateInfo & createInfo) {
	try {
		auto instance = std::make_shared<Shader>(createInfo.type);
		instance->compile(createInfo.code.c_str());
		return instance;
	}
	catch (std::exception & exception) {
		fprintf(stderr, "ERROR: %s shader object creation failed.\n", stringize(createInfo.type).c_str());
		throw;
	}
}

Shader::Shader(ShaderType_t type) : AShaderBase(type)
	, _type(type)
	, _compiled(false) {
	// Empty
}

Shader::~Shader() {
	// Empty
}

void Shader::compile(lpcstr_t source) {
	boost::ignore_unused(source);
	_compiled = true;
}

bool Shader::isCompiled() const {
	return _compiled;
}

ShaderType_t Shader::getType() const {
	return _type;
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
