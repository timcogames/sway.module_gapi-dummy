#ifndef SWAY_GAPI_DUMMY_VIEWPORT_HPP
#define SWAY_GAPI_DUMMY_VIEWPORT_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

class Viewport : public IViewportBase {
public:
  static auto createInstance() -> ViewportRef_t;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Viewport();

  /**
   * @brief Деструктор класса.
   */
  virtual ~Viewport() = default;

  /**
   * @brief Устанавливает новые значения прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   */
  MTHD_OVERRIDE(void set(s32_t x, s32_t y, s32_t w, s32_t h));

  /**
   * @brief Устанавливает размер прямоугольной области.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   */
  MTHD_OVERRIDE(void set(s32_t w, s32_t h));

  /**
   * @brief Получает размер прямоугольной области.
   */
  // clang-format off
  MTHD_OVERRIDE(auto get() const -> math::rect4i_t);  // clang-format on

  /**
   * @brief Получает соотношение сторон.
   */
  // clang-format off
  MTHD_OVERRIDE(auto aspect() const -> f32_t);  // clang-format on
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_VIEWPORT_HPP
