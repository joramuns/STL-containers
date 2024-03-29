# STL Containers Implementation

## Описание проекта

Данный проект представляет собой реализацию контейнеров стандартной библиотеки шаблонов (STL) на языке программирования C++ с использованием стандарта C++17. Основной фокус проекта - предоставление высокоэффективных и надежных контейнеров для обработки данных.

## Особенности

- Использование C++17: Проект разработан с использованием последних стандартов C++ для обеспечения максимальной производительности и совместимости.
- Контейнеры STL: **array, vector, list, queue, stack, map, set, multiset**
- Красно-черное дерево: Реализация красно-черного дерева для эффективного поиска в контейнерах map, set, multiset.
- Покрытие тестами: Проект содержит обширный набор тестов для обеспечения надежности и стабильности контейнеров.
- В проекте реализовано графическое отображение покрытия функций с помощью утилиты **lcov** : ```make gcov_report```.

## Сборка проекта

Для сборки и тестирования проекта используется Makefile. Вы можете скомпилировать проект, используя следующую команду:
```make test```

## Docker

Сборка в контейнере Ubuntu с помощью скрипта ```run.sh```, который собирает образ, запускает контейнер и запускает тесты библиотеки через динамический анализатор кода Valgrind.
