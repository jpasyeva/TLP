def multiply_binary_strings(x1, x2):
    # Преобразуем бинарные строки в целые числа
    num1 = int(x1, 2)
    num2 = int(x2, 2)

    # Умножаем числа
    result = num1 * num2

    # Преобразуем результат обратно в бинарную строку
    result_binary = bin(result)[2:]

    return result_binary

# Пример использования
binary_string1 = "111"
binary_string2 = "101"
result = multiply_binary_strings(binary_string1, binary_string2)

print(f'Произведение бинарных чисел {binary_string1} и {binary_string2}: {result}') 
