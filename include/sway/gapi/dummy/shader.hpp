#ifndef SWAY_GAPI_DUMMY_SHADER_HPP
#define SWAY_GAPI_DUMMY_SHADER_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

/**
 * @brief Представление шейдерного объекта.
 */
class Shader final : public ShaderBase {
public:
  static auto createInstance(const ShaderCreateInfo &createInfo) -> ShaderRef_t;

  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] type Тип создаваемого шейдера.
   */
  Shader(ShaderType_t type);

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
  virtual ~Shader();

  /**
   * @brief Выполняет компиляцию шейдерного объекта.
   *
   * @param[in] source Исходный код шейдера.
   */
  MTHD_OVERRIDE(void compile(lpcstr_t source));

  /**
   * @brief Возвращает статус компиляции.
   *
   * @return Если компиляция прошла успешно 'true', иначе 'false'.
   */
  // clang-format off
  MTHD_OVERRIDE(auto isCompiled() const -> bool);  // clang-format on

  /**
   * @brief Получает тип шейдера.
   *
   * @return Тип шейдера.
   */
  // clang-format off
  MTHD_OVERRIDE(auto getType() const -> ShaderType_t);  // clang-format on

private:
  ShaderType_t type_;  // Тип шейдера.
  bool compiled_;
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_SHADER_HPP
