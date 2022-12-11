############## парсер не доделан (broken) ######################



############ эти строки должны быть в файле main.py, но я не хочу заполнять папку "для галочки" #############
from headhunter import extract_max_page,
exctract_hh_jobs

max_page = extract_max_page
exctact_hh_jobs(max_page)
print(max_page)
###########################

import requests
from bs4 import BeautifulSoup

ITEMS = 100
URL = f'https://hh.ru/search/vacancy?text=python&st=searchVacancy&items_on_page={ITEMS}'

# блок для обмана сайта. прикидываемся реальным пользователем браузера, а не парсером!
headers = {
  'Host': 'hh.ru',
  'User-Agent': 'Safari',
  'Accept': '*/*',
  'Accept-Encoding': 'gzip, deflate, br',
  'Connection': 'keep-alive'
}
 
#заведём функцию для получения номера последней страницы
def extract_max_page():
  
#делаем запрос к странице с вакансиями
  hh_request = requests.get(URL, headers = headers)

#из запроса вытаскиваем текст и передаём его в beautifulsoup 
  hh_soup = BeautifulSoup(hh_request.text, 'html.parser')


  pages = []


#нашли пагинатор с помощью find 
  paginator = hh_soup.find_all("span", {'class' : 'pager-item-not-in-short-range'})
#из пагинатора вытащили все ссылки


  for page in paginator:
    pages.append(int(page.find('a').text))
  #из каждого спана забрать ссылку, а из них текст, т.е. число, которое будет выдавать массив, а это число - номер страницы. int переводит его в число
   
#дальше из списка нам надо вытащить последний элемент

  return  pages[-1]

#номер последней страницы соответствует числу необходимых нам запросов

#генерируем последовательность числе исходя из нашего аргумента max_page
#for page in range(max_page):
#  print(f'page={page}')

#последовательность от 0 до 19
#хотя в браузере 20 ссылок, на сайте hh.ru они нумеруются как в python


# косяк где-то в этом блоке.
def extract_hh_jobs(last_page):
  jobs = []
  for page in range(last_page):
    result = requests.get(f'{URL}&page={page}', headers = headers)
    print(result.status_code)
    soup = BeautifulSoup(result.text, 'html.parser')
    results = soup.find_all('div', {'class': 'vacancy-serp-item'})
    for result in results:
      title = result.find('a').text
      company_div = result.find('div', {'class': 'vacancy-serp-item_meta-info-company'}).find('a').text
      print(company)
      company_link = company_div.find('a').text

  return jobs 
