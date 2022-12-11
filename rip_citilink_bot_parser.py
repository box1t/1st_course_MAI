# изначально я парсил вакансии на hh_ru, но возникли проблемы с библиотекой lxml: она не работает на моём железе (?) понял я это очень поздно...
# потом парсил Avito. это был бы самый полезный бот, но я не смог сделать и его: у них стоит защита от парсинга. и опять же, для этого дела нужна была lxml.


# проблема этого кода в том, что при отправке пользователем сообщений вылезают ошибки, обращаемые к строкам библиотек.
# т.е. ошибки рода "line 425", хотя здесь всего 43 строки
from aiogram import types, executor, Dispatcher, Bot
from bs4 import BeautifulSoup
import requests

# этого бота больше нет, а жаль.. у него была смешная аватарка Галустяна
bot = Bot("5903554539:AAFG-pghNMGr3AFXYk_G7_jZR_Pne78oqHs") 
dp = Dispatcher(bot)

# команда "старт"
@dp.message_handler(commands=['start'])
async def start(message: types.message):
    await bot.send_message(message.chat.id, "Приветствую тебя, перекуп! Я отслеживаю товары в магазине Citilink. Что будем искать?")

# дальше идёт код парсера, завязанный на отправленном пользователем тексте. 
@dp.message_handler(content_types=['text'])

# этот бот делает запрос по слову, которое мы вобьём. он делает запрос как бы приклеивая наш запрос к ссылке.
# здесь можно играться и с другими параметрами, но хоть бы это сделать......
async def parser(message: types.message):
    url = "https://www.citilink.ru/search/?text=" + message.text
    request = requests.get(url)
    soup = BeautifulSoup(requests.text, "html.parser")

    # здесь парсер соотносит наш запрос с классом товара. это должно работать для всех видов товаров.
    # код устроен там так, что для самой сущности товара отведён именно указанный тут класс.
    # дальше идёт пляска от этого класса: в нём есть подклассы с изображениями, ценой, названием.
    all_links = soup.find_all("a", class_="  ProductCardVertical__name  Link js--Link Link_type_default")
    for link in all_links:
        url =  "https://www.citilink.ru" + link["href"]
        request = requests.get(url)
        soup = BeautifulSoup(requests.text, "html.parser")
        
        
    # парсер ситилинка может выводить только фотку, цену, ссылку на товар (по url было бы понятно, что за модель товара).
    # название товара не может быть получено, поскольку так реализована защита от парсеров на сайте: для каждого товара создан свой класс с именем. 
        price = soup.find("span", class_="ProductCardVerticalPrice__price-current_current-price js--ProductCardVerticalPrice__price-current_current-price ").text
        price = price.text

    # получаем картинку. findChildren означает поиск дочернего элемента класса.
    # под дочерним имеется в виду просто подпункт в классе.
    # если объяснять на пальцах, в коде элемента древовидная структура. нажимаешь на стрелку - открываются подпункты. 
        img = soup.find("div", class_="ProductCardVertical__picture js--ProductCardInListing__picture")
        img = img.findChildren("img")[0]
        img = img["src"]

        # отправление сообщения ботом
        await bot.send_photo(message.chat.id, img, caption="<i>" + price + "</i> href='{url}'", parse_mode="html")

        # на ситилинке одновременно показывается 40 предметов, соответственно индекс 39
        if all_links.index(link) == 39:
            break
# так завершается работа бота
executor.start_polling(dp)
