#ifndef SWAY_GAPI_DUMMY_BUFFER_HPP
#define SWAY_GAPI_DUMMY_BUFFER_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

/**
 * @brief Представление аппаратного буфера.
 */
class Buffer final : public BufferBase {
public:
  static auto createInstance(BufferIdQueueRef_t idQueue, const BufferCreateInfo &createInfo) -> BufferRef_t;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Buffer(BufferIdQueueRef_t idQueue, const BufferDescriptor &desc);

  /**
   * @brief Деструктор класса.
   *        Освобождает захваченные ресурсы.
   */
  virtual ~Buffer();

  /**
   * @brief Устанавливает данные в аппаратный буфер.
   *
   * @param[in] data Первоначальный данные.
   */
  MTHD_OVERRIDE(bool allocate(const void *data));

  /**
   * @brief Изменяет данные в уже существующем буфере.
   *
   * @param[in] offset Начало изменяемого блока данных.
   * @param[in] size Размер изменяемого блока данных.
   * @param[in] source Область памяти, содержащая новые значения.
   * @sa updateSubdata(const void *)
   */
  MTHD_OVERRIDE(void updateSubdata(u32_t offset, u32_t size, const void *source));

  /**
   * @brief Изменяет данные в уже существующем буфере.
   *
   * @param[in] source Область памяти, содержащая новые значения.
   * @sa updateSubdata(u32_t, u32_t, const void *)
   */
  MTHD_OVERRIDE(void updateSubdata(const void *source));

  /**
   * @brief Получает указатель на область памяти, в которой находятся данные буфера.
   *
   * @sa unmap()
   */
  // clang-format off
  MTHD_OVERRIDE(auto map() -> void *);  // clang-format on

  /**
   * @brief Возвращает данные буфера в память.
   *
   * @sa map()
   */
  MTHD_OVERRIDE(void unmap());

  /**
   * @brief Делает буфер текущим.
   *
   * @sa unbind()
   */
  MTHD_OVERRIDE(void bind());

  /**
   * @brief Делает текущим пустой буфер.
   *
   * @sa bind()
   */
  MTHD_OVERRIDE(void unbind());

  /**
   * @brief Получает целевой тип буфера.
   */
  // clang-format off
  MTHD_OVERRIDE(auto getTarget() const -> BufferTarget_t);  // clang-format on

  /**
   * @brief Получает режим работы с данными.
   */
  // clang-format off
  MTHD_OVERRIDE(auto getUsage() const -> BufferUsage_t);  // clang-format on

  /**
   * @brief Получает количество элементов в массиве.
   */
  // clang-format off
  MTHD_OVERRIDE(auto getCapacity() const -> s32_t);  // clang-format on

  /**
   * @brief Получает размер структуры данных.
   */
  // clang-format off
  MTHD_OVERRIDE(auto getByteStride() const -> s32_t);  // clang-format on

private:
  BufferTarget_t target_;
  BufferUsage_t usage_;
  s32_t capacity_;
  s32_t byteStride_;
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_BUFFER_HPP
