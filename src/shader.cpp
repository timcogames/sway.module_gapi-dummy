#include <sway/gapi/dummy/shader.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

ShaderRef_t Shader::createInstance(const ShaderCreateInfo &createInfo) {
  try {
    auto instance = std::make_shared<Shader>(createInfo.type);
    instance->compile(createInfo.code.c_str());
    return instance;
  } catch (std::exception &exception) {
    fprintf(stderr, "ERROR: %s shader object creation failed.\n", stringize(createInfo.type).c_str());
    throw;
  }
}

Shader::Shader(ShaderType_t type)
    : AShaderBase(type)
    , type_(type)
    , compiled_(false) {
  // Empty
}

Shader::~Shader() {
  // Empty
}

void Shader::compile([[maybe_unused]] lpcstr_t source) { compiled_ = true; }

bool Shader::isCompiled() const { return compiled_; }

ShaderType_t Shader::getType() const { return type_; }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
