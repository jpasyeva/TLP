import requests
import json
import time

def get_vacancies():
    # Инициализация пустого списка для хранения данных о вакансиях
    json_data = []
    
    # Цикл по страницам для получения вакансий (ограничение до 100 страниц для примера)
    for page in range(1, 100):
        # URL API HeadHunter для получения вакансий
        url = "https://api.hh.ru/vacancies"
        
        # Параметры запроса, в данном случае ищем вакансии Python разработчика в Москве
        params = {
            "text": "Python разработчик",
            "area": 113,  # Код региона (1 - Москва)
            "per_page": 100,  # Количество вакансий на странице
            "page": page  # Номер страницы
        }
        
        # Заголовки запроса для эмуляции браузера
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
                          "Chrome/96.0.4664.45 Safari/537.36",
        }

        try:
            # Отправка GET-запроса к API HeadHunter
            response = requests.get(url, params=params, headers=headers, timeout=10)
            response.raise_for_status()  # Проверка наличия ошибок в ответе

            # Получение данных в формате JSON
            data = response.json()
            
            # Извлечение списка вакансий
            vacancies = data.get("items", [])
            
            # Подсчет количества вакансий
            num_vacancies = len(vacancies)

            if num_vacancies > 0:
                # Обработка каждой вакансии
                for i, vacancy in enumerate(vacancies):
                    # Извлечение необходимой информации из объекта вакансии
                    vacancy_name = vacancy.get("name", "Не указано")
                    experience = vacancy.get("experience", {}).get("name", "Не указан опыт")
                    salary = vacancy.get("salary", {})
                    
                    if salary is None:
                        salary = "Не указана"
                    else:
                        salary = f"{salary.get('from')} {salary.get('currency')}"

                    region = vacancy.get("area", {}).get("name", "Не указан регион")
                    
                    # Добавление информации о вакансии в список данных
                    json_data.append({
                        "name": vacancy_name,
                        "experience": experience,
                        "salary": salary,
                        "region": region
                    })
            else:
                print(f"No vacancies on page {page}.")
                break  # Прерываем цикл, если больше нет вакансий
        except requests.RequestException as e:
            print(f"Error: {e}")

        time.sleep(1)  # Задержка, чтобы избежать превышения лимитов запросов к API

    # Запись данных в файл JSON
    write_json(json_data)

def write_json(data):
    # Запись данных в файл JSON
    with open('data.json', 'a', encoding='utf-8') as file:
        json.dump(data, file, ensure_ascii=False, indent=4)

if __name__ == '__main__':
    # Вызов функции для получения вакансий и записи данных в файл JSON
    get_vacancies()
