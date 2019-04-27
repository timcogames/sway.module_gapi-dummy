#ifndef SWAY_GAPI_DUMMY_DRAWCALL_H
#define SWAY_GAPI_DUMMY_DRAWCALL_H

#include <sway/gapi/dummy/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(gapi)

class DrawCall : public IDrawCallBase {
public:
	static DrawCallRef_t createInstance();
	
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	DrawCall() {
		// Empty
	}

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	virtual ~DrawCall() {
		// Empty
	}

	/*!
	 * \brief
	 *    Выполняет отрисовку примитива.
	 * 
	 * \param[in] topology
	 *    Топология примитива.
	 * 
	 * \param[in] count
	 *    Количество отображаемых элементов.
	 * 
	 * \param[in] ibo
	 *    Указатель на буфер индексов.
	 * 
	 * \param[in] type
	 *    Тип значений в индексах.
	 */
	virtual void execute(PrimitiveType_t topology, s32_t count, BufferRef_t ibo, core::detail::DataType_t type);
};

NAMESPACE_END(gapi)
NAMESPACE_END(sway)

#endif // SWAY_GAPI_DUMMY_DRAWCALL_H
