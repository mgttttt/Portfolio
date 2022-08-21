import schedule
import vk_api
from vk_api.longpoll import VkLongPoll, VkEventType
import re
import json
import datetime
from time import sleep
from threading import Thread
import config
import templates_messages

# Подключаем токен и longpoll
vk_session = vk_api.VkApi(token=config.TOKEN_VK)
longpoll = VkLongPoll(vk_session)
vk = vk_session.get_api()


def send_massage(id, text):
    vk_session.method('messages.send', {'user_id': id, 'message': text, 'random_id': 0})


def print_id():
    with open("static_files/data_group.json") as f:
        db_json = json.load(f)

    message_id = "{\n"
    for key, value in db_json.items():
        message_id += f'"{key}": ["{value[0]}", {value[1]}],\n'
    message_id += "}"

    send_massage(config.ID_ADMIN_VK, message_id)
    send_massage(config.ID_ADMIN_VK, f"Уникальных пользователей: {len(db_json.keys())}")


def add_group_id(id, group):
    with open("static_files/schedul_all_group.json", "r", encoding="utf-8") as read_file:
        data = json.load(read_file)

    if group in data:
        with open("static_files/data_group.json") as f:
            db_json = json.load(f)

        if str(id) in db_json.keys():
            subscription = db_json[str(id)][1]
            db_json[str(id)] = [group, subscription]
            send_massage(id, "Номер группы успешно обновлен")
            print_id()
        else:
            db_json[str(id)] = [group, 0]
            send_massage(id, "Я запомнил твою группу")
            print_id()

        with open("static_files/data_group.json", 'w') as f:
            json.dump(db_json, f, ensure_ascii=False, indent=4)
    else:
        send_massage(id, templates_messages.not_group)


def subscription_on_off(id):
    with open("static_files/data_group.json") as f:
        db_json = json.load(f)

    if str(id) in db_json.keys():
        subscription = db_json[str(id)][1]

        if subscription == 0:
            db_json[str(id)][1] = 1
            send_massage(id, "Оповещения включены")
        else:
            db_json[str(id)][1] = 0
            send_massage(id, "Оповещения отключены")

        with open("static_files/data_group.json", 'w') as f:
            json.dump(db_json, f, ensure_ascii=False, indent=4)

    else:
        send_massage(id, "Для подключения оповещений сначала укажите свою группу\nПример: /000-00")


def num_or_den(request):
    day_week_str = ["", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"]
    request = str(request).upper()

    # День недели request
    index_req = day_week_str.index(request)
    # День недели сегодня
    day_week_int = datetime.date.today().isoweekday()

    # Номер недели
    num_weekly = int(datetime.date.today().strftime("%V"))

    if index_req >= day_week_int:
        # 0 - знаменатель, 1 - числитель
        num_or_den = num_weekly % 2
    else:
        # Тоже самое, но т.к. просят следующий день недели, то там меняется неделя
        num_or_den = (num_weekly+1) % 2
    return num_or_den


def make_message(id, request):
    dw = {"ПН": "понедельник", "ВТ": "вторник", "СР": "среду", "ЧТ": "четверг", "ПТ": "пятницу", "СБ": "субботу"}

    request = str(request).upper()

    with open("static_files/data_group.json") as f:
        db_json = json.load(f)

    with open("static_files/schedul_all_group.json", "r", encoding="utf-8") as read_file:
        data_schedule = json.load(read_file)

    if str(id) in db_json:
        group = db_json[str(id)][0]

        if group in data_schedule:
            schedule_day_week = data_schedule[group][request]
            message = f"Расписание на {dw[request]}, группа {group}:\n"

            for key, value in schedule_day_week.items():
                value_str = " | ".join(value)
                message += f'    • {key} пара - {value_str}\n'

            den_or_num = num_or_den(request)
            if den_or_num == 0:
                message += "\nУчимся по знаменателю"
            else:
                message += "\nУчимся по числителю"
        else:
            message = "Группа не найдена"
    else:
        message = "Для использования этой команды сначала укажите свою группу\nПример: /000-00"

    return message

# Оповещения. Работает только на обычных серверах. На heroku дает сбой
# def schedule_message(db_json, group, day_week_str, para, fisic):
#     if group not in db_json:
#         return "None"
#     if day_week_str not in db_json[group]:
#         return "None"
#     if para not in db_json[group][day_week_str]:
#         return "None"
#
#     obj = " | ".join(db_json[group][day_week_str][para])
#
#
#     if fisic:
#         if str(obj).lower().find("спорт") != -1:
#             return "Следующая пара: " + obj
#         else:
#             return "None"
#     else:
#         if str(obj).lower().find("спорт") == -1:
#             return "Следующая пара: " + obj
#         else:
#             return "None"
#
#
# def send_users(day_week_str, para, fisic):
#     with open("static_files/data_group.json") as f:
#         db_user_json = json.load(f)
#     with open("static_files/schedul_all_group.json", "r", encoding="utf-8") as read_file:
#         db_json = json.load(read_file)
#
#     for user, param in db_user_json.items():
#         if param[1] == 1:
#             message = schedule_message(db_json, param[0], day_week_str, para, fisic)
#
#             if message != "None":
#                 send_massage(user, message)
#
#
# def scheduler():
#     day_week_str = ["", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"][datetime.date.today().isoweekday()]
#     # Пары по физической культуре
#     schedule.every().day.at("03:20").do(send_users, day_week_str, "1", True)
#     schedule.every().day.at("05:00").do(send_users, day_week_str, "2", True)
#     schedule.every().day.at("06:40").do(send_users, day_week_str, "3", True)
#     schedule.every().day.at("07:20").do(send_users, day_week_str, "4", True)
#     schedule.every().day.at("09:55").do(send_users, day_week_str, "5", True)
#
#     # Обычные пары
#     schedule.every().day.at("02:50").do(send_users, day_week_str, "1", False)
#     schedule.every().day.at("04:30").do(send_users, day_week_str, "2", False)
#     schedule.every().day.at("06:10").do(send_users, day_week_str, "3", False)
#     schedule.every().day.at("07:10").do(send_users, day_week_str, "4", False)
#     schedule.every().day.at("09:50").do(send_users, day_week_str, "5", False)
#     schedule.every().day.at("11:30").do(send_users, day_week_str, "6", False)
#     schedule.every().day.at("13:10").do(send_users, day_week_str, "7", False)
#     schedule.every().day.at("14:50").do(send_users, day_week_str, "8", False)
#
#     while True:
#         schedule.run_pending()
#         sleep(1)  # Выберите оптимальное значение под свои задачи планировщика
#
#
# # Создаём и запускаем планировщик в отдельном потоке
# t = Thread(target=scheduler)
# t.start()


for event in longpoll.listen():
    if event.type == VkEventType.MESSAGE_NEW and event.to_me:
        try:
            request = event.text.lower()
            id = event.user_id

            if request == "инфо":
                send_massage(id, templates_messages.info_messages)

            elif request == "сегодня":
                day_week_str = ["", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"]
                day_week_int = datetime.date.today().isoweekday()
                request = day_week_str[day_week_int]
                send_massage(id, make_message(id, request))
            elif request == "завтра":
                day_week_str = ["", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"]
                day_week_int = (datetime.date.today() + datetime.timedelta(days=1)).isoweekday()
                request = day_week_str[day_week_int]
                send_massage(id, make_message(id, request))

            elif re.match(r"\d\d.\d\d", request) is not None:
                # жесткий костыль для работы с датой)
                try:
                    day_week_str = ["", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"]
                    request += ".2022"
                    date = datetime.datetime.strptime(request, "%d.%m.%Y")
                    day_week_int = date.isoweekday()
                    message = make_message(id, day_week_str[day_week_int])
                    message = message.split(" ")

                    if message[-1] != "найдена":
                        den_or_num = int(date.strftime("%V")) % 2
                        if den_or_num == 0:
                            message[-1] = "знаменателю"
                        else:
                            message[-1] = "числителю"

                    message = " ".join(message)
                    send_massage(id, message)
                except:
                    send_massage(id, "Либо ты хочешь узнать расписание на воскресенье, либо неверный формат даты")

            elif re.match(r"\d\d\d-\d\d", request) is not None:
                add_group_id(id, request)

            elif request == "звонки":
                send_massage(id, templates_messages.schedule_calls)

            # elif request == "оповещение":
            #     subscription_on_off(id)

            elif request in ["пн", "вт", "ср", "чт", "пт", "сб"]:
                send_massage(id, make_message(id, request))

            elif request == "неделя":
                den_or_num = int(datetime.date.today().strftime("%V")) % 2

                if den_or_num == 0:
                    send_massage(id, "Учимся по знаменателю")
                else:
                    send_massage(id, "Учимся по числителю")

            elif request == "начать":
                send_massage(id, templates_messages.hello_messages)

            elif request == "анализ" and id == config.ID_ADMIN_VK:
                print_id()

            elif request == "время" and id == config.ID_ADMIN_VK:
                current_time = datetime.datetime.now().time()
                send_massage(config.ID_ADMIN_VK, current_time)

            else:
                send_massage(id, "Команда не найдена. Чтобы получить список команд введи /инфо")

        except:
            send_massage(event.user_id, "Команда не найдена. Чтобы получить список команд введи /инфо")
            send_massage(config.ID_ADMIN_VK, f"Пользователь с id {event.user_id} вызвал ошибку на сервере")
