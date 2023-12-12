def is_palindrome(s):
    # Приводим строку к нижнему регистру и удаляем пробелы с использованием replace
    s = s.lower().replace(" ", "")
    
    # Сравниваем строку с ее обратным вариантом
    return s == s[::-1]

# Пример использования
input_string = "blackcat"
result = is_palindrome(input_string)

if not result:
    print(f'Вывод: False. \nСтрока "{input_string}" не является палиндромом.')
else:
    print(f'Вывод: False. \nСтрока "{input_string}" является палиндромом.')
