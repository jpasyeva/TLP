print("Enter intenger")
number = int(input())

def int_to_roman(num):
    # Значения и символы для представления чисел в римской системе
    val = [
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    ]
    syb = [
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    ]
    
    # Инициализация строки для римского представления числа
    roman_num = ''
    
    # Итерация по значениям и символам
    i = 0
    while num > 0:
        # Добавление соответствующих символов в римское представление числа
        for _ in range(num // val[i]):
            roman_num += syb[i]
            num -= val[i]
        i += 1
    
    # Возвращение римского представления числа
    return roman_num

# Пример использования функции с числом 1945
#number = 1945
roman_representation = int_to_roman(number)
print(f'Число {number} в римской системе счисления: {roman_representation}')
