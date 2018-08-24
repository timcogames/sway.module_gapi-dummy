# sway.module_gapi-dummy

## Клонирование проекта

```console
git clone --recursive https://github.com/timcogames/sway.module_gapi-dummy.git
```

## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

```console
cmake -DCMAKE_BUILD_TYPE=Release ../
```

Опция сборки | Описание | По умолчанию
:---|:---|:---:
`MODULE_GAPI_BUILD_SHARED` | Сборка библиотеки общего пользования | `OFF`

Запускаем сборку

```console
cmake --build .
```
