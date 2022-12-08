#ifndef SWAY_GAPI_DUMMY_DRAWCALL_HPP
#define SWAY_GAPI_DUMMY_DRAWCALL_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

class DrawCall : public IDrawCallBase {
public:
  static auto createInstance() -> DrawCallRef_t;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  DrawCall() {
    // Empty
  }

  /**
   * @brief Деструктор класса.
   */
  virtual ~DrawCall() {
    // Empty
  }

  /**
   * @brief Выполняет отрисовку примитива.
   *
   * @param[in] topology Топология примитива.
   * @param[in] bufset Набор буферных объектов.
   * @param[in] type Тип значений в индексах.
   */
  MTHD_OVERRIDE(void execute(TopologyType_t topology, BufferSet bufset, core::ValueDataType type));
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_DRAWCALL_HPP
