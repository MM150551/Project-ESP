from info import *
from botbutttton import *
Astra = telebot.TeleBot(token_bot)

list1 =["hi","hello","welcome","ثبح","مسا","صبح"]
list2 =["bye","goodbye","see you","good evening"]
list3 =["time", "date","الوقت","الزمن","الساعة","الساعه","وقت","زمن"]

def replay_fun(m):
    if m.text.lower() in list1:
        Astra.reply_to(m,"welcom " + m.from_user.first_name +" : this is Astra bot project \nto use bot you should write one of this words: ", reply_markup=list_btn2)
    elif m.text.lower() == "my info" :
            Astra.reply_to(m,m)
    elif m.text.lower() in list2 :
        Astra.reply_to(m,"see you, enjoy"+ m.from_user.first_name )  
    elif m.text.lower() == "astra":   
          Astra.reply_to(m,"you astra ?", reply_markup=list_btn)
    elif m.text.lower() in list3 : 
        Astra.reply_to(m, "what time want ?", reply_markup=list_btn3)   
    elif m.text.lower() == "start" :
        Astra.reply_to(m,"welcom " + m.from_user.first_name +" : this is Astra bot project \nto use bot you should write one of this words: ", reply_markup=list_btn2) 
    elif m.text == "GET OUT" :
        bnn= Astra.ban_chat_member (m.chat.id, m.reply_to_message.from_user.id)
        if bnn  :
            Astra.send_message(m.chat.id,  " GET OUT " + "@" + str(m.reply_to_message.from_user.first_name ))
    
           
    