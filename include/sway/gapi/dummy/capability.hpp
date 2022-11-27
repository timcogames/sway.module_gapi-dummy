#ifndef SWAY_GAPI_DUMMY_CAPABILITY_HPP
#define SWAY_GAPI_DUMMY_CAPABILITY_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

class Capability : public ICapabilityBase {
public:
  static auto createInstance() -> CapabilityRef_t;

  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса.
   *
   */
  Capability();

  /**
   * @brief Деструктор класса.
   *
   */
  virtual ~Capability();

  /**
   * @brief Возвращает версию OpenGL.
   *
   */
  virtual auto getVersion() const -> core::Version;
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_CAPABILITY_HPP
