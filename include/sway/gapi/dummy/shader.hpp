#ifndef SWAY_GAPI_DUMMY_SHADER_HPP
#define SWAY_GAPI_DUMMY_SHADER_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

/**
 * @brief Представление шейдерного объекта.
 *
 */
class Shader final : public AShaderBase {
public:
  static ShaderRef_t createInstance(const ShaderCreateInfo &createInfo);

  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] type Тип создаваемого шейдера.
   *
   */
  Shader(ShaderType_t type);

  /**
   * @brief Деструктор класса.
   * Освобождает захваченные ресурсы.
   *
   */
  virtual ~Shader();

  /**
   * @brief Выполняет компиляцию шейдерного объекта.
   *
   * @param[in] source Исходный код шейдера.
   *
   */
  virtual void compile(lpcstr_t source);

  /**
   * @brief Возвращает статус компиляции.
   *
   * @return Если компиляция прошла успешно 'true', иначе 'false'.
   *
   */
  virtual bool isCompiled() const;

  /**
   * @brief Получает тип шейдера.
   *
   * @return Тип шейдера.
   *
   */
  virtual auto getType() const -> ShaderType_t;

private:
  ShaderType_t type_; /*!< Тип шейдера. */
  bool compiled_;
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_SHADER_HPP
