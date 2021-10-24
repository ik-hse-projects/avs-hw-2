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

- **Процессор:**  Intel(R) Core(TM) i5 CPU M 560 @ 2.67GHz
- **ОС:** Arch Linux
- **Kernel:** `Linux 5.14.14-arch1-1 x86_64`

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
По одному модулю (`.cpp` + `.h`) на каждый тип, получаем 7 модулей. Плюс драйвер `main.cpp`

# Производительность
```
> AVS2 -f /tmp/tests/1000.in -o /tmp/tests/1000.out
Executed in   30.38 millis

> AVS2 -f /tmp/tests/5000.in -o /tmp/tests/5000.out
Executed in    523.23 millis

>  ./build/AVS2 -f /tmp/tests/10000.in -o /tmp/tests/10000.out
Executed in    2.07 secs
```

В сравнении с [структурным подходом](https://github.com/ik-hse-projects/avs-hw-1#%D0%BF%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%BE%D0%B4%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D1%8C), производительность заметно выше.