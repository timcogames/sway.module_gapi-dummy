#include <sway/gapi/dummy/shader.hpp>
#include <sway/gapi/dummy/shaderprogram.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

auto ShaderProgram::createInstance() -> ShaderProgramRef_t {
  auto instance = std::make_shared<ShaderProgram>();
  return instance;
}

ShaderProgram::ShaderProgram()
    : linked_(false)
    , validated_(false) {
  // Empty
}

ShaderProgram::~ShaderProgram() {
  // Empty
}

void ShaderProgram::attach([[maybe_unused]] ShaderRef_t shader) {
  // Empty
}

void ShaderProgram::detach([[maybe_unused]] u32_t attachedId) {
  // Empty
}

void ShaderProgram::link() { linked_ = true; }

bool ShaderProgram::isLinked() const { return linked_; }

void ShaderProgram::validate() { validated_ = true; }

bool ShaderProgram::isValidated() const { return validated_; }

void ShaderProgram::use() {
  // Empty
}

void ShaderProgram::unuse() {
  // Empty
}

bool ShaderProgram::isUsed() const { return false; }

void ShaderProgram::setUniformVec4f(
    [[maybe_unused]] const std::string &uniform, [[maybe_unused]] const math::vec4f_t &vec) {
  // Empty
}

void ShaderProgram::setUniformCol4f(
    [[maybe_unused]] const std::string &uniform, [[maybe_unused]] const math::col4f_t &col) {
  // Empty
}

NAMESPACE_END(gapi)
NAMESPACE_END(sway)
