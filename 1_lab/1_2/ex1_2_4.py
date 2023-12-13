print("Введите скобки в формате [{}({})]")
expression = input()

def is_valid_expression(s):
    # Инициализация стека для отслеживания открывающих скобок
    stack = []
    
    # Словарь, отображающий закрывающие скобки на соответствующие открывающие
    brackets = {')': '(', '}': '{', ']': '['}

    # Итерация по каждому символу в выражении
    for char in s:
        # Если символ - открывающая скобка, добавляем ее в стек
        if char in brackets.values():
            stack.append(char)
        # Если символ - закрывающая скобка
        elif char in brackets.keys():
            # Проверяем соответствие закрывающей скобки последней открывающей в стеке
            if not stack or stack.pop() != brackets[char]:
                return False

    # Выражение считается валидным, если стек пуст после итерации
    return not stack

# Пример использования функции
#expression = "[()"
result = is_valid_expression(expression)

# Вывод результата
if result:
    print(True)
else:
    print(False)
