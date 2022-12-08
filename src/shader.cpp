#include <sway/gapi/dummy/shader.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

auto Shader::createInstance(const ShaderCreateInfo &createInfo) -> ShaderRef_t {
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
    : ShaderBase(type)
    , type_(type)
    , compiled_(false) {
  // Empty
}

Shader::~Shader() {
  // Empty
}

void Shader::compile([[maybe_unused]] lpcstr_t source) { compiled_ = true; }

auto Shader::isCompiled() const -> bool { return compiled_; }

auto Shader::getType() const -> ShaderType_t { return type_; }

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
