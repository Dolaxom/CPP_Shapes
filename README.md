# Рисование фигур на OpenGL

Тестовое задание от **ЗАО «Топ Системы»** на вакансию C++ разработчик

![app](/misc/imgs/Application.png)

## Управление программой

| Клавиша        | Действие                |
|----------------|-------------------------|
| Стрелка вверх  | Поднять камеру          |
| Стрелка вниз   | Опустить камеру         |
| Стрелка влево  | Повернуть камеру левее  |
| Стрелка вправо | Повернуть камеру правее |

## Создание модели

1. Задать параметры для Color в формате RGB в диапазоне от 0 до 1. При использовании других значений они будут сброшены до значений по умолчанию.
2. Задать параметры x и y для Location в любом видимом диапозоне.
3. Выбрать интересуемую фигуру (Shape/Figure) из списка.
4. Нажать на кнопку **Create Shape**.

## Документация по коду

Ниже представлена диаграмма показывающая взаимосвязь между классама:

![app](/misc/imgs/UML.png)

Программа разработана по паттерну **MVC**, в котором есть разделение на интерфейс *(view)* и бизнес-логику *(model)*, которая хранит текущее состояние приложения. Связь и обработку входящих значений между model и view обрабатывает *controller*.

Для работы с объектами, которые в будущем должны будут отрисовываться, есть **интерфейс Object**. От него наследуются **класс Grid** (адаптивная сетка) и **класс Figure**, который является общим предком для всех остальных конкретных фигур, таких как круг, треугольник и квадрат.

---

Окно создаётся через библиотеку **GLFW**, отрисовка графики происходит через **OpenGL**, создание и отрисовка пользовательского интерфейса через **ImGUI**. Предкомпилированные библиотеки GLFW для Windows64 и ImGUI (кроссплатформенная) находятся в директории ``src/third_party.``. Для Linux GLFW необходимо предустановить глобально через ``sudo apt-get install libglfw3`` и ``sudo apt-get install libglfw3-dev``. **CMakeList** поддерживает сборку для обеих систем.

## Поддерживаемые системы

| Система        | Поддержка     |
|----------------|---------------|
| Windows x64    | Работает      |
| Linux (Ubuntu) | Работает      |
| MacOS          | Не проверено  |
| Windows x86    | Нет поддержки |
