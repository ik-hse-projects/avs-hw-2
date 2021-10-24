# АВС, задание 2

- **Автор**: Коннов Илья (@iliakonnov), БПИ201
- **Вариант**: 16

## Задание
Прочитать простые геометрические фигуры с цветом, отсортировать их по периметру при помощи straight sort и вывести.

# Компиляция и запуск
```bash
./build.sh -DCMAKE_BUILD_TYPE=Release && ./build/AVS2
```

# Использование
См. `AVS2 -h`

# Архитектура

Параметры компьютера:

- **Процессор:**  AMD Athlon(tm) X4 750K Quad Core Processor
- **ОС:** NixOS 21.11.git.e83b22e2a36
- **Kernel:** `Linux 5.10.69 x86_64`

## Использование памяти

- Базовые типы:
    * `size_t`, `*T` - 8
    * `unsigned int`, `int` - 4
    * `char` - 1
    * Небольшие перечисления компилируются как `int` в моём случае.

- `class Color`
    - `Value value` — 4 (0)

- `class Point`
    * `int x` – 4 (0)
    * `int y` — 4 (4)
    * Итого: 8

- `class Shape`
    * `Color color` — 4

- `class Circle : Shape`
    * `point` — 8 (0)
    * `int radius` – 4 (8)
    * Итого: 12

- `class Rectangle : Shape`
    * `Point left_upper` — 8 (0)
    * `Point right_bottom` – 8 (8)
    * Итого: 16

- `class Triangle : Shape`
    * `Point a` — 8 (0)
    * `Point b` – 8 (8)
    * `Point c` – 8 (16)
    * Итого: 24

- `class Buffer`
    * Всего: 0

- `class Stream : Buffer`
    * `std::istream& stream` — 8 (0)
    * Итого: 8

- `class Randomized : Buffer`
    * Итого: 0

# Модули
По одному модулю (`.c` + `.h`) на каждую структуру, получаем 8 модулей. Плюс точка входа `main.c`
