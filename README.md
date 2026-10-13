# Стек

Отдельный CMake-проект с реализацией стека. Элементы извлекаются в порядке LIFO: последним добавлен — первым извлечён.

## Сборка и проверка

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

`StackApp` показывает работу основных операций. `StackTests` проверяет поведение структуры.
