#ifndef SWAY_GAPI_DUMMY_BUFFER_HPP
#define SWAY_GAPI_DUMMY_BUFFER_HPP

#include <sway/gapi/dummy/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

/**
 * @brief Представление аппаратного буфера.
 *
 */
class Buffer final : public ABufferBase {
public:
  static BufferRef_t createInstance(const BufferCreateInfo &createInfo);

  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса.
   *
   */
  Buffer(const BufferDescriptor &desc);

  /**
   * @brief Деструктор класса.
   * Освобождает захваченные ресурсы.
   *
   */
  virtual ~Buffer();

  /**
   * @brief Устанавливает данные в аппаратный буфер.
   *
   * @param[in] data Первоначальный данные.
   *
   */
  virtual bool allocate(const void *data);

  /**
   * @brief Изменяет данные в уже существующем буфере.
   *
   * @param[in] offset Начало изменяемого блока данных.
   * @param[in] size Размер изменяемого блока данных.
   * @param[in] source Область памяти, содержащая новые значения.
   *
   * @sa updateSubdata(const void *)
   *
   */
  virtual void updateSubdata(u32_t offset, u32_t size, const void *source);

  /**
   * @brief Изменяет данные в уже существующем буфере.
   *
   * @param[in] source Область памяти, содержащая новые значения.
   *
   * @sa updateSubdata(u32_t, u32_t, const void *)
   *
   */
  virtual void updateSubdata(const void *source);

  /**
   * @brief Получает указатель на область памяти, в которой находятся данные буфера.
   *
   * @sa unmap()
   *
   */
  virtual auto map() -> void *;

  /**
   * @brief Возвращает данные буфера в память.
   *
   * @sa map()
   *
   */
  virtual void unmap();

  /**
   * @brief Делает буфер текущим.
   *
   * @sa unbind()
   *
   */
  virtual void bind();

  /**
   * @brief Делает текущим пустой буфер.
   *
   * @sa bind()
   *
   */
  virtual void unbind();

  /**
   * @brief Получает целевой тип буфера.
   *
   */
  virtual auto getTarget() const -> BufferTarget_t;

  /**
   * @brief Получает режим работы с данными.
   *
   */
  virtual auto getUsage() const -> BufferUsage_t;

  /**
   * @brief Получает количество элементов в массиве.
   *
   */
  virtual auto getCapacity() const -> s32_t;

  /**
   * @brief Получает размер структуры данных.
   *
   */
  virtual auto getByteStride() const -> s32_t;

private:
  BufferTarget_t target_;
  BufferUsage_t usage_;
  s32_t capacity_;
  s32_t byteStride_;
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif  // SWAY_GAPI_DUMMY_BUFFER_HPP
