# Chat from scratch

Code from the series of my streams where I work on creating Chat application absolutely from scratch.

# Заметки

1. То что у лейаутов есть функции button и прочие не круто - много дублирования кода.

- Сделать шаблонный метод `layout.NewElement<Button>("click me")`.
  Проблема - среда разработки ничего не подскажет!
  
- Layout - это генератор размеров. 
  - VerticalLayout
  - Horizontal
  - AbsoluteLayout
  
```c++
auto chatList = root.NewVerticalLayout(0, 0, 300);

for (const auto& user: chat.GetUsers()) {
    if (Button(chatList, user, 32)) {
      chat.selectedUser = user;
    }
}

auto floatLay = NewFloatLay(150, 200);
Button(floatLay, "Click me");
```

## Вопросы

- как эффективнее и лучше хранить контекст UI движка 
  (например, для текстового поля ввода или для z-индексов)
  - в глобальной приватной переменной
  - в божественном классе GUI. Пример: gui.Button(), gui.TextEditor();
  
- как хранить текущий фокус
- как управлять z-индексами
- как вычислять размеры объектов, если размеры известны после отрисовки?
  Мб сохранять команды на отрисовку?
- как рисовать модальные окна и обрабатывать корректно фокус на кнопки.