from flask import Flask, flash, redirect, render_template, \
     request, url_for
import os
import requests
import json
import time


volume = 50
queue_list = []
name_list = []
name_dict = { #TODO: OrderedDict 
    'green':'Зеленый',
    'blue':'Синий',
    'red':'Красный',
    'orange':'Оранжевый',
    'yellow':'Желтый',
    'lightblue':'Голубой',
    'violet':'Фиолетовый',
    'pink':'Розовый',
    'brown':'Коричневый',
    'white':'Белый',
    'rest':'Покой',
    'sit':'Сесть',
    'stand':'Встать',
    'dance':'Странный танец',
    'breathe':'Дышать',
    'breatheoff':'Не дышать',
    'hands_clap':'Хлопок в ладоши',
    'wipe_forehead':'Трогает голову',
    'close_hands':"Сжать кулак",
    'open_hands':'Разжать кулак',
    'hello':'Машет рукой',
    'breath':'Дыхание',
    'hi':'Привет',
    'name':'Меня зовут Нао',
    'good':'Молодец',
    'bye':'Пока',
    'touch_right_hand':'Потрогай мою правую руку',
    'touch_left_hand':'Потрогай мою левую руку',
    'touch_left_foot':'Потрогай мою левую ногу',
    'touch_right_foot':'Потрогай мою правую ногу',
    'touch_head':'Потрогай мою голву',
    'color':'Какого цвета мои глаза?',
    'bend_right':'Наклон вправо',
    'bend_left':'Наклон влево',
    'head_yes':'Движение "Да"',
    'head_no':'Движение "нет"',
    'hands_o':'Разжать обе руки',
    'hands_ol':'Разжать левую',
    'hands_or':'Разжать правую',
    'hands_c':'Сжать обе руки',
    'hands_cl':'Сжать левую',
    'hands_cr':'Сжать правую',
    'left_hand_up':'Левая вверх',
    'right_hand_up':'Правая вверх',
    'hands_up':'Руки вверх',
    'left_hand_left':'Левая в сторону',
    'right_hand_right':'Правая в сторону',
    'hands_sides':'Руки в стороны',
    'hands_front':'Руки вперед',
    'left_hand_front':'Левая вперед',
    'right_hand_front':'Правая вперед',
    'left_shoulder_up':'Левый локоть вверх',
    'right_shoulder_up':'Правый локоть вверх',
    'shoulders_up':'Локоть вверх',
    'play_gena':'Гена',
    'play_spyat':'Колыбельная',
    'play_bear':'Умка',
    'play_matroskin':'Матроскин',
    'play_pooh':'Винни',
    'play_airplane_1':'Самолет 1',
    'play_airplane_2':'Самолет 2',
    'play_car':'Машина',
    'play_cat_eating':'Кот ест',
    'play_cat_meow':'Мяукает',
    'play_dog_bark':'Гавкает',
    'play_dog_breathe':'Дышит',
    'play_dog_cry':'Скулит',
    'play_parrot_1':'Попугай 1',
    'play_parrot_2':'Попугай 2',
    'play_train':'Поезд',
    'play_water':'Вода',
    'play_zhel_hands_up':'Жел Руки',
    'play_zhel_top_hlop':'Жел Топ',
    'play_zhel_tuk_tok':'Жел Тук',
    'play_zhel_zayka':'Зайка',
    'play_zhel_logo_zha_zhu':'Лого Жа',
    'play_zhel_logo_ku_gi':'Лого Ку',
    'play_zhel_logo_no':'Лого Но',
    'play_zhel_logo_su_sa':'Лого Су',
    'pause':'Пауза',
    'yes':'Да',
    'no':'Нет',
    'your_name':'Как зовут?',
    'repeat':'Повторяй',
    'again':'Еще раз',
    'nice':'Хорошо',
    'give_ball':'Дай мяч',
    'give_toy':'Дай игрушку',
    'come_here':'Подойди',
    'want_play':'Хочешь поиграть?',

}
hands_dict = {
    'hands_ol':'open_left',
    'hands_or':'open_right',
    'hands_cl':'close_left',
    'hands_cr':'close_right',
    'hands_o':'open_both',
    'hands_c':'close_both'
}

app = Flask(__name__)
app.secret_key = '#&*(#TY(#*HRIRHDO*&Y#HIUDO*#&DY*H' 

#port = "8181"
#port = "8195"
#port = "0"
#port = "8159"
#port = "3555"
#port = "9559"
port = "9555"

#ip = "http://192.168.43.117:"
ip = "http://192.168.1.249:"
#ip = "http://192.168.43.201:"
#ip = "http://127.0.0.1:"

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/login/', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        if request.form['Name'] != 'admin' or request.form['Age'] != '17':
            error = 'Invalid credentials'
        else:
            # flash('You were successfully logged in')
            return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)
    return render_template('login.html', error=error)


@app.route('/hello/<pushed_button>/', methods=['GET'])
def pushed_button_funk(pushed_button):    
    action = pushed_button
    text = 'qwer'
    if (action in hands_dict):
        text = hands_dict[pushed_button]
        action ='hands'
    r = requests.get(ip + port + "/" + "?" + "action=/" + action + "&" + "text=" + text )


    print(r)
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)

@app.route('/free/free/', methods=['GET'])
def pushed_free():    
    # os.system ("wget " + '"' + ip + port + "/" + pushed_button + '"')
    action = 'free'
    text = 'qwer'
    r = requests.get(ip + port + "/" + "?" + "action=/" + action + "&" + "text=" + text )

    print(r)
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)

@app.route('/hello/<add_to_queue>/+/', methods=['GET'])
def add_to_queue_funk(add_to_queue):    
    global queue_list
    global name_dict
    global name_list
    print(queue_list)
    queue_list.append(add_to_queue)

    name = 'name_name'
    name_list.append(name_dict[add_to_queue])
    print(queue_list)
    
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)

@app.route('/play/queue/',methods=['GET'])
def play_queue():
    global queue_list
    print(len(queue_list))
    if (len(queue_list) != []):
        action_list = queue_list
        a1 = 200
        for action in action_list:
            text = 'qw'
            if (action == 'pause'):
                time.sleep(2)
            else:
                if (action in hands_dict):
                    text = hands_dict[action]
                    action ='hands'
                while(a1 == 667):
                    time.sleep(0.1)
                    r1 = requests.get(ip + port + "/" + "?" + "action=/" + 'free' + "&" + "text=" + text )
                    a1 = r1.status_code
                    print(a1)
                
                r = requests.get(ip + port + "/" + "?" + "action=/" + action + "&" + "text=" + text )
                r1 = requests.get(ip + port + "/" + "?" + "action=/" + 'free' + "&" + "text=" + text )
                a1 = r1.status_code
                print(a1, 'free')
                a = r.status_code
                print(a, action)
   
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)


@app.route('/pause/',  methods=['GET'])
def pause():
    time.sleep(2)
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)


@app.route('/new/queue/', methods=['GET'])
def new_queue():
    global queue_list
    global name_list
    queue_list = []
    name_list = []
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)
@app.route('/clear/', methods=['GET'])
def clear():
    print('Clear')
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)

@app.route('/queue/',methods=['GET'])
def queue():
    action_list = [ 'speak','red', 'stand', 'speak', 'speak', 'green', 'sit' ]
    a1 = 200
    for action in action_list:
        while(a1 == 667):
            time.sleep(0.1)
            r1 = requests.get(ip + port + "/" + "?" + "action=/" + 'free' + "&" + "text=" + text )
            a1 = r1.status_code
            print(a1)
        text = 'привет друг'
        r = requests.get(ip + port + "/" + "?" + "action=/" + action + "&" + "text=" + text )
        r1 = requests.get(ip + port + "/" + "?" + "action=/" + 'free' + "&" + "text=" + text )
        a1 = r1.status_code
        print(a1, 'free')
        a = r.status_code
        print(a, 'action')

    print(r)
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)

# @app.route('/hello/name/', methods=['GET'])
# def name():    
#     #os.system ("wget " + '"' + ip + port + "/" + 'name' + '"')
#     return render_template('hello.html', queue_list=queue_list, name_list=name_list)


# @app.route('/hello/blue/', methods=['GET'])
# def blue_button():    
#     os.system ("wget " + '"' + ip + port + "/blue" + '"')
#     return render_template('hello.html', queue_list=queue_list, name_list=name_list)

# @app.route('/hello/red/', methods=['GET'])
# def red_button():    
#     os.system ("wget " + '"' + ip + port + "/red" + '"')
#     return render_template('hello.html', queue_list=queue_list, name_list=name_list)

# @app.route('/hello/zubenko/', methods=['GET'])    
# def zubenko ():    
#     os.system ("wget " + '"' + ip + port + "/kekspeaker" + '"')
#     return render_template('hello.html', queue_list=queue_list, name_list=name_list)

my_text_text = 'а'
@app.route('/my_text/', methods=['GET', 'POST', 'PUT'])
def my_text():
    if request.method == 'POST':
        text = request.form['my_text']
        if (text == ''):
            text = 'а'
        action = '/speak'
        print(text)
        r = requests.get(ip + port + "/" + "?" + "action=" + action + "&" + "text=" + text )
        #os.system("wget " + '"' + ip + port + "/" + "?" + "action=" + action + "&" + "text=" + text1 + '"')
        print(r)
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)

# @app.route('/set_speaker_volume/', methods=['GET', 'POST', 'PUT'])
# def volume_func():
#     if request.method == 'POST':
#         text = request.form['volume']
#         action = '/set_speaker_volume'
#         print(text)
#         r = requests.get(ip + port + "/" + "?" + "action=" + action + "&" + "text=" + text )
#         #os.system("wget " + '"' + ip + port + "/" + "?" + "action=" + action + "&" + "text=" + text1 + '"')
#         print(r)
#     return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)


@app.route('/volume/<act>/', methods=['GET', 'POST', 'PUT'])
def volume_act(act):
    global volume
    if ( act == 'i' and volume <100 ):
        volume +=5
    if (act == 'd'  and volume >15 ):
        volume -=5
    text = str(volume)
    action = '/set_speaker_volume'
    r = requests.get(ip + port + "/" + "?" + "action=" + action + "&" + "text=" + text )
    return render_template('hello.html', queue_list=queue_list, name_list=name_list, volume=volume)




if __name__ == "__main__":
    app.run()
