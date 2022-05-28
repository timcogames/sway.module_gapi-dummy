#ifndef SWAY_GAPI_DUMMY_CAPABILITY_HPP
#define SWAY_GAPI_DUMMY_CAPABILITY_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

class Capability : public ICapabilityBase {
public:
  static CapabilityRef_t createInstance();

  /*!
   * \brief
   *    Конструктор класса.
   *    Выполняет инициализацию нового экземпляра класса.
   */
  Capability();

  /*!
   * \brief
   *    Деструктор класса.
   */
  virtual ~Capability();

  /*!
   * \brief
   *    Возвращает версию OpenGL.
   */
  virtual core::Version getVersion() const;
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif
