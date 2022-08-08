<h1 align="center">Геометрические фигуры, полиморфное применение классов</h1>

Все числовые данные в этой работе должны быть представлены значениями с плавающей запятой.

1) Создать файл base-types.hpp, содержащий определения следующих структур:
  - point_t, представляющую собой точку на плоскости, координаты должны храниться в полях x и y.
  - rectangle_t, описывающую прямоугольник шириной width и высотой height с центром в точке pos.
2) Создать файл shape.hpp, содержащий определение абстрактного класса Shape. Этот класс должен предоставлять следующие методы: getArea вычисление площади getFrameRect получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще- го пункта), стороны ограничивающего прямоугольника всегда параллельны осям move перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям абсцисс и ординат
3) Реализовать классы Rectangle и Circle в файлах rectangle.hpp, rectangle.cpp, circle.hpp и circle.cpp соответственно.
4) Продемонстрировать правильную работу классов простой программой. Демонстрация должна включать полиморфное применение классов.